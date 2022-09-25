---
title: 329.矩阵中的最长递增路径
date: 2022-09-25 20:50:43
tags: [题解, LeetCode, 困难, 深度优先搜索, 广度优先搜索, 图, 拓扑排序, 记忆化搜索, 动态规划, 排序]
---

# 【LetMeFly】329.矩阵中的最长递增路径：从大到小处理的动态规划

力扣题目链接：[https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/)

<p>给定一个 <code>m x n</code> 整数矩阵 <code>matrix</code> ，找出其中 <strong>最长递增路径</strong> 的长度。</p>

<p>对于每个单元格，你可以往上，下，左，右四个方向移动。 你 <strong>不能</strong> 在 <strong>对角线</strong> 方向上移动或移动到 <strong>边界外</strong>（即不允许环绕）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[9,9,4],[6,6,8],[2,1,1]]
<strong>输出：</strong>4 
<strong>解释：</strong>最长递增路径为 <code>[1, 2, 6, 9]</code>。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>matrix = [[3,4,5],[3,2,6],[2,2,1]]
<strong>输出：</strong>4 
<strong>解释：</strong>最长递增路径是 <code>[3, 4, 5, 6]</code>。注意不允许在对角线方向上移动。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1]]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 200</code></li>
	<li><code>0 <= matrix[i][j] <= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：从大到小处理的动态规划

因为路径必须是严格递增的，因此如果从地图中最大的值开始，“最长递增路径”就是“1”（因为没有比它更大的了）

处理完最大的数，我们就可以处理“第二大”的数了。第二大的数**四**周如果有第一大的数，那么从这个第二大的数开始出发，“最长递增路径”为“2”

接着我们可以处理第三大的数、第四大的数、……

总之，只需要将原始地图中的元素按从大到小的顺序排个序（注意排序过程中，元素在地图中的原始位置信息不要丢失），就能从大到小开始遍历。遍历到一个数时，看这个数的四周有没有比它大的数，如果有，从这个数出发的“最长递增路径”就*可以*是“从它旁边比它大的数出发的最长路径 + 1”

整个过程中，不断更新“从某个点出发的最长递增路径”的最大值 即为答案。

+ 时间复杂度$O(m n)$
+ 空间复杂度$O(m n\times \log (m n))$

### AC代码

#### C++

```cpp
struct MyNode {
    int x, y;
    int val;
};

bool cmp(const MyNode& a, const MyNode& b) {
    return a.val > b.val;
}

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<MyNode> nodes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nodes.push_back({i, j, matrix[i][j]});
            }
        }
        sort(nodes.begin(), nodes.end(), cmp);
        vector<vector<int>> dp(n, vector<int>(m, 1));
        int ans = 1;
        for (MyNode thisNode : nodes) {
            int x = thisNode.x, y = thisNode.y;
            int val = thisNode.val;
            for (int d = 0; d < 4; d++) {
                int tx = x + directions[d][0];
                int ty = y + directions[d][1];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (matrix[tx][ty] > val) {
                        dp[x][y] = max(dp[x][y], dp[tx][ty] + 1);
                    }
                }
            }
            ans = max(ans, dp[x][y]);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/25/LeetCode%200329.%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E8%B7%AF%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127043063](https://letmefly.blog.csdn.net/article/details/127043063)
