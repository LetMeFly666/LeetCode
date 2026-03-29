#!/bin/bash
# 将 list-diff.txt 中列举的文件（来自 "mp3+m4a版音乐"）压缩为 zip
# 密码 LetMeFly，最高压缩等级，放到 diff 文件夹

mkdir -p diff

while IFS= read -r filename; do
    [ -z "$filename" ] && continue
    srcfile="mp3+m4a版音乐/${filename}"
    outzip="diff/${filename}.zip"
    if [ -f "$srcfile" ]; then
        echo "压缩: $filename -> $outzip"
        7z a -tzip -p'LetMeFly' -mx=9 "$outzip" "$srcfile"
    else
        echo "警告: 文件不存在 $srcfile"
    fi
done < list-diff.txt

echo "全部压缩完成。"
