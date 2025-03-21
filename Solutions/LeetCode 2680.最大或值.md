---
title: 2680.最大或值：位运算
date: 2025-03-21 16:36:22
tags: [题解, LeetCode, 中等, 贪心, 位运算, 数组, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】2680.最大或值：位运算

力扣题目链接：[https://leetcode.cn/problems/maximum-or/](https://leetcode.cn/problems/maximum-or/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code> 。每一次操作中，你可以选择一个数并将它乘&nbsp;<code>2</code>&nbsp;。</p>

<p>你最多可以进行 <code>k</code>&nbsp;次操作，请你返回<em>&nbsp;</em><code>nums[0] | nums[1] | ... | nums[n - 1]</code>&nbsp;的最大值。</p>

<p><code>a | b</code>&nbsp;表示两个整数 <code>a</code>&nbsp;和 <code>b</code>&nbsp;的 <strong>按位或</strong>&nbsp;运算。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [12,9], k = 1
<b>输出：</b>30
<b>解释：</b>如果我们对下标为 1 的元素进行操作，新的数组为 [12,18] 。此时得到最优答案为 12 和 18 的按位或运算的结果，也就是 30 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [8,1,2], k = 2
<b>输出：</b>35
<b>解释：</b>如果我们对下标 0 处的元素进行操作，得到新数组 [32,1,2] 。此时得到最优答案为 32|1|2 = 35 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 15</code></li>
</ul>

很不错的一道题！位运算的与或异或都考察了。

## 解题方法一：前缀和

首先需要发现并理解的是：一定要每次都将“二进制下位数最长的那个数乘2”。

> 假如a二进制下是3位，b二进制下是2位，那么将b乘以2后和a或运算还是3位，一定不如将a乘以2变成2位大。

二进制下长度最长的数有多个，如何选择呢？

> 无所谓，每个都试试呗。我们只需要逮着一个数一直乘以2共k次，判断所有选择中结果最大的那个就好了。

这一听不是$O(n^2)$吗，如何优化？

> 使用一个前缀和$prefix[i]$代表从下标$0$或到下标$i$这个元素的结果，“后缀和”$suffix[i]$代表从最后一个元素或到下标$i$的结果。
>
> 那么，如果将$nums[i]$乘以$k$次$2$的话，最终的或结果就是$prefix[i - 1]\ |\ nums[i] << k\ |\ suffix[i + 1]$。

所有的这些结果中，最大的那个即为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:09:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 15:17:06
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

typedef long long ll;

class Solution {
public:
    ll maximumOr(vector<int>& nums, int k) {
        vector<int> suffix(nums.size() + 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] | nums[i];
        }
        ll ans = 0;
        int prefix = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, (ll)(nums[i]) << k | prefix | suffix[i + 1]);
            prefix |= nums[i];
        }
        return ans;
    }
};
```

## 解题方法二：位运算

方法一空间复杂度为$O(n)$，可否使用位运算优化？例如我单独将$nums[i]$拎出来左移$k$次的话，如何在$O(1)$空间下快速判断出剩下所有元素的或值为多少？

> 假设数组中所有元素或运算的结果为$allOr$：
>
> + 对于$nums[i]$二进制下的某个$1$，如果其他元素中这一位**也有**出现过$1$，那么拎出来$nums[i]$后剩下元素这一位的或结果和$allOr$相同
>
> + 对于$nums[i]$二进制下的某个$1$，如果其他元素中这一位**没有**出现过$1$，那么拎出来$nums[i]$后剩下元素这一位的或结果和$allOr$不同

也就是说，我们只需要统计一下哪一位$1$出现过最少两次（$all1$为$1$的位代表至少有两个数这一位为$1$），如果$nums[i]$这一位为$1$的话，依据$all1$的这一位是否为$1$，就能判断出其他元素中是否存在这一位为$1$的情况，就能得知除$nums[i]$外其他元素这一位或运算的结果是否为$1$了。

最后就剩下了一个问题：如何求出$all1$？

> 同样使用前缀和的思路，$prefix$代表从第一个元素到当前元素的上一个元素为止的或结果。
>
> 如果那么$prefix\ \&\ nums[i]$的某一位为$1$的话，就代表$nums[i]$和前面的数中的某些数这一位都为$1$，也就是说这一位至少出现了两次$1$
>
> 因此将$all1$或上$prefix\ \&\ nums[i]$即可。

这样，遍历到$nums[i]$时，$allOr\ \^\ nums[i]\ |\ all1$即为所有元素除去$nums[i]$后的或结果。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:29:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 15:32:32
 * @Descriptions: Fake Time
 * @Descriptions: AC,100.00%,90.30%
 */
typedef long long ll;

class Solution {
public:
    ll maximumOr(vector<int>& nums, int k) {
        int allOr = 0, all1 = 0;
        for (int t : nums) {
            all1 |= allOr & t;
            allOr |= t;
        }
        ll ans = 0;
        for (int t : nums) {
            ans = max(ans, allOr ^ t | all1 | (ll)(t) << k);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-21 15:21:19
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-21 15:27:03
'''
from typing import List

class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        allOr = all1 = 0
        for t in nums:
            all1 |= t & allOr
            allOr |= t
        ans = 0
        for t in nums:
            ans = max(ans, t ^ allOr | all1 | t << k)
        return ans
    
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:32:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 15:34:12
 */
class Solution {
    public long maximumOr(int[] nums, int k) {
        int allOr = 0, all1 = 0;
        for (int t : nums) {
            all1 |= t & allOr;
            allOr |= t;
        }
        long ans = 0;
        for (int t : nums) {
            ans = Math.max(ans, allOr ^ t | all1 | (long)t << k);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-21 15:34:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-21 16:32:51
 * @Description: Go int和int64的位运算似乎几乎一点都不会自动转换类型
 */
package main

func maximumOr(nums []int, k int) (ans int64) {
    allOr, all1 := 0, 0
    for _, t := range nums {
        all1 |= allOr & t
        allOr |= t
    }
    for _, t := range nums {
        ans = max(ans, int64(allOr) ^ int64(t) | int64(all1) | int64(t) << k)
    }
    return
}
```

## End

说实话感觉这次官解写的不错，灵神有待加油啊。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146426782)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/21/LeetCode%202680.%E6%9C%80%E5%A4%A7%E6%88%96%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
