---
title: 3101.交替子数组计数
date: 2024-07-06 10:54:38
tags: [题解, LeetCode, 中等, 数组, 数学]
---

# 【LetMeFly】3101.交替子数组计数：等差数列求和（较详题解）

力扣题目链接：[https://leetcode.cn/problems/count-alternating-subarrays/](https://leetcode.cn/problems/count-alternating-subarrays/)

<p>给你一个<span data-keyword="binary-array">二进制数组 </span><code>nums</code> 。</p>

<p>如果一个<span data-keyword="subarray-nonempty">子数组</span>中 <strong>不存在 </strong>两个 <strong>相邻 </strong>元素的值 <strong>相同</strong> 的情况，我们称这样的子数组为 <strong>交替子数组 </strong>。</p>

<p>返回数组 <code>nums</code> 中交替子数组的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,1,1,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>
<!-- 解释示例1的交替子数组 -->

<p>以下子数组是交替子数组：<code>[0]</code> 、<code>[1]</code> 、<code>[1]</code> 、<code>[1]</code> 以及 <code>[0,1]</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,0,1,0]</span></p>

<p><strong>输出：</strong> <span class="example-io">10</span></p>

<p><strong>解释：</strong></p>
<!-- 解释示例2的交替子数组 -->

<p>数组的每个子数组都是交替子数组。可以统计在内的子数组共有 10 个。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 不是 <code>0</code> 就是 <code>1</code> 。</li>
</ul>


    
## 解题方法：等差数列求和

首先需要能看懂：

1. 若相邻两个元素不相同，则这两个元素必定不能在一个`交替子数组`中。
2. 若从`l`到`r`的相邻元素都不同，则`l`到`r`的任一子数组都是`交替子数组`。

因此任务明确了。只需要将原始数组划分为若干个`最长交替子数组`的集合：

> 例如数组`[0, 1, 0, 0, 0, 1]`是由三个`最长交替子数组`组成，
>
> `[0, 1, 0, 0, 0, 1] = [0, 1, 0] + [0] + [0, 1]`。

这样就只剩下最后一个问题：对于长度为`length`的`(最长交替子)数组`，一共有多少个子数组呢？

> 例如对于长度为4的数组`[0, 1, 0, 1]`，其下标为`[0, 1, 2, 3]`，其子数组分别为：
>
> + 从`0`到`0`、从`0`到`1`、从`0`到`2`、从`0`到`3`，共计`4`个；
> + 从`1`到`1`、从`1`到`2`、从`1`到`3`，共计`3`个；
> + 从`2`到`2`、从`2`到`3`，共计`2`个；
> + 从`3`到`3`，共计`1`个。
>
> 子数组个数总计`1 + 2 + 3 + 4`个。
>
> 长度为`length`的数组一共有$1+2+\cdots+length=\frac{(1 + length) \times length}{2}$个子数组。

至此，问题解决。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/06/LeetCode%203101.%E4%BA%A4%E6%9B%BF%E5%AD%90%E6%95%B0%E7%BB%84%E8%AE%A1%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140226055](https://letmefly.blog.csdn.net/article/details/140226055)
