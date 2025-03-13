---
title: 2644.找出可整除性得分最大的整数
date: 2024-05-18 15:41:46
tags: [题解, LeetCode, 简单, 数组, 暴力, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】2644.找出可整除性得分最大的整数：暴力模拟（两层循环）

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-divisibility-score/](https://leetcode.cn/problems/find-the-maximum-divisibility-score/)

<p>给你两个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和 <code>divisors</code> 。</p>

<p><code>divisors[i]</code> 的 <strong>可整除性得分</strong> 等于满足 <code>nums[j]</code> 能被 <code>divisors[i]</code> 整除的下标 <code>j</code> 的数量。</p>

<p>返回 <strong>可整除性得分</strong> 最大的整数 <code>divisors[i]</code> 。如果有多个整数具有最大得分，则返回数值最小的一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,7,9,3,9], divisors = [5,2,3]
<strong>输出：</strong>3
<strong>解释：</strong>divisors 中每个元素的可整除性得分为：
divisors[0] 的可整除性得分为 0 ，因为 nums 中没有任何数字能被 5 整除。
divisors[1] 的可整除性得分为 1 ，因为 nums[0] 能被 2 整除。 
divisors[2] 的可整除性得分为 3 ，因为 nums[2]、nums[3] 和 nums[4] 都能被 3 整除。 
因此，返回 divisors[2] ，它的可整除性得分最大。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [20,14,21,10], divisors = [5,7,5]
<strong>输出：</strong>5
<strong>解释：</strong>divisors 中每个元素的可整除性得分为：
divisors[0] 的可整除性得分为 2 ，因为 nums[0] 和 nums[3] 都能被 5 整除。
divisors[1] 的可整除性得分为 2 ，因为 nums[1] 和 nums[2] 都能被 7 整除。
divisors[2] 的可整除性得分为 2 ，因为 nums[0] 和 nums[3] 都能被5整除。 
由于 divisors[0]、divisors[1] 和 divisors[2] 的可整除性得分都是最大的，因此，我们返回数值最小的一个，即 divisors[2] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [12], divisors = [10,16]
<strong>输出：</strong>10
<strong>解释：</strong>divisors 中每个元素的可整除性得分为：
divisors[0] 的可整除性得分为 0 ，因为 nums 中没有任何数字能被 10 整除。
divisors[1] 的可整除性得分为 0 ，因为 nums 中没有任何数字能被 16 整除。 
由于 divisors[0] 和 divisors[1] 的可整除性得分都是最大的，因此，我们返回数值最小的一个，即 divisors[0] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, divisors.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], divisors[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：两层循环枚举

外层循环遍历每一个“被除数”，对于某个被除数$d$，记录其“可整除性得分”。

+ 如果这个得分**大于**历史最大得分，更新最大得分并将其暂时视为答案；
+ 如果这个得分**等于**历史最大得分，将它和“临时答案”中最小的那个暂时视为答案。

最终的“临时答案”即为最终答案。

+ 时间复杂度$O(len(nums)\times len(divisors))$
+ 空间复杂度$O(N\log N)$

> 本题似乎没有更小的时空复杂度的算法，能做的似乎最多是一些剪枝。

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int M = -1, ans = 0;
        for (int d : divisors) {
            int thisCnt = 0;
            for (int n : nums) {
                if (n % d == 0) {
                    thisCnt++;
                }
            }
            if (thisCnt > M) {
                M = thisCnt;
                ans = d;
            }
            else if (thisCnt == M) {
                M = thisCnt;
                ans = min(ans, d);
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        M, ans = -1, 0
        for d in divisors:
            thisCnt = 0
            for n in nums:
                thisCnt += n % d == 0
            if thisCnt > M:
                M = thisCnt
                ans = d
            elif thisCnt == M:
                ans = min(ans, d)
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/18/LeetCode%202644.%E6%89%BE%E5%87%BA%E5%8F%AF%E6%95%B4%E9%99%A4%E6%80%A7%E5%BE%97%E5%88%86%E6%9C%80%E5%A4%A7%E7%9A%84%E6%95%B4%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139026732](https://letmefly.blog.csdn.net/article/details/139026732)
