---
title: 1764.通过连接另一个数组的子数组得到一个数组
date: 2022-12-17 10:43:28
tags: [题解, LeetCode, 中等, 贪心, 数组, 字符串匹配, 双指针, KMP]
---

# 【LetMeFly】1764.通过连接另一个数组的子数组得到一个数组

力扣题目链接：[https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/](https://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/)

<p>给你一个长度为 <code>n</code> 的二维整数数组 <code>groups</code> ，同时给你一个整数数组 <code>nums</code> 。</p>

<p>你是否可以从 <code>nums</code> 中选出 <code>n</code> 个 <strong>不相交</strong> 的子数组，使得第 <code>i</code> 个子数组与 <code>groups[i]</code> （下标从 <strong>0</strong> 开始）完全相同，且如果 <code>i > 0</code> ，那么第 <code>(i-1)</code> 个子数组在 <code>nums</code> 中出现的位置在第 <code>i</code> 个子数组前面。（也就是说，这些子数组在 <code>nums</code> 中出现的顺序需要与 <code>groups</code> 顺序相同）</p>

<p>如果你可以找出这样的 <code>n</code> 个子数组，请你返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p>如果不存在下标为 <code>k</code> 的元素 <code>nums[k]</code> 属于不止一个子数组，就称这些子数组是 <strong>不相交</strong> 的。子数组指的是原数组中连续元素组成的一个序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
<b>输出：</b>true
<b>解释：</b>你可以分别在 nums 中选出第 0 个子数组 [1,-1,0,<strong>1,</strong><strong>-1,</strong><strong>-1</strong>,3,-2,0] 和第 1 个子数组 [1,-1,0,1,-1,-1,<strong>3,</strong><strong>-2,0</strong>] 。
这两个子数组是不相交的，因为它们没有任何共同的元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
<b>输出：</b>false
<strong>解释：</strong>选择子数组 [<strong>1,2,3,4</strong>,10,-2] 和 [1,2,3,4,<strong>10,-2</strong>] 是不正确的，因为它们出现的顺序与 groups 中顺序不同。
[10,-2] 必须出现在 [1,2,3,4] 之前。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
<b>输出：</b>false
<strong>解释：</strong>选择子数组 [7,7,<strong>1,2,3</strong>,4,7,7] 和 [7,7,1,2,<strong>3,4</strong>,7,7] 是不正确的，因为它们不是不相交子数组。
它们有一个共同的元素 nums[4] （下标从 0 开始）。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>groups.length == n</code></li>
	<li><code>1 <= n <= 10<sup>3</sup></code></li>
	<li><code>1 <= groups[i].length, sum(groups[i].length) <= 10<sup><span style="">3</span></sup></code></li>
	<li><code>1 <= nums.length <= 10<sup>3</sup></code></li>
	<li><code>-10<sup>7</sup> <= groups[i][j], nums[k] <= 10<sup>7</sup></code></li>
</ul>


    
## 方法一：双指针

这道题的数据量是$10^3$级别的，$groups$中所有的数字加起来最多$10^3$个。同时，$nums$数组中的数字个数最多也是$10^3$

因此，$O(sum(len(groups))\times len(nums)$的时间复杂度的算法（最多$10^6$级别）可以通过本题。当然，更高效的KMP算法则更能通过本题

最朴素的算法就是双指针暴力，这道题是要求“按顺序找到所有的groups中的数组”，因此，我们最外层遍历$groups$中的每一个数组，这个数组匹配完了再匹配下一个数组，否则就一直匹配这个数组到$nums$末尾

使用变量$locN$表示$nums$数组“使用”到了哪个元素，接着遍历$groups$中的所有数组，在数组未匹配完时，不断进行匹配，直到**这个数组匹配完**（接着匹配下一个数组）或**nums数组匹配完**（$nums$中再无元素和匹配，直接返回$false$）或**二者不匹配**（从$nums$开始匹配这个数组的下一位置开始匹配）为止。

+ 时间复杂度$O(len(nums)\times \max\{len(groups[i])\})$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int locN = 0;
        for (vector<int>& v : groups) {
            int locV = 0;
            while (locV < v.size() && locN < nums.size()) {
                if (v[locV] == nums[locN]) {
                    locV++, locN++;
                }
                else {
                    locN -= locV - 1, locV = 0;
                }
            }
            if (locN == nums.size() && locV != v.size())
                return false;
        }
        return true;
    }
};
```

运行结果还不错：

![result](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/0ce7372b0deb47e88b72d7b301424e0b.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/17/LeetCode%201764.%E9%80%9A%E8%BF%87%E8%BF%9E%E6%8E%A5%E5%8F%A6%E4%B8%80%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E5%BE%97%E5%88%B0%E4%B8%80%E4%B8%AA%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128352023](https://letmefly.blog.csdn.net/article/details/128352023)
