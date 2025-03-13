---
title: 2455.可被三整除的偶数的平均值
date: 2023-05-29 10:27:01
tags: [题解, LeetCode, 简单, 数组, 数学, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2455.可被三整除的偶数的平均值

力扣题目链接：[https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/](https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/)

<p>给你一个由正整数组成的整数数组 <code>nums</code> ，返回其中可被 <code>3</code> 整除的所有偶数的平均值。</p>

<p>注意：<code>n</code> 个元素的平均值等于 <code>n</code> 个元素 <strong>求和</strong> 再除以 <code>n</code> ，结果 <strong>向下取整</strong> 到最接近的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,6,10,12,15]
<strong>输出：</strong>9
<strong>解释：</strong>6 和 12 是可以被 3 整除的偶数。(6 + 12) / 2 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,7,10]
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足题目要求的整数，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：遍历

能被3整除的偶数 等价于 能被6整除的数。

我们只需要使用两个变量“cnt”和“s”，初始值都为0，分别用来统计能 能整除6的数的个数 和 能整除6的数的和。

遍历一遍数组即可完成统计。

最终，如果cnt为0就返回0，否则就返回$\lfloor\frac{s}{cnt}\rfloor$

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        int s = 0;
        for (int t : nums) {
            if (t % 6 == 0) {
                s += t;
                cnt++;
            }
        }
        return cnt ? s / cnt : 0;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def averageValue(self, nums: List[int]) -> int:
        cnt = 0
        s = 0
        for t in nums:
            if t % 6 == 0:
                s += t
                cnt += 1
        return s // cnt if cnt else 0
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/05/29/LeetCode%202455.%E5%8F%AF%E8%A2%AB%E4%B8%89%E6%95%B4%E9%99%A4%E7%9A%84%E5%81%B6%E6%95%B0%E7%9A%84%E5%B9%B3%E5%9D%87%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130923191](https://letmefly.blog.csdn.net/article/details/130923191)
