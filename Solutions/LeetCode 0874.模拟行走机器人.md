---
title: 874.模拟行走机器人：哈希表模拟
date: 2023-07-19 09:01:26
tags: [题解, LeetCode, 中等, 数组, 模拟, 哈希表, 哈希, set]
---

# 【LetMeFly】874.模拟行走机器人：哈希表模拟

力扣题目链接：[https://leetcode.cn/problems/walking-robot-simulation/](https://leetcode.cn/problems/walking-robot-simulation/)

<p>机器人在一个无限大小的 XY 网格平面上行走，从点 <code>(0, 0)</code> 处开始出发，面向北方。该机器人可以接收以下三种类型的命令 <code>commands</code> ：</p>

<ul>
	<li><code>-2</code> ：向左转 <code>90</code> 度</li>
	<li><code>-1</code> ：向右转 <code>90</code> 度</li>
	<li><code>1 <= x <= 9</code> ：向前移动 <code>x</code> 个单位长度</li>
</ul>

<p>在网格上有一些格子被视为障碍物 <code>obstacles</code> 。第 <code>i</code> 个障碍物位于网格点  <code>obstacles[i] = (x<sub>i</sub>, y<sub>i</sub>)</code> 。</p>

<p>机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续尝试进行该路线的其余部分。</p>

<p>返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。（即，如果距离为 <code>5</code> ，则返回 <code>25</code> ）</p>

<div class="d-google dictRoot saladict-panel isAnimate">
<div>
<div class="MachineTrans-Text">
<div class="MachineTrans-Lines">
<div class="MachineTrans-Lines-collapse MachineTrans-lang-en"> </div>
</div>

<div class="MachineTrans-Lines">
<p class="MachineTrans-lang-zh-CN"><strong>注意：</strong></p>

<ul>
	<li class="MachineTrans-lang-zh-CN">北表示 <code>+Y</code> 方向。</li>
	<li class="MachineTrans-lang-zh-CN">东表示 <code>+X</code> 方向。</li>
	<li class="MachineTrans-lang-zh-CN">南表示 <code>-Y</code> 方向。</li>
	<li class="MachineTrans-lang-zh-CN">西表示 <code>-X</code> 方向。</li>
</ul>
</div>
</div>
</div>
</div>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>commands = [4,-1,3], obstacles = []
<strong>输出：</strong>25
<strong>解释：
</strong>机器人开始位于 (0, 0)：
1. 向北移动 4 个单位，到达 (0, 4)
2. 右转
3. 向东移动 3 个单位，到达 (3, 4)
距离原点最远的是 (3, 4) ，距离为 3<sup>2</sup> + 4<sup>2</sup> = 25</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>commands = [4,-1,4,-2,4], obstacles = [[2,4]]
<strong>输出：</strong>65
<strong>解释</strong>：机器人开始位于 (0, 0)：
1. 向北移动 4 个单位，到达 (0, 4)
2. 右转
3. 向东移动 1 个单位，然后被位于 (2, 4) 的障碍物阻挡，机器人停在 (1, 4)
4. 左转
5. 向北走 4 个单位，到达 (1, 8)
距离原点最远的是 (1, 8) ，距离为 1<sup>2</sup> + 8<sup>2</sup> = 65</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= commands.length <= 10<sup>4</sup></code></li>
	<li><code>commands[i]</code> is one of the values in the list <code>[-2,-1,1,2,3,4,5,6,7,8,9]</code>.</li>
	<li><code>0 <= obstacles.length <= 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup> <= x<sub>i</sub>, y<sub>i</sub> <= 3 * 10<sup>4</sup></code></li>
	<li>答案保证小于 <code>2<sup>31</sup></code></li>
</ul>


    
## 方法一：哈希表模拟

先来看看数据量：最多移动$10^4$次，每次最多移动$9$步，完全可以一步一步地模拟。

因此，我们只需要建立一个[哈希表](https://blog.tisfy.eu.org/tags/%E5%93%88%E5%B8%8C%E8%A1%A8/)，将所有的障碍物存入哈希表中；接下来模拟机器人的每一步，遇到障碍就停下，否则就执行命令并更新答案最大值。

**细节处理：**

若所选编程语言不支持直接将“障碍物”放入哈希表中，则可以将$障碍物横坐标 \times 60001 + 障碍物纵坐标$放入哈希表中。这是因为地图中$x$的范围是$60001$

可以建立一个方向数组$directions$，使用一个下标$d$表示方向，横纵坐标分别加上$directions[d]$的$[0]$和$[1]$即为前进一步。

+ 时间复杂度$O(len(obstacles) + len(commands))$，其中每个command最多走9步，可以视为常数。
+ 空间复杂度$O(len(obstacles))$。

### AC代码

#### C++

```cpp
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // ↑→↓←

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> se;
        for (auto& obstacle : obstacles) {
            se.insert(obstacle[0] * 60001 + obstacle[1]);  // 30001不可，会无法通过最后一组数据，因为存在负数
        }

        int nowDirection = 0, x = 0, y = 0;
        int ans = 0;
        for (int t : commands) {
            if (t == -2) {
                nowDirection = (nowDirection + 3) % 4;
            }
            else if (t == -1) {
                nowDirection = (nowDirection + 1) % 4;
            }
            else {
                for (int i = 0; i < t; i++) {
                    int tx = x + directions[nowDirection][0], ty = y + directions[nowDirection][1];
                    if (se.count(tx * 60001 + ty)) {
                        break;
                    }
                    x = tx, y = ty;
                    ans = max(ans, x * x + y * y);
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]  # ↑→↓←

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        se = set()
        for obstacle in obstacles:
            se.add(tuple(obstacle))
        
        x, y, nowDirection = 0, 0, 0
        ans = 0
        for command in commands:
            if command == -2:
                nowDirection = (nowDirection + 3) % 4
            elif command == -1:
                nowDirection = (nowDirection + 1) % 4
            else:
                for i in range(command):
                    tx, ty = x + directions[nowDirection][0], y + directions[nowDirection][1]
                    if (tx, ty) in se:
                        break
                    x, y = tx, ty
                    ans = max(ans, x * x + y * y)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/07/19/LeetCode%200874.%E6%A8%A1%E6%8B%9F%E8%A1%8C%E8%B5%B0%E6%9C%BA%E5%99%A8%E4%BA%BA/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131800691](https://letmefly.blog.csdn.net/article/details/131800691)
