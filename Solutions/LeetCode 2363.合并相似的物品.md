---
title: 2363.合并相似的物品
date: 2023-02-28 10:48:22
tags: [题解, LeetCode, 简单, 数组, 哈希表, 有序集合, 排序, 双指针]
categories: [题解, LeetCode]
---

# 【LetMeFly】2363.合并相似的物品：两种方法（哈希 / 排序+双指针）

力扣题目链接：[https://leetcode.cn/problems/merge-similar-items/](https://leetcode.cn/problems/merge-similar-items/)

<p>给你两个二维整数数组&nbsp;<code>items1</code> 和&nbsp;<code>items2</code>&nbsp;，表示两个物品集合。每个数组&nbsp;<code>items</code>&nbsp;有以下特质：</p>

<ul>
	<li><code>items[i] = [value<sub>i</sub>, weight<sub>i</sub>]</code> 其中&nbsp;<code>value<sub>i</sub></code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;件物品的&nbsp;<strong>价值</strong>&nbsp;，<code>weight<sub>i</sub></code>&nbsp;表示第 <code>i</code>&nbsp;件物品的 <strong>重量</strong>&nbsp;。</li>
	<li><code>items</code>&nbsp;中每件物品的价值都是 <strong>唯一的</strong>&nbsp;。</li>
</ul>

<p>请你返回一个二维数组&nbsp;<code>ret</code>，其中&nbsp;<code>ret[i] = [value<sub>i</sub>, weight<sub>i</sub>]</code>，&nbsp;<code>weight<sub>i</sub></code>&nbsp;是所有价值为&nbsp;<code>value<sub>i</sub></code><sub>&nbsp;</sub>物品的&nbsp;<strong>重量之和</strong>&nbsp;。</p>

<p><strong>注意：</strong><code>ret</code>&nbsp;应该按价值 <strong>升序</strong>&nbsp;排序后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
<b>输出：</b>[[1,6],[3,9],[4,5]]
<b>解释：</b>
value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 5 ，总重量为 1 + 5 = 6 。
value = 3 的物品再 items1 中 weight = 8 ，在 items2 中 weight = 1 ，总重量为 8 + 1 = 9 。
value = 4 的物品在 items1 中 weight = 5 ，总重量为 5 。
所以，我们返回 [[1,6],[3,9],[4,5]] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
<b>输出：</b>[[1,4],[2,4],[3,4]]
<b>解释：</b>
value = 1 的物品在 items1 中 weight = 1 ，在 items2 中 weight = 3 ，总重量为 1 + 3 = 4 。
value = 2 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 1 ，总重量为 3 + 1 = 4 。
value = 3 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
所以，我们返回 [[1,4],[2,4],[3,4]] 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
<b>输出：</b>[[1,7],[2,4],[7,1]]
<strong>解释：
</strong>value = 1 的物品在 items1 中 weight = 3 ，在 items2 中 weight = 4 ，总重量为 3 + 4 = 7 。
value = 2 的物品在 items1 中 weight = 2 ，在 items2 中 weight = 2 ，总重量为 2 + 2 = 4 。
value = 7 的物品在 items2 中 weight = 1 ，总重量为 1 。
所以，我们返回 [[1,7],[2,4],[7,1]] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= items1.length, items2.length &lt;= 1000</code></li>
	<li><code>items1[i].length == items2[i].length == 2</code></li>
	<li><code>1 &lt;= value<sub>i</sub>, weight<sub>i</sub> &lt;= 1000</code></li>
	<li><code>items1</code>&nbsp;中每个 <code>value<sub>i</sub></code>&nbsp;都是 <b>唯一的</b>&nbsp;。</li>
	<li><code>items2</code>&nbsp;中每个 <code>value<sub>i</sub></code>&nbsp;都是 <b>唯一的</b>&nbsp;。</li>
</ul>


    
## 方法一：哈希表

使用哈希表（有序哈希表 或 无序哈希表加排序），以每个物品的value为key，累加相同的key的weight，最终将哈希表转化成列表/数组即可

+ 时间复杂度$O((len(items1) + len(items2))\times \log (len(items1) + len(items2)))$
+ 空间复杂度$O(len(items1) + len(items2))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> ma;
        for (auto& v : items1) {
            ma[v[0]] += v[1];
        }
        for (auto& v : items2) {
            ma[v[0]] += v[1];
        }
        vector<vector<int>> ans;
        for (auto& v : ma) {
            ans.push_back({v.first, v.second});
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
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        ma = defaultdict(int)
        for a, b in items1:
            ma[a] += b
        for a, b in items2:
            ma[a] += b
        return sorted([[a, b] for a, b in ma.items()])
```

## 方法二：排序 + 双指针

方法一中使用现成的哈希表使得代码写起来很简单，但是需要$O(len(items1) + len(items2))$的空间复杂度

不难发现，题目中只需要合并两个数组为一个数组，因此我们只需要对两个数组分别排序，然后使用双指针指向这两个数组，比较这两个指针所指元素的value的大小，如果两数组所指的value相同，则累加后放入答案中；否则将value较小的放入答案中。

每放入一个元素到答案中，当前数组的指针就后移。直到两个数组的指针都指向了数组的末尾为止。

+ 时间复杂度$O(len(items1)\times\log len(items1)  + len(items2)\times\log len(items2))$
+ 空间复杂度$O(1)$，返回的答案不计入算法的空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items1.begin(), items1.end());
        sort(items2.begin(), items2.end());
        vector<vector<int>> ans;
        int l1 = 0, l2 = 0;
        while (l1 < items1.size() && l2 < items2.size()) {
            if (items1[l1][0] == items2[l2][0]) {
                ans.push_back({items1[l1][0], items1[l1][1] + items2[l2][1]});
                l1++, l2++;
            }
            else if (items1[l1][0] < items2[l2][0]) {
                ans.push_back(items1[l1]);
                l1++;
            }
            else {
                ans.push_back(items2[l2]);
                l2++;
            }
        }
        while (l1 < items1.size()) {
            ans.push_back(items1[l1++]);
        }
        while (l2 < items2.size()) {
            ans.push_back(items2[l2++]);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        items1.sort()
        items2.sort()
        ans = []
        l1, l2 = 0, 0
        while l1 < len(items1) and l2 < len(items2):
            if items1[l1][0] == items2[l2][0]:
                ans.append([items1[l1][0], items1[l1][1] + items2[l2][1]])
                l1 += 1
                l2 += 1
            elif items1[l1][0] < items2[l2][0]:
                ans.append(items1[l1])
                l1 += 1
            else:
                ans.append(items2[l2])
                l2 += 1
        while l1 < len(items1):
            ans.append(items1[l1])
            l1 += 1
        while l2 < len(items2):
            ans.append(items2[l2])
            l2 += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/02/28/LeetCode%202363.%E5%90%88%E5%B9%B6%E7%9B%B8%E4%BC%BC%E7%9A%84%E7%89%A9%E5%93%81/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129257424](https://letmefly.blog.csdn.net/article/details/129257424)
