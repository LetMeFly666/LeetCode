---
title: 1594.矩阵的最大非负积：动态规划O(mn)
date: 2026-03-23 22:00:25
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】1594.矩阵的最大非负积：动态规划O(mn)

力扣题目链接：[https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/](https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/)

<p>给你一个大小为 <code>m x n</code> 的矩阵 <code>grid</code> 。最初，你位于左上角 <code>(0, 0)</code> ，每一步，你可以在矩阵中 <strong>向右</strong> 或 <strong>向下</strong> 移动。</p>

<p>在从左上角 <code>(0, 0)</code> 开始到右下角 <code>(m - 1, n - 1)</code> 结束的所有路径中，找出具有 <strong>最大非负积</strong> 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。</p>

<p>返回 <strong>最大非负积 </strong>对<strong><em> </em><code>10<sup>9</sup>&nbsp;+ 7</code></strong> <strong>取余</strong> 的结果。如果最大积为 <strong>负数</strong> ，则返回<em> </em><code>-1</code> 。</p>

<p><strong>注意，</strong>取余是在得到最大积之后执行的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/23/product1.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
<strong>输出：</strong>-1
<strong>解释：</strong>从 (0, 0) 到 (2, 2) 的路径中无法得到非负积，所以返回 -1 。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/23/product2.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
<strong>输出：</strong>8
<strong>解释：</strong>最大非负积对应的路径如图所示 (1 * 1 * -2 * -4 * 1 = 8)
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/12/23/product3.jpg" style="width: 164px; height: 165px;" />
<pre>
<strong>输入：</strong>grid = [[1,3],[0,-4]]
<strong>输出：</strong>0
<strong>解释：</strong>最大非负积对应的路径如图所示 (1 * 0 * -4 = 0)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 15</code></li>
	<li><code>-4 &lt;= grid[i][j] &lt;= 4</code></li>
</ul>


    
## 解题方法：动态规划

使用两个和grid等大的数组实时记录下每个位置的最大最小值就好了。

+ 如果$grid[i][j]\geq 0$，则：

    + $maximum[i][j] = \max(left, up)\times grid[i][j]$
    + $minimum[i][j] = \min(left,up)\times grid[i][j]$

+ 如果$grd[i][j]\lt 0$，则：

    + $maximum[i][j] = \min(left, up)\times grid[i][j]$
    + $minimum[i][j] = \max(left, up)\times grid[i][j]$

以上。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-23 22:00:02
 */
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> maximum(n, vector<ll>(m));
        vector<vector<ll>> minimum(n, vector<ll>(m));

        maximum[0][0] = minimum[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maximum[i][0] = minimum[i][0] = maximum[i - 1][0] * grid[i][0];
        }
        for (int j = 1; j < m; j++) {
            maximum[0][j] = minimum[0][j] = maximum[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] >= 0) {
                    maximum[i][j] = max(maximum[i][j - 1], maximum[i - 1][j]) * grid[i][j];
                    minimum[i][j] = min(minimum[i][j - 1], minimum[i - 1][j]) * grid[i][j];
                } else {
                    maximum[i][j] = min(minimum[i][j - 1], minimum[i - 1][j]) * grid[i][j];
                    minimum[i][j] = max(maximum[i][j - 1], maximum[i - 1][j]) * grid[i][j];
                }
            }
        }

        return maximum[n - 1][m - 1] >= 0 ? maximum[n - 1][m - 1] % MOD : -1;
    }
};

#ifdef _DEBUG
/*
[[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]

之前的逻辑：
ll left_max = j ? maximum[i][j - 1] : 1;
ll left_min = j ? minimum[i][j - 1] : 1;
ll up_max = i ? maximum[i - 1][j] : 1;
ll up_min = i ? minimum[i - 1][j] : 1;
minimum[i][j] = max(left_max, up_max) * grid[i][j];  // when grid[i][j] < 0
错在：
-1 -2
在-2时候，min和max都应该是2，但是max(-1, 1)会导致计算结果为-2。

-1
*/
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        vector<vector<int>> v = stringToVectorVector(s);
        cout << sol.maxProductPath(v) << endl;
    }
    return 0;
}
#endif

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159396105)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/23/LeetCode%201594.%E7%9F%A9%E9%98%B5%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%9E%E8%B4%9F%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
