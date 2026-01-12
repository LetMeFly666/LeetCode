---
title: 1266.访问所有点的最小时间：贪心（数学）+python一行版
date: 2026-01-12 23:37:50
tags: [题解, LeetCode, 简单, 几何, 数组, 数学, 贪心]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/11/24/1626_example_1.png
---

# 【LetMeFly】1266.访问所有点的最小时间：贪心（数学）+python一行版

力扣题目链接：[https://leetcode.cn/problems/minimum-time-visiting-all-points/](https://leetcode.cn/problems/minimum-time-visiting-all-points/)

<p>平面上有 <code>n</code> 个点，点的位置用整数坐标表示 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。请你计算访问所有这些点需要的 <strong>最小时间</strong>（以秒为单位）。</p>

<p>你需要按照下面的规则在平面上移动：</p>

<ul>
	<li>每一秒内，你可以：
	<ul>
		<li>沿水平方向移动一个单位长度，或者</li>
		<li>沿竖直方向移动一个单位长度，或者</li>
		<li>跨过对角线移动 <code>sqrt(2)</code> 个单位长度（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。</li>
	</ul>
	</li>
	<li>必须按照数组中出现的顺序来访问这些点。</li>
	<li>在访问某个点时，可以经过该点后面出现的点，但经过的那些点不算作有效访问。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/11/24/1626_example_1.png" style="height: 428px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>points = [[1,1],[3,4],[-1,0]]
<strong>输出：</strong>7
<strong>解释：</strong>一条最佳的访问路径是： <strong>[1,1]</strong> -> [2,2] -> [3,3] -> <strong>[3,4] </strong>-> [2,3] -> [1,2] -> [0,1] -> <strong>[-1,0]</strong>   
从 [1,1] 到 [3,4] 需要 3 秒 
从 [3,4] 到 [-1,0] 需要 4 秒
一共需要 7 秒</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[3,2],[-2,2]]
<strong>输出：</strong>5
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>points.length == n</code></li>
	<li><code>1 <= n <= 100</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-1000 <= points[i][0], points[i][1] <= 1000</code></li>
</ul>


    
## 解题方法：贪心

斜着移动一次相当于横着移动一次加竖着移动一次，点的访问顺序是固定的，所以从a点到b点时：

> 我们尽可能多地斜向移动，移动到一条水平线或竖直线时水平/竖直移动。
>
> 总移动次数：$max(水平diff, 竖直diff)$。相当于斜向移动时候把近的那个水平/竖直分量给一块走了。

+ 时间复杂度$O(len(pints))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-12 23:28:12
 */
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][0] - points[i - 1][0]), abs(points[i][1] - points[i - 1][1]));
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-01-12 23:32:26
'''
from typing import List
from itertools import pairwise

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return sum(max(abs(a[0] - b[0]), abs(a[1] - b[1])) for a, b in pairwise(points))
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-12 23:32:59
 */
class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int ans = 0;
        for (int i = 1; i < points.length; i++) {
            ans += Math.max(Math.abs(points[i][0] - points[i - 1][0]) , Math.abs(points[i][1] - points[i - 1][1]));
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-01-12 23:35:23
 */
package main

func abs1266(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func minTimeToVisitAllPoints(points [][]int) (ans int) {
    for i := 1; i < len(points); i++ {
        ans += max(abs1266(points[i][0] - points[i - 1][0]), abs1266(points[i][1] - points[i - 1][1]))
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-12 23:37:10
 */
impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let mut ans: i32 = 0;
        for i in 1..points.len() {
            ans += (points[i][0] - points[i - 1][0]).abs().max((points[i][1] - points[i - 1][1]).abs());
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156875167)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/12/LeetCode%201266.%E8%AE%BF%E9%97%AE%E6%89%80%E6%9C%89%E7%82%B9%E7%9A%84%E6%9C%80%E5%B0%8F%E6%97%B6%E9%97%B4/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
