---
title: 2438.二的幂数组中查询范围内的乘积：模拟(前缀和可选)
date: 2025-08-11 21:48:30
tags: [题解, LeetCode, 中等, 位运算, 数组, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】2438.二的幂数组中查询范围内的乘积：模拟(前缀和可选)

力扣题目链接：[https://leetcode.cn/problems/range-product-queries-of-powers/](https://leetcode.cn/problems/range-product-queries-of-powers/)

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，你需要找到一个下标从&nbsp;<strong>0</strong>&nbsp;开始的数组&nbsp;<code>powers</code>&nbsp;，它包含 <strong>最少</strong>&nbsp;数目的 <code>2</code>&nbsp;的幂，且它们的和为&nbsp;<code>n</code>&nbsp;。<code>powers</code>&nbsp;数组是&nbsp;<strong>非递减</strong>&nbsp;顺序的。根据前面描述，构造&nbsp;<code>powers</code>&nbsp;数组的方法是唯一的。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;，其中&nbsp;<code>queries[i]</code>&nbsp;表示请你求出满足&nbsp;<code>left<sub>i</sub> &lt;= j &lt;= right<sub>i</sub></code>&nbsp;的所有&nbsp;<code>powers[j]</code>&nbsp;的乘积。</p>

<p>请你返回一个数组<em>&nbsp;</em><code>answers</code>&nbsp;，长度与<em>&nbsp;</em><code>queries</code>&nbsp;的长度相同，其中<em>&nbsp;</em><code>answers[i]</code>是第<em>&nbsp;</em><code>i</code>&nbsp;个查询的答案。由于查询的结果可能非常大，请你将每个&nbsp;<code>answers[i]</code>&nbsp;都对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 15, queries = [[0,1],[2,2],[0,3]]
<b>输出：</b>[2,4,64]
<strong>解释：</strong>
对于 n = 15 ，得到 powers = [1,2,4,8] 。没法得到元素数目更少的数组。
第 1 个查询的答案：powers[0] * powers[1] = 1 * 2 = 2 。
第 2 个查询的答案：powers[2] = 4 。
第 3 个查询的答案：powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64 。
每个答案对 10<sup>9</sup> + 7 得到的结果都相同，所以返回 [2,4,64] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 2, queries = [[0,0]]
<b>输出：</b>[2]
<strong>解释：</strong>
对于 n = 2, powers = [2] 。
唯一一个查询的答案是 powers[0] = 2 。答案对 10<sup>9</sup> + 7 取余后结果相同，所以返回 [2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt; powers.length</code></li>
</ul>


    
## 解题方法：模拟

**如何将$n$拆成递增的2的幂组成的数组powers**

很简单，$n$二进制下哪一位(记为$i$)是$1$就将$1\lt \lt i$按顺序加入powers数组。

**对于一个query如何求出对应answer**

两种方法：

1. 直接暴力从query[0]累乘到query[1]并随时取模
2. 前缀和的思想，使用数组prefix[j]代表$\prod_{0}^{j-1}powers[i]$

直接暴力的方法并不会很耗时，因为powers数组中最多30个元素；

前缀和的思想适用于Python这种自带大整数的编程语言，否则取模后的相除还需要取逆元。

### 时空复杂度分析

暴力：

+ 时间复杂度$O(\log n\times len(queries))$
+ 空间复杂度$O(\log n)$

前缀和

+ 时间复杂度$O(\log n + len(queries))$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-11 18:41:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-11 21:43:41
 */
typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pows;
        int th = 0;
        while (n) {
            if (n & 1) {
                pows.push_back(1 << th);
            }
            n >>= 1;
            th++;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ll thisVal = 1;
            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
                thisVal = thisVal * pows[j] % MOD;
            }
            ans[i] = thisVal;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-11 21:37:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-11 21:46:52
'''
from typing import List

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        pows = []
        th = 0
        while n:
            if n & 1:
                pows.append(1 << th)
            th += 1
            n >>= 1
        prefix = [1] * (len(pows) + 1)
        for i in range(1, len(pows) + 1):
            prefix[i] = prefix[i - 1] * pows[i - 1]
        return [prefix[q[1] + 1] // prefix[q[0]] % 1000000007 for q in queries]
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150227536)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/11/LeetCode%202438.%E4%BA%8C%E7%9A%84%E5%B9%82%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E8%AF%A2%E8%8C%83%E5%9B%B4%E5%86%85%E7%9A%84%E4%B9%98%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
