---
title: 2544.交替数字和
date: 2023-07-12 08:49:22
tags: [题解, LeetCode, 简单, 数学, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2544.交替数字和

力扣题目链接：[https://leetcode.cn/problems/alternating-digit-sum/](https://leetcode.cn/problems/alternating-digit-sum/)

<p>给你一个正整数 <code>n</code> 。<code>n</code> 中的每一位数字都会按下述规则分配一个符号：</p>

<ul>
	<li><strong>最高有效位</strong> 上的数字分配到 <strong>正</strong> 号。</li>
	<li>剩余每位上数字的符号都与其相邻数字相反。</li>
</ul>

<p>返回所有数字及其对应符号的和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 521
<strong>输出：</strong>4
<strong>解释：</strong>(+5) + (-2) + (+1) = 4</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 111
<strong>输出：</strong>1
<strong>解释：</strong>(+1) + (-1) + (+1) = 1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 886996
<strong>输出：</strong>0
<strong>解释：</strong>(+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>


    
## 方法一：模拟

首先将数字转为字符串，从下标0开始遍历字符串的每一位：

+ 如果当前下标是偶数，就加上这一位
+ 否则，就减去这一位（加上$-1\times 这一位$）

最终返回累加的和即可

+ 时间复杂度$O(\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += (i % 2 ? -1 : 1) * (s[i] - '0');
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def alternateDigitSum(self, n: int) -> int:
        s = str(n)
        return sum((-1 if i % 2 else 1) * (ord(s[i]) - ord('0')) for i in range(len(s)))
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/12/LeetCode%202544.%E4%BA%A4%E6%9B%BF%E6%95%B0%E5%AD%97%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131673485](https://letmefly.blog.csdn.net/article/details/131673485)
