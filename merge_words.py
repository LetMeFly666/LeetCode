import sys
import subprocess
import re
from pathlib import Path


TARGET_FILE = "Solutions/Other-English-LearningNotes-SomeWords.md"


def get_commit_time(commit):
    """
    获取commit时间
    """
    result = subprocess.check_output(
        [
            "git",
            "show",
            "-s",
            "--format=%ct",
            commit,
        ],
        text=True,
    )

    return int(result.strip())


def get_added_lines(base, branch):
    """
    获取branch相对于base新增内容
    """

    diff = subprocess.check_output(
        [
            "git",
            "diff",
            "--unified=0",
            base,
            branch,
            "--",
            TARGET_FILE,
        ],
        text=True,
    )

    lines = []

    for line in diff.splitlines():

        # 只取新增
        if line.startswith("+") and not line.startswith("+++"):
            lines.append(line[1:])

    return lines


def extract_words(lines):

    result = []

    for line in lines:

        # 单词表格
        m = re.match(
            r"\|([^|]+)\|([^|]+)\|",
            line
        )

        if m:
            result.append(
                {
                    "type": "word",
                    "content": line,
                }
            )

        # 分隔
        elif line.strip() == "|||":
            result.append(
                {
                    "type": "separator",
                    "content": "|||",
                }
            )

    return result



def main():

    ancestor = sys.argv[1]
    current = sys.argv[2]
    other = sys.argv[3]


    current_time = get_commit_time(current)
    other_time = get_commit_time(other)


    additions = []


    for commit in [
        (current, current_time),
        (other, other_time),
    ]:

        lines = get_added_lines(
            ancestor,
            commit[0]
        )

        additions.append(
            (
                commit[1],
                extract_words(lines)
            )
        )


    # 按commit时间排序
    additions.sort(
        key=lambda x:x[0]
    )


    merged=[]


    for _, items in additions:

        for item in items:

            merged.append(
                item["content"]
            )


    # 去掉连续重复空行
    output=[]

    last_sep=False

    for line in merged:

        if line=="|||":

            if last_sep:
                continue

            last_sep=True

        else:
            last_sep=False


        output.append(line)


    # 取当前文件作为基础
    current_file=Path(TARGET_FILE)

    text=current_file.read_text()


    # 找到表格区域
    lines=text.splitlines()


    start=None
    end=None


    for i,l in enumerate(lines):

        if re.match(
            r"\|[^|]+\|[^|]+\|",
            l
        ):
            if start is None:
                start=i

        elif start is not None:
            end=i
            break


    if start is None:
        print("cannot find table")
        return 1


    if end is None:
        end=len(lines)


    new_lines = (
        lines[:start]
        +
        output
        +
        lines[end:]
    )


    current_file.write_text(
        "\n".join(new_lines)+"\n"
    )


    return 0



if __name__=="__main__":
    sys.exit(main())
