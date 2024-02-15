---
title: 2309.兼具大小写的最好英文字母
date: 2023-01-27 10:07:55
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 枚举, 哈希, 遍历]
---

# 【LetMeFly】2309.兼具大小写的最好英文字母

力扣题目链接：[https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/](https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/)

<p>给你一个由英文字母组成的字符串 <code>s</code> ，请你找出并返回 <code>s</code> 中的 <strong>最好</strong> 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。</p>

<p><strong>最好</strong> 英文字母的大写和小写形式必须 <strong>都</strong> 在 <code>s</code> 中出现。</p>

<p>英文字母 <code>b</code> 比另一个英文字母&nbsp;<code>a</code>&nbsp;<strong>更好</strong> 的前提是：英文字母表中，<code>b</code> 在 <code>a</code> 之 <strong>后</strong> 出现。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "l<em><strong>Ee</strong></em>TcOd<em><strong>E</strong></em>"
<strong>输出：</strong>"E"
<strong>解释：</strong>
字母 'E' 是唯一一个大写和小写形式都出现的字母。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a<em><strong>rR</strong></em>AzFif"
<strong>输出：</strong>"R"
<strong>解释：</strong>
字母 'R' 是大写和小写形式都出现的最好英文字母。
注意 'A' 和 'F' 的大写和小写形式也都出现了，但是 'R' 比 'F' 和 'A' 更好。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "AbCdEfGhIjK"
<strong>输出：</strong>""
<strong>解释：</strong>
不存在大写和小写形式都出现的字母。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 由小写和大写英文字母组成</li>
</ul>


    
## 方法一：哈希

思路很简单，从```zZ```开始往前[遍历](https://blog.letmefly.xyz/tags/%E9%81%8D%E5%8E%86/)到```aA```，如果其中某个字母的大小写```xX```均出现在[字符串](https://blog.letmefly.xyz/tags/%E5%AD%97%E7%AC%A6%E4%B8%B2/)中，则返回这个字母的大写形式```X```

因此，我们建立一个[哈希表](https://blog.letmefly.xyz/tags/%E5%93%88%E5%B8%8C%E8%A1%A8/)，首先将[字符串](https://blog.letmefly.xyz/tags/%E5%AD%97%E7%AC%A6%E4%B8%B2/)中出现过的字母存入[哈希表](https://blog.letmefly.xyz/tags/%E5%93%88%E5%B8%8C%E8%A1%A8/)中，以便快速判断一个字母是否在[字符串](https://blog.letmefly.xyz/tags/%E5%AD%97%E7%AC%A6%E4%B8%B2/)中出现

接着开始从后往前[枚举](https://blog.letmefly.xyz/tags/%E6%9E%9A%E4%B8%BE/)字母（的大小写），若某个字母的大小写都在[字符串](https://blog.letmefly.xyz/tags/%E5%AD%97%E7%AC%A6%E4%B8%B2/)中出现过（也就是说[哈希](https://blog.letmefly.xyz/tags/%E5%93%88%E5%B8%8C/)表中存在），就返回这个字母。

若[枚举](https://blog.letmefly.xyz/tags/%E6%9E%9A%E4%B8%BE/)结束未返回，则返回空[字符串](https://blog.letmefly.xyz/tags/%E5%AD%97%E7%AC%A6%E4%B8%B2/)。

+ 时间复杂度$O(C + len(s))$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> se(s.begin(), s.end());
        for (int i = 25; i >= 0; i--) {
            if (se.count('a' + i) && se.count('A' + i)) {
                return string(1, 'A' + i);
            }
        }
        return "";
    }
};
```

#### Python

**方法一**

```python
class Solution:
    def greatestLetter(self, s: str) -> str:
        se = set(s)
        for i in range(25, -1, -1):
            if chr(ord('a') + i) in se and chr(ord('A') + i) in se:
                return chr(ord('A') + i)
        return ""
```

**方法二**（类似方法一）

```python
# from string import ascii_lowercase, ascii_uppercase

class Solution:
    def greatestLetter(self, s: str) -> str:
        se = set(s)
        for lower, upper in zip(reversed(ascii_lowercase), reversed(ascii_uppercase)):
            if lower in se and upper in se:
                return upper
        return ""
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/27/LeetCode%202309.%E5%85%BC%E5%85%B7%E5%A4%A7%E5%B0%8F%E5%86%99%E7%9A%84%E6%9C%80%E5%A5%BD%E8%8B%B1%E6%96%87%E5%AD%97%E6%AF%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128769360](https://letmefly.blog.csdn.net/article/details/128769360)
