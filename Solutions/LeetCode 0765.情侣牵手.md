---
title: 765.情侣牵手
date: 2023-11-11 22:54:27
tags: [题解, LeetCode, 困难, 贪心, 深度优先搜索, 广度优先搜索, BFS, 并查集, 图]
---

# 【LetMeFly】765.情侣牵手：广度优先搜索BFS

力扣题目链接：[https://leetcode.cn/problems/couples-holding-hands/](https://leetcode.cn/problems/couples-holding-hands/)

<p><code>n</code> 对情侣坐在连续排列的 <code>2n</code>&nbsp;个座位上，想要牵到对方的手。</p>

<p>人和座位由一个整数数组 <code>row</code> 表示，其中 <code>row[i]</code> 是坐在第 <code>i </code>个座位上的人的 <strong>ID</strong>。情侣们按顺序编号，第一对是&nbsp;<code>(0, 1)</code>，第二对是&nbsp;<code>(2, 3)</code>，以此类推，最后一对是&nbsp;<code>(2n-2, 2n-1)</code>。</p>

<p>返回 <em>最少交换座位的次数，以便每对情侣可以并肩坐在一起</em>。 <i>每次</i>交换可选择任意两人，让他们站起来交换座位。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> row = [0,2,1,3]
<strong>输出:</strong> 1
<strong>解释:</strong> 只需要交换row[1]和row[2]的位置即可。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> row = [3,2,0,1]
<strong>输出:</strong> 0
<strong>解释:</strong> 无需交换座位，所有的情侣都已经可以手牵手了。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2n == row.length</code></li>
	<li><code>2 &lt;= n &lt;= 30</code></li>
	<li><code>n</code>&nbsp;是偶数</li>
	<li><code>0 &lt;= row[i] &lt; 2n</code></li>
	<li><code>row</code>&nbsp;中所有元素均<strong>无重复</strong></li>
</ul>


    
## 方法一：广度优先搜索BFS

首先我们可以把“0号1号”都看成“0号”、“2号3号”都看成“1号”、“4号5号”都看成“2号”、...、“$2n$号$2n+1$号”看成“$n$号”。

接下来讨论坐错的情况下，需要交换的次数：
   + 假设一对情侣坐在一起```(0, 0)```，则需要交换$0$次
   + 假设两对情侣坐错了```(0, 1) (1, 0)```，则需要交换$1$次
   + 假设三对情侣坐错了```(0, 1) (1, 2) (2, 0)```，则需要交换$2$次
   + ...
   + 假设n对情侣坐错了，则需要交换$n-1$次

因此我们的任务就是，将所有的人分成数个“循环情侣坐错环”。

怎么做呢？我们只需要建一张图，假设当前```(0, 1)```在一起，则在图中将点```0```和点```1```相连。

这样，我们只需要尝试从每个点开始广度优先搜索，就能得到每个子图的大小。每个子图的大小减一即为这个子图需要交换的次数。

```
座位情况：
3 3 0 1 1 2 4 5 2 0 4 5
--- --- --- --- --- ---

图的边：
3-3
0-1
1-2
4-5
2-0

子图：
3   0-1-2   4-5

需要交换次数：
(1-1) + (3-1) + (2-1) = 3
```

+ 时间复杂度$O(len(row))$
+ 空间复杂度$O(len(row))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        vector<vector<int>> graph(row.size() / 2);
        for (int i = 0; i < row.size(); i += 2) {
            graph[row[i] / 2].push_back(row[i + 1] / 2);
            graph[row[i + 1] / 2].push_back(row[i] / 2);
        }
        vector<bool> visited(row.size() / 2, false);
        queue<int> q;
        for (int i = 0; i < row.size() / 2; i++) {
            if (visited[i]) {
                continue;
            }
            q.push(i);
            visited[i] = true;
            int thisCnt = 0;
            while (q.size()) {
                thisCnt++;
                int thisPeople = q.front();
                q.pop();
                for (int nextPeople : graph[thisPeople]) {
                    if (!visited[nextPeople]) {
                        visited[nextPeople] = true;
                        q.push(nextPeople);
                    }
                }
            }
            ans += thisCnt - 1;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        graph = [[] for _ in range(len(row) // 2)]
        for i in range(0, len(row), 2):
            graph[row[i] // 2].append(row[i + 1] // 2)
            graph[row[i + 1] // 2].append(row[i] // 2)
        visited = [False] * (len(row) // 2)
        ans = 0
        for i in range(len(row) // 2):
            if visited[i]:
                continue
            q = []
            q.append(i)
            visited[i] = True
            thisCnt = 0
            while q:
                thisCnt += 1
                thisPeople = q.pop()
                for nextPeople in graph[thisPeople]:
                    if not visited[nextPeople]:
                        visited[nextPeople] = True
                        q.append(nextPeople)
            ans += thisCnt - 1
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/11/11/LeetCode%200765.%E6%83%85%E4%BE%A3%E7%89%B5%E6%89%8B/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134355602](https://letmefly.blog.csdn.net/article/details/134355602)
