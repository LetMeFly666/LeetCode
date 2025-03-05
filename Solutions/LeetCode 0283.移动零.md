---
title: 283.移动零：三种小方法实现
date: 2025-03-05 22:48:59
tags: [题解, LeetCode, 简单, 数组, 双指针]
---

# 【LetMeFly】283.移动零：三种小方法实现

力扣题目链接：[https://leetcode.cn/problems/move-zeroes/](https://leetcode.cn/problems/move-zeroes/)

<p>给定一个数组 <code>nums</code>，编写一个函数将所有 <code>0</code> 移动到数组的末尾，同时保持非零元素的相对顺序。</p>

<p><strong>请注意</strong>&nbsp;，必须在不复制数组的情况下原地对数组进行操作。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = <code>[0,1,0,3,12]</code>
<strong>输出:</strong> <code>[1,3,12,0,0]</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = <code>[0]</code>
<strong>输出:</strong> <code>[0]</code></pre>

<p>&nbsp;</p>

<p><strong>提示</strong>:</p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= nums[i] &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>

<p><b>进阶：</b>你能尽量减少完成的操作次数吗？</p>


    
## 解题方法一：指针标记非零位置，元素全覆盖

一个指针loc标记非零位置，一个指针i开始遍历。

遍历指针一旦遇到非零元素，就将这个元素放到loc处。

最终将loc之后的所有元素标0。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

看loc指针不难发现，相当于给每个位置都重新赋值了一遍。

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int loc = 0;
        for (int& t : nums) {
            if (t)
                nums[loc++] = t;
        }
        while (loc < nums.size())
            nums[loc++] = 0;
    }
};
```

## 解题方法二：指针标记非零位置，交换元素

和方法一类似，不同之处在于不是只赋值$nums[loc]$为非零元素，而是同时将$nuns[i]$赋值为$0$。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

但是这样可能会“在开头连续非零的地方自己换自己”。（全非零数组直接每个元素和自身交换了一次）

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int loc0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                swap(nums[i], nums[loc0++]);
            }
        }
    }
};
```

## 解题方法三：快慢指针

使用慢指针l指向第一个零的位置，使用快指r针从l开始指向第一个非零位置，交换这两个位置。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

无多余交换，但写得不如前两种方法优雅/简洁。

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int l = 0, r = 0; r < nums.size(); l++) {
            while (l < nums.size() && nums[l]) {  // 到第一个0
                l++;
            }
            if (l == nums.size()) {
                break;
            }
            r = l + 1;
            while (r < nums.size() && !nums[r]) {  // 到第一个非零
                r++;
            }
            if (r == nums.size()) {
                break;
            }
            swap(nums[l], nums[r]);
        }
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146055908)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/05/LeetCode%200283.%E7%A7%BB%E5%8A%A8%E9%9B%B6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
