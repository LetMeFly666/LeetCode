
import subprocess
import sys
import re
from pathlib import Path


TARGET = "Solutions/Other-English-LearningNotes-SomeWords.md"


def git(*args):
    return subprocess.check_output(
        ["git", *args],
        text=True
    ).strip()



def commit_time(commit):
    return int(
        git(
            "show",
            "-s",
            "--format=%ct",
            commit
        )
    )



def commits_between(base, head):
    """
    获取 base..head 中所有commit
    从旧到新
    """

    result = git(
        "rev-list",
        "--reverse",
        f"{base}..{head}"
    )

    if not result:
        return []

    return result.splitlines()



def file_added_by_commit(commit):
    """
    获取某一次commit针对目标文件新增内容
    """

    try:

        diff = git(
            "show",
            "--format=",
            "--unified=0",
            commit,
            "--",
            TARGET
        )

    except subprocess.CalledProcessError:
        return []


    result=[]

    for line in diff.splitlines():

        if (
            line.startswith("+")
            and not line.startswith("+++")
        ):
            result.append(
                line[1:]
            )


    return result



def is_word(line):

    return bool(
        re.match(
            r"^\|[^|]+\|[^|]+\|$",
            line
        )
    )



def collect_commits(base, head):

    commits=[]

    for c in commits_between(base, head):

        lines=file_added_by_commit(c)

        words=[]

        for line in lines:

            if is_word(line) or line=="|||":

                words.append(line)


        if words:

            commits.append(
                {
                    "hash": c,
                    "time": commit_time(c),
                    "lines": words
                }
            )


    return commits



def find_table(lines):

    start=None
    end=None


    for i,line in enumerate(lines):

        if is_word(line):

            if start is None:
                start=i

        elif start is not None:

            end=i
            break


    if start is None:
        raise RuntimeError(
            "cannot locate markdown table"
        )


    if end is None:
        end=len(lines)


    return start,end



def main():


    # merge driver:
    # %O ancestor file
    # %A current file
    # %B other file


    if len(sys.argv)!=4:
        print(
            "usage: merge_words.py %O %A %B"
        )
        return 1


    ancestor_file=sys.argv[1]


    # 当前HEAD
    try:
        current_commit=git(
            "rev-parse",
            "HEAD"
        )

        other_commit=git(
            "rev-parse",
            "MERGE_HEAD"
        )

    except Exception as e:

        print(e)
        return 1



    base_commit=git(
        "merge-base",
        current_commit,
        other_commit
    )


    print(
        "base:",
        base_commit
    )


    commits=[]


    commits.extend(
        collect_commits(
            base_commit,
            current_commit
        )
    )


    commits.extend(
        collect_commits(
            base_commit,
            other_commit
        )
    )


    # 按真实commit时间排序

    commits.sort(
        key=lambda x: (
            x["time"],
            x["hash"]
        )
    )


    merged=[]


    for c in commits:

        merged.extend(
            c["lines"]
        )


    # 读取当前文件

    target=Path(TARGET)

    text=target.read_text(
        encoding="utf-8"
    )

    lines=text.splitlines()


    start,end=find_table(lines)


    new_lines=(
        lines[:start]
        +
        merged
        +
        lines[end:]
    )


    target.write_text(
        "\n".join(new_lines)+"\n",
        encoding="utf-8"
    )


    return 0



if __name__=="__main__":

    sys.exit(main())
