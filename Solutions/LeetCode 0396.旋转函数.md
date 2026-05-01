---
title: 396.旋转函数：求diff（增量法）
date: 2026-05-01 21:35:54
tags: [题解, LeetCode, 中等, 数组, 数学, 动态规划]
categories: [题解, LeetCode]
---

# 【LetMeFly】396.旋转函数：求diff（增量法）

力扣题目链接：[https://leetcode.cn/problems/rotate-function/](https://leetcode.cn/problems/rotate-function/)

<p>给定一个长度为 <code>n</code> 的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>假设&nbsp;<code>arr<sub>k</sub></code>&nbsp;是数组&nbsp;<code>nums</code>&nbsp;顺时针旋转 <code>k</code> 个位置后的数组，我们定义&nbsp;<code>nums</code>&nbsp;的 <strong>旋转函数</strong>&nbsp;&nbsp;<code>F</code>&nbsp;为：</p>

<ul>
	<li><code>F(k) = 0 * arr<sub>k</sub>[0] + 1 * arr<sub>k</sub>[1] + ... + (n - 1) * arr<sub>k</sub>[n - 1]</code></li>
</ul>

<p>返回&nbsp;<em><code>F(0), F(1), ..., F(n-1)</code>中的最大值&nbsp;</em>。</p>

<p>生成的测试用例让答案符合&nbsp;<strong>32 位</strong> 整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,3,2,6]
<strong>输出:</strong> 26
<strong>解释:</strong>
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [100]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：增量法

以样例1为例：

> $nums = [4, 3, 2, 6]$
> 
> $F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25$
>
> $F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16$

如何由$F(0)$得到$F(1)$呢？很简单：

> $F(1) = F(0) + (4 + 3 + 2 + 6) - 4\times 6$
> 
> 即：$F(1)=F(0)+\sum nums[i] - len(nums)\times nums[-1]$

我们只需要遍历一遍$nums$数组，得到$F(0)$、$\sum nums[i]$，就能在$O(1)$的时间内推出$F(1)$了，递推推到$F(n-1)$总耗时$O(n)$。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-01 21:34:50
 */
typedef long long ll;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        ll now = 0, sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            now += i * nums[i];
            sum += nums[i];
        }
        
        ll ans = now;
        for (int i = 1; i < n; i++) {
            now = now + sum - n * nums[n - i];
            ans = max(ans, now);
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160694129)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/01/LeetCode%200396.%E6%97%8B%E8%BD%AC%E5%87%BD%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
