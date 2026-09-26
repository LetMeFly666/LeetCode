---
title: 2996.大于等于顺序前缀和的最小缺失整数：模拟（小数据无需哈希表）
date: 2026-08-11 09:21:41
tags: [题解, LeetCode, 简单, 数组, 哈希表, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2996.大于等于顺序前缀和的最小缺失整数：模拟（小数据无需哈希表）

力扣题目链接：[https://leetcode.cn/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/](https://leetcode.cn/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>如果一个前缀&nbsp;<code>nums[0..i]</code>&nbsp;满足对于&nbsp;<code>1 &lt;= j &lt;= i</code>&nbsp;的所有元素都有&nbsp;<code>nums[j] = nums[j - 1] + 1</code>&nbsp;，那么我们称这个前缀是一个 <strong>顺序前缀</strong> 。特殊情况是，只包含&nbsp;<code>nums[0]</code>&nbsp;的前缀也是一个 <strong>顺序前缀</strong> 。</p>

<p>请你返回 <code>nums</code>&nbsp;中没有出现过的 <strong>最小</strong>&nbsp;整数&nbsp;<code>x</code>&nbsp;，满足&nbsp;<code>x</code>&nbsp;大于等于&nbsp;<strong>最长</strong> 顺序前缀的和。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,2,5]
<b>输出：</b>6
<b>解释：</b>nums 的最长顺序前缀是 [1,2,3] ，和为 6 ，6 不在数组中，所以 6 是大于等于最长顺序前缀和的最小整数。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,4,5,1,12,14,13]
<b>输出：</b>15
<b>解释：</b>nums 的最长顺序前缀是 [3,4,5] ，和为 12 ，12、13 和 14 都在数组中，但 15 不在，所以 15 是大于等于最长顺序前缀和的最小整数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>


    
## 解题方法：模拟

使用一个变量$cnt$统计最长前缀的和，初始值$cnt=nums[0]$；接着从$i=1$开始向后遍历，如果$nums[i] \neq nums[i-1]+1$说明前缀终止结束遍历，否则令$cnt$加上$nums[i]$。

当$cnt$在$nums$数组中存在的时候，不断令$cnt+1$，返回第一个不存在于$nums$数组中的$cnt$即为所求。

+ 时间复杂度$O(n^2)$，$cnt$每次加一最多加不超过$n$次，每次查找的时间复杂度是$O(n)$。 此小数据量下的$O(n^2)$ 小于 常数很大的$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-11 09:20:09
 */
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int cnt = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            }
            cnt += nums[i];
        }
        while (ranges::find(nums, cnt) != nums.end()) {  // 注意≠是存在
            cnt++;
        }
        return cnt;
    }
};
```

+ 执行用时分布 0 ms 击败 100.00%
+ 消耗内存分布 22.16 MB 击败 96.68%

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163656089)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/11/LeetCode%202996.%E5%A4%A7%E4%BA%8E%E7%AD%89%E4%BA%8E%E9%A1%BA%E5%BA%8F%E5%89%8D%E7%BC%80%E5%92%8C%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BC%BA%E5%A4%B1%E6%95%B4%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
