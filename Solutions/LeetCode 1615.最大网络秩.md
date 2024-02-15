---
title: 1615.最大网络秩
date: 2023-03-15 10:00:10
tags: [题解, LeetCode, 中等, 图, 哈希表, 哈希, set]
---

# 【LetMeFly】1615.最大网络秩

力扣题目链接：[https://leetcode.cn/problems/maximal-network-rank/](https://leetcode.cn/problems/maximal-network-rank/)

<p><code>n</code> 座城市和一些连接这些城市的道路 <code>roads</code> 共同组成一个基础设施网络。每个 <code>roads[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 都表示在城市 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code> 之间有一条双向道路。</p>

<p>两座不同城市构成的 <strong>城市对</strong> 的 <strong>网络秩</strong> 定义为：与这两座城市 <strong>直接</strong> 相连的道路总数。如果存在一条道路直接连接这两座城市，则这条道路只计算 <strong>一次</strong> 。</p>

<p>整个基础设施网络的 <strong>最大网络秩</strong> 是所有不同城市对中的 <strong>最大网络秩</strong> 。</p>

<p>给你整数 <code>n</code> 和数组 <code>roads</code>，返回整个基础设施网络的 <strong>最大网络秩</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/11/ex1.png" style="width: 292px; height: 172px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
<strong>输出：</strong>4
<strong>解释：</strong>城市 0 和 1 的网络秩是 4，因为共有 4 条道路与城市 0 或 1 相连。位于 0 和 1 之间的道路只计算一次。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/11/ex2.png" style="width: 292px; height: 172px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
<strong>输出：</strong>5
<strong>解释：</strong>共有 5 条道路与城市 1 或 2 相连。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
<strong>输出：</strong>5
<strong>解释：</strong>2 和 5 的网络秩为 5，注意并非所有的城市都需要连接起来。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 100</code></li>
	<li><code>0 <= roads.length <= n * (n - 1) / 2</code></li>
	<li><code>roads[i].length == 2</code></li>
	<li><code>0 <= a<sub>i</sub>, b<sub>i</sub> <= n-1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>每对城市之间 <strong>最多只有一条</strong> 道路相连</li>
</ul>


    
## 方法一：图 + 哈希表

使用一个长度为$n$的整型数组$cnt$，其中$cnt[i]$代表节点$i$相连的路径的数量。

使用一个哈希表$se$记录路径$(i, j)$或路径$(j, i)$是否存在。

初始时遍历所有路径，统计出$cnt$和$se$

接着枚举所有的“城市对”（也就是枚举所有不相同的两个城市），那么这两个城市（记为i和j）之间的“网络秩”就是$cnt[i]+cnt[j]-se.count((i, j))$

+ 时间复杂度$O(n^2 + \sum roads)$
+ 空间复杂度$O(n + \sum roads)$

### AC代码

#### C++

C++想要使用内置哈希表的话，可以选择将（i * 1000 + j）作为键值存入。

```cpp
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<int> cnt(n);
        unordered_set<int> se;
        for (vector<int>& road : roads) {
            cnt[road[0]]++;
            cnt[road[1]]++;
            se.insert(road[0] * 1000 + road[1]);
            se.insert(road[1] * 1000 + road[0]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = max(ans, cnt[i] + cnt[j] - (int)se.count(i * 1000 + j));
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        ans = 0
        cnt = [0 for _ in range(n)]
        se = set()
        for road in roads:
            cnt[road[0]] += 1
            cnt[road[1]] += 1
            se.add((road[0], road[1]))
            se.add((road[1], road[0]))
        for i in range(n):
            for j in range(i + 1, n):
                ans = max(ans, cnt[i] + cnt[j] - ((i, j) in se))
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/15/LeetCode%201615.%E6%9C%80%E5%A4%A7%E7%BD%91%E7%BB%9C%E7%A7%A9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129546421](https://letmefly.blog.csdn.net/article/details/129546421)
