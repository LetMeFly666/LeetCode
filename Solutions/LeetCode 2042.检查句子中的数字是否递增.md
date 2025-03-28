---
title: 2042.检查句子中的数字是否递增
date: 2023-01-03 19:19:59
tags: [题解, LeetCode, 简单, 字符串, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2042.检查句子中的数字是否递增

力扣题目链接：[https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/](https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/)

<p>句子是由若干 <strong>token</strong> 组成的一个列表，<strong>token</strong> 间用 <strong>单个</strong> 空格分隔，句子没有前导或尾随空格。每个 token 要么是一个由数字 <code>0-9</code> 组成的不含前导零的 <strong>正整数</strong>&nbsp;，要么是一个由小写英文字母组成的 <strong>单词</strong> 。</p>

<ul>
	<li>示例，<code>"a puppy has 2 eyes 4 legs"</code> 是一个由 7 个 token 组成的句子：<code>"2"</code> 和 <code>"4"</code> 是数字，其他像&nbsp;<code>"puppy"</code> 这样的 tokens 属于单词。</li>
</ul>

<p>给你一个表示句子的字符串 <code>s</code> ，你需要检查 <code>s</code> 中的 <strong>全部</strong> 数字是否从左到右严格递增（即，除了最后一个数字，<code>s</code> 中的 <strong>每个</strong> 数字都严格小于它 <strong>右侧</strong> 的数字）。</p>

<p>如果满足题目要求，返回 <code>true</code>&nbsp;，否则，返回<em> </em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="example-1" src="https://assets.leetcode.com/uploads/2021/09/30/example1.png" style="width: 637px; height: 48px;" /></p>

<pre>
<strong>输入：</strong>s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
<strong>输出：</strong>true
<strong>解释：</strong>句子中的数字是：1, 3, 4, 6, 12 。
这些数字是按从左到右严格递增的 1 &lt; 3 &lt; 4 &lt; 6 &lt; 12 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "hello world 5 x 5"
<strong>输出：</strong>false
<strong>解释：</strong>句子中的数字是：<em><strong>5</strong></em>, <strong><em>5</em></strong> 。这些数字不是严格递增的。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="example-3" src="https://assets.leetcode.com/uploads/2021/09/30/example3.png" style="width: 794px; height: 48px;" /></p>

<pre>
<strong>输入：</strong>s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
<strong>输出：</strong>false
<strong>解释：</strong>s 中的数字是：7, <em><strong>51</strong></em>, <em><strong>50</strong></em>, 60 。这些数字不是严格递增的。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "4 5 11 26"
<strong>输出：</strong>true
<strong>解释：</strong>s 中的数字是：4, 5, 11, 26 。
这些数字是按从左到右严格递增的：4 &lt; 5 &lt; 11 &lt; 26 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 200</code></li>
	<li><code>s</code> 由小写英文字母、空格和数字 <code>0</code> 到 <code>9</code> 组成（包含 <code>0</code> 和 <code>9</code>）</li>
	<li><code>s</code> 中数字 token 的数目在 <code>2</code> 和 <code>100</code> 之间（包含 <code>2</code> 和 <code>100</code>）</li>
	<li><code>s</code> 中的 token 之间由单个空格分隔</li>
	<li><code>s</code> 中至少有 <strong>两个</strong> 数字</li>
	<li><code>s</code> 中的每个数字都是一个 <strong>小于</strong> <code>100</code> 的 <strong>正</strong> 数，且不含前导零</li>
	<li><code>s</code> 不含前导或尾随空格</li>
</ul>


    
## 方法一：遍历

用一个整型变量```lastVal```记录上一个“数字token”是多少，初始值是“极小值”```0```

用一个整型变量```thisVal```记录当前遍历到的“数字token”，若当前遍历到的不是数字，则将```thisVal```置为```0```

接着遍历字符串，如果当前字符为数字，那么就将```thisVal```乘以```10```并加上```当前数字```

如果当前字符不是数字，并且上一个字符为数字（```thisVal ≠ 0```），那么就比较这个数字和上一个数字的大小（是否```thisVal > lastVal```），若不合法则直接返回```false```

字符串遍历结束后，看```thisVal```是否非零，若非零则再进行一次比较（说明字符串最后一个字符是数字）

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool areNumbersAscending(string s) {
        int lastVal = 0;
        int thisVal = 0;
        for (char c : s) {
            if (isdigit(c)) {
                thisVal = thisVal * 10 + c - '0';
            }
            else {
                if (thisVal) {  // 数字转字母
                    if (lastVal >= thisVal)
                        return false;
                    lastVal = thisVal;
                    thisVal = 0;
                }
            }
        }
        if (thisVal) {
            if (lastVal >= thisVal)
                return false;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/03/LeetCode%202042.%E6%A3%80%E6%9F%A5%E5%8F%A5%E5%AD%90%E4%B8%AD%E7%9A%84%E6%95%B0%E5%AD%97%E6%98%AF%E5%90%A6%E9%80%92%E5%A2%9E/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128538008](https://letmefly.blog.csdn.net/article/details/128538008)
