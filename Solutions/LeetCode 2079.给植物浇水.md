---
title: 2079.给植物浇水
date: 2024-05-08 18:14:11
tags: [题解, LeetCode, 中等, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】2079.给植物浇水：O(n)模拟

力扣题目链接：[https://leetcode.cn/problems/watering-plants/](https://leetcode.cn/problems/watering-plants/)

<p>你打算用一个水罐给花园里的 <code>n</code> 株植物浇水。植物排成一行，从左到右进行标记，编号从 <code>0</code> 到 <code>n - 1</code> 。其中，第 <code>i</code> 株植物的位置是 <code>x = i</code> 。<code>x = -1</code>&nbsp;处有一条河，你可以在那里重新灌满你的水罐。</p>

<p>每一株植物都需要浇特定量的水。你将会按下面描述的方式完成浇水：</p>

<ul>
	<li>按从左到右的顺序给植物浇水。</li>
	<li>在给当前植物浇完水之后，如果你没有足够的水 <strong>完全</strong> 浇灌下一株植物，那么你就需要返回河边重新装满水罐。</li>
	<li>你 <strong>不能</strong> 提前重新灌满水罐。</li>
</ul>

<p>最初，你在河边（也就是，<code>x = -1</code>），在 x 轴上每移动 <strong>一个单位</strong>&nbsp;都需要 <strong>一步</strong> 。</p>

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>plants</code> ，数组由 <code>n</code> 个整数组成。其中，<code>plants[i]</code> 为第 <code>i</code> 株植物需要的水量。另有一个整数 <code>capacity</code> 表示水罐的容量，返回浇灌所有植物需要的 <strong>步数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>plants = [2,2,3,3], capacity = 5
<strong>输出：</strong>14
<strong>解释：</strong>从河边开始，此时水罐是装满的：
- 走到植物 0 (1 步) ，浇水。水罐中还有 3 单位的水。
- 走到植物 1 (1 步) ，浇水。水罐中还有 1 单位的水。
- 由于不能完全浇灌植物 2 ，回到河边取水 (2 步)。
- 走到植物 2 (3 步) ，浇水。水罐中还有 2 单位的水。
- 由于不能完全浇灌植物 3 ，回到河边取水 (3 步)。
- 走到植物 3 (4 步) ，浇水。
需要的步数是 = 1 + 1 + 2 + 3 + 3 + 4 = 14 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>plants = [1,1,1,4,2,3], capacity = 4
<strong>输出：</strong>30
<strong>解释：</strong>从河边开始，此时水罐是装满的：
- 走到植物 0，1，2 (3 步) ，浇水。回到河边取水 (3 步)。
- 走到植物 3 (4 步) ，浇水。回到河边取水 (4 步)。
- 走到植物 4 (5 步) ，浇水。回到河边取水 (5 步)。
- 走到植物 5 (6 步) ，浇水。
需要的步数是 = 3 + 3 + 4 + 4 + 5 + 5 + 6 = 30 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>plants = [7,7,7,7,7,7,7], capacity = 8
<strong>输出：</strong>49
<strong>解释：</strong>每次浇水都需要重新灌满水罐。
需要的步数是 = 1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 + 5 + 5 + 6 + 6 + 7 = 49 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == plants.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= plants[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>max(plants[i]) &lt;= capacity &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：模拟

使用一个变量```step```来记录走过的总步数，使用一个变量```now```来记录当前的水量。

接着开始遍历植物数组：

> 如果当前水量＜植物所需，说明上一步就应该返回并重新打水（```step += i + i```）。
>
> 从上一植物走到这一植物（```step += 1```），并给这一植物浇水（```now -= plants[i]```）。

然后就没有然后了，浇完水也不用回到河边。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step = 0;
        int now = capacity;
        for (int i = 0; i < plants.size(); i++) {
            if (now < plants[i]) {  // 上一步应该返回
                step += i + i;
                now = capacity;
            }
            step++;
            now -= plants[i];
        }
        return step;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        step = 0
        now = capacity
        for i in range(len(plants)):
            if now < plants[i]:
                step += i + i
                now = capacity
            step += 1
            now -= plants[i]
        return step
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/08/LeetCode%202079.%E7%BB%99%E6%A4%8D%E7%89%A9%E6%B5%87%E6%B0%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138581691](https://letmefly.blog.csdn.net/article/details/138581691)
