---
title: 2999.统计强大整数的数目：上下界数位DP
date: 2025-04-13 14:04:15
tags: [题解, LeetCode, 困难, 数学, 字符串, 动态规划, DP, 搜索, 深度优先搜索, DFS, 数位DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】2999.统计强大整数的数目：上下界数位DP

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-powerful-integers/](https://leetcode.cn/problems/count-the-number-of-powerful-integers/)

<p>给你三个整数&nbsp;<code>start</code>&nbsp;，<code>finish</code>&nbsp;和&nbsp;<code>limit</code>&nbsp;。同时给你一个下标从&nbsp;<strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;，表示一个 <strong>正</strong>&nbsp;整数。</p>

<p>如果一个 <strong>正</strong>&nbsp;整数&nbsp;<code>x</code> 末尾部分是&nbsp;<code>s</code>&nbsp;（换句话说，<code>s</code>&nbsp;是 <code>x</code>&nbsp;的 <strong>后缀</strong>），且 <code>x</code>&nbsp;中的每个数位至多是 <code>limit</code>&nbsp;，那么我们称 <code>x</code>&nbsp;是 <strong>强大的</strong>&nbsp;。</p>

<p>请你返回区间&nbsp;<code>[start..finish]</code>&nbsp;内强大整数的&nbsp;<strong>总数目</strong>&nbsp;。</p>

<p>如果一个字符串 <code>x</code>&nbsp;是 <code>y</code>&nbsp;中某个下标开始（<strong>包括</strong>&nbsp;<code>0</code>&nbsp;），到下标为&nbsp;<code>y.length - 1</code>&nbsp;结束的子字符串，那么我们称&nbsp;<code>x</code>&nbsp;是&nbsp;<code>y</code>&nbsp;的一个后缀。比方说，<code>25</code>&nbsp;是&nbsp;<code>5125</code>&nbsp;的一个后缀，但不是&nbsp;<code>512</code>&nbsp;的后缀。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>start = 1, finish = 6000, limit = 4, s = "124"
<b>输出：</b>5
<b>解释：</b>区间 [1..6000] 内的强大数字为 124 ，1124 ，2124 ，3124 和 4124 。这些整数的各个数位都 &lt;= 4 且 "124" 是它们的后缀。注意 5124 不是强大整数，因为第一个数位 5 大于 4 。
这个区间内总共只有这 5 个强大整数。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>start = 15, finish = 215, limit = 6, s = "10"
<b>输出：</b>2
<b>解释：</b>区间 [15..215] 内的强大整数为 110 和 210 。这些整数的各个数位都 &lt;= 6 且 "10" 是它们的后缀。
这个区间总共只有这 2 个强大整数。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>start = 1000, finish = 2000, limit = 4, s = "3000"
<b>输出：</b>0
<b>解释：</b>区间 [1000..2000] 内的整数都小于 3000 ，所以 "3000" 不可能是这个区间内任何整数的后缀。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= start &lt;= finish &lt;= 10<sup>15</sup></code></li>
	<li><code>1 &lt;= limit &lt;= 9</code></li>
	<li><code>1 &lt;= s.length &lt;= floor(log<sub>10</sub>(finish)) + 1</code></li>
	<li><code>s</code>&nbsp;数位中每个数字都小于等于&nbsp;<code>limit</code>&nbsp;。</li>
	<li><code>s</code>&nbsp;不包含任何前导 0 。</li>
</ul>


## 解题方法：上下界数位DP

我们可以从前往后一位一位地构造。在构造的过程中，要保证构造出来的数在`start`和`finish`之间（先不考虑`limit`和后缀`s`）。

> 例如`start = 123`，`finish = 456`的话：
> 
> + 假如我们构造的整数第一位为`1`，那么第二位最小为`2`（可以为`2`、`3`、`4`、`...`），但不能为`0`和`1`。
> + 假如我们构造的整数第一位为`2`，那么第二位可以取`0 - 9`的任意数。
> + 假设我们构造的整数第一位为`3`，那么第二位可以取`0 - 9`的任意数。
> + 假设我们构造的整数第一位为`4`，那么第二位最大为`5`（可以为`...`、`3`、`4`、`5`），但不能为`6 - 9`。
>
> 也就是说，我们可以使用一个函数`dfs(i, limitLow, limitHigh)`来表示：(当前应该构造第`i`位、这一位的最小值是否需要限制为`start[i]`、这一位的最大值是否需要限制为`finish[i]`)。
>
> + 在构造下一位时，如果`limitLow`为`true`且`构造的这一位`为`start[i]`，则构造下一位时`limitLow`仍需为`true`。
> + 在构造下一位时，如果`limitHigh`为`true`且`构造的这一位`为`finish[i]`，则构造下一位时`limitHigh`仍需为`true`。

然后就是考虑一下题目的额外两个限制`limit`和`s`。

> 构造过程中，任何一个元素不能超过`limit`；
>
> 构造过程中，若在构造最后的`len(s)`个元素，则当前元素最多有一种选择`s[对应下标]`。

最后就是需要记忆化一下。

> 记忆化的时候，记录`(i, limitLow, limitHigh)`三个变量可能有些麻烦，我们也可以只记录`i`这一个变量，并且在`limitLow`和`limitHigh`都为`false`时再使用记忆化。（因为有`true`的话不会被再次调用）

+ 时间复杂度$O(\log finish\times D)$，其中$D=10$
+ 空间复杂度$O(\log finish)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 11:03:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 11:56:04
 */
typedef long long ll;

class Solution {
private:
    int limit, n, nonFixed;
    string suffix, start, finish;
    unordered_map<int, ll> cache;

    ll dfs(int i, bool limitLow, bool limitHigh) {
        if (i == n) {
            return 1;
        }
        if (!limitLow && !limitHigh && cache.count(i)) {
            return cache[i];
        }
        int low = limitLow ? start[i] - '0' : 0;  // 这一位的有效范围时[log, high]
        int high = limitHigh ? finish[i] - '0' : 9;
        ll ans = 0;
        if (i < nonFixed) {
            for (int d = low; d <= min(high, limit); d++) {  // 构造这一位
                ans += dfs(i + 1, limitLow && d == low, limitHigh && d == high);
            }
        } else {
            int x = suffix[i - nonFixed] - '0';  // 构造这一位
            if (low <= x && x <= high) {  // 题目限制一定小于limit
                ans = dfs(i + 1, limitLow && x == low, limitHigh && x == high);
            }
        }
        if (!limitLow && !limitHigh) {
            cache[i] = ans;
        }
        return ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        this->limit = limit;
        suffix = move(s);
        this->finish = to_string(finish);
        n = this->finish.size();
        this->start = to_string(start);
        this->start = string(n - this->start.size(), '0') + this->start;  // 原始范围时[1, 200]的话，将其变成[001, 200]
        nonFixed = n - this->suffix.size();

        return dfs(0, true, true);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-12 22:20:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-12 22:37:40
'''
from functools import cache

class Solution:
    @cache
    def dfs(self, n: int, limitLow: bool, limitHigh: bool) -> int:
        if n == self.n:
            return 1
        low = self.start[n] if limitLow else 0
        high = self.finish[n] if limitHigh else 9
        ans = 0
        if n < self.free:  # 什么都可以
            for d in range(low, min(high, self.limit) + 1):
                ans += self.dfs(n + 1, limitLow and d == low, limitHigh and d == high)
        else:
            x = self.s[n - self.free]
            if low <= x <= high:
                ans = self.dfs(n + 1, limitLow and x == low, limitHigh and x == high)
        return ans
        
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        self.finish = list(map(int, str(finish)))
        self.n = len(self.finish)
        self.start = list(map(int, str(start).zfill(self.n)))
        self.limit = limit
        self.free = self.n - len(s)
        self.s = list(map(int, s))
        return self.dfs(0, True, True)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 13:00:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 13:37:04
 * @Description: AC,70.30%,86.73%
 */
import java.util.Arrays;

class Solution {
    private int n, nonFixed, limit;
    private String start, finish, suffix;
    private long[] cache;

    private long dfs(int i, boolean limitLow, boolean limitHigh) {
        if (i == n) {
            return 1;
        }
        if (!limitLow && !limitHigh && cache[i] != -1) {
            return cache[i];
        }
        int low = limitLow ? start.charAt(i) - '0' : 0;
        int high = limitHigh ? finish.charAt(i) - '0' : 9;
        long ans = 0;
        if (i < nonFixed) {
            for (int d = low; d <= Math.min(limit, high); d++) {
                ans += dfs(i + 1, limitLow && d == low, limitHigh && d == high);
            }
        } else {
            int x = suffix.charAt(i - nonFixed) - '0';
            if (low <= x && x <= high) {
                ans = dfs(i + 1, limitLow && x == low, limitHigh && x == high);
            }
        }
        if (!limitLow && !limitHigh) {
            cache[i] = ans;
        }
        return ans;
    }
    
    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        this.finish = String.valueOf(finish);
        n = this.finish.length();
        this.start = String.valueOf(start);
        this.start = "0".repeat(n - this.start.length()) + this.start;
        this.limit = limit;
        nonFixed = n - s.length();
        cache = new long[n];
        Arrays.fill(cache, -1);
        suffix = s;
        return dfs(0, true, true);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-13 13:38:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-13 14:00:33
 */
package main

import (
    "strconv"
    "strings"
)

func dfs2999(i int, limitLow, limitHigh bool, start, finish string, nonFixed int, cache []int64, limit int, suffix string) (ans int64) {
    if i == len(start) {
        return 1
    }
    if !limitLow && !limitHigh && cache[i] != -1 {
        return cache[i]
    }

    var low, high int
    if limitLow {
        low = int(start[i]) - int('0')
    } else {
        low = 0
    }
    if limitHigh {
        high = int(finish[i]) - int('0')
    } else {
        high = 9
    }
    if i < nonFixed {
        for d := low; d <= min(high, limit); d++ {
            ans += dfs2999(i + 1, limitLow && d == low, limitHigh && d == high, start, finish, nonFixed, cache, limit, suffix)
        }
    } else {
        d := int(suffix[i - nonFixed]) - int('0')
        if low <= d && d <= high {
            ans = dfs2999(i + 1, limitLow && d == low, limitHigh && d == high, start, finish, nonFixed, cache, limit, suffix)
        }
    }
    if !limitLow && !limitHigh {
        cache[i] = ans
    }
    return ans
}

func numberOfPowerfulInt(start int64, finish int64, limit int, s string) int64 {
    finish_str := strconv.FormatInt(finish, 10)
    cache := make([]int64, len(finish_str) + 1)
    for i := range cache {
        cache[i] = -1
    }
    start_str := strconv.FormatInt(start, 10)
    start_str = strings.Repeat("0", len(finish_str) - len(start_str)) + start_str
    nonFixed := len(finish_str) - len(s)
    return dfs2999(0, true, true, start_str, finish_str, nonFixed, cache, limit, s)
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147191672)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/12/LeetCode%202999.%E7%BB%9F%E8%AE%A1%E5%BC%BA%E5%A4%A7%E6%95%B4%E6%95%B0%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
