---
title: 344.反转字符串
date: 2022-10-01 09:32:55
tags: [题解, LeetCode, 简单, 递归, 双指针, 字符串]
---

# 【LetMeFly】344.反转字符串

力扣题目链接：[https://leetcode.cn/problems/reverse-string/](https://leetcode.cn/problems/reverse-string/)

<p>编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 <code>s</code> 的形式给出。</p>

<p>不要给另外的数组分配额外的空间，你必须<strong><a href="https://baike.baidu.com/item/原地算法" target="_blank">原地</a>修改输入数组</strong>、使用 O(1) 的额外空间解决这一问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = ["h","e","l","l","o"]
<strong>输出：</strong>["o","l","l","e","h"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = ["H","a","n","n","a","h"]
<strong>输出：</strong>["h","a","n","n","a","H"]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 都是 <a href="https://baike.baidu.com/item/ASCII" target="_blank">ASCII</a> 码表中的可打印字符</li>
</ul>


    
## 方法一：模拟

用$i$从$0$到$\lfloor\frac{s.size()}{2}\rfloor$遍历字符串，并将这个遍历到的字符于字符串后半部分对应的字符交换。

主要是记得下标不要对应错就好

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/01/LeetCode%200344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127131770](https://letmefly.blog.csdn.net/article/details/127131770)
