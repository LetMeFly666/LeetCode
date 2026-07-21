---
title: 3499.操作后最大活跃区段数 I：一次遍历(脑筋急转弯)
date: 2026-07-21 09:49:59
tags: [题解, LeetCode, 中等, 字符串, 枚举, 脑筋急转弯, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3499.操作后最大活跃区段数 I：一次遍历(脑筋急转弯)

力扣题目链接：[https://leetcode.cn/problems/maximize-active-section-with-trade-i/](https://leetcode.cn/problems/maximize-active-section-with-trade-i/)

<p>给你一个长度为 <code>n</code> 的二进制字符串 <code>s</code>，其中：</p>

<ul>
	<li><code>'1'</code> 表示一个 <strong>活跃</strong> 区段。</li>
	<li><code>'0'</code> 表示一个 <strong>非活跃</strong> 区段。</li>
</ul>

<p>你可以执行 <strong>最多一次操作</strong>&nbsp;来最大化 <code>s</code> 中的活跃区段数量。在一次操作中，你可以：</p>

<ul>
	<li>将一个被 <code>'0'</code> 包围的连续 <code>'1'</code> 区块转换为全 <code>'0'</code>。</li>
	<li>然后，将一个被 <code>'1'</code> 包围的连续 <code>'0'</code> 区块转换为全 <code>'1'</code>。</li>
</ul>

<p>返回在执行最优操作后，<code>s</code> 中的 <strong>最大</strong> 活跃区段数。</p>

<p><strong>注意：</strong>处理时需要在 <code>s</code> 的两侧加上 <code>'1'</code> ，即 <code>t = '1' + s + '1'</code>。这些加上的 <code>'1'</code> 不会影响最终的计数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "01"</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>因为没有被 <code>'0'</code> 包围的 <code>'1'</code> 区块，因此无法进行有效操作。最大活跃区段数为 1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "0100"</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>字符串 <code>"0100"</code> → 两端加上 <code>'1'</code>&nbsp;后得到&nbsp;<code>"101001"</code>&nbsp;。</li>
	<li>选择 <code>"0100"</code>，<code>"10<u><strong>1</strong></u>001"</code> → <code>"1<u><strong>0000</strong></u>1"</code> → <code>"1<u><strong>1111</strong></u>1"</code>&nbsp;。</li>
	<li>最终的字符串去掉两端的 <code>'1'</code>&nbsp;后为 <code>"1111"</code>&nbsp;。最大活跃区段数为 4。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "1000100"</span></p>

<p><strong>输出：</strong> <span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>字符串 <code>"1000100"</code> → 两端加上 <code>'1'</code>&nbsp;后得到 <code>"110001001"</code>&nbsp;。</li>
	<li>选择 <code>"000100"</code>，<code>"11000<u><strong>1</strong></u>001"</code> → <code>"11<u><strong>000000</strong></u>1"</code> → <code>"11<u><strong>111111</strong></u>1"</code>。</li>
	<li>最终的字符串去掉两端的 <code>'1'</code>&nbsp;后为 <code>"1111111"</code>。最大活跃区段数为 7。</li>
</ul>
</div>

<p><strong class="example">示例 4：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "01010"</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>字符串 <code>"01010"</code> → 两端加上 <code>'1'</code>&nbsp;后得到 <code>"1010101"</code>。</li>
	<li>选择 <code>"010"</code>，<code>"10<u><strong>1</strong></u>0101"</code> → <code>"1<u><strong>000</strong></u>101"</code> → <code>"1<u><strong>111</strong></u>101"</code>。</li>
	<li>最终的字符串去掉两端的 <code>'1'</code>&nbsp;后为 <code>"11110"</code>。最大活跃区段数为 4。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 仅包含 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


    
## 解题思路：脑筋急转弯

最终求的是`1`的个数而非连续`1`的个数，所以我们的目的是把尽可能多的`0`变成`1`。

首先可以把一段`1`变成`0`，这个操作的**唯一意义**就是把原本不相连的两段`0`连接起来，然后下一步一起变成`1`。

所以其实这道题最终是把相邻的两段`0`变成`1`，然后返回`1`的个数。也相当于返回原始`1`的个数加上相邻两段`0`中`0`的个数。

## 解题方法：一次遍历

回忆一下我们都需要哪些值：

1. 字符串中原始`1`的个数，这个可以由一个变量$cnt1$在一次遍历后得出。
2. 字符串中当前*区段*共计遍历到了多少个`0`，这个可以由一个变量$now_cnt0$在遍历过程中维护。当前字符是`0`的话$now_cnt0+1$；当前字符是刚刚由`0`转`1`的话，$now_cnt0$置$0$。
3. 字符串上一个连续`0`的个数，这个可以由一个变量$last_cnt0$来维护，初始值为无穷小。
4. 字符串最大两个连续`0`的个数，这个可以由一个变量$max0$来更新。

这样，我们就可以开始遍历字符串：

+ 如果当前元素是`0`，则$now_cnt0+1$；
+ 如果当前原始是刚刚由`0`变成了`1`，则更新$max0$、$last_cnt0$、$now_cnt0$。

## 时空复杂度分析

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

## AC代码

### C++

```cpp
/*
 * @LastEditTime: 2026-07-21 09:48:29
 */
class Solution {
public:
    int maxActiveSectionsAfterTrade(string& s) {
        int cnt1 = 0, max0 = -1000000;
        for (int last_cnt0 = -1000000, now_cnt0 = 0, i = 0, n = s.size(); i <= n; i++) {
            if (i < n && s[i] == '0') {
                now_cnt0++;
            } else if (i && s[i - 1] == '0') {  // 0->1
                max0 = max(max0, last_cnt0 + now_cnt0);
                last_cnt0 = now_cnt0;
                now_cnt0 = 0;
            }
            cnt1 += i < n && s[i] == '1';
        }
        return cnt1 + max(max0, 0);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163067749)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/21/LeetCode%203499.%E6%93%8D%E4%BD%9C%E5%90%8E%E6%9C%80%E5%A4%A7%E6%B4%BB%E8%B7%83%E5%8C%BA%E6%AE%B5%E6%95%B0I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
