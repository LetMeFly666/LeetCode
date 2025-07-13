---
title: 3439.重新安排会议得到最多空余时间 I：贪心(滑动窗口) - 连开k场会议
date: 2025-07-13 22:23:38
tags: [题解, LeetCode, 中等, 贪心, 数组, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】3439.重新安排会议得到最多空余时间 I：贪心(滑动窗口) - 连开k场会议

力扣题目链接：[https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/](https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/)

<p>给你一个整数&nbsp;<code>eventTime</code>&nbsp;表示一个活动的总时长，这个活动开始于&nbsp;<code>t = 0</code>&nbsp;，结束于&nbsp;<code>t = eventTime</code>&nbsp;。</p>

<p>同时给你两个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>startTime</code> 和&nbsp;<code>endTime</code>&nbsp;。它们表示这次活动中 <code>n</code>&nbsp;个时间&nbsp;<strong>没有重叠</strong>&nbsp;的会议，其中第&nbsp;<code>i</code>&nbsp;个会议的时间为&nbsp;<code>[startTime[i], endTime[i]]</code>&nbsp;。</p>

<p>你可以重新安排 <strong>至多</strong>&nbsp;<code>k</code>&nbsp;个会议，安排的规则是将会议时间平移，且保持原来的 <strong>会议时长</strong>&nbsp;，你的目的是移动会议后 <strong>最大化</strong>&nbsp;相邻两个会议之间的 <strong>最长</strong> 连续空余时间。</p>

<p>移动前后所有会议之间的 <strong>相对</strong>&nbsp;顺序需要保持不变，而且会议时间也需要保持互不重叠。</p>

<p>请你返回重新安排会议以后，可以得到的 <strong>最大</strong>&nbsp;空余时间。</p>

<p><b>注意</b>，会议 <strong>不能</strong>&nbsp;安排到整个活动的时间以外。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/21/example0_rescheduled.png" style="width: 375px; height: 123px;" /></p>

<p>将&nbsp;<code>[1, 2]</code>&nbsp;的会议安排到&nbsp;<code>[2, 3]</code>&nbsp;，得到空余时间&nbsp;<code>[0, 2]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/12/21/example1_rescheduled.png" style="width: 375px; height: 125px;" /></p>

<p>将&nbsp;<code>[2, 4]</code>&nbsp;的会议安排到&nbsp;<code>[1, 3]</code>&nbsp;，得到空余时间&nbsp;<code>[3, 9]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>活动中的所有时间都被会议安排满了。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= eventTime &lt;= 10<sup>9</sup></code></li>
	<li><code>n == startTime.length == endTime.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
	<li><code>0 &lt;= startTime[i] &lt; endTime[i] &lt;= eventTime</code></li>
	<li><code>endTime[i] &lt;= startTime[i + 1]</code> 其中&nbsp;<code>i</code>&nbsp;在范围&nbsp;<code>[0, n - 2]</code>&nbsp;之间。</li>
</ul>


    
## 解题方法：滑动窗口

### 解题思路

怎么尽可能出现“最大间隙”？当然是尽可能地把会放到一块开。

> 题外话：长痛不如短痛，一下连着把课上了然后连着放个长假挺好的。

但是，我们最多调整k个会议的时间。怎么调？选连续的k个挤到一块呗（把当前选中的4个放到<span title="或0">上次会议的end</span>之后紧挨着）。

每次把连续的$k$个会议往前调后，k场会议中最后一个的结束时间和<span title="或eventTime">下一场会议的start</span>之间的间隔即为调整这k个会议的情况下所能营造的最长连续间隔。

### 具体方法

首先将前k场会议统一挪到0时刻开始紧挨着k场。我们把这k场视为“窗口”，那么下一个“窗口”就是这次窗口右移一位（加上下一场会议减去第一场会议）。

使用一个变量cnt记录当前窗口中k场会议的总时间，根据（其实只需要加上→）窗口的上一场会议的结束时间就能得到这k场会议全部结束的时间了。

### 时空复杂度分析

+ 时间复杂度$O(len(startTime))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 21:44:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 22:03:24
 */
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += endTime[i] - startTime[i];
        }
        int ans = 0;
        int n = startTime.size();
        for (int i = k; i <= n; i++) {
            int l = (i == k ? 0 : endTime[i - k - 1]) + cnt;
            int r = (i == n ? eventTime : startTime[i]);
            ans = max(ans, r - l);
            // printf("i = %d, l = %d, r = %d, cnt = %d, ans = %d\n", i, l, r, cnt, ans);
            if (i == n) {
                break;
            }
            cnt += endTime[i] - startTime[i];
            cnt -= endTime[i - k] - startTime[i - k];
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-13 21:44:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-13 22:11:54
'''
from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        cnt = sum(endTime[i] - startTime[i] for i in range(k))
        n = len(startTime)
        ans = 0
        for i in range(k, n + 1):
            l = (endTime[i - k - 1] if i > k else 0) + cnt
            r = eventTime if i == n else startTime[i]
            ans = max(ans, r - l)
            if i == n:
                break
            cnt += endTime[i] - startTime[i]
            cnt -= endTime[i - k] - startTime[i - k]
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 21:44:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 22:17:13
 */
class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += endTime[i] - startTime[i];
        }
        int n = startTime.length;
        int ans = 0;
        for (int i = k; i <= n; i++) {
            int l = (i == k ? 0 : endTime[i - k - 1]) + cnt;
            int r = i == n ? eventTime : startTime[i];
            ans = Math.max(ans, r - l);
            if (i == n) {
                break;
            }
            cnt += endTime[i] - startTime[i];
            cnt -= endTime[i - k] - startTime[i - k];
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 21:44:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 22:23:03
 */
package main

func maxFreeTime(eventTime int, k int, startTime []int, endTime []int) (ans int) {
    cnt := 0
    for i := 0; i < k; i++ {
        cnt += endTime[i] - startTime[i]
    }
    n := len(startTime)
    for i := k; i <= n; i++ {
        var l, r int
        if i == k {
            l = cnt
        } else {
            l = endTime[i - k - 1] + cnt
        }
        if i == n {
            r = eventTime
        } else {
            r = startTime[i]
        }
        ans = max(ans, r - l)
        if i == n {
            break
        }
        cnt += endTime[i] - startTime[i]
        cnt -= endTime[i - k] - startTime[i - k]
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149317430)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/13/LeetCode%203439.%E9%87%8D%E6%96%B0%E5%AE%89%E6%8E%92%E4%BC%9A%E8%AE%AE%E5%BE%97%E5%88%B0%E6%9C%80%E5%A4%9A%E7%A9%BA%E4%BD%99%E6%97%B6%E9%97%B4I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
