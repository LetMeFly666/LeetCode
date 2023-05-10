---
title: Codeforces - Codeforces Round 857 (Div. 2) - B. Settlement of Guinea Pigs
date: 2023-04-05 21:20:13
tags: [题解, Codeforces, 中等, 思维]
---


@[TOC](目录)

## Codeforces Round 857 (Div. 2)-B. Settlement of Guinea Pigs

<a href="https://codeforces.com/contest/1802/problem/B">传送门</a>

**Time Limit**: 1 second

**Memory Limit**: 256 megabytes

### Problem Description

Dasha loves guinea pigs very much. In this regard, she decided to settle as many guinea pigs at home as possible and developed a plan for the next $n$ days. Every day, she will either buy a new guinea pig or call a doctor to examine all her pets.

Unfortunately, the store where she was going to buy guinea pigs does not understand them. Therefore, it cannot determine their gender. Dasha can't do it either. The only one who can help is a doctor. 

To keep guinea pigs, aviaries are needed. Dasha plans to buy them in the same store. Unfortunately, only one species is sold there — a double aviary. No more than two guinea pigs can live in it.

Since Dasha does not want to cause moral injury to her pets — she will not settle two guinea pigs of different genders in one aviary.

Help Dasha calculate how many aviaries in the worst case you need to buy so that you can be sure that at no moment of time do two guinea pigs of different genders live in the same aviary.**As part of this task, we believe that guinea pigs have only two genders — male and female.**

### Input

The first line of input data contains one number $t$ ($1 \leqslant t \leqslant 10^5$) — the number of input data sets.

The first line of each input data set contains one number $n$ ($1 \leqslant n \leqslant 10^5$) — the number of days Dasha has a plan for.

The next line contains $n$ numbers $b_1, b_2, b_3, \ldots, b_n$ ($1 \leqslant b_i \leqslant 2$) — Dasha's plan. If $b_i = 1$, then on the $i$th day, Dasha will buy a new guinea pig. If $b_i = 2$, then on the $i$th day, a doctor will come to Dasha and help determine the sex of all guinea pigs that Dasha already has.

It is guaranteed that the sum of $n$ for all input data sets does not exceed $10^5$.

### Output

For each set of input data, output one number — the minimum number of aviaries Dasha needs to buy so that no matter what the genders of the pigs turn out to be, we can settle them so that at no point in time do two guinea pigs of different genders live together.

### Sample Input

```
6
3
1 1 1
3
2 2 2
5
1 1 1 2 1
10
1 2 1 2 1 2 1 2 1 2
20
1 2 1 1 1 1 1 2 1 2 1 2 2 1 1 1 1 1 1 1
20
2 1 1 2 1 1 2 1 2 2 1 1 1 2 2 1 1 1 1 2
```

### Sample Onput

```
3
0
3
4
12
9
```

### Note

In the first set of input data, Dasha needs to put each guinea pig in a separate enclosure, since she does not know their gender.

In the second set of input data, Dasha will buy $0$ guinea pigs, which means she will need $0$ aviaries.

In the third set of input data, you even need $3$ aviaries to put each guinea pig in a separate aviary before the doctor arrives at the $4$th day. When she finds out their gender, at least two guinea pigs will be of the same gender and they can be placed in one aviary, and the third in another aviary. Thus, she will have one free aviary in which she can settle a new guinea pig. So answer is $3$.

In the fourth set of input data, we show that $4$ is the optimal answer. 

To begin with, we note that the first four guinea pigs can be placed one at a time in an aviary. Then a doctor will come and determine their gender. Among these four guinea pigs there will be at least one pair of the same gender, because: either male guinea pigs are at least $2$, or they are not more than $1$, which means that the female is at least $3$. Now we can put this couple in one aviary, and the other two in separate ones. We will have one more empty aviary where we can put a new pig.

Now let's show that the answer is at least $4$. Let's say that among the first $4$ guinea pigs, $3$ are female and $1$ is male. We need at least $3$ aviaries to settle them. Then, when we buy a new guinea pig, we will need another aviary in which we will put it, since we do not know its gender.

### 题目大意

天竺鼠（tiān zhú shǔ，一下简称老鼠）爱好者一共进行$n$天操作。

每次操作可以买一只**性别未知**的老鼠，也可以请老鼠专家鉴定所有已购老鼠的性别。

爱好者要给老鼠安排到双人笼中（啊呸，双鼠笼，一个笼子里能装两只老鼠），但是为了防止意外的情况发生，爱好者决定，**只有性别相同的老鼠才能被分配到同一个笼子里**

现在已知爱好者$n$天的操作（1是买新老鼠，2是请性别鉴定师），请你帮爱好者算一算，性别鉴定结果最优的情况下，至少要准备多少个笼子。

### 解题思路

遍历输入的1 2序列，在每次遇到2之前，每个1需要1个笼子（因为不知道新鼠的性别，所以新的老鼠必须在单独的一个笼子里）

一旦遇到2，就需要把之前所有的老鼠“尽可能地压缩到最少的笼子里”，也就是说两只相同性别的老鼠会被放到一个笼子里

关键就在于，假设医生来检查时已有n只老鼠，那么，这n只老鼠最多占据多少只笼子呢？

答案是：只有一只是雄性老鼠，其他n - 1只全是雌性老鼠

这样，我们就知道了每时每刻需要多少笼子，取整个过程的最大值就是答案。

**What's More** <small>这让我想起了我们学校大约半个月前的甲流隔离，也是两人间，但是，可能🚹🚺混寝！kz的病友就是被分配到了妹子的房间后不愿意要求调换后来到kz隔间的。。。</small>

### AC代码

**C++**

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
        int n;
        cin >> n;
        int ans = 0;
        int nowSingle = 0, nowGirl = 0, nowBoy = 0;
        while (n--) {
            int t;
            cin >> t;
            if (t == 1) {
                nowSingle++;
            }
            else {
                if (!nowBoy) {
                    if (!nowSingle) {  // 没单鸟
                        continue;
                    }
                    nowBoy = 1;
                    nowGirl = nowSingle - 1;
                    nowSingle = 0;
                }
                else {
                    nowGirl += nowSingle;
                    nowSingle = 0;
                }
            }
            ans = max(ans, nowSingle + (nowBoy + 1) / 2 + (nowGirl + 1) / 2);
        }
        cout << ans << endl;
    }
    return 0;
}
```

**题外话：**

这道题目是2023年3月9日帮lwx学妹看那次CF比赛时想的解法，拖到了现在才开始写题解...

And：

上次使用脚本将CF题面转Markdown还是2022.3.7 20:02，那次获取的题面是1649的D。天呐，时光飞逝，我都这么久没写CF的题解了吗！

> 原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/04/05/Codeforces%20-%20Codeforces%20Round%20857%20(Div.%202)%20-%20B.%20Settlement%20of%20Guinea%20Pigs/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129978565](https://letmefly.blog.csdn.net/article/details/129978565)