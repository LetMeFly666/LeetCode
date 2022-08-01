---
title: 128.最长连续序列
date: 2022-07-21 22:45:29
tags: [题解, LeetCode, 中等, 并查集, 数组, 哈希表, set, 思维, 构造, 子问题, 最x子xx]
---

# 【LetMeFly】128.最长连续序列

力扣题目链接：[https://leetcode.cn/problems/longest-consecutive-sequence/](https://leetcode.cn/problems/longest-consecutive-sequence/)

<p>给定一个未排序的整数数组 <code>nums</code> ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。</p>

<p>请你设计并实现时间复杂度为 <code>O(n)</code><em> </em>的算法解决此问题。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [100,4,200,1,3,2]
<strong>输出：</strong>4
<strong>解释：</strong>最长数字连续序列是 <code>[1, 2, 3, 4]。它的长度为 4。</code></pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,3,7,2,5,8,4,6,0,1]
<strong>输出：</strong>9
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：排序（非O(n)）

方法一比较简单，但是时间复杂度非题目要求的$O(n)$

首先对原数组进行排序，排序过后从前向后遍历一遍数组，遇到与上一个相同的就跳过，遇到比上一个大$1$的就累计，否则就重新开始统计并更新答案。

+ 时间复杂度$O(n\log n)$，其中$n$是原始数组的大小
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int lastNum = -INT_MAX;
        int nowCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == lastNum)
                continue;
            if (nums[i] == lastNum + 1) {
                nowCnt++;
            }
            else {
                nowCnt = 1;
            }
            lastNum = nums[i];
            ans = max(ans, nowCnt);
        }
        return ans;
    }
};
```


## 方法二：哈希（O(n)）

方法一中的时间复杂度主要来自排序。

排序的目的是什么？

排序的目的是：**遇到a的时候看是否存在a + 1**。

那么，用哈希表记录一下不是一样的效果吗？

初始时，用哈希表统计原始数据并去重

之后遍历去重后的数字，遍历到$a$时，如果$a-1$存在（$se.count(a-1)$），那么就继续遍历

如果$a-1$不存在，那么久说明$a$是某个“连续串”的开始（原始数组中存在$a, a+1, a+\cdots$）

这时候，从$a$开始，每次$a$递增$1$，看是否存在新的$a$，以此来统计从$a$开始的“连续串”的长度

+ 时间复杂度$O(n)$，其中$n$是原始数组的大小。因此是从最小的$a$开始统计的，所以所有数字最多额外遍历一遍。
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> se;
        int ans = 0;
        for (int& t : nums) {
            se.insert(t);
        }
        for (int t : se) {
            if (!se.count(t - 1)) {  // 一串数字的最小的
                int thisCnt = 0;
                while (se.count(t)) {
                    thisCnt++;
                    t++;
                }
                ans = max(ans, thisCnt);
            }
        }
        return ans;
    }
};
```

## 对比

因为方法一的空间复杂度较低，并且方法一只需要排序，时间复杂度不一定达到$O(n\log n)$

方法二空间复杂度较高，虽然时间复杂度是$O(n)$，但是哈希表时间复杂度常数较大，时间不一定比方法一短。

经过不严谨对比（每种方法都只试了一次）：

+ 方法一执行用时52ms，空间消耗32.9MB
+ 方法二执行用时100ms，空间消耗48.6MB

数据可能存在很大的偶然性误差，但是上述提交方法一的表现要比方法二优秀

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/21/LeetCode%200128.%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125922929](https://letmefly.blog.csdn.net/article/details/125922929)
