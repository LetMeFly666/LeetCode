---
title: 2708.一个小组的最大实力值
date: 2024-09-04 09:14:06
tags: [题解, LeetCode, 中等, 贪心, 位运算, 数组, 动态规划, 回溯, 枚举, 排序, 遍历]
---

# 【LetMeFly】2708.一个小组的最大实力值：O(n)一次遍历

力扣题目链接：[https://leetcode.cn/problems/maximum-strength-of-a-group/](https://leetcode.cn/problems/maximum-strength-of-a-group/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它表示一个班级中所有学生在一次考试中的成绩。老师想选出一部分同学组成一个 <strong>非空</strong>&nbsp;小组，且这个小组的 <strong>实力值</strong>&nbsp;最大，如果这个小组里的学生下标为&nbsp;<code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, <code>i<sub>2</sub></code>, ... , <code>i<sub>k</sub></code>&nbsp;，那么这个小组的实力值定义为&nbsp;<code>nums[i<sub>0</sub>] * nums[i<sub>1</sub>] * nums[i<sub>2</sub>] * ... * nums[i<sub>k</sub>​]</code>&nbsp;。</p>

<p>请你返回老师创建的小组能得到的最大实力值为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,-1,-5,2,5,-9]
<strong>输出：</strong>1350
<b>解释：</b>一种构成最大实力值小组的方案是选择下标为 [0,2,3,4,5] 的学生。实力值为 3 * (-5) * 2 * 5 * (-9) = 1350 ，这是可以得到的最大实力值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [-4,-5,-4]
<b>输出：</b>20
<b>解释：</b>选择下标为 [0, 1] 的学生。得到的实力值为 20 。我们没法得到更大的实力值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 13</code></li>
	<li><code>-9 &lt;= nums[i] &lt;= 9</code></li>
</ul>


    
## 解题方法：一次遍历

非常小的负数（绝对值非常大）乘以一个负整数就变成了非常大的数；非常大的正数乘以一个正整数也是非常大的数。

有没有发现，我们只需要考虑最大的数和最小的数就可以了。

因此只需要遍历一次数组，遍历的过程中使用两个变量$M$和$m$分别维护当前最大值和最小值。更新公式：

$$
new\_m = \min\{m, nums[i], m\times nums[i], M\times nums[i]\} \\
new\_M = \max\{M, nums[i], m\times nums[i], M\times nums[i]\} 
$$

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
// 9^{13} = 2541865828329
class Solution {
public:
    ll maxStrength(vector<int>& nums) {
        ll m = nums[0], M = m;
        for (int i = 1; i < nums.size(); i++) {
            ll newm = min({m, (ll)nums[i], m * nums[i], M * nums[i]});
            ll newM = max({M, (ll)nums[i], m * nums[i], M * nums[i]});
            m = newm, M = newM;
        }
        return M;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        M, m = nums[0], nums[0]
        for i in range(1, len(nums)):
            M, m = max(M, nums[i], M * nums[i], m * nums[i]), \
                   min(m, nums[i], M * nums[i], m * nums[i])
        return M
```

#### Java

```java
class Solution {
    public long maxStrength(int[] nums) {
        long m = nums[0], M = nums[0];
        for (int i = 1; i < nums.length; i++) {
            long newm = Math.min(m, Math.min((long)(nums[i]), Math.min(m * nums[i], M * nums[i])));
            long newM = Math.max(M, Math.max((long)(nums[i]), Math.max(m * nums[i], M * nums[i])));
            m = newm;
            M = newM;
        }
        return M;
    }
}
```

#### Go

```go
package main

func min(a int64, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

func min4(a int64, b int64, c int64, d int64) int64 {
    return min(a, min(b, min(c, d)))
}

func max(a int64, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func max4(a int64, b int64, c int64, d int64) int64 {
    return max(a, max(b, max(c, d)))
}

func maxStrength(nums []int) int64 {
    m, M := (int64)(nums[0]), int64(nums[0])
    for i := 1; i < len(nums); i++ {
        m, M = min4(m, (int64)(nums[i]), m * (int64)(nums[i]), M * (int64)(nums[i])),
               max4(M, (int64)(nums[i]), m * (int64)(nums[i]), M * (int64)(nums[i]))
    }
    return M
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/04/LeetCode%202708.%E4%B8%80%E4%B8%AA%E5%B0%8F%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%AE%9E%E5%8A%9B%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141884725](https://letmefly.blog.csdn.net/article/details/141884725)
