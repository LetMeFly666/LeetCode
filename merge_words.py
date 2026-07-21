#!/usr/bin/env python3

import sys
from pathlib import Path
import re


TARGET = "Solutions/Other-English-LearningNotes-SomeWords.md"



def is_word(line):

    return bool(
        re.match(
            r"^\|[^|]+\|[^|]+\|$",
            line
        )
    )



def table_end(lines):

    started=False

    for i,line in enumerate(lines):

        if is_word(line) or line=="|||":

            started=True

        elif started:

            return i


    return len(lines)



def table_part(lines):

    end=table_end(lines)

    return lines[:end]



def tail_after_ancestor(
    ancestor,
    branch
):

    """
    找 branch 比 ancestor 多出来的表格内容
    """

    a=table_part(ancestor)
    b=table_part(branch)


    if b[:len(a)]==a:

        return b[len(a):]


    # fallback:
    # 找公共前缀

    i=0

    while (
        i<len(a)
        and
        i<len(b)
        and
        a[i]==b[i]
    ):
        i+=1


    return b[i:]




def merge_separator(lines):

    """
    防止两个|||连续

    但只处理边界

    """

    result=[]

    for x in lines:

        if (
            x=="|||"
            and result
            and result[-1]=="|||"
        ):
            continue

        result.append(x)


    return result



def merge(
    ancestor_file,
    ours_file,
    theirs_file
):


    ancestor=Path(
        ancestor_file
    ).read_text(
        encoding="utf8"
    ).splitlines()


    ours=Path(
        ours_file
    ).read_text(
        encoding="utf8"
    ).splitlines()


    theirs=Path(
        theirs_file
    ).read_text(
        encoding="utf8"
    ).splitlines()



    base_table=table_part(
        ancestor
    )


    ours_add=tail_after_ancestor(
        ancestor,
        ours
    )


    theirs_add=tail_after_ancestor(
        ancestor,
        theirs
    )


    print(
        "OURS ADD:",
        ours_add
    )

    print(
        "THEIRS ADD:",
        theirs_add
    )


    merged = (
        base_table
        +
        ours_add
        +
        theirs_add
    )


    merged=merge_separator(
        merged
    )


    end=table_end(
        ancestor
    )


    result=(
        ancestor[:end]
        +
        merged[len(base_table):]
        +
        ancestor[end:]
    )


    Path(
        ours_file
    ).write_text(
        "\n".join(result)+"\n",
        encoding="utf8"
    )



def main():

    if len(sys.argv)!=4:

        print(
            "usage %O %A %B"
        )

        return 1


    ancestor,ours,theirs=sys.argv[1:]


    merge(
        ancestor,
        ours,
        theirs
    )


    return 0



if __name__=="__main__":

    sys.exit(
        main()
    )