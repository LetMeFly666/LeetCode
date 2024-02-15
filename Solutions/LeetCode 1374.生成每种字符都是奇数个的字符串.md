---
title: 1374.生成每种字符都是奇数个的字符串
date: 2022-08-01 08:20:21
tags: [题解, LeetCode, 简单, 字符串, 思维, 构造]
---

# 【LetMeFly】1374.生成每种字符都是奇数个的字符串

力扣题目链接：[https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts/](https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts/)

<p>给你一个整数 <code>n</code>，请你返回一个含<em> <code>n</code> </em>个字符的字符串，其中每种字符在该字符串中都恰好出现 <strong>奇数次</strong> <em><strong>。</strong></em></p>

<p>返回的字符串必须只含小写英文字母。如果存在多个满足题目要求的字符串，则返回其中任意一个即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>&quot;pppz&quot;
<strong>解释：</strong>&quot;pppz&quot; 是一个满足题目要求的字符串，因为 &#39;p&#39; 出现 3 次，且 &#39;z&#39; 出现 1 次。当然，还有很多其他字符串也满足题目要求，比如：&quot;ohhh&quot; 和 &quot;love&quot;。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>&quot;xy&quot;
<strong>解释：</strong>&quot;xy&quot; 是一个满足题目要求的字符串，因为 &#39;x&#39; 和 &#39;y&#39; 各出现 1 次。当然，还有很多其他字符串也满足题目要求，比如：&quot;ag&quot; 和 &quot;ur&quot;。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>&quot;holasss&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>


    
## 方法一：构造

+ 如果字符串的长度为奇数，那么字符串中每个字符都是```a```就能满足题目要求；
+ 如果字符串的长度为偶数($n$)，那么$n-1$为奇数，返回$n-1$个```a```和$1$个```b```就能满足题目要求。

(PS: 可使用语法糖——三木运算符 一行代码解决)

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string generateTheString(int n) {
        return n % 2 ? string(n, 'a') : string(n - 1, 'a') + 'b';
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/01/LeetCode%201374.%E7%94%9F%E6%88%90%E6%AF%8F%E7%A7%8D%E5%AD%97%E7%AC%A6%E9%83%BD%E6%98%AF%E5%A5%87%E6%95%B0%E4%B8%AA%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126093645](https://letmefly.blog.csdn.net/article/details/126093645)
