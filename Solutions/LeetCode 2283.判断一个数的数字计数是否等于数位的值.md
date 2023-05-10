---
title: 2283.判断一个数的数字计数是否等于数位的值
date: 2023-01-11 22:57:46
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数, 遍历, 模拟]
---

# 【LetMeFly】2283.判断一个数的数字计数是否等于数位的值

力扣题目链接：[https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/](https://leetcode.cn/problems/check-if-number-has-equal-digit-count-and-digit-value/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的字符串&nbsp;<code>num</code>&nbsp;，它只包含数字。</p>

<p>如果对于 <strong>每个</strong><em>&nbsp;</em><code>0 &lt;= i &lt; n</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;，都满足数位<em>&nbsp;</em><code>i</code>&nbsp;在 <code>num</code>&nbsp;中出现了&nbsp;<code>num[i]</code>次，那么请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>num = "1210"
<b>输出：</b>true
<strong>解释：</strong>
num[0] = '1' 。数字 0 在 num 中出现了一次。
num[1] = '2' 。数字 1 在 num 中出现了两次。
num[2] = '1' 。数字 2 在 num 中出现了一次。
num[3] = '0' 。数字 3 在 num 中出现了零次。
"1210" 满足题目要求条件，所以返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>num = "030"
<b>输出：</b>false
<strong>解释：</strong>
num[0] = '0' 。数字 0 应该出现 0 次，但是在 num 中出现了一次。
num[1] = '3' 。数字 1 应该出现 3 次，但是在 num 中出现了零次。
num[2] = '0' 。数字 2 在 num 中出现了 0 次。
下标 0 和 1 都违反了题目要求，所以返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == num.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>num</code>&nbsp;只包含数字。</li>
</ul>


    
## 方法一：模拟

这道题我们按照题意进行模拟即可。

我们一共需要遍历两次原始字符串，第一次我们开辟一个大小为$10$的整型数组，初始值全部为$0$。

在第一次遍历字符串的时候，遇到一个字符，就将这个字符在数组中对应的位置加一。

```cpp
int cnt[10] = {0};
for (char c : num) {
    cnt[c - '0']++;
}
```

这样，在一次遍历之后，我们就知道了数组中每个数出现了几次。

接着进行第二次遍历，按照题意，判断```'i'```是否在```num```中出现了```num[i]```次。

遍历过程中一旦发现某值不成立，就返回```false```。若全部遍历完成后未返回```false```，则返回```true```。

```cpp
for (int i = 0; i < num.size(); i++) {
    if (cnt[i] != num[i] - '0')
        return false;
}
return true;
```

+ 时间复杂度$O(len(num))$
+ 空间复杂度$O(C)$，其中$C=10$，也可以认为空间复杂度是$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool digitCount(string& num) {
        int cnt[10] = {0};
        for (char c : num) {
            cnt[c - '0']++;
        }
        for (int i = 0; i < num.size(); i++) {
            if (cnt[i] != num[i] - '0')
                return false;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/01/11/LeetCode%202283.%E5%88%A4%E6%96%AD%E4%B8%80%E4%B8%AA%E6%95%B0%E7%9A%84%E6%95%B0%E5%AD%97%E8%AE%A1%E6%95%B0%E6%98%AF%E5%90%A6%E7%AD%89%E4%BA%8E%E6%95%B0%E4%BD%8D%E7%9A%84%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128652351](https://letmefly.blog.csdn.net/article/details/128652351)
