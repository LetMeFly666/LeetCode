---
title: 1288.删除被覆盖区间：排序(非二重循环暴力)
date: 2026-07-07 22:37:36
tags: [题解, LeetCode, 中等, 数组, 排序, 贪心]
categories: [题解, LeetCode]
---

# 【LetMeFly】1288.删除被覆盖区间：排序(非二重循环暴力)

力扣题目链接：[https://leetcode.cn/problems/remove-covered-intervals/](https://leetcode.cn/problems/remove-covered-intervals/)

<p>给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。</p>

<p>只有当&nbsp;<code>c &lt;= a</code>&nbsp;且&nbsp;<code>b &lt;= d</code>&nbsp;时，我们才认为区间&nbsp;<code>[a,b)</code> 被区间&nbsp;<code>[c,d)</code> 覆盖。</p>

<p>在完成所有删除操作后，请你返回列表中剩余区间的数目。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>intervals = [[1,4],[3,6],[2,8]]
<strong>输出：</strong>2
<strong>解释：</strong>区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong>​​​​​​</p>

<ul>
	<li><code>1 &lt;= intervals.length &lt;= 1000</code></li>
	<li><code>0 &lt;= intervals[i][0] &lt;&nbsp;intervals[i][1] &lt;= 10^5</code></li>
	<li>对于所有的&nbsp;<code>i != j</code>：<code>intervals[i] != intervals[j]</code></li>
</ul>


    
## 解题方法一：二重循环暴力

由于数据量最大只有$1000$，所以可以二重循环一一对比，查看某个区间是否被包含在其他区间中。

+ 时间复杂度$O(n^2)$，其中$n=len(intervals)$
+ 空间复杂度$O(1)$

## 解题方法二：排序（贪心）

按照其实时间从小到大排序，那么按顺序遍历的过程中，后遍历的区间起始时间一定比先遍历区间的晚。那么如果前面有区间的截止时间在此区间之后，是不是说明这个区间一定被覆盖掉了。

所以排序依据：若起始时间不同则起始时间小的优先，否则截止时间大的优先。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-07-07 22:16:53
 */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = intervals.size();
        for (int i = 0, n = intervals.size(), r = 0; i < n; i++) {
            ans -= intervals[i][1] <= r;
            r = max(r, intervals[i][1]);
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-07-07 22:19:44
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = len(intervals)
        R = 0
        for l, r in intervals:
            ans -= r <= R
            R = max(R, r)
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-07-07 22:31:39
 */
import java.util.Arrays;

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
        });
        int ans = intervals.length;
        int r = 0;
        for (int[] v : intervals) {
            if (v[1] <= r) {
                ans--;
            } else {
                r = v[1];
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-07-07 22:28:57
 */
package main

import "sort"

func removeCoveredIntervals(intervals [][]int) int {
    sort.Slice(intervals, func(i, j int) bool {
        if intervals[i][0] == intervals[j][0] {
            return intervals[i][1] > intervals[j][1]
        }
        return intervals[i][0] < intervals[j][0]
    })
    
    ans := len(intervals)
    r := 0
    for _, v := range intervals {
        if v[1] <= r {
            ans -= 1
        }
        r = max(r, v[1])
    }
    return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-07-07 22:36:22
 */
impl Solution {
    pub fn remove_covered_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(|x| (x[0], -x[1]));
        let mut ans = intervals.len() as i32;
        let mut r = 0;
        for v in intervals.iter() {
            if v[1] <= r {
                ans -= 1;
            } else {
                r = v[1];
            }
        }
        return ans;
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162691877)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/07/LeetCode%201288.%E5%88%A0%E9%99%A4%E8%A2%AB%E8%A6%86%E7%9B%96%E5%8C%BA%E9%97%B4/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
