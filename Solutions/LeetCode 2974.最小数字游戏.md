---
title: 2974.最小数字游戏
date: 2024-07-12 00:25:46
tags: [题解, LeetCode, 简单, 数组, 排序, 模拟, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】2974.最小数字游戏：排序+交换奇偶位

力扣题目链接：[https://leetcode.cn/problems/minimum-number-game/](https://leetcode.cn/problems/minimum-number-game/)

<p>你有一个下标从 <strong>0</strong> 开始、长度为 <strong>偶数</strong> 的整数数组 <code>nums</code> ，同时还有一个空数组 <code>arr</code> 。Alice 和 Bob 决定玩一个游戏，游戏中每一轮 Alice 和 Bob 都会各自执行一次操作。游戏规则如下：</p>

<ul>
	<li>每一轮，Alice 先从 <code>nums</code> 中移除一个<strong> 最小</strong> 元素，然后 Bob 执行同样的操作。</li>
	<li>接着，Bob 会将移除的元素添加到数组 <code>arr</code> 中，然后 Alice 也执行同样的操作。</li>
	<li>游戏持续进行，直到 <code>nums</code> 变为空。</li>
</ul>

<p>返回结果数组 <code>arr</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,2,3]
<strong>输出：</strong>[3,2,5,4]
<strong>解释：</strong>第一轮，Alice 先移除 2 ，然后 Bob 移除 3 。然后 Bob 先将 3 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [3,2] 。
第二轮开始时，nums = [5,4] 。Alice 先移除 4 ，然后 Bob 移除 5 。接着他们都将元素添加到 arr 中，arr 变为 [3,2,5,4] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,5]
<strong>输出：</strong>[5,2]
<strong>解释：</strong>第一轮，Alice 先移除 2 ，然后 Bob 移除 5 。然后 Bob 先将 5 添加到 arr 中，接着 Alice 再将 2 添加到 arr 中。于是 arr = [5,2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums.length % 2 == 0</code></li>
</ul>


    
## 解题方法：排序

相当于是每次挑选两个最小的数，然后让第二小的数放到第一小的数的前面。

例如`[1, 2, 3, 4]`会变成`[2, 1, 4, 3]`。

因此对nums排序，之后用i每隔一个下标遍历数组，交换$nums[i]$和$nums[i+1]$，最终返回nums即可。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < nums.size(); i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        for i in range(0, len(nums) - 1, 2):
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
        return nums
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/12/LeetCode%202974.%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97%E6%B8%B8%E6%88%8F/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140365205](https://letmefly.blog.csdn.net/article/details/140365205)
