---
title: 1911.最大子序列交替和
date: 2023-07-11 08:36:19
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
---

# 【LetMeFly】1911.最大子序列交替和

力扣题目链接：[https://leetcode.cn/problems/maximum-alternating-subsequence-sum/](https://leetcode.cn/problems/maximum-alternating-subsequence-sum/)

<p>一个下标从 <strong>0</strong> 开始的数组的 <strong>交替和</strong> 定义为 <strong>偶数</strong> 下标处元素之 <strong>和</strong> 减去 <strong>奇数</strong> 下标处元素之 <strong>和</strong> 。</p>

<ul>
	<li>比方说，数组 <code>[4,2,5,3]</code> 的交替和为 <code>(4 + 5) - (2 + 3) = 4</code> 。</li>
</ul>

<p>给你一个数组 <code>nums</code> ，请你返回 <code>nums</code> 中任意子序列的 <strong>最大交替和</strong> （子序列的下标 <strong>重新</strong> 从 0 开始编号）。</p>

<ul>
</ul>

<p>一个数组的 <strong>子序列</strong> 是从原数组中删除一些元素后（也可能一个也不删除）剩余元素不改变顺序组成的数组。比方说，<code>[2,7,4]</code> 是 <code>[4,<strong>2</strong>,3,<strong>7</strong>,2,1,<strong>4</strong>]</code> 的一个子序列（加粗元素），但是 <code>[2,4,2]</code> 不是。</p>

<p> </p>

<p><b>示例 1：</b></p>

<pre><b>输入：</b>nums = [<strong>4</strong>,<strong>2</strong>,<strong>5</strong>,3]
<b>输出：</b>7
<b>解释：</b>最优子序列为 [4,2,5] ，交替和为 (4 + 5) - 2 = 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [5,6,7,<strong>8</strong>]
<b>输出：</b>8
<b>解释：</b>最优子序列为 [8] ，交替和为 8 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [<strong>6</strong>,2,<strong>1</strong>,2,4,<strong>5</strong>]
<b>输出：</b>10
<b>解释：</b>最优子序列为 [6,1,5] ，交替和为 (6 + 5) - 1 = 10 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：动态规划（思维）

从头到尾遍历一遍nums数组，使用两个变量even和odd分别记录“子序列”的结尾为偶数下标 和 奇数下标 时的最优解。

遍历过程中，$even = max(even, odd + nums[i])$，$odd = max(odd, even - nums[i])$

最终返回$\max (odd, even)$即可。

**初始值怎么确定？**

初始值可以设置为遍历到下标为$0$时候的状态，即：$even = nums[0], odd = 0$。之后从下标$1$开始遍历。

**为什么不需要even, newEven, odd, newOdd？even的值修改后不会影响odd的值吗？**

如果使用newEven和newOdd，则有：

```cpp
newEven = max(even, odd + nums[i]);   // line1
newOdd = max(odd, even - nums[i]);    // line2
even = newEven, odd = newOdd;         // line3
```

执行过line1后，newEven的值一共有两种情况：

+ $even \geq odd + nums[i]$，则$newEven = even$，使用不使用newEven都一样
+ $even < odd + nums[i]$，则$newEven = odd + nums[i]$，$\max(odd, newEven - nums[i]) = \max(odd, odd) = odd$，因此时$odd > even - nums[i]$，所以$max(odd, even - nums[i]) = odd$，使用不使用newEven都一样

**为什么有的题解返回的是even而不是max(even, odd)？**

因为如果以奇数下标结尾的话，最后一定会减去最后的奇数，不可能优于其对应的以偶数结尾的序列。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;

class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        ll even = nums[0], old = 0;
        for (int i = 1; i < nums.size(); i++) {
            even = max(even, old + nums[i]);
            old = max(old, even - nums[i]);
        }
        return even;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        even, odd = nums[0], 0
        for i in range(1, len(nums)):
            even = max(even, odd + nums[i])
            odd = max(odd, even - nums[i])
        return even
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/11/LeetCode%201911.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%88%97%E4%BA%A4%E6%9B%BF%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131652316](https://letmefly.blog.csdn.net/article/details/131652316)
