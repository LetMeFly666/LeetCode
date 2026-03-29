#!/bin/bash
# 将 original 下每个文件重新压缩为 zip（带原始后缀），最高压缩等级，密码 LetMeFly

mkdir -p GoodMusic-zipped

for filepath in original/*; do
    [ -f "$filepath" ] || continue
    filename="$(basename "$filepath")"
    outzip="GoodMusic-zipped/${filename}.zip"
    echo "压缩: $filename -> $outzip"
    7z a -tzip -p'LetMeFly' -mx=9 "$outzip" "$filepath"
done

echo "全部压缩完成。"
