---
title: 1090.受标签影响的最大值
date: 2023-05-23 11:55:02
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 哈希, map, 计数, 排序]
---

# 【LetMeFly】1090.受标签影响的最大值

力扣题目链接：[https://leetcode.cn/problems/largest-values-from-labels/](https://leetcode.cn/problems/largest-values-from-labels/)

<p>我们有一个&nbsp;<code>n</code>&nbsp;项的集合。给出两个整数数组&nbsp;<code>values</code>&nbsp;和 <code>labels</code>&nbsp;，第 <code>i</code> 个元素的值和标签分别是&nbsp;<code>values[i]</code>&nbsp;和&nbsp;<code>labels[i]</code>。还会给出两个整数&nbsp;<code>numWanted</code>&nbsp;和 <code>useLimit</code> 。</p>

<p>从 <code>n</code> 个元素中选择一个子集 <code>s</code> :</p>

<ul>
	<li>子集 <code>s</code> 的大小&nbsp;<strong>小于或等于</strong> <code>numWanted</code> 。</li>
	<li><code>s</code> 中 <strong>最多</strong> 有相同标签的 <code>useLimit</code> 项。</li>
</ul>

<p>一个子集的&nbsp;<strong>分数&nbsp;</strong>是该子集的值之和。</p>

<p>返回子集&nbsp;<code>s</code> 的最大 <strong>分数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
<strong>输出：</strong>9
<strong>解释：</strong>选出的子集是第一项，第三项和第五项。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
<strong>输出：</strong>12
<strong>解释：</strong>选出的子集是第一项，第二项和第三项。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
<strong>输出：</strong>16
<strong>解释：</strong>选出的子集是第一项和第四项。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == values.length == labels.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= values[i], labels[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= numWanted, useLimit &lt;= n</code></li>
</ul>


    
## 方法一：贪心 + 排序

**首先咱们不考虑这道题的“标签”**，给你一个values数组和一个整数numWanted，让你从values中选取不超过numWanted个元素使得所选元素的和尽可能地大，那么应该怎么做呢？

很简单，将values中的元素按从大到小的规则排序，从前到后选择min(所有, numWanted)个元素即可。

**现在仅仅是在刚才的基础上，添加了“标签”，并且做了以下限制**：同一个标签的元素选取数量不超过useLimit个。

怎么办呢？很简单，我们仍然按照values数组从大到小的规则排序，在选取的过程中使用哈希表统计每个标签选择了多少个，如果某个标签已经选择了useLimit个，跳过这个元素继续选下一个元素就好了。

+ 时间复杂度$O(n \log n)$，其中$n=len(values)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> v(values.size());
        for (int i = 0; i < values.size(); i++) {
            v[i] = {values[i], labels[i]};
        }
        sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        unordered_map<int, int> ma;
        int cnt = 0;
        int ans = 0;
        for (auto&& [value, label] : v) {
            if (ma[label] == useLimit) {
                continue;
            }
            ma[label]++;
            cnt++;
            ans += value;
            if (cnt == numWanted) {
                break;
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict


class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        v = list(zip(values, labels))
        v.sort(key=lambda x : -x[0])
        ans = 0
        cnt = 0
        ma = defaultdict(int)
        for value, label in v:
            if ma[label] == useLimit:
                continue
            ma[label] += 1
            cnt += 1
            ans += value
            if cnt == numWanted:
                break
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/23/LeetCode%201090.%E5%8F%97%E6%A0%87%E7%AD%BE%E5%BD%B1%E5%93%8D%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130824464](https://letmefly.blog.csdn.net/article/details/130824464)
