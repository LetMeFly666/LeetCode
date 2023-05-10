---
title: 1470.重新排列数组
date: 2022-08-29 08:48:08
tags: [题解, LeetCode, 简单, 数组, 双指针]
---

# 【LetMeFly】1470.重新排列数组：考研扣两分的做法

力扣题目链接：[https://leetcode.cn/problems/shuffle-the-array/](https://leetcode.cn/problems/shuffle-the-array/)

<p>给你一个数组 <code>nums</code> ，数组中有 <code>2n</code> 个元素，按 <code>[x<sub>1</sub>,x<sub>2</sub>,...,x<sub>n</sub>,y<sub>1</sub>,y<sub>2</sub>,...,y<sub>n</sub>]</code> 的格式排列。</p>

<p>请你将数组按 <code>[x<sub>1</sub>,y<sub>1</sub>,x<sub>2</sub>,y<sub>2</sub>,...,x<sub>n</sub>,y<sub>n</sub>]</code> 格式重新排列，返回重排后的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,5,1,3,4,7], n = 3
<strong>输出：</strong>[2,3,5,4,1,7] 
<strong>解释：</strong>由于 x<sub>1</sub>=2, x<sub>2</sub>=5, x<sub>3</sub>=1, y<sub>1</sub>=3, y<sub>2</sub>=4, y<sub>3</sub>=7 ，所以答案为 [2,3,5,4,1,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,4,3,2,1], n = 4
<strong>输出：</strong>[1,4,2,3,3,2,4,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,2,2], n = 2
<strong>输出：</strong>[1,2,1,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>nums.length == 2n</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^3</code></li>
</ul>


    
## 方法一：额外空间

不使用额外空间不好想，还是使用额外空间而作答次优解吧。

开辟一个额外空间来存储答案，使用两个指针，分别指向下标$0$和下标$\frac{n}{2}$

之后遍历答案数组，如果是奇数下标，就将第二个指针所指元素赋值给当前元素，并将第二个指针右移。

否则（偶数下标）就对第一个指针进行上述操作。

+ 时间复杂度$O(n)$，其中$n$是元素个数
+ 空间复杂度$O(1)$，$O(1)$是因为力扣的答案不计入算法复杂度。注意：虽是$O(1)$但此法并不是原地操作

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        int p1 = 0, p2 = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2) {
                ans[i] = nums[p2++];
            }
            else {
                ans[i] = nums[p1++];
            }
        }
        return ans;
    }
};

/*
尝试使用双指针原地交换但失败了的尝试

1,2,3,4,5,6,7,8 
1,5,3,4,2,6,7,8
1,5,2,4,3,6,7,8
1,5,2,6,3,4,7,8


1,5,2,6,3,7,4,8
*/
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/29/LeetCode%201470.%E9%87%8D%E6%96%B0%E6%8E%92%E5%88%97%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126577789](https://letmefly.blog.csdn.net/article/details/126577789)
