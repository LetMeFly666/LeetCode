---
title: 3583.统计特殊三元组：哈希表计数
date: 2025-12-09 23:51:33
tags: [题解, LeetCode, 中等, 数组, 哈希表, map, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】3583.统计特殊三元组：哈希表计数

力扣题目链接：[https://leetcode.cn/problems/count-special-triplets/](https://leetcode.cn/problems/count-special-triplets/)

<p>给你一个整数数组 <code>nums</code>。</p>

<p><strong>特殊三元组 </strong>定义为满足以下条件的下标三元组 <code>(i, j, k)</code>：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt; n</code>，其中 <code>n = nums.length</code></li>
	<li><code>nums[i] == nums[j] * 2</code></li>
	<li><code>nums[k] == nums[j] * 2</code></li>
</ul>

<p>返回数组中&nbsp;<strong>特殊三元组&nbsp;</strong>的总数。</p>

<p>由于答案可能非常大，请返回结果对 <code>10<sup>9</sup> + 7</code> 取余数后的值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [6,3,6]</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>唯一的特殊三元组是 <code>(i, j, k) = (0, 1, 2)</code>，其中：</p>

<ul>
	<li><code>nums[0] = 6</code>, <code>nums[1] = 3</code>, <code>nums[2] = 6</code></li>
	<li><code>nums[0] = nums[1] * 2 = 3 * 2 = 6</code></li>
	<li><code>nums[2] = nums[1] * 2 = 3 * 2 = 6</code></li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,1,0,0]</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>唯一的特殊三元组是 <code>(i, j, k) = (0, 2, 3)</code>，其中：</p>

<ul>
	<li><code>nums[0] = 0</code>, <code>nums[2] = 0</code>, <code>nums[3] = 0</code></li>
	<li><code>nums[0] = nums[2] * 2 = 0 * 2 = 0</code></li>
	<li><code>nums[3] = nums[2] * 2 = 0 * 2 = 0</code></li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [8,4,2,8,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>共有两个特殊三元组：</p>

<ul>
	<li><code>(i, j, k) = (0, 1, 3)</code>

	<ul>
		<li><code>nums[0] = 8</code>, <code>nums[1] = 4</code>, <code>nums[3] = 8</code></li>
		<li><code>nums[0] = nums[1] * 2 = 4 * 2 = 8</code></li>
		<li><code>nums[3] = nums[1] * 2 = 4 * 2 = 8</code></li>
	</ul>
	</li>
	<li><code>(i, j, k) = (1, 2, 4)</code>
	<ul>
		<li><code>nums[1] = 4</code>, <code>nums[2] = 2</code>, <code>nums[4] = 4</code></li>
		<li><code>nums[1] = nums[2] * 2 = 2 * 2 = 4</code></li>
		<li><code>nums[4] = nums[2] * 2 = 2 * 2 = 4</code></li>
	</ul>
	</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：哈希表计数

使用一个哈希表，统计nums中每个数分别出现了多少次。

接着再次遍历nums数组，再使用一个哈希表，统计到目前为止每个数分别出现了多少次。

假设当前遍历元素为$t$，那么在此之前$2t$出现的次数乘以$2t$在此之后出现的次数($出现总次数-此前出现次数$)累加到答案中。

注意：

1. 特判$t=0$时
2. 其实也可以使用64位整数并且只在最后取一次模

### 时空复杂度分析

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-09 18:43:53
 */
typedef long long ll;
const long long MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        ll ans = 0;
        unordered_map<int, int> total, now;
        for (int t : nums) {
            total[t]++;
        }
        for (int t : nums) {
            int finding = t * 2;
            if (now.count(finding)) {
                ll left = now[finding];
                ans = (ans + left * (total[finding] - left - (t == 0))) % MOD;
            }
            now[t]++;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/155754955)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/09/LeetCode%203583.%E7%BB%9F%E8%AE%A1%E7%89%B9%E6%AE%8A%E4%B8%89%E5%85%83%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
