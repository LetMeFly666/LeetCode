---
title: 1704.判断字符串的两半是否相似
date: 2022-11-11 09:01:33
tags: [题解, LeetCode, 简单, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】1704.判断字符串的两半是否相似：小难懂的代码

力扣题目链接：[https://leetcode.cn/problems/determine-if-string-halves-are-alike/](https://leetcode.cn/problems/determine-if-string-halves-are-alike/)

<p>给你一个偶数长度的字符串 <code>s</code> 。将其拆分成长度相同的两半，前一半为 <code>a</code> ，后一半为 <code>b</code> 。</p>

<p>两个字符串 <strong>相似</strong> 的前提是它们都含有相同数目的元音（<code>'a'</code>，<code>'e'</code>，<code>'i'</code>，<code>'o'</code>，<code>'u'</code>，<code>'A'</code>，<code>'E'</code>，<code>'I'</code>，<code>'O'</code>，<code>'U'</code>）。注意，<code>s</code> 可能同时含有大写和小写字母。</p>

<p>如果<em> </em><code>a</code><em> </em>和<em> </em><code>b</code> 相似，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "book"
<strong>输出：</strong>true
<strong>解释：</strong>a = "b<strong>o</strong>" 且 b = "<strong>o</strong>k" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "textbook"
<strong>输出：</strong>false
<strong>解释：</strong>a = "t<strong>e</strong>xt" 且 b = "b<strong>oo</strong>k" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
注意，元音 o 在 b 中出现两次，记为 2 个。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s.length</code> 是偶数</li>
	<li><code>s</code> 由 <strong>大写和小写</strong> 字母组成</li>
</ul>


    
## 方法一：计数

首先写一个函数判断**一个小写字母**是否未元音字母

```cpp
bool YuanYin(char c) {  // 只接受小写字母
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
```

然后用一个变量```cnt```记录“元音字母”的个数

遍历字符串，如果是前半个字符串，就让```cnt```加上“是否为元音字母”，否则就减去

```cpp
for (int i = 0; i < n; i++) {
    if (i < n / 2)
        cnt += YuanYin(tolower(s[i]));
    else
        cnt -= YuanYin(tolower(s[i]));
}
```

最后看cnt是否为0

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool YuanYin(char c) {  // 只接受小写字母
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    bool halvesAreAlike(string& s) {
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                cnt += YuanYin(tolower(s[i]));
            else
                cnt -= YuanYin(tolower(s[i]));
        }
        return !cnt;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/11/LeetCode%201704.%E5%88%A4%E6%96%AD%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E4%B8%A4%E5%8D%8A%E6%98%AF%E5%90%A6%E7%9B%B8%E4%BC%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127799858](https://letmefly.blog.csdn.net/article/details/127799858)
