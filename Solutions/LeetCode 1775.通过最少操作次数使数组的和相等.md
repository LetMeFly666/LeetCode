---
title: 1775.通过最少操作次数使数组的和相等
date: 2022-12-07 10:29:21
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】1775.通过最少操作次数使数组的和相等

力扣题目链接：[https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/](https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/)

<p>给你两个长度可能不等的整数数组 <code>nums1</code> 和 <code>nums2</code> 。两个数组中的所有值都在 <code>1</code> 到 <code>6</code> 之间（包含 <code>1</code> 和 <code>6</code>）。</p>

<p>每次操作中，你可以选择 <strong>任意</strong> 数组中的任意一个整数，将它变成 <code>1</code> 到 <code>6</code> 之间 <strong>任意</strong> 的值（包含 <code>1</code> 和 <code><span style="">6</span></code>）。</p>

<p>请你返回使 <code>nums1</code> 中所有数的和与 <code>nums2</code> 中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
<b>输出：</b>3
<b>解释：</b>你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [<strong>6</strong>,1,2,2,2,2] 。
- 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,<strong>1</strong>], nums2 = [6,1,2,2,2,2] 。
- 将 nums1[2] 变为 2 。 nums1 = [1,2,<strong>2</strong>,4,5,1], nums2 = [6,1,2,2,2,2] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [1,1,1,1,1,1,1], nums2 = [6]
<b>输出：</b>-1
<b>解释：</b>没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums1 = [6,6], nums2 = [1]
<b>输出：</b>3
<b>解释：</b>你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums1[0] 变为 2 。 nums1 = [<strong>2</strong>,6], nums2 = [1] 。
- 将 nums1[1] 变为 2 。 nums1 = [2,<strong>2</strong>], nums2 = [1] 。
- 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [<strong>4</strong>] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 6</code></li>
</ul>


    
## 方法一：贪心 + 计数

<!-- 
这里取消了原本的普通文本代码段
-->

两个数组中的元素的初始和可能不同。为了方便，我们假设第一个数组的元素和**小于**第二个数组（不是的话交换两个数组的地址即可）

那么，我们的任务就是，将第一个数组中的元素变大，或者将第二个数组中的元素减小，使得两个数组中的元素和相等。

因为数字的**合法范围**是$1$到$6$，因此，第一个数组中，我们尽量让小的元素优先变成$6$，这样所带来的“和的增加”最多。

同理，第二个数组中，我们尽量让大的元素变成$1$，这样所带来的“和的减少”最多。

因此，我们可以预处理一遍两个数组，计算出两个数组中“和的差值”，并统计两个数组中1到6的元素的个数

然后，我们将第一个数组中的“1”变成“6”，同时将第二个数组中的“6”变成“1”，直到“没有元素可变”或“差值小于等于0”

接着，我们将第一个数组中的“2”变成“6”，同时将第二个数组中的“5”变成“1”，直到“没有元素可变”或“差值小于等于0”

......

这样，我们每次修改元素，都是“尽最大努力”地减小了两个数组中的差值，这样就能保证每次更改能“尽大可能”地缩小差值

这就是**贪心**

其实不难发现，将第一个数组中的“1”变成“6”和将第二个数组中的“6”变成“1”所带来的结果是等价的，因此，为了方便，我们可以直接将第二个数组中的“6”和第一个数组中的“1”统计到一起。

+ 时间复杂度$O(len(nums1) + len(nums2) + C)$，其中$C$是数组中元素的合法范围的大小，即$C=6$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (s1 > s2)
            swap(nums1, nums2);
        int times[6] = {0};
        for (int& t : nums1)
            times[t - 1]++;
        for (int& t : nums2)
            times[6 - t]++;
        int ans = 0;
        int loc = 0;
        int diff = abs(s2 - s1);
        while (diff) {
            int perChange = 6 - loc - 1;
            if (!perChange)
                break;
            int maxChange = times[loc] * perChange;
            int realChange = min(maxChange, diff);
            diff -= realChange;
            int changeTimes = realChange / perChange + (realChange % perChange != 0);
            ans += changeTimes;
            loc++;
        }
        return diff ? -1 : ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/07/LeetCode%201775.%E9%80%9A%E8%BF%87%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0%E4%BD%BF%E6%95%B0%E7%BB%84%E7%9A%84%E5%92%8C%E7%9B%B8%E7%AD%89/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128216782](https://letmefly.blog.csdn.net/article/details/128216782)
