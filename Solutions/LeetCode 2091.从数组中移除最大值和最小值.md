---
title: 2091.从数组中移除最大值和最小值：三种可能取最小
date: 2026-08-30 09:47:31
tags: [题解, LeetCode, 中等, 贪心, 数组, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2091.从数组中移除最大值和最小值：三种可能取最小

力扣题目链接：[https://leetcode.cn/problems/removing-minimum-and-maximum-from-array/](https://leetcode.cn/problems/removing-minimum-and-maximum-from-array/)

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组由若干 <strong>互不相同</strong> 的整数组成。</p>

<p><code>nums</code> 中有一个值最小的元素和一个值最大的元素。分别称为 <strong>最小值</strong> 和 <strong>最大值</strong> 。你的目标是从数组中移除这两个元素。</p>

<p>一次 <strong>删除</strong> 操作定义为从数组的 <strong>前面</strong> 移除一个元素或从数组的 <strong>后面</strong> 移除一个元素。</p>

<p>返回将数组中最小值和最大值 <strong>都</strong> 移除需要的最小删除次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,<em><strong>10</strong></em>,7,5,4,<em><strong>1</strong></em>,8,6]
<strong>输出：</strong>5
<strong>解释：</strong>
数组中的最小元素是 nums[5] ，值为 1 。
数组中的最大元素是 nums[1] ，值为 10 。
将最大值和最小值都移除需要从数组前面移除 2 个元素，从数组后面移除 3 个元素。
结果是 2 + 3 = 5 ，这是所有可能情况中的最小删除次数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,<em><strong>-4</strong></em>,<em><strong>19</strong></em>,1,8,-2,-3,5]
<strong>输出：</strong>3
<strong>解释：</strong>
数组中的最小元素是 nums[1] ，值为 -4 。
数组中的最大元素是 nums[2] ，值为 19 。
将最大值和最小值都移除需要从数组前面移除 3 个元素。
结果是 3 ，这是所有可能情况中的最小删除次数。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [<em><strong>101</strong></em>]
<strong>输出：</strong>1
<strong>解释：</strong>
数组中只有这一个元素，那么它既是数组中的最小值又是数组中的最大值。
移除它只需要 1 次删除操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code> 中的整数 <strong>互不相同</strong></li>
</ul>


    
## 解题方法：一次遍历

一次遍历即可得到最大元素和最小元素的位置。最优的删除两下标的方式有三种：

1. 从左往右删完两个下标
2. 从右往左删完两个下标
3. 从两边开始分别删掉两个下标

以上。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-30 09:44:30
 */
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int m = nums[0], M = m;
        int im = 0, iM = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < m) {
                m = nums[i];
                im = i;
            }
            if (nums[i] > M) {
                M = nums[i];
                iM = i;
            }
        }

        if (im > iM) {
            swap(im, iM);
        }
        return min(im + 1 + n - iM, min(iM + 1, n - im));
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/164193705)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/30/LeetCode%202091.%E4%BB%8E%E6%95%B0%E7%BB%84%E4%B8%AD%E7%A7%BB%E9%99%A4%E6%9C%80%E5%A4%A7%E5%80%BC%E5%92%8C%E6%9C%80%E5%B0%8F%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
