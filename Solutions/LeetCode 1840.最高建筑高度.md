---
title: 1840.最高建筑高度：左右两次扫描，传递限制约束(没有很多头痛公式版)
date: 2026-06-20 11:18:57
tags: [题解, LeetCode, 困难, 数组, 数学, 排序]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex2.png
---

# 【LetMeFly】1840.最高建筑高度：左右两次扫描，传递限制约束(没有很多头痛公式版)

力扣题目链接：[https://leetcode.cn/problems/maximum-building-height/](https://leetcode.cn/problems/maximum-building-height/)

<p>在一座城市里，你需要建 <code>n</code> 栋新的建筑。这些新的建筑会从 <code>1</code> 到 <code>n</code> 编号排成一列。</p>

<p>这座城市对这些新建筑有一些规定：</p>

<ul>
	<li>每栋建筑的高度必须是一个非负整数。</li>
	<li>第一栋建筑的高度 <strong>必须</strong> 是 <code>0</code> 。</li>
	<li>任意两栋相邻建筑的高度差 <strong>不能超过</strong>  <code>1</code> 。</li>
</ul>

<p>除此以外，某些建筑还有额外的最高高度限制。这些限制会以二维整数数组 <code>restrictions</code> 的形式给出，其中 <code>restrictions[i] = [id<sub>i</sub>, maxHeight<sub>i</sub>]</code> ，表示建筑 <code>id<sub>i</sub></code> 的高度 <strong>不能超过</strong> <code>maxHeight<sub>i</sub></code> 。</p>

<p>题目保证每栋建筑在 <code>restrictions</code> 中<strong> 至多出现一次</strong> ，同时建筑 <code>1</code> <strong>不会</strong> 出现在 <code>restrictions</code> 中。</p>

<p>请你返回 <strong>最高</strong> 建筑能达到的 <strong>最高高度</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex1-1.png" style="width: 400px; height: 253px;" />
<pre>
<b>输入：</b>n = 5, restrictions = [[2,1],[4,1]]
<b>输出：</b>2
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,1,2] ，最高建筑的高度为 2 。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex2.png" style="width: 500px; height: 269px;" />
<pre>
<b>输入：</b>n = 6, restrictions = []
<b>输出：</b>5
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,4,5] ，最高建筑的高度为 5 。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2021/04/25/ic236-q4-ex3.png" style="width: 500px; height: 187px;" />
<pre>
<b>输入：</b>n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
<b>输出：</b>5
<b>解释：</b>上图中的绿色区域为每栋建筑被允许的最高高度。
我们可以使建筑高度分别为 [0,1,2,3,3,4,4,5,4,3] ，最高建筑的高度为 5 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10<sup>9</sup></code></li>
	<li><code>0 <= restrictions.length <= min(n - 1, 10<sup>5</sup>)</code></li>
	<li><code>2 <= id<sub>i</sub> <= n</code></li>
	<li><code>id<sub>i</sub></code> 是 <strong>唯一的</strong> 。</li>
	<li><code>0 <= maxHeight<sub>i</sub> <= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：从左到右限制一次 + 从右到左限制一次

假设能确定坐标$a$的楼**可以**达到$ha$这么高，其右边坐标$b$的楼**可以**达到$hb$这么高，那么从$a$到$b$这段区间的楼最多能有多高呢？

> 不妨假设$ha\leq hb$，那么楼高总体上呈现先上升后下降的趋势。$a$处楼高$ha$，$a+1$处楼高$ha+1$，...，$a + (hb-ha)$处楼高$hb$（和$b$处等高）。
>
> $a + (hb-ha)$处和$b$处楼都高$hb$，如果二者之间有一栋或两栋楼则最高高度可达$hb+1$，如果二者之间有三栋或四栋楼则最高高度可达$hb+2$，...，如果二者之间有$n$栋楼则最高高度可达$hb+\lfloor\frac{n+1}{2}\rfloor$。由于二者之间有$b-a-(hb-ha)-1$栋楼所以二者之间最高高度可达$hb+\lfloor\frac{b-a-(hb-ha)}{2}\rfloor$，即为从$a$到$b$这段范围的最大楼高。
>
> 如果$ha\gt hb$同理，不妨直接交换$ha$和$hb$使得$ha\lt hb$，这样并不影响这段区间的最大楼高计算结果。

现在问题是每个关键坐标的最大楼高确定了吗？还没有。

> 前面讨论的前提是坐标$a$的楼**可以**达到$ha$这么高，而题目中给的$maxHeight$限制不一定能达到！
>
> 例如假设坐标$5$的楼最高为$3$，那么坐标$7$的楼最高为$5$，即使题目中给$restrictions[i]=[7, 99999]$的限制也达不到。

最终剩下了如何确定每个关键点的最大高度这一个关键问题了，很简单：

> 一个楼的最大高度限制除了题目给定的自身限制以外，还有来自其左右楼高的限制。
>
> 我们从左到右遍历一遍关键坐标的楼高并传递更新最大楼高限制，再从右往左遍历一遍传递更新最大楼高限制，不就ok了吗？
>
> 假设坐标$a$的楼高限制是$ha$，那么其右边坐标$b$的楼高最多为$ha+b-a$。
>
> 注意题目中还有两个初始情况下的额外限制：坐标$1$最大高度$0$，坐标$n$最大高度$+\infty$。

时空复杂度分析：

+ 时间复杂度$O(m\log m)$，其中$m=len(restrictions)$，$\log m$的时间复杂度来自排序；
+ 空间复杂度$O(\log m)$。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-20 11:17:44
 */
/*
从左到右限制一遍再从右到左限制一遍是不是就可以了呢？是不是不需要由较低的高度往两边限制呢？
*/
class Solution {
private:
    int cal(int a, int ha, int b, int hb) {
        if (ha > hb) {
            swap(ha, hb);
        }
        return hb + (b - a - (hb - ha)) / 2;
    }
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, INT_MAX});
        sort(restrictions.begin(), restrictions.end());
        for (int i = 1; i < restrictions.size(); i++) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + restrictions[i][0] - restrictions[i - 1][0]);
        }
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]);
        }
        
        int ans = 0;
        for (int i = 1; i < restrictions.size(); i++) {
            ans = max(ans, cal(restrictions[i - 1][0], restrictions[i - 1][1], restrictions[i][0], restrictions[i][1]));
        }
        return ans;
    }

    void testCal() {
        assert(cal(7, 3, 10, 4) == 5);
        assert(cal(7, 4, 10, 3) == 5);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162142809)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/20/LeetCode%201840.%E6%9C%80%E9%AB%98%E5%BB%BA%E7%AD%91%E9%AB%98%E5%BA%A6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
