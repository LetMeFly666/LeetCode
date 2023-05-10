---
title: 1768.交替合并字符串
date: 2022-10-23 09:05:32
tags: [题解, LeetCode, 简单, 双指针, 字符串]
---

# 【LetMeFly】1768.交替合并字符串

力扣题目链接：[https://leetcode.cn/problems/merge-strings-alternately/](https://leetcode.cn/problems/merge-strings-alternately/)

<p>给你两个字符串 <code>word1</code> 和 <code>word2</code> 。请你从 <code>word1</code> 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。</p>

<p>返回 <strong>合并后的字符串</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abc", word2 = "pqr"
<strong>输出：</strong>"apbqcr"
<strong>解释：</strong>字符串合并情况如下所示：
word1：  a   b   c
word2：    p   q   r
合并后：  a p b q c r
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "ab", word2 = "pqrs"
<strong>输出：</strong>"apbqrs"
<strong>解释：</strong>注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
word1：  a   b 
word2：    p   q   r   s
合并后：  a p b q   r   s
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abcd", word2 = "pq"
<strong>输出：</strong>"apbqcd"
<strong>解释：</strong>注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
word1：  a   b   c   d
word2：    p   q 
合并后：  a p b q c   d
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word1.length, word2.length <= 100</code></li>
	<li><code>word1</code> 和 <code>word2</code> 由小写英文字母组成</li>
</ul>


    
## 方法一：双指针

使用两个“指针”分别指向两个字符串处理到的位置。

当两个指针都没有达到字符串末尾时，答案字符串加上两个指针所指的元素（交替）

当某个指针指到了字符串末尾，就把没指到末尾的指针不断后移并添加到答案字符串中（多出来的部分），直到这个指针也移动到字符串末尾

+ 时间复杂度$O(n+m)$，其中$n$和$m$分别是两个字符串的长度
+ 空间复杂度$O(1)$，力扣算法答案不计入空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    string mergeAlternately(string& word1, string& word2) {
        int n1 = word1.size(), n2 = word2.size();
        int loc1 = 0, loc2 = 0;
        string ans;
        while (loc1 < n1 && loc2 < n2) {
            ans += word1[loc1++];
            ans += word2[loc2++];
        }
        while (loc1 < n1) {
            ans += word1[loc1++];
        }
        while (loc2 < n2) {
            ans += word2[loc2++];
        }
        return ans;
    }
};
```

运气比较好

![Lucky](https://img-blog.csdnimg.cn/555c0ee492f9437187111ae144cea411.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/23/LeetCode%201768.%E4%BA%A4%E6%9B%BF%E5%90%88%E5%B9%B6%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127470753](https://letmefly.blog.csdn.net/article/details/127470753)
