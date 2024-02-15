---
title: 2481.分割圆的最少切割次数
date: 2023-06-17 09:58:16
tags: [题解, LeetCode, 简单, 几何, 数学, 思维]
---

# 【LetMeFly】2481.分割圆的最少切割次数

力扣题目链接：[https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/](https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/)

<p>圆内一个 <strong>有效切割</strong>&nbsp;，符合以下二者之一：</p>

<ul>
	<li>该切割是两个端点在圆上的线段，且该线段经过圆心。</li>
	<li>该切割是一端在圆心另一端在圆上的线段。</li>
</ul>

<p>一些有效和无效的切割如下图所示。</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/29/alldrawio.png" style="width: 450px; height: 174px;" /></p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，请你返回将圆切割成相等的&nbsp;<code>n</code>&nbsp;等分的&nbsp;<strong>最少</strong>&nbsp;切割次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/24/11drawio.png" style="width: 200px; height: 200px;" /></p>

<pre>
<b>输入：</b>n = 4
<b>输出：</b>2
<b>解释：</b>
上图展示了切割圆 2 次，得到四等分。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/24/22drawio.png" style="width: 200px; height: 201px;" /></p>

<pre>
<b>输入：</b>n = 3
<b>输出：</b>3
<strong>解释：</strong>
最少需要切割 3 次，将圆切成三等分。
少于 3 次切割无法将圆切成大小相等面积相同的 3 等分。
同时可以观察到，第一次切割无法将圆切割开。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>


    
## 方法一：几何

这道题意思是：最少使用几条```直径/半径```，能把圆$n$等分。

其实分为两种情况考虑即可：

+ 如果$n$是偶数，我们使用直径分割，每多一条直径，所分成的块数$+2$
+ 如果$n$是奇数，那么无法使用直径分割（否则无法做到等分），每多一条半径，所分成的块数$12$

**特别的：** 如果要把圆分成1块，那么使用一条半径分割没有意义（因此返回$0$）

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) {
            return 0;
        }
        return n % 2 ? n : n / 2;
    }
};
```

#### Python

```python
class Solution:
    def numberOfCuts(self, n: int) -> int:
        if n == 1:
            return 0
        return n if n % 2 else n // 2
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/17/LeetCode%202481.%E5%88%86%E5%89%B2%E5%9C%86%E7%9A%84%E6%9C%80%E5%B0%91%E5%88%87%E5%89%B2%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131257304](https://letmefly.blog.csdn.net/article/details/131257304)
