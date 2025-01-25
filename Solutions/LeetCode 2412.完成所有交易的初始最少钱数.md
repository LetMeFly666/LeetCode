---
title: 2412.完成所有交易的初始最少钱数：【年度巨献】举例说明(讲明白)，由难至简(手脚不乱)，附Python一行版
date: 2025-01-25 10:14:50
tags: [题解, LeetCode, 困难, 贪心, 数组, 排序, 思维, 脑筋急转弯]
---

# 【LetMeFly】2412.完成所有交易的初始最少钱数：【年度巨献】举例说明(讲明白)，由难至简(手脚不乱)，附Python一行版

## 问题描述

力扣题目链接：[https://leetcode.cn/problems/minimum-money-required-before-transactions/](https://leetcode.cn/problems/minimum-money-required-before-transactions/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code><font face="monospace">transactions</font></code>，其中<code>transactions[i] = [cost<sub>i</sub>, cashback<sub>i</sub>]</code>&nbsp;。</p>

<p>数组描述了若干笔交易。其中每笔交易必须以 <strong>某种顺序</strong> 恰好完成一次。在任意一个时刻，你有一定数目的钱&nbsp;<code>money</code>&nbsp;，为了完成交易&nbsp;<code>i</code>&nbsp;，<code>money &gt;= cost<sub>i</sub></code>&nbsp;这个条件必须为真。执行交易后，你的钱数&nbsp;<code>money</code> 变成&nbsp;<code>money - cost<sub>i</sub> + cashback<sub>i</sub></code><sub>&nbsp;</sub>。</p>

<p>请你返回 <strong>任意一种</strong> 交易顺序下，你都能完成所有交易的最少钱数<em>&nbsp;</em><code>money</code>&nbsp;是多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>transactions = [[2,1],[5,0],[4,2]]
<b>输出：</b>10
<strong>解释：
</strong>刚开始 money = 10 ，交易可以以任意顺序进行。
可以证明如果 money &lt; 10 ，那么某些交易无法进行。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>transactions = [[3,0],[0,3]]
<b>输出：</b>3
<strong>解释：</strong>
- 如果交易执行的顺序是 [[3,0],[0,3]] ，完成所有交易需要的最少钱数是 3 。
- 如果交易执行的顺序是 [[0,3],[3,0]] ，完成所有交易需要的最少钱数是 0 。
所以，刚开始钱数为 3 ，任意顺序下交易都可以全部完成。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= transactions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>transactions[i].length == 2</code></li>
	<li><code>0 &lt;= cost<sub>i</sub>, cashback<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：贪心

> “在运气和实力面前，我选择了实力”——小T如是说。
> 
> 不论机遇多么坏，我都必将不负债。

那么，最“坏”的机遇是什么？当然是先亏钱（$cost \lt casnback$）再赚钱，主打一个完事开头难。

### 那行，我们先选赔钱的

对于两笔赔钱投资`[[6, 4], [3, 2]]`，有两种选择方案：

1. 先选`[6, 4]`，那么我们需要初始资金`max(6, 6 + 3 - 4) = 5 = max(6, (6 - 4) + (3 - 2) + 2)`
2. 先选`[3, 2]`，那么我们需要初始资金`max(3, 3 + 6 - 2) = 7 = (3 - 2) + (6 - 4) + 4`

有没有发现，不论选择方案如何，初始资金都为`max(cost, 赔钱总额 + 最后一次投资的cashback)`。

> 想要初始资金最大，那么我们就最后选“cashback”最大的那次投资。

赔钱投资的最大初始资金要求为`赔钱总额 + max(cashback_赔)`，最终剩余`max(cashback_赔)`开始进行赚钱投资。

### 到了能赚钱时候也不容易

好了，现在开始赚钱投资，钱开始越来越多了。但是，能赚钱不等于容易赚钱。**想要赚钱，你得有那个资本。**

既然接下来每一笔都会赚钱，也就是说每经过一笔交易所需的负担就会减小一些，所以我们不如上来就选最难的那个。

> 上来就选cost最大的那个，所需金额为`max(cost_赚)`。

别忘了，赔钱阶段虽然赔钱，但是最终我们还剩下了`max(cashback_赔)`。因此还需要资金`max(0, max(cashback_赔) - max(cost_赚))`。

### 解法来了

总结：两次遍历，第一次只遍历赔钱的交易，第二次遍历不赔钱的交易。

+ 对于赔钱的交易，所需初始资金`ans = 赔钱总额 + max(cashback_赔)`
+ 对于不赔钱交易，还需初始资金加上`max(0, max(cashback_赔) - max(cost_赚))`

下面先贴一个完整版代码，再放一个核心代码。

完整版代码：

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 08:08:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 09:53:23
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/*
先选赔的
    [[6, 4], [3, 2]]：
        先[6, 4]的话需要初始资金max(6, 6+3-4)=max(6, 5)=6=max(6, (6-4)+(3-2)+2)
        先[3, 2]的话需要初始资金max(3, 6+3-2)=max(3, 7)=7=(3-2)+(6-4)+4
    对于赔的：
        初始资金：赔钱总额+最大cashback
        结束资金：最大cashback
后选不赔的
    赚的一样：[[1, 2], [2, 3]]，先[2, 3]再[1, 2]
    赚的不同：
        [[3, 5], [7, 8]]：
            先[3, 5]的话需要初始资金7-(5-3)=5
            先[7, 8]的话需要初始资金7
    反正就是只要钱到了最大的“cost”，钱就够了。
    如果先投资“cost”比较小的话，一定会赚，本金加上赚的钱达到最大cost就行，所以初始值所需较小。
*/
typedef long long ll;

class Solution {
public:
    ll minimumMoney(vector<vector<int>>& transactions) {
        ll ans = 0;
        int M_pei = 0;
        // 先算赔的
        for (vector<int>& transaction : transactions) {
            if (transaction[1] < transaction[0]) {
                ans += transaction[0] - transaction[1];
                M_pei = max(M_pei, transaction[1]);
            }
        }
        ans += M_pei;
        // 再算赚的，初始资金M_pei
        int M_zhuan = 0;
        for (vector<int>& transaction : transactions) {
            if (transaction[1] >= transaction[0]) {
                M_zhuan = max(M_zhuan, transaction[0]);
            }
        }
        ans += max(M_zhuan - M_pei, 0);
        return ans;
    }
};

#ifdef _WIN32
/*
[[2,1],[5,0],[4,2]]

10
*/
/*
[[36,79],[94,94],[12,54],[71,25],[34,78],[89,66],[66,25],[7,29],[5,58],[2,25],[10,83],[62,62],[11,52],[40,5],[10,79],[74,53],[33,90],[91,81],[30,84]]

270
*/

// 暴力验证一个答案是否正确，复杂度O(len(t)!)，对于10以内的数据还算可行
bool isok_baoliYanzheng(vector<vector<int>>& t, ll init) {
    sort(t.begin(), t.end());
    auto isok = [](vector<vector<int>>& t, ll init) {
        for (vector<int>& t0 : t) {
            if (init < t0[0]) {
                return false;
            }
            init += t0[1] - t0[0];
        }
        return true;
    };
    do {
        for (vector<int>& t0 : t) {
            cout << '(' << t0[0] << ", " << t0[1] << "), ";
        }
        cout << endl;
        bool isThisOk = isok(t, init);
        if (!isThisOk) {
            return false;
        }
    } while (next_permutation(t.begin(), t.end()));
    return true;
}

int main() {
    string s;
    Solution sol;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        debug(v);
        ll ans = sol.minimumMoney(v);
        dbg(ans);
        if (v.size() <= 10) {
            cout << "ifOk: ";
            fflush(stdout);
            cout << isok_baoliYanzheng(v, ans) << endl;
        }
    }
    return 0;
}
#endif
```

核心代码：

```cpp
ll ans = 0;
int M_pei = 0;
// 先算赔的
for (vector<int>& transaction : transactions) {
    if (transaction[1] < transaction[0]) {
        ans += transaction[0] - transaction[1];
        M_pei = max(M_pei, transaction[1]);
    }
}
ans += M_pei;
// 再算赚的，初始资金M_pei
int M_zhuan = 0;
for (vector<int>& transaction : transactions) {
    if (transaction[1] >= transaction[0]) {
        M_zhuan = max(M_zhuan, transaction[0]);
    }
}
ans += max(M_zhuan - M_pei, 0);
return ans;
```

## 写法上的优化

上述代码的伪代码为：

```cpp
ans = 0
M_pei = 0
for 赔钱交易 {
    ans += 赔钱总额
    M_pei = max(cashback)
}
ans += M_pei
M_zhuan = 0
for 不赔钱交易 {
    M_zhuan = max(cost)
}
if M_zhuan > M_pei {
    ans += M_zhuan - M_pei
}
```

我们不妨调换个顺序：

```cpp
ans = 0
M_pei = 0
for 赔钱交易 {
    ans += 赔钱总额
    M_pei = max(cashback)
}
M_zhuan = 0
for 不赔钱交易 {
    M_zhuan = max(cost)
}
ans += M_pei  // 将这一行调换到这里
if M_zhuan > M_pei {
    ans += M_zhuan - M_pei
}
```

那么，最后4行的：

```cpp
ans += M_pei
if M_zhuan > M_pei {
    ans += M_zhuan - M_pei
}
```

就可以简写为：

```cpp
ans += max(M_zhuan, M_pei)
```

同时，前面10行的：

```cpp
ans = 0
M_pei = 0
for 赔钱交易 {
    ans += 赔钱总额
    M_pei = max(cashback)
}
M_zhuan = 0
for 不赔钱交易 {
    M_zhuan = max(cost)
}
```

就可以缩减为一次遍历：

```cpp
ans = 0
M_pei = 0
M_zhuan = 0
for 交易 {
    if cost > cashback {  // 赔钱
        ans += 赔钱总额
        M_pei = max(cashback)
    } else {
        M_zhuan = max(cost)
    }
}
```

不难发现，如果赔钱则`cashback`更小，如果不赔钱则`cost`更小。也就是说`M_pei`和`M_zhuan`其实都是`min(cost, cashback)`的最大值。

因此上述代码还可以简写为：

```cpp
ans = 0
M = 0
for 交易 {
    ans += max(0, cost - cashback)
    M = max(M, min(cost, cashback))
}
```

**也就是说：**

最终答案为：`赔钱总额 + 最大的“min(cost, cashback)”`

## 时空复杂度分析

+ 时间复杂度$O(len(transactions))$
+ 空间复杂度$O(1)$

## AC代码（简化写法）

### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 09:58:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 09:59:57
 */
typedef long long ll;

class Solution {
public:
    ll minimumMoney(vector<vector<int>>& transactions) {
        ll ans = 0;
        int M = 0;
        for (vector<int>& t : transactions) {
            ans += max(0, t[0] - t[1]);
            M = max(M, min(t[0], t[1]));
        }
        return ans + M;
    }
};
```

### Python

```python
'''
Author: LetMeFly
Date: 2025-01-25 10:00:39
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-25 10:02:46
'''
from typing import List

class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        return sum(max(0, c - e) for c, e in transactions) + max(min(t) for t in transactions)
```

### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 10:05:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 10:06:21
 */
class Solution {
    public long minimumMoney(int[][] transactions) {
        long ans = 0;
        int M = 0;
        for (int[] t : transactions) {
            ans += Math.max(0, t[0] - t[1]);
            M = Math.max(M, Math.min(t[0], t[1]));
        }
        return ans + M;
    }
}
```

### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-25 10:07:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-25 10:12:39
 */
package main

func max_MMRBT[T int](a T, b T) T {
    if a > b {
        return a
    }
    return b
}

func min_MMRBT(a int, b int) int {
    if a < b {
        return a
    }
    return b
}

func minimumMoney(transactions [][]int) (ans int64) {
    M := 0
    for _, t := range transactions {
        ans += int64(max_MMRBT(0, t[0] - t[1]))
        M = max_MMRBT(M, min_MMRBT(t[0], t[1]))
    }
    ans += int64(M)
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/25/LeetCode%202412.%E5%AE%8C%E6%88%90%E6%89%80%E6%9C%89%E4%BA%A4%E6%98%93%E7%9A%84%E5%88%9D%E5%A7%8B%E6%9C%80%E5%B0%91%E9%92%B1%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145352577](https://letmefly.blog.csdn.net/article/details/145352577)
