---
title: 498.对角线遍历：模拟遍历(if-else)/对角线思维
date: 2025-08-26 10:40:07
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】498.对角线遍历：模拟遍历(if-else)/对角线思维

力扣题目链接：[https://leetcode.cn/problems/diagonal-traverse/](https://leetcode.cn/problems/diagonal-traverse/)

<p>给你一个大小为 <code>m x n</code> 的矩阵 <code>mat</code> ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg" style="width: 334px; height: 334px;" />
<pre>
<strong>输入：</strong>mat = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[1,2,4,7,5,3,6,8,9]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2],[3,4]]
<strong>输出：</strong>[1,2,3,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length</code></li>
	<li><code>m == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= mat[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

## 解题方法一：模拟遍历 —— if-else

![官方图示例1](https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg)

没啥好说的，起点`(0, 0)`，终点`(n - 1, m - 1)`，`direction=true`代表向右上否则代表向左下。

向右上时：如果已经达到了最右边一列，则下次从下一行对应元素开始(如图中的3到6)；如果已经达到了第一行，则下次从这一行右边一个元素开始（如图中的1到2）；否则就正常往右上方走（如图中的5到3）。

向左下时：同理，判下if-else即可。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-06-14 15:04:55
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-06-14 15:16:23
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        int x = 0, y = 0;
        bool direction = true;
        while (true) {
            ans.push_back(mat[x][y]);
            if (x == n - 1 && y == m - 1)
                break;
            if (direction) {  // ↗
                if (y == m - 1) {
                    x++;
                    direction = false;
                }
                else if (x == 0) {
                    y++;
                    direction = false;
                }
                else {
                    x--, y++;
                }
            }
            else {  // ↙
                if (x == n - 1) {
                    y++;
                    direction = true;
                }
                else if (y == 0) {
                    x++;
                    direction = true;
                }
                else {
                    x++, y--;
                }
            }
        }
        return ans;
    }
};
```

## 解题方法二：对角线思维

![官方图示例1](https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg)

不考虑图中mat外的虚线，不难发现不管是褐色(向右上方)还是黄色(向左下方)，都是在沿着反对角线的方向走。

$n\times m$的矩形一共有多少条对角线呢？一共$m+n-1$条。并且反对角线上的坐标有一个性质，就是一条反对角线上的元素横纵坐标之和相等。

所以只需要枚举是第几根反对角线(从0开始)，偶数时往右上走奇数时往左下走，走到边界就停下。

相比于方法一，其实是将很多的if-else（下一个坐标位置的计算判断）改成了相对简单的走到边界就停下，省去了**方向转换时**的“复杂”判断。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-25 22:09:04
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        for (int k = 0; k < m + n - 1; k++) {
            if (k % 2) {
                for (int j = min(k, m - 1), i = k - j; j >= 0 && i < n; i++, j--) {
                    ans.push_back(mat[i][j]);
                }
            } else {
                for (int i = min(k, n - 1), j = k - i; i >= 0 && j < m; i--, j++) {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-25 18:56:28
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-25 23:54:37
'''
from typing import List

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans: List[int] = []
        n, m = len(mat), len(mat[0])
        for k in range(m + n - 1):
            if k % 2:
                j = min(k, m - 1)
                i = k - j
                while i < n and j >= 0:
                    ans.append(mat[i][j])
                    i += 1
                    j -= 1
            else:
                i = min(k, n - 1)
                j = k - i
                while i >= 0 and j < m:
                    ans.append(mat[i][j])
                    i -= 1
                    j += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 10:24:47
 */
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[] ans = new int[m * n];
        for (int k = 0, cnt = 0; k < m + n - 1; k++) {
            if (k % 2 == 0) {
                for (int i = Math.min(k, n - 1), j = k - i; i >= 0 && j < m; i--, j++) {
                    ans[cnt++] = mat[i][j];
                }
            } else {
                for (int j = Math.min(k, m - 1), i = k - j; i < n && j >= 0; i++, j--) {
                    ans[cnt++] = mat[i][j];
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 00:00:06
 */
package main

func findDiagonalOrder(mat [][]int) []int {
    n, m := len(mat), len(mat[0])
    ans := make([]int, 0, m * n)
    for k := 0; k < m + n - 1; k++ {
        if k % 2 == 0 {
            i := min(k, n - 1)
            for j := k - i; i >= 0 && j < m; i, j = i - 1, j + 1 {
                ans = append(ans, mat[i][j])
            }
        } else {
            j := min(k, m - 1)
            for i := k - j; i < n && j >= 0; i, j = i + 1, j - 1 {
                ans = append(ans, mat[i][j])
            }
        }
    }
    return ans
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-25 18:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 10:39:12
 */
impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let n: isize = mat.len() as isize;  // 注意，usize永远大于0
        let m: isize = mat[0].len() as isize;
        let mut ans: Vec<i32> = vec![0; (m * n) as usize];
        let mut cnt: usize = 0;
        for k in 0..(m + n - 1) {
            if k % 2 == 0 {
                let mut i: isize = k.min(n - 1);
                let mut j: isize = k - i;
                while i >= 0 && j < m {
                    ans[cnt] = mat[i as usize][j as usize];
                    cnt += 1;
                    i -= 1;
                    j += 1;
                }
            } else {
                let mut j: isize = k.min(m - 1);
                let mut i: isize = k - j;
                while i < n && j >= 0 {
                    ans[cnt] = mat[i as usize][j as usize];
                    cnt += 1;
                    i += 1;
                    j -= 1;
                }
            }
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150851418)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/25/LeetCode%200498.%E5%AF%B9%E8%A7%92%E7%BA%BF%E9%81%8D%E5%8E%86/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
