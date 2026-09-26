---
title: 3637.三段式数组 I：一次遍历（三种实现）
date: 2026-02-04 22:06:33
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3637.三段式数组 I：一次遍历（三种实现）

力扣题目链接：[https://leetcode.cn/problems/trionic-array-i/](https://leetcode.cn/problems/trionic-array-i/)

<p data-end="128" data-start="0">给你一个长度为 <code data-end="51" data-start="48">n</code> 的整数数组 <code data-end="37" data-start="31">nums</code>。</p>

<p data-end="128" data-start="0">如果存在索引 <code data-end="117" data-start="100">0 &lt; p &lt; q &lt; n − 1</code>，使得数组满足以下条件，则称其为 <strong data-end="76" data-start="65">三段式数组（trionic）</strong>：</p>

<ul>
	<li data-end="170" data-start="132"><code data-end="144" data-start="132">nums[0...p]</code>&nbsp;<strong>严格</strong> 递增，</li>
	<li data-end="211" data-start="173"><code data-end="185" data-start="173">nums[p...q]</code>&nbsp;<strong>严格</strong> 递减，</li>
	<li data-end="252" data-start="214"><code data-end="228" data-start="214">nums[q...n − 1]</code>&nbsp;<strong>严格</strong> 递增。</li>
</ul>

<p data-end="315" data-is-last-node="" data-is-only-node="" data-start="254">如果 <code data-end="277" data-start="271">nums</code> 是三段式数组，返回 <code data-end="267" data-start="261">true</code>；否则，返回 <code data-end="314" data-start="307">false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">nums = [1,3,5,4,2,6]</span></p>

<p><strong>输出:</strong> <span class="example-io">true</span></p>

<p><strong>解释:</strong></p>

<p>选择 <code data-end="91" data-start="84">p = 2</code>, <code data-end="100" data-start="93">q = 4</code>：</p>

<ul>
	<li><code data-end="130" data-start="108">nums[0...2] = [1, 3, 5]</code> 严格递增&nbsp;(<code data-end="166" data-start="155">1 &lt; 3 &lt; 5</code>)。</li>
	<li><code data-end="197" data-start="175">nums[2...4] = [5, 4, 2]</code> 严格递减&nbsp;(<code data-end="233" data-start="222">5 &gt; 4 &gt; 2</code>)。</li>
	<li><code data-end="262" data-start="242">nums[4...5] = [2, 6]</code> 严格递增&nbsp;(<code data-end="294" data-start="287">2 &lt; 6</code>)。</li>
</ul>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">nums = [2,1,3]</span></p>

<p><strong>输出:</strong> <span class="example-io">false</span></p>

<p><strong>解释:</strong></p>

<p>无法选出能使数组满足三段式要求的&nbsp;<code>p</code> 和 <code>q</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li data-end="41" data-start="26"><code data-end="39" data-start="26">3 &lt;= n &lt;= 100</code></li>
	<li data-end="70" data-start="44"><code data-end="70" data-start="44">-1000 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：遍历

使用一个状态$state$分别代表正在处于三个数组的那一段。

### 方法一：if-else

+ 如果`之前处于第1段数组`且`当前元素比上一个小`，则跳转到第2段数组；
+ 如果`之前处于第2段数组`且`当前元素比上一个大`，则跳转到第3段数组；
+ 如果`之前处于第3段数组`且`当前元素比上一个小`，则返回`false`。

最终如果处于第三段数组则返回`true`。

### 方法二：累加$state$

只要发生数组跳跃，就一定是”当前元素比上个`小`且上个元素比上上个`大`” 或 “当前元素比上个`大`且上个元素比上上个`小`”，总之就是数组由增变减或由减变增，此时$state+1$。

最终如果处于第三段数组则返回`true`。

### What's more

1. 记得特判$nums[1]$和$nums[0]$的大小
2. 数组中不得出现相邻且相等的元素，记得特判

### 时空复杂度分析

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++ - 方法一

```cpp
/*
 * @LastEditTime: 2026-02-04 21:56:05
 */
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        if (nums[1] <= nums[0]) {
            return false;
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return false;
            }
            if (state == 0) {
                if (nums[i] < nums[i - 1]) {
                    state = 1;
                }
            } else if (state == 1) {
                if (nums[i] > nums[i - 1]) {
                    state = 2;
                }
            } else if (state == 2) {
                if (nums[i] < nums[i - 1]) {
                    return false;
                }
            }
        }
        return state == 2;
    }
};
```

#### C++ - 方法一+if合并版

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2026-02-04 21:57:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-02-04 21:58:07
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        if (nums[1] <= nums[0]) {
            return false;
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return false;
            }
            if (state == 0 && nums[i] < nums[i - 1]) {
                state = 1;
            } else if (state == 1 && nums[i] > nums[i - 1]) {
                state = 2;
            } else if (state == 2 && nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return state == 2;
    }
};
```

#### C++ - 方法二

```cpp
/*
 * @LastEditTime: 2026-02-04 22:02:00
 */
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        if (nums[1] <= nums[0]) {
            return false;
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return false;
            }
            if ((nums[i] > nums[i - 1]) != (nums[i - 1] > nums[i - 2])) {
                state++;
                if (state > 2) {
                    return false;
                }
            }
        }
        return state == 2;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157738457)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/04/LeetCode%203637.%E4%B8%89%E6%AE%B5%E5%BC%8F%E6%95%B0%E7%BB%84I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
