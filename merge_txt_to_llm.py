'''
Author: LetMeFly
Date: 2026-10-26 22:28:37
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-26 22:28:42
'''
from pathlib import Path
import sys

def main():
    folder = Path(sys.argv[1]) if len(sys.argv) > 1 else Path.cwd()

    if not folder.is_dir():
        print(f"文件夹不存在：{folder}")
        return

    output = folder / "汇总.txt"
    files = sorted(
        (p for p in folder.glob("*.txt") if p.resolve() != output.resolve()),
        key=lambda p: p.name.lower()
    )

    with output.open("w", encoding="utf-8") as f:
        for path in files:
            content = path.read_text(encoding="utf-8-sig")
            f.write(f"===== {path.name} =====\n")
            f.write(content)
            f.write("\n\n")

    print(f"已汇总 {len(files)} 个文件：{output}")

if __name__ == "__main__":
    main()