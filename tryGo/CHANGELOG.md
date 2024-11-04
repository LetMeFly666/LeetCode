<!--
 * @Author: LetMeFly
 * @Date: 2024-11-04 19:41:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-04 19:41:54
-->
remote: Enumerating objects: 59, done.
remote: Counting objects: 100% (59/59), done.
remote: Compressing objects: 100% (33/33), done.
remote: Total 59 (delta 29), reused 49 (delta 26), pack-reused 0 (from 0)
Unpacking objects: 100% (59/59), 199.33 KiB | 50.00 KiB/s, done.
From ssh.github.com:LetMeFly666/LeetCode
 * branch                    master     -> FETCH_HEAD
   df0f80b1aeb..e4401cc0689  master     -> origin/master
Updating df0f80b1aeb..e4401cc0689
Fast-forward
 Codes/0638-shopping-offers.cpp                     |  67 ++++
 Codes/0638-shopping-offers.py                      |  47 +++
 Codes/0684-redundant-connection.cpp                |  52 +++
 Codes/0684-redundant-connection_tuoPuPaiXu.cpp     |  48 +++
 Codes/0684-redundant-connection_tuoPuPaiXu.go      |  33 ++
 Codes/0684-redundant-connection_tuoPuPaiXu.java    |  35 ++
 Codes/0684-redundant-connection_tuoPuPaiXu.py      |  25 ++
 Codes/0685-redundant-connection-ii.cpp             | 164 ++++++++
 Codes/0685-redundant-connection-ii.go              |  82 ++++
 Codes/0685-redundant-connection-ii.java            |  81 ++++
 Codes/0685-redundant-connection-ii.py              |  57 +++
 ...m-of-subsequence-with-non-adjacent-elements.cpp |  63 +++
 ...um-of-subsequence-with-non-adjacent-elements.go |  70 ++++
 ...-of-subsequence-with-non-adjacent-elements.java |  55 +++
 ...um-of-subsequence-with-non-adjacent-elements.py |  49 +++
 ...hanges-to-make-two-integers-equal-WeYunSuan.cpp |  16 +
 ...changes-to-make-two-integers-equal-WeYunSuan.go |  15 +
 ...anges-to-make-two-integers-equal-WeYunSuan.java |  11 +
 ...changes-to-make-two-integers-equal-WeYunSuan.py |   9 +
 ...r-of-bit-changes-to-make-two-integers-equal.cpp |  25 ++
 README.md                                          |   9 +-
 ...e 0638.\345\244\247\347\244\274\345\214\205.md" | 163 ++++++++
 ...206\227\344\275\231\350\277\236\346\216\245.md" | 260 +++++++++++++        
 ...6\227\344\275\231\350\277\236\346\216\245II.md" | 421 +++++++++++++++++++++
 ...232\204\346\234\200\345\244\247\345\222\214.md" | 326 ++++++++++++++++     
 ...233\264\346\224\271\346\254\241\346\225\260.md" | 146 +++++++
 Solutions/Other-Accumulation-SomeTips.md           |   4 +
 Solutions/Other-English-LearningNotes-SomeWords.md |   4 +
 Solutions/Other-Japanese-LearningNotes.md          |   2 +
 29 files changed, 2337 insertions(+), 2 deletions(-)
 create mode 100644 Codes/0638-shopping-offers.cpp
 create mode 100644 Codes/0638-shopping-offers.py
 create mode 100644 Codes/0684-redundant-connection.cpp
 create mode 100644 Codes/0684-redundant-connection_tuoPuPaiXu.cpp
 create mode 100644 Codes/0684-redundant-connection_tuoPuPaiXu.go
 create mode 100644 Codes/0684-redundant-connection_tuoPuPaiXu.java
 create mode 100644 Codes/0684-redundant-connection_tuoPuPaiXu.py
 create mode 100644 Codes/0685-redundant-connection-ii.cpp
 create mode 100644 Codes/0685-redundant-connection-ii.go
 create mode 100644 Codes/0685-redundant-connection-ii.java
 create mode 100644 Codes/0685-redundant-connection-ii.py
 create mode 100644 Codes/3165-maximum-sum-of-subsequence-with-non-adjacent-elements.cpp
 create mode 100644 Codes/3165-maximum-sum-of-subsequence-with-non-adjacent-elements.go
 create mode 100644 Codes/3165-maximum-sum-of-subsequence-with-non-adjacent-elements.java
 create mode 100644 Codes/3165-maximum-sum-of-subsequence-with-non-adjacent-elements.py
 create mode 100644 Codes/3226-number-of-bit-changes-to-make-two-integers-equal-WeYunSuan.cpp
 create mode 100644 Codes/3226-number-of-bit-changes-to-make-two-integers-equal-WeYunSuan.go
 create mode 100644 Codes/3226-number-of-bit-changes-to-make-two-integers-equal-WeYunSuan.java
 create mode 100644 Codes/3226-number-of-bit-changes-to-make-two-integers-equal-WeYunSuan.py
 create mode 100644 Codes/3226-number-of-bit-changes-to-make-two-integers-equal.cpp
 create mode 100644 "Solutions/LeetCode 0638.\345\244\247\347\244\274\345\214\205.md"
 create mode 100644 "Solutions/LeetCode 0684.\345\206\227\344\275\231\350\277\236\346\216\245.md"
 create mode 100644 "Solutions/LeetCode 0685.\345\206\227\344\275\231\350\277\236\346\216\245II.md"
 create mode 100644 "Solutions/LeetCode 3165.\344\270\215\345\214\205\345\220\253\347\233\270\351\202\273\345\205\203\347\264\240\347\232\204\345\255\220\345\272\217\345\210\227\347\232\204\346\234\200\345\244\247\345\222\214.md"
 create mode 100644 "Solutions/LeetCode 3226.\344\275\277\344\270\244\344\270\252\346\225\264\346\225\260\347\233\270\347\255\211\347\232\204\344\275\215\346\233\264\346\224\271\346\254\241\346\225\260.md"