---
title: 2070.每一个查询的最大美丽值：排序 + 二分查找
date: 2025-03-09 14:18:25
tags: [题解, LeetCode, 中等, 数组, 二分查找, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2070.每一个查询的最大美丽值：排序 + 二分查找

力扣题目链接：[https://leetcode.cn/problems/most-beautiful-item-for-each-query/](https://leetcode.cn/problems/most-beautiful-item-for-each-query/)

<p>给你一个二维整数数组&nbsp;<code>items</code>&nbsp;，其中&nbsp;<code>items[i] = [price<sub>i</sub>, beauty<sub>i</sub>]</code>&nbsp;分别表示每一个物品的 <strong>价格</strong>&nbsp;和 <strong>美丽值</strong>&nbsp;。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>queries</code>&nbsp;。对于每个查询&nbsp;<code>queries[j]</code>&nbsp;，你想求出价格小于等于&nbsp;<code>queries[j]</code>&nbsp;的物品中，<strong>最大的美丽值</strong>&nbsp;是多少。如果不存在符合条件的物品，那么查询的结果为&nbsp;<code>0</code>&nbsp;。</p>

<p>请你返回一个长度与 <code>queries</code>&nbsp;相同的数组<em>&nbsp;</em><code>answer</code>，其中<em>&nbsp;</em><code>answer[j]</code>是第&nbsp;<code>j</code>&nbsp;个查询的答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
<b>输出：</b>[2,4,5,5,6,6]
<strong>解释：</strong>
- queries[0]=1 ，[1,2] 是唯一价格 &lt;= 1 的物品。所以这个查询的答案为 2 。
- queries[1]=2 ，符合条件的物品有 [1,2] 和 [2,4] 。
  它们中的最大美丽值为 4 。
- queries[2]=3 和 queries[3]=4 ，符合条件的物品都为 [1,2] ，[3,2] ，[2,4] 和 [3,5] 。
  它们中的最大美丽值为 5 。
- queries[4]=5 和 queries[5]=6 ，所有物品都符合条件。
  所以，答案为所有物品中的最大美丽值，为 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
<b>输出：</b>[4]
<b>解释：</b>
每个物品的价格均为 1 ，所以我们选择最大美丽值 4 。
注意，多个物品可能有相同的价格和美丽值。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>items = [[10,1000]], queries = [5]
<b>输出：</b>[0]
<strong>解释：</strong>
没有物品的价格小于等于 5 ，所以没有物品可以选择。
因此，查询的结果为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= items.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>items[i].length == 2</code></li>
	<li><code>1 &lt;= price<sub>i</sub>, beauty<sub>i</sub>, queries[j] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：排序 + 二分查找

每个查询q所能包含的物品范围都是“价格小于等于q”的元素，因此我们可以二话不说对items按照价格从小到大排个序，这样对于查询q就能使用二分查找的方式在$\log n$的时间复杂度内找到“符合条件商品范围”了。

知道了符合条件的商品范围，如何快速知道这个范围内商品的最大美丽值呢？不难发现，价格低的商品的美丽值是可以被价格高的商品所“继承”的。因为若价格高的商品在符合条件范围内，那么价格低的商品一定也在符合条件的商品范围内。

因此，我们对商品按价格从低到高排过序后，可以直接遍历一遍并更新当前商品价值为遍历过的商品的最大价值。

+ 时间复杂度$O(n\log n)$，其中$n=len(items)$
+ 空间复杂度$O(1)$，直接全部原地修改了😆

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-09 13:49:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-09 14:03:45
 */
class Solution {
private:
    int getAns(vector<vector<int>>& items, int q) {  // 找第一个大于q的位置
        int l = 0, r = items.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (items[mid][0] > q) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int cnt = 0;
        for (int i = 0; i < items.size(); i++) {
            cnt = items[i][1] = max(cnt, items[i][1]);
        }
        for (int i = 0; i < queries.size(); i++) {
            int index = getAns(items, queries[i]);
            queries[i] = index ? items[index - 1][1] : 0;
        }
        return queries;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-09 14:04:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-09 14:07:29
'''
from typing import List

class Solution:
    def search(self, items: List[List[int]], target: int) -> int:
        l, r = 0, len(items) - 1
        while l <= r:
            mid = (l + r) >> 1
            if items[mid][0] > target:
                r = mid - 1
            else:
                l = mid + 1
        return l
    
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        cnt = 0
        for i, (_, val) in enumerate(items):
            cnt = items[i][1] = max(cnt, val)
        for i, q in enumerate(queries):
            index = self.search(items, q)
            queries[i] = items[index - 1][1] if index else 0
        return queries
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-09 14:08:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-09 14:11:18
 */
import java.util.Arrays;

class Solution {
    private int search(int[][] items, int target) {
        int l = 0, r = items.length - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (items[mid][0] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    public int[] maximumBeauty(int[][] items, int[] queries) {
        Arrays.sort(items,(a, b) -> Integer.compare(a[0], b[0]));
        int cnt = 0;
        for (int[] item : items) {
            cnt = item[1] = Math.max(cnt, item[1]);
        }
        for (int i = 0; i < queries.length; i++) {
            int index = search(items, queries[i]);
            if (index > 0) {
                queries[i] = items[index - 1][1];
            } else {
                queries[i] = 0;
            }
        }
        return queries;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-09 14:12:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-09 14:17:20
 */
package main

import "sort"

func search_2070(items [][]int, target int) int {
    l, r := 0, len(items) - 1
    for l <= r {
        mid := (l + r) >> 1
        if items[mid][0] > target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return l
}

func maximumBeauty(items [][]int, queries []int) []int {
    sort.Slice(items, func(i, j int) bool {
        return items[i][0] < items[j][0]
    })
    cnt := 0
    for _, item := range items {
        cnt = max(cnt, item[1])
        item[1] = cnt
    }
    for i, q := range queries {
        index := search_2070(items, q)
        if index > 0 {
            queries[i] = items[index - 1][1]
        } else {
            queries[i] = 0
        }
    }
    return queries
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146132104)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/09/LeetCode%202070.%E6%AF%8F%E4%B8%80%E4%B8%AA%E6%9F%A5%E8%AF%A2%E7%9A%84%E6%9C%80%E5%A4%A7%E7%BE%8E%E4%B8%BD%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
