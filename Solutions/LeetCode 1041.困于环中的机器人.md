---
title: 1041.困于环中的机器人
date: 2023-04-11 11:00:14
tags: [题解, LeetCode, 中等, 数学, 字符串, 模拟, 坐标]
---

# 【LetMeFly】1041.困于环中的机器人

力扣题目链接：[https://leetcode.cn/problems/robot-bounded-in-circle/](https://leetcode.cn/problems/robot-bounded-in-circle/)

<p>在无限的平面上，机器人最初位于&nbsp;<code>(0, 0)</code>&nbsp;处，面朝北方。注意:</p>

<ul>
	<li><strong>北方向</strong> 是y轴的正方向。</li>
	<li><strong>南方向</strong> 是y轴的负方向。</li>
	<li><strong>东方向</strong> 是x轴的正方向。</li>
	<li><strong>西方向</strong> 是x轴的负方向。</li>
</ul>

<p>机器人可以接受下列三条指令之一：</p>

<ul>
	<li><code>"G"</code>：直走 1 个单位</li>
	<li><code>"L"</code>：左转 90 度</li>
	<li><code>"R"</code>：右转 90 度</li>
</ul>

<p>机器人按顺序执行指令&nbsp;<code>instructions</code>，并一直重复它们。</p>

<p>只有在平面中存在环使得机器人永远无法离开时，返回&nbsp;<code>true</code>。否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>instructions = "GGLLGG"
<strong>输出：</strong>true
<strong>解释：</strong>机器人最初在(0,0)处，面向北方。
“G”:移动一步。位置:(0,1)方向:北。
“G”:移动一步。位置:(0,2).方向:北。
“L”:逆时针旋转90度。位置:(0,2).方向:西。
“L”:逆时针旋转90度。位置:(0,2)方向:南。
“G”:移动一步。位置:(0,1)方向:南。
“G”:移动一步。位置:(0,0)方向:南。
重复指令，机器人进入循环:(0,0)——&gt;(0,1)——&gt;(0,2)——&gt;(0,1)——&gt;(0,0)。
在此基础上，我们返回true。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>instructions = "GG"
<strong>输出：</strong>false
<strong>解释：</strong>机器人最初在(0,0)处，面向北方。
“G”:移动一步。位置:(0,1)方向:北。
“G”:移动一步。位置:(0,2).方向:北。
重复这些指示，继续朝北前进，不会进入循环。
在此基础上，返回false。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>instructions = "GL"
<strong>输出：</strong>true
<strong>解释：</strong>机器人最初在(0,0)处，面向北方。
“G”:移动一步。位置:(0,1)方向:北。
“L”:逆时针旋转90度。位置:(0,1).方向:西。
“G”:移动一步。位置:(- 1,1)方向:西。
“L”:逆时针旋转90度。位置:(- 1,1)方向:南。
“G”:移动一步。位置:(- 1,0)方向:南。
“L”:逆时针旋转90度。位置:(- 1,0)方向:东方。
“G”:移动一步。位置:(0,0)方向:东方。
“L”:逆时针旋转90度。位置:(0,0)方向:北。
重复指令，机器人进入循环:(0,0)——&gt;(0,1)——&gt;(- 1,1)——&gt;(- 1,0)——&gt;(0,0)。
在此基础上，我们返回true。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= instructions.length &lt;= 100</code></li>
	<li><code>instructions[i]</code>&nbsp;仅包含&nbsp;<code>'G', 'L', 'R'</code></li>
</ul>


    
## 方法一：模拟

### 解题思路

首先需要明确的是，执行一次```instructions```，结束状态为什么的时候说明会被困住（多次执行会循环）

当执行结束时，恰好回到了起点 或者 当前方向不为北  的话，多次执行必定会回到起点。

首先如果执行一次回到了起点，那么之后执行也会回到起点，顶多每次的方向不同；

其次如果结束时方向不为北的话，4次或2次内就会绕回到起点。例如：```GL```等。

### 具体方法

知道了解题思路，怎么编程实现模拟呢？

首先我们可以定义一个数组，代表朝向为北东南西时，前进一步的坐标变化。```directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]```

接着使用一个变量记录当前方向，向右转时方向加一并对4取模，向左转时方向加三并对4取模（相当于方向减一后取模），向前走时就坐标累加即可。

（当然，无脑模拟4次判断是否回到了起点也可以）

+ 时间复杂度$O(len(instructions))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
const int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 北东南西

class Solution {
public:
    bool isRobotBounded(string& instructions) {
        int nowDirection = 0;
        int x = 0, y = 0;
        for (char c : instructions) {
            if (c == 'G') {
                x += directions[nowDirection][0];
                y += directions[nowDirection][1];
            }
            else if (c == 'L') {
                nowDirection = (nowDirection + 3) % 4;
            }
            else {
                nowDirection = (nowDirection + 1) % 4;
            }
        }
        return nowDirection || (!x && !y);
    }
};
```

#### Python

```python
directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        nowDirection = 0
        x, y = 0, 0
        for c in instructions:
            if c == 'G':
                x += directions[nowDirection][0]
                y += directions[nowDirection][1]
            elif c == 'L':
                nowDirection = (nowDirection + 3) % 4
            else:
                nowDirection = (nowDirection + 1) % 4
        return nowDirection != 0 or (not x and not y)
```



> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/11/LeetCode%201041.%E5%9B%B0%E4%BA%8E%E7%8E%AF%E4%B8%AD%E7%9A%84%E6%9C%BA%E5%99%A8%E4%BA%BA/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130079272](https://letmefly.blog.csdn.net/article/details/130079272)
