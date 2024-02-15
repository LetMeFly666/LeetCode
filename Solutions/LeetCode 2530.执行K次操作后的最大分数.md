---
title: 2530.执行 K 次操作后的最大分数
date: 2023-10-18 09:32:49
tags: [题解, LeetCode, 中等, 贪心, 数组, 堆（优先队列）, 堆, 优先队列]
---

# 【LetMeFly】2530.执行 K 次操作后的最大分数：优先队列（贪心）

力扣题目链接：[https://leetcode.cn/problems/maximal-score-after-applying-k-operations/](https://leetcode.cn/problems/maximal-score-after-applying-k-operations/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。你的 <strong>起始分数</strong> 为 <code>0</code> 。</p>

<p>在一步 <strong>操作</strong> 中：</p>

<ol>
	<li>选出一个满足 <code>0 &lt;= i &lt; nums.length</code> 的下标 <code>i</code> ，</li>
	<li>将你的 <strong>分数</strong> 增加 <code>nums[i]</code> ，并且</li>
	<li>将 <code>nums[i]</code> 替换为 <code>ceil(nums[i] / 3)</code> 。</li>
</ol>

<p>返回在 <strong>恰好</strong> 执行 <code>k</code> 次操作后，你可能获得的最大分数。</p>

<p>向上取整函数 <code>ceil(val)</code> 的结果是大于或等于 <code>val</code> 的最小整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,10,10,10,10], k = 5
<strong>输出：</strong>50
<strong>解释：</strong>对数组中每个元素执行一次操作。最后分数是 10 + 10 + 10 + 10 + 10 = 50 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,10,3,3,3], k = 3
<strong>输出：</strong>17
<strong>解释：</strong>可以执行下述操作：
第 1 步操作：选中 i = 1 ，nums 变为 [1,<em><strong>4</strong></em>,3,3,3] 。分数增加 10 。
第 2 步操作：选中 i = 1 ，nums 变为 [1,<em><strong>2</strong></em>,3,3,3] 。分数增加 4 。
第 3 步操作：选中 i = 2 ，nums 变为 [1,1,<em><strong>1</strong></em>,3,3] 。分数增加 3 。
最后分数是 10 + 4 + 3 = 17 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：优先队列（贪心）

每次取一个数并累加到总分中，要想使总分最大，当然要选尽可能大的数。

因此使用一个大根堆，将数组中所有的整数加入堆栈（优先队列），并进行$k$次以下操作：

> 每次从队首（堆顶）取出一个元素累加，并将其三分之一（向上取整）重新入队。

最终返回累加的答案即可。

+ 时间复杂度$O(len(nums) + k\times \log len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int t : nums) {
            pq.push(t);
        }
        ll ans = 0;
        while (k--) {
            int thisNum = pq.top();
            pq.pop();
            ans += thisNum;
            pq.push((thisNum + 2) / 3);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# import heapq

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        nums = list(map(lambda x: -x, nums))
        heapq.heapify(nums)
        ans = 0
        for _ in range(k):
            thisNum = -heapq.heappop(nums)
            ans += thisNum
            heapq.heappush(nums, -((thisNum + 2) // 3))
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/18/LeetCode%202530.%E6%89%A7%E8%A1%8CK%E6%AC%A1%E6%93%8D%E4%BD%9C%E5%90%8E%E7%9A%84%E6%9C%80%E5%A4%A7%E5%88%86%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133899145](https://letmefly.blog.csdn.net/article/details/133899145)
