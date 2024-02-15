---
title: 2251.花期内花的数目
date: 2023-09-28 11:04:13
tags: [题解, LeetCode, 困难, 数组, 哈希表, 二分查找, 二分, 有序集合, 前缀和, 排序]
---

# 【LetMeFly】2251.花期内花的数目：排序 + 二分

力扣题目链接：[https://leetcode.cn/problems/number-of-flowers-in-full-bloom/](https://leetcode.cn/problems/number-of-flowers-in-full-bloom/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>flowers</code>&nbsp;，其中&nbsp;<code>flowers[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;朵花的 <strong>花期</strong>&nbsp;从&nbsp;<code>start<sub>i</sub></code>&nbsp;到&nbsp;<code>end<sub>i</sub></code>&nbsp;（都 <strong>包含</strong>）。同时给你一个下标从 <strong>0</strong>&nbsp;开始大小为 <code>n</code>&nbsp;的整数数组&nbsp;<code>persons</code>&nbsp;，<code>persons[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个人来看花的时间。</p>

<p>请你返回一个大小为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>是第&nbsp;<code>i</code>&nbsp;个人到达时在花期内花的&nbsp;<strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/ex1new.jpg" style="width: 550px; height: 216px;"></p>

<pre><b>输入：</b>flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
<b>输出：</b>[1,2,2,2]
<strong>解释：</strong>上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/03/02/ex2new.jpg" style="width: 450px; height: 195px;"></p>

<pre><b>输入：</b>flowers = [[1,10],[3,3]], persons = [3,3,2]
<b>输出：</b>[2,2,1]
<b>解释：</b>上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= flowers.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>flowers[i].length == 2</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= persons.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= persons[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：排序 + 二分

将所有的开花时间放入一个数组并从小到大排序；将所有的闭花时间也放入一个数组并从小到大排序。

对于某个时刻（某一天），当前盛开的花朵的数量为：$开花时间小于等于当前时间的花数 - 闭花小于等于当前时间前一天的花数$。

如何快速得到非降序数组$a$中$\leq k$的元素的个数？二分即可。（C++的upper_bound / Python的bisect_right）

+ 时间复杂度$O((n + m)\log n)$，其中$n = len(flowers)$，$m = len(people)$
+ 空间复杂度$O(n)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start(flowers.size()), end(flowers.size()), ans(people.size());
        for (int i = 0; i < flowers.size(); i++) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (int i = 0; i < people.size(); i++) {
            // 到这一天为止的开花总数 - 到这一天的前一天为止的闭花总数
            int hanagasaku = upper_bound(start.begin(), start.end(), people[i]) - start.begin();  // 花が咲く(はながさく)
            int hanagatiru = upper_bound(end.begin(), end.end(), people[i] - 1) - end.begin();//  花が散る(はながちる)
            ans[i] = hanagasaku - hanagatiru;
        }
        return ans;
    }
};
```

#### Python

真简！

```python
# from typing import List
# from bisect import bisect_right

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        start = sorted([f[0] for f in flowers])
        end = sorted([f[1] for f in flowers])
        return [bisect_right(start, p) - bisect_right(end, p - 1) for p in people]

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/28/LeetCode%202251.%E8%8A%B1%E6%9C%9F%E5%86%85%E8%8A%B1%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133378624](https://letmefly.blog.csdn.net/article/details/133378624)
