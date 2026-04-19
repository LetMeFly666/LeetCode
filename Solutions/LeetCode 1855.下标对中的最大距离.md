---
title: 1855.下标对中的最大距离：双指针
date: 2026-04-19 13:40:00
tags: [题解, LeetCode, 中等, 数组, 双指针, 二分查找]
categories: [题解, LeetCode]
---

# 【LetMeFly】1855.下标对中的最大距离：双指针

力扣题目链接：[https://leetcode.cn/problems/maximum-distance-between-a-pair-of-values/](https://leetcode.cn/problems/maximum-distance-between-a-pair-of-values/)

<p>给你两个 <strong>非递增</strong> 的整数数组 <code>nums1</code>​​​​​​ 和 <code>nums2</code>​​​​​​ ，数组下标均 <strong>从 0 开始</strong> 计数。</p>

<p>下标对 <code>(i, j)</code> 中 <code>0 &lt;= i &lt; nums1.length</code> 且 <code>0 &lt;= j &lt; nums2.length</code> 。如果该下标对同时满足 <code>i &lt;= j</code> 且 <code>nums1[i] &lt;= nums2[j]</code> ，则称之为 <strong>有效</strong> 下标对，该下标对的 <strong>距离</strong> 为 <code>j - i</code>​​ 。​​</p>

<p>返回所有 <strong>有效</strong> 下标对<em> </em><code>(i, j)</code><em> </em>中的 <strong>最大距离</strong> 。如果不存在有效下标对，返回 <code>0</code> 。</p>

<p>一个数组 <code>arr</code> ，如果每个 <code>1 &lt;= i &lt; arr.length</code> 均有 <code>arr[i-1] &gt;= arr[i]</code> 成立，那么该数组是一个 <strong>非递增</strong> 数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
<strong>输出：</strong>2
<strong>解释：</strong>有效下标对是 (0,0), (2,2), (2,3), (2,4), (3,3), (3,4) 和 (4,4) 。
最大距离是 2 ，对应下标对 (2,4) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,2,2], nums2 = [10,10,1]
<strong>输出：</strong>1
<strong>解释：</strong>有效下标对是 (0,0), (0,1) 和 (1,1) 。
最大距离是 1 ，对应下标对 (0,1) 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
<strong>输出：</strong>2
<strong>解释：</strong>有效下标对是 (2,2), (2,3), (2,4), (3,3) 和 (3,4) 。
最大距离是 2 ，对应下标对 (2,4) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[j] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums1</code> 和 <code>nums2</code> 都是 <strong>非递增</strong> 数组</li>
</ul>


    
## 解题方法：双指针

可以枚举$j$，随着$j$的增大，$nums2[j]$变小，满足$nums1[i]\leq nums2[j]$的$nums1[j]$会变小，$i$会增大。

使用双指针，在枚举$j$的时候，不断增大$i$并保持$nums1[i]\leq nums2[j]$。如果$i$超出数组范围，则说明$nums1$中最小的元素仍然大于$nums2[j]$，退出。

+ 时间复杂度$O(len(nums1)+len(nums2))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-19 13:38:49
 */
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0, j = 0, n = nums1.size(), m = nums2.size(); j < m; j++) {
            while (i < n && nums1[i] > nums2[j]) {
                i++;
            }
            if (i == n) {
                break;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160307177)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/19/LeetCode%201855.%E4%B8%8B%E6%A0%87%E5%AF%B9%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%9D%E7%A6%BB/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
