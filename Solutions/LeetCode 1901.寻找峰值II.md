---
title: 1901.寻找峰值 II
date: 2023-12-19 13:44:49
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】1901.寻找峰值 II：二分查找

力扣题目链接：[https://leetcode.cn/problems/find-a-peak-element-ii/](https://leetcode.cn/problems/find-a-peak-element-ii/)

<p>一个 2D 网格中的 <strong>峰值</strong><strong> </strong>是指那些 <strong>严格大于 </strong>其相邻格子(上、下、左、右)的元素。</p>

<p>给你一个<strong> 从 0 开始编号 </strong>的 <code>m x n</code> 矩阵 <code>mat</code> ，其中任意两个相邻格子的值都<strong> 不相同</strong> 。找出 <strong>任意一个 峰值</strong> <code>mat[i][j]</code> 并 <strong>返回其位置 </strong><code>[i,j]</code> 。</p>

<p>你可以假设整个矩阵周边环绕着一圈值为 <code>-1</code> 的格子。</p>

<p>要求必须写出时间复杂度为 <code>O(m log(n))</code> 或 <code>O(n log(m))</code> 的算法</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/06/08/1.png" style="width: 206px; height: 209px;" /></p>

<pre>
<strong>输入:</strong> mat = [[1,4],[3,2]]
<strong>输出:</strong> [0,1]
<strong>解释:</strong>&nbsp;3 和 4 都是峰值，所以[1,0]和[0,1]都是可接受的答案。
</pre>

<p><strong>示例 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/06/07/3.png" style="width: 254px; height: 257px;" /></strong></p>

<pre>
<strong>输入:</strong> mat = [[10,20,15],[21,30,14],[7,16,32]]
<strong>输出:</strong> [1,1]
<strong>解释:</strong>&nbsp;30 和 32 都是峰值，所以[1,1]和[2,2]都是可接受的答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
	<li>任意两个相邻元素均不相等.</li>
</ul>


    
## 方法一：一路爬山

从任意一点出发不断“爬山”：若这一点四周都比这一点低则返回这一点的坐标；否则从这一点移动到比这一点更高的相邻点。

+ 时间复杂度$O(nm)$，其中$mat$未$n$行$m$列
+ 空间复杂度$O(1)$

小数据下方法二不一定快于方法一，但其不失为一个不错的思路。阅读前可参考上一题[162.寻找峰值](https://blog.letmefly.xyz/2023/12/18/LeetCode%200162.%E5%AF%BB%E6%89%BE%E5%B3%B0%E5%80%BC/)。

## 方法二：二分查找

二分查找有点类似于方法一的“跳跃式爬山”版本。从第一行到最后一行按行进行二分。二分到第mid行时：

+ 找到mid行的最大值所在位置(mid, maxLocation)。
   + 若此点比其上下两点都大，则直接返回此点坐标
   + 若此点上方的点比其大，则说明“爬山路线”以及“山顶”都在mid这一行的上方（这个点是这一行最大的了，爬山路线不可能穿过mid行），开始二分[0, mid - 1]
   + （否则）若此点下方的点比其大，开始二分[mid + 1, 行数 - 1]

以上。

+ 时间复杂度$O(m\log n)$，其中$mat$未$n$行$m$列
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = 0, r = mat.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            int maxLocation = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (mid - 1 >= 0 && mat[mid - 1][maxLocation] > mat[mid][maxLocation]) {
                r = mid;
            }
            else if (mid + 1 < mat.size() && mat[mid + 1][maxLocation] > mat[mid][maxLocation]) {
                l = mid + 1;
            }
            else {
                return {mid, maxLocation};
            }
        }
        return {};  // Fake Return
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        l, r = 0, len(mat)
        while l < r:
            mid = (l + r) >> 1
            maxLocation = mat[mid].index(max(mat[mid]))
            if mid - 1 >= 0 and mat[mid - 1][maxLocation] > mat[mid][maxLocation]:
                r = mid
            elif mid + 1 < len(mat) and mat[mid + 1][maxLocation] > mat[mid][maxLocation]:
                l = mid + 1
            else:
                return [mid, maxLocation]
        return []  # Fake Return
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/19/LeetCode%201901.%E5%AF%BB%E6%89%BE%E5%B3%B0%E5%80%BCII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135083347](https://letmefly.blog.csdn.net/article/details/135083347)
