has_modified=false
###
 # @Author: LetMeFly
 # @Date: 2026-01-13 10:11:54
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-01-13 10:17:53
### 
while IFS= read -r -d '' status && IFS= read -r -d '' file; do
    [[ "$file" == Solutions/*.md ]] || continue

    filename=$(basename "$file")
    has_modified=true
    echo "($status)$filename"

    case "$status" in
        A|M)
        echo "Updated $filename"
        # json_content=$(echo "$json_content" | jq \
        #     --arg k "$filename" \
        #     --arg v "$commit_time" \
        #     '. + {($k): $v}')
        ;;
        D)
        # echo "Deleted $filename"
        # json_content=$(echo "$json_content" | jq \
        #     --arg k "$filename" \
        #     'del(.[$k])')
        ;;
    esac
done < <(git diff --name-status -z HEAD~1 HEAD)

echo $has_modified

# D       .commitTitleExtra
# D       .commitmsg
# M       .github/workflows/deployHexo.yml
# A       Codes/1266-minimum-time-visiting-all-points.cpp
# A       Codes/1266-minimum-time-visiting-all-points.go
# A       Codes/1266-minimum-time-visiting-all-points.java
# A       Codes/1266-minimum-time-visiting-all-points.py
# A       Codes/1266-minimum-time-visiting-all-points.rs
# M       Codes/lib.rs
# M       README.md
# A       "Solutions/LeetCode 1266.\350\256\277\351\227\256\346\211\200\346\234\211\347\202\271\347\232\204\346\234\200\345\260\217\346\227\266\351\227\264.md"
# M       Solutions/Other-English-LearningNotes-SomeWords.md

# 几年前没经验啊，还有空格还有中文
# 体验了一波向下兼容
