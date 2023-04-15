---
title: 1042.不邻接植花
date: 2023-04-15 12:22:56
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 图, 图染色]
---

# 【LetMeFly】1042.不邻接植花

力扣题目链接：[https://leetcode.cn/problems/flower-planting-with-no-adjacent/](https://leetcode.cn/problems/flower-planting-with-no-adjacent/)

<p>有 <code>n</code> 个花园，按从&nbsp;<code>1</code>&nbsp;到 <code>n</code> 标记。另有数组 <code>paths</code> ，其中 <code>paths[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;描述了花园&nbsp;<code>x<sub>i</sub></code> 到花园&nbsp;<code>y<sub>i</sub></code> 的双向路径。在每个花园中，你打算种下四种花之一。</p>

<p>另外，所有花园 <strong>最多</strong> 有 <strong>3</strong> 条路径可以进入或离开.</p>

<p>你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。</p>

<p><em>以数组形式返回 <strong>任一</strong> 可行的方案作为答案&nbsp;<code>answer</code>，其中&nbsp;<code>answer[i]</code>&nbsp;为在第&nbsp;<code>(i+1)</code>&nbsp;个花园中种植的花的种类。花的种类用 &nbsp;1、2、3、4 表示。保证存在答案。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, paths = [[1,2],[2,3],[3,1]]
<strong>输出：</strong>[1,2,3]
<strong>解释：</strong>
花园 1 和 2 花的种类不同。
花园 2 和 3 花的种类不同。
花园 3 和 1 花的种类不同。
因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2] 和 [3,2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, paths = [[1,2],[3,4]]
<strong>输出：</strong>[1,2,1,2]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
<strong>输出：</strong>[1,2,3,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= paths.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>paths[i].length == 2</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= n</code></li>
	<li><code>x<sub>i</sub> != y<sub>i</sub></code></li>
	<li>每个花园 <strong>最多</strong> 有 <strong>3</strong> 条路径可以进入或离开</li>
</ul>


    
## 方法一：图染色

首先需要明确的是，每个花园最多相邻三个另外的花园，而且有4种颜色的花可以种植，因此根本不需要考虑染色的顺序等问题，其他花园随便染，到我至少还剩一种颜色可以染。

所以这就好办了，首先将给定的路径建图，使得graph[i] = {a1, a2, ...}代表点i相邻的点为a1，a2，...

接下来使用答案数组ans，其中ans[i]代表第i个花园的花朵的颜色。

这样，我们只需要从0到n - 1遍历花园，对于某个花园i，我们统计出所有的与之相邻的花园的颜色，将这个花园的颜色赋值为周围花园未出现过的颜色即可。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(len(paths) + n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n);
        vector<vector<int>> graph(n);
        for (vector<int>& path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }
        for (int i = 0; i < n; i++) {
            bool already[5] = {false, false, false, false, false};
            for (int toPoint : graph[i]) {
                already[ans[toPoint]] = true;
            }
            for (int j = 1; j < 5; j++) {
                if (!already[j]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        ans = [0] * n
        graph = [[] for _ in range(n)]
        for path in paths:
            graph[path[0] - 1].append(path[1] - 1)
            graph[path[1] - 1].append(path[0] - 1)
        for i in range(n):
            visited = [False] * 5
            for toPoint in graph[i]:
                visited[ans[toPoint]] = True
            for j in range(1, 5):
                if not visited[j]:
                    ans[i] = j
                    break
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/04/15/LeetCode%201042.%E4%B8%8D%E9%82%BB%E6%8E%A5%E6%A4%8D%E8%8A%B1/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130168403](https://letmefly.blog.csdn.net/article/details/130168403)
