<!--
 * @Author: LetMeFly
 * @Date: 2024-12-25 00:12:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-25 00:12:36
-->
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git pull origin master
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 1003 bytes | 17.00 KiB/s, done.
From ssh.github.com:LetMeFly666/LeetCode
 * branch                    master     -> FETCH_HEAD
   b4295956946..b2e26e89338  master     -> origin/master
Updating b4295956946..b2e26e89338
Fast-forward
 .../2545-sort-the-students-by-their-kth-score.cpp  |  20 +
 Codes/2545-sort-the-students-by-their-kth-score.go |  16 +
 ...210\206\346\225\260\346\216\222\345\272\217.md" | 147 +++++++
 Solutions/Other-English-LearningNotes-SomeWords.md |   2 +
 tryGoPy/CHANGELOG.2.md                             | 441 +++++++++++++++++++++
 tryGoPy/NEW-PROBLEM.txt                            |   7 -
 create mode 100644 Codes/2545-sort-the-students-by-their-kth-score.cpp
 create mode 100644 Codes/2545-sort-the-students-by-their-kth-score.py
 create mode 100644 "Solutions/LeetCode 2545.\346\240\271\346\215\256\347\254\254K\345\234\272\350\200\203\350\257\225\347\232\204\345\210\206\346\225\260\346\216\222\345\272\217.md"
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git pull origin master
remote: Enumerating objects: 106, done.
remote: Counting objects: 100% (106/106), done.
remote: Compressing objects: 100% (32/32), done.
remote: Total 83 (delta 46), reused 82 (delta 46), pack-reused 0 (from 0)
Unpacking objects: 100% (83/83), 22.19 KiB | 3.00 KiB/s, done.
From ssh.github.com:LetMeFly666/LeetCode
 * branch                    master     -> FETCH_HEAD
   b2e26e89338..ab894f2f285  master     -> origin/master
Updating b2e26e89338..ab894f2f285
Fast-forward
 ...705-maximum-number-of-eaten-apples_20241224.cpp |  93 +++++        
 ...1705-maximum-number-of-eaten-apples_20241224.go |  51 +++
 ...05-maximum-number-of-eaten-apples_20241224.java |  40 ++
 ...1705-maximum-number-of-eaten-apples_20241224.py |  32 ++
 README.md                                          |   1 +
 ...234\200\345\244\247\346\225\260\347\233\256.md" | 284 +++++++++++++
 Solutions/Other-CloudflareWorkers-How2use.md       |   2 +
 Solutions/Other-English-LearningNotes-SomeWords.md |   7 +
 api/.wrangler/state/v3/.gitignore                  |   1 +
 api/calendar/README.md                             | 257 +++++++++++- 
 api/calendar/back/README.md                        | 333 +++++++++++++++-
 api/calendar/back/event.js                         |  39 +-
 api/calendar/back/tags.js                          |  86 ++++
 api/calendar/back/temp/createTaskTableInDB.sql     |  72 +++-
 api/calendar/back/test/testBackEvent.py            |  15 +-
 api/calendar/back/test/testBackTag.py              |  56 +++
 api/calendar/back/{ => utils}/cookie.js            |   8 +-
 api/calendar/back/{ => utils}/user.js              |   4 +-
 api/calendar/handler.js                            |  26 +-
 api/calendar/url.js                                |   5 +-
 api/main.js                                        |  13 +-
 api/wrangler.toml                                  |  14 +-
 tryGoPy/.gitkeep                                   |   6 +-
 tryGoPy/CHANGELOG.2.md                             | 441 ---------------------
 tryGoPy/CHANGELOG.md                               | 139 -------
 tryGoPy/Go/002-for/main.go                         |  16 +
 26 files changed, 1403 insertions(+), 638 deletions(-)
 create mode 100644 Codes/1705-maximum-number-of-eaten-apples_20241224.cpp
 create mode 100644 Codes/1705-maximum-number-of-eaten-apples_20241224.go
 create mode 100644 Codes/1705-maximum-number-of-eaten-apples_20241224.java
 create mode 100644 Codes/1705-maximum-number-of-eaten-apples_20241224.py
 create mode 100644 "Solutions/LeetCode 1705.\345\220\203\350\213\271\346\236\234\347\232\204\346\234\200\345\244\247\346\225\260\347\233\256.md"
 create mode 100644 api/.wrangler/state/v3/.gitignore
 create mode 100644 api/calendar/back/tags.js
 create mode 100644 api/calendar/back/test/testBackTag.py
 rename api/calendar/back/{ => utils}/cookie.js (54%)
 rename api/calendar/back/{ => utils}/user.js (84%)
 delete mode 100644 tryGoPy/CHANGELOG.2.md
 delete mode 100644 tryGoPy/CHANGELOG.md
 create mode 100644 tryGoPy/Go/002-for/main.go