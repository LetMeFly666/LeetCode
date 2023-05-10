---
title: BUCTOJ - 2023校赛 - 2022-2023-2
date: 2023-05-10 16:09:20
tags: [题解, BUCTOJ, 中等, 阅读理解, 字符串匹配, 字符串, 数学, 暴力, 模拟]
---

# BUCTOJ - 2023校赛 - 2022-2023-2

# 前言

本题解开始写于2023.5.10，比赛开始日期未知，现处于验题阶段。

但是放心，比赛结束之前是不会公布此题解的。看到此题解之时必在比赛结束之后（飞某除外）

比赛地址：[]() TODO: 填写比赛地址和补题地址
补题地址：[]()

## 问题 A: 大雪封路

[题目地址](https://buctcoder.com/problem.php?id=7024)

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

```

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

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

```

## 问题 D: 圆的面积

[题目地址](https://buctcoder.com/problem.php?id=7027)

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

```

## 问题 E: 英雄熟练度

[题目地址](https://buctcoder.com/problem.php?id=7028)

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

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

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

```

## 问题 H: 厨房安排

[题目地址](https://buctcoder.com/problem.php?id=7031)

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

```

## 问题 I: 半排列

[题目地址](https://buctcoder.com/problem.php?id=7032)

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

```

## 问题 J: 洞窟探险

[题目地址](https://buctcoder.com/problem.php?id=7033)

知识点：

### 题目描述



### 输入



### 输出



### 样例输入

```

```

### 样例输出

```

```

### 解题思路



### AC代码

#### C++

```cpp

```

#### Python

```python

```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/10/BUCT-BUCT2023XiaoSai-2022-2023-2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/TODO:](https://letmefly.blog.csdn.net/article/details/TODO:)

TODO: 添加此博客至README
