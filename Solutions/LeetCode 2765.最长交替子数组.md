---
title: 2765.最长交替子数组
date: 2024-01-23 22:05:37
tags: [题解, LeetCode, 简单, 数组, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】2765.最长交替子数组：O(n)的做法（两次遍历）

力扣题目链接：[https://leetcode.cn/problems/longest-alternating-subarray/](https://leetcode.cn/problems/longest-alternating-subarray/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。如果 <code>nums</code>&nbsp;中长度为&nbsp;<code>m</code>&nbsp;的子数组&nbsp;<code>s</code>&nbsp;满足以下条件，我们称它是一个 <strong>交替子数组</strong> ：</p>

<ul>
	<li><code>m</code>&nbsp;大于&nbsp;<code>1</code>&nbsp;。</li>
	<li><code>s<sub>1</sub> = s<sub>0</sub> + 1</code>&nbsp;。</li>
	<li>下标从 <strong>0</strong> 开始的子数组&nbsp;<code>s</code>&nbsp;与数组&nbsp;<code>[s<sub>0</sub>, s<sub>1</sub>, s<sub>0</sub>, s<sub>1</sub>,...,s<sub>(m-1) % 2</sub>]</code>&nbsp;一样。也就是说，<code>s<sub>1</sub> - s<sub>0</sub> = 1</code>&nbsp;，<code>s<sub>2</sub> - s<sub>1</sub> = -1</code>&nbsp;，<code>s<sub>3</sub> - s<sub>2</sub> = 1</code>&nbsp;，<code>s<sub>4</sub> - s<sub>3</sub> = -1</code>&nbsp;，以此类推，直到&nbsp;<code>s[m - 1] - s[m - 2] = (-1)<sup>m</sup></code>&nbsp;。</li>
</ul>

<p>请你返回 <code>nums</code>&nbsp;中所有 <strong>交替</strong>&nbsp;子数组中，最长的长度，如果不存在交替子数组，请你返回 <code>-1</code>&nbsp;。</p>

<p>子数组是一个数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,4,3,4]
<b>输出：</b>4
<b>解释：</b>交替子数组有 [3,4] ，[3,4,3] 和 [3,4,3,4] 。最长的子数组为 [3,4,3,4] ，长度为4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [4,5,6]
<b>输出：</b>2
<strong>解释：</strong>[4,5] 和 [5,6] 是仅有的两个交替子数组。它们长度都为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


## 方法零：O(n^2)的做法（两层循环）

第一层循环遍历“交替数组”的起点，第二层循环从这个起点开始往后遍历，得到交替数组的终点。更新答案的最大值。

## 方法一：O(n)的做法（两次遍历）

对于样例```[2, 3, 4, 3, 4]```，我们不能将```3```分给```2 3```，而是要把```3```分给```3 4 3 4```。

怎么办呢？其实“交替数组”一共有两种：从奇数下标开始的数组和从偶数下标开始的数组。

因此，我们写一个函数来求“交替数组”，参数为“奇数下标时下一个元素该加一还是减一”。

求完两种交替数组的最大值，取二者最大的那个即为答案。

+ 时间复杂度$O(n)$，其中$n=len(nums)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int get1(vector<int>& nums, int oddLoc=1) {
        int evenLoc = -oddLoc;
        int ans = 1;
        int cnt = 1;
        for (int i = 0; i < nums.size(); i++) {
            int shouldAdd = i % 2 ? oddLoc : evenLoc;
            if (i + 1 == nums.size() || nums[i + 1] != nums[i] + shouldAdd || cnt == 1 && shouldAdd == -1) {
                ans = max(ans, cnt);
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        return ans;
    }
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = max(get1(nums), get1(nums, -1));
        return ans < 2 ? -1 : ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def get1(self, oddLoc=1) -> int:
        evenLoc = -oddLoc
        ans = 1
        cnt = 1
        for i in range(len(self.nums)):
            shouldAdd = oddLoc if i % 2 else evenLoc
            if i + 1 == len(self.nums) or self.nums[i + 1] != self.nums[i] + shouldAdd or (cnt == 1 and shouldAdd == -1):
                ans = max(ans, cnt)
                cnt = 1
            else:
                cnt += 1
        return ans

    def alternatingSubarray(self, nums: List[int]) -> int:
        self.nums = nums
        ans = max(self.get1(), self.get1(-1))
        return ans if ans >= 2 else -1
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/23/LeetCode%202765.%E6%9C%80%E9%95%BF%E4%BA%A4%E6%9B%BF%E5%AD%90%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135794883](https://letmefly.blog.csdn.net/article/details/135794883)
