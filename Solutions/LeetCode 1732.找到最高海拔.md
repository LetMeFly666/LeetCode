---
title: 1732.找到最高海拔
date: 2022-11-19 08:33:19
tags: [题解, LeetCode, 简单, 数组, 前缀和, 模拟]
---

# 【LetMeFly】1732.找到最高海拔

力扣题目链接：[https://leetcode.cn/problems/find-the-highest-altitude/](https://leetcode.cn/problems/find-the-highest-altitude/)

<p>有一个自行车手打算进行一场公路骑行，这条路线总共由 <code>n + 1</code> 个不同海拔的点组成。自行车手从海拔为 <code>0</code> 的点 <code>0</code> 开始骑行。</p>

<p>给你一个长度为 <code>n</code> 的整数数组 <code>gain</code> ，其中 <code>gain[i]</code> 是点 <code>i</code> 和点 <code>i + 1</code> 的 <strong>净海拔高度差</strong>（<code>0 <= i < n</code>）。请你返回 <strong>最高点的海拔</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>gain = [-5,1,5,0,-7]
<b>输出：</b>1
<b>解释：</b>海拔高度依次为 [0,-5,-4,1,1,-6] 。最高海拔为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>gain = [-4,-3,-2,-1,4,3,2]
<b>输出：</b>0
<b>解释：</b>海拔高度依次为 [0,-4,-7,-9,-10,-6,-3,-1] 。最高海拔为 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == gain.length</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>-100 <= gain[i] <= 100</code></li>
</ul>


    
## 方法一：累加求最大值

初始海拔为$0$，之后每次海拔的变化值为$gain[i]$

因此，我们只需要模拟“骑手”，从初始位置到终止位置遍历一遍，并计算出当前高度即可。

整个计算过程中，我们不断更新答案的最大值。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int now = 0;
        for (int& t : gain) {
            now += t;
            ans = max(ans, now);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/19/LeetCode%201732.%E6%89%BE%E5%88%B0%E6%9C%80%E9%AB%98%E6%B5%B7%E6%8B%94/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127932334](https://letmefly.blog.csdn.net/article/details/127932334)
