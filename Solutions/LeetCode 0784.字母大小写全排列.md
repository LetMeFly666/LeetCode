---
title: 784.字母大小写全排列
date: 2022-10-30 08:46:42
tags: [题解, LeetCode, 中等, 位运算, 字符串, 回溯, 状态压缩, 二进制枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】784.字母大小写全排列：二进制枚举

力扣题目链接：[https://leetcode.cn/problems/letter-case-permutation/](https://leetcode.cn/problems/letter-case-permutation/)

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，通过将字符串&nbsp;<code>s</code>&nbsp;中的每个字母转变大小写，我们可以获得一个新的字符串。</p>

<p>返回 <em>所有可能得到的字符串集合</em> 。以 <strong>任意顺序</strong> 返回输出。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "a1b2"
<strong>输出：</strong>["a1b2", "a1B2", "A1b2", "A1B2"]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "3z4"
<strong>输出:</strong> ["3z4","3Z4"]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 12</code></li>
	<li><code>s</code>&nbsp;由小写英文字母、大写英文字母和数字组成</li>
</ul>


    
## 方法一：二进制枚举

这道题其实是每个字母的“变”与“不变”

这不，每个字母都有两种状态？

很容易想到二进制枚举。

唯一的区别是，可变的字母中，混杂了一些不可变的数字。

那么我们只需要先预处理，把字符串中字母的位置记录下来就可以了。

这样，我们只枚举字母位置的变与不变就可以了。

+ 时间复杂度$O(n + 2^N)$，其中$n$是字符串长度，$N$是字符串中字母的数量
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> letterCasePermutation(string& s) {
        vector<int> charLoc;
        for (int i = 0; i < s.size(); i++) {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                charLoc.push_back(i);
            }
        }
        vector<string> ans;
        int to = 1 << charLoc.size();
        for (int i = 0; i < to; i++) {
            ans.push_back(s);
            for (int j = 0; j < charLoc.size(); j++) {
                if (i & (1 << j)) {
                    ans.back()[charLoc[j]] ^= 32;
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/30/LeetCode%200784.%E5%AD%97%E6%AF%8D%E5%A4%A7%E5%B0%8F%E5%86%99%E5%85%A8%E6%8E%92%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127595187](https://letmefly.blog.csdn.net/article/details/127595187)
