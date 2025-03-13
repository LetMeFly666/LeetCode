---
title: 2050.并行课程 III：DFS
date: 2023-07-28 09:24:33
tags: [题解, LeetCode, 困难, 图, 拓扑排序, 数组, 动态规划, 记忆化搜索, 搜索, 深度优先搜索, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】2050.并行课程 III：DFS

力扣题目链接：[https://leetcode.cn/problems/parallel-courses-iii/](https://leetcode.cn/problems/parallel-courses-iii/)

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示有&nbsp;<code>n</code>&nbsp;节课，课程编号从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;。同时给你一个二维整数数组&nbsp;<code>relations</code>&nbsp;，其中&nbsp;<code>relations[j] = [prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code>&nbsp;，表示课程&nbsp;<code>prevCourse<sub>j</sub></code>&nbsp;必须在课程&nbsp;<code>nextCourse<sub>j</sub></code>&nbsp;<strong>之前</strong>&nbsp;完成（先修课的关系）。同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>time</code>&nbsp;，其中&nbsp;<code>time[i]</code>&nbsp;表示完成第&nbsp;<code>(i+1)</code>&nbsp;门课程需要花费的 <strong>月份</strong>&nbsp;数。</p>

<p>请你根据以下规则算出完成所有课程所需要的 <strong>最少</strong>&nbsp;月份数：</p>

<ul>
	<li>如果一门课的所有先修课都已经完成，你可以在 <strong>任意</strong>&nbsp;时间开始这门课程。</li>
	<li>你可以&nbsp;<strong>同时</strong>&nbsp;上&nbsp;<strong>任意门课程</strong>&nbsp;。</li>
</ul>

<p>请你返回完成所有课程所需要的 <strong>最少</strong>&nbsp;月份数。</p>

<p><strong>注意：</strong>测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/10/07/ex1.png" style="width: 392px; height: 232px;"></strong></p>

<pre><strong>输入：</strong>n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
<b>输出：</b>8
<b>解释：</b>上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
你可以在月份 0 同时开始课程 1 和 2 。
课程 1 花费 3 个月，课程 2 花费 2 个月。
所以，最早开始课程 3 的时间是月份 3 ，完成所有课程所需时间为 3 + 5 = 8 个月。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/10/07/ex2.png" style="width: 500px; height: 365px;"></strong></p>

<pre><b>输入：</b>n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
<b>输出：</b>12
<b>解释：</b>上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
你可以在月份 0 同时开始课程 1 ，2 和 3 。
在月份 1，2 和 3 分别完成这三门课程。
课程 4 需在课程 3 之后开始，也就是 3 个月后。课程 4 在 3 + 4 = 7 月完成。
课程 5 需在课程 1，2，3 和 4 之后开始，也就是在 max(1,2,3,7) = 7 月开始。
所以完成所有课程所需的最少时间为 7 + 5 = 12 个月。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= relations.length &lt;= min(n * (n - 1) / 2, 5 * 10<sup>4</sup>)</code></li>
	<li><code>relations[j].length == 2</code></li>
	<li><code>1 &lt;= prevCourse<sub>j</sub>, nextCourse<sub>j</sub> &lt;= n</code></li>
	<li><code>prevCourse<sub>j</sub> != nextCourse<sub>j</sub></code></li>
	<li>所有的先修课程对&nbsp;<code>[prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]</code>&nbsp;都是 <strong>互不相同</strong>&nbsp;的。</li>
	<li><code>time.length == n</code></li>
	<li><code>1 &lt;= time[i] &lt;= 10<sup>4</sup></code></li>
	<li>先修课程图是一个有向无环图。</li>
</ul>


    
## 方法一：深度优先搜索（DFS）

这道题其实不难，无脑记忆化搜索就可以了。

首先建立一个邻接表pre，pre[i]记录课程i的所有先修课程，接着写一个函数dfs(n)，用来求课程n最早修完的日期。

公式：$课程i的最早完成时 = max(其先修课的最早完成时) + 课程i耗时$

```cpp
int dfs(n) {
    若已计算过n则直接返回

    int ans = 0;
    for (int thisPre : pre[n]) {
		ans = max(ans, dfs(thisPre));
	}
	ans += time[n];
	return ans;  // 返回并“记忆之”
}
```

+ 时间复杂度$O(n + len(relations))$
+ 空间复杂度$O(n + len(relations))$

### AC代码

#### Python

```python
# from typing import List
# from functools import cache

class Solution:
    @cache
    def dfs(self, n):
        if self.dp[n]:
            return self.dp[n]
        for thisPre in self.pre[n]:
            self.dp[n] = max(self.dp[n], self.dfs(thisPre))
        self.dp[n] += self.time[n]
        return self.dp[n]

    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        self.time = time
        self.dp = [0] * n
        self.pre = [[] for _ in range(n)]  # 这里不能写成[[]] * n！！！
        for thisPre, thisNext in relations:
            self.pre[thisNext - 1].append(thisPre - 1)
        return max(self.dfs(i) for i in range(n))
```

#### C++

```cpp
class Solution {
private:
    vector<vector<int>> pre;
    vector<int> dp;
    vector<int> time;

    int dfs(int n) {  // n从0开始
        if (dp[n]) {
            return dp[n];
        }
        for (int thisPre : pre[n]) {
            // printf("n = %d, thisPre = %d, max(%d", n, thisPre, dp[n]);  //******
            dp[n] = max(dp[n], dfs(thisPre));
            // printf(", %d) = %d\n", dfs(thisPre), dp[n]);  //*********
        }
        return (dp[n] += time[n]);
    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        this->time = time;
        pre.resize(n);
        dp.resize(n);
        for (vector<int>& relation : relations) {
            pre[relation[1] - 1].push_back(relation[0] - 1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
```

因Py代码较为简洁，故今日将Py代码置于了C艹前。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/28/LeetCode%202050.%E5%B9%B6%E8%A1%8C%E8%AF%BE%E7%A8%8BIII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131973511](https://letmefly.blog.csdn.net/article/details/131973511)
