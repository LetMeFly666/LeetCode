---
title: 168.Excel表列名称
date: 2022-08-04 11:23:59
tags: [题解, LeetCode, 简单, 数学, 字符串, 模拟, 进制]
---

# 【LetMeFly】168.Excel表列名称

力扣题目链接：[https://leetcode.cn/problems/excel-sheet-column-title/](https://leetcode.cn/problems/excel-sheet-column-title/)

<p>给你一个整数 <code>columnNumber</code> ，返回它在 Excel 表中相对应的列名称。</p>

<p>例如：</p>

<pre>
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
</pre>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>columnNumber = 1
<strong>输出：</strong>"A"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>columnNumber = 28
<strong>输出：</strong>"AB"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>columnNumber = 701
<strong>输出：</strong>"ZY"
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>columnNumber = 2147483647
<strong>输出：</strong>"FXSHRXW"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= columnNumber <= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 方法一：模拟

详细的介绍可以参考我之前的一篇博客：[https://letmefly.blog.csdn.net/article/details/124512136](https://letmefly.blog.csdn.net/article/details/124512136)

有点类似十进制转二十六进制，但是Excel中列数是从1开始的而不是从0开始的。

也就是说0没有对应的字符。

如果是简单的进制转换，0应该对应字符A，但是这种情况下1对应字符A，因此在转换字符的每一位之前，把数字减去1即可。

+ 时间复杂度$O(\log_{26} columnNumber)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (--columnNumber >= 0) {
            ans = (char)(columnNumber % 26 + 'A') + ans;
            columnNumber /= 26;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/04/LeetCode%200168.Excel%E8%A1%A8%E5%88%97%E5%90%8D%E7%A7%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126156416](https://letmefly.blog.csdn.net/article/details/126156416)
