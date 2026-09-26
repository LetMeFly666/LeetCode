'''
Author: LetMeFly
Date: 2026-02-15 21:15:07
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-15 21:16:19
Usage: python mergeImage.py left.png right.png merged.png
'''
from PIL import Image
import sys

img1_path, img2_path, out_path = sys.argv[1:4]

img1 = Image.open(img1_path)
img2 = Image.open(img2_path)

if img1.size != img2.size:
    raise ValueError("两张图片尺寸不一致")

w, h = img1.size

# 新图，尺寸不变
out = Image.new(img1.mode, (w, h))

# 左半边：图片1
out.paste(img1.crop((0, 0, w // 2, h)), (0, 0))

# 右半边：图片2
out.paste(img2.crop((w // 2, 0, w, h)), (w // 2, 0))

out.save(out_path)
