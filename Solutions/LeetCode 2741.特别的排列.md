---
title: 2741.特别的排列
date: 2024-06-26 22:31:45
tags: [题解, LeetCode, 中等, 位运算, 数组, 状态压缩, DP, 动态规划]
---

# 【LetMeFly】2741.特别的排列：状压DP

力扣题目链接：[https://leetcode.cn/problems/special-permutations/](https://leetcode.cn/problems/special-permutations/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它包含 <code>n</code>&nbsp;个 <strong>互不相同</strong>&nbsp;的正整数。如果&nbsp;<code>nums</code>&nbsp;的一个排列满足以下条件，我们称它是一个特别的排列：</p>

<ul>
	<li>对于&nbsp;<code>0 &lt;= i &lt; n - 1</code>&nbsp;的下标 <code>i</code>&nbsp;，要么&nbsp;<code>nums[i] % nums[i+1] == 0</code>&nbsp;，要么&nbsp;<code>nums[i+1] % nums[i] == 0</code>&nbsp;。</li>
</ul>

<p>请你返回特别排列的总数目，由于答案可能很大，请将它对<strong>&nbsp;</strong><code>10<sup>9&nbsp;</sup>+ 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,6]
<b>输出：</b>2
<b>解释：</b>[3,6,2] 和 [2,6,3] 是 nums 两个特别的排列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,4,3]
<b>输出：</b>2
<b>解释：</b>[3,1,4] 和 [4,1,3] 是 nums 两个特别的排列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 14</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：状态压缩的动态规划

需要明白的是，若要看 “在特别排列```[a, b, c]```的基础上添加元素```d```生成的```[a, b, c, d]``` ”是否为特别排列，只需要判断```c```和```d```是否能整除或被整除即可。

因此，对于一个特别排列，我们**只关心这个排列的最后一个数字**以及**这个排列中已经有了哪些数字**。

对于“这个排列中已经有了哪些数字”，我们可以使用“一个整数二进制下的低$n$位”来表示。

因此，我们可以定义一个```DP```数组，```dp[state][last]```表示排列中出现的数字们为```state```，排列最后一个数字为```last```时的“特别排列”数。

这个数是怎么得到的呢？假设```prev```在当前排列中（```state & (1 << prev) ≠ 0```）且```prev```和```last```是倍数关系，那么这个排列可以由“这个排列移除```last```的最后一个数为```prev```的排列”拼接上```last```得到。

因此有状态转移方程：$dp[state][last] = \sum_{prev\in state} dp[state - (1 << last)][prev]$。

+ 时间复杂度$O(2^nn^2)$
+ 空间复杂度$O(2^nn)$

### AC代码

#### C++

```cpp
const static long long MOD = 1e9 + 7;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 1;
        }
        for (int state = 0; state < (1 << n); state++) {
            for (int prev = 0; prev < n; prev++) {  // 上一位
                for (int last = 0; last < n; last++) {  // 最后一位
                    if ((state & (1 << last)) && (state & (1 << prev)) && last != prev && (nums[last] % nums[prev] == 0 || nums[prev] % nums[last] == 0)) {
                        dp[state][last] = (dp[state][last] + dp[state ^ (1 << last)][prev]) % MOD;
                    }
                }
            }
        }
        long long ans = 0;
        for (int last = 0; last < n; last++) {
            ans = (ans + dp[(1 << n) - 1][last]) % MOD;
        }
        return ans;
    }
};
```

#### Python

附上一个Python超时版本。不想提前判断剪枝优化了。。。

```python
from typing import List

MOD = 1_000_000_007

class Solution:
    def specialPerm(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[0 for _ in range(n)] for __ in range(1 << n)]
        for i in range(n):
            dp[1 << i][i] = 1
        for state in range(1 << n):
            for last in range(n):
                for prev in range(n):
                    if (state & (1 << last)) and (state & (1 << prev)) and (nums[prev] % nums[last] == 0 or nums[last] % nums[prev] == 0):
                        dp[state][last] = (dp[state][last] + dp[state ^ (1 << last)][prev]) % MOD
        ans = 0
        for i in range(n):
            ans = (ans + dp[(1 << n) - 1][i]) % MOD
        return ans


if __name__ == '__main__':
    print(Solution.specialPerm('', [838335396, 241654240, 937115884, 795934157, 907282921, 71642053, 242720010, 16417709, 706807579, 752842522, 162230770, 425078819, 793563691, 522087056]))
```

反正也每人看我题解(bushi)。

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/26/LeetCode%202741.%E7%89%B9%E5%88%AB%E7%9A%84%E6%8E%92%E5%88%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140000372](https://letmefly.blog.csdn.net/article/details/140000372)
