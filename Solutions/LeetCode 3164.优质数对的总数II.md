---
title: 3164.优质数对的总数 II
date: 2024-10-11 23:09:55
tags: [题解, LeetCode, 中等, 数组, 哈希表, 因数, 质数]
categories: [题解, LeetCode]
---

# 【LetMeFly】3164.优质数对的总数 II：哈希表+因式分解

力扣题目链接：[https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/](https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/)

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>，长度分别为 <code>n</code> 和 <code>m</code>。同时给你一个<strong>正整数</strong> <code>k</code>。</p>

<p>如果 <code>nums1[i]</code> 可以被 <code>nums2[j] * k</code> 整除，则称数对 <code>(i, j)</code> 为 <strong>优质数对</strong>（<code>0 &lt;= i &lt;= n - 1</code>, <code>0 &lt;= j &lt;= m - 1</code>）。</p>

<p>返回<strong> 优质数对 </strong>的总数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,3,4], nums2 = [1,3,4], k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>5个优质数对分别是 <code>(0, 0)</code>, <code>(1, 0)</code>, <code>(1, 1)</code>, <code>(2, 0)</code>, 和 <code>(2, 2)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums1 = [1,2,4,12], nums2 = [2,4], k = 3</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>2个优质数对分别是 <code>(3, 0)</code> 和 <code>(3, 1)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>


    
## 解题方法：哈希表+因式分解

遍历$nums1$数组，对于其中的元素$a$，求出$\lfloor\frac{a}{k}\rfloor$的所有因数并存入哈希表中。

遍历$nums2$数组，累加其中元素在哈希表中出现的次数即为答案。

**如何求一个数$t$的所有因数？**

> 用$i$从$1$到$\sqrt{t}$枚举，若$t$能整除$i$，则说明$i$和$\frac{\sqrt t}{i}$都是$t$的因数。
>
> （这个过程有点类似“求一个数是否为质数”。）

+ 时间复杂度$O(n\sqrt{\frac Mk}+m)$，其中$M=\max(nums1)$
+ 空间复杂度$O(\sqrt{\frac Mk})$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ll ans = 0;
        unordered_map<int, int> ma;
        for (int t : nums1) {
            if (t % k) {
                continue;
            }
            t /= k;
            int sqrt_ = sqrt(t);
            for (int i = 1; i <= sqrt_; i++) {
                if (t % i == 0) {
                    ma[i]++;
                    ma[t / i]++;
                }
            }
            if (sqrt_ * sqrt_ == t) {
                ma[sqrt_]--;
            }
        }
        for (int t : nums2) {
            ans += ma[t];
        }
        return ans;
    }
};
```

#### Go

```go
package main
import "math"

func numberOfPairs(nums1 []int, nums2 []int, k int) int64 {
    ma := map[int]int{}
    for _, t := range nums1 {
        if t % k != 0 {
            continue
        }
        t /= k
        sqrt_ := int(math.Sqrt(float64(t)));
        for i := 1; i <= sqrt_; i++ {
            if t % i == 0 {
                ma[i]++
                ma[t / i]++
            }
        }
        if sqrt_ * sqrt_ == t {
            ma[sqrt_]--
        }
    }
    ans := int64(0)
    for _, t := range nums2 {
        ans += int64(ma[t])
    }
    return ans
}
```

#### Java

```java
import java.util.Map;
import java.util.HashMap;

class Solution {
    public long numberOfPairs(int[] nums1, int[] nums2, int k) {
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : nums1) {
            if (t % k != 0) {
                continue;
            }
            t /= k;
            int sqrt_ = (int)Math.sqrt(t);
            for (int i = 1; i <= sqrt_; i++) {
                if (t % i == 0) {
                    ma.merge(i, 1, Integer::sum);
                    ma.merge(t / i, 1, Integer::sum);
                }
            }
            if (sqrt_ * sqrt_ == t) {
                ma.merge(sqrt_, -1, Integer::sum);
            }
        }
        long ans = 0;
        for (int t : nums2) {
            ans += (long)ma.getOrDefault(t, 0);
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List
from collections import defaultdict
from math import sqrt

class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        ma = defaultdict(int)
        for t in nums1:
            if t % k:
                continue
            t //= k
            sqrt_ = int(sqrt(t))
            for i in range(1, sqrt_ + 1):
                if t % i == 0:
                    ma[i] += 1
                    ma[t // i] += 1
            if sqrt_ * sqrt_ == t:
                ma[sqrt_] -= 1
        ans = 0
        for t in nums2:
            ans += ma[t]
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/11/LeetCode%203164.%E4%BC%98%E8%B4%A8%E6%95%B0%E5%AF%B9%E7%9A%84%E6%80%BB%E6%95%B0II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142865441](https://letmefly.blog.csdn.net/article/details/142865441)
