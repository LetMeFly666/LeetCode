---
title: 3066.超过阈值的最少操作数 II：模拟 - 原地建堆O(1)空间 / 优先队列O(n)空间
date: 2025-01-15 14:55:00
tags: [题解, LeetCode, 中等, 数组, 模拟, 堆（优先队列）, 堆, 优先队列]
---

# 【LetMeFly】3066.超过阈值的最少操作数 II：模拟 - 原地建堆O(1)空间 / 优先队列O(n)空间

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-ii/](https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-ii/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一次操作中，你将执行：</p>

<ul>
	<li>选择 <code>nums</code>&nbsp;中最小的两个整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;。</li>
	<li>将&nbsp;<code>x</code> 和&nbsp;<code>y</code> 从&nbsp;<code>nums</code>&nbsp;中删除。</li>
	<li>将&nbsp;<code>min(x, y) * 2 + max(x, y)</code>&nbsp;添加到数组中的任意位置。</li>
</ul>

<p><b>注意，</b>只有当&nbsp;<code>nums</code>&nbsp;至少包含两个元素时，你才可以执行以上操作。</p>

<p>你需要使数组中的所有元素都大于或等于&nbsp;<code>k</code>&nbsp;，请你返回需要的&nbsp;<strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,11,10,1,3], k = 10
<b>输出：</b>2
<b>解释：</b>第一次操作中，我们删除元素 1 和 2 ，然后添加 1 * 2 + 2 到 nums 中，nums 变为 [4, 11, 10, 3] 。
第二次操作中，我们删除元素 3 和 4 ，然后添加 3 * 2 + 4 到 nums 中，nums 变为 [10, 11, 10] 。
此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。
使数组中所有元素都大于等于 10 需要的最少操作次数为 2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,2,4,9], k = 20
<b>输出：</b>4
<b>解释：</b>第一次操作后，nums 变为 [2, 4, 9, 3] 。
第二次操作后，nums 变为 [7, 4, 9] 。
第三次操作后，nums 变为 [15, 9] 。
第四次操作后，nums 变为 [33] 。
此时，数组中的所有元素都大于等于 20 ，所以我们停止操作。
使数组中所有元素都大于等于 20 需要的最少操作次数为 4 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>输入保证答案一定存在，也就是说一定存在一个操作序列使数组中所有元素都大于等于&nbsp;<code>k</code> 。</li>
</ul>


    
## 解题方法：小根堆

这道题说明了让你模拟，那咱就模拟。

使用小根堆（堆顶元素最小）。每次从堆中取出两个元素，并将计算结果放回堆中。

这样就保证了每次取出的元素都是当前最小值，直到堆顶元素$\geq k$停止。

+ 时间复杂度$O(n\log n)$：原地建堆时间复杂度$O(n)$，优先队列（额外建堆）时间复杂度$O(n\log n)$；单次操作时间复杂度$O(\log n)$，操作次数不超过$n$次
+ 空间复杂度：原地建堆$O(1)$，优先队列（额外建堆）$O(n)$

### AC代码

#### C++ - 原地建堆

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-15 13:38:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-15 13:58:45
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        make_heap(nums.begin(), nums.end(), greater<>());
        while (nums[0] < k) {
            int x = nums[0];
            pop_heap(nums.begin(), nums.end() - ans, greater<>());
            int y = nums[0];
            pop_heap(nums.begin(), nums.end() - (ans + 1), greater<>());
            nums[nums.size() - ans - 2] = min((unsigned)k, (unsigned)x + (unsigned)y + (unsigned)min(x, y));
            push_heap(nums.begin(), nums.end() - (ans + 1), greater<>());
            ans++;
        }
        return ans;
    }
};
```

+ 执行用时分布120ms击败49.31%；
+ 消耗内存分布83.55MB击败**100.00%**。

#### Python - 原地建堆

```python
'''
Author: LetMeFly
Date: 2025-01-15 14:02:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-15 14:12:18
'''
from typing import List
import heapq

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        heapq.heapify(nums)
        while nums[0] < k:
            x = nums[0]
            heapq.heappop(nums)
            y = nums[0]
            heapq.heappop(nums)
            heapq.heappush(nums, 2 * min(x, y) + max(x, y))
            ans += 1
        return ans

if __name__ == '__main__':
    sol = Solution()
    print(sol.minOperations([2, 11, 10, 1, 3], 10))
```

#### Java - 优先队列

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-15 14:22:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-15 14:30:40
 */
import java.util.PriorityQueue;

class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int t : nums) {
            pq.add((long)t);
        }
        while (pq.peek() < k) {
            long x = pq.remove(), y = pq.remove();
            pq.add(Math.min(x, y) * 2 + Math.max(x, y));
            ans++;
        }
        return ans;
    }
}
```

#### Go - 优先队列

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-15 14:37:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-15 14:53:17
 */
package main

import "container/heap"

func minOperations(nums []int, k int) (ans int) {
    pq := make(heap_MOETV2, 0)
    heap.Init(&pq)
    for _, n := range nums {
        heap.Push(&pq, n)
    }
    for ; pq[0] < k; ans++ {
        x, y := heap.Pop(&pq).(int), heap.Pop(&pq).(int)
        heap.Push(&pq, x + x + y)
    }
    return
}


type heap_MOETV2 []int

func (h heap_MOETV2) Len() int { return len(h) }
func (h heap_MOETV2) Less(i, j int) bool { return h[i] < h[j] }
func (h heap_MOETV2) Swap(i, j int) { h[i], h[j] = h[j], h[i] }
func (h *heap_MOETV2) Push(a interface{}) { *h = append(*h, a.(int)) }
func (h *heap_MOETV2) Pop() interface{} { temp := *h; ans := temp[len(temp) - 1]; (*h) = temp[0:len(temp) - 1]; return ans }

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/15/LeetCode%203066.%E8%B6%85%E8%BF%87%E9%98%88%E5%80%BC%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%95%B0II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145160799](https://letmefly.blog.csdn.net/article/details/145160799)
