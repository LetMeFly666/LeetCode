---
title: 1658.将 x 减到 0 的最小操作数：哈希表(+前缀和) / 滑动窗口
date: 2026-09-23 18:49:32
tags: [题解, LeetCode, 中等, 数组, 哈希表, 前缀和, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】1658.将 x 减到 0 的最小操作数：哈希表(+前缀和) / 滑动窗口

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/](https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/)

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>x</code> 。每一次操作时，你应当移除数组 <code>nums</code> 最左边或最右边的元素，然后从 <code>x</code> 中减去该元素的值。请注意，需要 <strong>修改</strong> 数组以供接下来的操作使用。</p>

<p>如果可以将 <code>x</code> <strong>恰好</strong> 减到 <code>0</code> ，返回<strong> 最小操作数 </strong>；否则，返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,4,2,3], x = 5
<strong>输出：</strong>2
<strong>解释：</strong>最佳解决方案是移除后两个元素，将 x 减到 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,6,7,8,9], x = 4
<strong>输出：</strong>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,20,1,1,3], x = 10
<strong>输出：</strong>5
<strong>解释：</strong>最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
	<li><code>1 <= x <= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法一：哈希表+前缀和

正序遍历一遍数组，将`sum(nums[0..i]) -> i`存入哈希表。

倒序遍历一遍数组，记录遍历过程中的后缀和$cnt$。如果$x-cnt$在哈希表中，则找到一个可行的移除方法。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-23 18:40:09
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int, int> prefix;
        for (int i = 0, cnt = 0, n = nums.size(); i < n && cnt < x; i++) {
            cnt += nums[i];
            prefix[cnt] = i;
        }
        prefix[0] = -1;
        int ans = prefix.count(x) ? prefix[x] + 1 : nums.size() + 1;
        for (int n = nums.size(), i = n - 1, cnt = 0; i >= 0 && cnt < x; i--) {
            cnt += nums[i];
            if (prefix.count(x - cnt)) {
                ans = min(ans, prefix[x - cnt] + n - i + 1);
            }
        }
        return ans > nums.size() ? -1 : ans;
    }
};
```

## 解题方法二：滑动窗口

移除前后缀共计$x$，即使得剩余数组和为$sum-x$。

滑动窗口，每次右边加入窗口一元素，当窗口中元素和大于$sum-x$时不断移除左边元素。若移除结束后窗口中元素和等于$sum-x$，则更新答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-23 18:48:44
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int allVal = accumulate(nums.begin(), nums.end(), 0);
        x = allVal - x;
        if (x < 0) {  // 不然while会下标越界
            return -1;
        }
        int ans = 10000000;
        for (int l = 0, r = 0, n = nums.size(), cnt = 0; r < n; r++) {
            cnt += nums[r];
            while (cnt > x) {
                cnt -= nums[l++];
            }
            if (cnt == x) {
                ans = min(ans, n - (r - l + 1));
            }
        }
        return ans == 10000000 ? -1 : ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166490471)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/23/LeetCode%201658.%E5%B0%86x%E5%87%8F%E5%88%B00%E7%9A%84%E6%9C%80%E5%B0%8F%E6%93%8D%E4%BD%9C%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
