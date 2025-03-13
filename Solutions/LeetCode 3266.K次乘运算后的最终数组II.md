---
title: 3266.K 次乘运算后的最终数组 II
date: 2024-12-14 17:45:56
tags: [题解, LeetCode, 困难, 数组, 模拟, 堆（优先队列）, 快速幂]
categories: [题解, LeetCode]
---

# 【LetMeFly】3266.K 次乘运算后的最终数组 II：堆（快速幂）

力扣题目链接：[https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-ii/](https://leetcode.cn/problems/final-array-state-after-k-multiplication-operations-ii/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，一个整数&nbsp;<code>k</code>&nbsp;&nbsp;和一个整数&nbsp;<code>multiplier</code>&nbsp;。</p>

<p>你需要对 <code>nums</code>&nbsp;执行 <code>k</code>&nbsp;次操作，每次操作中：</p>

<ul>
	<li>找到 <code>nums</code>&nbsp;中的 <strong>最小</strong>&nbsp;值&nbsp;<code>x</code>&nbsp;，如果存在多个最小值，选择最 <strong>前面</strong>&nbsp;的一个。</li>
	<li>将 <code>x</code>&nbsp;替换为&nbsp;<code>x * multiplier</code>&nbsp;。</li>
</ul>

<p><code>k</code>&nbsp;次操作以后，你需要将 <code>nums</code>&nbsp;中每一个数值对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余。</p>

<p>请你返回执行完 <code>k</code>&nbsp;次乘运算以及取余运算之后，最终的 <code>nums</code>&nbsp;数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,3,5,6], k = 5, multiplier = 2</span></p>

<p><span class="example-io"><b>输出：</b>[8,4,6,5,6]</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[2, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[4, 2, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>3 次操作后</td>
			<td>[4, 4, 3, 5, 6]</td>
		</tr>
		<tr>
			<td>4 次操作后</td>
			<td>[4, 4, 6, 5, 6]</td>
		</tr>
		<tr>
			<td>5 次操作后</td>
			<td>[8, 4, 6, 5, 6]</td>
		</tr>
		<tr>
			<td>取余操作后</td>
			<td>[8, 4, 6, 5, 6]</td>
		</tr>
	</tbody>
</table>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [100000,2000], k = 2, multiplier = 1000000</span></p>

<p><span class="example-io"><b>输出：</b>[999999307,999999993]</span></p>

<p><strong>解释：</strong></p>

<table>
	<tbody>
		<tr>
			<th>操作</th>
			<th>结果</th>
		</tr>
		<tr>
			<td>1 次操作后</td>
			<td>[100000, 2000000000]</td>
		</tr>
		<tr>
			<td>2 次操作后</td>
			<td>[100000000000, 2000000000]</td>
		</tr>
		<tr>
			<td>取余操作后</td>
			<td>[999999307, 999999993]</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= multiplier &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 解题方法：堆 + 快速幂

对于两个数$x\lt y$，如果$x\times multiplier\gt y$，那么下次选择将会是$y$，而$y\times multiplier$后又会大于$x\times multiplier$，下下次将会选择的是$x$，然后是$y$，......

也就是说，两个数较为接近后（之间的倍数小于$multiplier$），将会每个数依次被选中。

多个数也一样，假设多个数中最大的数是$M$，当$M$第一次变成最小的数时，其他所有的数都$\geq M$且$\lt M\times multiplier$。也就是说这时候所有的数都会比较接近，所有的数会像前面例子中的$x$和$y$一样依次被选中。

假设此时还剩$k$次操作，那么：

+ 前$k\% n$小的数还会被执行$\lfloor\frac{k}{n}\rfloor+1$次操作；
+ 其余数还会被执行$\lfloor\frac{k}{n}\rfloor$次操作。

对于$M$变成最小数之前的操作，我们可以使用堆或优先队列模拟进行；

对于之后的操作，可以使用[快速幂](https://letmefly.xyz/Notes/ACM/Problems/%E5%BF%AB%E9%80%9F%E5%B9%82/)来计算。

### 时空复杂度分析

+ 时间复杂度$O(n\log n\log_mM)$。单个数最多被模拟$\log_m M$次，最多模拟$n$个数，单次模拟时间复杂度$O(\log n)$。
+ 空间复杂度$O(n)$

其中$m=multiplier$，$n=len(nums)$，$M=\max(nums)$。

若$m=1$则可立即返回原数组，否则$m$至少为$2$，$M$最大为$10^9$，$n$最大为$10^4$，$\max(n\log n\log_mM)=10^4\times \log 10^4\times \log 10^9$=$10^4\times 13.288\times 29.897=3972713.36\approx4\times 10^6$

这数据范围不错。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-14 15:12:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-14 17:42:05
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

/* 
1 3 5 6
2

                  min
2 3 5 6            0
4 3 5 6            1
4 6 5 6            0
8 6 5 6            2
8 6 10 6           1
8 12 10 6          3
8 12 10 12         0
16 12 10 12        2
16 12 20 12        1
16 24 20 12        3
16 24 20 24        0
...
*/
typedef long long ll;
const ll MOD = 1e9+7;
class Solution {
private:
    ll pow(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        vector<pair<ll, int>> h;
        for (int i = 0; i < nums.size(); i++) {
            h.push_back({nums[i], i});
        }
        make_heap(h.begin(), h.end(), greater<>());
        ll M = *max_element(nums.begin(), nums.end());
        for (; k && h[0].first < M; k--) {
            pop_heap(h.begin(), h.end(), greater<>());
            h.back().first *= multiplier;  // 这里不能取模，因为取模后可能导致一个本来大于M的数又小于M了。
            push_heap(h.begin(), h.end(), greater<>());
        }
        sort(h.begin(), h.end());
        for (int i = 0; i < h.size(); i++) {
            auto& [val, index] = h[i];
            nums[index] = val % MOD * pow(multiplier, k / nums.size() + (i < k % nums.size())) % MOD;
        }
        return nums;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/14/LeetCode%203266.K%E6%AC%A1%E4%B9%98%E8%BF%90%E7%AE%97%E5%90%8E%E7%9A%84%E6%9C%80%E7%BB%88%E6%95%B0%E7%BB%84II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144473973](https://letmefly.blog.csdn.net/article/details/144473973)
