---
title: 1465.切割后面积最大的蛋糕
date: 2023-10-27 12:31:13
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1465.切割后面积最大的蛋糕：纵横分别处理

力扣题目链接：[https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/](https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)

<p>矩形蛋糕的高度为 <code>h</code> 且宽度为 <code>w</code>，给你两个整数数组 <code>horizontalCuts</code> 和 <code>verticalCuts</code>，其中：</p>

<ul>
	<li>&nbsp;<code>horizontalCuts[i]</code> 是从矩形蛋糕顶部到第&nbsp; <code>i</code> 个水平切口的距离</li>
	<li><code>verticalCuts[j]</code> 是从矩形蛋糕的左侧到第 <code>j</code> 个竖直切口的距离</li>
</ul>

<p>请你按数组 <em><code>horizontalCuts</code> </em>和<em> <code>verticalCuts</code> </em>中提供的水平和竖直位置切割后，请你找出 <strong>面积最大</strong> 的那份蛋糕，并返回其 <strong>面积</strong> 。由于答案可能是一个很大的数字，因此需要将结果&nbsp;<strong>对</strong>&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/leetcode_max_area_2.png" /></p>

<pre>
<strong>输入：</strong>h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
<strong>输出：</strong>4 
<strong>解释：</strong>上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色的那份蛋糕面积最大。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/leetcode_max_area_3.png" /></strong></p>

<pre>
<strong>输入：</strong>h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
<strong>输出：</strong>6
<strong>解释：</strong>上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色和黄色的两份蛋糕面积最大。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
<strong>输出：</strong>9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= h, w &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= horizontalCuts.length &lt;= min(h - 1, 10<sup>5</sup>)</code></li>
	<li><code>1 &lt;= verticalCuts.length &lt;= min(w - 1, 10<sup>5</sup>)</code></li>
	<li><code>1 &lt;= horizontalCuts[i] &lt; h</code></li>
	<li><code>1 &lt;= verticalCuts[i] &lt; w</code></li>
	<li>题目数据保证 <code>horizontalCuts</code> 中的所有元素各不相同</li>
	<li>题目数据保证 <code>verticalCuts</code>&nbsp;中的所有元素各不相同</li>
</ul>


    
## 方法一：纵横分别处理

横向的一刀和纵向的一刀之间是互不干扰的。因此，我们只需要求出“横向上的最大间隔”和“纵向上的最大间隔”，然后相乘即可。

对于单个方向：我们只需要求出“相邻两刀”的最大间隔，以及第一刀和最后一刀距离边界的值的最大值即可。

+ 时间复杂度$O(n\log n + m\log m)$
+ 空间复杂度$O(\log n + \log m)$

### AC代码

#### C++

```cpp
class Solution {
private:
    long long getMax(int l, vector<int>& v) {
        sort(v.begin(), v.end());
        int ans= 0;
        for (int i = 1; i < v.size(); i++) {
            ans = max(ans, v[i] -  v[i - 1]);
        }
        return max(ans, max(v[0], l - v[v.size() - 1]));
    }

public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return getMax(h, horizontalCuts) *  getMax(w, verticalCuts) % 1000000007;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def getMax(self, l: int, v: List[int]) -> int:
        v.sort()
        ans = v[0]
        for i in range(1, len(v)):
            ans = max(ans, v[i] - v[i - 1])
        return max(ans, l - v[-1])

    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        return self.getMax(h, horizontalCuts) * self.getMax(w, verticalCuts) % 1000000007
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/27/LeetCode%201465.%E5%88%87%E5%89%B2%E5%90%8E%E9%9D%A2%E7%A7%AF%E6%9C%80%E5%A4%A7%E7%9A%84%E8%9B%8B%E7%B3%95/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134073948](https://letmefly.blog.csdn.net/article/details/134073948)
