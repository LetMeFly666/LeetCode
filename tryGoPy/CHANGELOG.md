PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git pull origin master
remote: Enumerating objects: 35, done.
remote: Counting objects: 100% (35/35), done.
remote: Compressing objects: 100% (17/17), done.
remote: Total 26 (delta 9), reused 25 (delta 9), pack-reused 0 (from 0)
Unpacking objects: 100% (26/26), 19.92 KiB | 4.00 KiB/s, done.
From github.com:LetMeFly666/LeetCode
 * branch                master     -> FETCH_HEAD
   9e41c9485..6cb55b4a4  master     -> origin/master
Updating 9e41c9485..6cb55b4a4
Fast-forward
 ...-the-count-of-numbers-which-are-not-special.cpp | 104 +++++++     
 Codes/3238-find-the-number-of-winning-players.cpp  |  58 ++++        
 Codes/3238-find-the-number-of-winning-players.go   |  26 ++
 Codes/3238-find-the-number-of-winning-players.java |  24 ++
 Codes/3238-find-the-number-of-winning-players.py   |  14 +
 KongMingQi.cpp                                     |   3 +-
 README.md                                          |   4 +-
 Solutions/LeetCode 3238.求出胜利玩家的数目.md      | 176 ++++++++++++
 Solutions/Other-English-LearningNotes-SomeWords.md |   9 +-
 Solutions/Other-Japanese-LearningNotes.md          |   9 +-
 Solutions/Other-Python-LearnPythonFrom0.md         | 100 +++++++     
 Solutions/Other-Verilog-Note.md                    |   2 +
 history.del.html                                   |  67 +++++
 history.del.ipynb                                  | 238 ++++++++++++++++
 history.del.js                                     |  68 +++++
 history.del2.js                                    |  42 +++
 history.stillNeedREADME.del-视频压制.py            | 305 +++++++++++++++++++++
 tryGo/JSFUZZ.bash                                  |  19 --
 tryGo/chat-6yggde35y.bash                          | 118 --------
 temp-PythonTeaching.md => tryGo/temp-ZuiJin.md     |   0
 tryGo/temp.2.html                                  |  37 +++
 tryGo/temp.cssJianBian.html                        |  40 +++
 tryGo/tryEasyX.cpp                                 |  17 --
 24 files changed, 1381 insertions(+), 158 deletions(-)
 create mode 100644 Codes/3233-find-the-count-of-numbers-which-are-not-special.cpp
 create mode 100644 Codes/3238-find-the-number-of-winning-players.cpp
 create mode 100644 Codes/3238-find-the-number-of-winning-players.go
 create mode 100644 Codes/3238-find-the-number-of-winning-players.java
 create mode 100644 Codes/3238-find-the-number-of-winning-players.py
 create mode 100644 Solutions/LeetCode 3238.求出胜利玩家的数目.md
 create mode 100644 Solutions/Other-Python-LearnPythonFrom0.md
 create mode 100644 history.del.html
 create mode 100644 history.del.ipynb
 create mode 100644 history.del.js
 create mode 100644 history.del2.js
 create mode 100644 history.stillNeedREADME.del-视频压制.py
 delete mode 100644 tryGo/JSFUZZ.bash
 delete mode 100644 tryGo/chat-6yggde35y.bash
 rename temp-PythonTeaching.md => tryGo/temp-ZuiJin.md (100%)
 create mode 100644 tryGo/temp.2.html
 create mode 100644 tryGo/temp.cssJianBian.html
 delete mode 100644 tryGo/tryEasyX.cpp
 create mode 100644 tryGo/tt.3.html
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> cls^C
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> git pull origin master
remote: Enumerating objects: 30, done.
remote: Counting objects: 100% (30/30), done.
remote: Compressing objects: 100% (18/18), done.
remote: Total 30 (delta 12), reused 29 (delta 12), pack-reused 0 (from 0)
Unpacking objects: 100% (30/30), 46.26 KiB | 19.00 KiB/s, done.
From github.com:LetMeFly666/LeetCode
 * branch                master     -> FETCH_HEAD
   6cb55b4a4..37a4490d3  master     -> origin/master
Updating 6cb55b4a4..37a4490d3
Fast-forward
 .gitignore                                         |    1 +
 ...allest-range-covering-elements-from-k-lists.cpp |  174 +++
 KongMingQi.cpp                                     | 1287 --------------------
 README.md                                          |    1 +
 Solutions/LeetCode 0632.最小区间.md                |  109 ++
 Solutions/Other-English-LearningNotes-SomeWords.md |    3 +
 Solutions/Other-Japanese-LearningNotes.md          |    1 +
 Solutions/Other-Python-LearnPythonFrom0.md         |   50 +-
 history.del.html                                   |   67 -
 history.del.ipynb                                  |  238 ----
 history.del.js                                     |   68 --
 history.del2.js                                    |   42 -
 history.stillNeedREADME.del-视频压制.py            |  305 -----
 tryGo/.gitkeep                                     |    2 -
 tryGo/temp.2.html                                  |   37 -
 tryGo/temp.cssJianBian.html                        |   40 -
 tryGo/tt.3.html                                    |   59 -
 tryGoPy/.gitkeep                                   |    2 +
 {tryGo => tryGoPy}/OUT.md                          |   16 +-
 tryGoPy/py1/README.md                              |   13 +
 tryGoPy/py1/a.py                                   |    8 +
 tryGoPy/py1/b.py                                   |   10 +
 tryGo/temp-ZuiJin.md => tryGoPy/最近.md            |    0
 {tryGo => tryGoPy}/本周周报.md                     |   34 +-
 24 files changed, 394 insertions(+), 2173 deletions(-)
 create mode 100644 Codes/0632-smallest-range-covering-elements-from-k-lists.cpp
 delete mode 100644 KongMingQi.cpp
 create mode 100644 Solutions/LeetCode 0632.最小区间.md
 delete mode 100644 history.del.html
 delete mode 100644 history.del.ipynb
 delete mode 100644 history.del.js
 delete mode 100644 history.del2.js
 delete mode 100644 history.stillNeedREADME.del-视频压制.py
 delete mode 100644 tryGo/.gitkeep
 delete mode 100644 tryGo/temp.2.html
 delete mode 100644 tryGo/temp.cssJianBian.html
 delete mode 100644 tryGo/tt.3.html
 create mode 100644 tryGoPy/.gitkeep
 rename {tryGo => tryGoPy}/OUT.md (86%)
 create mode 100644 tryGoPy/py1/README.md
 create mode 100644 tryGoPy/py1/a.py
 create mode 100644 tryGoPy/py1/b.py
 rename tryGo/temp-ZuiJin.md => tryGoPy/最近.md (100%)
 rename {tryGo => tryGoPy}/本周周报.md (92%)
PS F:\OtherApps\Program\Git\Store\Store20_LeetCode> 