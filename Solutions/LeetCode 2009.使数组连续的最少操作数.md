---
title: 2009.使数组连续的最少操作数
date: 2024-04-08 14:48:01
tags: [题解, LeetCode, 困难, 数组, 二分查找, 排序, 哈希表, 哈希, set, 滑动窗口, 双指针]
categories: [题解, LeetCode]
---

# 【LetMeFly】2009.使数组连续的最少操作数：去重排序 + 滑动窗口

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous/](https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。每一次操作中，你可以将&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>任意</strong>&nbsp;一个元素替换成 <strong>任意&nbsp;</strong>整数。</p>

<p>如果&nbsp;<code>nums</code>&nbsp;满足以下条件，那么它是 <strong>连续的</strong>&nbsp;：</p>

<ul>
	<li><code>nums</code>&nbsp;中所有元素都是 <b>互不相同</b>&nbsp;的。</li>
	<li><code>nums</code>&nbsp;中 <strong>最大</strong>&nbsp;元素与&nbsp;<strong>最小</strong>&nbsp;元素的差等于&nbsp;<code>nums.length - 1</code>&nbsp;。</li>
</ul>

<p>比方说，<code>nums = [4, 2, 5, 3]</code>&nbsp;是 <strong>连续的</strong>&nbsp;，但是&nbsp;<code>nums = [1, 2, 3, 5, 6]</code> <strong>不是连续的</strong>&nbsp;。</p>

<p>请你返回使 <code>nums</code>&nbsp;<strong>连续</strong>&nbsp;的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [4,2,5,3]
<b>输出：</b>0
<b>解释：</b>nums 已经是连续的了。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,5,6]
<b>输出：</b>1
<b>解释：</b>一个可能的解是将最后一个元素变为 4 。
结果数组为 [1,2,3,5,4] ，是连续数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1,10,100,1000]
<b>输出：</b>3
<b>解释：</b>一个可能的解是：
- 将第二个元素变为 2 。
- 将第三个元素变为 3 。
- 将第四个元素变为 4 。
结果数组为 [1,2,3,4] ，是连续数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：去重排序 + 滑动窗口

元素顺序与是否连续无关，相同的元素对于数组的连续是无意义的，因此我们可以直接对原始数组来个去重（可使用哈希表）加排序。

接着使用变量```l```枚举左侧```nums[l]```作为“连续数组”的最小值，那么这个连续数组的数据范围就应该是```nums[l]```到```nums[l] + n - 1```（```n```为原始数组的长度）。

使用变量```r```枚举右侧```nums[r]```使得```r```为满足```nums[r] <= nums[l] + n - 1```的最大```r```。

那么，对于这个```l```，```nums[l]```到```nums[r]```即为最终“连续数组”可以使用的元素，```n```减去“可直接使用元素”的个数即为```nums[l]```作为连续数组最小值时所需的最小操作数。

+ 时间复杂度$O(n\log n)$：排序耗时$O(n\log n)$，滑动窗口总计耗时$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& originalNums) {
        int n = originalNums.size();
        unordered_set<int> differentNums(originalNums.begin(), originalNums.end());
        vector<int> nums(differentNums.begin(), differentNums.end());
        sort(nums.begin(), nums.end());
        int ans = n - 1;
        int r = 0;
        for (int l = 0; l < nums.size(); l++) {
            while (r < nums.size() && nums[r] <= nums[l] + n - 1) {
                r++;
            }
            ans = min(ans, n - (r - l));
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))
        ans = n - 1
        r = 0
        for l in range(len(nums)):
            while r < len(nums) and nums[r] <= nums[l] + n - 1:
                r += 1
            ans = min(ans, n - (r - l))
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/08/LeetCode%202009.%E4%BD%BF%E6%95%B0%E7%BB%84%E8%BF%9E%E7%BB%AD%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137509681](https://letmefly.blog.csdn.net/article/details/137509681)
