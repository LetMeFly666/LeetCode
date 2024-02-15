---
title: 1805.字符串中不同整数的数目
date: 2022-12-06 11:48:15
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 遍历]
---

# 【LetMeFly】1805.字符串中不同整数的数目

力扣题目链接：[https://leetcode.cn/problems/number-of-different-integers-in-a-string/](https://leetcode.cn/problems/number-of-different-integers-in-a-string/)

<p>给你一个字符串 <code>word</code> ，该字符串由数字和小写英文字母组成。</p>

<p>请你用空格替换每个不是数字的字符。例如，<code>"a123bc34d8ef34"</code> 将会变成 <code>" 123  34 8  34"</code> 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）：<code>"123"</code>、<code>"34"</code>、<code>"8"</code> 和 <code>"34"</code> 。</p>

<p>返回对 <code>word</code> 完成替换后形成的 <strong>不同</strong> 整数的数目。</p>

<p>只有当两个整数的 <strong>不含前导零</strong> 的十进制表示不同， 才认为这两个整数也不同。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "a<strong>123</strong>bc<strong>34</strong>d<strong>8</strong>ef<strong>34</strong>"
<strong>输出：</strong>3
<strong>解释：</strong>不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "leet<strong>1234</strong>code<strong>234</strong>"
<strong>输出：</strong>2
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "a<strong>1</strong>b<strong>01</strong>c<strong>001</strong>"
<strong>输出：</strong>1
<strong>解释：</strong>"1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word.length <= 1000</code></li>
	<li><code>word</code> 由数字和小写英文字母组成</li>
</ul>


    
## 方法一：遍历拆分

这个问题主要包括三部分：

1. 将数字从字符串中抽取出来
2. 将数字的前导零去除
3. 数字的去重与计数

接下来逐个解决这三个问题

**1. 将数字从字符串中提取出来：**

我们需要一个布尔类型的变量“lastIsNum”来记录上一个字符是否为数字。初始值为```false```

同时，我们还需要一个字符串，用来存储整个字符串中的某个数字。```string thisString```

接下来遍历字符串。若字符串遍历结束或者遍历到字母字符时，将```lastIsNum```标记为```true```，否则将```lastIsNum```标记为```false```

如果这个字符是字母，但上一个字符是数字，那么就说明我们找到了“一个数字的末尾”，此时我们就**提取出**了这个数字。

处理完这个数字记得将字符串清空。

如果这个字符是数字，那么直接无脑添加数字字符串```thisString```的末尾即可。

**2. 将数字的前导零去除：**

使用一个整数类型的变量```firstLoc```来记录一个数字第一个非零的位置，初始值为-1

接着遍历数字字符串，遇到第一个非零数字就结束遍历，并将```firstLoc```修改为遍历到的位置。

如果最后```firstLoc```的值仍未-1，那么就说明整个数字字符串全是```0```

否则，从```firstLoc```开始到字符串末尾所组成的子串即为去除前导零后的数字字符串

**3. 数字的去重与统计：**

题目问的是“有多少不同的数字”，这就需要我们对所有的数字做去重处理。

这个过程很简单，直接使用一个哈希表即可

将所有的处理过的数字字符串放入哈希表，最后返回哈希表的大小即为去重后的结果。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(len(word))$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_set<string> se;

    void insert(string toInsert) {
        int firstLoc = -1;
        for (int i = 0; i < toInsert.size(); i++) {
            if (toInsert[i] != '0') {
                firstLoc = i;
                break;
            }
        }
        if (firstLoc == -1)
            se.insert("0");
        else
            se.insert(toInsert.substr(firstLoc));
    }
public:
    int numDifferentIntegers(string word) {
        bool lastIsNum = false;
        string thisString;
        int n = word.size();
        for (int i = 0; i <= n; i++) {
            if (i == n || isalpha(word[i])) {
                if (lastIsNum) {
                    lastIsNum = false;
                    insert(thisString);
                    thisString.clear();
                }
            }
            else {
                thisString += word[i];
                lastIsNum = true;
            }
        }
        return se.size();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/06/LeetCode%201805.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E4%B8%8D%E5%90%8C%E6%95%B4%E6%95%B0%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128200587](https://letmefly.blog.csdn.net/article/details/128200587)
