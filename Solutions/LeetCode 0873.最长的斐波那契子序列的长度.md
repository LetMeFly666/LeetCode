---
title: 873.最长的斐波那契子序列的长度
date: 2022-07-09 10:43:36
tags: [题解, LeetCode, 中等, 数组, 哈希表, 动态规划, DP, 子问题, 最x子xx, 斐波那契]
---

# 【LetMeFly】873.最长的斐波那契子序列的长度

力扣题目链接：[https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/](https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/)

<p>如果序列 <code>X_1, X_2, ..., X_n</code> 满足下列条件，就说它是 <em>斐波那契式 </em>的：</p>

<ul>
	<li><code>n >= 3</code></li>
	<li>对于所有 <code>i + 2 <= n</code>，都有 <code>X_i + X_{i+1} = X_{i+2}</code></li>
</ul>

<p>给定一个<strong>严格递增</strong>的正整数数组形成序列 arr ，找到 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.600000381469727px"><span style="caret-color:#c7254e"><span style="background-color:#f9f2f4">arr</span></span></span></font></font> 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。</p>

<p><em>（回想一下，子序列是从原序列 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.600000381469727px"><span style="caret-color:#c7254e"><span style="background-color:#f9f2f4">arr</span></span></span></font></font> 中派生出来的，它从 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.600000381469727px"><span style="caret-color:#c7254e"><span style="background-color:#f9f2f4">arr</span></span></span></font></font> 中删掉任意数量的元素（也可以不删），而不改变其余元素的顺序。例如， <code>[3, 5, 8]</code> 是 <code>[3, 4, 5, 6, 7, 8]</code> 的一个子序列）</em></p>

<p> </p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>arr =<strong> </strong>[1,2,3,4,5,6,7,8]
<strong>输出: </strong>5
<strong>解释: </strong>最长的斐波那契式子序列为 [1,2,3,5,8] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入: </strong>arr =<strong> </strong>[1,3,7,11,12,14,18]
<strong>输出: </strong>3
<strong>解释</strong>: 最长的斐波那契式子序列有 [1,11,12]、[3,11,14] 以及 [7,11,18] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= arr.length <= 1000</code></li>
	<li>
	<p><code>1 <= arr[i] < arr[i + 1] <= 10^9</code></p>
	</li>
</ul>


    
## 方法一：动态规划 + 哈希

我们用$dp[i][j]$表示以$arr[i]$和$arr[j]$结尾的斐波那契数列的长度。

以$arr[i]$和$arr[j]$结尾的斐波那契数列的的前一项是$arr[j] - arr[i]$（记为$last$）。

如果$last$存在（我们可以用哈希表预处理每个元素出现过的位置），并且$last$出现的位置在$i$之前（记为$index$），则$dp[i][j] = dp[index][i]$。（以$arr[i]$、$arr[j]$结尾的斐波那契数列的长度是以$arr[j] - arr[i]$、$arr[i]$结尾的斐波那契数列的长度＋1）

具体实现可参考代码

+ 时间复杂度$O(n^2)$，其中$n$是数组$arr$的长度
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> ma;
        int n = arr.size();
        for (int i = 0; i < n; i++) {  // 预处理记录每个元素出现的位置
            ma[arr[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));  // 初始值以arr[i]和arr[j]结尾的数列长度为2
        int ans = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int last = arr[j] - arr[i];
                if (ma.count(last)) {
                    int index = ma[last];
                    if (index < i) {
                        // dp[i][j] = max(dp[i][j], dp[index][i] + 1);
                        dp[i][j] = dp[index][i] + 1;  // 这里不用max，因为dp[i][j]一定为2，一定小于dp[index][i] + 1
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        return ans > 2 ? ans : 0;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/09/LeetCode%200873.%E6%9C%80%E9%95%BF%E7%9A%84%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E9%95%BF%E5%BA%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125690924](https://letmefly.blog.csdn.net/article/details/125690924)
