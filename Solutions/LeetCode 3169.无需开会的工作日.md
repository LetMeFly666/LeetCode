---
title: 3169.无需开会的工作日：排序+一次遍历——不需要正难则反，因为正着根本不难
date: 2025-07-12 22:33:58
tags: [题解, LeetCode, 中等, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3169.无需开会的工作日：排序+一次遍历——不需要正难则反，因为正着根本不难

力扣题目链接：[https://leetcode.cn/problems/count-days-without-meetings/](https://leetcode.cn/problems/count-days-without-meetings/)

<p>给你一个正整数 <code>days</code>，表示员工可工作的总天数（从第 1 天开始）。另给你一个二维数组 <code>meetings</code>，长度为 <code>n</code>，其中 <code>meetings[i] = [start_i, end_i]</code> 表示第 <code>i</code> 次会议的开始和结束天数（包含首尾）。</p>

<p>返回员工可工作且没有安排会议的天数。</p>

<p><strong>注意：</strong>会议时间可能会有重叠。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">days = 10, meetings = [[5,7],[1,3],[9,10]]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>第 4 天和第 8 天没有安排会议。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">days = 5, meetings = [[2,4],[1,3]]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>第 5 天没有安排会议。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">days = 6, meetings = [[1,6]]</span></p>

<p><strong>输出：</strong>0</p>

<p><strong>解释：</strong></p>

<p>所有工作日都安排了会议。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= days &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= meetings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>meetings[i].length == 2</code></li>
	<li><code>1 &lt;= meetings[i][0] &lt;= meetings[i][1] &lt;= days</code></li>
</ul>


    
## 解题方法：xx

11111

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-11 23:25:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-11 23:33:35
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0;
        int last = 0;
        for (vector<int> me : meetings) {
            // printf("last = %d, me = [%d, %d]\n", last, me[0], me[1]);
            if (me[0] > last + 1) {
                ans += me[0] - last - 1;
                // printf("ans += %d\n", me[0] - last - 1);
            }
            last = max(last, me[1]);
        }
        ans += days - last;
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-11 23:25:31
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-12 12:00:22
'''
from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        ans = last = 0
        meetings.sort()
        for l, r in meetings:
            if l > last + 1:
                ans += l - last - 1
            last = max(last, r)
        ans += days - last
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-11 23:25:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-12 16:58:44
 */
import java.util.Arrays;

class Solution {
    public int countDays(int days, int[][] meetings) {
        int ans = 0;
        int last = 0;
        Arrays.sort(meetings, (a, b) -> a[0] - b[0]);
        for (int[] me : meetings) {
            if (me[0] > last + 1) {
                ans += me[0] - last - 1;
            }
            last = Math.max(last, me[1]);
        }
        ans += days - last;
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-11 23:25:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-12 17:00:47
 */
package main

import "slices"

func countDays(days int, meetings [][]int) (ans int) {
    last := 0
    slices.SortFunc(meetings, func(a, b []int) int {return a[0] - b[0]})
    for _, me := range meetings {
        if me[0] > last + 1 {
            ans += me[0] - last - 1
        }
        last = max(last, me[1])
    }
    ans += days - last
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/11/LeetCode%203169.%E6%97%A0%E9%9C%80%E5%BC%80%E4%BC%9A%E7%9A%84%E5%B7%A5%E4%BD%9C%E6%97%A5/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
