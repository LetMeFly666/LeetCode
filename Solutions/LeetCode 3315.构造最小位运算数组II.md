---
title: 3315.构造最小位运算数组 II：位运算
date: 2026-01-21 23:42:06
tags: [题解, LeetCode, 中等, 位运算, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】3315.构造最小位运算数组 II：位运算

力扣题目链接：[https://leetcode.cn/problems/construct-the-minimum-bitwise-array-ii/](https://leetcode.cn/problems/construct-the-minimum-bitwise-array-ii/)

<p>给你一个长度为 <code>n</code>&nbsp;的<span data-keyword="prime">质数</span>数组&nbsp;<code>nums</code>&nbsp;。你的任务是返回一个长度为 <code>n</code>&nbsp;的数组 <code>ans</code>&nbsp;，对于每个下标 <code>i</code>&nbsp;，以下<strong>&nbsp;条件</strong>&nbsp;均成立：</p>

<ul>
	<li><code>ans[i] OR (ans[i] + 1) == nums[i]</code></li>
</ul>

<p>除此以外，你需要 <strong>最小化</strong>&nbsp;结果数组里每一个&nbsp;<code>ans[i]</code>&nbsp;。</p>

<p>如果没法找到符合 <strong>条件</strong>&nbsp;的&nbsp;<code>ans[i]</code>&nbsp;，那么&nbsp;<code>ans[i] = -1</code>&nbsp;。</p>

<p><strong>质数</strong>&nbsp;指的是一个大于 1 的自然数，且它只有 1 和自己两个因数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,3,5,7]</span></p>

<p><span class="example-io"><b>输出：</b>[-1,1,4,3]</span></p>

<p><b>解释：</b></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;，不存在&nbsp;<code>ans[0]</code>&nbsp;满足&nbsp;<code>ans[0] OR (ans[0] + 1) = 2</code>&nbsp;，所以&nbsp;<code>ans[0] = -1</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 1</code>&nbsp;，满足 <code>ans[1] OR (ans[1] + 1) = 3</code>&nbsp;的最小&nbsp;<code>ans[1]</code>&nbsp;为&nbsp;<code>1</code>&nbsp;，因为&nbsp;<code>1 OR (1 + 1) = 3</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 2</code>&nbsp;，满足 <code>ans[2] OR (ans[2] + 1) = 5</code>&nbsp;的最小 <code>ans[2]</code>&nbsp;为&nbsp;<code>4</code>&nbsp;，因为&nbsp;<code>4 OR (4 + 1) = 5</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 3</code>&nbsp;，满足&nbsp;<code>ans[3] OR (ans[3] + 1) = 7</code>&nbsp;的最小&nbsp;<code>ans[3]</code>&nbsp;为&nbsp;<code>3</code>&nbsp;，因为&nbsp;<code>3 OR (3 + 1) = 7</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [11,13,31]</span></p>

<p><span class="example-io"><b>输出：</b>[9,12,15]</span></p>

<p><b>解释：</b></p>

<ul>
	<li>对于&nbsp;<code>i = 0</code>&nbsp;，满足&nbsp;<code>ans[0] OR (ans[0] + 1) = 11</code> 的最小&nbsp;<code>ans[0]</code>&nbsp;为&nbsp;<code>9</code>&nbsp;，因为&nbsp;<code>9 OR (9 + 1) = 11</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 1</code>&nbsp;，满足&nbsp;<code>ans[1] OR (ans[1] + 1) = 13</code>&nbsp;的最小&nbsp;<code>ans[1]</code>&nbsp;为&nbsp;<code>12</code>&nbsp;，因为&nbsp;<code>12 OR (12 + 1) = 13</code>&nbsp;。</li>
	<li>对于&nbsp;<code>i = 2</code>&nbsp;，满足&nbsp;<code>ans[2] OR (ans[2] + 1) = 31</code>&nbsp;的最小&nbsp;<code>ans[2]</code>&nbsp;为&nbsp;<code>15</code>&nbsp;，因为&nbsp;<code>15 OR (15 + 1) = 31</code>&nbsp;。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>2 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums[i]</code>&nbsp;是一个质数。</li>
</ul>


    
## 解题方法：位运算

### 解题思路

假设一个数的二进制是`10111`，那么最小的$ans$是多少？

想让$ans$尽可能小，就要$ans$高位尽可能小。

$ans$对应的`10111`最高位的`1`有可能是`0`吗（$ans$为`0xxxx`）？

> 不可能。
>
> 如果$ans$为`0xxxx`，那么$ans+1$就要为`1xxxx`，那么$ans$就要为`01xxx`，那么$ans\ \text{or}\ (ans+1)$一定是`11xxx`不可能是`10xxx`。

所以$ans$一定为`1xxxx`。

$ans$对应的`10111`第二高位的`1`有可能是`0`吗（$ans$为`100xx`）？

> 有可能。
>
> $ans$为`10011`就好。此时$ans+1$为`10100`，它们或的结果正好是`10111`。

不难发现，最终结果二进制低位是连续的`111`，此时$ans$可以为`011`，$ans+1$为`100`，或起来正好是`111`。

$ans$不能再小了，否则两个$0$，怎么或也或不回都是$1$了。

此外，如果$n$是偶数，则不存在$ans$（因为$ans$或$ans+1$一定为奇数），返回$-1$。

### 具体做法

讨论奇数情况：

使用一个变量$now=1$不断与$n$与，结果非零就令$n$左移一位，最终结果为$0$就得到了$n$最高位连续$1$的高一位。

$n$异或（或者减去）右移一位的$now$即为答案。

### 时空复杂度分析

+ 时间复杂度$O(len(nums)\times\log nums[i])$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-21 23:39:44
 */
/*
111
11 | 100

10111 (1+2+4+16=23)
10011 | 10100   (10011:1+2+16=19)

101
100 | 101

110
101 | 110 X

10
1 | 10 X
*/
class Solution {
private:
    int get(int n) {
        if (!(n & 1)) {
            return -1;
        }
        int now = 1;
        while (n & now) {
            now <<= 1;
            // printf("now = %d\n", now);
        }
        return n ^ (now >> 1);
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = get(nums[i]);  // 是nums[i]!!! 刚开始又写成i了
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157225057)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/21/LeetCode%203315.%E6%9E%84%E9%80%A0%E6%9C%80%E5%B0%8F%E4%BD%8D%E8%BF%90%E7%AE%97%E6%95%B0%E7%BB%84II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
