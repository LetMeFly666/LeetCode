---
title: 1329.将矩阵按对角线排序
date: 2024-04-29 23:55:09
tags: [题解, LeetCode, 中等, 数组, 矩阵, 排序]
---

# 【LetMeFly】1329.将矩阵按对角线排序：模拟——O(m+n)

力扣题目链接：[https://leetcode.cn/problems/sort-the-matrix-diagonally/](https://leetcode.cn/problems/sort-the-matrix-diagonally/)

<p><strong>矩阵对角线</strong> 是一条从矩阵最上面行或者最左侧列中的某个元素开始的对角线，沿右下方向一直到矩阵末尾的元素。例如，矩阵 <code>mat</code> 有 <code>6</code> 行 <code>3</code> 列，从 <code>mat[2][0]</code> 开始的 <strong>矩阵对角线</strong> 将会经过 <code>mat[2][0]</code>、<code>mat[3][1]</code> 和 <code>mat[4][2]</code> 。</p>

<p>给你一个 <code>m * n</code> 的整数矩阵 <code>mat</code> ，请你将同一条 <strong>矩阵对角线 </strong>上的元素按升序排序后，返回排好序的矩阵。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/25/1482_example_1_2.png" style="height: 198px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
<strong>输出：</strong>[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
<strong>输出：</strong>[[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 <= m, n <= 100</code></li>
	<li><code>1 <= mat[i][j] <= 100</code></li>
</ul>


    
## 解题方法：模拟

对角线的起点有哪些？起点为第一行和第一列的元素。

从**每个**起点开始向右下方遍历（横纵坐标各加一），将遍历到的元素加入数组中并排序，再次遍历并将排序后数组中的元素赋值给矩阵。

至此，排序已成。

+ 时间复杂度$O((n+m)\log(n + m))$
+ 空间复杂度$O(m + m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        // start point
        vector<pair<int, int>> startPoints;
        for (int j = 0; j < m; j++) {
            startPoints.push_back({0, j});
        }
        for (int i = 1; i < n; i++) {
            startPoints.push_back({i, 0});
        }
        // each line
        for (auto [x, y] : startPoints) {
            vector<int> vals;
            int i = x, j = y;
            while (i < n && j < m) {
                vals.push_back(mat[i++][j++]);
            }
            sort(vals.begin(), vals.end());
            int index = 0;
            i = x, j = y;
            while (i < n && j < m) {
                mat[i++][j++] = vals[index++];
            }
        }
        return mat;
    }
};
```

#### Python

```python
class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        startPoints = []
        for j in range(m):
            startPoints.append((0, j))
        for i in range(1, n):
            startPoints.append((i, 0))
        for thisPoint in startPoints:
            i, j = thisPoint
            vals = []
            while i < n and j < m:
                vals.append(mat[i][j])
                i += 1
                j += 1
            vals.sort()
            index = 0
            i, j = thisPoint
            while i < n and j < m:
                mat[i][j] = vals[index]
                i += 1
                j += 1
                index += 1
        return mat
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/29/LeetCode%201329.%E5%B0%86%E7%9F%A9%E9%98%B5%E6%8C%89%E5%AF%B9%E8%A7%92%E7%BA%BF%E6%8E%92%E5%BA%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138329644](https://letmefly.blog.csdn.net/article/details/138329644)
