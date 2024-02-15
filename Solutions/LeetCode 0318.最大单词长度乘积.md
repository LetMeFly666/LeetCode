---
title: 318.最大单词长度乘积
date: 2023-11-06 20:01:05
tags: [题解, LeetCode, 中等, 位运算, 数组, 字符串, 模拟]
---

# 【LetMeFly】318.最大单词长度乘积

力扣题目链接：[https://leetcode.cn/problems/maximum-product-of-word-lengths/](https://leetcode.cn/problems/maximum-product-of-word-lengths/)

<p>给你一个字符串数组&nbsp;<code>words</code> ，找出并返回 <code>length(words[i]) * length(words[j])</code>&nbsp;的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 <code>0</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["abcw","baz","foo","bar","xtfn","abcdef"]</code>
<strong>输出：</strong><code>16 
<strong>解释</strong></code><strong>：</strong><code>这两个单词为<strong> </strong>"abcw", "xtfn"</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["a","ab","abc","d","cd","bcd","abcd"]</code>
<strong>输出：</strong><code>4 
<strong>解释</strong></code><strong>：</strong>这两个单词为 <code>"ab", "cd"</code>。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = <code>["a","aa","aaa","aaaa"]</code>
<strong>输出：</strong><code>0 
<strong>解释</strong></code><strong>：</strong><code>不存在这样的两个单词。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>words[i]</code>&nbsp;仅包含小写字母</li>
</ul>


    
## 方法一：模拟

对于一个单词（字符串），我们可以使用一个整数二进制下的低26位代表这个单词中出现过的字母。这个整数的低$i$位代表字母$i$是否出现过。

这样，对于两个单词是否有相同的字母，我们只需要看这两个单词对应的整数与运算的结果是否为$0$即可。

+ 时间复杂度$O(n^2\times L)$，其中$n=len(words)$
+ 空间复杂度$O(n)$

## 方法二：模拟+哈希表小优化

方法一中，我们需要遍历每一个单词对应的整数，以观察二者是否有相同的字母。

方法二中的小优化是：使用哈希表存储整数$mask$对应单词的最大长度。复杂度不变，但是对于出现的字母相同的所有单词，只会存储一次。

+ 时间复杂度$O(n^2\times L)$，其中$n=len(words)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int genMask(string& s) {
        int ans = 0;
        for (char c : s) {
            ans |= (1 << (c - 'a'));
        }
        return ans;
    }
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> ma;
        int ans = 0;
        for (string& s : words) {
            int mask = genMask(s);
            int length = s.size();
            for (auto&& [thatMask, thatLength] : ma) {
                if (!(mask & thatMask)) {
                    ans = max(ans, length * thatLength);
                }
            }
            ma[mask] = max(ma[mask], length);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def genMask(self, s: str) -> int:
        ans = 0
        for c in s:
            ans |= (1 << (ord(c) - ord('a')))
        return ans
    
    def maxProduct(self, words: List[str]) -> int:
        ma = defaultdict(int)
        ans = 0
        for s in words:
            mask, length = self.genMask(s), len(s)
            for key, val in ma.items():
                if not key & mask:
                    ans = max(ans, val * length)
            ma[mask] = max(ma[mask], length)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/06/LeetCode%200318.%E6%9C%80%E5%A4%A7%E5%8D%95%E8%AF%8D%E9%95%BF%E5%BA%A6%E4%B9%98%E7%A7%AF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134254146](https://letmefly.blog.csdn.net/article/details/134254146)
