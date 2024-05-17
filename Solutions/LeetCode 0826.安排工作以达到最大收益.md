---
title: 826.安排工作以达到最大收益
date: 2024-05-17 17:06:47
tags: [题解, LeetCode, 中等, 贪心, 数组, 双指针, 二分查找, 排序]
---

# 【LetMeFly】826.安排工作以达到最大收益：排序 + 双指针

力扣题目链接：[https://leetcode.cn/problems/most-profit-assigning-work/](https://leetcode.cn/problems/most-profit-assigning-work/)

<p>你有 <code>n</code>&nbsp;个工作和 <code>m</code> 个工人。给定三个数组：&nbsp;<code>difficulty</code>,&nbsp;<code>profit</code>&nbsp;和&nbsp;<code>worker</code>&nbsp;，其中:</p>

<ul>
	<li><code>difficulty[i]</code>&nbsp;表示第 <code>i</code> 个工作的难度，<code>profit[i]</code> 表示第 <code>i</code> 个工作的收益。</li>
	<li><code>worker[i]</code> 是第 <code>i</code> 个工人的能力，即该工人只能完成难度小于等于 <code>worker[i]</code> 的工作。</li>
</ul>

<p>每个工人&nbsp;<strong>最多</strong> 只能安排 <strong>一个</strong> 工作，但是一个工作可以 <strong>完成多次</strong> 。</p>

<ul>
	<li>举个例子，如果 3 个工人都尝试完成一份报酬为 <code>$1</code> 的同样工作，那么总收益为 <code>$3</code>&nbsp;。如果一个工人不能完成任何工作，他的收益为 <code>$0</code> 。</li>
</ul>

<p>返回 <em>在把工人分配到工作岗位后，我们所能获得的最大利润&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
<strong>输出: </strong>100 
<strong>解释: </strong>工人被分配的工作难度是 [4,4,6,6] ，分别获得 [20,20,30,30] 的收益。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
<strong>输出:</strong> 0</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == difficulty.length</code></li>
	<li><code>n == profit.length</code></li>
	<li><code>m == worker.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= difficulty[i], profit[i], worker[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：排序 + 双指针

由已知：

1. 收益和难度无关、
1. 每个任务能完成无限次，

可得：

+ 每个工人要完成的工作都是“难度≤其能力的所有工作中收益最大的那个”。

二话不说开始排序：

+ 将工作按照难度从小到大的顺序排序、
+ 将工人按照能力从小到大的顺序排序。

接着开始遍历工人，同时使用变量$M$记录这个工人能完成的所有任务中收益最大的那个（初始值为$0$），使用变量$it$记录最多能完成到哪个工作（或者说$it$是第一个不能完成的工作的下标）：

> 当前工作都能胜任时不断后移$it$，同时更新$M$的最大值，直到遇到一个不能胜任的工作为止，
> 
> 那么这个工人的最大收益就是$M$。

**原理技巧：**

1. 排序后，前一个工人能完成的任务，后一个工人（能力相同或更强）一定能完成。因此后一个工人能在前一个工人的基础上更快得到结果。
2. 可以偷偷新增一个“无穷难”的工作，使得没有工人可以完成。这样就不用考虑$it$越界的问题了。

### 时空复杂度

+ 时间复杂度$O(n\log n+m\log m)$
+ 空间复杂度$O(n+\log m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> a(difficulty.size());
        for (int i = 0; i < difficulty.size(); i++) {
            a[i] = {difficulty[i], profit[i]};
        }
        sort(a.begin(), a.end());
        a.push_back({1000000, 0});
        sort(worker.begin(), worker.end());
        int M = 0;  // 能完成的任务里面收益最大的
        int ans = 0;
        for (int i = 0, it = 0; i < worker.size(); i++) {
            while (a[it].first <= worker[i]) {
                M = max(a[it].second, M);
                it++;
            }
            ans += M;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        a = sorted(zip(difficulty, profit)) + [(1000000, 0)]
        worker.sort()
        M = 0
        ans = 0
        it = 0
        for thisWorker in worker:
            while a[it][0] <= thisWorker:
                M = max(M, a[it][1])
                it += 1
            ans += M
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/17/LeetCode%200826.%E5%AE%89%E6%8E%92%E5%B7%A5%E4%BD%9C%E4%BB%A5%E8%BE%BE%E5%88%B0%E6%9C%80%E5%A4%A7%E6%94%B6%E7%9B%8A/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139009669](https://letmefly.blog.csdn.net/article/details/139009669)
