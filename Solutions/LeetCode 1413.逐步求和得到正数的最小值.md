---
title: 1413.逐步求和得到正数的最小值
date: 2022-08-09 09:44:59
tags: [题解, LeetCode, 简单, 数组, 前缀和, 模拟]
---

# 【LetMeFly】1413.逐步求和得到正数的最小值

力扣题目链接：[https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/](https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/)

<p>给你一个整数数组 <code>nums</code>&nbsp;。你可以选定任意的&nbsp;<strong>正数</strong> startValue 作为初始值。</p>

<p>你需要从左到右遍历 <code>nums</code>&nbsp;数组，并将 startValue 依次累加上&nbsp;<code>nums</code>&nbsp;数组中的值。</p>

<p>请你在确保累加和始终大于等于 1 的前提下，选出一个最小的&nbsp;<strong>正数</strong>&nbsp;作为 startValue 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [-3,2,-3,4,2]
<strong>输出：</strong>5
<strong>解释：</strong>如果你选择 startValue = 4，在第三次累加时，和小于 1 。
<strong>                累加求和
&nbsp;               startValue = 4 | startValue = 5 | nums
</strong>&nbsp;                 (4 <strong>-3</strong> ) = 1  | (5 <strong>-3</strong> ) = 2    |  -3
&nbsp;                 (1 <strong>+2</strong> ) = 3  | (2 <strong>+2</strong> ) = 4    |   2
&nbsp;                 (3 <strong>-3</strong> ) = 0  | (4 <strong>-3</strong> ) = 1    |  -3
&nbsp;                 (0 <strong>+4</strong> ) = 4  | (1 <strong>+4</strong> ) = 5    |   4
&nbsp;                 (4 <strong>+2</strong> ) = 6  | (5 <strong>+2</strong> ) = 7    |   2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2]
<strong>输出：</strong>1
<strong>解释：</strong>最小的 startValue 需要是正数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-2,-3]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 方法一：模拟

从前到后遍历数组，并求和。

> 如果当前这一步和为```-4```，那么就说明初始值至少是```5```（$5 = -4 + 1$）

因此，遍历过程中，不断更新初始值的最小值即可。

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1;
        int cnt = 0;
        for (int& t : nums) {
            cnt += t;
            ans = max(ans, -cnt + 1);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/09/LeetCode%201413.%E9%80%90%E6%AD%A5%E6%B1%82%E5%92%8C%E5%BE%97%E5%88%B0%E6%AD%A3%E6%95%B0%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126241399](https://letmefly.blog.csdn.net/article/details/126241399)
