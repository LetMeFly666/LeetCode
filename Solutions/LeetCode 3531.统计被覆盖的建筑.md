---
title: 3531.统计被覆盖的建筑：最大最小值
date: 2025-12-11 18:39:45
tags: [题解, LeetCode, 中等, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3531.统计被覆盖的建筑：最大最小值

力扣题目链接：[https://leetcode.cn/problems/count-covered-buildings/](https://leetcode.cn/problems/count-covered-buildings/)

<p>给你一个正整数 <code>n</code>，表示一个 <code>n x n</code> 的城市，同时给定一个二维数组 <code>buildings</code>，其中 <code>buildings[i] = [x, y]</code> 表示位于坐标 <code>[x, y]</code> 的一个&nbsp;<strong>唯一&nbsp;</strong>建筑。</p>

<p>如果一个建筑在四个方向（左、右、上、下）中每个方向上都至少存在一个建筑，则称该建筑&nbsp;<strong>被覆盖&nbsp;</strong>。</p>

<p>返回&nbsp;<strong>被覆盖&nbsp;</strong>的建筑数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img src="https://pic.leetcode.cn/1745660407-qtNUjI-telegram-cloud-photo-size-5-6212982906394101085-m.jpg" style="width: 200px; height: 204px;" /></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]</span></p>

<p><strong>输出:</strong> <span class="example-io">1</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>只有建筑 <code>[2,2]</code> 被覆盖，因为它在每个方向上都至少存在一个建筑：

	<ul>
		<li>上方 (<code>[1,2]</code>)</li>
		<li>下方 (<code>[3,2]</code>)</li>
		<li>左方 (<code>[2,1]</code>)</li>
		<li>右方 (<code>[2,3]</code>)</li>
	</ul>
	</li>
	<li>因此，被覆盖的建筑数量是 1。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<p><img src="https://pic.leetcode.cn/1745660407-tUMUKl-telegram-cloud-photo-size-5-6212982906394101086-m.jpg" style="width: 200px; height: 204px;" /></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]</span></p>

<p><strong>输出:</strong> <span class="example-io">0</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>没有任何一个建筑在每个方向上都有至少一个建筑。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<p><img src="https://pic.leetcode.cn/1745660407-bQIwBX-telegram-cloud-photo-size-5-6248862251436067566-x.jpg" style="width: 202px; height: 205px;" /></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]</span></p>

<p><strong>输出:</strong> <span class="example-io">1</span></p>

<p><strong>解释:</strong></p>

<ul>
	<li>只有建筑 <code>[3,3]</code> 被覆盖，因为它在每个方向上至少存在一个建筑：

	<ul>
		<li>上方 (<code>[1,3]</code>)</li>
		<li>下方 (<code>[5,3]</code>)</li>
		<li>左方 (<code>[3,2]</code>)</li>
		<li>右方 (<code>[3,5]</code>)</li>
	</ul>
	</li>
	<li>因此，被覆盖的建筑数量是 1。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= buildings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>buildings[i] = [x, y]</code></li>
	<li><code>1 &lt;= x, y &lt;= n</code></li>
	<li><code>buildings</code> 中所有坐标均&nbsp;<strong>唯一&nbsp;</strong>。</li>
</ul>


    
## 解题方法：最大最小值

遍历一遍所有点可以得到如下信息：

1. 使用两个数组xm和xM，分别记录所有横坐标为x的点中纵坐标的最小值和最大值；
1. 使用两个数组ym和yM，分别记录所有纵坐标为y的点中横坐标的最小值和最大值。

接着遍历一遍所有点（假设横纵坐标分别是x和y）：

> 如果$ym[y]\lt x\lt yM[y]$并且$xm[x]\lt y\lt xM[x]$则说明这个点上下左右都有点，答案加一。

+ 时间复杂度$O(n+len(buildings))$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-11 13:23:40
 */
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        n++;
        vector<int> xm(n, n), xM(n), ym(n, n), yM(n);
        for (vector<int>& building : buildings) {
            int x = building[0], y = building[1];
            xm[x] = min(xm[x], y);
            xM[x] = max(xM[x], y);
            ym[y] = min(ym[y], x);
            yM[y] = max(yM[y], x);
        }
        int ans = 0;
        for (vector<int>& building : buildings) {
            int x = building[0], y = building[1];
            ans += xm[x] < y && y < xM[x] && ym[y] < x && x < yM[y];
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-12-11 13:27:34
'''
from typing import List

class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        n += 1
        xm = [n] * n
        xM = [0] * n
        ym = [n] * n
        yM = [0] * n
        for x, y in buildings:
            xm[x] = min(xm[x], y)
            xM[x] = max(xM[x], y)
            ym[y] = min(ym[y], x)
            yM[y] = max(yM[y], x)
        ans = 0
        for x, y in buildings:
            ans += xm[x] < y < xM[x] and ym[y] < x < yM[y]
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2025-12-11 13:40:24
 */
import java.util.Arrays;

class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        n++;
        int[] xm = new int[n];
        int[] xM = new int[n];
        int[] ym = new int[n];
        int[] yM = new int[n];
        Arrays.fill(xm, n);
        Arrays.fill(ym, n);

        for (int[] building : buildings) {
            int x = building[0], y = building[1];
            xm[x] = Math.min(xm[x], y);
            xM[x] = Math.max(xM[x], y);
            ym[y] = Math.min(ym[y], x);
            yM[y] = Math.max(yM[y], x);
        }

        int ans = 0;
        for (int[] building : buildings) {
            int x = building[0], y = building[1];
            if (xm[x] < y && y < xM[x] && ym[y] < x && x < yM[y]) {
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-11 13:35:38
 */
package main

func countCoveredBuildings(n int, buildings [][]int) (ans int) {
    n++
    xm := make([]int, n)
    xM := make([]int, n)
    ym := make([]int, n)
    yM := make([]int, n)
    for i := range xm {
        xm[i] = n
        ym[i] = n
    }

    for _, building := range buildings {
        x, y := building[0], building[1]
        xm[x] = min(xm[x], y)
        xM[x] = max(xM[x], y)
        ym[y] = min(ym[y], x)
        yM[y] = max(yM[y], x)
    }

    for _, building := range buildings {
        x, y := building[0], building[1]
        if xm[x] < y && y < xM[x] && ym[y] < x && x < yM[y] {
            ans++
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-11 13:48:09
 */
impl Solution {
    pub fn count_covered_buildings(mut n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        n += 1;
        let mut xm: Vec<i32> = vec![n; n as usize];
        let mut xM: Vec<i32> = vec![0; n as usize];
        let mut ym: Vec<i32> = vec![n; n as usize];
        let mut yM: Vec<i32> = vec![0; n as usize];

        for building in buildings.iter() {
            let x: i32 = building[0];
            let y: i32 = building[1];
            xm[x as usize] = xm[x as usize].min(y);
            xM[x as usize] = xM[x as usize].max(y);
            ym[y as usize] = ym[y as usize].min(x);
            yM[y as usize] = yM[y as usize].max(x);
        }

        let mut ans: i32 = 0;
        for building in buildings.iter() {
            let x: i32 = building[0];
            let y: i32 = building[1];
            if xm[x as usize] < y && y < xM[x as usize] && ym[y as usize] < x && x < yM[y as usize] {
                ans += 1;
            }
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/155824933)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/11/LeetCode%203531.%E7%BB%9F%E8%AE%A1%E8%A2%AB%E8%A6%86%E7%9B%96%E7%9A%84%E5%BB%BA%E7%AD%91/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
