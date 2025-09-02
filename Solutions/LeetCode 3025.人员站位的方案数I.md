---
title: 3025.人员站位的方案数 I：既然是I，那就先暴力吧（三层循环）
date: 2025-09-02 18:57:13
tags: [题解, LeetCode, 中等, 几何, 数组, 数学, 枚举, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3025.人员站位的方案数 I：既然是I，那就先暴力吧（三层循环）

力扣题目链接：[https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-i/](https://leetcode.cn/problems/find-the-number-of-ways-to-place-people-i/)

<p>给你一个&nbsp;&nbsp;<code>n x 2</code>&nbsp;的二维数组 <code>points</code>&nbsp;，它表示二维平面上的一些点坐标，其中&nbsp;<code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;。</p>

<p>&nbsp;</p>

<p>计算点对&nbsp;<code>(A, B)</code>&nbsp;的数量，其中</p>

<ul>
	<li><code>A</code> 在 <code>B</code> 的左上角，并且</li>
	<li>它们形成的长方形中（或直线上）没有其它点（<strong>包括边界</strong>）。</li>
</ul>

<p>返回数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>points = [[1,1],[2,2],[3,3]]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2024/01/04/example1alicebob.png" style="width: 427px; height: 350px;" /></p>

<p>没有办法选择&nbsp;<code>A</code> 和&nbsp;<code>B</code>，使得&nbsp;<code>A</code>&nbsp;在&nbsp;<code>B</code>&nbsp;的左上角。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">points = [[6,2],[4,4],[2,6]]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img height="365" src="https://assets.leetcode.com/uploads/2024/06/25/t2.jpg" width="1321" /></p>

<ul>
	<li>左边的是点对&nbsp;<code>(points[1], points[0])</code>，其中&nbsp;<code>points[1]</code>&nbsp;在&nbsp;<code>points[0]</code>&nbsp;的左上角，并且形成的长方形内部是空的。</li>
	<li>中间的是点对&nbsp;<code>(points[2], points[1])</code>，和左边的一样是合法的点对。</li>
	<li>右边的是点对 <code>(points[2], points[0])</code>，其中 <code>points[2]</code> 在 <code>points[0]</code>&nbsp;的左上角，但&nbsp;<code>points[1]</code>&nbsp;在长方形内部，所以不是一个合法的点对。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">points = [[3,1],[1,3],[1,1]]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2024/06/25/t3.jpg" style="width: 1269px; height: 350px;" /></p>

<ul>
	<li>左边的是点对 <code>(points[2], points[0])</code>，其中&nbsp;<code>points[2]</code>&nbsp;在&nbsp;<code>points[0]</code>&nbsp;的左上角并且在它们形成的直线上没有其它点。注意两个点形成一条线的情况是合法的。</li>
	<li>中间的是点对 <code>(points[1], points[2])</code>，和左边一样也是合法的点对。</li>
	<li>右边的是点对 <code>(points[1], points[0])</code>，它不是合法的点对，因为&nbsp;<code>points[2]</code>&nbsp;在长方形的边上。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 50</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>0 &lt;= points[i][0], points[i][1] &lt;= 50</code></li>
	<li><code>points[i]</code>&nbsp;点对两两不同。</li>
</ul>


    
## 解题方法：三层循环模拟

第一层循环使用$i$和$j$分别枚举每个点，如果$i\neq j$并且$points[i]$在$points[j]$的左上方，则继续：

第三层循环使用$k$再次枚举每个点，枚举之前使用一个变量$can=true$。如果$points[k]$在$points[i]$和$points[j]$的中间，则令$can=false$并退出第三层循环。

如果第三层循环没有将$can$设置为$false$，则答案数量加一。

+ 时间复杂度$O(len(points)^3)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 13:08:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 13:51:14
 * @Description: rewrite from 0
 */
class Solution {
private:
    inline bool check(vector<vector<int>>& points, int i, int j) {
        return i != j && points[i][0] <= points[j][0] && points[i][1] >= points[j][1];
    }

    inline bool check(vector<vector<int>>& points, int i, int j, int k) {
        return !(points[i][0] <= points[k][0] && points[k][0] <= points[j][0]
              && points[i][1] >= points[k][1] && points[k][1] >= points[j][1]);
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (!check(points, i, j)) {
                    continue;
                }
                bool can = true;
                for (int k = 0; k < points.size(); k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (!check(points, i, j, k)) {
                        can = false;
                        break;
                    }
                }
                ans += can;
            }
        }
        return ans;
    }
}; 
```

#### C++ —— 原始版本（思考过程）可跳过

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 13:08:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 13:45:45
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline bool check(vector<vector<int>>& points, int i, int j) {  // 易错点3：单独的(i, j)也要check
        if (points[i][0] > points[j][0] || points[i][1] < points[j][1]) {  // 易错点1：注意这里纵坐标大于等于才合法
            return false;
        }
        return true;
    }
    inline bool check(vector<vector<int>>& points, int i, int j, int k) {
        if (points[i][0] <= points[k][0] && points[k][0] <= points[j][0] && points[i][1] >= points[k][1] && points[k][1] >= points[j][1]) {
            return false;
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (!check(points, i, j)) {
                    continue;
                }
                bool can = true;  // 易错点2：有一个k导致不符就不符
                for (int k = 0; k < points.size(); k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (!check(points, i, j, k)) {
                        can = false;
                        break;
                    }
                }
                ans += can;
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[[1,1],[2,2],[3,3]]

0
*/
/*
[[0,0],[0,3]]

1
*/
/*
[[6,2],[4,4],[2,6]]

(2,1) (1, 0)

2
*/
/*
[[0,0],[0,3]]

1
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.numberOfPairs(v) << endl;
    }
    return 0;
}
#endif
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-02 13:08:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-02 18:47:49
'''
from typing import List

class Solution:
    def check2(self, i: int, j: int) -> bool:
        return self.points[i][0] <= self.points[j][0] and self.points[i][1] >= self.points[j][1]
    
    def check3(self, i: int, j: int, k: int) -> bool:
        return not (self.points[i][0] <= self.points[k][0] <= self.points[j][0] and self.points[i][1] >= self.points[k][1] >= self.points[j][1])
    
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        n = len(points)
        self.points = points
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if not self.check2(i, j):
                    continue
                can = True
                for k in range(n):
                    if k == i or k == j:
                        continue
                    if not self.check3(i, j, k):
                        can = False
                        break
                ans += can
        return ans
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 13:08:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 18:53:07
 */
package main

func check2_3025(points [][]int, i, j int) bool {
    return points[i][0] <= points[j][0] && points[i][1] >= points[j][1]
}

func check3_3025(points [][]int, i, j, k int) bool {
    return !(points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
             points[i][1] >= points[k][1] && points[k][1] >= points[j][1])
}

func numberOfPairs(points [][]int) (ans int) {
    for i := range points {
        for j := range points {
            if i == j {
                continue
            }
            if !check2_3025(points, i, j) {
                continue
            }
            can := true
            for k := range points {
                if k == i || k == j {
                    continue
                }
                if !check3_3025(points, i, j, k) {
                    can = false
                    break
                }
            }
            if can {
                ans++
            }
        }
    }
    return
}
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-09-02 20:09:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-02 20:14:52
 */
class Solution {
    private int[][] points;

    private boolean check(int i, int j) {
        return points[i][0] <= points[j][0] && points[i][1] >= points[j][1];
    }

    private boolean check(int i, int j, int k) {
        return !(points[i][0] <= points[k][0] && points[k][0] <= points[j][0] && points[i][1] >= points[k][1] && points[k][1] >= points[j][1]);
    }

    public int numberOfPairs(int[][] points) {
        int ans = 0;
        this.points = points;
        for (int i = 0; i < points.length; i++) {
            for (int j = 0; j < points.length; j++) {
                if (i == j) {
                    continue;
                }
                if (!check(i, j)) {
                    continue;
                }
                boolean can = true;
                for (int k = 0; k < points.length; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (!check(i, j, k)) {
                        can = false;
                        break;
                    }
                }
                if (can) {
                    ans ++;
                }
            }
        }
        return ans;
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151119511)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/02/LeetCode%203025.%E4%BA%BA%E5%91%98%E7%AB%99%E4%BD%8D%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
