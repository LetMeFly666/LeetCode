import os
import sys
import subprocess
import re
from pathlib import Path
from dataclasses import dataclass


TARGET = "Solutions/Other-English-LearningNotes-SomeWords.md"


@dataclass
class Change:
    commit: str
    timestamp: int
    lines: list[str]



def run_git(*args):

    result = subprocess.run(
        [
            "git",
            *args
        ],
        text=True,
        capture_output=True
    )

    if result.returncode != 0:
        raise RuntimeError(
            f"""
git command failed:

git {' '.join(args)}

stdout:
{result.stdout}

stderr:
{result.stderr}
"""
        )

    return result.stdout.strip()



def debug():

    print("=" * 80)

    print("ARGV:")
    for i, x in enumerate(sys.argv):
        print(i, repr(x))


    print("\nENV GITHEAD:")

    for k, v in os.environ.items():

        if k.startswith("GITHEAD_"):
            print(
                k,
                "=",
                v
            )

    print("=" * 80)



def get_merge_commits():

    """
    merge driver 阶段：

    ours:
        HEAD

    theirs:
        GITHEAD_<sha>=branch
    """

    ours = run_git(
        "rev-parse",
        "HEAD"
    )


    theirs = None


    for k in os.environ:

        if k.startswith("GITHEAD_"):

            sha = k[len("GITHEAD_"):]

            if len(sha) == 40:
                theirs = sha
                break


    if theirs is None:
        raise RuntimeError(
            "Cannot find GITHEAD_*"
        )


    return ours, theirs



def commit_time(commit):

    return int(
        run_git(
            "show",
            "-s",
            "--format=%ct",
            commit
        )
    )



def commits_between(base, head):

    result = run_git(
        "rev-list",
        "--reverse",
        f"{base}..{head}"
    )

    if not result:
        return []

    return result.splitlines()



def is_word(line):

    return bool(
        re.match(
            r"^\|[^|]+\|[^|]+\|$",
            line
        )
    )



def extract_added_words(commit):

    diff = run_git(
        "show",
        "--format=",
        "--unified=0",
        commit,
        "--",
        TARGET
    )


    result=[]


    for line in diff.splitlines():

        if (
            line.startswith("+")
            and not line.startswith("+++")
        ):

            content = line[1:]


            if (
                content == "|||"
                or is_word(content)
            ):
                result.append(content)


    return result



def collect_changes(base, head):

    result=[]


    for commit in commits_between(
        base,
        head
    ):

        lines = extract_added_words(
            commit
        )


        if lines:

            result.append(
                Change(
                    commit=commit,
                    timestamp=commit_time(commit),
                    lines=lines
                )
            )


    return result



def find_table_end(lines):

    """
    找 markdown 单词表结束位置。

    文件结构：

    前置markdown

    |word|meaning|
    |word|meaning|
    |||

    后续内容

    返回：
        后续内容开始 index
    """

    in_table = False


    for i, line in enumerate(lines):

        if (
            is_word(line)
            or line == "|||"
        ):

            in_table = True


        elif in_table:

            return i


    return len(lines)



def normalize_append(lines):

    """
    保证追加内容格式正确。

    两个分支都有 |||：
    
        |||
        word

    不删除。

    只保证：
        旧表格和新内容之间有分隔。
    """

    if not lines:
        return lines


    result = list(lines)


    if result[0] != "|||":

        result.insert(
            0,
            "|||"
        )


    return result



def replace_table(
    file,
    merged_lines
):

    content = Path(
        file
    ).read_text(
        encoding="utf-8"
    )


    lines = content.splitlines()


    table_end = find_table_end(
        lines
    )


    merged_lines = normalize_append(
        merged_lines
    )


    new_lines = (
        lines[:table_end]
        +
        merged_lines
        +
        lines[table_end:]
    )


    Path(file).write_text(
        "\n".join(new_lines)
        +
        "\n",
        encoding="utf-8"
    )



def main():

    if len(sys.argv) != 4:

        print(
            "usage: merge_words.py %O %A %B"
        )

        return 1


    ancestor_file = sys.argv[1]
    ours_file = sys.argv[2]
    theirs_file = sys.argv[3]


    debug()


    print("FILES:")

    for f in [
        ancestor_file,
        ours_file,
        theirs_file
    ]:

        p = Path(f)

        print(
            f,
            "exists=",
            p.exists(),
            "size=",
            p.stat().st_size
            if p.exists()
            else None
        )


    ours, theirs = get_merge_commits()


    print(
        "OURS:",
        ours
    )

    print(
        "THEIRS:",
        theirs
    )


    base = run_git(
        "merge-base",
        ours,
        theirs
    )


    print(
        "BASE:",
        base
    )


    changes=[]


    changes.extend(
        collect_changes(
            base,
            ours
        )
    )


    changes.extend(
        collect_changes(
            base,
            theirs
        )
    )


    print("COMMITS:")

    for c in changes:

        print(
            c.timestamp,
            c.commit[:8],
            c.lines
        )


    changes.sort(
        key=lambda x:
            (
                x.timestamp,
                x.commit
            )
    )


    merged=[]


    for c in changes:

        merged.extend(
            c.lines
        )


    print(
        "MERGED LINES:",
        len(merged)
    )


    replace_table(
        ours_file,
        merged
    )


    return 0



if __name__ == "__main__":

    try:

        sys.exit(
            main()
        )

    except Exception as e:

        print(
            "ERROR:",
            e
        )

        sys.exit(1)