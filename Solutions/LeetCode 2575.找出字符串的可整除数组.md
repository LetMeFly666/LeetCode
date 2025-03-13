---
title: 2575.找出字符串的可整除数组
date: 2024-03-07 20:05:33
tags: [题解, LeetCode, 中等, 数组, 数学, 字符串, 同余]
categories: [题解, LeetCode]
---

# 【LetMeFly】2575.找出字符串的可整除数组：同余问题

力扣题目链接：[https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/](https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>word</code> ，长度为 <code>n</code> ，由从 <code>0</code> 到 <code>9</code> 的数字组成。另给你一个正整数 <code>m</code> 。</p>

<p><code>word</code> 的 <strong>可整除数组</strong> <code>div</code>&nbsp; 是一个长度为 <code>n</code> 的整数数组，并满足：</p>

<ul>
	<li>如果 <code>word[0,...,i]</code> 所表示的 <strong>数值</strong> 能被 <code>m</code> 整除，<code>div[i] = 1</code></li>
	<li>否则，<code>div[i] = 0</code></li>
</ul>

<p>返回<em> </em><code>word</code> 的可整除数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "998244353", m = 3
<strong>输出：</strong>[1,1,0,0,0,1,1,0,0]
<strong>解释：</strong>仅有 4 个前缀可以被 3 整除："9"、"99"、"998244" 和 "9982443" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "1010", m = 10
<strong>输出：</strong>[0,1,0,1]
<strong>解释：</strong>仅有 2 个前缀可以被 10 整除："10" 和 "1010" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>word.length == n</code></li>
	<li><code>word</code> 由数字 <code>0</code> 到 <code>9</code> 组成</li>
	<li><code>1 &lt;= m &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：同余问题

解决这道题只需要知道一个公式：$(a\times b+c)\% m=((a\%m)\times(b\%m)+(c\%m))\%m=((a\%m)\times b+c)\%m$。

也就是说，$(a\times 10+c)\% m=((a\%m)+c)\%m$。

初始值$val=0$，遍历字符串，每次$val = (val\times10+word[i])\%m$，并将其是否非零记录下来即可。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size());
        long long val = 0;
        for (int i = 0; i < word.size(); i++) {
            val = val * 10 + (word[i] - '0');
            val %= m;
            ans[i] = val == 0;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:  # AC,100.00%,78.26%
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        ans = [0] * len(word)
        val = 0
        for i in range(len(word)):
            val = val * 10 + (ord(word[i]) - ord('0'))
            val %= m
            ans[i] = 0 if val else 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/07/LeetCode%202575.%E6%89%BE%E5%87%BA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%8F%AF%E6%95%B4%E9%99%A4%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136544808](https://letmefly.blog.csdn.net/article/details/136544808)
