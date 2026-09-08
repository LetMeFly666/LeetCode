---
title: 3870.统计范围内的逗号：模拟 或 一步计算
date: 2026-09-08 12:39:35
tags: [题解, LeetCode, 简单, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3870.统计范围内的逗号：模拟 或 一步计算

力扣题目链接：[https://leetcode.cn/problems/count-commas-in-range/](https://leetcode.cn/problems/count-commas-in-range/)

<p>给你一个整数 <code>n</code>。</p>

<p>返回将所有从 <code>[1, n]</code>（包含两端）范围内的整数以&nbsp;<strong>标准&nbsp;</strong>数字格式书写时所用到的<strong>&nbsp;逗号总数</strong>。</p>

<p>在<strong>&nbsp;标准&nbsp;</strong>格式中：</p>

<ul>
	<li>从右边开始，每&nbsp;<strong>三位&nbsp;</strong>数字后插入一个逗号。</li>
	<li>位数&nbsp;<strong>少于四位&nbsp;</strong>的数字不包含逗号。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 1002</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>数字 <code>"1,000"</code>、<code>"1,001"</code> 和 <code>"1,002"</code> 每个都包含一个逗号，总计 3 个逗号。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 998</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>从 1 到 998 的所有数字位数都少于四位，因此没有使用逗号。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法一：模拟

从$1000$到$n$模拟，计算每个数字十进制下的位数（当数字非零时候不断除以$10$并向下取整），则逗号数量为$\frac{位数-1}{3}$。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-08 12:36:37
 */
class Solution {
private:
    int cal(int n) {
        int len = 0;
        while (n) {
            len++;
            n /= 10;
        }
        return (len - 1) / 3;
    }
public:
    int countCommas(int n) {
        int ans = 0;
        for (int i = 1000; i <= n; i++) {
            ans += cal(i);
        }
        return ans;
    }
};
```

## 解题方法二：一步计算

不难发现题目的数据范围是$1\leq n\leq 10^5$，而$1\leq n\leq 999$的数字没有逗号，$1000\leq n\leq 10^5$的数字每个数字有一个逗号，所以直接返回$999$到$n$的数字个数即可。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-08 12:38:43
 */
class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 999);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/164601089)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/08/LeetCode%203870.%E7%BB%9F%E8%AE%A1%E8%8C%83%E5%9B%B4%E5%86%85%E7%9A%84%E9%80%97%E5%8F%B7/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
