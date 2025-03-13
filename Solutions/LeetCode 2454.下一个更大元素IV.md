---
title: 2454.下一个更大元素 IV
date: 2023-12-12 20:35:59
tags: [题解, LeetCode, 困难, 栈, 数组, 二分查找, 排序, 单调栈, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】2454.下一个更大元素 IV：双单调栈

力扣题目链接：[https://leetcode.cn/problems/next-greater-element-iv/](https://leetcode.cn/problems/next-greater-element-iv/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的非负整数数组&nbsp;<code>nums</code>&nbsp;。对于&nbsp;<code>nums</code>&nbsp;中每一个整数，你必须找到对应元素的&nbsp;<strong>第二大</strong>&nbsp;整数。</p>

<p>如果&nbsp;<code>nums[j]</code>&nbsp;满足以下条件，那么我们称它为&nbsp;<code>nums[i]</code>&nbsp;的&nbsp;<strong>第二大</strong>&nbsp;整数：</p>

<ul>
	<li><code>j &gt; i</code></li>
	<li><code>nums[j] &gt; nums[i]</code></li>
	<li>恰好存在 <strong>一个</strong>&nbsp;<code>k</code>&nbsp;满足 <code>i &lt; k &lt; j</code>&nbsp;且&nbsp;<code>nums[k] &gt; nums[i]</code>&nbsp;。</li>
</ul>

<p>如果不存在&nbsp;<code>nums[j]</code>&nbsp;，那么第二大整数为&nbsp;<code>-1</code>&nbsp;。</p>

<ul>
	<li>比方说，数组&nbsp;<code>[1, 2, 4, 3]</code>&nbsp;中，<code>1</code>&nbsp;的第二大整数是&nbsp;<code>4</code>&nbsp;，<code>2</code>&nbsp;的第二大整数是&nbsp;<code>3</code>&nbsp;，<code>3</code> 和&nbsp;<code>4</code>&nbsp;的第二大整数是&nbsp;<code>-1</code>&nbsp;。</li>
</ul>

<p>请你返回一个整数数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[i]</code>是<em>&nbsp;</em><code>nums[i]</code>&nbsp;的第二大整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,4,0,9,6]
<b>输出：</b>[9,6,6,-1,-1]
<strong>解释：</strong>
下标为 0 处：2 的右边，4 是大于 2 的第一个整数，9 是第二个大于 2 的整数。
下标为 1 处：4 的右边，9 是大于 4 的第一个整数，6 是第二个大于 4 的整数。
下标为 2 处：0 的右边，9 是大于 0 的第一个整数，6 是第二个大于 0 的整数。
下标为 3 处：右边不存在大于 9 的整数，所以第二大整数为 -1 。
下标为 4 处：右边不存在大于 6 的整数，所以第二大整数为 -1 。
所以我们返回 [9,6,6,-1,-1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3]
<b>输出：</b>[-1,-1]
<strong>解释：</strong>
由于每个数右边都没有更大的数，所以我们返回 [-1,-1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：双单调栈

### 思路

使用一个单调栈可以很方便地得出每个数的“第一个更大数”。但现在要求每个数的“第二个更大数”，怎么办呢？那就使用两个单调栈呗。

使用两个单调非递增栈st1和st2，首先将数存到st1中。如果st1中（栈顶）的数遇到了更大的数，就（不断）弹出（栈顶元素）并放入st2。

在st2中若栈顶元素遇到了更大的数a，那么a就是栈顶元素的“第二更大数”。

### 方法

遍历数组，先处理st2后处理st1，保证二者为单调（非递增）栈即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> st1, st2;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            while (st2.size() && nums[st2.top()] < nums[i]) {  // 第二次遇到“更大数”
                ans[st2.top()] = nums[i];
                st2.pop();
            }
            stack<int> temp;  // temp的作用是保持st2的入栈顺序为大到小
            while (st1.size() && nums[st1.top()] < nums[i]) {  // 第一次遇到更大数
                temp.push(st1.top());
                st1.pop();
            }
            st1.push(i);
            while (temp.size()) {
                st2.push(temp.top());
                temp.pop();
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        ans = [-1] * len(nums)
        st1 = []
        st2 = []
        for i in range(len(nums)):
            while st2 and nums[st2[-1]] < nums[i]:
                ans[st2[-1]] = nums[i]
                st2.pop()
            temp = []
            while st1 and nums[st1[-1]] < nums[i]:
                temp.append(st1[-1])
                st1.pop()
            st1.append(i)
            temp.reverse()
            st2 += temp
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/12/LeetCode%202454.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0IV/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134958992](https://letmefly.blog.csdn.net/article/details/134958992)
