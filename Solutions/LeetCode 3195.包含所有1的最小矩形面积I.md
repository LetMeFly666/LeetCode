---
title: 3195.包含所有 1 的最小矩形面积 I：简单题-求长方形四个范围
date: 2025-08-22 21:34:06
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3195.包含所有 1 的最小矩形面积 I：简单题-求长方形四个范围

力扣题目链接：[https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/](https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/)

<p>给你一个二维 <strong>二进制 </strong>数组 <code>grid</code>。请你找出一个边在水平方向和竖直方向上、面积 <strong>最小</strong> 的矩形，并且满足 <code>grid</code> 中所有的 1 都在矩形的内部。</p>

<p>返回这个矩形可能的 <strong>最小 </strong>面积。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[0,1,0],[1,0,1]]</span></p>

<p><strong>输出：</strong> <span class="example-io">6</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/08/examplerect0.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 279px; height: 198px;" /></p>

<p>这个最小矩形的高度为 2，宽度为 3，因此面积为 <code>2 * 3 = 6</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">grid = [[0,0],[1,0]]</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/08/examplerect1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 204px; height: 201px;" /></p>

<p>这个最小矩形的高度和宽度都是 1，因此面积为 <code>1 * 1 = 1</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= grid.length, grid[i].length &lt;= 1000</code></li>
	<li><code>grid[i][j]</code> 是 0 或 1。</li>
	<li>输入保证 <code>grid</code> 中至少有一个 1 。</li>
</ul>


    
## 解题方法：遍历求长方形位置

一个横平竖直的长方形把所有的1覆盖掉，那么我们只需要遍历一次grid，求出所有1中最小的横坐标、最大的横坐标、最小的纵坐标、最大的纵坐标，即为长方形的left、right、up、down，$(r - l + 1) \times (d - u + 1)$即为所求。

+ 时间复杂度$O(size(grid))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:21:31
 */
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int l = 1000, r = 0, u = 1000, d = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    l = min(l, j);
                    r = max(r, j);
                    u = min(u, i);
                    d = max(d, i);
                }
            }
        }
        return (r - l + 1) * (d - u + 1);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-22 21:18:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-22 21:23:44
'''
from typing import List

class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        l = u = 1000
        r = d = 0
        for i, line in enumerate(grid):
            for j, g in enumerate(line):
                if g:
                    l = min(l, j)
                    r = max(r, j)
                    u = min(u, i)
                    d = max(d, i)
        return (r - l + 1) * (d - u + 1)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:33:05
 */
class Solution {
    public int minimumArea(int[][] grid) {
        int l = 1000, r = 0, u = 1000, d = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    l = Math.min(l, j);
                    r = Math.max(r, j);
                    u = Math.min(u, i);
                    d = Math.max(d, i);
                }
            }
        }
        return (r - l + 1) * (d - u + 1);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:30:00
 */
package main

func minimumArea(grid [][]int) int {
    l, r, u, d := 1000, 0, 1000, 0
    for i, row := range grid {
        for j, g := range row {
            if g == 1 {
                l = min(l, j)
                r = max(r, j)
                u = min(u, i)
                d = max(d, i)
            }
        }
    }
    return (r - l + 1) * (d - u + 1)
}
```

golang[第一次提交](https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/submissions/655617341/?envType=daily-question&envId=2025-08-22)leetcode出bug了

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-22 21:18:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-22 21:28:08
 */
impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut l: usize = 1000;
        let mut r: usize = 0;
        let mut u: usize = 1000;
        let mut d: usize = 0;
        for (i, row) in grid.into_iter().enumerate() {
            for (j, g) in row.into_iter().enumerate() {
                if g == 1 {
                    l = l.min(j);
                    r = r.max(j);
                    u = u.min(i);
                    d = d.max(i);
                }
            }
        }
        ((r - l + 1) * (d - u + 1)) as i32
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150618919)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/22/LeetCode%203195.%E5%8C%85%E5%90%AB%E6%89%80%E6%9C%891%E7%9A%84%E6%9C%80%E5%B0%8F%E7%9F%A9%E5%BD%A2%E9%9D%A2%E7%A7%AFI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
