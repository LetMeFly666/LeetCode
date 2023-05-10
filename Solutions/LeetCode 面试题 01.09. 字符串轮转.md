---
title: 面试题 01.09. 字符串轮转
date: 2022-09-29 12:21:20
tags: [题解, LeetCode, 简单, 字符串, 字符串匹配]
---

# 【LetMeFly】面试题 01.09.字符串轮转

力扣题目链接：[https://leetcode.cn/problems/string-rotation-lcci/](https://leetcode.cn/problems/string-rotation-lcci/)

<p>字符串轮转。给定两个字符串<code>s1</code>和<code>s2</code>，请编写代码检查<code>s2</code>是否为<code>s1</code>旋转而成（比如，<code>waterbottle</code>是<code>erbottlewat</code>旋转后的字符串）。</p>

<p><strong>示例1:</strong></p>

<pre><strong> 输入</strong>：s1 = &quot;waterbottle&quot;, s2 = &quot;erbottlewat&quot;
<strong> 输出</strong>：True
</pre>

<p><strong>示例2:</strong></p>

<pre><strong> 输入</strong>：s1 = &quot;aa&quot;, s2 = &quot;aba&quot;
<strong> 输出</strong>：False
</pre>

<ol>
</ol>

<p><strong>提示：</strong></p>

<ol>
	<li>字符串长度在[0, 100000]范围内。</li>
</ol>

<p><strong>说明:</strong></p>

<ol>
	<li>你能只调用一次检查子串的方法吗？</li>
</ol>




## 方法一：倍增字符串

首先如果两个字符串不等长，那么直接返回false

否则就将一个字符串复制一份，abc变成abcabc，然后直接调用内置的find函数，查找第二个字符串是否是第一个字符串“倍增”后的子串

+ 时间复杂度$O(n)$，其中$n$是第一个字符串的长度。（KMP 算法搜索子字符串的时间复杂度为 $O(n)$）
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isFlipedString(string& s1, string& s2) {
        if (s1.size() != s2.size())
            return false;
        return (s1 + s1).find(s2) != string::npos;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/29/LeetCode%20%E9%9D%A2%E8%AF%95%E9%A2%98%2001.09.%20%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%BD%AE%E8%BD%AC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127104669](https://letmefly.blog.csdn.net/article/details/127104669)
