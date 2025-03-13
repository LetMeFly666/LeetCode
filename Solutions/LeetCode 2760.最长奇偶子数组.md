---
title: 2760.最长奇偶子数组
date: 2023-11-16 19:59:46
tags: [题解, LeetCode, 简单, 数组, 滑动窗口, 模拟, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】2760.最长奇偶子数组：模拟（使用一个变量记录状态）

力扣题目链接：[https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>threshold</code> 。</p>

<p>请你从 <code>nums</code> 的子数组中找出以下标 <code>l</code> 开头、下标 <code>r</code> 结尾 <code>(0 &lt;= l &lt;= r &lt; nums.length)</code> 且满足以下条件的 <strong>最长子数组</strong> ：</p>

<ul>
	<li><code>nums[l] % 2 == 0</code></li>
	<li>对于范围&nbsp;<code>[l, r - 1]</code> 内的所有下标 <code>i</code> ，<code>nums[i] % 2 != nums[i + 1] % 2</code></li>
	<li>对于范围&nbsp;<code>[l, r]</code> 内的所有下标 <code>i</code> ，<code>nums[i] &lt;= threshold</code></li>
</ul>

<p>以整数形式返回满足题目要求的最长子数组的长度。</p>

<p><strong>注意：子数组</strong> 是数组中的一个连续非空元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,5,4], threshold = 5
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，我们选择从 l = 1 开始、到 r = 3 结束的子数组 =&gt; [2,5,4] ，满足上述条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2], threshold = 2
<strong>输出：</strong>1
<strong>解释：</strong>
在这个示例中，我们选择从 l = 1 开始、到 r = 1 结束的子数组 =&gt; [2] 。
该子数组满足上述全部条件。可以证明 1 是满足题目要求的最大长度。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,4,5], threshold = 4
<strong>输出：</strong>3
<strong>解释：</strong>
在这个示例中，我们选择从 l = 0 开始、到 r = 2 结束的子数组 =&gt; [2,3,4] 。 
该子数组满足上述全部条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100 </code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100 </code></li>
	<li><code>1 &lt;= threshold &lt;= 100</code></li>
</ul>


    
## 方法一：模拟（使用一个变量记录状态）

使用变量$nowCnt$来记录当前“奇偶子数组”的长度。

+ 如果$nowCnt \neq 0$，说明当前元素前面是“奇偶子数组”，因此看当前元素能否加入到子数组中。
    + 如果当前元素$\le threshold$并且当前元素奇偶性和上一个元素不同，则$nowCnt++$
	+ 否则，更新答案$ans$最大值，并将$nowCnt$归零
+ 否则（$nowCnt$为零），则看当前元素能否成为“奇偶子数组”的开始（为偶、不大于$threshold$）

注意对$nowCnt \neq 0$的判断要在$nowCnt=0$的判断之前，因为偶数元素可能无法添加到数组末尾但是可以作为数组的开头。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int nowCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nowCnt) {
                if (nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2) {
                    nowCnt++;
                }
                else {
                    ans = max(ans, nowCnt);
                    nowCnt = 0;
                }
            }
            if (!nowCnt && nums[i] <= threshold && nums[i] % 2 == 0) {
                nowCnt = 1;
            }
        }
        return max(ans, nowCnt);
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans = 0
        nowCnt = 0
        for i in range(len(nums)):
            if nowCnt:
                if nums[i] <= threshold and nums[i] % 2 != nums[i - 1] % 2:
                    nowCnt += 1
                else:
                    ans = max(ans, nowCnt)
                    nowCnt = 0
            if not nowCnt:
                if nums[i] <= threshold and nums[i] % 2 == 0:
                    nowCnt = 1
        return max(ans, nowCnt)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/16/LeetCode%202760.%E6%9C%80%E9%95%BF%E5%A5%87%E5%81%B6%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134449952](https://letmefly.blog.csdn.net/article/details/134449952)
