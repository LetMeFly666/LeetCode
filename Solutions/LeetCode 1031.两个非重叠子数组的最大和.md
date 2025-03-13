---
title: 1031.两个非重叠子数组的最大和
date: 2023-04-26 13:01:51
tags: [题解, LeetCode, 中等, 数组, 前缀和, 动态规划, DP, 思维, 滑动窗口, 贪心]
categories: [题解, LeetCode]
---

# 【LetMeFly】“动图”辅助：1031.两个非重叠子数组的最大和

力扣题目链接：[https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/](https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/)

<p>给出非负整数数组 <code>A</code> ，返回两个非重叠（连续）子数组中元素的最大和，子数组的长度分别为 <code>L</code> 和 <code>M</code>。（这里需要澄清的是，长为 L 的子数组可以出现在长为 M 的子数组之前或之后。）</p>

<p>从形式上看，返回最大的 <code>V</code>，而 <code>V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1])</code> 并满足下列条件之一：</p>

<p>&nbsp;</p>

<ul>
	<li><code>0 &lt;= i &lt; i + L - 1 &lt; j &lt; j + M - 1 &lt; A.length</code>, <strong>或</strong></li>
	<li><code>0 &lt;= j &lt; j + M - 1 &lt; i &lt; i + L - 1 &lt; A.length</code>.</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
<strong>输出：</strong>20
<strong>解释：</strong>子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
<strong>输出：</strong>29
<strong>解释：</strong>子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
<strong>输出：</strong>31
<strong>解释：</strong>子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>L &gt;= 1</code></li>
	<li><code>M &gt;= 1</code></li>
	<li><code>L + M &lt;= A.length &lt;= 1000</code></li>
	<li><code>0 &lt;= A[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：（双）滑动窗口

先first和先second的计算原理都是一样的，接下来先以“first + second”为例讨论这道题的解法。

这道题是在数组中选“firstLen”个连续元素，再在后面选“secondLen”个连续元素。

对于后面的“secondLen”个连续元素，我们可以使用一个滑动窗口，窗口大小固定未secondLen，每次窗口右移一个元素，就把窗口中的元素和更新（加上右边一个新元素，减去左边一个旧元素）

对于每次的窗口，我们可以知道这个窗口中的元素的和，即为“第二段子数组”的和。题目让求的，是第一段子数组和第二段子数组的和，因此，我们拿“当前窗口元素和”加上一个“左边长度为firstLen的子数组的最大和”，即为当前second窗口状态的最优解。

所有的最优解中的最优解即为答案。

怎么求左边所有长度为firstLen的子数组的最大和呢？我们同样使用一个滑动窗口来计算并更新即可。

```
0, 6, 5, 2, 2
-  ----
   second窗口

对于“second窗口”的“6 + 5”，加上“first窗口”的“0”为最优解
6 + 5 + 0 = 11
```

second窗口右移

```
0, 6, 5, 2, 2
   -  ----
      second窗口

对于“second窗口”的“5 + 2”，加上“first窗口”的“6”为最优解
5 + 2 + 6 = 13
```

second窗口右移

```
0, 6, 5, 2, 2
   -     ----
        second窗口

对于“second窗口”的“2 + 2”，加上“first窗口”的“6”为最优解
2 + 2 + 6 = 10

注意，此时虽然first窗口在“5”时为最佳，但这并不妨碍first窗口的同步右移。
这时first窗口其实已经右移到了5的位置，其中“6”仅仅是使用了一个变量记录了first窗口历史的最大和而已
```

因此最优解为$\max(11, 13, 10)=13$

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int calculate1(vector<int>& a, int ll, int lr) {  // a, len l, len r
        int sl = accumulate(a.begin(), a.begin() + ll, 0);  // sum l
        int sr = accumulate(a.begin() + ll, a.begin() + ll + lr, 0);  // sum r
        int ml = sl, ans = sl + sr;  // max l, ans
        for (int l = ll, r = ll + lr; r < a.size(); l++, r++) {
            sl = sl + a[l] - a[l - ll];
            sr = sr + a[r] - a[r - lr];
            ml = max(ml, sl);
            ans = max(ans, ml + sr);
        }
        return ans;
    }
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(calculate1(nums, firstLen, secondLen), calculate1(nums, secondLen, firstLen));
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2023-04-26 12:39:49
LastEditors: LetMeFly
LastEditTime: 2023-04-26 13:00:25
'''
# from typing import List

class Solution:
    def calculate1(self, a: List[int], ll: int, lr: int):
        sl = sum(a[i] for i in range(ll))
        sr = sum(a[i] for i in range(ll, ll + lr))
        ml = sl
        ans = ml + sr
        i, j = ll, ll + lr
        while j < len(a):
            sl = sl + a[i] - a[i - ll]
            sr = sr + a[j] - a[j - lr]
            ml = max(ml, sl)
            ans = max(ans, ml + sr)
            i, j = i + 1, j + 1
        return ans        
    
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        return max(self.calculate1(nums, firstLen, secondLen), self.calculate1(nums, secondLen, firstLen))
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/26/LeetCode%201031.%E4%B8%A4%E4%B8%AA%E9%9D%9E%E9%87%8D%E5%8F%A0%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130383831](https://letmefly.blog.csdn.net/article/details/130383831)
