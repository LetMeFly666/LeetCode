---
title: 1620.网络信号最好的坐标
date: 2022-11-02 09:52:15
tags: [题解, LeetCode, 中等, 数组, 枚举, 暴力]
---

# 【LetMeFly】1620.网络信号最好的坐标

力扣题目链接：[https://leetcode.cn/problems/coordinate-with-maximum-network-quality/](https://leetcode.cn/problems/coordinate-with-maximum-network-quality/)

<p>给你一个数组 <code>towers</code> 和一个整数 <code>radius</code> ，数组中包含一些网络信号塔，其中 <code>towers[i] = [x<sub>i</sub>, y<sub>i</sub>, q<sub>i</sub>]</code> 表示第 <code>i</code> 个网络信号塔的坐标是 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> 且信号强度参数为 <code>q<sub>i</sub></code><sub> </sub>。所有坐标都是在  X-Y 坐标系内的 <strong>整数</strong> 坐标。两个坐标之间的距离用 <strong>欧几里得距离</strong> 计算。</p>

<p>整数 <code>radius</code> 表示一个塔 <strong>能到达 </strong>的 <strong>最远距离</strong> 。如果一个坐标跟塔的距离在 <code>radius</code> 以内，那么该塔的信号可以到达该坐标。在这个范围以外信号会很微弱，所以 <code>radius</code> 以外的距离该塔是 <strong>不能到达的</strong> 。</p>

<p>如果第 <code>i</code> 个塔能到达 <code>(x, y)</code> ，那么该塔在此处的信号为 <code>⌊q<sub>i</sub> / (1 + d)⌋</code> ，其中 <code>d</code> 是塔跟此坐标的距离。一个坐标的 <b>网络信号</b> 是所有 <strong>能到达 </strong>该坐标的塔的信号强度之和。</p>

<p>请你返回 <strong>网络信号</strong> 最大的整数坐标点。如果有多个坐标网络信号一样大，请你返回字典序最小的一个坐标。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>坐标 <code>(x1, y1)</code> 字典序比另一个坐标 <code>(x2, y2)</code> 小：要么 <code>x1 < x2</code> ，要么 <code>x1 == x2</code> 且 <code>y1 < y2</code> 。</li>
	<li><code>⌊val⌋</code> 表示小于等于 <code>val</code> 的最大整数（向下取整函数）。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/17/untitled-diagram.png" style="width: 176px; height: 176px;" />
<pre>
<b>输入：</b>towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
<b>输出：</b>[2,1]
<strong>解释：</strong>
坐标 (2, 1) 信号强度之和为 13
- 塔 (2, 1) 强度参数为 7 ，在该点强度为 ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
- 塔 (1, 2) 强度参数为 5 ，在该点强度为 ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
- 塔 (3, 1) 强度参数为 9 ，在该点强度为 ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
没有别的坐标有更大的信号强度。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>towers = [[23,11,21]], radius = 9
<b>输出：</b>[23,11]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
<b>输出：</b>[1,2]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>towers = [[2,1,9],[0,1,9]], radius = 2
<b>输出：</b>[0,1]
<strong>解释：</strong>坐标 (0, 1) 和坐标 (2, 1) 都是强度最大的位置，但是 (0, 1) 字典序更小。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= towers.length <= 50</code></li>
	<li><code>towers[i].length == 3</code></li>
	<li><code>0 <= x<sub>i</sub>, y<sub>i</sub>, q<sub>i</sub> <= 50</code></li>
	<li><code>1 <= radius <= 50</code></li>
</ul>


    
## 方法一：暴力枚举

这道题一看坐标范围，$0 \leq x_i, y_i, q_i \leq 50$，就能想到暴力枚举了。

因为所有的“塔”都在$[0, 50]$的范围内，因此信号强度最大的地方一定也在$[0, 50]$的范围内

我们只需要枚举$x, y$从$0$到$50$的所有点，对于每个点，分别求出每个“塔”到达此点的信号之和

如果这个点的信号优于当前最优解，就更新最优解以及最优解多对应的下标

如果这个点的信号强度和当前最优解相等，那么将这个点的坐标和当前最优解的坐标比较，取字典序更小的那个。

+ 时间复杂度$O(L^2\times n)$，其中$L$是$51$（$0$到$50$），$n$是“塔”的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int M = 0;
        vector<int> ans = {0, 0};
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                int power = 0;
                for (auto& tower : towers) {
                    auto distance = sqrt((tower[0] - i) * (tower[0] - i) + (tower[1] - j) * (tower[1] - j));
                    if (distance <= radius)
                        power += tower[2] / (1 + distance);
                }
                if (power > M) {
                    M = power;
                    ans = {i, j};
                }
                else if (power == M) {
                    ans = min(ans, {i, j});
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/02/LeetCode%201620.%E7%BD%91%E7%BB%9C%E4%BF%A1%E5%8F%B7%E6%9C%80%E5%A5%BD%E7%9A%84%E5%9D%90%E6%A0%87/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127646389](https://letmefly.blog.csdn.net/article/details/127646389)
