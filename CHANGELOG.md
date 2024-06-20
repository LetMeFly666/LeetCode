remote: Enumerating objects: 61, done.
remote: Counting objects: 100% (61/61), done.
remote: Compressing objects: 100% (42/42), done.
remote: Total 61 (delta 26), reused 50 (delta 19), pack-reused 0
Unpacking objects: 100% (61/61), 203.70 KiB | 33.00 KiB/s, done.
From github.com:LetMeFly666/LeetCode
 * branch                master     -> FETCH_HEAD
   99d0c7476..65a91d637  master     -> origin/master
Updating 99d0c7476..65a91d637
Fast-forward
 CHANGELOG.md                                       | 547 ---------------------
 Codes/0521-longest-uncommon-subsequence-i.cpp      |  16 +
 Codes/0521-longest-uncommon-subsequence-i.go       |  19 +
 Codes/0521-longest-uncommon-subsequence-i.java     |  11 +
 Codes/0521-longest-uncommon-subsequence-i.py       |   9 +
 ...beauty-of-an-array-after-applying-operation.cpp |  25 +
 ...-beauty-of-an-array-after-applying-operation.go |  24 +
 ...eauty-of-an-array-after-applying-operation.java |  23 +
 ...-beauty-of-an-array-after-applying-operation.py |  19 +
 ...786-visit-array-positions-to-maximize-score.cpp |  26 +
 ...2786-visit-array-positions-to-maximize-score.go |  31 ++
 ...86-visit-array-positions-to-maximize-score.java |  20 +
 ...2786-visit-array-positions-to-maximize-score.py |  17 +
 ...2806-account-balance-after-rounded-purchase.cpp |  21 +
 .../2806-account-balance-after-rounded-purchase.go |  16 +
 ...806-account-balance-after-rounded-purchase.java |  16 +
 .../2806-account-balance-after-rounded-purchase.py |  13 +
 README.md                                          |   4 +
 Solutions/LeetCode 0521.最长特殊序列Ⅰ.md           | 117 +++++
 .../LeetCode 1261.在受污染的二叉树中查找元素.md    |   2 +-
 Solutions/LeetCode 2779.数组的最大美丽值.md        | 162 ++++++
 .../LeetCode 2786.访问数组中的位置使分数最大.md    | 163 ++++++
 Solutions/LeetCode 2806.取整购买后的账户余额.md    | 122 +++++
 Solutions/Other-English-LearningNotes-SomeWords.md |  28 +-
 Solutions/Other-Japanese-LearningNotes.md          |  56 ++-
 archiveHistory.py                                  |  60 ++-
 26 files changed, 984 insertions(+), 583 deletions(-)
 delete mode 100644 CHANGELOG.md
 create mode 100644 Codes/0521-longest-uncommon-subsequence-i.cpp
 create mode 100644 Codes/0521-longest-uncommon-subsequence-i.go
 create mode 100644 Codes/0521-longest-uncommon-subsequence-i.java
 create mode 100644 Codes/0521-longest-uncommon-subsequence-i.py
 create mode 100644 Codes/2779-maximum-beauty-of-an-array-after-applying-operation.cpp
 create mode 100644 Codes/2779-maximum-beauty-of-an-array-after-applying-operation.go
 create mode 100644 Codes/2779-maximum-beauty-of-an-array-after-applying-operation.java
 create mode 100644 Codes/2779-maximum-beauty-of-an-array-after-applying-operation.py
 create mode 100644 Codes/2786-visit-array-positions-to-maximize-score.cpp
 create mode 100644 Codes/2786-visit-array-positions-to-maximize-score.go
 create mode 100644 Codes/2786-visit-array-positions-to-maximize-score.java
 create mode 100644 Codes/2786-visit-array-positions-to-maximize-score.py
 create mode 100644 Codes/2806-account-balance-after-rounded-purchase.cpp
 create mode 100644 Codes/2806-account-balance-after-rounded-purchase.go
 create mode 100644 Codes/2806-account-balance-after-rounded-purchase.java
 create mode 100644 Codes/2806-account-balance-after-rounded-purchase.py
 create mode 100644 Solutions/LeetCode 0521.最长特殊序列Ⅰ.md
 create mode 100644 Solutions/LeetCode 2779.数组的最大美丽值.md
 create mode 100644 Solutions/LeetCode 2786.访问数组中的位置使分数最大.md
 create mode 100644 Solutions/LeetCode 2806.取整购买后的账户余额.md



remote: Enumerating objects: 22, done.
remote: Counting objects: 100% (22/22), done.
remote: Compressing objects: 100% (12/12), done.
remote: Total 22 (delta 10), reused 20 (delta 10), pack-reused 0
Unpacking objects: 100% (22/22), 40.10 KiB | 11.00 KiB/s, done.
From github.com:LetMeFly666/LeetCode
 * branch                master     -> FETCH_HEAD
   65a91d637..35c45cbc2  master     -> origin/master
Updating 65a91d637..35c45cbc2
Fast-forward
 Codes/0522-longest-uncommon-subsequence-ii.cpp     |  58 ++++++
 Codes/2288-apply-discount-to-prices.cpp            |  60 ++++++
 Codes/2288-apply-discount-to-prices.py             |  27 +++
 README.md                                          |   2 +
 Solutions/LeetCode 0522.最长特殊序列II.md          | 109 +++++++++++
 Solutions/LeetCode 2288.价格减免.md                | 215 +++++++++++++++++++++
 Solutions/Other-English-LearningNotes-SomeWords.md |  12 +-
 Solutions/Other-Japanese-LearningNotes.md          |  41 +++-
 8 files changed, 515 insertions(+), 9 deletions(-)
 create mode 100644 Codes/0522-longest-uncommon-subsequence-ii.cpp
 create mode 100644 Codes/2288-apply-discount-to-prices.cpp
 create mode 100644 Codes/2288-apply-discount-to-prices.py
 create mode 100644 Solutions/LeetCode 0522.最长特殊序列II.md
 create mode 100644 Solutions/LeetCode 2288.价格减免.md