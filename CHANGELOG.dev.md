PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git pull origin dev
remote: Enumerating objects: 8, done.
remote: Counting objects: 100% (8/8), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 5 (delta 3), reused 5 (delta 3), pack-reused 0 (from 0)
Unpacking objects: 100% (5/5), 6.63 KiB | 29.00 KiB/s, done.
From github.com:LetMeFly666/LeetCode
 * branch                dev        -> FETCH_HEAD
   8dae6ce93..ed9d93443  dev        -> origin/dev
Updating 8dae6ce93..ed9d93443
Fast-forward
 .github/workflows/deployHexo.yml                   |   3 +-
 CHANGELOG                                          |  93 -----
 CHANGELOG.md                                       | 118 ++++++
 Codes/0040-combination-sum-ii.cpp                  |  66 +++
 Codes/0040-combination-sum-ii.go                   |  35 ++
 Codes/0040-combination-sum-ii.java                 |  40 ++
 Codes/0040-combination-sum-ii.py                   |  30 ++
 Codes/0045-jump-game-ii.cpp                        |  24 ++
 Codes/0045-jump-game-ii.go                         |  19 +
 Codes/0045-jump-game-ii.java                       |  19 +
 Codes/0045-jump-game-ii.py                         |  23 ++
 Codes/0047-permutations-ii_20250206-BuiltIn.cpp    |  21 +
 Codes/0047-permutations-ii_20250206-BuiltIn.py     |  12 +
 Codes/0047-permutations-ii_20250206-HuiSu.cpp      |  37 ++
 Codes/0047-permutations-ii_20250206-HuiSu.go       |  34 ++
 Codes/0047-permutations-ii_20250206-HuiSu.java     |  41 ++
 Codes/0047-permutations-ii_20250206-HuiSu.py       |  29 ++
 Codes/0059-spiral-matrix-ii_20250207.cpp           |  31 ++
 Codes/0059-spiral-matrix-ii_20250207.go            |  32 ++
 Codes/0059-spiral-matrix-ii_20250207.java          |  27 ++
 Codes/0059-spiral-matrix-ii_20250207.py            |  24 ++
 Codes/0063-unique-paths-ii_20250208.cpp            |  50 +++
 Codes/0063-unique-paths-ii_20250208.go             |  29 ++
 Codes/0063-unique-paths-ii_20250208.java           |  29 ++
 Codes/0063-unique-paths-ii_20250208.py             |  21 +
 ...0080-remove-duplicates-from-sorted-array-ii.cpp |   4 +-
 ...ve-duplicates-from-sorted-array-ii_20250209.cpp |  22 +
 ...ove-duplicates-from-sorted-array-ii_20250209.go |  18 +
 ...e-duplicates-from-sorted-array-ii_20250209.java |  17 +
 ...ove-duplicates-from-sorted-array-ii_20250209.py |  16 +
 Codes/0090-subsets-ii_20250205-HuiSu.cpp           |  38 ++
 Codes/0090-subsets-ii_20250205-HuiSu.go            |  41 ++
 Codes/0090-subsets-ii_20250205-HuiSu.java          |  39 ++
 Codes/0090-subsets-ii_20250205-HuiSu.py            |  29 ++
 Codes/0090-subsets-ii_20250205.cpp                 |  29 ++
 Codes/0119-pascals-triangle-ii_20250128-ChuXi.cpp  |  24 ++
 ...0219-contains-duplicate-ii_20250129-ChunJie.cpp |  23 ++
 .../0219-contains-duplicate-ii_20250129-ChunJie.go |  18 +
 ...219-contains-duplicate-ii_20250129-ChunJie.java |  20 +
 .../0219-contains-duplicate-ii_20250129-ChunJie.py |  16 +
 ...0350-intersection-of-two-arrays-ii_20250130.cpp |  43 ++
 .../0350-intersection-of-two-arrays-ii_20250130.go |  21 +
 ...350-intersection-of-two-arrays-ii_20250130.java |  28 ++
 .../0350-intersection-of-two-arrays-ii_20250130.py |  18 +
 Codes/0541-reverse-string-ii_20250131.cpp          |  23 ++
 Codes/0541-reverse-string-ii_20250131.go           |  17 +
 Codes/0541-reverse-string-ii_20250131.java         |  24 ++
 Codes/0541-reverse-string-ii_20250131.py           |  12 +
 Codes/0598-range-addition-ii_20250202.cpp          |  20 +
 Codes/0598-range-addition-ii_20250202.go           |  22 +
 Codes/0598-range-addition-ii_20250202.java         |  15 +
 Codes/0598-range-addition-ii_20250202.py           |  14 +
 Codes/0624-maximum-distance-in-arrays.cpp          |  34 ++
 Codes/0624-maximum-distance-in-arrays.go           |  16 +
 Codes/0624-maximum-distance-in-arrays.java         |  21 +
 Codes/0624-maximum-distance-in-arrays.py           |  16 +
 Codes/0680-valid-palindrome-ii.cpp                 |  30 ++
 Codes/0680-valid-palindrome-ii.go                  |  25 ++
 Codes/0680-valid-palindrome-ii.java                |  25 ++
 Codes/0680-valid-palindrome-ii.py                  |  23 ++
 Codes/0922-sort-array-by-parity-ii.cpp             |  46 +++
 Codes/0922-sort-array-by-parity-ii.go              |  22 +
 Codes/0922-sort-array-by-parity-ii.java            |  24 ++
 Codes/0922-sort-array-by-parity-ii.py              |  21 +
 ...ment-appearing-more-than-25-in-sorted-array.cpp |  21 +
 ...ement-appearing-more-than-25-in-sorted-array.go |  17 +
 ...ent-appearing-more-than-25-in-sorted-array.java |  16 +
 ...ement-appearing-more-than-25-in-sorted-array.py |  15 +
 ...lements-with-greatest-element-on-right-side.cpp |  22 +
 ...elements-with-greatest-element-on-right-side.go |  24 ++
 ...ements-with-greatest-element-on-right-side.java |  17 +
 ...elements-with-greatest-element-on-right-side.py |  14 +
 Codes/1552-magnetic-force-between-two-balls.cpp    |  40 ++
 Codes/1552-magnetic-force-between-two-balls.go     |  37 ++
 Codes/1552-magnetic-force-between-two-balls.java   |  40 ++
 Codes/1552-magnetic-force-between-two-balls.py     |  30 ++
 Codes/1706-where-will-the-ball-fall_20250215.cpp   |  32 ++
 Codes/1706-where-will-the-ball-fall_20250215.go    |  26 ++
 Codes/1706-where-will-the-ball-fall_20250215.java  |  29 ++
 Codes/1706-where-will-the-ball-fall_20250215.py    |  25 ++
 ...2-maximum-number-of-balls-in-a-box_20250213.cpp |  29 ++
 ...42-maximum-number-of-balls-in-a-box_20250213.go |  32 ++
 ...-maximum-number-of-balls-in-a-box_20250213.java |  26 ++
 ...42-maximum-number-of-balls-in-a-box_20250213.py |  18 +
 ...-maximum-number-of-balls-in-a-box_20250213_2.py |  11 +
 ...60-minimum-limit-of-balls-in-a-bag_20250212.cpp |  29 ++
 ...60-minimum-limit-of-balls-in-a-bag_20250213.cpp |  32 ++
 ...760-minimum-limit-of-balls-in-a-bag_20250213.go |  29 ++
 ...0-minimum-limit-of-balls-in-a-bag_20250213.java |  37 ++
 ...760-minimum-limit-of-balls-in-a-bag_20250213.py |  24 ++
 Codes/2080-range-frequency-queries.cpp             |  35 ++
 Codes/2080-range-frequency-queries.go              |  34 ++
 Codes/2080-range-frequency-queries.java            |  38 ++
 Codes/2080-range-frequency-queries.py              |  28 ++
 ...imum-white-tiles-after-covering-with-carpet.cpp |  57 +++
 ...nimum-white-tiles-after-covering-with-carpet.go |  32 ++
 ...mum-white-tiles-after-covering-with-carpet.java |  40 ++
 ...nimum-white-tiles-after-covering-with-carpet.py |  23 ++
 ...-minimum-money-required-before-transactions.cpp | 108 +++++
 ...-money-required-before-transactions_JianHua.cpp |  24 ++
 ...m-money-required-before-transactions_JianHua.go |  31 ++
 ...money-required-before-transactions_JianHua.java |  17 +
 ...m-money-required-before-transactions_JianHua.py |  11 +
 Codes/2506-count-pairs-of-similar-strings.cpp      |  31 ++
 Codes/2506-count-pairs-of-similar-strings.go       |  25 ++
 Codes/2506-count-pairs-of-similar-strings.java     |  29 ++
 Codes/2506-count-pairs-of-similar-strings.py       |  24 ++
 Codes/2595-number-of-even-and-odd-bits.cpp         |  23 ++
 Codes/2595-number-of-even-and-odd-bits.go          |  16 +
 Codes/2595-number-of-even-and-odd-bits.java        |  18 +
 Codes/2595-number-of-even-and-odd-bits.py          |  17 +
 Codes/2944-minimum-number-of-coins-for-fruits.cpp  |  46 +++
 README.md                                          |  30 +-
 Solutions/LeetCode 0040.组合总和II.md              | 239 +++++++++++
 Solutions/LeetCode 0045.跳跃游戏II.md              | 178 +++++++++
 Solutions/LeetCode 0047.全排列II.md                | 291 ++++++++++++++
 Solutions/LeetCode 0059.螺旋矩阵II.md              | 187 +++++++++
 Solutions/LeetCode 0063.不同路径II.md              | 207 ++++++++++
 .../LeetCode 0080.删除有序数组中的重复项II.md      | 214 ++++++++++
 Solutions/LeetCode 0090.子集II.md                  | 267 +++++++++++++
 Solutions/LeetCode 0141.环形链表.md                |   2 +-
 Solutions/LeetCode 0219.存在重复元素II.md          | 157 ++++++++
 Solutions/LeetCode 0350.两个数组的交集II.md        | 124 +++++-
 Solutions/LeetCode 0541.反转字符串II.md            | 151 +++++++
 Solutions/LeetCode 0598.区间加法II.md              | 161 ++++++++
 Solutions/LeetCode 0624.数组列表中的最大距离.md    | 195 +++++++++
 Solutions/LeetCode 0680.验证回文串II.md            | 189 +++++++++
 Solutions/LeetCode 0922.按奇偶排序数组II.md        | 176 ++++++++
 ...LeetCode 1287.有序数组中出现次数超过25的元素.md | 135 +++++++
 .../LeetCode 1299.将每个元素替换为右侧最大元素.md  | 160 ++++++++
 Solutions/LeetCode 1552.两球之间的磁力.md          | 231 +++++++++++
 Solutions/LeetCode 1706.球会落何处.md              | 217 ++++++++++
 Solutions/LeetCode 1742.盒子中小球的最大数量.md    | 132 +++++-
 Solutions/LeetCode 1760.袋子里最少数目的球.md      | 150 ++++++-
 Solutions/LeetCode 2080.区间内查询数字的频率.md    | 176 ++++++++
 .../LeetCode 2209.用地毯覆盖后的最少白色砖块.md    | 235 +++++++++++
 .../LeetCode 2412.完成所有交易的初始最少钱数.md    | 442 +++++++++++++++++++++
 Solutions/LeetCode 2506.统计相似字符串对的数目.md  | 209 ++++++++++
 Solutions/LeetCode 2595.奇偶位数.md                | 165 ++++++++
 .../LeetCode 2944.购买水果需要的最少金币数.md      | 157 ++++++++
 Solutions/Other-Accumulation-Messy.md              | 129 ++++++
 Solutions/Other-Accumulation-SomeTips.md           |  36 ++
 Solutions/Other-English-LearningNotes-SomeWords.md |  68 +++-
 ...-Farewell-WhatIsEasilyDoneAtHomeButNotSchool.md |   3 +-
 ...ther-Github-CreatingIssuePrMergingPrByCMD-GH.md |   2 +-
 Solutions/Other-Github-PrCredentialLeakFix.md      | 102 +++++
 ...b-Record1Contribution2BytedanceCloudwegoDocs.md |  92 +++++
 Solutions/Other-Japanese-LearningNotes.md          |  95 ++++-
 Solutions/Other-Notes-Mianjing.md                  |  47 +++
 ...elfHostPasswordToolUsingBitwardenVaultWarden.md |  96 +++++
 .../Other-Windows-LoginWindowsWithoutPassword.md   |   2 +-
 Solutions/Other-Windows-OpenUIbySSH.md             |  66 +++
 ...LSchemeForYourApplicationWithoutUACOnWindows.md |  17 +-
 newSolution.py                                     |  21 +-
 tryGoPy/.gitkeep                                   |   3 +
 tryGoPy/BUG!/{ => cf}/README.md                    |   0
 tryGoPy/BUG!/{ => cf}/renderResult_main.js         |   0
 tryGoPy/BUG!/git/commit.md                         |  63 +++
 tryGoPy/BUG!/hexo/Readme.md                        |  10 +
 tryGoPy/BUG!/obs/Readme.md                         |   9 +
 tryGoPy/Go/douyinec/.gitignore                     |   1 -
 tryGoPy/Go/douyinec/README.md                      |  49 ---
 tryGoPy/{ => MGJW/下周}/WireSharker.py             |   0
 tryGoPy/{ => MGJW/下周}/周报-下周.md               |   0
 tryGoPy/public-专家意见                            |  16 -
 165 files changed, 9080 insertions(+), 204 deletions(-)
 delete mode 100644 CHANGELOG
 create mode 100644 CHANGELOG.md
 create mode 100644 Codes/0040-combination-sum-ii.cpp
 create mode 100644 Codes/0040-combination-sum-ii.go
 create mode 100644 Codes/0040-combination-sum-ii.java
 create mode 100644 Codes/0040-combination-sum-ii.py
 create mode 100644 Codes/0045-jump-game-ii.cpp
 create mode 100644 Codes/0045-jump-game-ii.go
 create mode 100644 Codes/0045-jump-game-ii.java
 create mode 100644 Codes/0045-jump-game-ii.py
 create mode 100644 Codes/0047-permutations-ii_20250206-BuiltIn.cpp
 create mode 100644 Codes/0047-permutations-ii_20250206-BuiltIn.py
 create mode 100644 Codes/0047-permutations-ii_20250206-HuiSu.cpp
 create mode 100644 Codes/0047-permutations-ii_20250206-HuiSu.go
 create mode 100644 Codes/0047-permutations-ii_20250206-HuiSu.java
 create mode 100644 Codes/0047-permutations-ii_20250206-HuiSu.py
 create mode 100644 Codes/0059-spiral-matrix-ii_20250207.cpp
 create mode 100644 Codes/0059-spiral-matrix-ii_20250207.go
 create mode 100644 Codes/0059-spiral-matrix-ii_20250207.java
 create mode 100644 Codes/0059-spiral-matrix-ii_20250207.py
 create mode 100644 Codes/0063-unique-paths-ii_20250208.cpp
 create mode 100644 Codes/0063-unique-paths-ii_20250208.go
 create mode 100644 Codes/0063-unique-paths-ii_20250208.java
 create mode 100644 Codes/0063-unique-paths-ii_20250208.py
 create mode 100644 Codes/0080-remove-duplicates-from-sorted-array-ii_20250209.cpp
 create mode 100644 Codes/0080-remove-duplicates-from-sorted-array-ii_20250209.go
 create mode 100644 Codes/0080-remove-duplicates-from-sorted-array-ii_20250209.java
 create mode 100644 Codes/0080-remove-duplicates-from-sorted-array-ii_20250209.py
 create mode 100644 Codes/0090-subsets-ii_20250205-HuiSu.cpp
 create mode 100644 Codes/0090-subsets-ii_20250205-HuiSu.go
 create mode 100644 Codes/0090-subsets-ii_20250205-HuiSu.java
 create mode 100644 Codes/0090-subsets-ii_20250205-HuiSu.py
 create mode 100644 Codes/0090-subsets-ii_20250205.cpp
 create mode 100644 Codes/0119-pascals-triangle-ii_20250128-ChuXi.cpp
 create mode 100644 Codes/0219-contains-duplicate-ii_20250129-ChunJie.cpp
 create mode 100644 Codes/0219-contains-duplicate-ii_20250129-ChunJie.go
 create mode 100644 Codes/0219-contains-duplicate-ii_20250129-ChunJie.java
 create mode 100644 Codes/0219-contains-duplicate-ii_20250129-ChunJie.py
 create mode 100644 Codes/0350-intersection-of-two-arrays-ii_20250130.cpp
 create mode 100644 Codes/0350-intersection-of-two-arrays-ii_20250130.go
 create mode 100644 Codes/0350-intersection-of-two-arrays-ii_20250130.java
 create mode 100644 Codes/0350-intersection-of-two-arrays-ii_20250130.py
 create mode 100644 Codes/0541-reverse-string-ii_20250131.cpp
 create mode 100644 Codes/0541-reverse-string-ii_20250131.go
 create mode 100644 Codes/0541-reverse-string-ii_20250131.java
 create mode 100644 Codes/0541-reverse-string-ii_20250131.py
 create mode 100644 Codes/0598-range-addition-ii_20250202.cpp
 create mode 100644 Codes/0598-range-addition-ii_20250202.go
 create mode 100644 Codes/0598-range-addition-ii_20250202.java
 create mode 100644 Codes/0598-range-addition-ii_20250202.py
 create mode 100644 Codes/0624-maximum-distance-in-arrays.cpp
 create mode 100644 Codes/0624-maximum-distance-in-arrays.go
 create mode 100644 Codes/0624-maximum-distance-in-arrays.java
 create mode 100644 Codes/0624-maximum-distance-in-arrays.py
 create mode 100644 Codes/0680-valid-palindrome-ii.cpp
 create mode 100644 Codes/0680-valid-palindrome-ii.go
 create mode 100644 Codes/0680-valid-palindrome-ii.java
 create mode 100644 Codes/0680-valid-palindrome-ii.py
 create mode 100644 Codes/0922-sort-array-by-parity-ii.cpp
 create mode 100644 Codes/0922-sort-array-by-parity-ii.go
 create mode 100644 Codes/0922-sort-array-by-parity-ii.java
 create mode 100644 Codes/0922-sort-array-by-parity-ii.py
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.cpp
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.go
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.java
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.py
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.cpp
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.go
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.java
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.py
 create mode 100644 Codes/1552-magnetic-force-between-two-balls.cpp
 create mode 100644 Codes/1552-magnetic-force-between-two-balls.go
 create mode 100644 Codes/1552-magnetic-force-between-two-balls.java
 create mode 100644 Codes/1552-magnetic-force-between-two-balls.py
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.cpp
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.go
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.java
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.py
 create mode 100644 Codes/1742-maximum-number-of-balls-in-a-box_20250213.cpp
 create mode 100644 Codes/1742-maximum-number-of-balls-in-a-box_20250213.go
 create mode 100644 Codes/1742-maximum-number-of-balls-in-a-box_20250213.java
 create mode 100644 Codes/1742-maximum-number-of-balls-in-a-box_20250213.py
 create mode 100644 Codes/1742-maximum-number-of-balls-in-a-box_20250213_2.py
 create mode 100644 Codes/1760-minimum-limit-of-balls-in-a-bag_20250212.cpp
 create mode 100644 Codes/1760-minimum-limit-of-balls-in-a-bag_20250213.cpp
 create mode 100644 Codes/1760-minimum-limit-of-balls-in-a-bag_20250213.go
 create mode 100644 Codes/1760-minimum-limit-of-balls-in-a-bag_20250213.java
 create mode 100644 Codes/1760-minimum-limit-of-balls-in-a-bag_20250213.py
 create mode 100644 Codes/2080-range-frequency-queries.cpp
 create mode 100644 Codes/2080-range-frequency-queries.go
 create mode 100644 Codes/2080-range-frequency-queries.java
 create mode 100644 Codes/2080-range-frequency-queries.py
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.cpp
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.go
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.java
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.py
 create mode 100644 Codes/2412-minimum-money-required-before-transactions.cpp
 create mode 100644 Codes/2412-minimum-money-required-before-transactions_JianHua.cpp
 create mode 100644 Codes/2412-minimum-money-required-before-transactions_JianHua.go
 create mode 100644 Codes/2412-minimum-money-required-before-transactions_JianHua.java
 create mode 100644 Codes/2412-minimum-money-required-before-transactions_JianHua.py
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.cpp
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.go
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.java
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.py
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.cpp
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.go
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.java
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.py
 create mode 100644 Codes/2944-minimum-number-of-coins-for-fruits.cpp
 create mode 100644 Solutions/LeetCode 0040.组合总和II.md
 create mode 100644 Solutions/LeetCode 0045.跳跃游戏II.md
 create mode 100644 Solutions/LeetCode 0047.全排列II.md
 create mode 100644 Solutions/LeetCode 0059.螺旋矩阵II.md
 create mode 100644 Solutions/LeetCode 0063.不同路径II.md
 create mode 100644 Solutions/LeetCode 0080.删除有序数组中的重复项II.md
 create mode 100644 Solutions/LeetCode 0090.子集II.md
 create mode 100644 Solutions/LeetCode 0219.存在重复元素II.md
 create mode 100644 Solutions/LeetCode 0541.反转字符串II.md
 create mode 100644 Solutions/LeetCode 0598.区间加法II.md
 create mode 100644 Solutions/LeetCode 0624.数组列表中的最大距离.md
 create mode 100644 Solutions/LeetCode 0680.验证回文串II.md
 create mode 100644 Solutions/LeetCode 0922.按奇偶排序数组II.md
 create mode 100644 Solutions/LeetCode 1287.有序数组中出现次数超过25的元素.md
 create mode 100644 Solutions/LeetCode 1299.将每个元素替换为右侧最大元素.md
 create mode 100644 Solutions/LeetCode 1552.两球之间的磁力.md
 create mode 100644 Solutions/LeetCode 1706.球会落何处.md
 create mode 100644 Solutions/LeetCode 2080.区间内查询数字的频率.md
 create mode 100644 Solutions/LeetCode 2209.用地毯覆盖后的最少白色砖块.md
 create mode 100644 Solutions/LeetCode 2412.完成所有交易的初始最少钱数.md
 create mode 100644 Solutions/LeetCode 2506.统计相似字符串对的数目.md
 create mode 100644 Solutions/LeetCode 2595.奇偶位数.md
 create mode 100644 Solutions/LeetCode 2944.购买水果需要的最少金币数.md
 create mode 100644 Solutions/Other-Github-PrCredentialLeakFix.md
 create mode 100644 Solutions/Other-Github-Record1Contribution2BytedanceCloudwegoDocs.md
 create mode 100644 Solutions/Other-Notes-Mianjing.md
 create mode 100644 Solutions/Other-Password-SelfHostPasswordToolUsingBitwardenVaultWarden.md
 create mode 100644 Solutions/Other-Windows-OpenUIbySSH.md
 rename tryGoPy/BUG!/{ => cf}/README.md (100%)
 rename tryGoPy/BUG!/{ => cf}/renderResult_main.js (100%)
 create mode 100644 tryGoPy/BUG!/git/commit.md
 create mode 100644 tryGoPy/BUG!/hexo/Readme.md
 create mode 100644 tryGoPy/BUG!/obs/Readme.md
 delete mode 100644 tryGoPy/Go/douyinec/.gitignore
 delete mode 100644 tryGoPy/Go/douyinec/README.md
 rename tryGoPy/{ => MGJW/下周}/WireSharker.py (100%)
 rename tryGoPy/{ => MGJW/下周}/周报-下周.md (100%)
 delete mode 100644 tryGoPy/public-专家意见