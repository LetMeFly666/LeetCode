---
title: 1833.雪糕的最大数量：桶排序
date: 2026-06-21 09:31:40
tags: [题解, LeetCode, 中等, 贪心, 数组, 计数排序, 排序, 桶排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1833.雪糕的最大数量：桶排序

力扣题目链接：[https://leetcode.cn/problems/maximum-ice-cream-bars/](https://leetcode.cn/problems/maximum-ice-cream-bars/)

<p>夏日炎炎，小男孩 Tony 想买一些雪糕消消暑。</p>

<p>商店中新到 <code>n</code> 支雪糕，用长度为 <code>n</code> 的数组 <code>costs</code> 表示雪糕的定价，其中 <code>costs[i]</code> 表示第 <code>i</code> 支雪糕的现金价格。Tony 一共有 <code>coins</code> 现金可以用于消费，他想要买尽可能多的雪糕。</p>

<p><strong>注意：</strong>Tony 可以按任意顺序购买雪糕。</p>

<p>给你价格数组 <code>costs</code> 和现金量 <code>coins</code> ，请你计算并返回 Tony 用 <code>coins</code> 现金能够买到的雪糕的 <strong>最大数量</strong> 。</p>

<p>你必须使用计数排序解决此问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>costs = [1,3,2,4,1], coins = 7
<strong>输出：</strong>4
<strong>解释：</strong>Tony 可以买下标为 0、1、2、4 的雪糕，总价为 1 + 3 + 2 + 1 = 7
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>costs = [10,6,8,7,7,8], coins = 5
<strong>输出：</strong>0
<strong>解释：</strong>Tony 没有足够的钱买任何一支雪糕。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>costs = [1,6,3,1,2,5], coins = 20
<strong>输出：</strong>6
<strong>解释：</strong>Tony 可以买下所有的雪糕，总价为 1 + 6 + 3 + 1 + 2 + 5 = 18 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>costs.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= costs[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= coins &lt;= 10<sup>8</sup></code></li>
</ul>


    
## 解题方法：桶排序

这道题思路很简单，就是尽可能买便宜的雪糕。主要是题目中还有这么一句“你必须使用计数排序解决此问题”，好，那就使用桶排序来解决吧。

数据范围$1\leq costs[i]\leq 10^5$，所以开辟一个长度为$100001$的数组$bin$就好，其中$bin[i]$代表价格为$i$的雪糕的出现次数。

**初始化bin数组中每个元素为0** ，遍历价格数组，假设出现了价格为$t$的雪糕，就令$bin[t]$加一。

得到桶排序数组后，从$1$到$10^5$遍历$bin$桶，当剩余金币小于当前雪糕价格时结束遍历。

对于价格为$t$的雪糕（共有$bin[t]$个），剩余金币为$coins$时，一共可以购买$\min(bin[t], \lfloor\frac{coins}{t}\rfloor)$个。

+ 时间复杂度$O(n+\max{coins[i]})$
+ 空间复杂度$O(\max{coins[i]})$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-21 09:30:30
 */
#define MAX 100000
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int bin[MAX + 1] = {0};
        for (int t : costs) {
            bin[t]++;
        }

        int ans = 0;
        for (int i = 1; i <= MAX && coins >= i; i++) {
            int num = min(coins / i, bin[i]);
            ans += num;
            coins -= i * num;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162163772)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/21/LeetCode%201833.%E9%9B%AA%E7%B3%95%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E9%87%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
