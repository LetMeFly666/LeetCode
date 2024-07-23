---
title: 2101.引爆最多的炸弹
date: 2024-07-23 10:30:52
tags: [题解, LeetCode, 中等, 深度优先搜索, DFS, 广度优先搜索, 图, 几何, 数组, 数学]
---

# 【LetMeFly】2101.引爆最多的炸弹：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/detonate-the-maximum-bombs/](https://leetcode.cn/problems/detonate-the-maximum-bombs/)

<p>给你一个炸弹列表。一个炸弹的 <strong>爆炸范围</strong>&nbsp;定义为以炸弹为圆心的一个圆。</p>

<p>炸弹用一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>bombs</code>&nbsp;表示，其中&nbsp;<code>bombs[i] = [x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub>]</code>&nbsp;。<code>x<sub>i</sub></code> 和&nbsp;<code>y<sub>i</sub></code>&nbsp;表示第 <code>i</code>&nbsp;个炸弹的 X 和 Y 坐标，<code>r<sub>i</sub></code>&nbsp;表示爆炸范围的 <strong>半径</strong>&nbsp;。</p>

<p>你需要选择引爆 <strong>一个&nbsp;</strong>炸弹。当这个炸弹被引爆时，<strong>所有</strong> 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。</p>

<p>给你数组&nbsp;<code>bombs</code>&nbsp;，请你返回在引爆&nbsp;<strong>一个</strong>&nbsp;炸弹的前提下，<strong>最多</strong>&nbsp;能引爆的炸弹数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/06/desmos-eg-3.png" style="width: 300px; height: 300px;"></p>

<pre><b>输入：</b>bombs = [[2,1,3],[6,1,4]]
<b>输出：</b>2
<strong>解释：</strong>
上图展示了 2 个炸弹的位置和爆炸范围。
如果我们引爆左边的炸弹，右边的炸弹不会被影响。
但如果我们引爆右边的炸弹，两个炸弹都会爆炸。
所以最多能引爆的炸弹数目是 max(1, 2) = 2 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/06/desmos-eg-2.png" style="width: 300px; height: 300px;"></p>

<pre><b>输入：</b>bombs = [[1,1,5],[10,10,5]]
<b>输出：</b>1
<strong>解释：
</strong>引爆任意一个炸弹都不会引爆另一个炸弹。所以最多能引爆的炸弹数目为 1 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/07/desmos-eg1.png" style="width: 300px; height: 300px;"></p>

<pre><b>输入：</b>bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
<b>输出：</b>5
<strong>解释：</strong>
最佳引爆炸弹为炸弹 0 ，因为：
- 炸弹 0 引爆炸弹 1 和 2 。红色圆表示炸弹 0 的爆炸范围。
- 炸弹 2 引爆炸弹 3 。蓝色圆表示炸弹 2 的爆炸范围。
- 炸弹 3 引爆炸弹 4 。绿色圆表示炸弹 3 的爆炸范围。
所以总共有 5 个炸弹被引爆。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= bombs.length&nbsp;&lt;= 100</code></li>
	<li><code>bombs[i].length == 3</code></li>
	<li><code>1 &lt;= x<sub>i</sub>, y<sub>i</sub>, r<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：深度优先搜索

首先，我们可以以每个炸弹为点建立一个有向图。如果炸弹i能引爆炸弹j，则建立一条由i指向j的边。两层循环遍历炸弹数组即可完成建图。（细节：可以使用距离的平方和半径的平方进行比较从而避免浮点数的出现）

有了这个图之后，我们就可以开始愉快地深搜了。以任意一个炸弹为起点开始深搜，搜索所有这个炸弹能到达的位置，即为点燃这个炸弹能引爆的所有炸弹的数量。从每个炸弹开始深搜，最大的能引爆数量即为所求。

+ 时间复杂度$O(len(bombs)^3)$，单次搜索复杂度最高可以达到$O(n^2)$
+ 空间复杂度$O(n^2)$，全连接图可以达到$O(n^2)$的空间复杂度

**进阶：** 有没有发现在搜索过程中很多计算是重复的？有没有方法避免？使用拓扑排序的变种？

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
private:
    vector<bool> visited;
    vector<vector<int>> graph;

    int dfs(int x) {
        visited[x] = true;
        int ans = 1;
        for (int nextNode : graph[x]) {
            if (!visited[nextNode]) {
                ans += dfs(nextNode);
            }
        }
        return ans;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        graph = vector<vector<int>>(n);
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = i + 1; j < bombs.size(); j++) {
                ll d2 = (ll)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (ll)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                if (d2 <= (ll)bombs[i][2] * bombs[i][2]) {  // i能引爆j
                    graph[i].push_back(j);
                }
                if (d2 <= (ll)bombs[j][2] * bombs[j][2]) {
                    graph[j].push_back(i);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            visited = vector<bool>(n);
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def dfs(self, x: int) -> int:
        self.visited[x] = True
        ans = 1
        for nextNode in self.graph[x]:
            if not self.visited[nextNode]:
                ans += self.dfs(nextNode)
        return ans

    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        self.graph = [[] for _ in range(len(bombs))]
        for i in range(len(bombs)):
            for j in range(i + 1, len(bombs)):
                d2 = (bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1])
                if d2 <= bombs[i][2] * bombs[i][2]:  # i能炸j
                    self.graph[i].append(j)
                if d2 <= bombs[j][2] * bombs[j][2]:
                    self.graph[j].append(i)
        
        ans = 1
        for i in range(len(bombs)):
            self.visited = [False] * len(bombs)
            ans = max(ans, self.dfs(i))
        return ans
```

#### Go

```go
package main

var visited []bool
var graph [][]int

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func dfs(x int) int {
    visited[x] = true
    ans := 1
    for _, nextNode := range graph[x] {
        if !visited[nextNode] {
            ans += dfs(nextNode)
        }
    }
    return ans
}

func maximumDetonation(bombs [][]int) int {
    n := len(bombs)
    graph = make([][]int, n)
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            d2 := (int64)(bombs[i][0] - bombs[j][0]) * (int64)(bombs[i][0] - bombs[j][0]) + (int64)(bombs[i][1] - bombs[j][1]) * (int64)(bombs[i][1] - bombs[j][1])
            if d2 <= (int64)(bombs[i][2]) * (int64)(bombs[i][2]) {
                graph[i] = append(graph[i], j)
            }
            if d2 <= (int64)(bombs[j][2]) * (int64)(bombs[j][2]) {
                graph[j] = append(graph[j], i)
            }
        }
    }

    ans := 1
    for i := 0; i < n; i++ {
        visited = make([]bool, n)
        ans = max(ans, dfs(i))
    }
    return ans
}
```

#### Java

```java

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private boolean[] visited;
    private List<Integer>[] graph;

    private int dfs(int x) {
        visited[x] = true;
        int ans = 1;
        for (int nextNode : graph[x]) {
            if (!visited[nextNode]) {
                ans += dfs(nextNode);
            }
        }
        return ans;
    }
    
    public int maximumDetonation(int[][] bombs) {
        int n = bombs.length;
        graph = new ArrayList[n];
        Arrays.setAll(graph, thisArray -> new ArrayList<>());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long d2 = (long)(bombs[i][0] - bombs[j][0]) * (bombs[i][0] - bombs[j][0]) + (long)(bombs[i][1] - bombs[j][1]) * (bombs[i][1] - bombs[j][1]);
                if (d2 <= (long)bombs[i][2] * bombs[i][2]) {
                    graph[i].add(j);
                }
                if (d2 <= (long)bombs[j][2] * bombs[j][2]) {
                    graph[j].add(i);
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            visited = new boolean[n];
            ans = Math.max(ans, dfs(i));
        }
        return ans;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/23/LeetCode%202101.%E5%BC%95%E7%88%86%E6%9C%80%E5%A4%9A%E7%9A%84%E7%82%B8%E5%BC%B9/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140629296](https://letmefly.blog.csdn.net/article/details/140629296)
