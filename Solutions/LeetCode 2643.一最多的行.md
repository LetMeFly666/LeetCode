---
title: 2643.一最多的行：模拟(更新答案)
date: 2025-03-22 22:54:18
tags: [题解, LeetCode, 简单, 数组, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】2643.一最多的行：模拟(更新答案)

力扣题目链接：[https://leetcode.cn/problems/row-with-maximum-ones/](https://leetcode.cn/problems/row-with-maximum-ones/)

<p>给你一个大小为 <code>m x n</code> 的二进制矩阵 <code>mat</code> ，请你找出包含最多 <strong>1</strong> 的行的下标（从 <strong>0</strong> 开始）以及这一行中 <strong>1</strong> 的数目。</p>

<p>如果有多行包含最多的 1 ，只需要选择 <strong>行下标最小</strong> 的那一行。</p>

<p>返回一个由行下标和该行中 1 的数量组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>mat = [[0,1],[1,0]]
<strong>输出：</strong>[0,1]
<strong>解释：</strong>两行中 1 的数量相同。所以返回下标最小的行，下标为 0 。该行 1 的数量为 1 。所以，答案为 [0,1] 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[0,0,0],[0,1,1]]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>下标为 1 的行中 1 的数量最多<code>。</code>该行 1 的数量<code>为 2 。所以，答案为</code> [1,2] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[0,0],[1,1],[0,0]]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>下标为 1 的行中 1 的数量最多。该行 1 的数量<code>为 2 。所以，答案为</code> [1,2] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code>&nbsp;</li>
	<li><code>n == mat[i].length</code>&nbsp;</li>
	<li><code>1 &lt;= m, n &lt;= 100</code>&nbsp;</li>
	<li><code>mat[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>


## 解题方法：模拟

使用一个变量$mx$记录当前一行中的最多1的个数，使用$ans$记录第一个有$mx$个1的行的下标。

遍历每一行，统计每一行的1的个数。如果这一行的1的个数比mx多，就更新mx和ans。

最终返回`{ans, mx}`。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 22:42:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 22:43:30
 */
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mx = 0, ans = 0;
        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                cnt += mat[i][j];
            }
            if (cnt > mx) {
                mx = cnt;
                ans = i;
            }
        }
        return {ans, mx};
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-22 22:44:18
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-22 22:44:32
'''
from typing import List

class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        mx, ans = 0, 0
        for i in range(len(mat)):
            cnt = sum(mat[i])
            if cnt > mx:
                mx, ans = cnt, i
        return [ans, mx]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 22:49:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 22:50:36
 */
class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int ans = 0, mx = 0;
        for (int i = 0; i < mat.length; i++) {
            int cnt = 0;
            for (int j = 0; j < mat[i].length; j++) {
                cnt += mat[i][j];
            }
            if (cnt > mx) {
                mx = cnt;
                ans = i;
            }
        }
        return new int[]{ans, mx};
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-22 22:51:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-22 22:52:04
 */
package main

func rowAndMaximumOnes(mat [][]int) []int {
    ans, mx := 0, 0
    for i := range mat {
        cnt := 0
        for _, t := range mat[i] {
            cnt += t
        }
        if cnt > mx {
            ans, mx = i, cnt
        }
    }
    return []int{ans, mx}
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146448280)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/22/LeetCode%202643.%E4%B8%80%E6%9C%80%E5%A4%9A%E7%9A%84%E8%A1%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
