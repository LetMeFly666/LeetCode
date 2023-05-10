---
title: 791.自定义字符串排序
date: 2022-11-13 10:25:35
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 排序]
---

# 【LetMeFly】791.自定义字符串排序

力扣题目链接：[https://leetcode.cn/problems/custom-sort-string/](https://leetcode.cn/problems/custom-sort-string/)

<p>给定两个字符串 <code>order</code> 和 <code>s</code> 。<code>order</code> 的所有单词都是 <strong>唯一</strong> 的，并且以前按照一些自定义的顺序排序。</p>

<p>对 <code>s</code> 的字符进行置换，使其与排序的&nbsp;<code>order</code>&nbsp;相匹配。更具体地说，如果在&nbsp;<code>order</code>&nbsp;中的字符 <code>x</code> 出现字符 <code>y</code> 之前，那么在排列后的字符串中， <code>x</code>&nbsp;也应该出现在 <code>y</code> 之前。</p>

<p>返回 <em>满足这个性质的 <code>s</code> 的任意排列&nbsp;</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> order = "cba", s = "abcd"
<strong>输出:</strong> "cbad"
<strong>解释:</strong> 
“a”、“b”、“c”是按顺序出现的，所以“a”、“b”、“c”的顺序应该是“c”、“b”、“a”。
因为“d”不是按顺序出现的，所以它可以在返回的字符串中的任何位置。“dcba”、“cdba”、“cbda”也是有效的输出。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> order = "cbafg", s = "abcd"
<strong>输出:</strong> "cbad"
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= order.length &lt;= 26</code></li>
	<li><code>1 &lt;= s.length &lt;= 200</code></li>
	<li><code>order</code>&nbsp;和&nbsp;<code>s</code>&nbsp;由小写英文字母组成</li>
	<li><code>order</code>&nbsp;中的所有字符都 <strong>不同</strong></li>
</ul>


    
## 方法一：自定义排序规则

$order$中未出现过的元素不需考虑，只需要给出现过的元素编个号。

使用数组$char2th[26]$来记录26个字母的出现顺序

对于$order$中出现过的字母，我们更新其出现位置$char2th$；对于$order$中未出现过的字母，我们无需考虑其在$char2th$中的值

在排序的时候，我们以字母在$char2th$中的大小为原则进行排序即可。

+ 时间复杂度$O(L1 + L2\log L2)$，其中$L1 = len(order), L2 = len(s)$
+ 空间复杂度$O(C + \log L2)$

### AC代码

#### C++

```cpp
int char2th[26];

bool cmp(const char& a, const char& b) {
    return char2th[a - 'a'] < char2th[b - 'a'];
}

class Solution {
private:
    void init(string& order) {
        for (int i = order.size() - 1; i >= 0; i--)
            char2th[order[i] - 'a'] = i;
    }
public:
    string customSortString(string& order, string& s) {
        init(order);
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
```

![result.png](https://img-blog.csdnimg.cn/22d9bf14b5d84e8ca34af6ec8de954b7.png#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/13/LeetCode%200791.%E8%87%AA%E5%AE%9A%E4%B9%89%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%8E%92%E5%BA%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127829276](https://letmefly.blog.csdn.net/article/details/127829276)
