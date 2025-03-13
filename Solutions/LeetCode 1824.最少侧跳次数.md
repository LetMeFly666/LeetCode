---
title: 1824.最少侧跳次数
date: 2023-01-21 10:46:55
tags: [题解, LeetCode, 中等, 贪心, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】1824.最少侧跳次数

力扣题目链接：[https://leetcode.cn/problems/minimum-sideway-jumps/](https://leetcode.cn/problems/minimum-sideway-jumps/)

<p>给你一个长度为 <code>n</code> 的 <strong>3 跑道道路</strong> ，它总共包含 <code>n + 1</code> 个 <strong>点</strong> ，编号为 <code>0</code> 到 <code>n</code> 。一只青蛙从 <code>0</code> 号点第二条跑道 <strong>出发</strong> ，它想要跳到点 <code>n</code> 处。然而道路上可能有一些障碍。</p>

<p>给你一个长度为 <code>n + 1</code> 的数组 <code>obstacles</code> ，其中 <code>obstacles[i]</code> （<b>取值范围从 0 到 3</b>）表示在点 <code>i</code> 处的 <code>obstacles[i]</code> 跑道上有一个障碍。如果 <code>obstacles[i] == 0</code> ，那么点 <code>i</code> 处没有障碍。任何一个点的三条跑道中 <strong>最多有一个</strong> 障碍。</p>

<ul>
	<li>比方说，如果 <code>obstacles[2] == 1</code> ，那么说明在点 2 处跑道 1 有障碍。</li>
</ul>

<p>这只青蛙从点 <code>i</code> 跳到点 <code>i + 1</code> 且跑道不变的前提是点 <code>i + 1</code> 的同一跑道上没有障碍。为了躲避障碍，这只青蛙也可以在 <strong>同一个</strong> 点处 <strong>侧跳</strong> 到 <strong>另外一条</strong> 跑道（这两条跑道可以不相邻），但前提是跳过去的跑道该点处没有障碍。</p>

<ul>
	<li>比方说，这只青蛙可以从点 3 处的跑道 3 跳到点 3 处的跑道 1 。</li>
</ul>

<p>这只青蛙从点 0 处跑道 <code>2</code> 出发，并想到达点 <code>n</code> 处的 <strong>任一跑道</strong> ，请你返回 <strong>最少侧跳次数</strong> 。</p>

<p><strong>注意</strong>：点 <code>0</code> 处和点 <code>n</code> 处的任一跑道都不会有障碍。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex1.png" style="width: 500px; height: 244px;" />
<pre>
<b>输入：</b>obstacles = [0,1,2,3,0]
<b>输出：</b>2 
<b>解释：</b>最优方案如上图箭头所示。总共有 2 次侧跳（红色箭头）。
注意，这只青蛙只有当侧跳时才可以跳过障碍（如上图点 2 处所示）。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex2.png" style="width: 500px; height: 196px;" />
<pre>
<b>输入：</b>obstacles = [0,1,1,3,3,0]
<b>输出：</b>0
<b>解释：</b>跑道 2 没有任何障碍，所以不需要任何侧跳。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/25/ic234-q3-ex3.png" style="width: 500px; height: 196px;" />
<pre>
<b>输入：</b>obstacles = [0,2,1,0,3,0]
<b>输出：</b>2
<b>解释：</b>最优方案如上图所示。总共有 2 次侧跳。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obstacles.length == n + 1</code></li>
	<li><code>1 <= n <= 5 * 10<sup>5</sup></code></li>
	<li><code>0 <= obstacles[i] <= 3</code></li>
	<li><code>obstacles[0] == obstacles[n] == 0</code></li>
</ul>


    
## 方法一：动态规划

也不用先像其他题解那样先考虑普通的DP再考虑如何原地滚动压缩优化到$O(1)$空间，直接考虑使用三个整型变量来当DP数组即可

dp[i]表示进行到当前距离时，若青蛙位于第i道上 的最小总横跳次数。

初始时青蛙的前进距离是0，并且位于中间的一道，因此初始值$dp[3] = {1, 0, 1}$

接着从起点的下一个位置遍历“障碍数组”，每次遍历时，我们分为两边：

1. 计算出到达这个前进距离所需的最小横跳次数
2. 更新三条跑道到这个前近距离的最小横跳次数

```cpp
for (int i = 1; i < obstacles.size(); i++) {
	int minStep = 999999;
	// 计算出到达这个前进距离所需的最小横跳次数

	// 更新三条跑道到这个前近距离的最小横跳次数
}
```

最终，返回三条跑道的最小值即可。

+ 时间复杂度$O(len(obstacles))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[3] = {1, 0, 1};
        for (int i = 1; i < obstacles.size(); i++) {
            int minStep = 999999;
            for (int j = 0; j < 3; j++) {  // 计算出到达这个前进距离所需的最小横跳次数
                if (obstacles[i] == j + 1) {  // 若有障碍则不可达，记为“无穷大”
                    dp[j] = 999999;
                }
                else {
                    minStep = min(minStep, dp[j]);
                }
            }
            for (int j = 0; j < 3; j++) {  // 更新三条跑道到这个前近距离的最小横跳次数
                if (obstacles[i] != j + 1) {  // 若此处非障碍，则可由此前进距离的另外两条跑道横跳而来
                    dp[j] = min(dp[j], minStep + 1);
                }
            }
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};
```

#### Python

```python
class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        dp = [1, 0, 1]
        for i in range(1, len(obstacles)):
            minStep = 999999
            for j in range(3):
                if obstacles[i] == j + 1:
                    dp[j] = 999999
                else:
                    minStep = min(minStep, dp[j])
            for j in range(3):
                if obstacles[i] != j + 1:
                    dp[j] = min(dp[j], minStep + 1)
        return min(dp)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/21/LeetCode%201824.%E6%9C%80%E5%B0%91%E4%BE%A7%E8%B7%B3%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128745707](https://letmefly.blog.csdn.net/article/details/128745707)
