#!/bin/bash
###
 # @Author: LetMeFly
 # @Date: 2026-03-29 20:15:24
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-03-29 20:59:43
### 
# 比较 "mp3+m4a版音乐" 和 "original" 文件夹
# 生成 list-original.txt 和 list-diff.txt

# 1. 列出 original 中所有文件名（含后缀）
ls -1 original > list-original.txt

# 2. 提取 original 中所有无后缀文件名，排序去重，写入临时文件
tmp_orig=$(mktemp)
for f in original/*; do
    basename "$f" | sed 's/\.[^.]*$//'
done | sort -u > "$tmp_orig"

# 3. 遍历 "mp3+m4a版音乐" 中的文件，检查无后缀名是否在 original 中出现过
> list-diff.txt
for f in "mp3+m4a版音乐"/*; do
    fullname=$(basename "$f")
    stem=$(echo "$fullname" | sed 's/\.[^.]*$//')
    if ! grep -qxF "$stem" "$tmp_orig"; then
        echo "$fullname" >> list-diff.txt
    fi
done

rm -f "$tmp_orig"
echo "list-original.txt 和 list-diff.txt 已生成。"