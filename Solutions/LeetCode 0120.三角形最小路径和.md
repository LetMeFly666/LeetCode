---
title: 120.三角形最小路径和：原地动态规划（根本不需要演变来演变去）
date: 2022-07-18 16:23:53
tags: [题解, LeetCode, 中等, 数组, 动态规划]
categories: [题解, LeetCode]
---

# 【LetMeFly】120.三角形最小路径和：原地动态规划（根本不需要演变来演变去）

力扣题目链接：[https://leetcode.cn/problems/triangle/](https://leetcode.cn/problems/triangle/)

<p>给定一个三角形 <code>triangle</code> ，找出自顶向下的最小路径和。</p>

<p>每一步只能移动到下一行中相邻的结点上。<strong>相邻的结点 </strong>在这里指的是 <strong>下标</strong> 与 <strong>上一层结点下标</strong> 相同或者等于 <strong>上一层结点下标 + 1</strong> 的两个结点。也就是说，如果正位于当前行的下标 <code>i</code> ，那么下一步可以移动到下一行的下标 <code>i</code> 或 <code>i + 1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
<strong>输出：</strong>11
<strong>解释：</strong>如下面简图所示：
   <strong>2</strong>
  <strong>3</strong> 4
 6 <strong>5</strong> 7
4 <strong>1</strong> 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>triangle = [[-10]]
<strong>输出：</strong>-10
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= triangle.length <= 200</code></li>
	<li><code>triangle[0].length == 1</code></li>
	<li><code>triangle[i].length == triangle[i - 1].length + 1</code></li>
	<li><code>-10<sup>4</sup> <= triangle[i][j] <= 10<sup>4</sup></code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以只使用 <code>O(n)</code> 的额外空间（<code>n</code> 为三角形的总行数）来解决这个问题吗？</li>
</ul>


    
## 方法一：原地修改

第$i$行的第$j$个元素可由第$i-1$行的第$j-1$ or 第$j$个元素走来。

那么具体由哪个走来呢？当然取决于上一行第$j-1$ 和 第$j$个的最小的那个。

直接在原三角形上进行修改即可。

+ 时间复杂度$O(N^2)$，其中$N$为三角形的边长
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-07-18 16:16:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-18 16:22:44
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = 1; i < n; i++) {
            triangle[i][0] += triangle[i - 1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            triangle[i][i] += triangle[i - 1][i - 1];
        }
		// 返回最后一行的最小元素
        int ans = triangle[n - 1][0];
        for (int i = 1; i < n; i++) {
            ans = min(ans, triangle[n - 1][i]);
        }
        return ans;
    }
};
```

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:18:09
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                int toAdd = 100000;
                if (j - 1 >= 0) {
                    toAdd = min(toAdd, triangle[i - 1][j - 1]);
                }
                if (j < i) {
                    toAdd = min(toAdd, triangle[i - 1][j]);
                }
                triangle[i][j] += toAdd;
            }
        }
        int ans = 100000;
        for (int t : triangle.back()) {
            ans = min(ans, t);
        }
        return ans;
    }
};
```

## 方法二：原地修改（倒序遍历）

其实只需要倒着写，代码实现就会简单很多。

+ 时间复杂度$O(N^2)$，其中$N$为三角形的边长
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:20:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:21:43
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-01 23:51:32
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-02 00:01:53
'''
from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1] for _ in range(numRows)]
        for i in range(1, numRows):
            for j in range(1, i):
                ans[i].append(ans[i - 1][j - 1] + ans[i - 1][j])
            ans[i].append(1)
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:31:13
 */
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle.get(i).set(j, triangle.get(i).get(j) + Math.min(triangle.get(i + 1).get(j), triangle.get(i + 1).get(j + 1)));
            }
        }
        return triangle.get(0).get(0);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:26:32
 */
package main

func minimumTotal(triangle [][]int) int {
    for i := len(triangle) - 2; i >= 0; i-- {
        for j := 0; j <= i; j++ {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
        }
    }
    return triangle[0][0]
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-09-25 23:12:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-25 23:34:54
 */
impl Solution {
    pub fn minimum_total(mut triangle: Vec<Vec<i32>>) -> i32 {
        for i in (0..triangle.len()-1).rev() {
            for j in 0..=i {
                triangle[i][j] += triangle[i+1][j].min(triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/125854342)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2022/07/18/LeetCode%200120.%E4%B8%89%E8%A7%92%E5%BD%A2%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
