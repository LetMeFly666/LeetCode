'''
Author: LetMeFly
Date: 2026-07-04 16:41:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-06 22:26:05
'''
import os
import shutil
import subprocess
import sys
import random
import string


IMAGE_EXTS = {
    ".heic",
    ".jpg",
    ".jpeg",
    ".png",
    ".gif",
    ".bmp",
    ".tif",
    ".tiff",
    ".webp",
}


def u32_hex(x: int) -> str:
    return f"{x & 0xFFFFFFFF:08X}"


def fix_len18(filename: str) -> str:
    stem, ext = os.path.splitext(filename)

    target = 18
    stem_len = target - len(ext)

    if len(stem) > stem_len:
        stem = stem[:stem_len]
    elif len(stem) < stem_len:
        stem += "".join(
            random.choices(
                string.ascii_letters + string.digits,
                k=stem_len - len(stem),
            )
        )

    return stem + ext


def generate_comment(heic_path: str, mov_path: str) -> str:
    heic_size = os.path.getsize(heic_path)
    mov_size = os.path.getsize(mov_path)

    # zip 中记录的是文件名，不含路径
    heic_name = os.path.basename(heic_path)
    mov_name = os.path.basename(mov_path)

    # Local File Header(30B) + 文件名长度
    offset = (30 + len(heic_name.encode("utf-8"))) + (
        30 + len(mov_name.encode("utf-8"))
    )

    part3 = heic_size
    part5 = part3 + offset
    part6 = mov_size

    if part5 > 0xFFFFFFFF:
        raise ValueError("HEIC file too large")  # 可能不到32-bit range就不行了
    if part6 > 0xFFFFFFFF:
        raise ValueError("MOV size out of 32-bit range")

    return (
        "0002"
        "00000030"
        + u32_hex(part3)
        + "0003"
        + u32_hex(part5)
        + u32_hex(part6)
        + "313030304C495650"
    )


def find_files(folder):
    files = [
        f
        for f in os.listdir(folder)
        if os.path.isfile(os.path.join(folder, f))
    ]

    heics = []
    movs = []
    images = []

    for f in files:
        ext = os.path.splitext(f)[1].lower()
        path = os.path.join(folder, f)

        if ext == ".heic":
            heics.append(path)
            images.append(path)
        elif ext == ".mov":
            movs.append(path)
        elif ext in IMAGE_EXTS:
            images.append(path)

    return heics, movs, images


def export_live(heic_path, mov_path, output_path):
    heic_dir = os.path.dirname(heic_path)
    heic_name = os.path.basename(heic_path)
    new_heic_name = fix_len18(heic_name)

    # 如果文件名需要修改，则临时复制一份
    temp_heic = heic_path
    need_delete = False

    if new_heic_name != heic_name:
        temp_heic = os.path.join(heic_dir, new_heic_name)
        shutil.copy2(heic_path, temp_heic)
        need_delete = True

    try:
        comment = generate_comment(temp_heic, mov_path)

        cmd = [
            "zip",
            "-0",
            "-X",
            "-z",
            output_path,
            os.path.basename(temp_heic),
            os.path.basename(mov_path),
        ]

        subprocess.run(
            cmd,
            cwd=heic_dir,
            input=comment + "\n",
            text=True,
            check=True,
        )
    finally:
        if need_delete:
            os.remove(temp_heic)


def process_parent(parent_folder):
    exported = os.path.join(parent_folder, "exported")
    os.makedirs(exported, exist_ok=True)

    errors = []
    success = 0

    for name in sorted(os.listdir(parent_folder)):
        folder = os.path.join(parent_folder, name)

        if not os.path.isdir(folder):
            continue

        if name == "exported":
            continue

        try:
            heics, movs, images = find_files(folder)

            # Live Photo
            if len(heics) == 1 and len(movs) == 1:
                output = os.path.join(exported, name + ".livp")
                export_live(heics[0], movs[0], output)
                success += 1
                continue

            # 静态图片
            if len(images) == 1 and len(movs) == 0:
                src = images[0]
                dst = os.path.join(exported, os.path.basename(src))
                shutil.copy2(src, dst)
                success += 1
                continue

            errors.append(
                f"{name}: "
                f"{len(heics)} heic, "
                f"{len(movs)} mov, "
                f"{len(images)} image(s)"
            )

        except Exception as e:
            errors.append(f"{name}: {e}")

    print(f"导出成功 {success} 个")

    if errors:
        print()
        print("=" * 60)
        print("以下目录处理失败：")
        for err in errors:
            print(" -", err)
        print("=" * 60)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage:")
        print("python livp.py <parent_folder>")
        sys.exit(1)

    process_parent(sys.argv[1])
