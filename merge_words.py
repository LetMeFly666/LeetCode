#!/usr/bin/env python3

import os
import sys
import subprocess
from pathlib import Path


def run(*args):
    print("$ git", *args)

    r = subprocess.run(
        ["git", *args],
        text=True,
        capture_output=True
    )

    print("return:", r.returncode)

    if r.stdout:
        print("stdout:")
        print(r.stdout)

    if r.stderr:
        print("stderr:")
        print(r.stderr)

    return r.stdout.strip()



def main():

    print("=" * 80)

    print("ARGV:")
    for i, x in enumerate(sys.argv):
        print(i, repr(x))


    print()
    print("FILES:")

    for x in sys.argv[1:]:
        p = Path(x)

        print(
            x,
            "exists=",
            p.exists(),
            "size=",
            p.stat().st_size if p.exists() else None
        )


    print()
    print("HASH:")

    for x in sys.argv[1:]:

        run(
            "hash-object",
            "--path",
            "Solutions/Other-English-LearningNotes-SomeWords.md",
            x
        )


    print()
    print("GIT STATUS")

    run(
        "status",
        "--short"
    )


    print()
    print("INDEX UNMERGED")

    run(
        "ls-files",
        "-u"
    )


    print()
    print("HEAD")

    run(
        "rev-parse",
        "HEAD"
    )


    print()
    print("MERGE_HEAD")

    run(
        "rev-parse",
        "MERGE_HEAD"
    )


    print()
    print("ENV")

    for k,v in sorted(os.environ.items()):

        if k.startswith("GIT"):

            print(
                k,
                "=",
                v
            )


    print("=" * 80)


    # 暂时告诉 git merge driver 成功
    # 不然一直 conflict
    return 0



if __name__=="__main__":
    sys.exit(main())