<!--
 * @Author: LetMeFly
 * @Date: 2025-02-23 23:32:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-23 23:32:41
-->
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git switch dev 
Updating files: 100% (59/59), done.
Switched to branch 'dev'
Your branch is up to date with 'origin/dev'.
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git merge master
Updating files: 100% (59/59), done.
Updating 01f69dc920f..19200fab42f
Fast-forward
 .github/workflows/deployHexo.yml                   |   3 +- 
 Codes/0624-maximum-distance-in-arrays.cpp          |  34 +++
 Codes/0624-maximum-distance-in-arrays.go           |  16 ++ 
 Codes/0624-maximum-distance-in-arrays.java         |  21 ++ 
 Codes/0624-maximum-distance-in-arrays.py           |  16 ++ 
 ...ment-appearing-more-than-25-in-sorted-array.cpp |  21 ++ 
 ...ement-appearing-more-than-25-in-sorted-array.go |  17 ++ 
 ...ent-appearing-more-than-25-in-sorted-array.java |  16 ++ 
 ...ement-appearing-more-than-25-in-sorted-array.py |  15 ++ 
 ...lements-with-greatest-element-on-right-side.cpp |  22 ++ 
 ...elements-with-greatest-element-on-right-side.go |  24 +++
 ...ements-with-greatest-element-on-right-side.java |  17 ++ 
 ...elements-with-greatest-element-on-right-side.py |  14 ++ 
 Codes/1706-where-will-the-ball-fall_20250215.cpp   |  32 +++
 Codes/1706-where-will-the-ball-fall_20250215.go    |  26 +++
 Codes/1706-where-will-the-ball-fall_20250215.java  |  29 +++
 Codes/1706-where-will-the-ball-fall_20250215.py    |  25 +++
 Codes/2080-range-frequency-queries.cpp             |  35 +++
 Codes/2080-range-frequency-queries.go              |  34 +++
 Codes/2080-range-frequency-queries.java            |  38 ++++
 Codes/2080-range-frequency-queries.py              |  28 +++
 ...imum-white-tiles-after-covering-with-carpet.cpp |  57 +++++
 ...nimum-white-tiles-after-covering-with-carpet.go |  32 +++
 ...mum-white-tiles-after-covering-with-carpet.java |  40 ++++
 ...nimum-white-tiles-after-covering-with-carpet.py |  23 ++
 Codes/2506-count-pairs-of-similar-strings.cpp      |  31 +++
 Codes/2506-count-pairs-of-similar-strings.go       |  25 +++
 Codes/2506-count-pairs-of-similar-strings.java     |  29 +++
 Codes/2506-count-pairs-of-similar-strings.py       |  24 +++
 Codes/2595-number-of-even-and-odd-bits.cpp         |  23 ++
 Codes/2595-number-of-even-and-odd-bits.go          |  16 ++
 Codes/2595-number-of-even-and-odd-bits.java        |  18 ++
 Codes/2595-number-of-even-and-odd-bits.py          |  17 ++
 README.md                                          |  16 +-
 ...234\200\345\244\247\350\267\235\347\246\273.md" | 195 +++++++++++++++++
 ...7\20725\347\232\204\345\205\203\347\264\240.md" | 135 ++++++++++++
 ...234\200\345\244\247\345\205\203\347\264\240.md" | 160 ++++++++++++++
 ...274\232\350\220\275\344\275\225\345\244\204.md" | 217 +++++++++++++++++++
 ...255\227\347\232\204\351\242\221\347\216\207.md" | 176 +++++++++++++++
 ...231\275\350\211\262\347\240\226\345\235\227.md" | 235 +++++++++++++++++++++
 ...257\271\347\232\204\346\225\260\347\233\256.md" | 209 ++++++++++++++++++
 ...245\207\345\201\266\344\275\215\346\225\260.md" | 165 +++++++++++++++
 Solutions/Other-Accumulation-Messy.md              |  46 ++++
 Solutions/Other-Accumulation-SomeTips.md           |  36 ++++
 Solutions/Other-English-LearningNotes-SomeWords.md |  15 +-
 ...-Farewell-WhatIsEasilyDoneAtHomeButNotSchool.md |   3 +-
 ...b-Record1Contribution2BytedanceCloudwegoDocs.md |   5 +-
 Solutions/Other-Japanese-LearningNotes.md          |  31 ++-
 Solutions/Other-Notes-Mianjing.md                  |  47 +++++
 ...elfHostPasswordToolUsingBitwardenVaultWarden.md |  96 +++++++++
 .../Other-Windows-LoginWindowsWithoutPassword.md   |   2 +-
 Solutions/Other-Windows-OpenUIbySSH.md             |  66 ++++++
 ...LSchemeForYourApplicationWithoutUACOnWindows.md |  17 +-
 newSolution.py                                     |   6 +-
 tryGoPy/BUG!/hexo/Readme.md                        |  10 +
 .../MGJW/\344\270\213\345\221\250/WireSharker.py"  |   0
 ...21\250\346\212\245-\344\270\213\345\221\250.md" |   0
 57 files changed, 2681 insertions(+), 25 deletions(-)
 create mode 100644 Codes/0624-maximum-distance-in-arrays.cpp
 create mode 100644 Codes/0624-maximum-distance-in-arrays.go
 create mode 100644 Codes/0624-maximum-distance-in-arrays.java
 create mode 100644 Codes/0624-maximum-distance-in-arrays.py
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.cpp
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.go
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.java
 create mode 100644 Codes/1287-element-appearing-more-than-25-in-sorted-array.py
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.cpp
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.go
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.java
 create mode 100644 Codes/1299-replace-elements-with-greatest-element-on-right-side.py
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.cpp
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.go
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.java
 create mode 100644 Codes/1706-where-will-the-ball-fall_20250215.py
 create mode 100644 Codes/2080-range-frequency-queries.cpp
 create mode 100644 Codes/2080-range-frequency-queries.go
 create mode 100644 Codes/2080-range-frequency-queries.java
 create mode 100644 Codes/2080-range-frequency-queries.py
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.cpp
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.go
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.java
 create mode 100644 Codes/2209-minimum-white-tiles-after-covering-with-carpet.py
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.cpp
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.go
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.java
 create mode 100644 Codes/2506-count-pairs-of-similar-strings.py
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.cpp
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.go
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.java
 create mode 100644 Codes/2595-number-of-even-and-odd-bits.py
 create mode 100644 "Solutions/LeetCode 0624.\346\225\260\347\273\204\345\210\227\350\241\250\344\270\255\347\232\204\346\234\200\345\244\247\350\267\235\347\246\273.md"
 create mode 100644 "Solutions/LeetCode 1287.\346\234\211\345\272\217\346\225\260\347\273\204\344\270\255\345\207\272\347\216\260\346\254\241\346\225\260\350\266\205\350\277\20725\347\232\204\345\205\203\347\264\240.md"
 create mode 100644 "Solutions/LeetCode 1299.\345\260\206\346\257\217\344\270\252\345\205\203\347\264\240\346\233\277\346\215\242\344\270\272\345\217\263\344\276\247\346\234\200\345\244\247\345\205\203\347\264\240.md"
 create mode 100644 "Solutions/LeetCode 1706.\347\220\203\344\274\232\350\220\275\344\275\225\345\244\204.md"
 create mode 100644 "Solutions/LeetCode 2080.\345\214\272\351\227\264\345\206\205\346\237\245\350\257\242\346\225\260\345\255\227\347\232\204\351\242\221\347\216\207.md"
 create mode 100644 "Solutions/LeetCode 2209.\347\224\250\345\234\260\346\257\257\350\246\206\347\233\226\345\220\216\347\232\204\346\234\200\345\260\221\347\231\275\350\211\262\347\240\226\345\235\227.md"
 create mode 100644 "Solutions/LeetCode 2506.\347\273\237\350\256\241\347\233\270\344\274\274\345\255\227\347\254\246\344\270\262\345\257\271\347\232\204\346\225\260\347\233\256.md"
 create mode 100644 "Solutions/LeetCode 2595.\345\245\207\345\201\266\344\275\215\346\225\260.md"
 create mode 100644 Solutions/Other-Notes-Mianjing.md
 create mode 100644 Solutions/Other-Password-SelfHostPasswordToolUsingBitwardenVaultWarden.md
 create mode 100644 Solutions/Other-Windows-OpenUIbySSH.md
 create mode 100644 tryGoPy/BUG!/hexo/Readme.md
 rename tryGoPy/MGJW/WireSharker.py => "tryGoPy/MGJW/\344\270\213\345\221\250/WireSharker.py" (100%)
 rename "tryGoPy/MGJW/\345\221\250\346\212\245-\344\270\213\345\221\250.md" => "tryGoPy/MGJW/\344\270\213\345\221\250/\345\221\250\346\212\245-\344\270\213\345\221\250.md" (100%)