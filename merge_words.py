#!/usr/bin/env python3

import sys
import subprocess
import re
from pathlib import Path
from dataclasses import dataclass


TARGET = "Solutions/Other-English-LearningNotes-SomeWords.md"


@dataclass
class CommitChange:
    commit: str
    timestamp: int
    lines: list[str]


def git(*args, check=True):
    return subprocess.run(
        ["git", *args],
        text=True,
        capture_output=True,
        check=check,
    ).stdout.strip()



def get_commit_time(commit: str) -> int:
    return int(
        git(
            "show",
            "-s",
            "--format=%ct",
            commit,
        )
    )



def get_conflict_blobs(path: str):
    """
    从 Git index 获取 merge 三方 blob

    stage:
        1 ancestor
        2 ours
        3 theirs
    """

    output = git(
        "ls-files",
        "-u",
        "--",
        path,
    )

    result = {}

    for line in output.splitlines():

        mode, sha, stage, filename = line.split(
            maxsplit=3
        )

        result[int(stage)] = sha


    return result



def get_all_commits():

    result = git(
        "rev-list",
        "--all",
    ).splitlines()
    print(f'all history len: {len(result)}')
    return result



def blob_in_commit(blob, commit):

    output = git(
        "ls-tree",
        "-r",
        commit,
        "--",
        TARGET,
        check=False,
    )

    return blob in output



def find_commits_by_blob(blob):

    """
    找拥有该 blob 的 commit
    """

    result=[]

    for commit in get_all_commits():

        if blob_in_commit(blob, commit):

            result.append(commit)


    return result



def find_tip_commit(blob):

    """
    blob可能对应多个commit。
    选择时间最新的那个。
    """

    commits=find_commits_by_blob(blob)

    if not commits:
        raise RuntimeError(
            f"cannot find commit for blob {blob}"
        )


    return max(
        commits,
        key=get_commit_time
    )



def commits_after(base, head):

    if base == head:
        return []

    result = git(
        "rev-list",
        "--reverse",
        f"{base}..{head}",
    )

    if not result:
        return []

    return result.splitlines()



def extract_added_lines(commit):

    diff = git(
        "show",
        "--format=",
        "--unified=0",
        commit,
        "--",
        TARGET,
    )


    result=[]

    for line in diff.splitlines():

        if (
            line.startswith("+")
            and not line.startswith("+++")
        ):
            content=line[1:]

            if (
                content == "|||"
                or is_word_line(content)
            ):
                result.append(content)


    return result



def is_word_line(line):

    return bool(
        re.match(
            r"^\|[^|]+\|[^|]+\|$",
            line
        )
    )



def collect_branch_changes(
    base,
    head,
):

    changes=[]

    for commit in commits_after(
        base,
        head,
    ):

        lines=extract_added_lines(commit)

        if lines:

            changes.append(
                CommitChange(
                    commit=commit,
                    timestamp=get_commit_time(commit),
                    lines=lines,
                )
            )

    return changes



def get_merge_base(a,b):

    return git(
        "merge-base",
        a,
        b,
    )



def get_current_head():

    return git(
        "rev-parse",
        "HEAD",
    )



def get_theirs_commit():

    """
    从 stage3 blob 找 incoming commit
    """

    blobs=get_conflict_blobs(TARGET)

    theirs_blob=blobs[3]

    return find_tip_commit(
        theirs_blob
    )



def merge_words():

    ancestor_file=sys.argv[1]
    ours_file=sys.argv[2]
    theirs_file=sys.argv[3]


    print(
        "ancestor:",
        ancestor_file
    )

    print(
        "ours:",
        ours_file
    )

    print(
        "theirs:",
        theirs_file
    )


    blobs=get_conflict_blobs(TARGET)

    print(
        "blobs:",
        blobs
    )


    ours_blob=blobs[2]
    theirs_blob=blobs[3]


    ours_commit=find_tip_commit(
        ours_blob
    )

    theirs_commit=find_tip_commit(
        theirs_blob
    )


    print(
        "ours commit:",
        ours_commit
    )

    print(
        "theirs commit:",
        theirs_commit
    )


    base=get_merge_base(
        ours_commit,
        theirs_commit
    )


    print(
        "base:",
        base
    )


    changes=[]


    changes.extend(
        collect_branch_changes(
            base,
            ours_commit
        )
    )


    changes.extend(
        collect_branch_changes(
            base,
            theirs_commit
        )
    )


    # 按真实 commit 时间排序

    changes.sort(
        key=lambda x: (
            x.timestamp,
            x.commit,
        )
    )


    merged=[]

    for c in changes:

        merged.extend(
            c.lines
        )


    # 写回 %A
    # 注意：
    # 不写 TARGET
    # Git 会读取这个文件作为 merge result

    original=Path(
        ours_file
    ).read_text(
        encoding="utf-8"
    ).splitlines()


    start=None
    end=None


    for i,line in enumerate(original):

        if is_word_line(line):

            if start is None:
                start=i

        elif start is not None:

            end=i
            break


    if start is None:
        raise RuntimeError(
            "table not found"
        )


    if end is None:
        end=len(original)


    result=(
        original[:start]
        +
        merged
        +
        original[end:]
    )


    Path(ours_file).write_text(
        "\n".join(result)+"\n",
        encoding="utf-8"
    )


    return 0



if __name__=="__main__":

    try:
        sys.exit(
            merge_words()
        )

    except Exception as e:

        print(
            "ERROR:",
            e
        )

        sys.exit(1)