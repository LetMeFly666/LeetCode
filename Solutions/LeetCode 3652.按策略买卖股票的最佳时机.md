---
title: 3652.按策略买卖股票的最佳时机：滑动窗口
date: 2025-12-18 18:45:15
tags: [题解, LeetCode, 中等, 数组, 前缀和, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】3652.按策略买卖股票的最佳时机：滑动窗口

力扣题目链接：[https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-using-strategy/](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-using-strategy/)

<p>给你两个整数数组 <code>prices</code> 和 <code>strategy</code>，其中：</p>

<ul>
	<li><code>prices[i]</code> 表示第 <code>i</code> 天某股票的价格。</li>
	<li><code>strategy[i]</code> 表示第 <code>i</code> 天的交易策略，其中：
	<ul>
		<li><code>-1</code> 表示买入一单位股票。</li>
		<li><code>0</code> 表示持有股票。</li>
		<li><code>1</code> 表示卖出一单位股票。</li>
	</ul>
	</li>
</ul>

<p>同时给你一个&nbsp;<strong>偶数&nbsp;</strong>整数 <code>k</code>，你可以对 <code>strategy</code> 进行&nbsp;<strong>最多一次&nbsp;</strong>修改。一次修改包括：</p>

<ul>
	<li>选择 <code>strategy</code> 中恰好 <code>k</code> 个&nbsp;<strong>连续&nbsp;</strong>元素。</li>
	<li>将前 <code>k / 2</code> 个元素设为 <code>0</code>（持有）。</li>
	<li>将后 <code>k / 2</code> 个元素设为 <code>1</code>（卖出）。</li>
</ul>

<p><strong>利润&nbsp;</strong>定义为所有天数中 <code>strategy[i] * prices[i]</code> 的&nbsp;<strong>总和&nbsp;</strong>。</p>

<p>返回你可以获得的&nbsp;<strong>最大&nbsp;</strong>可能利润。</p>

<p><strong>注意：</strong> 没有预算或股票持有数量的限制，因此所有买入和卖出操作均可行，无需考虑过去的操作。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">prices = [4,2,8], strategy = [-1,0,1], k = 2</span></p>

<p><strong>输出：</strong> <span class="example-io">10</span></p>

<p><strong>解释：</strong></p>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">修改</th>
			<th style="border: 1px solid black;">策略</th>
			<th style="border: 1px solid black;">利润计算</th>
			<th style="border: 1px solid black;">利润</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">原始</td>
			<td style="border: 1px solid black;">[-1, 0, 1]</td>
			<td style="border: 1px solid black;">(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8</td>
			<td style="border: 1px solid black;">4</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">修改 [0, 1]</td>
			<td style="border: 1px solid black;">[0, 1, 1]</td>
			<td style="border: 1px solid black;">(0 × 4) + (1 × 2) + (1 × 8) = 0 + 2 + 8</td>
			<td style="border: 1px solid black;">10</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">修改 [1, 2]</td>
			<td style="border: 1px solid black;">[-1, 0, 1]</td>
			<td style="border: 1px solid black;">(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8</td>
			<td style="border: 1px solid black;">4</td>
		</tr>
	</tbody>
</table>

<p>因此，最大可能利润是 10，通过修改子数组 <code>[0, 1]</code> 实现。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">prices = [5,4,3], strategy = [1,1,0], k = 2</span></p>

<p><strong>输出：</strong> <span class="example-io">9</span></p>

<p><strong>解释：</strong></p>

<div class="example-block">
<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;">修改</th>
			<th style="border: 1px solid black;">策略</th>
			<th style="border: 1px solid black;">利润计算</th>
			<th style="border: 1px solid black;">利润</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">原始</td>
			<td style="border: 1px solid black;">[1, 1, 0]</td>
			<td style="border: 1px solid black;">(1 × 5) + (1 × 4) + (0 × 3) = 5 + 4 + 0</td>
			<td style="border: 1px solid black;">9</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">修改 [0, 1]</td>
			<td style="border: 1px solid black;">[0, 1, 0]</td>
			<td style="border: 1px solid black;">(0 × 5) + (1 × 4) + (0 × 3) = 0 + 4 + 0</td>
			<td style="border: 1px solid black;">4</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">修改 [1, 2]</td>
			<td style="border: 1px solid black;">[1, 0, 1]</td>
			<td style="border: 1px solid black;">(1 × 5) + (0 × 4) + (1 × 3) = 5 + 0 + 3</td>
			<td style="border: 1px solid black;">8</td>
		</tr>
	</tbody>
</table>

<p>因此，最大可能利润是 9，无需任何修改即可达成。</p>
</div>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= prices.length == strategy.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= strategy[i] &lt;= 1</code></li>
	<li><code>2 &lt;= k &lt;= prices.length</code></li>
	<li><code>k</code> 是偶数</li>
</ul>


    
## 解题方法：滑动窗口

既然修改范围是定长的，并且最多修改1次，那么就从前往后将每一种修改可能都试试呗。

初始先计算原数组不修改时收益，再从前往后依次尝试修改区间，取收益最大的一个作为答案。

如何从一个区间快速计算出下一个区间呢？变化的有3个：（变化前的）区间起点、区间中点、区间终点，把这三个位置的值更新一下就好了。

+ 时间复杂度$O(len(prices))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-18 18:42:50
 */
typedef long long ll;
class Solution {
public:
    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll ans = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            ans += strategy[i] * prices[i];
        }

        ll now = ans;
        for (int i = 0; i < k / 2; i++) {
            now += (0 - strategy[i]) * prices[i];
        }
        for (int i = k / 2; i < k; i++) {
            now += (1 - strategy[i]) * prices[i];
        }
        ans = max(ans, now);

        for (int i = 1; i + k <= n; i++) {
            // i-1: 0->original
            // i+k/2-1: 1->0
            // i+k-1: original->1
            now += (strategy[i - 1] - 0) * prices[i - 1] + (0 - 1) * prices[i + k/2 - 1] + (1 - strategy[i + k - 1]) * prices[i + k - 1];
            ans = max(ans, now);
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156061117)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/18/LeetCode%203652.%E6%8C%89%E7%AD%96%E7%95%A5%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
