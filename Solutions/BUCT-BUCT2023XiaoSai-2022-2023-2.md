---
title: BUCTOJ - 2023校赛 - 2022-2023-2
date: 2023-05-10 16:09:20
tags: [题解, BUCTOJ, 中等, 阅读理解, 字符串匹配, 字符串, 数学, 暴力, 模拟, 思维]
---

# BUCTOJ - 2023校赛 - 2022-2023-2 - 部分题解

# 前言

本题解开始写于2023.5.10，比赛开始日期未知，现处于验题阶段。

但是放心，比赛结束之前是不会公布此题解的。看到此题解之时必在比赛结束之后（飞某除外）

+ 比赛地址：[BUCTCoder@Contest3174](https://buctcoder.com/contest.php?cid=3174)
+ 补题地址：[BUCTCoder@Contest3176](https://buctcoder.com/contest.php?cid=3176)

只写了部分题解 且 部分题目较验题时可能有所变化。

## 问题 A: 大雪封路

[题目地址](https://buctcoder.com/problem.php?id=7024)

## 问题 B: 本题由ChatGPT生成

[题目地址](https://buctcoder.com/problem.php?id=7025)

知识点：阅读理解, 字符串匹配

### 题目描述

莎士比亚穿越到了现代，对电影这种新奇的艺术形式产生了浓厚的兴趣。

他观看了几部不同类型的经典影片：Gone with the Wind（乱世佳人）讲述了一段动荡时代的爱恨情仇，Twelve Angry Men（十二怒汉）展现了一个陪审团的辩论过程，The Sound of Music（音乐之声）唱出了一家人的欢乐与困难，The Godfather（教父）揭示了黑手党的权力斗争，Star Wars（星球大战）描绘了一个遥远的银河系中的冒险故事，Alien（异形）惊悚地揭示了外星生物的恐怖，Back to the Future（回到未来）幽默地展示了时空旅行的可能性。

莎翁被这些影片深深地打动，于是用他独特的诗才，用这几部影片的片名拼凑出了一首诗：莎翁被这些影片深深地打动，于是用他独特的诗才，用这几部影片的片名拼凑出了一首诗：

```
In days of old when knights were bold,
And journeys gone with the wind,
A tale was told of men so cold,
Twelve angry men within.

Their fury raged like fire ablaze,
But hark! What's that I hear?
The sound of music through the haze,
A melody so clear.

It spoke of love and family ties,
Of the godfather's might,
And battles fought in distant skies,
In star wars day and night.

But though the future seemed so grand,
With alien life to find,
Our hero wished to take a stand,
And journey back to the future in time.

For in his heart he knew so true,
That the sound of music's call,
Would guide him home to love anew,
And peace would come to all.
```

### 输入

无

### 输出

请输出一部电影的英文原名。

例如，如果他最喜欢的是《回到未来》，请输出一行"Back to the Future"（不含引号）。

### 解题思路

我们只需要复制题目描述中的所有影片名：“Gone with the Wind”、“Twelve Angry Men”、...在网页中Ctrl + F搜索一下，看看哪个影片名出现了两次，就输出哪个影片名即可

### AC代码

#### C++

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    puts("The Sound of Music");
    return 0;
}
```

#### Python

```python
print('The Sound of Music')
```

## 问题 C: 简单的数学题

[题目地址](https://buctcoder.com/problem.php?id=7026)

## 问题 D: 圆的面积

[题目地址](https://buctcoder.com/problem.php?id=7027)

## 问题 E: 英雄熟练度

[题目地址](https://buctcoder.com/problem.php?id=7028)

知识点：思维, 模拟

### 题目描述

小玉是一名资深的英雄联盟（青铜）玩家，他最爱的三个英雄是亚索（Yasuo）、易大师（Master Yi）和李青（Lee Sin）。

小玉对每个英雄都有一定的掌握程度，掌握程度为0表示他完全不会玩这个英雄，而掌握程度为100表示他能够熟练地驾驭这个英雄。

小玉可以对他最喜欢的三个英雄进行特训，提高自己的技能。每次特训会使得他选择的一个英雄的掌握程度增加1，而另外两个英雄的掌握程度都会减少1。

作为小玉的游戏伙伴，你可以给他出一些特训建议。但你的目的是使得他最终有两个掌握程度为0的英雄。因为你们要进行一场SOLO赛，只要你禁用掉他唯一还会玩的英雄，就可以轻松取胜。请问你是否能得逞？

在特训的过程中，你不能让小玉的任何一个英雄的掌握程度低于0。

### 输入

输入的第一行为一个整数 T(1 ≤ T ≤ 105)，表示共有 T 组测试数据。

接下来依次出现 T 组测试数据，每组数据包含三个整数 Y,M,L(0 ≤ Y,M,L ≤ 100)，代表小玉对亚索、易大师和李青这三个英雄的初始掌握程度。

### 输出

对于每组数据，如果你能够通过合理安排特训计划，使得小玉在若干次特训后拥有两个掌握程度为0的英雄，输出一行“Yes”，否则输出一行“No”（不含引号）。

### 样例输入

```
1
1 2 3
```

### 样例输出

```
Yes
```

### 解题思路

题目意思是：三个人物每次选择一个数值加一，另外两个数值减一，整个过程不能出现负数。问你能否将三个数变成两个0和一个非零。

答案一定是Yes。

在三个数均不相等时，我们可以每次增加最小的那个数减小另外两个数，直到三个数中有至少两个数相同。

之后无脑让相同的这两个数减少另一个数增加就好了。

### AC代码

#### C++

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int T;
    cin >> T;
    while (T--) {
        puts("Yes");
    }
    return 0;
}
```

#### Python

```python
T = int(input())
for _CASE in range(T):
    print('Yes')
```

## 问题 F: 乘号漂移

[题目地址](https://buctcoder.com/problem.php?id=7029)

知识点：字符串, 数学, 暴力, 模拟

### 题目描述

乘号漂移是一种数字现象，指的是在一个只有一个乘号的算式中，将乘号像漂移一样滑动到另一个（非开头或结尾的）位置，而不影响算式的结果。

比如：1 ∗ 6664，将乘号向右滑动三位之后，得到 1666 ∗ 4，而这两个算式的值都是 6664。

还有一些其他的乘号漂移的例子：

+ 3999 ∗ 75 → 3 ∗ 99975
+ 1 ∗ 0101 → 101 ∗ 01

现在给你只有一个乘号的算式，请你判断这个算式能否进行乘号漂移。

### 输入

输入的第一行为一个整数 T(1 ≤ T ≤ 100)，表示共有 T 组测试数据。

接下来依次出现 T 组测试数据，每组数据包含一行字符串 S(3 ≤ |S| ≤ 18)，S 仅包含阿拉伯数字和一个乘号 “ ∗”，表示一个算式，乘数和被乘数可能有前导0，乘号不会出现在开头或结尾

### 输出

对于每组数据，如果算式能进行乘号漂移，请输出一行“Yes”，否则输出一行“No”（不含引号）。

### 样例输入

```
4
1*6664
101*01
3*99975
412*43
```

### 样例输出

```
Yes
Yes
Yes
No
```

### 解题思路

模拟，将乘号“漂移”到所有的非原始位置，看有无与漂移前相同的结果。

### AC代码

#### C++

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int locMul = s.find('*');
        ll originalVal = stoll(s.substr(0, locMul)) * stoll(s.substr(locMul + 1, s.size() - locMul - 1));
        string pureNum = s.substr(0, locMul) + s.substr(locMul + 1, s.size() - locMul - 1);
        for (int loc = 1; loc < pureNum.size(); loc++) {  // 将乘号置于哪个下标之前
            if (loc == locMul) {
                continue;
            }
            if (originalVal == stoll(pureNum.substr(0, loc)) * stoll(pureNum.substr(loc, pureNum.size() - loc))) {
                puts("Yes");
                goto loop;
            }
        }
        puts("No");
        loop:;
    }
    return 0;
}
```

#### Python

我不知道提交上去为什么连样例都无法通过

本地测试是可以的

```bash
python BUCT.py < in > out 
```

```python
T = int(input())
for _CASE in range(T):
    s = input()
    locMul = s.find('*')
    originalVal = int(s[:locMul]) * int(s[locMul + 1:])
    pureNum = s[:locMul] + s[locMul + 1:]
    can = False
    for loc in range(1, len(pureNum)):
        if loc == locMul:
            continue
        if int(pureNum[:loc]) * int(pureNum[loc:]) == originalVal:
            can = True
            break
    print('Yes' if can else 'No')
```

## 问题 G: 铲雪

[题目地址](https://buctcoder.com/problem.php?id=7030)

## 问题 H: 厨房安排

[题目地址](https://buctcoder.com/problem.php?id=7031)

## 问题 I: 半排列

[题目地址](https://buctcoder.com/problem.php?id=7032)

## 问题 J: 洞窟探险

[题目地址](https://buctcoder.com/problem.php?id=7033)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/05/10/BUCT-BUCT2023XiaoSai-2022-2023-2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131293300](https://letmefly.blog.csdn.net/article/details/131293300)