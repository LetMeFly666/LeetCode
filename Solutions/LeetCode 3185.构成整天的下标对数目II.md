---
title: 3185.构成整天的下标对数目 II
date: 2024-10-23 23:02:55
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 计数]
---

# 【LetMeFly】3185.构成整天的下标对数目 II：哈希表

力扣题目链接：[https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/](https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/)

<p>给你一个整数数组 <code>hours</code>，表示以 <strong>小时 </strong>为单位的时间，返回一个整数，表示满足 <code>i &lt; j</code> 且 <code>hours[i] + hours[j]</code> 构成 <strong>整天 </strong>的下标对&nbsp;<code>i</code>, <code>j</code> 的数目。</p>

<p><strong>整天 </strong>定义为时间持续时间是 24 小时的 <strong>整数倍 </strong>。</p>

<p>例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [12,12,30,24,24]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code> 和 <code>(3, 4)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [72,48,24,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code>、<code>(0, 2)</code> 和 <code>(1, 2)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hours.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= hours[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：哈希表

不论小时数为多少，最终结果都只与小时数取模24后的结果有关。因此我们可以开辟一个大小为24的哈希表，分别记录小时数模24后的结果数量。

**方法一：** 遍历一遍得到哈希表，$0$和$0$是一对，$12$和$12$是一对，其他$i$和$24-i$是一对。遍历哈希表得到答案数量。

**方法二：** 遍历过程中，假设这个数对$24$取模后的结果为$k$，则将答案数量加上$哈希表[(24 - k) \% 24]$。

+ 时间复杂度$O(len(hours))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
0 0
1 23
2 22
...
11 13
12 12
*/
typedef long long ll;
class Solution {
public:
    ll countCompleteDayPairs(vector<int>& hours) {
        ll bin[24] = {0};
        for (int t : hours) {
            bin[t % 24]++;
        }
        ll ans = bin[0] * (bin[0] - 1) / 2 + bin[12] * (bin[12] - 1) / 2;
        for (int i = 1; i < 12; i++) {
            ans += bin[i] * bin[24 - i];
        }
        return ans;
    }
};
```

#### Go

```go
package main

func countCompleteDayPairs(hours []int) int64 {
    bin := make([]int64, 24)
    var ans int64
    for _, t := range hours {
        ans += bin[(24 - t % 24) % 24]
        bin[t % 24]++
    }
    return ans
}
```

#### Java

```java
class Solution {
    public long countCompleteDayPairs(int[] hours) {
        long[] bin = new long[24];
        for (int t : hours) {
            bin[t % 24]++;
        }
        long ans = bin[0] * (bin[0] - 1) / 2 + bin[12] * (bin[12] - 1) / 2;
        for (int i = 1; i < 12; i++) {
            ans += bin[i] * bin[24 - i];
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        bin = [0] * 24
        for t in hours:
            bin[t % 24] += 1
        ans = bin[0] * (bin[0] - 1) // 2 + bin[12] * (bin[12] - 1) // 2
        for i in range(1, 12):
            ans += bin[i] * bin[24 - i]
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/23/LeetCode%203185.%E6%9E%84%E6%88%90%E6%95%B4%E5%A4%A9%E7%9A%84%E4%B8%8B%E6%A0%87%E5%AF%B9%E6%95%B0%E7%9B%AEII/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143196224](https://letmefly.blog.csdn.net/article/details/143196224)
