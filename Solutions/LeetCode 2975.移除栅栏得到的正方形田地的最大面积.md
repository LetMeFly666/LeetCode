---
title: 2975.移除栅栏得到的正方形田地的最大面积：暴力枚举所有可能宽度
date: 2026-01-17 21:10:06
tags: [题解, LeetCode, 中等, 数组, 哈希表, set, 枚举, 暴力]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2023/11/05/screenshot-from-2023-11-05-22-40-25.png
---

# 【LetMeFly】2975.移除栅栏得到的正方形田地的最大面积：暴力枚举所有可能宽度

力扣题目链接：[https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/](https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/)

<p>有一个大型的 <code>(m - 1) x (n - 1)</code> 矩形田地，其两个对角分别是 <code>(1, 1)</code> 和 <code>(m, n)</code> ，田地内部有一些水平栅栏和垂直栅栏，分别由数组 <code>hFences</code> 和 <code>vFences</code> 给出。</p>

<p>水平栅栏为坐标 <code>(hFences[i], 1)</code> 到 <code>(hFences[i], n)</code>，垂直栅栏为坐标 <code>(1, vFences[i])</code> 到 <code>(m, vFences[i])</code> 。</p>

<p>返回通过<strong> 移除 </strong>一些栅栏（<strong>可能不移除</strong>）所能形成的最大面积的<strong> 正方形 </strong>田地的面积，或者如果无法形成正方形田地则返回 <code>-1</code>。</p>

<p>由于答案可能很大，所以请返回结果对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的值。</p>

<p><strong>注意：</strong>田地外围两个水平栅栏（坐标 <code>(1, 1)</code> 到 <code>(1, n)</code> 和坐标 <code>(m, 1)</code> 到 <code>(m, n)</code> ）以及两个垂直栅栏（坐标 <code>(1, 1)</code> 到 <code>(m, 1)</code> 和坐标 <code>(1, n)</code> 到 <code>(m, n)</code> ）所包围。这些栅栏<strong> 不能</strong> 被移除。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/05/screenshot-from-2023-11-05-22-40-25.png" /></p>

<pre>
<strong>输入：</strong>m = 4, n = 3, hFences = [2,3], vFences = [2]
<strong>输出：</strong>4
<strong>解释：</strong>移除位于 2 的水平栅栏和位于 2 的垂直栅栏将得到一个面积为 4 的正方形田地。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/11/22/maxsquareareaexample1.png" style="width: 285px; height: 242px;" /></p>

<pre>
<strong>输入：</strong>m = 6, n = 7, hFences = [2], vFences = [4]
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明无法通过移除栅栏形成正方形田地。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= m, n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= hFences.length, vFences.length &lt;= 600</code></li>
	<li><code>1 &lt; hFences[i] &lt; m</code></li>
	<li><code>1 &lt; vFences[i] &lt; n</code></li>
	<li><code>hFences</code> 和 <code>vFences</code> 中的元素是唯一的。</li>
</ul>


    
## 解题方法：暴力枚举

水平竖直单看一个方向，可能的边长有哪些？

> 任意两个栅栏之间的距离都可以是边长，可以二重循环栅栏位置并将其放入哈希表中。

水平竖直一块看，如果一个边长在水平方向有可能得到，在竖直方向也有可能得到，那么就有办法得到这个长度为边长的正方形。

也就是两个哈希表求个交并取最大就好了。

+ 时间复杂度$O((len(hFences) + len(vFences))^2)$，这是因为$(a+b)^2=a^2+b^2+2ab$，复杂度中等于$a^2+b^2+ab$
+ 空间复杂度$O(len(hFences) + len(vFences))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-17 21:08:43
 */
class Solution {
private:
    unordered_set<int> get(int n, vector<int>& v) {
        v.push_back(1);
        v.push_back(n);
        unordered_set<int> ans;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                ans.insert(abs(v[i] - v[j]));
            }
        }
        return ans;
    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> va = get(m, hFences), vb = get(n, vFences);
        int side = 0;
        for (int a : va) {
            if (vb.count(a)) {
                side = max(side, a);
            }
        }
        return side ? (long long) side * side % 1000000007 : -1;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157068738)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/17/LeetCode%202975.%E7%A7%BB%E9%99%A4%E6%A0%85%E6%A0%8F%E5%BE%97%E5%88%B0%E7%9A%84%E6%AD%A3%E6%96%B9%E5%BD%A2%E7%94%B0%E5%9C%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%A2%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
