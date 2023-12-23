---
title: 1962.移除石子使总数最小
date: 2023-12-23 09:46:19
tags: [题解, LeetCode, 中等, 数组, 堆（优先队列）, 堆, 优先队列, 贪心]
---

# 【LetMeFly】1962.移除石子使总数最小：优先队列（大根堆）

力扣题目链接：[https://leetcode.cn/problems/remove-stones-to-minimize-the-total/](https://leetcode.cn/problems/remove-stones-to-minimize-the-total/)

<p>给你一个整数数组 <code>piles</code> ，数组 <strong>下标从 0 开始</strong> ，其中 <code>piles[i]</code> 表示第 <code>i</code> 堆石子中的石子数量。另给你一个整数 <code>k</code> ，请你执行下述操作 <strong>恰好</strong> <code>k</code> 次：</p>

<ul>
	<li>选出任一石子堆 <code>piles[i]</code> ，并从中 <strong>移除</strong> <code>floor(piles[i] / 2)</code> 颗石子。</li>
</ul>

<p><strong>注意：</strong>你可以对 <strong>同一堆</strong> 石子多次执行此操作。</p>

<p>返回执行 <code>k</code> 次操作后，剩下石子的 <strong>最小</strong> 总数。</p>

<p><code>floor(x)</code> 为 <strong>小于</strong> 或 <strong>等于</strong> <code>x</code> 的 <strong>最大</strong> 整数。（即，对 <code>x</code> 向下取整）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>piles = [5,4,9], k = 2
<strong>输出：</strong>12
<strong>解释：</strong>可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [5,4,<strong><em>5</em></strong>] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [<strong><em>3</em></strong>,4,5] 。
剩下石子的总数为 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>piles = [4,3,6,7], k = 3
<strong>输出：</strong>12
<strong>解释：</strong>可能的执行情景如下：
- 对第 2 堆石子执行移除操作，石子分布情况变成 [4,3,<strong><em>3</em></strong>,7] 。
- 对第 3 堆石子执行移除操作，石子分布情况变成 [4,3,3,<strong><em>4</em></strong>] 。
- 对第 0 堆石子执行移除操作，石子分布情况变成 [<strong><em>2</em></strong>,3,3,4] 。
剩下石子的总数为 12 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：优先队列（大根堆）

使用一个大根堆（优先队列），大的元素在前。每次从队列中弹出最大的元素t，并将$\lceil\frac{t}{2}\rceil$重新放入队列中。

最终返回数列中元素之和。

+ 时间复杂度$O(k\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            int t = pq.top();
            pq.pop();
            pq.push((t + 1) / 2);
            ans -= t / 2;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# import heapq

class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        for i in range(len(piles)):
            piles[i] *= -1
        heapq.heapify(piles)
        for _ in range(k):
            heapq.heapreplace(piles, piles[0] // 2)  # 负数向下取整 = 负的 正数向上取整
        return -sum(piles)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/12/23/LeetCode%201962.%E7%A7%BB%E9%99%A4%E7%9F%B3%E5%AD%90%E4%BD%BF%E6%80%BB%E6%95%B0%E6%9C%80%E5%B0%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135165032](https://letmefly.blog.csdn.net/article/details/135165032)
