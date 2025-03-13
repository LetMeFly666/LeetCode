---
title: 1333.餐厅过滤器
date: 2023-09-27 19:09:35
tags: [题解, LeetCode, 中等, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1333.餐厅过滤器

力扣题目链接：[https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/](https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/)

<p>给你一个餐馆信息数组&nbsp;<code>restaurants</code>，其中&nbsp;&nbsp;<code>restaurants[i] = [id<sub>i</sub>, rating<sub>i</sub>, veganFriendly<sub>i</sub>, price<sub>i</sub>, distance<sub>i</sub>]</code>。你必须使用以下三个过滤器来过滤这些餐馆信息。</p>

<p>其中素食者友好过滤器&nbsp;<code>veganFriendly</code>&nbsp;的值可以为 <code>true</code> 或者 <code>false</code>，如果为 <em>true</em>&nbsp;就意味着你应该只包括&nbsp;<code>veganFriendly<sub>i</sub></code>&nbsp;为 true 的餐馆，为&nbsp;<em>false</em>&nbsp;则意味着可以包括任何餐馆。此外，我们还有最大价格&nbsp;<code>maxPrice</code>&nbsp;和最大距离&nbsp;<code>maxDistance</code>&nbsp;两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。</p>

<p>过滤后返回餐馆的 <strong><em>id</em></strong>，按照 <em><strong>rating</strong></em>&nbsp;从高到低排序。如果 <em><strong>rating</strong></em> 相同，那么按 <em><strong>id</strong></em> 从高到低排序。简单起见，&nbsp;<code>veganFriendly<sub>i</sub></code> 和 <code>veganFriendly</code>&nbsp;为&nbsp;<em>true</em>&nbsp;时取值为 <em>1</em>，为 <em>false</em> 时，取值为&nbsp;<em>0 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
<strong>输出：</strong>[3,1,5] 
<strong>解释： 
</strong>这些餐馆为：
餐馆 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
餐馆 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
餐馆 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
餐馆 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
餐馆 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
在按照 veganFriendly = 1, maxPrice = 50 和 maxDistance = 10 进行过滤后，我们得到了餐馆 3, 餐馆 1 和 餐馆 5（按评分从高到低排序）。 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 50, maxDistance = 10
<strong>输出：</strong>[4,3,2,1,5]
<strong>解释：</strong>餐馆与示例 1 相同，但在 veganFriendly = 0 的过滤条件下，应该考虑所有餐馆。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 0, maxPrice = 30, maxDistance = 3
<strong>输出：</strong>[4,5]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;restaurants.length &lt;= 10^4</code></li>
	<li><code>restaurants[i].length == 5</code></li>
	<li><code>1 &lt;=&nbsp;id<sub>i</sub>, rating<sub>i</sub>, price<sub>i</sub>, distance<sub>i </sub>&lt;= 10^5</code></li>
	<li><code>1 &lt;=&nbsp;maxPrice,&nbsp;maxDistance &lt;= 10^5</code></li>
	<li><code>veganFriendly<sub>i</sub></code> 和&nbsp;<code>veganFriendly</code>&nbsp;的值为 0 或 1 。</li>
	<li>所有 <code>id<sub>i</sub></code> 各不相同。</li>
</ul>


    
## 方法一：排序

建立一个临时数组，数组中存放满足条件的元素。

接着将数组中的元素按照rating优先其次id优先的规则排序，排序后，将临时数组中每个元素的id放入新数组并返回即可。

**怎么判断某个餐厅是否满足条件呢？**

+ ```veganFriendly```：如果这个餐厅的```veganFriendly```**大于等于**所需的```veganFriendly```，则不删
+ ```price```：如果这个餐厅的```price```**大于等于**所需的```price```，则不删
+ ```distance```：如果这个餐厅的```distance```**大于等于**所需的```distance```，则不删

即可。

+ 时间复杂度$O(n\log n)$，其中$n = len(restaurants)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> temp;
        for (auto&& v : restaurants) {
            if (v[2] >= veganFriendly && v[3] <= maxPrice && v[4] <= maxDistance) {
                temp.push_back(v);
            }
        }
        sort(temp.begin(), temp.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] > b[1];
        });
        vector<int> ans;
        for (auto&& v : temp) {
            ans.push_back(v[0]);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        temp = [v for v in restaurants if v[2] >= veganFriendly and v[3] <= maxPrice and v[4] <= maxDistance]
        temp.sort(key=lambda v:(-v[1], -v[0]))
        return [v[0] for v in temp]
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/27/LeetCode%201333.%E9%A4%90%E5%8E%85%E8%BF%87%E6%BB%A4%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133362152](https://letmefly.blog.csdn.net/article/details/133362152)
