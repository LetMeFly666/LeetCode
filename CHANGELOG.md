<!--
 * @Author: LetMeFly
 * @Date: 2024-07-16 22:42:22
 * @LastEditors: LetMeFly
 * @LastEditTime: 2024-07-16 22:42:24
-->
remote: Enumerating objects: 128, done.
remote: Counting objects: 100% (128/128), done.
remote: Compressing objects: 100% (74/74), done.
remote: Total 128 (delta 59), reused 110 (delta 52), pack-reused 0
Receiving objects: 100% (128/128), 253.36 KiB | 170.00 KiB/s, done.
Resolving deltas: 100% (59/59), completed with 6 local objects.
From ssh.github.com:LetMeFly666/LeetCode
 * branch                  master     -> FETCH_HEAD
   586d41cb4c..62d5111984  master     -> origin/master
Updating 586d41cb4c..62d5111984
Fast-forward
 .github/workflows/deployHexo.yml                   |   2 +- 
 .vscode/settings.json                              |   1 +  
 Codes/0724-find-pivot-index.cpp                    |  24 +++
 Codes/0724-find-pivot-index.go                     |  22 ++ 
 Codes/0724-find-pivot-index.java                   |  22 ++ 
 Codes/0724-find-pivot-index.py                     |  17 ++ 
 Codes/1301-count-alternating-subarrays.cpp         |  24 +++
 Codes/1301-count-alternating-subarrays.go          |  19 ++
 Codes/1301-count-alternating-subarrays.java        |  19 ++
 Codes/1301-count-alternating-subarrays.py          |  18 ++
 Codes/1958-check-if-move-is-legal.cpp              |  55 +++++
 Codes/1958-check-if-move-is-legal.go               |  32 +++
 Codes/1958-check-if-move-is-legal.java             |  34 ++++
 Codes/1958-check-if-move-is-legal.py               |  29 +++
 Codes/2065-maximum-path-quality-of-a-graph.cpp     |  51 +++++
 Codes/2065-maximum-path-quality-of-a-graph.py      |  34 ++++
 ...ount-the-number-of-incremovable-subarrays-i.cpp |  36 ++++
 ...count-the-number-of-incremovable-subarrays-i.go |  31 +++
 ...unt-the-number-of-incremovable-subarrays-i.java |  31 +++
 ...count-the-number-of-incremovable-subarrays-i.py |  26 +++
 Codes/2974-minimum-number-game.cpp                 |  20 ++
 Codes/2974-minimum-number-game.py                  |  14 ++
 Codes/3011-find-if-array-can-be-sorted.cpp         |  37 ++++
 Codes/3033-modify-the-matrix.cpp                   |  27 +++
 Codes/3033-modify-the-matrix.go                    |  23 +++
 Codes/3033-modify-the-matrix.java                  |  22 ++
 Codes/3033-modify-the-matrix.py                    |  18 ++
 Codes/3099-harshad-number.cpp                      |  26 +++
 Codes/3099-harshad-number.go                       |  24 +++
 Codes/3099-harshad-number.java                     |  20 ++
 Codes/3099-harshad-number.py                       |  16 ++
 Codes/3115-maximum-prime-difference.cpp            |  35 ++++
 Codes/3115-maximum-prime-difference.go             |  44 ++++
 Codes/3115-maximum-prime-difference.java           |  31 +++
 Codes/3115-maximum-prime-difference.py             |  24 +++
 README.md                                          |  10 +
 ...270\255\345\277\203\344\270\213\346\240\207.md" | 157 ++++++++++++++
 ...230\257\345\220\246\345\220\210\346\263\225.md" | 225 +++++++++++++++++++++
 ...267\257\345\276\204\344\273\267\345\200\274.md" | 196 ++++++++++++++++++
 ...73\204\347\232\204\346\225\260\347\233\256I.md" | 200 ++++++++++++++++++
 ...225\260\345\255\227\346\270\270\346\210\217.md" |  95 +++++++++
 ...217\230\344\270\272\346\234\211\345\272\217.md" | 105 ++++++++++
 ...277\256\346\224\271\347\237\251\351\230\265.md" | 146 +++++++++++++
 ...223\210\346\262\231\345\276\267\346\225\260.md" | 149 ++++++++++++++
 ...225\260\347\273\204\350\256\241\346\225\260.md" |  91 +++++++++
 ...234\200\345\244\247\350\267\235\347\246\273.md" | 193 ++++++++++++++++++
 ...-FL-FederatedLearning-ProjectWritingIn1month.md |  21 +-
 Solutions/Other-Accumulation-SomeTips.md           |  77 ++++++-
 Solutions/Other-English-LearningNotes-SomeWords.md |  39 +++-
 Solutions/Other-Japanese-LearningNotes.md          |  36 ++++
 Solutions/Other-Python-Overload.md                 |   2 +-
 51 files changed, 2644 insertions(+), 6 deletions(-)
 create mode 100644 Codes/0724-find-pivot-index.cpp
 create mode 100644 Codes/0724-find-pivot-index.go
 create mode 100644 Codes/0724-find-pivot-index.java
 create mode 100644 Codes/0724-find-pivot-index.py
 create mode 100644 Codes/1301-count-alternating-subarrays.cpp
 create mode 100644 Codes/1301-count-alternating-subarrays.go
 create mode 100644 Codes/1301-count-alternating-subarrays.java
 create mode 100644 Codes/1301-count-alternating-subarrays.py
 create mode 100644 Codes/1958-check-if-move-is-legal.cpp
 create mode 100644 Codes/1958-check-if-move-is-legal.go
 create mode 100644 Codes/1958-check-if-move-is-legal.java
 create mode 100644 Codes/1958-check-if-move-is-legal.py
 create mode 100644 Codes/2065-maximum-path-quality-of-a-graph.cpp
 create mode 100644 Codes/2065-maximum-path-quality-of-a-graph.py
 create mode 100644 Codes/2970-count-the-number-of-incremovable-subarrays-i.cpp
 create mode 100644 Codes/2970-count-the-number-of-incremovable-subarrays-i.go
 create mode 100644 Codes/2970-count-the-number-of-incremovable-subarrays-i.java
 create mode 100644 Codes/2970-count-the-number-of-incremovable-subarrays-i.py
 create mode 100644 Codes/2974-minimum-number-game.cpp
 create mode 100644 Codes/2974-minimum-number-game.py
 create mode 100644 Codes/3011-find-if-array-can-be-sorted.cpp
 create mode 100644 Codes/3033-modify-the-matrix.cpp
 create mode 100644 Codes/3033-modify-the-matrix.go
 create mode 100644 Codes/3033-modify-the-matrix.java
 create mode 100644 Codes/3033-modify-the-matrix.py
 create mode 100644 Codes/3099-harshad-number.cpp
 create mode 100644 Codes/3099-harshad-number.go
 create mode 100644 Codes/3099-harshad-number.java
 create mode 100644 Codes/3099-harshad-number.py
 create mode 100644 Codes/3115-maximum-prime-difference.cpp
 create mode 100644 Codes/3115-maximum-prime-difference.go
 create mode 100644 Codes/3115-maximum-prime-difference.java
 create mode 100644 Codes/3115-maximum-prime-difference.py
 create mode 100644 "Solutions/LeetCode 0724.\345\257\273\346\211\276\346\225\260\347\273\204\347\232\204\344\270\255\345\277\203\344\270\213\346\240\207.md"
 create mode 100644 "Solutions/LeetCode 1958.\346\243\200\346\237\245\346\223\215\344\275\234\346\230\257\345\220\246\345\220\210\346\263\225.md"
 create mode 100644 "Solutions/LeetCode 2065.\346\234\200\345\244\247\345\214\226\344\270\200\345\274\240\345\233\276\344\270\255\347\232\204\350\267\257\345\276\204\344\273\267\345\200\274.md"
 create mode 100644 "Solutions/LeetCode 2970.\347\273\237\350\256\241\347\247\273\351\231\244\351\200\222\345\242\236\345\255\220\346\225\260\347\273\204\347\232\204\346\225\260\347\233\256I.md"
 create mode 100644 "Solutions/LeetCode 2974.\346\234\200\345\260\217\346\225\260\345\255\227\346\270\270\346\210\217.md"
 create mode 100644 "Solutions/LeetCode 3011.\345\210\244\346\226\255\344\270\200\344\270\252\346\225\260\347\273\204\346\230\257\345\220\246\345\217\257\344\273\245\345\217\230\344\270\272\346\234\211\345\272\217.md"
 create mode 100644 "Solutions/LeetCode 3033.\344\277\256\346\224\271\347\237\251\351\230\265.md"
 create mode 100644 "Solutions/LeetCode 3099.\345\223\210\346\262\231\345\276\267\346\225\260.md"
 create mode 100644 "Solutions/LeetCode 3101.\344\272\244\346\233\277\345\255\220\346\225\260\347\273\204\350\256\241\346\225\260.md"
 create mode 100644 "Solutions/LeetCode 3115.\350\264\250\346\225\260\347\232\204\346\234\200\345\244\247\350\267\235\347\246\273.md"