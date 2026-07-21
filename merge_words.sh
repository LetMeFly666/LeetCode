#!/bin/zsh
###
 # @Author: LetMeFly
 # @Date: 2026-07-21 15:57:42
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-07-21 15:58:54
### 

set -e


BASE=$1
CURRENT_FILE=$2
OTHER_FILE=$3

echo "BASE: $BASE"
echo "CURRENT_FILE: $CURRENT_FILE"
echo "OTHER_FILE: $OTHER_FILE"


CURRENT=$(git rev-parse HEAD)


# MERGE_HEAD 不一定存在
# 使用正在merge的目标commit

if git rev-parse MERGE_HEAD >/dev/null 2>&1
then
    OTHER=$(git rev-parse MERGE_HEAD)
else

    echo "MERGE_HEAD unavailable"

    # fallback:
    # 从MERGE_MSG找
    OTHER=$(git rev-parse FETCH_HEAD 2>/dev/null || true)

fi


if [ -z "$OTHER" ]; then
    echo "cannot find other commit"
    exit 1
fi


python3 merge_words.py \
    "$BASE" \
    "$CURRENT_FILE" \
    "$OTHER"
