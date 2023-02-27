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

TODO: 解题思路

**注意**，这道题是单向边，AC代码中是按单向边处理的。

### AC代码

#### C++

##### 我的代码

```cpp
#include <bits/stdc++.h>
using namespace std;
#define mem(a) memset(a, 0, sizeof(a))
#define dbg(x) cout << #x << " = " << x << endl
#define fi(i, l, r) for (int i = l; i < r; i++)
#define cd(a) scanf("%d", &a)
typedef long long ll;
typedef pair<int, int> pii;

int ans[111];
vector<pii> graph[111];
bool visited[111];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            ans[i] = 1e9;
            visited[i] = false;
            graph[i].clear();
        }
        while (m--) {
            int a, b, l;
            scanf("%d%d%d", &a, &b, &l);
            graph[a].push_back({b, l});
            // graph[b].push_back({a, l});
        }
        int start;
        cin >> start;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        ans[start] = 0;
        while (q.size()) {
            int loc = q.front();
            q.pop();
            for (pii& edge : graph[loc]) {
                int toLoc = edge.first;
                int distance = edge.second;
                if (!visited[toLoc]) {
                    visited[toLoc] = true;
                    q.push(toLoc);
                }
                // if (toLoc == 2 && ans[toLoc] > ans[loc] + distance) {  //**********
                //     printf("ans[%d] + %d = %d\n", loc, distance, ans[loc] + distance);
                // }
                ans[toLoc] = min(ans[toLoc], ans[loc] + distance);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (ans[i] > 1e8) {
                printf("impossible ");
            }
            else {
                printf("%d ", ans[i]);
            }
        }
        puts("");
    }
    return 0;
}
```

##### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int t;
int g[110][110];
int dis[110];
int n, m, s;
bool f[110];

void dijksta()
{
    memset(f, 0, sizeof(f));
    memset(dis, 0x3f, sizeof(dis));

    dis[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!f[j] && (t == -1 || dis[j] < dis[t]))
                t = j; //寻找还未确定最短路的点中路径最短的点
        }

        // if (f[t])continue;   //如果某个点已经被确定就直接跳过  //*********
        f[t] = 1;
        printf("t = %d\n", t);

        for (int j = 1; j <= n; j++)
        {
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        }
    }
}

void hp()
{

    cin >> n >> m;

    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        g[a][b] = min(g[a][b], x);
    }
    cin >> s;
    dijksta();
    for (int i = 1; i <= n; i++)
        if (dis[i] != 0x3f3f3f3f)
            cout << dis[i] << " ";
        else
            cout << "impossible"
                 << " ";
    puts("");
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> t;

    while (t--)
        hp();

    return 0;
}
```

**What's more**： 这道题我和答案计算出来的不一样。

对于样例：

```
1
26 343
18 7 38
8 22 93
14 23 57
5 14 99
12 5 68
16 19 40
25 20 56
15 13 50
18 4 3
22 1 51
9 12 7
23 4 70
9 20 93
23 19 20
19 9 36
11 5 2
24 19 64
13 22 53
23 16 89
22 4 15
7 5 43
6 22 77
21 15 57
7 9 62
17 8 57
22 5 31
23 5 9
18 10 31
3 14 18
12 1 25
20 2 49
21 6 16
1 26 88
9 7 91
11 4 5
8 18 58
11 2 15
1 23 7
10 8 16
6 21 74
10 18 94
13 2 60
8 17 22
8 5 32
4 21 36
13 25 13
23 18 27
13 6 59
11 6 78
16 26 29
14 18 32
5 19 32
14 13 12
3 12 55
11 16 6
6 20 27
26 6 13
21 10 11
10 4 61
26 11 7
25 18 85
14 13 80
21 11 37
26 15 71
2 25 21
7 15 75
24 12 100
24 21 86
18 20 28
3 4 71
23 1 1
17 10 10
5 19 72
21 18 81
12 3 81
3 17 48
9 12 90
19 8 51
16 22 76
16 20 84
12 21 30
16 4 8
1 10 15
9 17 93
5 19 20
15 23 29
10 14 61
13 1 95
11 13 15
12 17 36
14 7 47
15 8 94
6 19 40
9 22 60
16 13 74
5 7 73
1 11 11
1 8 88
25 15 70
3 8 75
3 4 12
17 3 32
23 11 30
17 9 33
16 12 41
24 16 8
21 1 66
23 3 85
24 2 22
3 17 6
23 11 85
19 24 82
1 18 5
7 21 63
4 2 43
6 22 96
26 23 64
13 3 40
17 24 98
20 13 61
5 12 84
17 14 52
15 1 82
11 26 33
25 1 56
18 15 81
11 1 96
24 13 3
2 17 97
25 11 87
26 16 11
17 1 96
1 25 40
8 18 89
16 1 74
2 12 4
6 18 20
4 5 79
17 15 74
15 2 1
1 5 97
20 26 76
8 1 76
5 13 45
15 19 1
5 14 33
1 2 33
21 18 73
9 21 99
25 9 20
16 4 85
6 10 84
12 25 98
17 3 97
15 20 5
4 10 98
1 7 7
5 18 79
13 20 87
4 14 6
24 16 6
12 23 29
18 8 25
15 19 29
6 17 77
1 6 100
11 10 78
23 21 30
22 26 40
25 21 65
18 3 71
19 14 82
22 10 19
2 8 62
11 4 18
13 10 45
26 25 49
24 21 77
17 20 43
1 9 83
5 16 82
12 10 52
3 9 90
17 14 82
4 16 66
6 14 50
9 14 77
1 19 18
10 14 19
12 3 43
11 10 61
3 1 45
8 22 68
23 15 87
15 26 48
3 9 17
18 9 18
24 26 42
9 13 77
18 10 84
18 20 83
18 6 48
7 9 13
18 3 51
25 14 11
12 13 23
1 7 42
13 24 89
10 5 39
1 11 78
22 20 81
6 7 22
7 3 10
22 19 77
17 19 48
20 6 97
15 26 60
12 25 14
16 13 78
6 2 3
11 25 10
9 3 15
21 11 24
5 16 28
11 3 75
5 26 92
15 19 31
1 16 85
17 23 4
12 11 82
14 2 7
15 17 52
6 14 44
7 21 41
4 26 74
15 24 8
13 10 80
22 3 82
13 14 81
21 3 83
23 3 76
17 26 45
24 11 60
12 9 79
18 20 52
7 8 20
8 13 85
24 1 37
10 26 24
17 15 88
15 7 30
16 26 77
21 23 4
24 19 16
22 19 56
6 25 96
12 19 67
17 5 8
1 17 78
16 5 17
24 16 12
7 17 84
12 14 79
10 8 4
17 9 21
4 10 95
3 9 65
24 3 83
17 11 27
22 4 63
20 5 49
14 23 54
8 19 81
7 25 31
21 6 42
8 5 85
19 21 41
20 9 97
26 18 7
20 6 26
26 17 5
2 12 91
13 19 49
11 18 13
17 10 37
24 7 93
8 19 2
12 17 78
16 1 19
17 20 40
2 10 82
13 21 83
2 12 50
11 25 14
19 17 80
2 11 72
9 14 39
5 16 48
26 20 8
14 20 50
10 26 74
19 12 9
22 6 25
10 6 25
14 13 35
23 20 52
15 5 32
8 7 39
18 20 88
19 6 44
22 16 43
1 17 35
2 16 24
6 12 88
17 21 28
6 5 27
9 1 16
26 20 85
23 12 13
6 20 50
10 17 100
16 11 51
12 11 45
26 22 68
8 10 50
9 22 85
21 1 20
23 6 47
19 20 88
22 11 99
9 4 90
17 22 73
12 20 86
9 7 43
6 7 42
2 4 96
2 19 32
24 18 36
6 9 48
22 7 42
10 24 58
23 1 76
6 13 95
23
```

由答案得到的结果为：

```
1 22 18 9 9 41 8 20 21 16 12 13 27 15 83 18 24 6 19 34 30 80 0 74 22 40
```

上述结果由AC代码同样能得到。

但是我的代码运行的结果是：

```
1 27 18 17 9 41 8 20 21 16 12 13 27 33 83 18 36 6 19 48 30 80 0 74 22 40
```

**假设答案是正确的**，那么从起点到达点11的最短距离是12（答案中的第11个数）

输入样例中存在这么一行：

```
11 2 15
```

也就是说存在一条路径，从点11出发，到达点2，距离是15。

我们经过点11走这条路到达点2，这样起点到达点2的距离就可以为：12 + 15 = 27

但是答案中第二个数是

# TODO: 修改下方链接、Readme链接
> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/02/20/LeetCode%202347.%E6%9C%80%E5%A5%BD%E7%9A%84%E6%89%91%E5%85%8B%E6%89%8B%E7%89%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129117439](https://letmefly.blog.csdn.net/article/details/129117439)
