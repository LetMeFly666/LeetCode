---
title: 1458.两个子序列的最大点积：动态规划
date: 2026-01-08 09:52:21
tags: [题解, LeetCode, 困难, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】1458.两个子序列的最大点积：动态规划

力扣题目链接：[https://leetcode.cn/problems/max-dot-product-of-two-subsequences/](https://leetcode.cn/problems/max-dot-product-of-two-subsequences/)

<p>给你两个数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;。</p>

<p>请你返回 <code>nums1</code> 和 <code>nums2</code> 中两个长度相同的 <strong>非空</strong> 子序列的最大点积。</p>

<p>数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，<code>[2,3,5]</code>&nbsp;是&nbsp;<code>[1,2,3,4,5]</code>&nbsp;的一个子序列而&nbsp;<code>[1,5,3]</code>&nbsp;不是。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,1,-2,5], nums2 = [3,0,-6]
<strong>输出：</strong>18
<strong>解释：</strong>从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
它们的点积为 (2*3 + (-2)*(-6)) = 18 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [3,-2], nums2 = [2,-6,7]
<strong>输出：</strong>21
<strong>解释：</strong>从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
它们的点积为 (3*7) = 21 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [-1,-1], nums2 = [1,1]
<strong>输出：</strong>-1
<strong>解释：</strong>从 nums1 中得到子序列 [-1] ，从 nums2 中得到子序列 [1] 。
它们的点积为 -1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 500</code></li>
	<li><code>-1000 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>点积：</strong></p>

<pre>
定义 <code><strong>a</strong>&nbsp;= [<em>a</em><sub>1</sub>,&nbsp;<em>a</em><sub>2</sub>,…,&nbsp;<em>a</em><sub><em>n</em></sub>]</code> 和<strong> <code>b</code></strong><code>&nbsp;= [<em>b</em><sub>1</sub>,&nbsp;<em>b</em><sub>2</sub>,…,&nbsp;<em>b</em><sub><em>n</em></sub>]</code> 的点积为：

<img alt="\mathbf{a}\cdot \mathbf{b} = \sum_{i=1}^n a_ib_i = a_1b_1 + a_2b_2 + \cdots + a_nb_n " class="tex" src="https://pic.leetcode-cn.com/1666164309-PBJMQp-image.png" />

这里的 <strong>Σ</strong> 指示总和符号。
</pre>


    
## 解题方法：动态规划

令`dp[i][j]`表示`nums1[0..i]`与`nums2[0..j]`的子序列最大点积，那么则有状态转移方程：

```cpp
dp[i][j] = max(
    nums1[i] * nums1[j],              // 不要前面的，从nums1[i]和nums2[j]开始
    dp[i-1][j],                       // nums1[0..i-1]与nums2[0..j]的子序列最大点积
    dp[i][j-1],                       // nums1[0..i]与nums2[0..j-1]的子序列最大点积
    dp[i-1][j-1] + nums1[i]*nums1[j]  // 前面的最大点积，加上nums1[i]*nums1[j]
)
```

上述转移方程包含了所有$nums1[i]$与$nums2[j]$相乘和不相乘的情况。

+ 时间复杂度$O(len(nums1)\times len(nums2))$
+ 空间复杂度$O(len(nums1)\times len(nums2))$

当然，为了减少对$i-1$是否越界的判断，也可以给dp数组多开辟一行一列的空间，但注意这样的话多开辟那一行一列空间的初始值要小于等于$-10^6$（单个$nums1[i]\times nums2[j]最小值）。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-08 09:23:30
 */
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = nums1[i] * nums2[j];
                if (i) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                if (j) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
                if (i && j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums1[i] * nums2[j]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-01-08 09:29:41
'''
from typing import List

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [[-1000000000] * (len(nums2) + 1) for _ in range(len(nums1) + 1)]
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                dp[i][j] = max(x * y, dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + x * y)
        return dp[-1][-1]
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-08 09:45:31
 */
import java.util.Arrays;

class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int n = nums1.length, m = nums2.length;
        int[][] dp = new int[n+1][m+1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1000000);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = Math.max(nums1[i-1] * nums2[j-1], Math.max(dp[i-1][j], Math.max(dp[i][j - 1], dp[i-1][j-1] + nums1[i-1] * nums2[j-1])));
            }
        }
        return dp[n][m];
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-01-08 09:36:59
 */
package main

func max1458_2(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func max1458(a, b, c, d int) int {
    return max1458_2(a, max1458_2(b, max1458_2(c, d)))
}

func maxDotProduct(nums1 []int, nums2 []int) int {
    n, m := len(nums1), len(nums2)
    dp := make([][]int, n + 1)
    for i := range dp {
        dp[i] = make([]int, m + 1)
        for j := range dp[i] {
            dp[i][j] = -1000000;
        }
    }
    
    for i, x := range nums1 {
        for j, y := range nums2 {
            dp[i+1][j+1] = max1458(x*y, dp[i][j+1], dp[i+1][j], dp[i][j] + x*y)
        }
    }
    return dp[n][m]  // 不是dp[n-1][m-1]
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-08 09:51:58
 */
impl Solution {
    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let n: usize = nums1.len();
        let m: usize = nums2.len();
        let mut dp: Vec<Vec<i32>> = vec![vec![-1000000; m+1]; n+1];
        for i in 1..=n {
            for j in 1..=m {
                dp[i][j] = dp[i-1][j].max(dp[i][j-1].max((nums1[i-1] * nums2[j-1]).max(dp[i-1][j-1] + nums1[i-1] * nums2[j-1])));
            }
        }
        dp[n][m]
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156713484)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/08/LeetCode%201458.%E4%B8%A4%E4%B8%AA%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E6%9C%80%E5%A4%A7%E7%82%B9%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
