---
title: 474.一和零
date: 2022-10-27 08:43:16
tags: [题解, LeetCode, 中等, 数组, 字符串, 动态规划, dp]
---

# 【LetMeFly】474.一和零

力扣题目链接：[https://leetcode.cn/problems/ones-and-zeroes/](https://leetcode.cn/problems/ones-and-zeroes/)

<p>给你一个二进制字符串数组 <code>strs</code> 和两个整数 <code>m</code> 和 <code>n</code> 。</p>

<div class="MachineTrans-Lines">
<p class="MachineTrans-lang-zh-CN">请你找出并返回 <code>strs</code> 的最大子集的长度，该子集中 <strong>最多</strong> 有 <code>m</code> 个 <code>0</code> 和 <code>n</code> 个 <code>1</code> 。</p>

<p class="MachineTrans-lang-zh-CN">如果 <code>x</code> 的所有元素也是 <code>y</code> 的元素，集合 <code>x</code> 是集合 <code>y</code> 的 <strong>子集</strong> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
<strong>输出：</strong>4
<strong>解释：</strong>最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["10", "0", "1"], m = 1, n = 1
<strong>输出：</strong>2
<strong>解释：</strong>最大的子集是 {"0", "1"} ，所以答案是 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 600</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code>&nbsp;仅由&nbsp;<code>'0'</code> 和&nbsp;<code>'1'</code> 组成</li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
</ul>


    
## 方法一：动态规划

用$dp[j][k]$代表遍历到当前字符串时，一共有$j$个$1$和$k$个$0$的“最大子集的长度”

在遍历到一个新的字符串时，如果这个字符串有$one$个$1$和$zero$个$0$，那么对于任意的$dp[j][k]$，都可由$dp[j - one][k - zero]$加上当前字符串组合而来。因此$dp[j][k] = \max(dp[j][k], dp[j - one][k - zero]) + 1$

问题解决了。

+ 时间复杂度$O(n\times m\times l + N\times l)$，其中$l$是字符串的个数，$N$是平均一个字符串中的字符个数
+ 空间复杂度$O(n\times m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < strs.size(); i++) {
            int zero = 0, one = 0;
            for (char c : strs[i]) {
                if (c == '1')
                    one++;
                else
                    zero++;
            }
            for (int j = m; j >= zero; j--) {
                for (int k = n; k >= one; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/27/LeetCode%200474.%E4%B8%80%E5%92%8C%E9%9B%B6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127544970](https://letmefly.blog.csdn.net/article/details/127544970)
