---
title: 2555.两个线段获得的最多奖品
date: 2024-09-11 14:40:52
tags: [题解, LeetCode, 中等, 数组, 二分查找, 滑动窗口, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】2555.两个线段获得的最多奖品：动态规划+滑动窗口

力扣题目链接：[https://leetcode.cn/problems/maximize-win-from-two-segments/](https://leetcode.cn/problems/maximize-win-from-two-segments/)

<p>在 <strong>X轴</strong>&nbsp;上有一些奖品。给你一个整数数组&nbsp;<code>prizePositions</code>&nbsp;，它按照 <strong>非递减</strong>&nbsp;顺序排列，其中&nbsp;<code>prizePositions[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;件奖品的位置。数轴上一个位置可能会有多件奖品。再给你一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以选择两个端点为整数的线段。每个线段的长度都必须是 <code>k</code>&nbsp;。你可以获得位置在任一线段上的所有奖品（包括线段的两个端点）。注意，两个线段可能会有相交。</p>

<ul>
	<li>比方说&nbsp;<code>k = 2</code>&nbsp;，你可以选择线段&nbsp;<code>[1, 3]</code> 和&nbsp;<code>[2, 4]</code>&nbsp;，你可以获得满足&nbsp;<code>1 &lt;= prizePositions[i] &lt;= 3</code> 或者&nbsp;<code>2 &lt;= prizePositions[i] &lt;= 4</code>&nbsp;的所有奖品 i 。</li>
</ul>

<p>请你返回在选择两个最优线段的前提下，可以获得的 <strong>最多</strong>&nbsp;奖品数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>prizePositions = [1,1,2,2,3,3,5], k = 2
<b>输出：</b>7
<b>解释：</b>这个例子中，你可以选择线段 [1, 3] 和 [3, 5] ，获得 7 个奖品。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>prizePositions = [1,2,3,4], k = 0
<b>输出：</b>2
<b>解释：</b>这个例子中，一个选择是选择线段 <code>[3, 3]</code> 和 <code>[4, 4] ，获得 2 个奖品。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= prizePositions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prizePositions[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup> </code></li>
	<li><code>prizePositions</code>&nbsp;有序非递减。</li>
</ul>


    
## 解题方法：动态规划+滑动窗口

使用一个数组$dp$，其中$dp[i]$表示前$i$个元素中一条线至多覆盖多少个元素。怎么确定一条线之多能覆盖多少个元素？滑动窗口即可。

> 使用两个指针$l$和$r$分别指向直线覆盖的最左元素和最右元素。每次$r$后移一位，若长度超过$k$则不断右移$l$直至长度$\leq k$。
> 
> 这样，我们就得到了以第$r+1$个元素为直线右端点的直线最多覆盖多少个元素。同时更新$dp$数组即可得到前$i$个元素中一条线至多覆盖多少个元素。

但是这道题有两条线。两条线好说：

> 以类似的方法（双指针的滑动窗口）确定第二条线右端点为$prizePositions[r]$时的最大覆盖数量，加上$dp[l]$就变成了两条线的最大覆盖数量了（没有人想让两条线有重叠吧）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        vector<int> dp(prizePositions.size() + 1);
        int ans = 0;
        for (int l = 0, r = 0; r < prizePositions.size(); r++) {
            while (prizePositions[r] - prizePositions[l] > k) {
                l++;
            }
            ans = max(ans, r - l + 1 + dp[l]);
            dp[r + 1] = max(dp[r], r - l + 1);
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        ans = 0
        dp = [0] * (len(prizePositions) + 1)
        l, r = 0, 0
        while r < len(prizePositions):
            while prizePositions[r] - prizePositions[l] > k:
                l += 1
            ans = max(ans, r - l + 1 + dp[l])
            dp[r + 1] = max(dp[r], r - l + 1)
            r += 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/11/LeetCode%202555.%E4%B8%A4%E4%B8%AA%E7%BA%BF%E6%AE%B5%E8%8E%B7%E5%BE%97%E7%9A%84%E6%9C%80%E5%A4%9A%E5%A5%96%E5%93%81/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142149662](https://letmefly.blog.csdn.net/article/details/142149662)
