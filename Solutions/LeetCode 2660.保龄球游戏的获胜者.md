---
title: 2660.保龄球游戏的获胜者
date: 2023-12-27 15:08:27
tags: [题解, LeetCode, 简单, 数组, 模拟]
---

# 【LetMeFly】2660.保龄球游戏的获胜者：模拟

力扣题目链接：[https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/](https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/)

<p>给你两个下标从 <strong>0</strong> 开始的整数数组 <code>player1</code> 和 <code>player2</code> ，分别表示玩家 1 和玩家 2 击中的瓶数。</p>

<p>保龄球比赛由 <code>n</code> 轮组成，每轮的瓶数恰好为 <code>10</code> 。</p>

<p>假设玩家在第 <code>i</code> 轮中击中&nbsp;<code>x<sub>i</sub></code> 个瓶子。玩家第 <code>i</code> 轮的价值为：</p>

<ul>
	<li>如果玩家在该轮的前两轮的任何一轮中击中了 <code>10</code> 个瓶子，则为 <code>2x<sub>i</sub></code> 。</li>
	<li>否则，为&nbsp;<code>x<sub>i</sub></code> 。</li>
</ul>

<p>玩家的得分是其 <code>n</code> 轮价值的总和。</p>

<p>返回</p>

<ul>
	<li>如果玩家 1 的得分高于玩家 2 的得分，则为 <code>1</code> ；</li>
	<li>如果玩家 2 的得分高于玩家 1 的得分，则为 <code>2</code> ；</li>
	<li>如果平局，则为 <code>0</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>player1 = [4,10,7,9], player2 = [6,5,2,3]
<strong>输出：</strong>1
<strong>解释：</strong>player1 的得分是 4 + 10 + 2*7 + 2*9 = 46 。
player2 的得分是 6 + 5 + 2 + 3 = 16 。
player1 的得分高于 player2 的得分，所以 play1 在比赛中获胜，答案为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>player1 = [3,5,7,6], player2 = [8,10,10,2]
<strong>输出：</strong>2
<strong>解释：</strong>player1 的得分是 3 + 5 + 7 + 6 = 21 。
player2 的得分是 8 + 10 + 2*10 + 2*2 = 42 。
player2 的得分高于 player1 的得分，所以 play2 在比赛中获胜，答案为 2 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>player1 = [2,3], player2 = [4,1]
<strong>输出：</strong>0
<strong>解释：</strong>player1 的得分是 2 + 3 = 5 。
player2 的得分是 4 + 1 = 5 。
player1 的得分等于 player2 的得分，所以这一场比赛平局，答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == player1.length == player2.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= player1[i], player2[i] &lt;= 10</code></li>
</ul>


    
## 方法一：模拟

可以写一个函数```getScore```，用来计算一个“击球数组”的得分。

假设我们实现了这一函数，那么只需要计算出给定的两个数组的得分并进行比较即可。

这个函数怎么实现呢？

> 若得分数组的长度为1，直接返回$v[0]$即可
>
> 否则，答案的初始值是前两个元素的得分，从第3个元素（如有）开始遍历，并将得分累加到答案中即可

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int getScore(vector<int>& v) {  // v: 1~1000
        if (v.size() == 1) {
            return v[0];
        }
        int ans = v[0] + (v[0] == 10 ? 2 : 1) * v[1];
        for (int i = 2; i < v.size(); i++) {
            ans += (v[i - 1] == 10 || v[i - 2] == 10 ? 2 : 1) * v[i];
        }
        return ans;
    }
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int v1 = getScore(player1), v2 = getScore(player2);
        return v1 == v2 ? 0 : v1 < v2 ? 2 : 1;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def getScore(self, v: List[int]) -> int:
        if len(v) == 1:
            return v[0]
        ans = v[0] + (2 if v[0] == 10 else 1) * v[1]
        for i in range(2, len(v)):
            ans += (2 if v[i - 1] == 10 or v[i - 2] == 10 else 1) * v[i]
        return ans
    
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        v1, v2 = self.getScore(player1), self.getScore(player2)
        return 0 if v1 == v2 else 2 if v1 < v2 else 1
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/27/LeetCode%202660.%E4%BF%9D%E9%BE%84%E7%90%83%E6%B8%B8%E6%88%8F%E7%9A%84%E8%8E%B7%E8%83%9C%E8%80%85/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135247177](https://letmefly.blog.csdn.net/article/details/135247177)
