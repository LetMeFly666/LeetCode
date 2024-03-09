---
title: 2386.找出数组的第 K 大和
date: 2024-03-09 18:35:02
tags: [题解, LeetCode, 困难, 数组, 排序, 堆（优先队列）, 堆, 优先队列]
---

# 【LetMeFly】2386.找出数组的第 K 大和：逆向思维（小根堆）

力扣题目链接：[https://leetcode.cn/problems/find-the-k-sum-of-an-array/](https://leetcode.cn/problems/find-the-k-sum-of-an-array/)

<p>给你一个整数数组 <code>nums</code> 和一个 <strong>正</strong> 整数 <code>k</code> 。你可以选择数组的任一 <strong>子序列</strong> 并且对其全部元素求和。</p>

<p>数组的 <strong>第 k 大和</strong> 定义为：可以获得的第 <code>k</code> 个 <strong>最大</strong> 子序列和（子序列和允许出现重复）</p>

<p>返回数组的 <strong>第 k 大和</strong> 。</p>

<p>子序列是一个可以由其他数组删除某些或不删除元素排生而来的数组，且派生过程不改变剩余元素的顺序。</p>

<p><strong>注意：</strong>空子序列的和视作 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,-2], k = 5
<strong>输出：</strong>2
<strong>解释：</strong>所有可能获得的子序列和列出如下，按递减顺序排列：
- 6、4、4、2、<strong><em>2</em></strong>、0、0、-2
数组的第 5 大和是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,-2,3,4,-10,12], k = 16
<strong>输出：</strong>10
<strong>解释：</strong>数组的第 16 大和是 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= min(2000, 2<sup>n</sup>)</code></li>
</ul>


    
## 方法一：逆向思维（小根堆）

> + 最大和怎么找？数组中正数之和即是。
> + 第二大和怎么找？最大和 的基础上减去一个很小的正数或加上一个很小的负数。
> + 第三大和怎么找？最大和/第二大和 的基础上减去一个很小的正数或加上一个很小的负数。
> + ...

不难发现除了初始的最大和，负数和其绝对值的正数结果是等价的。因此我们可以：

> 遍历一遍数组，若为正整数则累加，为负则变为正（取绝对值）。这样最大和就找到了。

又因为求的是“序列”和而不是“子数组”和，也就是说元素可以不连续。因此我们可以：

> 对处理后的全是非负数的数组从小到大排个序。

接下来的操作就是不断地从“最大和”的基础上，减去非负数组中的一些数了。每次减去地尽可能小，一共减去$k$次。也就是说：

> 我们只需要找到这个递增非负数组的前$k$个最小和即可。

假设这个处理后的数组是```[1, 2, 3]```，那么怎么生成它的$2^3$个子序列呢？

> + 初始序列为空：```[]```
> + 在空序列的基础上添加```1```得到```[1]```
> + 在```[1]```的基础上添加```2```得到```[1, 2]```；或将最后的```1```替换成```2```得到```[2]```
> + 在```[2]```基础上添加```3```得到```[2, 3]```；或直接替换最后的```2```成```[3]```
> + 在```[1, 2]```的基础上添加```3```得到```[1, 2, 3]```；或直接替换最后的```2```成```[1, 3]```

这不是很适合最小堆吗？

> 堆中存放```(当前和, 添加到了第几个元素）```，每次选当前和最小的出堆，即为下一个“最小序列和”。

+ 时间复杂度$O(n\log n + k\log k)$，其中$n=len(nums)$
+ 空间复杂度$O(k)$

### AC代码

#### C++

```cpp
/*
1 2 3

      1
    12  2
 123   23  3
*/

typedef long long ll;
typedef pair<ll, int> pli;
class Solution {
public:
    ll kSum(vector<int>& nums, int k) {
        ll sum = 0;
        for (int& t : nums) {
            if (t >= 0) {
                sum += t;
            }
            else {
                t = -t;
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({nums[0], 0});
        ll toDesc = 0;
        for (int i = 1; i < k; i++) {
            auto [nowSum, th] = pq.top();
            toDesc = nowSum;
            pq.pop();
            if (th == nums.size() - 1) {
                continue;
            }
            pq.push({nowSum + nums[th + 1], th + 1});
            pq.push({nowSum - nums[th] + nums[th + 1], th + 1});
        }
        return sum - toDesc;
    }
};
```

#### Python

```python
# from typing import List
# import heapq

class Solution:
    def kSum(self, nums: List[int], k: int) -> int:
        sum_ = 0
        for i in range(len(nums)):
            if nums[i] >= 0:
                sum_ += nums[i]
            else:
                nums[i] = -nums[i]
        nums.sort()
        pq = [(nums[0], 0)]
        toDesc = 0
        for _ in range(1, k):
            nowSum, th = heapq.heappop(pq)
            toDesc = nowSum
            if th == len(nums) - 1:
                continue
            heapq.heappush(pq, (nowSum + nums[th + 1], th + 1))
            heapq.heappush(pq, (nowSum - nums[th] + nums[th + 1], th + 1))
        return sum_ - toDesc
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/09/LeetCode%202386.%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E7%9A%84%E7%AC%ACK%E5%A4%A7%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136588803](https://letmefly.blog.csdn.net/article/details/136588803)
