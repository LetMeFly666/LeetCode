---
title: 2645.构造有效字符串的最少插入数
date: 2024-01-11 15:43:48
tags: [题解, LeetCode, 中等, 栈, 贪心, 字符串, 动态规划]
---

# 【LetMeFly】2645.构造有效字符串的最少插入数：O(n) + O(1)

力扣题目链接：[https://leetcode.cn/problems/minimum-additions-to-make-valid-string/](https://leetcode.cn/problems/minimum-additions-to-make-valid-string/)

<p>给你一个字符串 <code>word</code> ，你可以向其中任何位置插入 "a"、"b" 或 "c" 任意次，返回使 <code>word</code> <strong>有效</strong> 需要插入的最少字母数。</p>

<p>如果字符串可以由 "abc" 串联多次得到，则认为该字符串 <strong>有效</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word = "b"
<strong>输出：</strong>2
<strong>解释：</strong>在 "b" 之前插入 "a" ，在 "b" 之后插入 "c" 可以得到有效字符串 "<strong>a</strong>b<strong>c</strong>" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word = "aaa"
<strong>输出：</strong>6
<strong>解释：</strong>在每个 "a" 之后依次插入 "b" 和 "c" 可以得到有效字符串 "a<strong>bc</strong>a<strong>bc</strong>a<strong>bc</strong>" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word = "abc"
<strong>输出：</strong>0
<strong>解释：</strong>word 已经是有效字符串，不需要进行修改。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 50</code></li>
	<li><code>word</code> 仅由字母 "a"、"b" 和 "c" 组成。</li>
</ul>


    
## 方法一：if-else

从前到后遍历字符串，并补充最少的字符使所有字符都变成```abc```：

+ 如果当前字符为```a```：
   + 如果附近字符格式为```axx```，则```ans += 2```（```a```后插入```bc```）
   + 如果附近字符格式为```abx```，则```ans++; i++;```（```ab```后插入```c```）
   + 如果附近字符格式为```abc```，则```i += 2```
   + 如果附近字符格式为```ac```，则```ans++; i++;```（```ac```中插入```b```）
+ 如果当前字符为```b```：
   + 如果附近字符格式为```xbx```，则```ans += 2;```（```b```前后插入```ac```）
   + 如果附近字符格式为```xbc```，则```ans++; i++;```（```b```前插入```a```）
+ 如果当前字符为```c```：
   + 附近字符格式只能为```xxc```，则```ans += 2```（```c```前插入```ab```）

最终返回```ans```即为答案。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int addMinimum(string word) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a') {  // axx abx abc ac
                if (i + 2 < word.size() && word[i + 1] == 'b' && word[i + 2] == 'c') {  // abc
                    i += 2;
                }
                else if (i + 1 < word.size() && word[i + 1] == 'c') {  // ac
                    i++;
                    ans++;
                }
                else if (i + 1 < word.size() && word[i + 1] == 'b') {  // abx
                    i++;
                    ans++;
                }
                else {  // axx
                    ans += 2;
                }
            }
            else if (word[i] == 'b') {  // xbx xbc
                if (i + 1 < word.size() && word[i + 1] == 'c') {  // xbc
                    i++;
                    ans++;
                }
                else {  // xbx
                    ans += 2;
                }
            }
            else {  // xxc
                ans += 2;
            }
        }
        return ans;
    }
};
```

## 方法二：算最终是几个abc

有童鞋说这道题只有三个字符，如果有10个字符（abcdefghij）那得写多少if-else。

没办法了，换个更容易实现的方法吧。

不难发现，目标字符串```abc```是递增的，只要连续两个字符是递增的，那么它们必定可以划到一个```abc```中。（若连续两字符为```ab```、```ac```、```bc```，那么他们最终会在一个```abc```中）。

否则（第二个字符≤第一个字符），相邻两个字符只能处在两个```abc```中。

因此，我们只需要遍历以便字符串，看相邻两个字符中```第二个字符≤第一个字符```的个数，就能知道最终有多少个```abc```。

最终```abc```的个数乘```3```减去现有字符串长度即为要添加的字符的个数。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int addMinimum(string word) {
        int cntABC = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] <= word[i - 1]) {
                cntABC++;
            }
        }
        return cntABC * 3 - word.size();
    }
};
```

#### Python

```python
class Solution:
    def addMinimum(self, word: str) -> int:
        cntABC = 1
        for i in range(1, len(word)):
            if word[i] <= word[i - 1]:
                cntABC += 1
        return cntABC * 3 - len(word)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/11/LeetCode%202645.%E6%9E%84%E9%80%A0%E6%9C%89%E6%95%88%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%91%E6%8F%92%E5%85%A5%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135531917](https://letmefly.blog.csdn.net/article/details/135531917)
