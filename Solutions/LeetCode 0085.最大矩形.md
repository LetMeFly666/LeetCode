---
title: 85.最大矩形：单调栈
date: 2026-01-11 23:17:54
tags: [题解, LeetCode, 困难, 栈, 数组, 动态规划, 矩阵, 单调栈]
categories: [题解, LeetCode]
index_img: https://pic.leetcode.cn/1722912576-boIxpm-image.png
---

# 【LetMeFly】85.最大矩形：单调栈

力扣题目链接：[https://leetcode.cn/problems/maximal-rectangle/](https://leetcode.cn/problems/maximal-rectangle/)

<p>给定一个仅包含&nbsp;<code>0</code> 和 <code>1</code> 、大小为 <code>rows x cols</code> 的二维二进制矩阵，找出只包含 <code>1</code> 的最大矩形，并返回其面积。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://pic.leetcode.cn/1722912576-boIxpm-image.png" style="width: 402px; height: 322px;" />
<pre>
<strong>输入：</strong>matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
<strong>输出：</strong>6
<strong>解释：</strong>最大矩形如上图所示。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [["0"]]
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [["1"]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rows == matrix.length</code></li>
	<li><code>cols == matrix[0].length</code></li>
	<li><code>1 &lt;= row, cols &lt;= 200</code></li>
	<li><code>matrix[i][j]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


    
## 解题方法：单调栈

<img src="https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg">

先看[84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram)，求n个相邻柱子的最大面积：

> 使用一个单调递增栈，柱子前后加两个高度为0的哨兵。
>
> 某个柱子被逐出栈时，说明其左右最多能延伸到的柱子分别是“栈顶柱子”、“将其逐出的柱子”（左右不含），以其为高的最大矩形面积为$其高\times(右柱子-左柱子-1)$。
>
> ```cpp
> /*
>  * @LastEditTime: 2026-01-11 22:44:08
>  */
> class Solution {
> public:
>     int largestRectangleArea(vector<int>& heights) {
>         stack<int> idx;
>         heights.insert(heights.begin(), 0);
>         heights.push_back(0);
>         int ans = 0;
>         for (int i = 0; i < heights.size(); i++) {
>             while (idx.size() && heights[i] < heights[idx.top()]) {
>                 int lastIdx = idx.top();
>                 idx.pop();
>                 ans = max(ans, heights[lastIdx] * (i - idx.top() - 1));
>             }
>             idx.push(i);
>         }
>         return ans;
>     }
> };
> ```

这道题是一样的，对于$n$行的matrix，以第$i$行为底第$1$行为顶的子矩阵共$n$个，可以做$n$次上面的单调栈。

对于下面的matrix：

```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
```

相当于：

1. 第$1$行到第$1$行的子矩阵：

    ```
    1 0 1 0 0
    ```

    相当于高为`1 0 1 0 0`的柱子，做一次单调栈；

2. 第$1$行到第$2$行的子矩阵：

    ```
    1 0 1 0 0
    1 0 1 1 1
    ```

    相当于高为`2 0 2 1 1`的柱子，做一次单调栈；

3. 第$1$行到第$3$行的子矩阵：

    ```
    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    ```

    相当于高为`3 0 3 2 2`的柱子，做一次单调栈。

其中由第$i$行为底过度到由第$i+1$行为底时，可以借助上一行为底时的柱子高度快速更新新柱子的高度。

+ 时间复杂度$O(size(matrix))$
+ 空间复杂度$O(size(matrix[0]))$，需要一行的空间

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-11 23:13:41
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> heights(matrix[0].size() + 2);
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].insert(matrix[i].begin(), '0');
            matrix[i].push_back('0');
            stack<int> st;
            for (int j = 0; j < matrix[i].size(); j++) {
                heights[j] = heights[j] && matrix[i][j] == '1' ? heights[j] + 1 : matrix[i][j] == '1';
                while (st.size() && heights[j] < heights[st.top()]) {  // 记得st.size()也要判断，因为哨兵0会驱逐哨兵0
                    int idx = st.top();
                    st.pop();
                    ans = max(ans, heights[idx] * (j - st.top() - 1));
                }
                st.push(j);
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156837504)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/11/LeetCode%200085.%E6%9C%80%E5%A4%A7%E7%9F%A9%E5%BD%A2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
