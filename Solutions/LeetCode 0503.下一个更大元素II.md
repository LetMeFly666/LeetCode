---
title: 503.下一个更大元素 II
date: 2022-11-06 08:41:39
tags: [题解, LeetCode, 中等, 栈, 数组, 单调栈]
---

# 【LetMeFly】503.下一个更大元素 II

力扣题目链接：[https://leetcode.cn/problems/next-greater-element-ii/](https://leetcode.cn/problems/next-greater-element-ii/)

<p>给定一个循环数组&nbsp;<code>nums</code>&nbsp;（&nbsp;<code>nums[nums.length - 1]</code>&nbsp;的下一个元素是&nbsp;<code>nums[0]</code>&nbsp;），返回&nbsp;<em><code>nums</code>&nbsp;中每个元素的 <strong>下一个更大元素</strong></em> 。</p>

<p>数字 <code>x</code>&nbsp;的 <strong>下一个更大的元素</strong> 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,1]
<strong>输出:</strong> [2,-1,2]
<strong>解释:</strong> 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,3]
<strong>输出:</strong> [2,3,4,-1,4]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：单调栈

使用一个单调栈，栈底元素大栈顶元素小。

遍历原始数组，在栈顶元素（有的话）小于当前元素时，不断出栈栈顶元素 并且 将栈顶元素的“下一个最大元素”标记为当前元素，然后将当前元素入栈。

这样，每个元素出栈的时候，都是其右边的“第一个最大元素”将其弹出的，最终留在栈里的元素就是“后面没有比它更大的元素”的元素

但是本题中，```nums```是一个“循环数组”，也就是说最后一个元素的“下一个元素”是第一个元素，因此我们遍历两遍原始数组即可。

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        int n = nums.size(), to = 2 * nums.size();
        for (int i = 0; i < to; i++) {
            int loc = i % n;
            while (!st.empty() && nums[st.top()] < nums[loc]) {
                ans[st.top()] = nums[loc];
                st.pop();
            }
            st.push(loc);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/06/LeetCode%200503.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127712170](https://letmefly.blog.csdn.net/article/details/127712170)
