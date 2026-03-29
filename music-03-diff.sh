#!/bin/bash
# 比较 "mp3+m4a版音乐" 和 original，按无后缀文件名对比
# 生成 list-original.txt 和 list-diff.txt

> list-original.txt
> list-diff.txt

# 列出 original 中所有文件名（带后缀）
for f in original/*; do
    [ -f "$f" ] || continue
    basename "$f" >> list-original.txt
done

# 构建 original 中无后缀文件名集合
declare -A original_names
while IFS= read -r line; do
    name="${line%.*}"
    original_names["$name"]=1
done < list-original.txt

# 遍历 mp3+m4a版音乐，找出 original 中不存在的（按无后缀名比较）
for f in "mp3+m4a版音乐"/*; do
    [ -f "$f" ] || continue
    filename="$(basename "$f")"
    name="${filename%.*}"
    if [ -z "${original_names[$name]+x}" ]; then
        echo "$filename" >> list-diff.txt
    fi
done

echo "list-original.txt 和 list-diff.txt 已生成。"
