'''
Author: LetMeFly
Date: 2026-07-04 16:41:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-05 18:21:02
'''
import os
import glob
import random
import string
import sys


def u32_hex(x: int) -> str:
    """转8位大写十六进制（32-bit）"""
    return f"{x & 0xFFFFFFFF:08X}"


def find_single(pattern: str) -> str:
    files = glob.glob(pattern)
    if len(files) != 1:
        raise RuntimeError(
            f"Expected exactly 1 file for {pattern}, got {len(files)}: {files}"
        )
    return files[0]


def fix_heic_filename(path: str) -> str:
    """
    保证HEIC文件名（含扩展名）长度为18。
    不满足则直接重命名文件。
    """
    folder = os.path.dirname(path)
    filename = os.path.basename(path)

    stem, ext = os.path.splitext(filename)

    TARGET = 18
    stem_len = TARGET - len(ext)

    if len(stem) > stem_len:
        new_stem = stem[:stem_len]
    elif len(stem) < stem_len:
        new_stem = stem + "".join(
            random.choices(
                string.ascii_letters + string.digits,
                k=stem_len - len(stem),
            )
        )
    else:
        new_stem = stem

    new_name = new_stem + ext

    if new_name == filename:
        return path

    new_path = os.path.join(folder, new_name)

    if os.path.exists(new_path):
        raise RuntimeError(f"目标文件已存在：{new_name}")

    os.rename(path, new_path)

    print(f"Rename: {filename} -> {new_name}")

    return new_path


def generate_comment(folder: str) -> str:
    heic_path = find_single(os.path.join(folder, "*.heic"))
    mov_path = find_single(os.path.join(folder, "*.mov"))

    # 保证HEIC文件名长度为18
    heic_path = fix_heic_filename(heic_path)

    heic_size = os.path.getsize(heic_path)
    mov_size = os.path.getsize(mov_path)

    heic_name = os.path.basename(heic_path)
    mov_name = os.path.basename(mov_path)

    part3 = heic_size
    part5 = part3 + (30 + len(heic_name)) + (30 + len(mov_name))
    part6 = mov_size

    if part3 < 0 or part3 > 0xFFFFFFFF:
        raise ValueError("HEIC size out of 32-bit range")
    if part5 > 0xFFFFFFFF:
        raise ValueError("part5 overflow 32-bit")

    comment = (
        "0002"
        "00000030"
        + u32_hex(part3)
        + "0003"
        + u32_hex(part5)
        + u32_hex(part6)
        + "313030304C495650"
    )

    return comment

# python livp.py ~/Downloads/Photos/IMG_5190
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python livp.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]
    print(generate_comment(folder))