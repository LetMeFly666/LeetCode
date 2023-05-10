---
title: 485.最大连续 1 的个数
date: 2022-11-01 21:33:59
tags: [题解, LeetCode, 简单, 数组]
---

# 【LetMeFly】485.最大连续 1 的个数

力扣题目链接：[https://leetcode.cn/problems/max-consecutive-ones/](https://leetcode.cn/problems/max-consecutive-ones/)

<p>给定一个二进制数组 <code>nums</code> ， 计算其中最大连续 <code>1</code> 的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,0,1,1,1]
<strong>输出：</strong>3
<strong>解释：</strong>开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>nums = [1,0,1,1,0,1]
<b>输出：</b>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>.</li>
</ul>


    
## 方法一：统计

使用几个遍历：

+ ```ans```代表答案（也就是连续1的最大个数），初始值是0
+ ```lastIs1```代表上一个数字是否为1，初始值是false
+ ```nowCnt```代表**当前**“连续1”的个数，初始值是0

接下来遍历数组，如果这个元素是1，那么```nowCnt```就+1

如果这个元素是0并且上一个元素是1（lastIs1），那么就更新答案的最大值，并重置“nowCnt”

每次遍历完都需要更新“lastIs1”

最后，再次更新答案最大值即可（否则如果最后一个元素不是0，nowCnt就没有与ans做比较）

+ 时间复杂度$O(n)$，其中$n$是数组中的元素个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        bool lastIs1 = false;
        int nowCnt = 0;
        for(int i : nums) {
            if (i) {
                lastIs1 = true;
                nowCnt++;
            }
            else {
                if (lastIs1) {
                    lastIs1 = false;
                    ans = max(ans, nowCnt);
                    nowCnt = 0;
                }
            }
        }
        ans = max(ans, nowCnt);
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/01/LeetCode%200485.%E6%9C%80%E5%A4%A7%E8%BF%9E%E7%BB%AD1%E7%9A%84%E4%B8%AA%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127642017](https://letmefly.blog.csdn.net/article/details/127642017)
