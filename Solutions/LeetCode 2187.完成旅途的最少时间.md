---
title: 2187.完成旅途的最少时间
date: 2024-10-05 23:40:25
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分]
categories: [题解, LeetCode]
---

# 【LetMeFly】2187.完成旅途的最少时间：二分查找

力扣题目链接：[https://leetcode.cn/problems/minimum-time-to-complete-trips/](https://leetcode.cn/problems/minimum-time-to-complete-trips/)

<p>给你一个数组&nbsp;<code>time</code>&nbsp;，其中&nbsp;<code>time[i]</code>&nbsp;表示第 <code>i</code>&nbsp;辆公交车完成 <strong>一趟</strong><strong>旅途</strong>&nbsp;所需要花费的时间。</p>

<p>每辆公交车可以 <strong>连续</strong> 完成多趟旅途，也就是说，一辆公交车当前旅途完成后，可以 <strong>立马开始</strong>&nbsp;下一趟旅途。每辆公交车 <strong>独立</strong>&nbsp;运行，也就是说可以同时有多辆公交车在运行且互不影响。</p>

<p>给你一个整数&nbsp;<code>totalTrips</code>&nbsp;，表示所有公交车&nbsp;<strong>总共</strong>&nbsp;需要完成的旅途数目。请你返回完成 <strong>至少</strong>&nbsp;<code>totalTrips</code>&nbsp;趟旅途需要花费的 <strong>最少</strong>&nbsp;时间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>time = [1,2,3], totalTrips = 5
<b>输出：</b>3
<strong>解释：</strong>
- 时刻 t = 1 ，每辆公交车完成的旅途数分别为 [1,0,0] 。
  已完成的总旅途数为 1 + 0 + 0 = 1 。
- 时刻 t = 2 ，每辆公交车完成的旅途数分别为 [2,1,0] 。
  已完成的总旅途数为 2 + 1 + 0 = 3 。
- 时刻 t = 3 ，每辆公交车完成的旅途数分别为 [3,1,1] 。
  已完成的总旅途数为 3 + 1 + 1 = 5 。
所以总共完成至少 5 趟旅途的最少时间为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>time = [2], totalTrips = 1
<b>输出：</b>2
<strong>解释：</strong>
只有一辆公交车，它将在时刻 t = 2 完成第一趟旅途。
所以完成 1 趟旅途的最少时间为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= time.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= time[i], totalTrips &lt;= 10<sup>7</sup></code></li>
</ul>


    
## 解题方法：二分

花费时间越长，所能完成总趟数就越多。因此可以二分花费总时长，对于某个确定时长计算最多能够完成多少趟。

对于二分的上边界，无脑取$10^{14}$即可，反正$2^{47}=140,737,488,355,328\gt 10^{14}$，二分最多四十多次。

+ 时间复杂度$O(C\times len(times))$，其中$C=10^{14}$
+ 空间复杂度$O(1)$

每辆车的旅行耗时是确定的，但暂未想打更低复杂度的算法。（...）

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
private:
    bool check(vector<int>& times, ll totalTrips, ll timeCnt) {
        for (int t : times) {
            totalTrips -= timeCnt / t;
        }
        return totalTrips <= 0;
    }
public:
    ll minimumTime(vector<int>& times, int totalTrips) {
        ll l = 1, r = 1e14 + 1;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(times, totalTrips, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
package main

func check(times []int, totalTrips int64, timeConsume int64) bool {
    for _, t := range times {
        totalTrips -= timeConsume / int64(t)
    }
    return totalTrips <= 0
}

func minimumTime(times []int, totalTrips int) int64 {
    l, r := int64(1), int64(1e14) + 1
    for l < r {
        mid := (l + r) >> 1
        if check(times, int64(totalTrips), mid) {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return l
}
```

#### Java

```java
class Solution {
    private boolean check(int[] times, long totalTrips, long timeCnt) {
        for (int t : times) {
            totalTrips -= timeCnt / t;
        }
        return totalTrips <= 0;
    }
    public long minimumTime(int[] times, int totalTrips) {
        long l = 1, r = (long)1e14 + 1;
        while (l < r) {
            long mid = (l + r) >> 1;
            if (check(times, totalTrips, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def check(self, timeCnt: int) -> bool:
        return sum(timeCnt // t for t in self.time) >= self.totalTrips
    
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        self.time, self.totalTrips = time, totalTrips
        l, r = 1, int(1e14) + 1
        while l < r:
            mid = (l + r) >> 1
            if self.check(mid):
                r = mid
            else:
                l = mid + 1
        return l

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/05/LeetCode%202187.%E5%AE%8C%E6%88%90%E6%97%85%E9%80%94%E7%9A%84%E6%9C%80%E5%B0%91%E6%97%B6%E9%97%B4/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142720764](https://letmefly.blog.csdn.net/article/details/142720764)
