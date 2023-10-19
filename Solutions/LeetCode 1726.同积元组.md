---
title: 1726.同积元组
date: 2023-10-19 10:21:24
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map]
---

# 【LetMeFly】1726.同积元组：哈希表（组合数学）

力扣题目链接：[https://leetcode.cn/problems/tuple-with-same-product/](https://leetcode.cn/problems/tuple-with-same-product/)

<p>给你一个由 <strong>不同</strong> 正整数组成的数组 <code>nums</code> ，请你返回满足&nbsp;<code>a * b = c * d</code> 的元组<em> </em><code>(a, b, c, d)</code><em> </em>的数量。其中 <code>a</code>、<code>b</code>、<code>c</code> 和 <code>d</code> 都是 <code>nums</code> 中的元素，且 <code>a != b != c != d</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,4,6]
<strong>输出：</strong>8
<strong>解释：</strong>存在 8 个满足题意的元组：
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,5,10]
<strong>输出：</strong>16
<strong>解释：</strong>存在 16 个满足题意的元组：
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 中的所有元素 <strong>互不相同</strong></li>
</ul>


    
## 方法一：哈希表（组合数学）

本题的数据量为$10^3$，大约可以在$O(n^2)$的时间复杂度内解决。

因此我们只需要预先两层遍历一下nums数组，将所有的两数之积出现的次数统计出来并放入哈希表中。这样，对于两数之积$k$，我们可以通过哈希表在$O(1)$的时间复杂度内得到两数之积为$k$的数对的个数。

最后就是组合数学的问题了。对于两数之积$k$，有多少个$(a,b,c,d)$使得$a\times b=k=c\times d\ ①$呢？

> 假设有$v$个“两数之积”等于$k$，那么我们可以先从这$v$个数对中选出两个（$A_v^2$），分别放在等式$①$的左边和右边（$a_1\times b_1=a_2\times b_2$）。然后对于$a_1$和$b_1$，有两种顺序（$(a_1, b_1)$和$(b_1, a_1)$），$a_2,b_2$也有两种顺序。也就是说，对于$a_1\times b_1=a_2\times b_2$，一共有$2\times2=4$种顺序（$a_1,b_1,a_2,b_2$、$b_1,a_1,a_2,b_2$、$a_1,b_1,b_2,a_2$、$b_1,a_1,b_2,a_2$）。
>
> 也就是说，如果有$v$个两数之积等于$k$，那么有$A_v^2\times 4$种“```(a, b, c, d)```”四元组使得$a\times b=c\times d$。

对于所有的$k$，累加上式即可。

+ 时间复杂度$O(len(nums)^2)$
+ 空间复杂度$O(len(nums)^2)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> ma;
        for (int i =  0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ma[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto&& [k, v] : ma) {
            ans += v * (v - 1) * 4;
        }
        return ans;
    }
};
```

#### Python

皮一下：

```python
# from collections import Counter
# from typing import List

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        return sum([v * (v - 1) * 4 for _, v in Counter([nums[i] * nums[j] for i in range(len(nums)) for j in range(i + 1, len(nums))]).items()])
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/10/19/LeetCode%201726.%E5%90%8C%E7%A7%AF%E5%85%83%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133921549](https://letmefly.blog.csdn.net/article/details/133921549)
