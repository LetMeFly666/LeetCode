---
title: 1796.字符串中第二大的数字
date: 2022-12-03 12:24:32
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 遍历]
---

# 【LetMeFly】1796.字符串中第二大的数字

力扣题目链接：[https://leetcode.cn/problems/second-largest-digit-in-a-string/](https://leetcode.cn/problems/second-largest-digit-in-a-string/)

<p>给你一个混合字符串 <code>s</code> ，请你返回 <code>s</code> 中 <strong>第二大 </strong>的数字，如果不存在第二大的数字，请你返回 <code>-1</code> 。</p>

<p><strong>混合字符串 </strong>由小写英文字母和数字组成。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "dfa12321afd"
<b>输出：</b>2
<b>解释：</b>出现在 s 中的数字包括 [1, 2, 3] 。第二大的数字是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abc1111"
<b>输出：</b>-1
<b>解释：</b>出现在 s 中的数字只包含 [1] 。没有第二大的数字。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 500</code></li>
	<li><code>s</code> 只包含小写英文字母和（或）数字。</li>
</ul>


    
## 方法一：遍历

### 题目分析

题目中说的“第二大”数字，到底什么是第二大？英文原文是“Second largest”

也就是说，是从大到小第二个数，不是从小到大第二个数。

样例中“123”，不论是从小到大还是从大到小都是“2”，不如把样例换成“1234”，这样答案是“3”，就一目了然了。

### 解题思路

首先开辟一个大小为“10”的布尔数组，初始值为```false```

接着遍历字符串，如果字符串的某个字符是数字，那么就将对应的那个布尔值标记为```true```

接着，用一个变量```foundFirst```来记录是否已经找到了最大值，初始值为```false```

从```9```到```0```遍历布尔数组，如果遇到某个值为```true```，就看```foundFirst```是否已经为```true```

+ 如果为```true```，就返回当前的对应元素
+ 否则，将```foundFirst```标记为```true```

若遍历结束后仍未找到“第二大数”，那么就返回```-1```

### 复杂度分析

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(C)$，这里$C=10$，也可以理解为$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int secondHighest(string& s) {
        bool bin[10] = {false};
        for (char c : s) {
            if (c >= '0' && c <= '9')
                bin[c - '0'] = true;
        }
        bool foundFirst = false;
        for (int i = 9; i >= 0; i--) {
            if (bin[i]) {
                if (foundFirst) {
                    return i;
                }
                else {
                    foundFirst = true;
                }
            }
        }
        return -1;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/03/LeetCode%201796.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%AC%AC%E4%BA%8C%E5%A4%A7%E7%9A%84%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128160774](https://letmefly.blog.csdn.net/article/details/128160774)
