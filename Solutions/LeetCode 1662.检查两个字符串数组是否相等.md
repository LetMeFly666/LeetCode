---
title: 1662.检查两个字符串数组是否相等
date: 2022-11-01 21:07:19
tags: [题解, LeetCode, 简单, 数组, 字符串, 双指针]
---

# 【LetMeFly】1662.检查两个字符串数组是否相等

力扣题目链接：[https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/](https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/)

<p>给你两个字符串数组 <code>word1</code> 和 <code>word2</code> 。如果两个数组表示的字符串相同，返回<em> </em><code>true</code><em> </em>；否则，返回 <code>false</code><em> 。</em></p>

<p><strong>数组表示的字符串</strong> 是由数组中的所有元素 <strong>按顺序</strong> 连接形成的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = ["ab", "c"], word2 = ["a", "bc"]
<strong>输出：</strong>true
<strong>解释：</strong>
word1 表示的字符串为 "ab" + "c" -> "abc"
word2 表示的字符串为 "a" + "bc" -> "abc"
两个字符串相同，返回 true</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = ["a", "cb"], word2 = ["ab", "c"]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
<strong>输出：</strong>true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word1.length, word2.length <= 10<sup>3</sup></code></li>
	<li><code>1 <= word1[i].length, word2[i].length <= 10<sup>3</sup></code></li>
	<li><code>1 <= sum(word1[i].length), sum(word2[i].length) <= 10<sup>3</sup></code></li>
	<li><code>word1[i]</code> 和 <code>word2[i]</code> 由小写字母组成</li>
</ul>


    
## 方法一：字符串拼接

按题意就是问两个字符串数组分别拼接起来之后是否相等

那么直接把两个数组中的字符串分别拼接起来就好了

拼接起来之后比较一下是否相等就好

+ 时间复杂度$O(N)$，其中$N$是字符总个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    string concat(vector<string>& v) {
        string ans;
        for (auto& s : v) {
            ans += s;
        }
        return ans;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return concat(word1) == concat(word2);
    }
};
```

## 方法二：双指针（或者说“四指针”）

用一个指针指向数组1的第一维（同理用一个指针指向数组2的第一维）

用一个指针指向处理到了 数组1中第一维指针所指字符串的哪个元素（数组2同理）

我们需要数组1的“元素指针”和数组2的“元素指针”所指的元素时刻相同

一旦出现不同，就立刻返回```false```

当某个“元素指针”超出了所指字符串尾部时，“元素指针”归零，第一维指针后移。

**说白了就是**通过第一维指针的辅助，“元素指针”按顺序遍历了字符串数组的每一个元素。

这样，与方法一相比，优势在于不需要由于“拼接字符串”而开辟额外的空间了。

+ 时间复杂度$O(N)$，其中$N$是字符总个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int locWords1 = 0, locWord1 = 0;
        int locWords2 = 0, locWord2 = 0;
        bool end1 = false, end2 = false;
        while (true) {
            if (word1[locWords1][locWord1] != word2[locWords2][locWord2]) {
                return false;
            }
            locWord1++, locWord2++;
            if (locWord1 == word1[locWords1].size()) {  // “元素指针”超出末尾
                locWord1 = 0, locWords1++;
                if (locWords1 == word1.size())  // 第一维指针也指完了
                    end1 = true;
            }
            if (locWord2 == word2[locWords2].size()) {
                locWord2 = 0, locWords2++;
                if (locWords2 == word2.size())
                    end2 = true;
            }
            if (end1 != end2)  // 两个字符串数组必须同时指完
                return false;
            if (end1)  // 同时指完了则返回true
                return true;
        }
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/01/LeetCode%201662.%E6%A3%80%E6%9F%A5%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0%E7%BB%84%E6%98%AF%E5%90%A6%E7%9B%B8%E7%AD%89/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127641844](https://letmefly.blog.csdn.net/article/details/127641844)
