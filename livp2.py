'''
Author: LetMeFly
Date: 2026-07-04 16:41:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-05 10:20:24
'''
import os
import shutil
import subprocess
import sys


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


def generate_comment(heic_path: str, mov_path: str) -> str:
    heic_size = os.path.getsize(heic_path)
    mov_size = os.path.getsize(mov_path)

    part3 = heic_size
    part5 = part3 + 0x5F
    part6 = mov_size

    if part5 > 0xFFFFFFFF:
        raise ValueError("HEIC file too large")

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
    comment = generate_comment(heic_path, mov_path)

    cmd = [
        "zip",
        "-0",
        "-X",
        "-z",
        output_path,
        os.path.basename(heic_path),
        os.path.basename(mov_path),
    ]

    subprocess.run(
        cmd,
        cwd=os.path.dirname(heic_path),
        input=comment + "\n",
        text=True,
        check=True,
    )


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
