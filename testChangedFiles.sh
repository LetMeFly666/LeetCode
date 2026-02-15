###
 # @Author: LetMeFly
 # @Date: 2026-02-15 15:20:26
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-02-15 15:20:38
### 
CHANGED_FILES=$(git diff --name-only || true)
# 去掉前后可能的双引号
CHANGED_FILES=$(echo "$CHANGED_FILES" | sed 's/^"//;s/"$//')

if echo "$CHANGED_FILES" | grep -q '^Solutions/'; then
    echo "Solutions changed, deploy"
else
    echo "No Solutions changes, skip deploy"
fi
