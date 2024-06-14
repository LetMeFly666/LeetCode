---
title: 2786.访问数组中的位置使分数最大
date: 2024-06-14 19:15:32
tags: [题解, LeetCode, 中等, 数组, 动态规划]
---

# 【LetMeFly】2786.访问数组中的位置使分数最大：奇偶分开记录（逻辑还算清晰的题解）

力扣题目链接：[https://leetcode.cn/problems/visit-array-positions-to-maximize-score/](https://leetcode.cn/problems/visit-array-positions-to-maximize-score/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>x</code>&nbsp;。</p>

<p>你 <strong>一开始</strong>&nbsp;在数组的位置 <code>0</code>&nbsp;处，你可以按照下述规则访问数组中的其他位置：</p>

<ul>
	<li>如果你当前在位置&nbsp;<code>i</code>&nbsp;，那么你可以移动到满足&nbsp;<code>i &lt; j</code>&nbsp;的&nbsp;<strong>任意</strong>&nbsp;位置&nbsp;<code>j</code>&nbsp;。</li>
	<li>对于你访问的位置 <code>i</code>&nbsp;，你可以获得分数&nbsp;<code>nums[i]</code>&nbsp;。</li>
	<li>如果你从位置 <code>i</code>&nbsp;移动到位置 <code>j</code>&nbsp;且&nbsp;<code>nums[i]</code> 和&nbsp;<code>nums[j]</code>&nbsp;的 <strong>奇偶性</strong>&nbsp;不同，那么你将失去分数&nbsp;<code>x</code>&nbsp;。</li>
</ul>

<p>请你返回你能得到的 <strong>最大</strong>&nbsp;得分之和。</p>

<p><strong>注意</strong>&nbsp;，你一开始的分数为&nbsp;<code>nums[0]</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,3,6,1,9,2], x = 5
<b>输出：</b>13
<b>解释：</b>我们可以按顺序访问数组中的位置：0 -&gt; 2 -&gt; 3 -&gt; 4 。
对应位置的值为 2 ，6 ，1 和 9 。因为 6 和 1 的奇偶性不同，所以下标从 2 -&gt; 3 让你失去 x = 5 分。
总得分为：2 + 6 + 1 + 9 - 5 = 13 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,4,6,8], x = 3
<b>输出：</b>20
<b>解释：</b>数组中的所有元素奇偶性都一样，所以我们可以将每个元素都访问一次，而且不会失去任何分数。
总得分为：2 + 4 + 6 + 8 = 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], x &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 解题方法：两个变量分别记录上一个位置是奇数和偶数时的最大值

每个数都大于0，并且奇偶性相同的数之间跳跃没有额外的费用（不用-x）。因此**奇偶性相同的数不会间隔地跳**：

> 以奇数为例，假设有三个奇数$a$、$b$、$c$，则由奇数跳到$c$的话，一定是从$b$跳过去的，不可能是从$a$直接跳到$c$。因为$a->c$不如$a->b->c$。

因此，我们只需要使用两个变量$odd$和$even$，分别记录上一个数为奇数或偶数时的分数最大值。遍历整数数组时有如下公式：

> + 若当前元素$t$为奇数，则从奇数跳过来的话分数为$odd+t$，从偶数跳过来的话分数为$even+t-x$，因此最大分数为$\max(odd+t, even+t-x)$
> + 若当前元素$t$为偶数，则从奇数跳过来的话分数为$odd+t-x$，从偶数跳过来的话分数为$even+t$，因此最大分数为$\max(odd+t-x, even+t)$

特别的，起点必须为第一个数。假设第一个数为奇数，则偶数的默认值为$-x$。这是因为：

> 第一个数为奇数的话，第一次跳到偶数的时候，实质上必定是由奇数跳过去的。而计算公式中的$even+t$是由偶数跳过去的，相当于少扣了$x$分。

### 时空复杂度分析

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll maxScore(vector<int>& nums, int x) {
        ll odd = nums[0] % 2 ? 0 : -x, even = nums[0] % 2 ? -x : 0;
        for (int t : nums) {
            if (t % 2) {
                odd = max(odd + t, even + t - x);
            }
            else {
                even = max(odd + t - x, even + t);
            }
        }
        return max(odd, even);
    }
};
```

#### Go

```go
func max(a int64, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func maxScore(nums []int, x int) int64 {
    odd, even := int64(0), int64(0)
    if nums[0] % 2 == 0 {
        odd = -int64(x)
    } else {
        even = -int64(x)
    }
    for _, t := range nums {
        if t % 2 != 0 {
            odd = max(odd + int64(t), even + int64(t) - int64(x))
        } else {
            even =  max(odd + int64(t) - int64(x), even + int64(t))
        }
    }
    return max(odd, even)
}
```

#### Java

```java
class Solution {
    public long maxScore(int[] nums, int x) {
        long odd = nums[0] % 2 != 0 ? 0 : -x, even = nums[0] % 2 != 0 ? -x : 0;
        for (int t : nums) {
            if (t % 2 != 0) {
                odd = Math.max(odd + t, even + t - x);
            }
            else {
                even = Math.max(odd + t - x, even + t);
            }
        }
        return Math.max(odd, even);
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        odd, even = 0 if nums[0] % 2 else -x, -x if nums[0] % 2 else 0
        for t in nums:
            if t % 2:
                odd = max(odd + t, even + t - x)
            else:
                even = max(odd + t - x, even + t)
        return max(even, odd)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/14/LeetCode%202786.%E8%AE%BF%E9%97%AE%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E4%BD%8D%E7%BD%AE%E4%BD%BF%E5%88%86%E6%95%B0%E6%9C%80%E5%A4%A7/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139688753](https://letmefly.blog.csdn.net/article/details/139688753)
