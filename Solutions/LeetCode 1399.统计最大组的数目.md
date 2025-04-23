---
title: 1399.统计最大组的数目：哈希表模拟（简单题简单做）
date: 2025-04-23 13:29:46
tags: [题解, LeetCode, 简单, 哈希表, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1399.统计最大组的数目：哈希表模拟（简单题简单做）

力扣题目链接：[https://leetcode.cn/problems/count-largest-group/](https://leetcode.cn/problems/count-largest-group/)

<p>给你一个整数 <code>n</code>&nbsp;。请你先求出从 <code>1</code>&nbsp;到 <code>n</code> 的每个整数 10 进制表示下的数位和（每一位上的数字相加），然后把数位和相等的数字放到同一个组中。</p>

<p>请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 13
<strong>输出：</strong>4
<strong>解释：</strong>总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
[1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>总共有 2 个大小为 1 的组 [1]，[2]。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 15
<strong>输出：</strong>6
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 24
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
</ul>


    
## 解题方法：哈希表

如何统计一个数字十进制下的每一位之和？

> 在这个数字(假设为$t$)不为0时，不断累加这个数的个位（$t\%10$），并将这个数除以$10$（向下取整）。

使用一个哈希表，键为“一个数的每一位之和”，值为这个“和”的出现次数。

统计最大的“值”，然后统计有多少个键值对的值是这个最大的值。

+ 时间复杂度$O(n\log_{10}n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-23 13:17:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-23 13:19:12
 */

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> bin;
        int maxTimes = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0, temp = i;
            while (temp) {
                cnt += temp % 10;
                temp /= 10;
            }
            maxTimes = max(maxTimes, ++bin[cnt]);
        }
        int ans = 0;
        for (auto [a, b] : bin) {
            ans += b == maxTimes;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-23 13:20:37
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-23 13:22:37
'''
from collections import defaultdict

class Solution:
    def countLargestGroup(self, n: int) -> int:
        counter = defaultdict(int)
        maxTimes = 0
        for i in range(1, n + 1):
            cnt = sum(map(int, str(i)))
            counter[cnt] += 1
            maxTimes = max(maxTimes, counter[cnt])
        return sum(b == maxTimes for a, b in counter.items())
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-23 13:23:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-23 13:24:57
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int countLargestGroup(int n) {
        Map<Integer, Integer> times = new HashMap<>();
        int maxTimes = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0, temp = i;
            while (temp > 0) {
                cnt += temp % 10;
                temp /= 10;
            }
            maxTimes = Math.max(maxTimes, times.merge(cnt, 1, Integer::sum));
        }
        int ans = 0;
        for (Map.Entry<Integer, Integer> pair : times.entrySet()) {
            if (pair.getValue() == maxTimes) {
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-23 13:26:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-23 13:28:41
 */
package main

func countLargestGroup(n int) (ans int) {
    times := map[int]int{}
    maxTimes := 0
    for i := 1; i <= n; i++ {
        cnt := 0
        for temp := i; temp > 0; temp /= 10 {
            cnt += temp % 10
        }
        times[cnt]++
        maxTimes = max(maxTimes, times[cnt])
    }
    for _, val := range times {
        if val == maxTimes {
            ans++
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147448113)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/23/LeetCode%201399.%E7%BB%9F%E8%AE%A1%E6%9C%80%E5%A4%A7%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
