---
title: 2562.找出数组的串联值
date: 2023-10-12 18:50:12
tags: [题解, LeetCode, 简单, 数组, 双指针, 模拟]
---

# 【LetMeFly】2562.找出数组的串联值：模拟（双指针）

力扣题目链接：[https://leetcode.cn/problems/find-the-array-concatenation-value/](https://leetcode.cn/problems/find-the-array-concatenation-value/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组&nbsp;<code>nums</code> 。</p>

<p>现定义两个数字的 <strong>串联</strong>&nbsp;是由这两个数值串联起来形成的新数字。</p>

<ul>
	<li>例如，<code>15</code><span style="">&nbsp;和&nbsp;</span><code>49</code>&nbsp;的串联是&nbsp;<code>1549</code> 。</li>
</ul>

<p><code>nums</code>&nbsp;的 <strong>串联值</strong>&nbsp;最初等于 <code>0</code> 。执行下述操作直到&nbsp;<code>nums</code>&nbsp;变为空：</p>

<ul>
	<li>如果&nbsp;<code>nums</code>&nbsp;中存在不止一个数字，分别选中 <code>nums</code> 中的第一个元素和最后一个元素，将二者串联得到的值加到&nbsp;<code>nums</code>&nbsp;的 <strong>串联值</strong> 上，然后从&nbsp;<code>nums</code>&nbsp;中删除第一个和最后一个元素。</li>
	<li>如果仅存在一个元素，则将该元素的值加到&nbsp;<code>nums</code> 的串联值上，然后删除这个元素。</li>
</ul>

<p>返回执行完所有操作后<em>&nbsp;</em><code>nums</code> 的串联值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [7,52,2,4]
<b>输出：</b>596
<b>解释：</b>在执行任一步操作前，nums 为 [7,52,2,4] ，串联值为 0 。
 - 在第一步操作中：
我们选中第一个元素 7 和最后一个元素 4 。
二者的串联是 74 ，将其加到串联值上，所以串联值等于 74 。
接着我们从 nums 中移除这两个元素，所以 nums 变为 [52,2] 。
 - 在第二步操作中： 
我们选中第一个元素 52 和最后一个元素 2 。 
二者的串联是 522 ，将其加到串联值上，所以串联值等于 596 。
接着我们从 nums 中移除这两个元素，所以 nums 变为空。
由于串联值等于 596 ，所以答案就是 596 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,14,13,8,12]
<b>输出：</b>673
<b>解释：</b>在执行任一步操作前，nums 为 [5,14,13,8,12] ，串联值为 0 。 
- 在第一步操作中： 
我们选中第一个元素 5 和最后一个元素 12 。 
二者的串联是 512 ，将其加到串联值上，所以串联值等于 512 。 
接着我们从 nums 中移除这两个元素，所以 nums 变为 [14,13,8] 。
- 在第二步操作中：
我们选中第一个元素 14 和最后一个元素 8 。
二者的串联是 148 ，将其加到串联值上，所以串联值等于 660 。
接着我们从 nums 中移除这两个元素，所以 nums 变为 [13] 。 
- 在第三步操作中：
nums 只有一个元素，所以我们选中 13 并将其加到串联值上，所以串联值等于 673 。
接着我们从 nums 中移除这个元素，所以 nums 变为空。 
由于串联值等于 673 ，所以答案就是 673 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：模拟（双指针）

使用两个指针$l$和$r$分别指向数组中的第一个和最后一个元素。

两个指针不断向中间移动，在$l<r$时，累加$nums[l]\times len(nums[r]) + nums[r]$。

最后，如果$l=r$，则累加一个$nums[l]$。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int t = nums[r];
            long long mul = 1;
            while (t) {
                t /= 10;
                mul *= 10;
            }
            ans += nums[l] * mul + nums[r];
            l++, r--;
        }
        if (l == r) {
            ans += nums[l];
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        ans = 0
        while l < r:
            ans += int(str(nums[l]) + str(nums[r]))
            l, r = l + 1, r - 1
        if l == r:
            ans += nums[l]
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/12/LeetCode%202562.%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E7%9A%84%E4%B8%B2%E8%81%94%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133797249](https://letmefly.blog.csdn.net/article/details/133797249)
