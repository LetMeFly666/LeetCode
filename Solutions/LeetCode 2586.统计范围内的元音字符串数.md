---
title: 2586.统计范围内的元音字符串数
date: 2023-11-07 22:28:39
tags: [题解, LeetCode, 简单, 数组, 字符串, 模拟]
---

# 【LetMeFly】2586.统计范围内的元音字符串数：模拟

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/](https://leetcode.cn/problems/count-the-number-of-vowel-strings-in-range/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 和两个整数：<code>left</code> 和 <code>right</code> 。</p>

<p>如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 <strong>元音字符串</strong> ，其中元音字母是 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code> 。</p>

<p>返回<em> </em><code>words[i]</code> 是元音字符串的数目，其中<em> </em><code>i</code> 在闭区间 <code>[left, right]</code> 内。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["are","amy","u"], left = 0, right = 2
<strong>输出：</strong>2
<strong>解释：</strong>
- "are" 是一个元音字符串，因为它以 'a' 开头并以 'e' 结尾。
- "amy" 不是元音字符串，因为它没有以元音字母结尾。
- "u" 是一个元音字符串，因为它以 'u' 开头并以 'u' 结尾。
在上述范围中的元音字符串数目为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
<strong>输出：</strong>3
<strong>解释：</strong>
- "aeo" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
- "mu" 不是元音字符串，因为它没有以元音字母开头。
- "ooo" 是一个元音字符串，因为它以 'o' 开头并以 'o' 结尾。
- "artro" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
在上述范围中的元音字符串数目为 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
	<li><code>0 &lt;= left &lt;= right &lt; words.length</code></li>
</ul>


    
## 方法一：模拟

可以写一个函数```can(c)```用来判断字符```c```是否为元音字符。

接着从```left```到```right```遍历```words```数组，如果这个单词的第一个字母和最后一个字母都是元音字母（```can```），则累加。

+ 时间复杂度$O(right - left)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    inline int can(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int vowelStrings(vector<string>& words, int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += can(words[i][0]) && can(words[i].back());
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def can(self, c: str) -> bool:
        return c in 'aeiou'
    
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        return sum(self.can(words[i][0]) and self.can(words[i][-1]) for i in range(left, right + 1))
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/07/LeetCode%202586.%E7%BB%9F%E8%AE%A1%E8%8C%83%E5%9B%B4%E5%86%85%E7%9A%84%E5%85%83%E9%9F%B3%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134277884](https://letmefly.blog.csdn.net/article/details/134277884)
