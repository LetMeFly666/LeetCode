---
title: BUCTOJ - 2023上半年ACM&蓝桥杯每周训练题-1
date: 2023-02-21 21:23:52
tags: [题解, BUCTOJ, 中等, 数组, 递归, 动态规划, 循环, 模拟, 素数, 质数, 贪心, 排序, 图论, 图, 迪杰斯特拉, Dijstra, 树, 哈夫曼树, 最小生成树, 归并排序]
---

# BUCTOJ - 2023上半年ACM&蓝桥杯每周训练题-1-A~K题C++Python双语版

# 前言

这篇题解写包含《2023上半年ACM&蓝桥杯每周训练题-1》的A~K题的解析以及C++和Python双版本代码

蒟蒻的我为了《问题 H: 2.5 一场说走就走的旅行》还心血来潮地做了个无人问津的视频，也耽误了不少时间，导致题解现在才完成至这个模样。

PDF不能播放视频，且一段代码可能会分页显示，因此还是比较推荐在网页端看题解的。地址：[https://blog.tisfy.eu.org/2023/02/21/BUCT-BUCT2023LanQiaoWeekly1](https://blog.tisfy.eu.org/2023/02/21/BUCT-BUCT2023LanQiaoWeekly1/)

若想查找某一知识点，可以直接Ctrl + F。

## 问题 A: 1.2 神奇兔子数列

[题目地址](https://buctcoder.com/problem.php?id=5803)

知识点：数组，递归，动态规划

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

知识点：循环，模拟

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

知识点：模拟

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

知识点：模拟、素数/质数

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

知识点：贪心

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

知识点：贪心

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

知识点：排序、贪心

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

知识点：图论/图，Dijstra算法/迪杰斯特拉算法

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

#### Python

```python
T = int(input())
for __CASE in range(T):
    n, m = map(int, input().split())
    # init
    visited = [False for _ in range(n + 1)]
    graph = [[] for _ in range(n + 1)]
    shortestDistance = [1e9 for _ in range(n + 1)]
    # cin
    for _ in range(m):
        u, v, d = map(int, input().split())
        graph[u].append((v, d))
    start = int(input())
    # begin
    shortestDistance[start] = 0
    for _ in range(n):
        thisMinDistance = 1e9
        shortestPoint = -1
        for j in range(1, n + 1):
            if not visited[j] and shortestDistance[j] < thisMinDistance:
                thisMinDistance = shortestDistance[j]
                shortestPoint = j
        if shortestPoint == -1:
            break
        visited[shortestPoint] = True
        for toPoint, thisDistance in graph[shortestPoint]:
            shortestDistance[toPoint] = min(shortestDistance[toPoint], shortestDistance[shortestPoint] + thisDistance)
    # cout
    for i in range(1, n + 1):
        if shortestDistance[i] == 1e9:
            print("impossible", end=' ')
        else:
            print(shortestDistance[i], end=' ')
    print()
```

<font size="15">我做了个讲解Dijstra算法的视频，快去看看吧！<a href="https://www.bilibili.com/video/BV1Y84y1N7Lm/">https://www.bilibili.com/video/BV1Y84y1N7Lm</a></font>

<iframe src="//player.bilibili.com/player.html?aid=610289111&bvid=BV1Y84y1N7Lm&cid=1034907457&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true" height="600px" width="100%"> </iframe>

<!-- [video(video-pJFA3AY4-1677908081287)(type-bilibili)(url-https://player.bilibili.com/player.html?aid=610289111)(image-https://img-blog.csdnimg.cn/img_convert/a9c1ee0fc2e5e42e295a5aa696c6b3d8.jpeg)(title-单源最短路的Dijstra算法)] -->

## 问题 I: 2.6 神秘电报密码

[题目地址](https://buctcoder.com/problem.php?id=5808)

知识点：树、哈夫曼树

### 题目描述

```
看过谍战电影《风声》的观众都会对影片中神奇的消息传递惊叹不已！吴志国大队长在受了残忍的“针刑”之后躺在手术台上唱空城计，变了音调，把消息传给了护士，顾晓梦在 衣服上缝补了长短不一的针脚……那么，片中无处不在的摩尔斯码到底是什么？它又有着怎
样的神秘力量呢？
摩尔斯电码（Morse code）由点 dot（. ）、划 dash（-）两种符号组成。它的基本原理是：
把英文字母表中的字母、标点符号和空格按照出现的频率排序，然后用点和划的组合来代表这些字母、标点符号和空格，使频率最高的符号具有最短的点划组合。
```

### 输入

```
输入样例组数：
t ( 0 < t < 10 )
输入节点数目：
n ( 0 < n < 30 )
输入节点的名称和值：
( x 为字母， 0 <= v < 1 )
x1 v1
x2 v2

...
xi vi
```

### 输出

```
输出每一个节点的哈夫曼编码：( 注：不同节点间用空格隔开，每个节点内冒号后用空格隔开）
x: y
```

### 输入样例

```
1
6 
a 0.05 
b 0.32 
c 0.18 
d 0.07 
e 0.25 
f 0.13
```

### 输出样例

```
a: 1000 b: 11 c: 00 d: 1001 e: 01 f: 101
```

### 解题思路

哈夫曼编码的核心思想是“权重越小的距离根越远”

构建哈夫曼树时，在节点数量大于1时，每次选取权重最小的两个节点，合并为一个节点（权重累加）

最终剩下一个节点，哈夫曼树就构建完成了。

确定字符的编码时，从根节点开始往叶节点遍历。在遍历的过程中，若是往左子树遍历，则编码记为0，否则记为1。

### Not AC代码

#### C++

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

struct Node {
    char c;
    bool isLeaf;
    Node *leftChild, *rightChild;
    double weight;
};

struct cmp {
    bool operator() (Node* a, Node* b) {
        return a->weight > b->weight;  // 权重小的在前
    }
};

void output(Node* root, string nowString, unordered_map<char, string>& output2where) {
    if (root->isLeaf) {
        output2where[root->c] = nowString;
        return;
    }
    // not leaf
    if (root->leftChild) {
        output(root->leftChild, nowString + '0', output2where);
    }
    if (root->rightChild) {
        output(root->rightChild, nowString + '1', output2where);
    }
}

void destroyTree(Node* root) {
    if (root->isLeaf) {
        delete root;
        return;
    }
    if (root->leftChild) {
        destroyTree(root->leftChild);
    }
    if (root->rightChild) {
        destroyTree(root->rightChild);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        priority_queue<Node*, vector<Node*>, cmp> pq;
        vector<char> charOrder;
        unordered_map<char, string> ans;
        // input
        for (int i = 0; i < n; i++) {
            char c;
            double weight;
            cin >> c >> weight;
            charOrder.push_back(c);
            Node* thisNode = new Node;
            thisNode->c = c;
            thisNode->isLeaf = true;
            thisNode->weight = weight;
            pq.push(thisNode);
        }
        // build
        while (pq.size() > 1) {
            Node* leftNode = pq.top();
            pq.pop();
            Node* rightNode = pq.top();
            pq.pop();
            Node* newNode = new Node;
            newNode->isLeaf = false;
            newNode->weight = leftNode->weight + rightNode->weight;
            newNode->leftChild = leftNode, newNode->rightChild = rightNode;
            pq.push(newNode);
            // printf("[%lf + %lf]\n", leftNode->weight, rightNode->weight);
        }
        Node* root;
        if (pq.top()->isLeaf) {
            root = new Node;
            root->leftChild = pq.top();
            root->rightChild = nullptr;
            root->isLeaf = false;
            root->weight = pq.top()->weight;
        }
        else {
            root = pq.top();
        }
        // output
        output(root, "", ans);
        for (char c : charOrder) {
            cout << c << ": " << ans[c] << ' ';
        }
        puts("");
        // end
        destroyTree(root);
    }
    return 0;
}

/*
1
6 
a 0.05 
b 0.32 
c 0.18 
d 0.07 
e 0.25 
f 0.13

a: 1000 b: 11 c: 00 d: 1001 e: 01 f: 101
*/

/*
6
19
b 0.28
c 0.57
d 0.05
e 0.02
f 0.04
g 0.02
h 0.01
i 0.01
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
p 0.00
q 0.00
r 0.00
s 0.00
t 0.00
16
b 0.33
c 0.07
d 0.44
e 0.14
f 0.02
g 0.00
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
p 0.00
q 0.00
14
b 0.39
c 0.55
d 0.02
e 0.04
f 0.00
g 0.00
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
14
b 0.10
c 0.69
d 0.10
e 0.11
f 0.00
g 0.00
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00
n 0.00
o 0.00
7
b 0.85
c 0.08
d 0.03
e 0.01
f 0.03
g 0.00
h 0.00
12
b 0.15
c 0.06
d 0.60
e 0.05
f 0.13
g 0.01
h 0.00
i 0.00
j 0.00
k 0.00
l 0.00
m 0.00

b: 01 c: 1 d: 0011 e: 00100 f: 0001 g: 00101 h: 000011 i: 00000 j: 0000101010 k: 0000101011 l: 0000101100 m: 0000101101 n: 0000101110 o: 0000101111 p: 000010000 q: 000010001 r: 000010010 s: 000010011 t: 000010100
b: 11 c: 1001 d: 0 e: 101 f: 10001 g: 100001010 h: 100001011 i: 100001100 j: 100001101 k: 100001110 l: 100001111 m: 10000000 n: 10000001 o: 10000010 p: 10000011 q: 10000100
b: 01 c: 1 d: 0001 e: 001 f: 00001100 g: 00001101 h: 00001110 i: 00001111 j: 0000000 k: 0000001 l: 0000010 m: 0000011 n: 0000100 o: 0000101
b: 0111 c: 1 d: 010 e: 00 f: 01101100 g: 01101101 h: 01101110 i: 01101111 j: 0110000 k: 0110001 l: 0110010 m: 0110011 n: 0110100 o: 0110101
b: 1 c: 01 d: 0011 e: 00101 f: 000 g: 001000 h: 001001
b: 00 c: 0100 d: 1 e: 01011 f: 011 g: 010101 h: 010100100 i: 010100101 j: 010100110 k: 010100111 l: 01010000 m: 01010001
*/
```

上述代码我不认为它是错误的，但是它不能通过本题。

因为题目给定的数据中，有很多权重相同的节点。题目中未规定这些节点的编码顺序。因此答案不唯一，但本题无特判。

我的上述代码使用的是“C++的优先队列”，本质上是堆。这样在获取“weight最低的两个节点”时效率较高。而题目的作者应该是遍历所有节点来获取的。因此答案不同。

#### Python

```python
class Node:
    c = ''
    isLeaf = False
    leftChild, rightChild = '', ''
    weight = 0

ans = dict()

def output(root: Node, nowString: str):
    if root.isLeaf:
        ans[root.c] = nowString
        return
    if root.leftChild:
        output(root.leftChild, nowString + '0')
    if root.rightChild:
        output(root.rightChild, nowString + '1')

T = int(input())
for _CASE in range(T):
    n = int(input())
    charOrder = []
    ans.clear()
    Nodes = []
    # input
    for _ in range(n):
        c, weight = input().split()
        weight = float(weight)
        charOrder.append(c)
        thisNode = Node()
        thisNode.c = c
        thisNode.weight = weight
        thisNode.isLeaf = True
        Nodes.append(thisNode)
    # build
    while len(Nodes) > 1:
        Nodes.sort(key=lambda x : x.weight)
        leftNode, rightNode = Nodes[0], Nodes[1]
        Nodes = Nodes[2:]
        newNode = Node()
        newNode.isLeaf = False
        newNode.weight = leftNode.weight + rightNode.weight
        newNode.leftChild = leftNode
        newNode.rightChild = rightNode
        Nodes.append(newNode)
    root = ''
    if Nodes[0].isLeaf:
        root = Node()
        root.isLeaf = False
        root.leftChild = Nodes[0]
        root.rightChild = ''
        root.weight = Nodes[0].weight
    else:
        root = Nodes[0]
    # output
    output(root, '')
    for c in charOrder:
        print(f"{c}: {ans[c]} ", end='')
    print()
```

在Python版本的代码中，我没有使用优先队列，而是采用了排序的方式，恰好和答案编码相同。

以下是我对本题如何Special judge的一点思路：

首先判断用户答案的合法性：

1. 不同节点路径不同
2. 一个节点的路径不会为另一个节点的子路径

接着判断用户答案的“压缩程度”：

$\sum len(code_i)\times freq(char_i)$

简言之就是 字符编码的长度×字符出现频率 之和。

1. 如果“压缩程度”和标准答案相同，则视为用户的答案是正确的
2. 如果“压缩程度”大于标准答案，则说明用户的答案不是最优解
3. 如果“压缩程度”小于标准答案，则说明标准答案错误，标准答案不是最优解

## 问题 J: 2.7 沟通无限校园网

[题目地址](https://buctcoder.com/problem.php?id=5809)

知识点：图论/图、最小生成树

### 题目描述

校园网是为学校师生提供资源共享、信息交流和协同工作的计算机网络。校园网是一个宽带、具有交互功能和专业性很强的局域网络。如果一所学校包括多个学院及部门，也可以形成多个局域网络，并通过有线或无线方式连接起来。

原来的网络系统只局限于以学院、图书馆为单位的局域网，不能形成集中管理以及各种资源的共享，个别学院还远离大学本部，这些情况严重地阻碍了整个学校的网络化需求。现在需要设计网络电缆布线，将各个单位的 局域网络连通起来，如何设计能够使费用最少呢？

### 输入

```
输入样例组数：
t ( 0 < t < 10 )
输入结点数和边数：
n m ( 0 < n < 100 , 0 < m < 10000 )
输入结点数u，v和边值 w： ( 0 < w < 100 )
u1 v1 w1
u2 v2 w2
...
ui vi wi
```

### 输出

最小的花费 ans

### 输入样例

```
1
7 12 
1 2 23 
1 6 28 
1 7 36 
2 3 20 
2 7 1 
3 4 15 
3 7 4 
4 5 3
4 7 9 
5 6 17 
5 7 16 
6 7 25 
1
```

### 输出样例

```
57
```

### 解题思路

**写在前面：** 这道题没有说：“当给定图为非连通图时，输出0”。。。。。。

**还有：** 样例最后一行多出来的那个1是什么鬼😂

这道题是典型的最小生成树问题。

我C++代码所采用的方案是：从某个点开始，将所有能走的路“入队”。接着每次从队列中取出权重最小的那一条，如果这条边的终点还未被接通，就使用这条边，并将终点能到达的所有边入队。

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

struct Edge {
    int toNode;
    int weight;

    Edge(int toNode, int weight) : toNode(toNode), weight(weight) {}

    friend bool operator < (const Edge& a, const Edge& b) {
        return a.weight > b.weight;  // 权重小的在前
    }
};

int main() {
    // freopen("C:/Users/LetMe/Desktop/test1.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<bool> visited(n + 1, false);
        vector<vector<Edge>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        visited[1] = true;
        priority_queue<Edge> pq;
        for (Edge& thisEdge : graph[1]) {
            pq.push(thisEdge);
        }
        int ans = 0;
        int cntEdge = 0;
        while (cntEdge < n - 1) {
            if (!pq.size()) {
                break;
            }
            Edge thisEdge = pq.top();
            pq.pop();
            // printf("pq.size() = %lld\n", pq.size());  //*********
            if (!visited[thisEdge.toNode]) {
                visited[thisEdge.toNode] = true;
                ans += thisEdge.weight;
                cntEdge++;
                for (Edge& thatEdge : graph[thisEdge.toNode]) {
                    pq.push(thatEdge);
                }
            }
        }
        // printf("n = %d, cntEdge = %d, ans = ",n, cntEdge);  //*********
        if (cntEdge != n - 1) {
            puts("0");
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}
```

#### Python

```python
from queue import PriorityQueue

class Edge:
    toNode = weight = 0

    def __init__(self, toNode, weight) -> None:
        self.toNode = toNode
        self.weight = weight
    
    def __lt__(self, other: "Edge") -> bool:
        return self.weight < other.weight

T = int(input())
for _CASE in range(T):
    n, m = map(int, input().split())
    visited = [False for _ in range(n + 1)]
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append(Edge(v, w))
        graph[v].append(Edge(u, w))
    visited[1] = True
    pq = PriorityQueue()
    for thisNode in graph[1]:
        pq.put(thisNode)
    ans = 0
    cntEdge = 0
    while cntEdge < n - 1:
        if pq.empty():
            break
        thisEdge = pq.get()
        if not visited[thisEdge.toNode]:
            visited[thisEdge.toNode] = True
            ans += thisEdge.weight
            cntEdge += 1
            for thatEdge in graph[thisEdge.toNode]:
                pq.put(thatEdge)
    if cntEdge is not n - 1:
        print("0")
    else:
        print(ans)
```

## 问题 K: 3.3 合久必分，分久必合

[题目地址](https://buctcoder.com/problem.php?id=5811)

知识点：排序、归并排序

### 题目描述

```
在数列排序中，如果只有一个数，那么他本身就是有序的；如果只有两个数，那么一次比较就可以完成排序。也就是说，数越少，排序越容易。那么，如果有一个有大量数据组成的数列，我们很难快速完成排序，该怎么办呢？可以考虑将其分解为很小的数列，直到只剩下一个数时，本身已有序，再把这些有序的数列合并在一起，执行一个和分解相反的过程，从而完成整个数列的排序。
```

### 输入

```
请输入样例组数；
t ( 0 < t < 100 )
请输入数列中元素的个数：
n ( 0 < n < 10000 )
请依次输入数列中的元素：
x1 x2 ... xn ( 0 < x < 10000 )
```

### 输出

```
合并排序的结果
x1 x2 ... xn
```

### 输入样例

```
1
8
42 15 20 6 8 38 50 12
```

### 输出样例

```
6 8 12 15 20 38 42 50
```

### 解题思路

题目作者大概是想让我们使用“归并排序”吧！

遇到这种题当然是要先愉快地AC了再说。（先直接一个内置的sort）


### AC代码

#### C++

**内置sort版：**

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
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        puts("");
    }
    return 0;
}
```

**真正的归并排序版：**

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;

int a[10010];
int temp[10010];

void mergeSort(int l, int r) {
    if (l + 1 == r) {
        return;
    }
    int m = (l + r) >> 1;
    mergeSort(l, m);
    mergeSort(m, r);
    int ll = l, lr = m;  // loc l, loc r
    int lt = l;  // loc temp
    while (ll < m && lr < r) {
        if (a[ll] < a[lr]) {
            temp[lt++] = a[ll++];
        }
        else {
            temp[lt++] = a[lr++];
        }
    }
    while (ll < m) {
        temp[lt++] = a[ll++];
    }
    while (lr < r) {
        temp[lt++] = a[lr++];
    }
    for (int i = l; i < r; i++) {
        a[i] = temp[i];
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        mergeSort(0, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        puts("");
    }    
    return 0;
}

/*
1
8
42 15 20 6 8 38 50 12

*/
```

#### Python

**内置sort版：**

```python
T = int(input())
for _CASE in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    for i in a:
        print(i, end=' ')
    print()
```

**真正的归并排序版：**

```python
a = []
temp = [0 for _ in range(10010)]

def mergeSort(l: int, r: int) -> None:
    if l + 1 == r:
        return
    m = (l + r) >> 1
    mergeSort(l, m)
    mergeSort(m, r)
    ll, lr = l, m
    lt = l
    while ll < m and lr < r:
        if a[ll] < a[lr]:
            temp[lt] = a[ll]
            lt += 1
            ll += 1
        else:
            temp[lt] = a[lr]
            lt += 1
            lr += 1
    while ll < m:
        temp[lt] = a[ll]
        lt += 1
        ll += 1
    while lr < r:
        temp[lt] = a[lr]
        lt += 1
        lr += 1
    for i in range(l, r):
        a[i] = temp[i]


T = int(input())
for _CASE in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    mergeSort(0, n)
    # for i in a:
    #     print(i, end=' ')
    # print()
    print(*a)
```

对于test1.in需要执行约4s的时间，在BUCTOJ上可能会T

# The End

题解是从2月21号开始写的，但这都结束一周了，就先这样吧。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/02/21/BUCT-BUCT2023LanQiaoWeekly1/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129327761](https://letmefly.blog.csdn.net/article/details/129327761)
