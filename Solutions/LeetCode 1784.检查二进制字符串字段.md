---
title: 1784.检查二进制字符串字段
date: 2022-10-03 10:54:43
tags: [题解, LeetCode, 简单, 字符串]
---

# 【LetMeFly】1784.检查二进制字符串字段

力扣题目链接：[https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/](https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/)

<p>给你一个二进制字符串 <code>s</code> ，该字符串 <strong>不含前导零</strong> 。</p>

<p>如果 <code>s</code> 包含 <strong>零个或一个由连续的 <code>'1'</code> 组成的字段</strong> ，返回 <code>true</code>​​​ 。否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "1001"
<strong>输出：</strong>false
<strong>解释：</strong>字符串中的 1 没有形成一个连续字段。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "110"
<strong>输出：</strong>true</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code>​​​​ 为 <code>'0'</code> 或 <code>'1'</code></li>
	<li><code>s[0]</code> 为 <code>'1'</code></li>
</ul>


    
## 方法一：统计连续的1的个数

使用连个变量：

+ cnt1：连续1的个数
+ lastIs1：上一个字符是否是1

初始值

+ cnt1 = 0
+ lastIs1 = 0

之后遍历字符串，如果上一个字符是0并且这个字符是1，那么“连续1”的个数加一。

记得遍历过程中更新lastIs1

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkOnesSegment(string& s) {
        int cnt1 = 0;
        bool lastIs1 = false;
        for (char& c : s) {
            if (c == '0') {
                lastIs1 = false;
            }
            else {
                if (!lastIs1) {
                    lastIs1 = true;
                    cnt1++;
                }
            }
        }
        return cnt1 < 2;
    }
};
```

## 方法二：查找“01”是否存在

这道题数据比较有意思：二进制串**不含前导零**

啥意思呢，意思就是二进制串第一个元素为1。

既然第一个元素为1，并且不能有“两块1”，那么就只能是数个之后全是0

一旦字符串中出现了“01”，就说明字符串中存在不只一个的“连续1”

因此，直接调用编程语言的API，查找字符串中是否存在“01”即可。

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkOnesSegment(string& s) {
        return s.find("01") == s.npos;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/03/LeetCode%201784.%E6%A3%80%E6%9F%A5%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%AD%97%E6%AE%B5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127150307](https://letmefly.blog.csdn.net/article/details/127150307)
