#!/bin/bash
# 将 GoodMusic 下所有 zip 文件解压到 original 文件夹，密码 LetMeFly

mkdir -p original

for zipfile in GoodMusic/*.zip; do
    [ -f "$zipfile" ] || continue
    echo "解压: $zipfile"
    7z x -p'LetMeFly' -o'original' -y "$zipfile"
done

echo "全部解压完成。"
