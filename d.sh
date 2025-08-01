gh issue list -s "all" -S "2411"
git checkout 2411
git branch -d 2210
git push --delete origin 2210
gh issue label --help
gh issue --help | grep label

gh issue comment 1052 


gh issue edit --help

gh issue edit --remove-label solving

gh issue edit 1053 --remove-label solving

gh issue close --help

# gh issue close 可以选择duplicated理由吗

gh issue close 1053 --comment "Duplicate of #1047"

gh issue comment 1053 -b "看来gh的duplicated和网页上操作的还是有点不一样的"

gh issue edit 1053 --add-label "duplicate"