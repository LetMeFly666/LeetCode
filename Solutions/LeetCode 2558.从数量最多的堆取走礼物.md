---
title: 2558.从数量最多的堆取走礼物
date: 2023-10-28 09:27:32
tags: [题解, LeetCode, 简单, 数组, 模拟, 堆（优先队列）, 优先队列]
categories: [题解, LeetCode]
---

# 【LetMeFly】2558.从数量最多的堆取走礼物：优先队列（大根堆）

力扣题目链接：[https://leetcode.cn/problems/take-gifts-from-the-richest-pile/](https://leetcode.cn/problems/take-gifts-from-the-richest-pile/)

<p>给你一个整数数组 <code>gifts</code> ，表示各堆礼物的数量。每一秒，你需要执行以下操作：</p>

<ul>
	<li>选择礼物数量最多的那一堆。</li>
	<li>如果不止一堆都符合礼物数量最多，从中选择任一堆即可。</li>
	<li>选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。</li>
</ul>

<p>返回在 <code>k</code> 秒后剩下的礼物数量<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>gifts = [25,64,9,4,100], k = 4
<strong>输出：</strong>29
<strong>解释：</strong> 
按下述方式取走礼物：
- 在第一秒，选中最后一堆，剩下 10 个礼物。
- 接着第二秒选中第二堆礼物，剩下 8 个礼物。
- 然后选中第一堆礼物，剩下 5 个礼物。
- 最后，再次选中最后一堆礼物，剩下 3 个礼物。
最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>gifts = [1,1,1,1], k = 4
<strong>输出：</strong>4
<strong>解释：</strong>
在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。 
也就是说，你无法获取任一堆中的礼物。 
所以，剩下礼物的总数量是 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= gifts.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= gifts[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>3</sup></code></li>
</ul>


    
## 方法一：优先队列（大根堆）

首先将gifts数组变成大根堆（或者优先队列），然后在接下来的$n$次操作中，每次取出堆顶的一个元素，并将这个元素($t$)的$\lfloor \sqrt{t} \rfloor$加入堆栈中。

$k$次操作后，返回堆/数组中元素之和即可。

+ 时间复杂度$O(n + k \log n)$
+ 空间复杂度$O(1)$。这里直接在$gifts$数组上建堆了，没有使用过多的额外空间

### AC代码

#### C++

```cpp
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        make_heap(gifts.begin(), gifts.end());
        while (k--) {
            pop_heap(gifts.begin(), gifts.end());  // 弹出堆顶并一到数组末尾
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
```

#### Python

```python
from typing import List
from math import sqrt
import heapq

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for i in range(len(gifts)):
            gifts[i] = -gifts[i]
        heapq.heapify(gifts)
        for _ in range(k):
            thisGift = heapq.heappop(gifts)
            heapq.heappush(gifts, -int(sqrt(-thisGift)))
        return -sum(gifts)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/28/LeetCode%202558.%E4%BB%8E%E6%95%B0%E9%87%8F%E6%9C%80%E5%A4%9A%E7%9A%84%E5%A0%86%E5%8F%96%E8%B5%B0%E7%A4%BC%E7%89%A9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134088006](https://letmefly.blog.csdn.net/article/details/134088006)
