---
title: 868.二进制间距：位运算
date: 2026-02-22 10:05:37
tags: [题解, LeetCode, 简单, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】868.二进制间距：位运算

力扣题目链接：[https://leetcode.cn/problems/binary-gap/](https://leetcode.cn/problems/binary-gap/)

<p>给定一个正整数 <code>n</code>，找到并返回 <code>n</code> 的二进制表示中两个 <strong>相邻</strong> 1 之间的<strong> 最长距离 </strong>。如果不存在两个相邻的 1，返回 <code>0</code> 。</p>

<p>如果只有 <code>0</code> 将两个 <code>1</code> 分隔开（可能不存在 <code>0</code> ），则认为这两个 1 彼此 <strong>相邻</strong> 。两个 <code>1</code> 之间的距离是它们的二进制表示中位置的绝对差。例如，<code>"1001"</code> 中的两个 <code>1</code> 的距离为 3 。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 22
<strong>输出：</strong>2
<strong>解释：</strong>22 的二进制是 "10110" 。
在 22 的二进制表示中，有三个 1，组成两对相邻的 1 。
第一对相邻的 1 中，两个 1 之间的距离为 2 。
第二对相邻的 1 中，两个 1 之间的距离为 1 。
答案取两个距离之中最大的，也就是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>0
<strong>解释：</strong>8 的二进制是 "1000" 。
在 8 的二进制表示中没有相邻的两个 1，所以返回 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>2
<strong>解释：</strong>5 的二进制是 "101" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：位运算

以样例一的二进制`n = 10110`为例，我们只需要在`n`非零时使用一个变量`cnt`记录遇到下一个1之前一共有几位就好了，再次遇到`1`时更新答案最大值并重置`cnt`。

```cpp
while (n) {
    if (n & 1) {
        ans = max(ans, cnt);
        cnt = 0;
    }
    cnt++;
    n >>= 1;  // Don't forget
}
```

但是问题在于如何得到第一个`1`的位置，很简单，可以借助[`lowbit`](https://web.letmefly.xyz/Notes/ACM/Template/lowbit.html)的思想，`n & -n`得到最低位的`1`及后面的`0`（`lowbit(10110) = 10`）令`n / lowbit(n)`即相当于抹掉了低位的所有`0`，`n / lowbit(n) >> 1`相当于抹掉了最低位的`1`及其右边的所有`0`（`10110 / lowbit(10110) >> 1 = 101`），这样就找到最低位`1`的位置了。

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-22 10:04:00
 */
class Solution {
public:
    int binaryGap(int n) {
        n /= (n & -n) * 2;
        int ans = 0, cnt = 1;
        while (n) {
            if (n & 1) {
                ans = max(ans, cnt);
                cnt = 0;
            }
            cnt++;
            n >>= 1;  // Don't forget
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158283908)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/22/LeetCode%200868.%E4%BA%8C%E8%BF%9B%E5%88%B6%E9%97%B4%E8%B7%9D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
