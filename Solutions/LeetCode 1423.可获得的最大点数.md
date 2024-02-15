---
title: 1423.可获得的最大点数
date: 2023-12-03 14:01:12
tags: [题解, LeetCode, 中等, 数组, 前缀和, 滑动窗口]
---

# 【LetMeFly】1423.可获得的最大点数：滑动窗口

力扣题目链接：[https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/](https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/)

<p>几张卡牌<strong> 排成一行</strong>，每张卡牌都有一个对应的点数。点数由整数数组 <code>cardPoints</code> 给出。</p>

<p>每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 <code>k</code> 张卡牌。</p>

<p>你的点数就是你拿到手中的所有卡牌的点数之和。</p>

<p>给你一个整数数组 <code>cardPoints</code> 和整数 <code>k</code>，请你返回可以获得的最大点数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>cardPoints = [1,2,3,4,5,6,1], k = 3
<strong>输出：</strong>12
<strong>解释：</strong>第一次行动，不管拿哪张牌，你的点数总是 1 。但是，先拿最右边的卡牌将会最大化你的可获得点数。最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>cardPoints = [2,2,2], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>无论你拿起哪两张卡牌，可获得的点数总是 4 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>cardPoints = [9,7,7,9,7,7,9], k = 7
<strong>输出：</strong>55
<strong>解释：</strong>你必须拿起所有卡牌，可以获得的点数为所有卡牌的点数之和。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>cardPoints = [1,1000,1], k = 1
<strong>输出：</strong>1
<strong>解释：</strong>你无法拿到中间那张卡牌，所以可以获得的最大点数为 1 。 
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>cardPoints = [1,79,80,1,1,1,200,1], k = 3
<strong>输出：</strong>202
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cardPoints.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= cardPoints[i] &lt;= 10^4</code></li>
	<li><code>1 &lt;= k &lt;= cardPoints.length</code></li>
</ul>


    
## 方法一：滑动窗口

要选开头和结尾的元素共k个问最大总和是多少，就相当于从任意位置选$n-k$个问最小总和是多少（再使用数组总和减去这$n-k$个的总和）。

因此我们使用滑动窗口即可：

> 计算前$n-k$个元素的和作为“窗口”。
>
> 在窗口未达到数组末尾时，每次窗口向右滑动一个元素。窗口中元素的总和 加上新进入窗口的元素 减去刚离开窗口的元素，即为新的$n-k$个元素的和。
>
> 整个移动过程中取一个$min$即可。

+ 时间复杂度$O(n)$，其中$n=len(cardPoints)$
+ 空间复杂度$O(n-k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = cardPoints.size() - k;
        int cnt = 0;
        int s = 0;
        for (int i = 0; i < l; i++) {
            cnt += cardPoints[i];
            s += cardPoints[i];
        }
        int m = cnt;
        for (int i = l; i < cardPoints.size(); i++) {
            cnt += cardPoints[i] - cardPoints[i - l];
            m = min(m, cnt);
            s += cardPoints[i];
        }
        return s - m;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        l = len(cardPoints) - k
        cnt = 0
        s = 0
        for i in range(l):
            cnt += cardPoints[i]
            s += cardPoints[i]
        m = cnt
        for i in range(l, len(cardPoints)):
            cnt += cardPoints[i] - cardPoints[i - l]
            m = min(m, cnt)
            s += cardPoints[i]
        return s - m
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/03/LeetCode%201423.%E5%8F%AF%E8%8E%B7%E5%BE%97%E7%9A%84%E6%9C%80%E5%A4%A7%E7%82%B9%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134764681](https://letmefly.blog.csdn.net/article/details/134764681)
