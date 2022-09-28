---
title: 码蹄集 - MT3252 - 子序列问题
date: 2022-09-28 21:38:47
tags: [题解, 码蹄集, 简单, 子序列, 子问题]
---

@[TOC](传送门)


---


## 子序列问题

+ <a href="https://matiji.net/exam/brushquestion/252/3846/4C6668FEB8CFD6520DE73B365B31D1A4"> 子序列问题</a> <a href="https://matiji.net/exam/dohomework/1956/4">.</a>

<small>时间限制：1秒</small>
<small>空间限制：128M</small>



---



### 题目描述

小码哥给了你一个长度为 $n$ 的字符串 $s$，并请你帮他解决一个问题：

选择 $s$ 的两个长为 $k$ 的子序列 $A$、$B$ 满足：
1.$A=B$，即对于 $i\in[1,k]$，有 $A_i=B_i$。
2.令 ${a_i}$为 $A$ 的每一位在 $s$ 中的下标的集合，${b_i}$为 $B$ 的每一位在 $s$ 中的下标的集合，$m$ 为 ${a_i}$两个集合中相等的元素的个数，则 $m+1\le k$。

请你找到最大的 $k$ 使得 $s$ 中存在满足上述条件的 $A$ 和 $B$。若不存在则输出 $0$。

---

### 输入描述

输入一行，一个字符串 $s$，满足 $|s|\in[1,2\times 10^5]$，保证所有字符均为小写字母。

#### 数据范围

无



---


### 输出描述

输出一行，$k$。



---


### 样例一

#### 输入

```
apple
```

#### 输出

```
4
```

样例中 ```ap le``` 和 ```a ple``` 两个子序列满足题中条件（即 ${a_i}={1,2,4,5}$，${b_i}={1,3,4,5}$。


# 题目分析

这道题主要是题目较难理解。理解了之后就不难了。

说人话就是：从原字符串中选取两个子序列，这两个子序列相同，但不能全部选自原字符串的相同位置的元素。问所有选法中，子序列最长能有多长。

比如```apple```，我们选取第1、2、4、5个字母，或者选取第1、3、4、5个字母  所得到的子序列都是```aple```，但是```{1、2、4、5} ≠ {1、3、4、5}```

怎么做呢？不难发现，只要两个子序列中存在一个来源不同的元素即可。


假如出现了“xxxxxxabaxxxx”，那么我们就可以：两个子序列都选择“aba”前面的所有字母，一个子序列选择“aba”中的第一个“a”另一个子序列选择“aba”中的第二个“a”，两个子序列都选择“aba”后面的所有字母

因此，我们关心的就是，对于相同的字母，最近出现的距离是多少。

最终答案就是原始字符串长度减去“最近两个相同字母的距离”

# AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
int main() {
    int shortest = 1e6;
    int cnt[26];
    memset(cnt, -1, sizeof(cnt));
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int th = s[i] - 'a';
        if (cnt[th] != -1) {
            shortest = min(shortest, i - cnt[th]);
        }
        cnt[th] = i;
    }
    cout << max(0, (int)s.size() - shortest) << endl;
    return 0;
}
```

<font color="black" face="楷体" size="5px">虽然代码可以复制，但最好还是自己理解后再敲哦</font>

<!-- <font color="black" face="楷体" size="5px">每周提前更新菁英班周赛题解，点关注，不迷路</font> -->

>原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/28/MaTiJi%20-%20MT3252%20-%20%E5%AD%90%E5%BA%8F%E5%88%97%E9%97%AE%E9%A2%98/)哦~
>Tisfy：[https://letmefly.blog.csdn.net/article/details/127097657](https://letmefly.blog.csdn.net/article/details/127097657)