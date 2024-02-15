---
title: 1710.卡车上的最大单元数
date: 2022-11-15 09:06:20
tags: [题解, LeetCode, 简单, 贪心, 数组, 排序]
---

# 【LetMeFly】1710.卡车上的最大单元数

力扣题目链接：[https://leetcode.cn/problems/maximum-units-on-a-truck/](https://leetcode.cn/problems/maximum-units-on-a-truck/)

<p>请你将一些箱子装在 <strong>一辆卡车</strong> 上。给你一个二维数组 <code>boxTypes</code> ，其中 <code>boxTypes[i] = [numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>numberOfBoxes<sub>i</sub></code> 是类型 <code>i</code> 的箱子的数量。</li>
	<li><code>numberOfUnitsPerBox<sub>i</sub></code><sub> </sub>是类型 <code>i</code> 每个箱子可以装载的单元数量。</li>
</ul>

<p>整数 <code>truckSize</code> 表示卡车上可以装载 <strong>箱子</strong> 的 <strong>最大数量</strong> 。只要箱子数量不超过 <code>truckSize</code> ，你就可以选择任意箱子装到卡车上。</p>

<p>返回卡车可以装载 <strong>单元</strong> 的 <strong>最大</strong> 总数<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
<strong>输出：</strong>8
<strong>解释：</strong>箱子的情况如下：
- 1 个第一类的箱子，里面含 3 个单元。
- 2 个第二类的箱子，每个里面含 2 个单元。
- 3 个第三类的箱子，每个里面含 1 个单元。
可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
<strong>输出：</strong>91
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= boxTypes.length <= 1000</code></li>
	<li><code>1 <= numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub> <= 1000</code></li>
	<li><code>1 <= truckSize <= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：排序

感觉这道题汉语题目翻译得不是那么完美

箱子是等大小的，卡车一共能装```truckSize```个箱子。```boxTypes[i] = [5, 6]```代表第$i$**种**箱子有$5$个，每个箱子里有$6$个“宝贝”

问卡车最多装多少宝贝。

既然箱子一样大，那肯定是先装宝贝多的箱子啊

把所有的箱子按照其中的宝贝数量从大到小排序，遍历“箱子们”

某箱子的装箱量是“这种箱子的剩余数量 和 卡车剩余容量 的 最小值”

装上上述数量的箱子，并更新卡车剩余容量即可。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int ans = 0;
        for (auto&& box : boxTypes) {
            int thisNumOfBox = min(box[0], truckSize);
            ans += thisNumOfBox * box[1];
            truckSize -= thisNumOfBox;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/15/LeetCode%201710.%E5%8D%A1%E8%BD%A6%E4%B8%8A%E7%9A%84%E6%9C%80%E5%A4%A7%E5%8D%95%E5%85%83%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127859337](https://letmefly.blog.csdn.net/article/details/127859337)
