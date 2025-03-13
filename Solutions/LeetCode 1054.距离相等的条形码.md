---
title: 1054.距离相等的条形码
date: 2023-05-14 09:37:40
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 哈希, map, 计数, 排序, 堆（优先队列）, 思维, 构造]
categories: [题解, LeetCode]
---

# 【LetMeFly】1054.距离相等的条形码

力扣题目链接：[https://leetcode.cn/problems/distant-barcodes/](https://leetcode.cn/problems/distant-barcodes/)

<p>在一个仓库里，有一排条形码，其中第 <code>i</code> 个条形码为&nbsp;<code>barcodes[i]</code>。</p>

<p>请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。 你可以返回任何满足该要求的答案，此题保证存在答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>barcodes = [1,1,1,2,2,2]
<strong>输出：</strong>[2,1,2,1,2,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>barcodes = [1,1,1,1,2,2,3,3]
<strong>输出：</strong>[1,3,1,3,2,1,2,1]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= barcodes.length &lt;= 10000</code></li>
	<li><code>1 &lt;= barcodes[i] &lt;= 10000</code></li>
</ul>


    
## 方法一：排序（思维 + 构造）

首先使用哈希表ma统计每个数出现的次数。

接着将原始数组barcodes中的元素按照他们在ma中出现的次数从大到小排序，出现次数相同的按照数字大小排序（小到大或大到小都可，这是为了**保证相同的数排序后相邻**）。

接着开辟一个长度为$len(barcodes)$的答案数组ans，将排好序的barcodes中的元素依次放入ans的偶数下标$0, 2, 4, ...$，再依次放入ans的奇数下标$1, 3, 5, ...$即可。

题目保证有解，因此不会出现同一个数占据了所有偶数下标后还有剩余的情况

+ 时间复杂度$O(len(barcodes)\times \log len(barcodes))$
+ 空间复杂度$O(len(barcodes))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> ma;
        for (int t : barcodes) {
            ma[t]++;
        }
        sort(barcodes.begin(), barcodes.end(), [&](int a, int b) {
            return ma[a] != ma[b] ? ma[a] > ma[b] : a > b;
        });
        vector<int> ans(barcodes.size());
        for (int j = 0, k = 0; k < 2; k++) {
            for (int i = k; i < barcodes.size(); i += 2) {
                ans[i] = barcodes[j++];
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
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        ma = defaultdict(int)
        for t in barcodes:
            ma[t] += 1
        barcodes.sort(key=lambda x: (-ma[x], x))
        ans = [0] * len(barcodes)
        ans[::2] = barcodes[:(len(barcodes) + 1) // 2]
        ans[1::2] = barcodes[(len(barcodes) + 1) // 2:]
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/05/14/LeetCode%201054.%E8%B7%9D%E7%A6%BB%E7%9B%B8%E7%AD%89%E7%9A%84%E6%9D%A1%E5%BD%A2%E7%A0%81/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130665688](https://letmefly.blog.csdn.net/article/details/130665688)
