---
title: 982.按位与为零的三元组
date: 2023-03-04 14:31:39
tags: [题解, LeetCode, 困难, 位运算, 数组, 哈希表, 哈希]
---

# 【LetMeFly】982.按位与为零的三元组

力扣题目链接：[https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/)

<p>给定一个整数数组&nbsp;<code>A</code>，找出索引为 (i, j, k) 的三元组，使得：</p>

<ul>
	<li><code>0 &lt;= i &lt; A.length</code></li>
	<li><code>0 &lt;= j &lt; A.length</code></li>
	<li><code>0 &lt;= k &lt; A.length</code></li>
	<li><code>A[i]&nbsp;&amp; A[j]&nbsp;&amp; A[k] == 0</code>，其中&nbsp;<code>&amp;</code>&nbsp;表示按位与（AND）操作符。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>[2,1,3]
<strong>输出：</strong>12
<strong>解释：</strong>我们可以选出如下 i, j, k 三元组：
(i=0, j=0, k=1) : 2 &amp; 2 &amp; 1
(i=0, j=1, k=0) : 2 &amp; 1 &amp; 2
(i=0, j=1, k=1) : 2 &amp; 1 &amp; 1
(i=0, j=1, k=2) : 2 &amp; 1 &amp; 3
(i=0, j=2, k=1) : 2 &amp; 3 &amp; 1
(i=1, j=0, k=0) : 1 &amp; 2 &amp; 2
(i=1, j=0, k=1) : 1 &amp; 2 &amp; 1
(i=1, j=0, k=2) : 1 &amp; 2 &amp; 3
(i=1, j=1, k=0) : 1 &amp; 1 &amp; 2
(i=1, j=2, k=0) : 1 &amp; 3 &amp; 2
(i=2, j=0, k=1) : 3 &amp; 2 &amp; 1
(i=2, j=1, k=0) : 3 &amp; 1 &amp; 2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 1000</code></li>
	<li><code>0 &lt;= A[i] &lt; 2^16</code></li>
</ol>


    
## 方法一：哈希表

三个数的“与”，要是三层循环肯定超时。

能降低到两层循环吗？当然可以。这道题$nums[i]$的范围是$[0, 2^{16})$，而$2^{16}=65536$，不是很大的一个数

也就是说$nums[i] \& nums[j]$的范围也就是$[0, 65536)$

因此我们可以提前计算出$nums[i] \& nums[j]$共有多少种，以及每种有多少个，存入到哈希表（或数组）中

接下来我们第一层遍历$nums$中的所有数字，第二层遍历哈希表中的所有数字（也就是两数的与），如果结果为0就累加到答案中。

+ 时间复杂度$O(len(nums)^2 + C\times(len(nums)))$，其中$C=2^{16}$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> two(1 << 16);
        for (int& a : nums) {
            for (int& b : nums) {
                two[a & b]++;
            }
        }
        int ans = 0;
        for (int& one : nums) {
            for (int mask = 0; mask < (1 << 16); mask++) {
                if ((one & mask) == 0) {
                    ans += two[mask];
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from collections import Counter
# from typing import List

class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        two = Counter((x & y) for x in nums for y in nums)
        ans = 0
        for one in nums:
            for mask, times in two.items():
                if (one & mask) == 0:
                    ans += times
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/04/LeetCode%200982.%E6%8C%89%E4%BD%8D%E4%B8%8E%E4%B8%BA%E9%9B%B6%E7%9A%84%E4%B8%89%E5%85%83%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129334313](https://letmefly.blog.csdn.net/article/details/129334313)
