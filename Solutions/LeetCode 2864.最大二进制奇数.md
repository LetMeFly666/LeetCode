---
title: 2864.最大二进制奇数
date: 2024-03-13 08:42:22
tags: [题解, LeetCode, 简单, 贪心, 数学, 字符串]
---

# 【LetMeFly】2864.最大二进制奇数：贪心（C++/Python的两行构造）

力扣题目链接：[https://leetcode.cn/problems/maximum-odd-binary-number/](https://leetcode.cn/problems/maximum-odd-binary-number/)

<p>给你一个 <strong>二进制</strong> 字符串 <code>s</code> ，其中至少包含一个 <code>'1'</code> 。</p>

<p>你必须按某种方式 <strong>重新排列</strong> 字符串中的位，使得到的二进制数字是可以由该组合生成的 <strong>最大二进制奇数</strong> 。</p>

<p>以字符串形式，表示并返回可以由给定组合生成的最大二进制奇数。</p>

<p><strong>注意 </strong>返回的结果字符串 <strong>可以</strong> 含前导零。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "010"
<strong>输出：</strong>"001"
<strong>解释：</strong>因为字符串 s 中仅有一个 '1' ，其必须出现在最后一位上。所以答案是 "001" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "0101"
<strong>输出：</strong>"1001"
<strong>解释：</strong>其中一个 '1' 必须出现在最后一位上。而由剩下的数字可以生产的最大数字是 "100" 。所以答案是 "1001" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由 <code>'0'</code> 和 <code>'1'</code> 组成</li>
	<li><code>s</code> 中至少包含一个 <code>'1'</code></li>
</ul>


    
## 方法一：贪心

两个条件：

1. 奇数：最后一位二进制为$1$
2. 尽可能大：所有$1$尽可能靠前

因此统计一下字符串```s```中有多少个$1$（假设有```cnt1```个），那么“```cnt1 - 1```个```1```、```len(s) - cnt1```个```0```、```1```个```1```”组成的字符串即为最大奇二进制字符串。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt1 = count(s.begin(), s.end(), '1');
        return string(cnt1 - 1, '1') + string(s.size() - cnt1, '0') + '1';
    }
};
```

#### Python

```python
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        cnt1 = sum(1 if c == '1' else 0 for c in s)
        return '1' * (cnt1 - 1) + '0' * (len(s) - cnt1) + '1'
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/13/LeetCode%202864.%E6%9C%80%E5%A4%A7%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%A5%87%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136669293](https://letmefly.blog.csdn.net/article/details/136669293)
