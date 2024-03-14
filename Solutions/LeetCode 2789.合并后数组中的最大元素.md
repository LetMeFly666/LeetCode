---
title: 2789.合并后数组中的最大元素
date: 2024-03-14 08:58:14
tags: [题解, LeetCode, 中等, 贪心, 数组, 前缀和]
---

# 【LetMeFly】2789.合并后数组中的最大元素：贪心（倒序）

力扣题目链接：[https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/](https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/)

<p>给你一个下标从 <strong>0</strong> 开始、由正整数组成的数组 <code>nums</code> 。</p>

<p>你可以在数组上执行下述操作 <strong>任意</strong> 次：</p>

<ul>
	<li>选中一个同时满足&nbsp;<code>0 &lt;= i &lt; nums.length - 1</code> 和 <code>nums[i] &lt;= nums[i + 1]</code> 的整数 <code>i</code> 。将元素 <code>nums[i + 1]</code> 替换为 <code>nums[i] + nums[i + 1]</code> ，并从数组中删除元素 <code>nums[i]</code> 。</li>
</ul>

<p>返回你可以从最终数组中获得的 <strong>最大</strong> 元素的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,7,9,3]
<strong>输出：</strong>21
<strong>解释：</strong>我们可以在数组上执行下述操作：
- 选中 i = 0 ，得到数组 nums = [<strong><em>5</em></strong>,7,9,3] 。
- 选中 i = 1 ，得到数组 nums = [5,<em><strong>16</strong></em>,3] 。
- 选中 i = 0 ，得到数组 nums = [<em><strong>21</strong></em>,3] 。
最终数组中的最大元素是 21 。可以证明我们无法获得更大的元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,3,3]
<strong>输出：</strong>11
<strong>解释：</strong>我们可以在数组上执行下述操作：
- 选中 i = 1 ，得到数组 nums = [5,<em><strong>6</strong></em>] 。
- 选中 i = 0 ，得到数组 nums = [<em><strong>11</strong></em>] 。
最终数组中只有一个元素，即 11 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：贪心（倒序）

相邻两个数，如果右边大于等于左边，则右边可以**吃掉**左边并化为己有。

那就从最右边往左开吃呗！若能吃，则吃之；若不能，则为之。（如果右边的数不小于左边，则右边的数吃掉左边的数；否则，右边的数成为左边的数。）

直到遍历到最左边为止。

### Q&A

Q1：为什么要从右往左开吃？

A1：贪心。因为只有右边较大才能吃到左边，最终目标是总和尽可能大（也就是吃地尽可能多），因此要先大右边再大左边。例如```2 2 3```，若先“```3```吃```2```”则变成```2 5```，最终变成```7```；若先“```2```吃```2```”则变成```4 3```，无法继续。

Q2：为什么“若不能，则为之”？

A2：因为“不能”是因为“右边小于左边”，右边那个数“永无再吃之日”，并且其比左边那个数小，因此舍弃右边的数使用更大的左边的数继续。

### 时空复杂度

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll maxArrayValue(vector<int>& nums) {
        ll ans = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] <= ans) {
                ans += nums[i];
            }
            else {
                ans = nums[i];
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        ans = nums[-1]
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] <= ans:
                ans += nums[i]
            else:
                ans = nums[i]
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/14/LeetCode%202789.%E5%90%88%E5%B9%B6%E5%90%8E%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136698122](https://letmefly.blog.csdn.net/article/details/136698122)
