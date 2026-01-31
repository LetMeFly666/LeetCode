#!/bin/bash
# for i in {1..5}; do
#     # echo "$i"
#     git commit --amend --no-edit >/dev/null 2>&1
#     SHA=$(git rev-parse HEAD)
#     echo "$SHA"
# done

# # ./beautiful.twich.sh
# # 91993a83a5073a11183e811758f8cc74680a7d00
# # 91993a83a5073a11183e811758f8cc74680a7d00
# # 91993a83a5073a11183e811758f8cc74680a7d00
# # 91993a83a5073a11183e811758f8cc74680a7d00
# # 91993a83a5073a11183e811758f8cc74680a7d00

while true; do
    # echo "$i"
    git commit --amend --no-edit >/dev/null 2>&1
    SHA=$(git rev-parse HEAD)
    echo "$SHA"
done

# 大约1秒一换