<!--
 * @Author: LetMeFly
 * @Date: 2024-12-19 18:08:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-19 18:08:12
-->
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git pull origin master
remote: Enumerating objects: 33, done.
remote: Counting objects: 100% (33/33), done.
remote: Compressing objects: 100% (22/22), done.
remote: Total 33 (delta 11), reused 27 (delta 11), pack-reused 0 (from 0)
Unpacking objects: 100% (33/33), 245.08 KiB | 63.00 KiB/s, done.
From ssh.github.com:LetMeFly666/LeetCode
 * branch                    master     -> FETCH_HEAD
   d7f14e7ffd2..3bc3ccac4f4  master     -> origin/master
Updating d7f14e7ffd2..3bc3ccac4f4
Fast-forward
 Codes/2931-maximum-spending-after-buying-items.cpp |  33 ++++
 Codes/2931-maximum-spending-after-buying-items.go  |  27 +++ 
 .../2931-maximum-spending-after-buying-items.java  |  29 +++ 
 Codes/2931-maximum-spending-after-buying-items.py  |  21 +++ 
 ...y-state-after-k-multiplication-operations-i.cpp |  26 +++ 
 ...ay-state-after-k-multiplication-operations-i.go |  20 ++  
 ...-state-after-k-multiplication-operations-i.java |  21 +++ 
 ...ay-state-after-k-multiplication-operations-i.py |  17 ++  
 README.md                                          |   2 +   
 ...234\200\345\244\247\345\274\200\351\224\200.md" | 209 +++++++++++++++++++++
 ...34\200\347\273\210\346\225\260\347\273\204I.md" | 198 +++++++++++++++++++
 Solutions/Other-Accumulation-SomeTips.md           | 115 +++++++++++-
 Solutions/Other-English-LearningNotes-SomeWords.md |  19 +-
 Solutions/Other-Japanese-LearningNotes.md          |   2 +-
 d.bash                                             |   0
 tryGoPy/CHANGELOG.md                               |  88 ---------
 ...0\350\204\232\346\234\254\347\232\204output.md" |  81 --------
 17 files changed, 730 insertions(+), 178 deletions(-)
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git pull origin master
remote: Enumerating objects: 91, done.
remote: Counting objects: 100% (14/14), done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 91 (delta 8), reused 8 (delta 8), pack-reused 77 (from 1)
Unpacking objects: 100% (91/91), 272.90 KiB | 42.00 KiB/s, done.
From ssh.github.com:LetMeFly666/LeetCode
 * branch                    master     -> FETCH_HEAD
   3bc3ccac4f4..6469449cc37  master     -> origin/master
Updating 3bc3ccac4f4..6469449cc37
Fast-forward
 Codes/1338-reduce-array-size-to-the-half.cpp       |  51 +++++  
 Codes/1338-reduce-array-size-to-the-half.go        |  26 +++    
 Codes/1338-reduce-array-size-to-the-half.java      |  26 +++    
 Codes/1338-reduce-array-size-to-the-half.py        |  20 ++     
 Codes/1847-closest-room.cpp                        |  42 ++++   
 Codes/1847-closest-room.go                         |  23 +++    
 Codes/1847-closest-room.java                       |  44 +++++  
 Codes/1847-closest-room.py                         |  54 +++++  
 ...-state-after-k-multiplication-operations-ii.cpp |  67 +++++++
 ...ate-after-k-multiplication-operations-ii_cp.cpp |  72 +++++++
 README.md                                          |   6 +-
 ...244\247\345\260\217\345\207\217\345\215\212.md" | 153 +++++++++++++++
 ...277\221\347\232\204\346\210\277\351\227\264.md" | 188 ++++++++++++++++++
 ...4\200\347\273\210\346\225\260\347\273\204II.md" | 217 +++++++++++++++++++++
 Solutions/Other-Accumulation-SomeTips.md           | 163 ++++++++++++++--
 Solutions/Other-CloudflareWorkers-How2use.md       |  10 +-
 Solutions/Other-English-LearningNotes-SomeWords.md |  10 +
 Solutions/Other-Japanese-LearningNotes.md          |   5 +-
 api/calendar/README.md                             | 164 ++++++++++++++++
 api/calendar/front/html.js                         |  65 ++++++
 api/calendar/front/temp/README.md                  |   7 +
 api/calendar/front/temp/index.html                 |  23 +++
 api/calendar/front/temp/index2.html                |  61 ++++++
 api/calendar/handler.js                            |  23 +++
 api/calendar/url.js                                |  12 ++
 api/github/public/README.md                        |  12 +-
 api/github/public/handler.js                       |   8 +-
 api/github/public/url.js                           |   6 +
 api/main.js                                        |  22 ++-
 api/user/README.md                                 |  79 ++++++++
 api/user/temp/README.md                            |   7 +
 api/user/temp/user-table-create.sql                |  14 ++
 api/user/temp/user-user1Login.sql                  |   2 +
 api/wrangler.toml                                  |   5 +
 d.bash                                             |   0
 tryGoPy/Go/001/main.go                             |  36 ++++
 tryGoPy/Java/.gitignore                            |   1 +
 tryGoPy/Java/001/main.java                         |  11 ++
 tryGoPy/Java/002/main.java                         |  11 ++
 tryGoPy/Java/003/main.java                         |  11 ++
 tryGoPy/Java/004/main.java                         |   6 +
 tryGoPy/Java/005/TreeSetExample.java               |  26 +++
 tryGoPy/Java/006/ArrayExample.java                 |  21 ++
 tryGoPy/Py/001-async/1then2.py                     |  39 ++++
 tryGoPy/Py/001-async/2then1.py                     |  42 ++++
 tryGoPy/Py/002-async/1then2.py                     |  29 +++
 tryGoPy/Py/002-async/2then1.py                     |  32 +++
 tryGoPy/{ => Py}/py1/README.md                     |   0
 tryGoPy/{ => Py}/py1/a.py                          |   0
 tryGoPy/{ => Py}/py1/b.py                          |   0
 ...234\254\345\221\250\345\221\250\346\212\245.md" |  17 --
 51 files changed, 1913 insertions(+), 56 deletions(-)
 create mode 100644 Codes/1338-reduce-array-size-to-the-half.cpp
 create mode 100644 Codes/1338-reduce-array-size-to-the-half.go
 create mode 100644 Codes/1338-reduce-array-size-to-the-half.java
 create mode 100644 Codes/1338-reduce-array-size-to-the-half.py
 create mode 100644 Codes/1847-closest-room.cpp
 create mode 100644 Codes/1847-closest-room.go
 create mode 100644 Codes/1847-closest-room.java
 create mode 100644 Codes/1847-closest-room.py
 create mode 100644 Codes/3266-final-array-state-after-k-multiplication-operations-ii.cpp
 create mode 100644 Codes/3266-final-array-state-after-k-multiplication-operations-ii_cp.cpp
 create mode 100644 "Solutions/LeetCode 1338.\346\225\260\347\273\204\345\244\247\345\260\217\345\207\217\345\215\212.md"
 create mode 100644 "Solutions/LeetCode 1847.\346\234\200\350\277\221\347\232\204\346\210\277\351\227\264.md"
 create mode 100644 "Solutions/LeetCode 3266.K\346\254\241\344\271\230\350\277\220\347\256\227\345\220\216\347\232\204\346\234\200\347\273\210\346\225\260\347\273\204II.md"
 create mode 100644 api/calendar/README.md
 create mode 100644 api/calendar/front/html.js
 create mode 100644 api/calendar/front/temp/README.md
 create mode 100644 api/calendar/front/temp/index.html
 create mode 100644 api/calendar/front/temp/index2.html
 create mode 100644 api/calendar/handler.js
 create mode 100644 api/calendar/url.js
 create mode 100644 api/user/README.md
 create mode 100644 api/user/temp/README.md
 create mode 100644 api/user/temp/user-table-create.sql
 create mode 100644 api/user/temp/user-user1Login.sql
 delete mode 100644 d.bash
 create mode 100644 tryGoPy/Go/001/main.go
 create mode 100644 tryGoPy/Java/.gitignore
 create mode 100644 tryGoPy/Java/001/main.java
 create mode 100644 tryGoPy/Java/002/main.java
 create mode 100644 tryGoPy/Java/003/main.java
 create mode 100644 tryGoPy/Java/004/main.java
 create mode 100644 tryGoPy/Java/005/TreeSetExample.java
 create mode 100644 tryGoPy/Java/006/ArrayExample.java
 create mode 100644 tryGoPy/Py/001-async/1then2.py
 create mode 100644 tryGoPy/Py/001-async/2then1.py
 create mode 100644 tryGoPy/Py/002-async/1then2.py
 create mode 100644 tryGoPy/Py/002-async/2then1.py
 rename tryGoPy/{ => Py}/py1/README.md (100%)
 rename tryGoPy/{ => Py}/py1/a.py (100%)
 rename tryGoPy/{ => Py}/py1/b.py (100%)
 delete mode 100644 "tryGoPy/\346\234\254\345\221\250\345\221\250\346\212\245.md"