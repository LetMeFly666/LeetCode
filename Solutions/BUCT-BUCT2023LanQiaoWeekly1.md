---
title: BUCTOJ - 2023上半年ACM&蓝桥杯每周训练题-1
date: 2023-02-21 21:23:52
tags: [题解, BUCTOJ, 中等]
---

# BUCTOJ - 2023上半年ACM&蓝桥杯每周训练题-1

## 问题 A: 1.2 神奇兔子数列

[题目地址](https://buctcoder.com/problem.php?id=5803)

### 题目描述

假设第 1 个月有 1 对刚诞生的兔子，第 2 个月进入成熟期，第 3 个月开始生育兔子，而1 对成熟的兔子每月会生 1 对兔子，兔子永不死去……那么，由 1 对初生兔子开始，12 个月后会有多少对兔子呢？
兔子数列即斐波那契数列，它的发明者是意大利数学家列昂纳多·斐波那契（Leonardo Fibonacci，1170—1250）。1202 年，他撰写了《算盘全书（《Liber Abaci》）一书，该书是一部较全面的初等数学著作。书中系统地介绍了印度—阿拉伯数码及其演算法则，介绍了中国的“盈不足术”；引入了负数，并研究了一些简单的一次同余式组。

### 输入

无

### 输出

一个整数（12个月后有多少对兔子）

### 解题思路

这道题就是要求斐波那契数列的第12项

在计算斐波那契数列的过程中，我们只需要关注连续的3项。

使用两个变量_1和_2代表已经计算出的第一项和第二项，那么要计算出的第三项_3就等于$_1 + _2$

如此往复，更新第一项和第二项为原来的第二项和第三项，就能不断求出新的第三项。

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
    ll _1 = 1, _2 = 1, _3;
    for (int i = 3; i <= 12; i++) {
        _3 = _1 + _2;
        _1 = _2, _2 = _3;
    }
    cout << _3 << endl;
    return 0;
}
```

#### Python

```python
_1, _2, _3 = 1, 1, ''
for i in range(3, 13):
    _3 = _1 + _2
    _1, _2 = _2, _3
print(_3)
```

## 问题 B: 1.3 马克思手稿中的数学题

[题目地址](https://buctcoder.com/problem.php?id=5804)

### 题目描述

马克思手稿中有一道趣味数学问题：有 30 个人，其中有男人、女人和小孩，这些人在一家饭馆吃饭花了 50 先令；每个男人花 3 先令，每个女人花 2 先令，每个小孩花 1 先令；问男人、女人和小孩各有几人？

### 输入

无

### 输出

输出所有可能的解
每行三个整数x，y，z（用空格隔开，x代表男人，y代表女人，z代表小孩，按x升序排列）：
x y z

### 解题思路

数据量并不大，我们暴力枚举0到30范围内的所有x、y、z即可。

**注意**题目中说“其中有男人、女人和小孩”，也就是说每种人都有，不能为0。

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
    fi (x, 1, 31) {
        fi (y, 1, 31) {
            fi (z, 1, 31) {
                if (x + y + z == 30 && 3 * x + 2 * y + z == 50) {
                    cout << x << ' ' << y << ' ' << z << endl;
                }
            }
        }
    }
    return 0;
}
```

#### Python

```python
for x in range(1, 31):
    for y in range(1, 31):
        for z in range(1, 31):
            if  x + y + z == 30 and 3 * x + 2 * y + z == 50:
                print(x, y, z)
```

## 问题 C: 1.4 爱因斯坦的阶梯

[题目地址](https://buctcoder.com/problem.php?id=5805)

### 题目描述

爱因斯坦家里有一条长阶梯，若每步跨 2 阶，则最后剩 1 阶；若每步跨 3 阶，则最后剩 2 阶；若每步跨 5 阶，则最后剩 4 阶；若每步跨 6 阶，则最后剩 5 阶。只有每次跨 7 阶，最后才正好 1 阶不剩。请问这条阶梯共有多少阶？

### 输入

无

### 输出

满足题目的最小整数

### 解题思路

从1开始往上模拟即可

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
    int ans = 1;
    while (true) {
        if (ans % 2 == 1 && ans % 3 == 2 && ans % 5 == 4 && ans % 6 == 5 && ans % 7 == 0) {
            cout << ans << endl;
            break;
        }
        ans++;
    }
    return 0;
}
```

#### Python

```python
ans = 1
while True:
    if ans % 2 == 1 and ans % 3 == 2 and ans % 5 == 4 and ans % 6 == 5 and ans % 7 == 0:
        print(ans)
        break
    ans += 1
```

## 问题 D: 1.5 哥德巴赫猜想

[题目地址](https://buctcoder.com/problem.php?id=5806)

### 题目描述

哥德巴赫猜想：任一大于 2 的偶数，都可表示成两个素数之和。
验证：2000 以内大于 2 的偶数都能够分解为两个素数之和。

### 输入

无

### 输出

```
2000 以内大于 2 的偶数被分解的两个素数
按升序排列，第一个素数为最小值
4=2+2
6=3+3
8=3+5
10=3+7
12=5+7
14=3+11
16=3+13

......
```

### 解题思路

题目数据范围不大，我们可以先求出2000以内的素数并放入数组和哈希表中，接着对于某个偶数，从最小的素数开始尝试，快速得到$偶数-这个素数$是否也为素数。若是则输出，否则尝试大一点的素数。

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

bool isPrime(int n) {
    int k = sqrt(n);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> prime;
    unordered_set<int> se;
    for (int i = 2; i <= 2000; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
            se.insert(i);
        }
    }

    for (int i = 4; i <= 2000; i += 2) {
        for (int t : prime) {
            if (se.count(i - t)) {
                printf("%d=%d+%d\n", i, t, i - t);
                break;
            }
        }
    }
    return 0;
}
```

#### Python

```python
from math import sqrt


def isPrime(n):
    k = int(sqrt(n))
    for i in range(2, k + 1):
        if n % i == 0:
            return False
    return True


prime = []
se = set()

for i in range(2, 2001):
    if isPrime(i):
        prime.append(i)
        se.add(i)

for i in range(4, 2001, 2):
    for t in prime:
        if i - t in se:
            print(f"{i}={t}+{i-t}")
            break
```

## 问题 E: 2.2 加勒比海盗船

[题目地址](https://buctcoder.com/problem.php?id=5800)

### 题目描述

```
   在北美洲东南部，有一片神秘的海域，那里碧海蓝天、阳光明媚，这正是传说中海盗最活跃的加勒比海（Caribbean Sea）。17 世纪时，这里更是欧洲大陆的商旅舰队到达美洲的必经之地，所以当时的海盗活动非常猖獗，海盗不仅攻击过往商人，甚至攻击英国皇家舰……
   有一天，海盗们截获了一艘装满各种各样古董的货船，每一件古董都价值连城，一旦打碎就失去了它的价值。虽然海盗船足够大，但载重量为 C，每件古董的重量为 wi，海盗们该如何把尽可能多数量的宝贝装上海盗船呢？
```

### 输入

```
请输入问题的组数 m：
m ( 0 < m < 100 )
请输入载重量 c 及古董个数 n：
c n (0 < c, n < 10000)
请输入每个古董的重量，用空格分开：
w1 w2 w3 ... wn  (0 < wi < 100)
```

### 输出

能装入的古董最大数量为:
ans

### 输入样例

```
1
30 8
4 10 7 11 3 5 14 2
```

### 输出样例

```
5
```

### 解题思路

装载数量优先，那必是先装重量小的。

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

int a[10010];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = 0;
        while (m > 0 && ans < n) {
            if (m >= a[ans]) {
                m -= a[ans++];
            }
            else {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```

#### Python

```python
T = int(input())
for _ in range(T):
    m, n = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    ans = 0
    while m > 0 and ans < n:
        if m >= a[ans]:
            m -= a[ans]
            ans += 1
        else:
            break
    print(ans)
```

## 问题 F: 2.3 阿里巴巴与四十大盗

[题目地址](https://buctcoder.com/problem.php?id=5801)

### 题目描述

```
   有一天，阿里巴巴赶着一头毛驴上山砍柴。砍好柴准备下山时，远处突然出现一股烟尘，弥漫着直向上空飞扬，朝他这儿卷过来，而且越来越近。靠近以后，他才看清原来是一支马队，他们共有四十人，一个个年轻力壮、行动敏捷。一个首领模样的人背负沉重的鞍袋，从丛林中一直来到那个大石头跟前，喃喃地说道：“芝麻，开门吧！”随着那个头目的喊声，大石头前突然出现一道宽阔的门路，于是强盗们鱼贯而入。阿里巴巴待在树上观察他们，直到他们走得无影无踪之后，才从树上下来。他大声喊道：“芝麻，开门吧！”他的喊声刚落，洞门立刻打开了。
   他小心翼翼地走了进去，一下子惊呆了，洞中堆满了财物，还有多得无法计数的金银珠宝，有的散堆在地上，有的盛在皮袋中。突然看见这么多的金银财富，阿里巴巴深信这肯定是一个强盗们数代经营、掠夺所积累起来的宝窟。为了让乡亲们开开眼界，见识一下这些宝物，他想一种宝物只拿一个，如果太重就用锤子凿开，但毛驴的运载能力是有限的，怎么才能用驴子运走最大价值的财宝分给穷人呢？阿里巴巴陷入沉思中……
```

### 输入

```
样例的组数 t
t ( 0 < t < 100 )
宝物数量m和驴子的承载重量 n
m  n ( 0 < m, n < 10000 )
第i个宝物的重量和价值 ( 0 < wi, vi < 100 )

w1  v1  
w2  v2
...
wm  vm
```

### 输出

装入宝物的最大价值

### 输入样例

```
1
6 19
2 8
6 1
7 9 
4 3 
10 2 
3 4
```

### 输出样例

```
24.6
```

### 解题思路

注意题目描述了吗？“如果太重就用锤子凿开”。好家伙，凿开还是宝物的话，那就看哪个宝物的“含金密度”大呗！

接下来我们给每个宝物评分，评分规则是宝物的“密度”（$\frac{重量}{体积}$）

**需要注意的是**，这道题数据有误，数据中存在重量为0的宝物，也就是说其分数（密度）无限大。注意这时候不能用“重量 * 分数”来计算其总价值了。

**还需要注意的是**，题目中没有说明输出格式。经测试得知当答案为整数时输出0位小数，答案非整数时输出一些位的小数，完美贴合C++的cout。

**还需要注意的是**，题目中没有说明多组输入的格式，样例中的多组输入数据之间是有一个空行的，Python选手需要注意

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

struct Treasure {
    int w, v;
    double score;
} a[10010];

bool cmp(Treasure& a, Treasure& b) {
    return a.score > b.score;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].w, &a[i].v);
            a[i].score = 1. * a[i].v / a[i].w;
        }
        sort(a, a + n, cmp);
        double v = 0;
        double w = m;
        int th = 0;
        while (w > 0 && th < n) {
            if (!a[th].w) {
                v += a[th++].v;
                continue;
            }
            int thisW = min((double)a[th].w, w);
            v += thisW * a[th].score;
            w -= thisW;
            th++;
        }
        cout << v << endl;
    }
    return 0;
}
```

#### Python

Python提交上去会超时。。。

```python
class Treasure:
    def __init__(self, v, w) -> None:
        self.v = v
        self.w = w
        self.score = v / w if w else 100000000


T = int(input())
for _ in range(T):
    while True:
        thisLine = input()
        if thisLine:
            break
    n, m = map(int, thisLine.split())
    a = []
    for __ in range(n):
        w, v = map(int, input().split())
        a.append(Treasure(v, w))
    a.sort(key=lambda x: -x.score)
    v = 0
    w = m
    th = 0
    while w > 0 and th < n:
        # print('*' * 50)
        if not a[th].w:
            v += a[th].v
            th += 1
            continue
        thisW = min(w, a[th].w)
        v += thisW * a[th].score
        w -= thisW
        th += 1
    if int(v) == v:
        print(int(v))
    else:
        print("{:.1f}".format(v))
```

## 问题 G: 2.4 高级钟点秘书

[题目地址](https://buctcoder.com/problem.php?id=5802)

### 题目描述

```
所谓“钟点秘书”，是指年轻白领女性利用工余时间为客户提供秘书服务，并按钟点收取酬金。“钟点秘书”为客户提供有偿服务的方式一般是：采用电话、电传、上网等“遥控”式服务，或亲自到客户公司处理部分业务。其服务对象主要有三类：一是外地前来考察商务经营、项目投资的商人或政要人员，他们由于初来乍到，急需有经验和熟悉本地情况的秘书帮忙；二是前来开展短暂商务活动，或召开小型资讯发布会的国外客商；三是本地一些请不起长期秘书的企、事业单位。这些客户普遍认为：请“钟点秘书”，一则可免去专门租楼请人的大笔开销；二则可根据开展的商务活动请有某方面专长的可用人才；三则由于对方是临时雇用关系，工作效率往往比固定的秘书更高。据调查，在上海“钟点秘书”的行情日趋看好。对此，业内人士认为：为了便于管理，各大城市有必要组建若干家“钟点秘书服务公司”，通过会员制的形式，为众多客户提供规范、优良、全面的服务，这也是建设国际化大都市所必需的。
某跨国公司总裁正分身无术，为一大堆会议时间表焦头烂额，希望高级钟点秘书能做出合理的安排，能在有限的时间内召开更多的会议。
```

### 输入

```
输入样例组数：
t ( 0 < t < 10 )
输入会议总数：
n ( 0 < n < 10000)
输入会议的开始时间和结束时间，以空格分开： ( 0 < bi, ei < 50 )
b1  e1
b2  e2
...
bn  en
```

### 输出

最多可以安排的会议数目m

### 输入样例

```
1
10 
3 6 
1 4 
5 7 
2 5 
5 9 
3 8 
8 11 
6 10 
8 12 
12 14
```

### 输出样例

```
4
```

### 解题思路

对所有的会议排序，排序规则是：结束早的会议优先靠前。

这样，我们只需要从前到后遍历所有的会议，如果某个会议的开始时间不早于“秘书最后参会”的结束时间，那么就参加这个会议。

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
typedef pair<int, int> pii;
pii a[10010];

bool cmp(pii& a, pii& b) {
    return a.second < b.second;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
        }
        sort(a, a + n, cmp);
        int lastEnd = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i].first >= lastEnd) {
                ans++;
                lastEnd = a[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```

#### Python

```python
'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-02-24 20:58:03
'''
T = int(input())
for _ in range(T):
    thisLine = ''
    while not thisLine:
        thisLine = input()
    n = int(thisLine)
    a = []
    for __ in range(n):
        thisInput = input().split()
        a.append((int(thisInput[0]), int(thisInput[1])))
    # print(a)
    a.sort(key=lambda x: x[1])
    lastEnd = 0
    ans = 0
    for p in a:
        if p[0] >= lastEnd:
            ans += 1
            lastEnd = p[1]
    print(ans)
```

## 问题 H: 2.5 一场说走就走的旅行

[题目地址](https://buctcoder.com/problem.php?id=5807)

### 题目描述

```
有一天，孩子回来对我说：“妈妈，听说马尔代夫很不错，放假了我想去玩。”
马尔代夫？我也想去！没有人不向往一场说走就走的旅行！
“其实我想去的地方很多，呼伦贝尔大草原、玉龙雪山、布达拉宫、艾菲尔铁塔……”小孩子还说着他感兴趣的地方。
于是我们拿出地图，标出想去的地点，然后计算最短路线，估算大约所需的时间，有了这张秘制地图，一场说走就走的旅行不是梦！
“哇，感觉我们像凡尔纳的《环游地球八十天》，好激动！可是老妈你也太 out 了，学计算机的最短路线你用手算？”
暴汗……，“小子你别牛，你知道怎么算？”
“呃，好像是叫什么迪科斯彻的人会算。”
哈哈，关键时刻还要老妈上场了！
```

### 输入

```
样例组数：
t ( 0 < t <= 10 )
城市的个数：
n ( 0 < n < 100 )
城市之间的路线的个数：
m ( 0 < m < 10000 )
请输入城市之间的路线以及距离：
( 0 < ui, vi, di <= 100 )
u1 v1 d1
u2 v2 d2
...
ui vi di
请输入小明所在的位置：
l ( 0 < l < 100 )
```

### 输出

```
小明到各个城市的最短距离;
l1 l2 ... ln (若某城市无法达到则输出impossible）
```

### 输入样例

```
1
5 11 
1 5 12 
5 1 8 
1 2 16 
2 1 29 
5 2 32 
2 4 13 
4 2 27 
1 3 15 
3 1 21 
3 4 7 
4 3 19 
5
```

### 输出样例

```
8 24 23 30 0
```

### 解题思路

这道题是典型的单源起点最短路径的Dijstra算法。

这里不得不提一提我的班主任[彭老师](https://github.com/TeacherPeng)，他的[数据结构PPT](https://github.com/TeacherPeng/Datastruct)做得特别好。其中图论PPT地址为：[https://github.com/TeacherPeng/Datastruct/blob/master/教案/第07章 图.pptx](https://github.com/TeacherPeng/Datastruct/blob/master/%E6%95%99%E6%A1%88/%E7%AC%AC07%E7%AB%A0%20%E5%9B%BE.pptx)，此算法在75页。（[05064f61c0b16a8764e7d63ae2bfef0b2dd04798版本](https://github.com/TeacherPeng/Datastruct/commit/05064f61c0b16a8764e7d63ae2bfef0b2dd04798)）

**注意**，这道题是单向边，AC代码中是按单向边处理的。

Dijstra单源起点最短路径算法的思路是，从起点开始，遍历所有的起点能到达的点中，路径最短的一条。

接着将“路径最短的一条路径”所到达的点标记为“已算出”，再更新从这个点出发的所有的路径所能到达的顶点中，距离起点的最近距离（原始距离 或 起点到刚刚算出的点的距离+刚刚点的距离到这个点的距离）。

直到 起点到所有点的最短距离都计算出来为止。

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
typedef pair<int, int> pii;
#define INF 1e9

int shortest[111];
vector<pii> graph[111];
bool visited[111];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        // init
        for (int i = 1; i <= n; i++) {
            shortest[i] = INF;
            visited[i] = false;
            graph[i].clear();
        }
        // cin
        for (int i = 0; i < m; i++) {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            graph[u].push_back({v, d});
        }
        int start;
        cin >> start;
        // begin
        shortest[start] = 0;
        for (int i = 0; i < n; i++) {  // 第一次求出start到start的最短距离
            int thisMinDistance = INF;
            int shortestPoint = -1;
            for (int j = 1; j <= n; j++) {
                if (!visited[j] && shortest[j] < thisMinDistance) {
                    thisMinDistance = shortest[j];
                    shortestPoint = j;
                }
            }
            if (shortestPoint == -1) {  // 节点可达
                break;
            }
            visited[shortestPoint] = true;
            for (auto[toPoint, distance] : graph[shortestPoint]) {
                shortest[toPoint] = min(shortest[toPoint], shortest[shortestPoint] + distance);
            }
        }
        // cout
        for (int i = 1; i <= n; i++) {
            if (shortest[i] == INF) {
                printf("impossible ");
            }
            else {
                printf("%d ", shortest[i]);
            }
        }
    }
    return 0;
}
```


# TODO: 修改下方链接、Readme链接
> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/02/20/LeetCode%202347.%E6%9C%80%E5%A5%BD%E7%9A%84%E6%89%91%E5%85%8B%E6%89%8B%E7%89%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129117439](https://letmefly.blog.csdn.net/article/details/129117439)
