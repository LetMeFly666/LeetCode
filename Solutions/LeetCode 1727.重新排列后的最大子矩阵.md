---
title: 1727.重新排列后的最大子矩阵：枚举矩形底边是哪一行 + 排序
date: 2026-03-17 22:03:02
tags: [题解, LeetCode, 中等, 贪心, 数组, 矩阵, 排序]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/01/17/screenshot-2020-12-30-at-40536-pm.png
---

# 【LetMeFly】1727.重新排列后的最大子矩阵：枚举矩形底边是哪一行 + 排序

力扣题目链接：[https://leetcode.cn/problems/largest-submatrix-with-rearrangements/](https://leetcode.cn/problems/largest-submatrix-with-rearrangements/)

<p>给你一个二进制矩阵 <code>matrix</code> ，它的大小为 <code>m x n</code> ，你可以将 <code>matrix</code> 中的 <strong>列</strong> 按任意顺序重新排列。</p>

<p>请你返回最优方案下将 <code>matrix</code> 重新排列后，全是 <code>1</code> 的子矩阵面积。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/01/17/screenshot-2020-12-30-at-40536-pm.png" style="width: 300px; height: 144px;" /></strong></p>

<pre>
<b>输入：</b>matrix = [[0,0,1],[1,1,1],[1,0,1]]
<b>输出：</b>4
<b>解释：</b>你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/01/17/screenshot-2020-12-30-at-40852-pm.png" style="width: 500px; height: 62px;" /></p>

<pre>
<b>输入：</b>matrix = [[1,0,1,0,1]]
<b>输出：</b>3
<b>解释：</b>你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>matrix = [[1,1,0],[1,0,1]]
<b>输出：</b>2
<b>解释：</b>由于你只能整列整列重新排布，所以没有比面积为 2 更大的全 1 子矩形。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>matrix = [[0,0],[0,0]]
<b>输出：</b>0
<b>解释：</b>由于矩阵中没有 1 ，没有任何全 1 的子矩阵，所以面积为 0 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m * n <= 10<sup>5</sup></code></li>
	<li><code>matrix[i][j]</code> 要么是 <code>0</code> ，要么是 <code>1</code> 。</li>
</ul>


    
## 解题方法：枚举矩形底边是哪一行 + 排序

对于样例1：

![sample2](https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/01/17/screenshot-2020-12-30-at-40536-pm.png)，假设最优的答案矩形的底在第三行，那么怎么计算*以第三行为底的矩形中面积最大的那个*呢？

> 很简单，看下每一列从第三行开始向上能延伸多少格：`[2, 0, 3]`；排个序：`[0, 2, 3]`。
> 
> 1. 假设矩形从第一列开始，$0$是矩形的高，则矩形最大面积是$0\times 3=0$
> 2. 假设矩形从第二列开始，$2$是矩形的高，则矩形最大面积是$2\times 2=4$
> 3. 假设矩形从第三列开始，$3$是矩形的高，则矩形最大面积是$3\times 1=3$
> 
> 也就是说矩形从第$i$列开始的话，由于后面列的高都不低于这一列，所以矩形的最大面积是从这一列的高度一直持续到最后一列，为$heights[i]\times (n-i)$，其中$n$是列数。
> 
> 也就是说，如果固定了矩形底边是哪一行的话，如果我们知道每一列以这个底边向上的连续1个数$height$，就能对$heights$数组从小到大排个序，然后遍历一遍求出最大矩形面积了。

现在底边有很多行，我们一行一行地枚举并做上述运算，顺便在枚举下一行的时候借助上一行的heights结果计算出新的heights就好了。

+ 时间复杂度$O(nm\log n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-17 22:00:41
 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for (vector<int>& row : matrix) {
            for (int i = 0; i < n; i++) {
                heights[i] = row[i] ? heights[i] + 1 : 0;
            }
            vector<int> ordered_heights = heights;
            sort(ordered_heights.begin(), ordered_heights.end());
            for (int i = 0; i < n; i++) {
                ans = max(ans, ordered_heights[i] * (n - i));
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159174953)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/17/LeetCode%201727.%E9%87%8D%E6%96%B0%E6%8E%92%E5%88%97%E5%90%8E%E7%9A%84%E6%9C%80%E5%A4%A7%E5%AD%90%E7%9F%A9%E9%98%B5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
