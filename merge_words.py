#!/usr/bin/env python3

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
git failed:

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


    print("\nGITHEAD:")

    for k, v in os.environ.items():

        if k.startswith("GITHEAD_"):

            print(k, v)


    print("=" * 80)



def get_merge_commits():

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
            "cannot find GITHEAD"
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
        "--ancestry-path",
        f"{base}..{head}"
    )


    if not result:

        return []


    return result.splitlines()



def is_word(line):

    # ||| 是 session separator，不是单词记录
    if line == "|||":
        return False

    # 支持：
    # |word|meaning|
    # |1||
    # ||2|
    # |a|b|
    return bool(
        re.match(
            r"^\|.*\|.*\|$",
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


            if content == "|||":

                result.append(content)

            elif is_word(content):

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
    找表格结束位置

    支持:

    |word|meaning|
    |||

    """

    started=False


    for i,line in enumerate(lines):

        if (
            is_word(line)
            or line=="|||"
        ):

            started=True

            continue


        if started:

            if line.strip()=="":
                continue


            return i


    return len(lines)



def replace_table(
    ancestor_file,
    output_file,
    merged_lines
):


    ancestor = Path(
        ancestor_file
    ).read_text(
        encoding="utf-8"
    )


    lines = ancestor.splitlines()



    end = find_table_end(
        lines
    )


    new_lines = (
        lines[:end]
        +
        merged_lines
        +
        lines[end:]
    )


    Path(output_file).write_text(
        "\n".join(new_lines)
        +
        "\n",
        encoding="utf-8"
    )



def main():

    if len(sys.argv)!=4:

        print(
            "usage: merge_words.py %O %A %B"
        )

        return 1



    ancestor_file=sys.argv[1]

    ours_file=sys.argv[2]

    theirs_file=sys.argv[3]


    debug()


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



    print("\nCOMMITS:")

    for c in changes:

        print(
            c.timestamp,
            c.commit[:8],
            c.lines
        )



    # 关键：
    # 按真实 commit 时间排序

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
        "\nMERGED:"
    )

    for x in merged:

        print(x)



    replace_table(
        ancestor_file,
        ours_file,
        merged
    )


    return 0



if __name__=="__main__":

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