---
title: 2404.出现最频繁的偶数元素
date: 2023-04-13 18:16:53
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, map, 计数, 排序, 双指针]
---

# 【LetMeFly】2404.出现最频繁的偶数元素

力扣题目链接：[https://leetcode.cn/problems/most-frequent-even-element/](https://leetcode.cn/problems/most-frequent-even-element/)

<p>给你一个整数数组 <code>nums</code> ，返回出现最频繁的偶数元素。</p>

<p>如果存在多个满足条件的元素，只需要返回 <strong>最小</strong> 的一个。如果不存在这样的元素，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,2,2,4,4,1]
<strong>输出：</strong>2
<strong>解释：</strong>
数组中的偶数元素为 0、2 和 4 ，在这些元素中，2 和 4 出现次数最多。
返回最小的那个，即返回 2 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,4,4,9,2,4]
<strong>输出：</strong>4
<strong>解释：</strong>4 是出现最频繁的偶数元素。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [29,47,21,41,13,37,25,7]
<strong>输出：</strong>-1
<strong>解释：</strong>不存在偶数元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：哈希表

使用哈希表统计每个数出现的次数。

遍历原始数组，如果这个数是偶数，就将每个数加入到哈希表中，并且更新答案的最优解。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> ma;
        int M = 0, ans = 1e8;
        for (int& n : nums) {
            if (n % 2 == 0) {
                ma[n]++;
                // printf("n = %d, ma[%d] = %d, M = %d\n", n, n, ma[n], M);  //**************
                if (ma[n] > M) {
                    M = ma[n];
                    ans = n;
                }
                else if (ma[n] == M) {
                    ans = min(ans, n);
                }
            }
        }
        return ans == 1e8 ? -1 : ans;
    }
};
```

#### Python

```python

```

## 方法二：排序 + 双指针

首先对原始数组排个序，再使用双指针统计连续的数字的个数。

遍历排序后的数组，如果某个元素不同于前一个元素，就由两个指针之间的距离求出上一个元素一共出现了多少次，并更新首指针的位置。

排序还有一个好处，就是假设有两个偶数都出现了最多次数，那么先遍历到的出现这么多次的偶数是最小的。

+ 时间复杂度$O(len(nums)\times \log len(nums))$
+ 空间复杂度$O( \log len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int M = 0, ans = -1;
        int beginLoc = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (i == nums.size() || nums[i] != nums[i - 1]) {
                if (nums[i - 1] % 2 == 0) {
                    int thisCnt = i - beginLoc;
                    if (thisCnt > M) {
                        M = thisCnt;
                        ans = nums[i - 1];
                    }
                }
                beginLoc = i;
            }
        }
        return ans;
    }
};
```

C++的时间超过了96.65%的提交，空间小于98.14%的提交  嘿嘿

#### Python

```python
# from typing import List

class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        nums.sort()
        M, ans = 0, -1
        beginLoc = 0
        for i in range(1, len(nums) + 1):
            if i == len(nums) or nums[i] != nums[i - 1]:
                if nums[i - 1] % 2 == 0:
                    thisCnt = i - beginLoc
                    if thisCnt > M:
                        M = thisCnt
                        ans = nums[i - 1]
                beginLoc = i
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/04/13/LeetCode%202404.%E5%87%BA%E7%8E%B0%E6%9C%80%E9%A2%91%E7%B9%81%E7%9A%84%E5%81%B6%E6%95%B0%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130137031](https://letmefly.blog.csdn.net/article/details/130137031)
