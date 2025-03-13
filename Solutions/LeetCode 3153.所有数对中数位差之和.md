---
title: 3153.所有数对中数位差之和
date: 2024-08-30 23:50:44
tags: [题解, LeetCode, 中等, 数组, 哈希表, 数学, 计数, 排列组合]
categories: [题解, LeetCode]
---

# 【LetMeFly】3153.所有数对中数位差之和：计数

力扣题目链接：[https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs/](https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs/)

<p>车尔尼有一个数组&nbsp;<code>nums</code>&nbsp;，它只包含 <strong>正</strong>&nbsp;整数，所有正整数的数位长度都 <strong>相同</strong>&nbsp;。</p>

<p>两个整数的 <strong>数位不同</strong>&nbsp;指的是两个整数 <b>相同</b>&nbsp;位置上不同数字的数目。</p>

<p>请车尔尼返回 <code>nums</code>&nbsp;中 <strong>所有</strong>&nbsp;整数对里，<strong>数位不同之和。</strong></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [13,23,12]</span></p>

<p><b>输出：</b>4</p>

<p><strong>解释：</strong><br />
计算过程如下：<br />
-&nbsp;<strong>1</strong>3 和&nbsp;<strong>2</strong>3 的数位不同为&nbsp;1 。<br />
- 1<strong>3</strong> 和 1<strong>2</strong>&nbsp;的数位不同为&nbsp;1 。<br />
-&nbsp;<strong>23</strong> 和&nbsp;<strong>12</strong>&nbsp;的数位不同为&nbsp;2 。<br />
所以所有整数数对的数位不同之和为&nbsp;<code>1 + 1 + 2 = 4</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [10,10,10,10]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong><br />
数组中所有整数都相同，所以所有整数数对的数位不同之和为 0 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt; 10<sup>9</sup></code></li>
	<li><code>nums</code>&nbsp;中的整数都有相同的数位长度。</li>
</ul>


    
## 解题方法：计数

首先需要明确每一位互不干扰，因此每一位分开计算，然后加起来就好了。

对于每个数的每一位，假设有3个0、2个1和4个2，那么“不同数字的数目”是什么呢？

不同数字的数目为$3\times(2+4)+2\times(3+4)+4\times(3+2) = 3\times(9-3)+2\times(9-2)+4\times(9-4)$。

也就是说，统计一下每个数字出现的次数就好了。

+ 时间复杂度$O(n\log M)$，其中$M$是每个数的最大范围
+ 空间复杂度$O(C)$，其中$C=10$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll sumDigitDifferences(vector<int>& nums) {
        ll ans = 0;
        do {
            ll times[10] = {0};
            for (int& t : nums) {
                times[t % 10]++;
                t /= 10;
            }
            for (int i = 0; i < 10; i++) {
                ans += times[i] * (nums.size() - times[i]);
            }
        } while (nums[0]);
        return ans / 2;
    }
};
```

#### Go

```go
package main

func sumDigitDifferences(nums []int) int64 {
    ans := int64(0)
    for nums[0] > 0 {
        times := make([]int, 10)
        for i, n := range nums {
            times[n % 10]++
            nums[i] /= 10
        }
        for i := 0; i < 10; i++ {
            ans += int64(times[i] * (len(nums) - times[i]))
        }
    }
    return ans / 2
}
```

#### Java

```java
class Solution {
    public long sumDigitDifferences(int[] nums) {
        long ans = 0;
        while (nums[0] > 0) {
            long[] times = new long[10];
            for (int i = 0; i < nums.length; i++) {
                times[nums[i] % 10]++;
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; i++) {
                ans += times[i] * (nums.length - times[i]);
            }
        }
        return ans / 2;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        ans = 0
        n = max(nums)
        while n:  # while nums[0]的话可能会有[0, 1]的情况  # 后续更新：忽然发现题目限定是正数，有点过考虑了
            n //= 10
            times = [0] * 10
            for th, x in enumerate(nums):
                times[x % 10] += 1
                nums[th] //= 10
            for i in range(10):
                ans += times[i] * (len(nums) - times[i])
        return ans // 2
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/30/LeetCode%203153.%E6%89%80%E6%9C%89%E6%95%B0%E5%AF%B9%E4%B8%AD%E6%95%B0%E4%BD%8D%E5%B7%AE%E4%B9%8B%E5%92%8C/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141729979](https://letmefly.blog.csdn.net/article/details/141729979)
