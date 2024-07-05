---
title: 3033.修改矩阵
date: 2024-07-05 21:57:21
tags: [题解, LeetCode, 简单, 数组, 矩阵]
---

# 【LetMeFly】3033.修改矩阵：原地修改

力扣题目链接：[https://leetcode.cn/problems/modify-the-matrix/](https://leetcode.cn/problems/modify-the-matrix/)

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的整数矩阵 <code>matrix</code> ，新建一个下标从 <strong>0</strong> 开始、名为 <code>answer</code> 的矩阵。使 <code>answer</code> 与 <code>matrix</code> 相等，接着将其中每个值为 <code>-1</code> 的元素替换为所在列的 <strong>最大</strong> 元素。</p>

<p>返回矩阵 <code>answer</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/12/24/matrix1.png" style="width: 491px; height: 161px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
<strong>输出：</strong>[[1,2,9],[4,8,6],[7,8,9]]
<strong>解释：</strong>上图显示了发生替换的元素（蓝色区域）。
- 将单元格 [1][1] 中的值替换为列 1 中的最大值 8 。
- 将单元格 [0][2] 中的值替换为列 2 中的最大值 9 。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/12/24/matrix2.png" style="width: 411px; height: 111px;" />
<pre>
<strong>输入：</strong>matrix = [[3,-1],[5,2]]
<strong>输出：</strong>[[3,2],[5,2]]
<strong>解释：</strong>上图显示了发生替换的元素（蓝色区域）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>-1 &lt;= matrix[i][j] &lt;= 100</code></li>
	<li>测试用例中生成的输入满足每列至少包含一个非负整数。</li>
</ul>


    
## 解题方法：一列一列地计算

先遍历第一列，找出这一列的最大值并记为M，再遍历一次第一列，如果当前位置为-1则将其修改为M。

然后开始遍历第二列，进行相同的操作。

直到遍历完每一列为止，matrix矩阵就变成了题目想要的样子。

+ 时间复杂度$O(size(matrix))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix[0].size(); j++) {
            int M = matrix[0][j];
            for (int i = 1; i < matrix.size(); i++) {
                M = max(M, matrix[i][j]);
            }
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = M;
                }
            }
        }
        return matrix;
    }
};
```

#### Go

```go
package main
func modifiedMatrix(matrix [][]int) [][]int {
    for j := 0; j < len(matrix[0]); j++ {
        M := matrix[0][j]
        for i := 1; i < len(matrix); i++ {
            if matrix[i][j] > M {
                M = matrix[i][j]
            }
        }
        for i := 0; i < len(matrix); i++ {
            if matrix[i][j] == -1 {
                matrix[i][j] = M
            }
        }
    }
    return matrix
}
```

#### Java

```java
class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        for (int j = 0; j < matrix[0].length; j++) {
            int M = matrix[0][j];
            for (int i = 1; i < matrix.length; i++) {
                M = Math.max(M, matrix[i][j]);
            }
            for (int i = 0; i < matrix.length; i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = M;
                }
            }
        }
        return matrix;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        for j in range(0, len(matrix[0])):
            M = matrix[0][j]
            for i in range(1, len(matrix)):
                M = max(M, matrix[i][j])
            for i in range(0, len(matrix)):
                if matrix[i][j] == -1:
                    matrix[i][j] = M
        return matrix
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/05/LeetCode%203033.%E4%BF%AE%E6%94%B9%E7%9F%A9%E9%98%B5/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140219034](https://letmefly.blog.csdn.net/article/details/140219034)
