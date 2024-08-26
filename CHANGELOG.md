git pull origin master
remote: Enumerating objects: 133, done.
remote: Counting objects: 100% (133/133), done.
remote: Compressing objects: 100% (77/77), done.
remote: Total 133 (delta 61), reused 113 (delta 55), pack-reused 0 (from 0)Receiving objects:  82% (110/133), 216.01 KiB | 184.00 KiB/s
Receiving objects: 100% (133/133), 239.74 KiB | 139.00 KiB/s, done.
Resolving deltas: 100% (61/61), completed with 7 local objects.
From github.com:LetMeFly666/LeetCode
 * branch                master     -> FETCH_HEAD
   92aab9230..5663d5023  master     -> origin/master
Updating 92aab9230..5663d5023
Fast-forward
 .../0551-student-attendance-record-i_20240818.cpp  |  28 +++
 .../0552-student-attendance-record-ii_20240819.cpp | 121 +++++++++++++
 Codes/0572-subtree-of-another-tree.cpp             |  49 ++++++
 Codes/0572-subtree-of-another-tree.py              |  26 +++
 Codes/3131-find-the-integer-added-to-array-i.cpp   |  16 ++
 Codes/3131-find-the-integer-added-to-array-i.go    |  13 ++
 Codes/3131-find-the-integer-added-to-array-i.java  |  19 ++
 Codes/3131-find-the-integer-added-to-array-i.py    |  11 ++
 Codes/3132-find-the-integer-added-to-array-ii.cpp  |  40 +++++
 Codes/3133-minimum-array-end.cpp                   |  97 ++++++++++
 Codes/3133-minimum-array-end.go                    |  18 ++
 Codes/3133-minimum-array-end.java                  |  18 ++
 Codes/3133-minimum-array-end.py                    |  16 ++
 ...umber-of-operations-to-make-word-k-periodic.cpp |  21 +++
 ...number-of-operations-to-make-word-k-periodic.go |  17 ++
 ...number-of-operations-to-make-word-k-periodic.py |  17 ++
 ...-word-k-periodic_usingCounter-1lineVersion.java |  19 ++
 ...ke-word-k-periodic_usingCounter-1lineVersion.py |  11 ++
 ...-permutation-difference-between-two-strings.cpp |  25 +++
 ...6-permutation-difference-between-two-strings.go |  27 +++
 ...permutation-difference-between-two-strings.java |  15 ++
 ...6-permutation-difference-between-two-strings.py |  12 ++
 Codes/3148-maximum-difference-score-in-a-grid.cpp  |  31 ++++
 Codes/3148-maximum-difference-score-in-a-grid.go   |  40 +++++
 Codes/3148-maximum-difference-score-in-a-grid.java |  27 +++
 Codes/3148-maximum-difference-score-in-a-grid.py   |  21 +++
 Codes/3151-special-array-i.cpp                     |  21 +++
 Codes/3152-special-array-ii.cpp                    |  27 +++
 Codes/3152-special-array-ii.go                     |  24 +++
 Codes/3152-special-array-ii.java                   |  22 +++
 Codes/3152-special-array-ii.py                     |  17 ++
 README.md                                          |  17 +-
 Solutions/LeetCode 0551.学生出勤记录I.md           |  97 ++++++++++
 Solutions/LeetCode 0572.另一棵树的子树.md          | 133 ++++++++++++++
 .../LeetCode 2236.判断根结点是否等于子结点之和.md  |   2 +-
 Solutions/LeetCode 3131.找出与数组相加的整数I.md   | 151 ++++++++++++++++
 Solutions/LeetCode 3132.找出与数组相加的整数II.md  | 125 +++++++++++++
 .../LeetCode 3133.数组最后一个元素的最小值.md      | 165 +++++++++++++++++
 .../LeetCode 3137.K周期字符串需要的最少操作次数.md | 196 +++++++++++++++++++++
 Solutions/LeetCode 3146.两个字符串的排列差.md      | 152 ++++++++++++++++
 Solutions/LeetCode 3148.矩阵中的最大得分.md        | 195 ++++++++++++++++++++
 Solutions/LeetCode 3151.特殊数组I.md               |  95 ++++++++++
 Solutions/LeetCode 3152.特殊数组II.md              | 164 +++++++++++++++++
 Solutions/Other-English-LearningNotes-SomeWords.md | 101 ++++++++++-
 ...-Farewell-WhatIsEasilyDoneAtHomeButNotSchool.md |   2 +-
 Solutions/Other-Japanese-LearningNotes.md          |  85 ++++++++-
 Solutions/Other-OJ-Vjudge-how2use.md               |  72 ++++++++
 get1VPS.js                                         |  46 +++++
 t                                                  |   1 +
 49 files changed, 2652 insertions(+), 13 deletions(-)
 create mode 100644 Codes/0551-student-attendance-record-i_20240818.cpp
 create mode 100644 Codes/0552-student-attendance-record-ii_20240819.cpp
 create mode 100644 Codes/0572-subtree-of-another-tree.cpp
 create mode 100644 Codes/0572-subtree-of-another-tree.py
 create mode 100644 Codes/3131-find-the-integer-added-to-array-i.cpp
 create mode 100644 Codes/3131-find-the-integer-added-to-array-i.go
 create mode 100644 Codes/3131-find-the-integer-added-to-array-i.java
 create mode 100644 Codes/3131-find-the-integer-added-to-array-i.py
 create mode 100644 Codes/3132-find-the-integer-added-to-array-ii.cpp
 create mode 100644 Codes/3133-minimum-array-end.cpp
 create mode 100644 Codes/3133-minimum-array-end.go
 create mode 100644 Codes/3133-minimum-array-end.java
 create mode 100644 Codes/3133-minimum-array-end.py
 create mode 100644 Codes/3137-minimum-number-of-operations-to-make-word-k-periodic.cpp      
 create mode 100644 Codes/3137-minimum-number-of-operations-to-make-word-k-periodic.go       
 create mode 100644 Codes/3137-minimum-number-of-operations-to-make-word-k-periodic.py       
 create mode 100644 Codes/3137-minimum-number-of-operations-to-make-word-k-periodic_usingCounter-1lineVersion.java
 create mode 100644 Codes/3137-minimum-number-of-operations-to-make-word-k-periodic_usingCounter-1lineVersion.py
 create mode 100644 Codes/3146-permutation-difference-between-two-strings.cpp
 create mode 100644 Codes/3146-permutation-difference-between-two-strings.go
 create mode 100644 Codes/3146-permutation-difference-between-two-strings.java
 create mode 100644 Codes/3146-permutation-difference-between-two-strings.py
 create mode 100644 Codes/3148-maximum-difference-score-in-a-grid.cpp
 create mode 100644 Codes/3148-maximum-difference-score-in-a-grid.go
 create mode 100644 Codes/3148-maximum-difference-score-in-a-grid.java
 create mode 100644 Codes/3148-maximum-difference-score-in-a-grid.py
 create mode 100644 Codes/3151-special-array-i.cpp
 create mode 100644 Codes/3152-special-array-ii.cpp
 create mode 100644 Codes/3152-special-array-ii.go
 create mode 100644 Codes/3152-special-array-ii.java
 create mode 100644 Codes/3152-special-array-ii.py
 create mode 100644 Solutions/LeetCode 0551.学生出勤记录I.md
 create mode 100644 Solutions/LeetCode 0572.另一棵树的子树.md
 create mode 100644 Solutions/LeetCode 3131.找出与数组相加的整数I.md
 create mode 100644 Solutions/LeetCode 3132.找出与数组相加的整数II.md
 create mode 100644 Solutions/LeetCode 3133.数组最后一个元素的最小值.md
 create mode 100644 Solutions/LeetCode 3137.K周期字符串需要的最少操作次数.md
 create mode 100644 Solutions/LeetCode 3146.两个字符串的排列差.md
 create mode 100644 Solutions/LeetCode 3148.矩阵中的最大得分.md
 create mode 100644 Solutions/LeetCode 3151.特殊数组I.md
 create mode 100644 Solutions/LeetCode 3152.特殊数组II.md
 create mode 100644 Solutions/Other-OJ-Vjudge-how2use.md
 create mode 100644 get1VPS.js
 create mode 100644 t