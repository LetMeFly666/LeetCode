---
title: 304.二维区域和检索 - 矩阵不可变
date: 2022-09-17 18:48:16
tags: [题解, LeetCode, 中等, 设计, 数组, 矩阵, 前缀和, 二维前缀和]
---

# 【LetMeFly】304.二维区域和检索 - 矩阵不可变

力扣题目链接：[https://leetcode.cn/problems/range-sum-query-2d-immutable/](https://leetcode.cn/problems/range-sum-query-2d-immutable/)

<p><big><small>给定一个二维矩阵 <code>matrix</code>，</small></big>以下类型的多个请求：</p>

<ul>
	<li><big><small>计算其子矩形范围内元素的总和，该子矩阵的 <strong>左上角</strong> 为 <code>(row1,&nbsp;col1)</code> ，<strong>右下角</strong> 为 <code>(row2,&nbsp;col2)</code> 。</small></big></li>
</ul>

<p>实现 <code>NumMatrix</code> 类：</p>

<ul>
	<li><code>NumMatrix(int[][] matrix)</code>&nbsp;给定整数矩阵 <code>matrix</code> 进行初始化</li>
	<li><code>int sumRegion(int row1, int col1, int row2, int col2)</code>&nbsp;返回<big><small> <strong>左上角</strong></small></big><big><small> <code>(row1,&nbsp;col1)</code>&nbsp;、<strong>右下角</strong>&nbsp;<code>(row2,&nbsp;col2)</code></small></big> 所描述的子矩阵的元素 <strong>总和</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://pic.leetcode-cn.com/1626332422-wUpUHT-image.png" style="width: 200px;" /></p>

<pre>
<strong>输入:</strong> 
["NumMatrix","sumRegion","sumRegion","sumRegion"]
[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
<strong>输出:</strong> 
[null, 8, 11, 12]

<strong>解释:</strong>
NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m,&nbsp;n &lt;=&nbsp;200</code><meta charset="UTF-8" /></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= matrix[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; m</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; n</code></li>
	<li><meta charset="UTF-8" />最多调用 <code>10<sup>4</sup></code> 次&nbsp;<code>sumRegion</code> 方法</li>
</ul>


    
## 方法一：二维前缀和

二维前缀和的思路就是用一个二维数组来存放“从左上角到某个元素的矩形中所有元素”的和。

例如$prefix[2][3]$就表示以$(0,0)$和$(2,3)$为对角的矩形中，所有元素的和。

初始化和查询的方法如图所示

![Demonstration](https://img-blog.csdnimg.cn/c92fff4ce271419183ccb93512ea68d9.png#pic_center)

<!-- ![Demonstration.png](https://pic.leetcode-cn.com/1663412553-DXuxDJ-Demonstration.png) -->

初始化的时候，红色框里的元素的和可以由```上方紫色矩形的元素和```、```左边绿色矩形的元素和```、```紫色绿色重合部分矩形的元素和```三者在$O(1)$的时间内求得。

查询的时候，红色框里的元素和可以由```蓝色框里的元素和```、```上方紫色矩形的元素和```、```左边绿色矩形的元素和```、```紫色绿色重合部分矩形的元素和```四者在$O(1)$的时间内求得。

因为第一行的“上边的绿色矩形”已经超出了数组的范围，因此为了方便，在开辟$prefix$数组的时候，可以在上方多开辟一行，左侧多开辟一列。即：为$n\times m$大小的原始数组开辟$(n+1)\times(m+1)$大小的$prefix$数组以防止计算过程越界。同时，$prefix$数组从下标$(1,1)$开始使用。

+ 时间复杂度：初始化$O(nm)$，查询$O(1)$。其中矩阵的形状为$n\times m$
+ 空间复杂度$O(nm)$

### AC代码

#### C++

```cpp
class NumMatrix {
private:
    vector<vector<int>> prefix;

    void init(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        prefix.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i + 1][j + 1] = prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j] + a[i][j];
            }
        }
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        init(matrix);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/17/LeetCode%200304.%E4%BA%8C%E7%BB%B4%E5%8C%BA%E5%9F%9F%E5%92%8C%E6%A3%80%E7%B4%A2-%E7%9F%A9%E9%98%B5%E4%B8%8D%E5%8F%AF%E5%8F%98/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126909280](https://letmefly.blog.csdn.net/article/details/126909280)
