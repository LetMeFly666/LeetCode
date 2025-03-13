---
title: 2959.关闭分部的可行集合数目
date: 2024-07-17 22:56:28
tags: [题解, LeetCode, 困难, 位运算, 图, 枚举, 二进制枚举, 最短路, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】2959.关闭分部的可行集合数目：二进制枚举+Floyd算法

力扣题目链接：[https://leetcode.cn/problems/number-of-possible-sets-of-closing-branches/](https://leetcode.cn/problems/number-of-possible-sets-of-closing-branches/)

<p>一个公司在全国有 <code>n</code>&nbsp;个分部，它们之间有的有道路连接。一开始，所有分部通过这些道路两两之间互相可以到达。</p>

<p>公司意识到在分部之间旅行花费了太多时间，所以它们决定关闭一些分部（<b>也可能不关闭任何分部</b>），同时保证剩下的分部之间两两互相可以到达且最远距离不超过&nbsp;<code>maxDistance</code>&nbsp;。</p>

<p>两个分部之间的 <strong>距离</strong> 是通过道路长度之和的 <strong>最小值</strong>&nbsp;。</p>

<p>给你整数&nbsp;<code>n</code>&nbsp;，<code>maxDistance</code>&nbsp;和下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>roads</code>&nbsp;，其中&nbsp;<code>roads[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code>&nbsp;表示一条从&nbsp;<code>u<sub>i</sub></code>&nbsp;到&nbsp;<code>v<sub>i</sub></code>&nbsp;长度为&nbsp;<code>w<sub>i</sub></code>的&nbsp;<strong>无向</strong>&nbsp;道路。</p>

<p>请你返回关闭分部的可行方案数目，满足每个方案里剩余分部之间的最远距离不超过<em>&nbsp;</em><code>maxDistance</code>。</p>

<p><strong>注意</strong>，关闭一个分部后，与之相连的所有道路不可通行。</p>

<p><b>注意</b>，两个分部之间可能会有多条道路。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/08/example11.png" style="width: 221px; height: 191px;" /></p>

<pre>
<b>输入：</b>n = 3, maxDistance = 5, roads = [[0,1,2],[1,2,10],[0,2,10]]
<b>输出：</b>5
<b>解释：</b>可行的关闭分部方案有：
- 关闭分部集合 [2] ，剩余分部为 [0,1] ，它们之间的距离为 2 。
- 关闭分部集合 [0,1] ，剩余分部为 [2] 。
- 关闭分部集合 [1,2] ，剩余分部为 [0] 。
- 关闭分部集合 [0,2] ，剩余分部为 [1] 。
- 关闭分部集合 [0,1,2] ，关闭后没有剩余分部。
总共有 5 种可行的关闭方案。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/08/example22.png" style="width: 221px; height: 241px;" /></p>

<pre>
<b>输入：</b>n = 3, maxDistance = 5, roads = [[0,1,20],[0,1,10],[1,2,2],[0,2,2]]
<b>输出：</b>7
<b>解释：</b>可行的关闭分部方案有：
- 关闭分部集合 [] ，剩余分部为 [0,1,2] ，它们之间的最远距离为 4 。
- 关闭分部集合 [0] ，剩余分部为 [1,2] ，它们之间的距离为 2 。
- 关闭分部集合 [1] ，剩余分部为 [0,2] ，它们之间的距离为 2 。
- 关闭分部集合 [0,1] ，剩余分部为 [2] 。
- 关闭分部集合 [1,2] ，剩余分部为 [0] 。
- 关闭分部集合 [0,2] ，剩余分部为 [1] 。
- 关闭分部集合 [0,1,2] ，关闭后没有剩余分部。
总共有 7 种可行的关闭方案。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>n = 1, maxDistance = 10, roads = []
<b>输出：</b>2
<b>解释：</b>可行的关闭分部方案有：
- 关闭分部集合 [] ，剩余分部为 [0] 。
- 关闭分部集合 [0] ，关闭后没有剩余分部。
总共有 2 种可行的关闭方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= maxDistance &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= roads.length &lt;= 1000</code></li>
	<li><code>roads[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= 1000</code></li>
	<li>一开始所有分部之间通过道路互相可以到达。</li>
</ul>


    
## 解题方法：二进制枚举+Floyd算法

不难发现最多一共10个点，因此可以使用二进制枚举每个分公司是否被移除的情况，最多有$2^{10}=1024$种可能。

对于每种情况，对没被移除的公式应用一下Flody算法即可得到任意两点之间的最短距离，就能判断这种移法是否可行。

+ 时间复杂度$O(2^n\times n^3)$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<bool> remain;
    vector<vector<int>> graph, distances;

    // 计算remain状态下任意被保留的两点之间的最短距离 并将结果保存在distances中
    void floyd() {
        for (int k = 0; k < remain.size(); k++) {
            if (!remain[k]) {
                continue;
            }
            for (int i = 0; i < remain.size(); i++) {
                if (!remain[i]) {
                    continue;
                }
                for (int j = 0; j < remain.size(); j++) {
                    if (!remain[j]) {
                        continue;
                    }
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }
    }
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        graph = vector<vector<int>>(n, vector<int>(n, 100001));
        remain.resize(n);
        for (vector<int>& road : roads) {
            graph[road[1]][road[0]] = graph[road[0]][road[1]] = min(graph[road[0]][road[1]], road[2]);
        }
        int ans = 0;
        for (int state = 0; state < (1 << n); state++) {
            for (int i = 0; i < n; i++) {
                remain[i] = state & (1 << i);
            }
            distances = graph;
            floyd();
            for (int i = 0; i < n; i++) {
                if (!remain[i]) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    if (!remain[j]) {
                        continue;
                    }
                    if (distances[i][j] > maxDistance) {
                        goto loop;
                    }
                }
            }
            ans++;
            loop:;
        }
        return ans;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/17/LeetCode%202959.%E5%85%B3%E9%97%AD%E5%88%86%E9%83%A8%E7%9A%84%E5%8F%AF%E8%A1%8C%E9%9B%86%E5%90%88%E6%95%B0%E7%9B%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140507896](https://letmefly.blog.csdn.net/article/details/140507896)
