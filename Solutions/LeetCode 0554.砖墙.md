---
title: 554.砖墙
date: 2023-03-14 13:34:51
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希]
---

# 【LetMeFly】554.砖墙

力扣题目链接：[https://leetcode.cn/problems/brick-wall/](https://leetcode.cn/problems/brick-wall/)

<p>你的面前有一堵矩形的、由 <code>n</code> 行砖块组成的砖墙。这些砖块高度相同（也就是一个单位高）但是宽度不同。每一行砖块的宽度之和相等。</p>

<p>你现在要画一条 <strong>自顶向下 </strong>的、穿过 <strong>最少 </strong>砖块的垂线。如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。<strong>你不能沿着墙的两个垂直边缘之一画线，这样显然是没有穿过一块砖的。</strong></p>

<p>给你一个二维数组 <code>wall</code> ，该数组包含这堵墙的相关信息。其中，<code>wall[i]</code> 是一个代表从左至右每块砖的宽度的数组。你需要找出怎样画才能使这条线 <strong>穿过的砖块数量最少</strong> ，并且返回 <strong>穿过的砖块数量</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/cutwall-grid.jpg" style="width: 493px; height: 577px;" />
<pre>
<strong>输入：</strong>wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>wall = [[1],[1],[1]]
<strong>输出：</strong>3
</pre>
 

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == wall.length</code></li>
	<li><code>1 <= n <= 10<sup>4</sup></code></li>
	<li><code>1 <= wall[i].length <= 10<sup>4</sup></code></li>
	<li><code>1 <= sum(wall[i].length) <= 2 * 10<sup>4</sup></code></li>
	<li>对于每一行 <code>i</code> ，<code>sum(wall[i])</code> 是相同的</li>
	<li><code>1 <= wall[i][j] <= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：哈希表

从上到下画一条线，如果没有避开任何砖块，那么有多少层就穿过了多少次的砖块。

同理，如果避开了$n$个砖块，那么就穿过了$层数-n$个砖块。

因此，我们使用哈希表将所有砖块之间“缝隙的位置”记录下来即可。

记录下所有的缝隙位置后，遍历所有的缝隙位置，看同在这个竖直位置的缝隙有多少个，缝隙越多经过砖块越少。

+ 时间复杂度：C++：$O(C)$，Python：$O(C\log C)$（python字典存取值的时间复杂度应该是$O(\log C)$，因为Python中似乎没有“无序哈希表”？此处存疑），其中$C$是砖块的数量
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = wall.size();
        unordered_map<int, int> ma;
        for (vector<int>& line : wall) {
            int cntWidth = 0;
            for (int i = 0; i + 1 < line.size(); i++) {
                cntWidth += line[i];
                ma[cntWidth]++;
            }
        }
        for (auto& [loc, times] : ma) {
            ans = min(ans, (int)wall.size() - times);
        }
        return ans;
    }
};
```

#### Python

```python
# from collections import defaultdict
# from typing import List


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        ans = len(wall)
        ma = defaultdict(int)
        for line in wall:
            cntWidth = 0
            for i in range(len(line) - 1):
                cntWidth += line[i]
                ma[cntWidth] += 1
        for loc, times in ma.items():
            ans = min(ans, len(wall) - times)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/03/14/LeetCode%200554.%E7%A0%96%E5%A2%99/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129525388](https://letmefly.blog.csdn.net/article/details/129525388)
