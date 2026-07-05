'''
Author: LetMeFly
Date: 2026-07-04 16:41:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-05 10:24:28
'''
import os
import glob
import sys

def u32_hex(x: int) -> str:
    """转 8位大写十六进制（32-bit）"""
    return f"{x & 0xFFFFFFFF:08X}"

def find_single(pattern: str) -> str:
    files = glob.glob(pattern)
    if len(files) != 1:
        raise RuntimeError(f"Expected exactly 1 file for {pattern}, got {len(files)}: {files}")
    return files[0]

def generate_comment(folder: str) -> str:
    # heic_path = find_single(os.path.join(folder, "*.HEIC.heic"))
    # mov_path  = find_single(os.path.join(folder, "*.HEIC.mov"))
    heic_path = find_single(os.path.join(folder, "*.heic"))
    mov_path  = find_single(os.path.join(folder, "*.mov"))

    heic_size = os.path.getsize(heic_path)
    mov_size  = os.path.getsize(mov_path)

    # part3 / part5 / part6
    part3 = heic_size
    part6 = mov_size

    # part5 = part3 + 0x5F (必须保证 32-bit 不溢出)
    part5 = part3 + 0x5F

    if part3 < 0 or part3 > 0xFFFFFFFF:
        raise ValueError("HEIC size out of 32-bit range")
    if part5 > 0xFFFFFFFF:
        raise ValueError("part5 overflow 32-bit, invalid HEIC size")

    part1 = "0002"
    part2 = "00000030"
    part4 = "0003"
    part7 = "313030304C495650"

    comment = (
        part1 +
        part2 +
        u32_hex(part3) +
        part4 +
        u32_hex(part5) +
        u32_hex(part6) +
        part7
    )

    return comment

# python livp.py ~/Downloads/2026-06-18_162750
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python livp.py <folder>")
        sys.exit(1)

    folder = sys.argv[1]
    print(generate_comment(folder))