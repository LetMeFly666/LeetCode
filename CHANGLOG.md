remote: Enumerating objects: 30, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (19/19), done.
remote: Total 30 (delta 11), reused 27 (delta 11), pack-reused 0
Unpacking objects: 100% (30/30), 155.75 KiB | 98.00 KiB/s, done.
From ssh.github.com:LetMeFly666/LeetCode
 * branch                master     -> FETCH_HEAD
   ecbf65644..b38813da2  master     -> origin/master
Updating ecbf65644..b38813da2
Fast-forward
 CHANGELOG.md                                       |  77 ----------
 ...976-number-of-ways-to-arrive-at-destination.cpp |  47 +++++++   
 ...1976-number-of-ways-to-arrive-at-destination.py |  34 +++++     
 ...575-find-the-divisibility-array-of-a-string.cpp |  23 +++       
 ...2575-find-the-divisibility-array-of-a-string.py |  17 +++
 Codes/2917-find-the-k-or-of-an-array.cpp           |  27 ++++
 Codes/2917-find-the-k-or-of-an-array.py            |  19 +++
 README.md                                          |   3 +
 ...232\204\346\226\271\346\241\210\346\225\260.md" | 156 +++++++++++++++++++++
 ...225\264\351\231\244\346\225\260\347\273\204.md" | 101 +++++++++++++
 ...204\344\270\255\347\232\204K-or\345\200\274.md" | 119 ++++++++++++++++
 Solutions/Other-English-LearningNotes-SomeWords.md |   6 +
 Solutions/Other-Japanese-LearningNotes.md          |  22 ++-
 13 files changed, 571 insertions(+), 80 deletions(-)
 delete mode 100644 CHANGELOG.md
 create mode 100644 Codes/1976-number-of-ways-to-arrive-at-destination.cpp
 create mode 100644 Codes/1976-number-of-ways-to-arrive-at-destination.py
 create mode 100644 Codes/2575-find-the-divisibility-array-of-a-string.cpp
 create mode 100644 Codes/2575-find-the-divisibility-array-of-a-string.py
 create mode 100644 Codes/2917-find-the-k-or-of-an-array.cpp
 create mode 100644 Codes/2917-find-the-k-or-of-an-array.py
 create mode 100644 "Solutions/LeetCode 1976.\345\210\260\350\276\276\347\233\256\347\232\204\345\234\260\347\232\204\346\226\271\346\241\210\346\225\260.md"
 create mode 100644 "Solutions/LeetCode 2575.\346\211\276\345\207\272\345\255\227\347\254\246\344\270\262\347\232\204\345\217\257\346\225\264\351\231\244\346\225\260\347\273\204.md"
 create mode 100644 "Solutions/LeetCode 2917.\346\211\276\345\207\272\346\225\260\347\273\204\344\270\255\347\232\204K-or\345\200\274.md"