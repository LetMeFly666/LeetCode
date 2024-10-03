---
title: 2073.买票需要的时间
date: 2024-10-03 13:58:00
tags: [题解, LeetCode, 简单, 队列, 数组, 模拟, 遍历]
---

# 【LetMeFly】2073.买票需要的时间：硬卷O(n)——一次遍历

力扣题目链接：[https://leetcode.cn/problems/time-needed-to-buy-tickets/](https://leetcode.cn/problems/time-needed-to-buy-tickets/)

<p>有 <code>n</code> 个人前来排队买票，其中第 <code>0</code> 人站在队伍 <strong>最前方</strong> ，第 <code>(n - 1)</code> 人站在队伍 <strong>最后方</strong> 。</p>

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>tickets</code> ，数组长度为 <code>n</code> ，其中第 <code>i</code> 人想要购买的票数为 <code>tickets[i]</code> 。</p>

<p>每个人买票都需要用掉 <strong>恰好 1 秒</strong> 。一个人 <strong>一次只能买一张票</strong> ，如果需要购买更多票，他必须走到&nbsp; <strong>队尾</strong> 重新排队（<strong>瞬间 </strong>发生，不计时间）。如果一个人没有剩下需要买的票，那他将会 <strong>离开</strong> 队伍。</p>

<p>返回位于位置 <code>k</code>（下标从 <strong>0</strong> 开始）的人完成买票需要的时间（以秒为单位）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>tickets = [2,3,2], k = 2
<strong>输出：</strong>6
<strong>解释：</strong> 
- 第一轮，队伍中的每个人都买到一张票，队伍变为 [1, 2, 1] 。
- 第二轮，队伍中的每个都又都买到一张票，队伍变为 [0, 1, 0] 。
位置 2 的人成功买到 2 张票，用掉 3 + 3 = 6 秒。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>tickets = [5,1,1,1], k = 0
<strong>输出：</strong>8
<strong>解释：</strong>
- 第一轮，队伍中的每个人都买到一张票，队伍变为 [4, 0, 0, 0] 。
- 接下来的 4 轮，只有位置 0 的人在买票。
位置 0 的人成功买到 5 张票，用掉 4 + 1 + 1 + 1 + 1 = 8 秒。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == tickets.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= tickets[i] &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt; n</code></li>
</ul>


    
## 解题方法：一次遍历

试想，下标`k`买完所有票后，其他人分别买了几张票？

+ 如果这个人`i`在`k`及其之*前*，那么他最多买`tickets[k]`张票，他实际买了`min(tickets[i], tickets[k])`张。
+ 如果这个人`i`在`k`及其之*后*，那么他最多买`tickets[k] - 1`张票，他实际买了`min(tickets[i], tickets[k] - 1)`张。

因此，一次遍历即可得到答案了。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++) {
            ans += i <= k ? min(tickets[i], tickets[k]) : min(tickets[i], tickets[k] - 1);
        }
        return ans;
    }
};
```

#### Go

```go
package main

func timeRequiredToBuy(tickets []int, k int) int {
    ans := 0
    for th, t := range tickets {
        if th <= k {
            ans += min(t, tickets[k])
        } else {
            ans += min(t, tickets[k] - 1)
        }
    }
    return ans
}
```

执行用时分布0ms击败100.00%复杂度分析；消耗内存分布2.10MB击败100.00%。

#### Java

```java
class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        int ans = 0;
        for (int i = 0; i < tickets.length; i++) {
            if (i <= k) {
                ans += Math.min(tickets[i], tickets[k]);
            } else {
                ans += Math.min(tickets[i], tickets[k] - 1);
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        # return sum(min(t, tickets[k] if th <= k else tickets[k] - 1) for th, t in enumerate(tickets))
        return sum(min(t, tickets[k] - (th > k)) for th, t in enumerate(tickets))
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/03/LeetCode%202073.%E4%B9%B0%E7%A5%A8%E9%9C%80%E8%A6%81%E7%9A%84%E6%97%B6%E9%97%B4/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142691600](https://letmefly.blog.csdn.net/article/details/142691600)
