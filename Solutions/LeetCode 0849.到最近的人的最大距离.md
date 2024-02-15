---
title: 849.到最近的人的最大距离
date: 2023-08-22 09:07:48
tags: [题解, LeetCode, 中等, 数组, 模拟, 遍历]
---

# 【LetMeFly】849.到最近的人的最大距离

力扣题目链接：[https://leetcode.cn/problems/maximize-distance-to-closest-person/](https://leetcode.cn/problems/maximize-distance-to-closest-person/)

<p>给你一个数组 <code>seats</code> 表示一排座位，其中 <code>seats[i] = 1</code> 代表有人坐在第 <code>i</code> 个座位上，<code>seats[i] = 0</code> 代表座位 <code>i</code> 上是空的（<strong>下标从 0 开始</strong>）。</p>

<p>至少有一个空座位，且至少有一人已经坐在座位上。</p>

<p>亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。</p>

<p>返回他到离他最近的人的最大距离。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/10/distance.jpg" style="width: 650px; height: 257px;" />
<pre>
<strong>输入：</strong>seats = [1,0,0,0,1,0,1]
<strong>输出：</strong>2
<strong>解释：
</strong>如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
因此，他到离他最近的人的最大距离是 2 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>seats = [1,0,0,0]
<strong>输出：</strong>3
<strong>解释：</strong>
如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
这是可能的最大距离，所以答案是 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>seats = [0,1]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= seats.length <= 2 * 10<sup>4</sup></code></li>
	<li><code>seats[i]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li>至少有一个 <strong>空座位</strong></li>
	<li>至少有一个 <strong>座位上有人</strong></li>
</ul>


    
## 方法一：遍历

一共分为三种情况：

1. 坐**最**左边
2. **尽可能**坐两人中间
3. 坐**最**右边

遍历一遍，取一个最大值即可。

+ 时间复杂度$O(len(seats))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=1;
        int lastSeat = -1;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                if (lastSeat == -1) {  // 首次
                    ans = max(ans, i);
                }
                else {
                    ans = max(ans, (i - lastSeat) / 2);
                }
                lastSeat = i;
            }
        }
        ans = max(ans, (int)seats.size() - lastSeat - 1);
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        ans = 1
        lastSeat = -1
        for i in range(len(seats)):
            if seats[i]:
                if lastSeat == -1:
                    ans = max(ans, i)
                else:
                    ans = max(ans, (i - lastSeat) // 2)
                lastSeat = i
        ans = max(ans, len(seats) - lastSeat - 1)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/22/LeetCode%200849.%E5%88%B0%E6%9C%80%E8%BF%91%E7%9A%84%E4%BA%BA%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%9D%E7%A6%BB/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132420545](https://letmefly.blog.csdn.net/article/details/132420545)
