---
title: 1488.避免洪水泛滥
date: 2023-10-13 14:15:52
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 哈希, 有序集合, set, map, 二分查找, 堆（优先队列）]
---

# 【LetMeFly】1488.避免洪水泛滥：哈希（贪心）

力扣题目链接：[https://leetcode.cn/problems/avoid-flood-in-the-city/](https://leetcode.cn/problems/avoid-flood-in-the-city/)

<p>你的国家有无数个湖泊，所有湖泊一开始都是空的。当第 <code>n</code>&nbsp;个湖泊下雨前是空的，那么它就会装满水。如果第 <code>n</code>&nbsp;个湖泊下雨前是 <strong>满的&nbsp;</strong>，这个湖泊会发生 <strong>洪水</strong> 。你的目标是避免任意一个湖泊发生洪水。</p>

<p>给你一个整数数组&nbsp;<code>rains</code>&nbsp;，其中：</p>

<ul>
	<li><code>rains[i] &gt; 0</code>&nbsp;表示第 <code>i</code>&nbsp;天时，第 <code>rains[i]</code>&nbsp;个湖泊会下雨。</li>
	<li><code>rains[i] == 0</code>&nbsp;表示第 <code>i</code>&nbsp;天没有湖泊会下雨，你可以选择 <strong>一个</strong>&nbsp;湖泊并 <strong>抽干</strong>&nbsp;这个湖泊的水。</li>
</ul>

<p>请返回一个数组<em>&nbsp;</em><code>ans</code>&nbsp;，满足：</p>

<ul>
	<li><code>ans.length == rains.length</code></li>
	<li>如果&nbsp;<code>rains[i] &gt; 0</code> ，那么<code>ans[i] == -1</code>&nbsp;。</li>
	<li>如果&nbsp;<code>rains[i] == 0</code>&nbsp;，<code>ans[i]</code>&nbsp;是你第&nbsp;<code>i</code>&nbsp;天选择抽干的湖泊。</li>
</ul>

<p>如果有多种可行解，请返回它们中的 <strong>任意一个</strong>&nbsp;。如果没办法阻止洪水，请返回一个 <strong>空的数组</strong>&nbsp;。</p>

<p>请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rains = [1,2,3,4]
<strong>输出：</strong>[-1,-1,-1,-1]
<strong>解释：</strong>第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，装满水的湖泊包括 [1,2,3]
第四天后，装满水的湖泊包括 [1,2,3,4]
没有哪一天你可以抽干任何湖泊的水，也没有湖泊会发生洪水。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rains = [1,2,0,0,2,1]
<strong>输出：</strong>[-1,-1,2,1,-1,-1]
<strong>解释：</strong>第一天后，装满水的湖泊包括 [1]
第二天后，装满水的湖泊包括 [1,2]
第三天后，我们抽干湖泊 2 。所以剩下装满水的湖泊包括 [1]
第四天后，我们抽干湖泊 1 。所以暂时没有装满水的湖泊了。
第五天后，装满水的湖泊包括 [2]。
第六天后，装满水的湖泊包括 [1,2]。
可以看出，这个方案下不会有洪水发生。同时， [-1,-1,1,2,-1,-1] 也是另一个可行的没有洪水的方案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rains = [1,2,0,1,2]
<strong>输出：</strong>[]
<strong>解释：</strong>第二天后，装满水的湖泊包括 [1,2]。我们可以在第三天抽干一个湖泊的水。
但第三天后，湖泊 1 和 2 都会再次下雨，所以不管我们第三天抽干哪个湖泊的水，另一个湖泊都会发生洪水。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rains.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= rains[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：哈希（贪心）

### 思路

使用有序集合（例如C++的```set```）记录当前哪天没下雨并且没“被征用”；使用哈希表记录某湖的上次下雨日期。

需要明白的是，某湖的第一次下雨并不需要管，也不需要立刻抽水，只需要记下来就行了。当它再次下雨时，从**上次下雨后**没下雨且没被征用的一天中选**尽可能早**的一天，来抽取此湖の水就好了。

为什么在符合条件的“天”中，要选“尽可能早”的一天？因为对于没有下雨的两天```d1```和```d2```，$(d1, d2)$之间某天下雨的湖，只有$d2$能抽这个湖的水。

+ 时间复杂度$O(len(rains)\log len(rains))$
+ 空间复杂度$O(len(rains))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> whenNotRain;
        unordered_map<int, int> whichAndWhen;
        vector<int> ans(rains.size(), 1);  // 没有0号湖
        for (int i = 0; i < rains.size(); i++) {
            if (!rains[i]) {
                whenNotRain.insert(i);
                continue;
            }
            ans[i] = -1;
            if (whichAndWhen.count(rains[i])) {
                int lastRainDay = whichAndWhen[rains[i]];  // 找一个lastRainDay后的晴天
                set<int>::iterator it = whenNotRain.upper_bound(lastRainDay);
                if (it == whenNotRain.end()) {
                    return {};
                }
                ans[*it] = rains[i];
                whenNotRain.erase(it);
            }
            whichAndWhen[rains[i]] = i;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
from sortedcontainers import SortedList


class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        whenNotRain = SortedList()
        whichAndRain = {}
        ans = [1] * len(rains)
        for i in range(len(rains)):
            if not rains[i]:
                whenNotRain.add(i)
                continue
            ans[i] = -1
            if rains[i] in whichAndRain:
                lastRainDay = whichAndRain[rains[i]]
                it = whenNotRain.bisect_right(lastRainDay)
                if it == len(whenNotRain):
                    return {}
                ans[whenNotRain[it]] = rains[i]
                whenNotRain.discard(whenNotRain[it])
            whichAndRain[rains[i]] = i
        return ans

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/13/LeetCode%201488.%E9%81%BF%E5%85%8D%E6%B4%AA%E6%B0%B4%E6%B3%9B%E6%BB%A5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133809999](https://letmefly.blog.csdn.net/article/details/133809999)
