#!/usr/bin/env python3

import sys
from pathlib import Path
import re
import difflib



def is_table_line(line):

    return (
        line == "|||"
        or
        bool(
            re.match(
                r"^\|.*\|.*\|$",
                line
            )
        )
    )



def find_table_range(lines):

    start=None
    end=None


    for i,line in enumerate(lines):

        if is_table_line(line):

            start=i
            break


    if start is None:

        raise Exception(
            "cannot find table"
        )


    empty_count=0


    for i in range(start,len(lines)):

        line=lines[i]


        if is_table_line(line):

            empty_count=0
            continue


        if line.strip()=="":
            empty_count+=1

            # 一个空行允许
            continue


        # 非表格内容
        if empty_count>=1:

            end=i-empty_count
            break


    if end is None:
        end=len(lines)


    return start,end



def extract_table(lines):

    s,e=find_table_range(lines)

    return lines[s:e]



def after_common_prefix(base, branch):

    """
    获取branch相对于base新增部分
    """

    i=0


    while (
        i<len(base)
        and
        i<len(branch)
        and
        base[i]==branch[i]
    ):
        i+=1


    return branch[i:]



def remove_duplicate_boundary(lines):

    """
    只处理边界重复

    不删除两个新增session
    """

    result=[]


    for x in lines:

        if (
            result
            and
            x=="|||"
            and
            result[-1]=="|||"
        ):
            continue

        result.append(x)


    return result



def merge_file(
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



    as_,ae=find_table_range(
        ancestor
    )

    os_,oe=find_table_range(
        ours
    )

    ts_,te=find_table_range(
        theirs
    )


    ancestor_table=ancestor[as_:ae]

    ours_table=ours[os_:oe]

    theirs_table=theirs[ts_:te]



    ours_new=after_common_prefix(
        ancestor_table,
        ours_table
    )


    theirs_new=after_common_prefix(
        ancestor_table,
        theirs_table
    )


    print(
        "OURS NEW:",
        ours_new
    )

    print(
        "THEIRS NEW:",
        theirs_new
    )



    merged_table=(
        ancestor_table
        +
        ours_new
        +
        theirs_new
    )


    merged_table=remove_duplicate_boundary(
        merged_table
    )


    result=(
        ours[:os_]
        +
        merged_table
        +
        ours[oe:]
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
            "usage: merge_words.py %O %A %B"
        )

        return 1


    merge_file(
        sys.argv[1],
        sys.argv[2],
        sys.argv[3]
    )


if __name__=="__main__":

    main()