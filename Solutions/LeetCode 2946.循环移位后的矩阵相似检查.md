---
title: 2946.循环移位后的矩阵相似检查：模拟（左即是右）
date: 2026-03-27 09:09:55
tags: [题解, LeetCode, 简单, 数组, 数学, 矩阵, 模拟]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2023/10/29/similarmatrix.png
---

# 【LetMeFly】2946.循环移位后的矩阵相似检查：模拟（左即是右）

力扣题目链接：[https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts/](https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts/)

<p>给你一个<strong>下标从 0 开始</strong>且大小为 <code>m x n</code> 的整数矩阵 <code>mat</code> 和一个整数 <code>k</code> 。请你将矩阵中的<strong> 奇数</strong> 行循环 <strong>右</strong> 移 <code>k</code> 次，<strong>偶数</strong> 行循环 <strong>左</strong> 移 <code>k</code> 次。</p>

<p>如果初始矩阵和最终矩阵完全相同，则返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
<strong>输出：</strong>true
<strong>解释：</strong>
<img alt="" src="https://assets.leetcode.com/uploads/2023/10/29/similarmatrix.png" style="width: 500px; height: 117px;" />

初始矩阵如图一所示。
图二表示对奇数行右移一次且对偶数行左移一次后的矩阵状态。
图三是经过两次循环移位后的最终矩阵状态，与初始矩阵相同。
因此，返回 true 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[2,2],[2,2]], k = 3
<strong>输出：</strong>true
<strong>解释：</strong>由于矩阵中的所有值都相等，即使进行循环移位，矩阵仍然保持不变。因此，返回 true 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[1,2]], k = 1
<strong>输出：</strong>false
<strong>解释：</strong>循环移位一次后，mat = [[2,1]]，与初始矩阵不相等。因此，返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= mat.length &lt;= 25</code></li>
	<li><code>1 &lt;= mat[i].length &lt;= 25</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 25</code></li>
	<li><code>1 &lt;= k &lt;= 50</code></li>
</ul>


    
## 解题方法：模拟

如果一行左移$k$次和原来相同，那么它右移$k$次肯定也和原来相同。

所以我们不用管第几行，统一判断每个元素右移$k$后是否等值就好了（$row[j] == row[(j + k)\mod len(row)]$）

+ 时间复杂度$O(size(mat))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-27 08:49:37
 */
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat[0].size();
        for (vector<int>& row : mat) {
            for (int j = 0; j < m; j++) {
                if (row[j] != row[(j + k) % m]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-03-27 08:58:55
'''
from typing import List

class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        m = len(mat[0])
        return all(row[j] == row[(j + k) % m] for j in range(m) for row in mat)

```

#### Java

```java
/*
 * @LastEditTime: 2026-03-27 08:57:58
 */
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat[0].length;
        for (int[] row : mat) {
            for (int j = 0; j < m; j++) {
                if (row[j] != row[(j + k) % m]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-03-27 08:53:34
 */
package main

func areSimilar(mat [][]int, k int) bool {
	m := len(mat[0])
    for _, row := range mat {
		for j := range row {
			if row[j] != row[(j + k) % m] {
				return false
			}
		}
	}
	return true
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-03-27 09:08:38
 */
impl Solution {
    pub fn are_similar(mat: Vec<Vec<i32>>, k: i32) -> bool {
        let m = mat[0].len();
        for row in mat.iter() {
            for j in 0..row.len() {
                if (row[j] != row[(j + k as usize) % m]) {
                    return false;
                }
            }
        }
        true
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159527340)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/27/LeetCode%202946.%E5%BE%AA%E7%8E%AF%E7%A7%BB%E4%BD%8D%E5%90%8E%E7%9A%84%E7%9F%A9%E9%98%B5%E7%9B%B8%E4%BC%BC%E6%A3%80%E6%9F%A5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
