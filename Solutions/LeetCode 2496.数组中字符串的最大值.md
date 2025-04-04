---
title: 2496.数组中字符串的最大值
date: 2023-06-23 07:58:37
tags: [题解, LeetCode, 简单, 数组, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2496.数组中字符串的最大值

力扣题目链接：[https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/](https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/)

<p>一个由字母和数字组成的字符串的 <strong>值</strong>&nbsp;定义如下：</p>

<ul>
	<li>如果字符串 <strong>只</strong> 包含数字，那么值为该字符串在 <code>10</code>&nbsp;进制下的所表示的数字。</li>
	<li>否则，值为字符串的 <strong>长度&nbsp;</strong>。</li>
</ul>

<p>给你一个字符串数组&nbsp;<code>strs</code>&nbsp;，每个字符串都只由字母和数字组成，请你返回 <code>strs</code>&nbsp;中字符串的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["alic3","bob","3","4","00000"]
<b>输出：</b>5
<b>解释：</b>
- "alic3" 包含字母和数字，所以值为长度 5 。
- "bob" 只包含字母，所以值为长度 3 。
- "3" 只包含数字，所以值为 3 。
- "4" 只包含数字，所以值为 4 。
- "00000" 只包含数字，所以值为 0 。
所以最大的值为 5 ，是字符串 "alic3" 的值。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>strs = ["1","01","001","0001"]
<b>输出：</b>1
<b>解释：</b>
数组中所有字符串的值都是 1 ，所以我们返回 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 9</code></li>
	<li><code>strs[i]</code>&nbsp;只包含小写英文字母和数字。</li>
</ul>


    
## 方法一：模拟

我们只需要按照题目要求进行模拟即可。

为了方便，可以写一个函数，用来返回一个字符串的“值”。

字符串的初始值为$ans = 0$，从头到尾开始遍历字符串，一旦遇到非数字字符，就直接返回字符串的长度作为字符串的值；

否则，遍历过程中，每次将字符串的值ans修改为$ans * 10 + c$，最终返回ans即可。

+ 时间复杂度$O(N)$，其中$N$是所有字符串的字符总个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int value(string& s) {
        int ans = 0;
        for (char c : s) {
            if (c < '0' || c > '9') {
                return s.size();
            }
            ans = ans * 10 + c - '0';
        }
        return ans;
    }
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (string& s : strs) {
            ans = max(ans, value(s));
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def value(self, s: str) -> int:
        ans = 0
        for c in s:
            if ord(c) < ord('0') or ord(c) > ord('9'):
                return len(s)
            ans = ans * 10 + ord(c) - ord('0')
        return ans

    def maximumValue(self, strs: List[str]) -> int:
        ans = 0
        for str in strs:
            ans = max(ans, self.value(str))
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/23/LeetCode%202496.%E6%95%B0%E7%BB%84%E4%B8%AD%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%A4%A7%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131347121](https://letmefly.blog.csdn.net/article/details/131347121)
