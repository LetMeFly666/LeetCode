---
title: 1653.使字符串平衡的最少删除次数
date: 2023-03-06 12:06:42
tags: [题解, LeetCode, 中等, 栈, 字符串, 动态规划, 模拟, 前缀和]
---

# 【LetMeFly】1653.使字符串平衡的最少删除次数

力扣题目链接：[https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/](https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/)

<p>给你一个字符串 <code>s</code> ，它仅包含字符 <code>'a'</code> 和 <code>'b'</code>​​​​ 。</p>

<p>你可以删除 <code>s</code> 中任意数目的字符，使得 <code>s</code> <strong>平衡</strong> 。我们称 <code>s</code> <strong>平衡的</strong> 当不存在下标对 <code>(i,j)</code> 满足 <code>i < j</code> 且 <code>s[i] = 'b'</code> 同时 <code>s[j]= 'a'</code> 。</p>

<p>请你返回使 <code>s</code> <strong>平衡</strong> 的 <strong>最少</strong> 删除次数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aababbab"
<b>输出：</b>2
<b>解释：</b>你可以选择以下任意一种方案：
下标从 0 开始，删除第 2 和第 6 个字符（"aa<strong>b</strong>abb<strong>a</strong>b" -> "aaabbb"），
下标从 0 开始，删除第 3 和第 6 个字符（"aab<strong>a</strong>bb<strong>a</strong>b" -> "aabbbb"）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "bbaaaaabb"
<b>输出：</b>2
<b>解释：</b>唯一的最优解是删除最前面两个字符。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 要么是 <code>'a'</code> 要么是 <code>'b'</code>​<strong> </strong>。​</li>
</ul>


## 题目分析

这道题的“平衡”是什么？说白了就是字符串前面全是```'a'```，后面全是```'b'```

## 方法一：模拟 + 前缀和

所谓模拟，就是模拟字符串的每一个位置（n个字符长的字符串有n+1个位置），看从这个位置开始前面全是'a'后面全是'b'需要删除多少个字符。

假设长度为$n$的字符串的$n+1$个位置为“0，1，2，...，n”，那么：

我们用```backB[i]```表示字符串第```i```个位置开始往后的字符'b'的个数；用```frontA[i]```表示字符串第```i```个位置开始往前的字符'a'的个数

接着遍历字符串的每一个“位置”，把这个位置前面的'b'全删掉，后面的'a'全删掉，共需要```frontA[i] + backB[i]```次

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumDeletions(string& s) {
        vector<int> frontB(s.size() + 1, 0);
        vector<int> backA(s.size() + 1, 0);
        int ans = s.size() - 1;
        for (int i = 1; i <= s.size(); i++) {
            frontB[i] = frontB[i - 1] + (s[i - 1] == 'b');
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            backA[i] = backA[i + 1] + (s[i] == 'a');
        }
        for (int i = 0; i <= s.size(); i++) {
            ans = min(ans, backA[i] + frontB[i]);
        }
        return ans;
    }
};
```

## 方法二：模拟 + 前缀和（空间优化）

方法一我们开辟了两个数组来存放某个位置前后的'a'和'b'的个数。

那么，这个过程能否动态实现呢？我们不提前算出每个位置前后的'a'、'b'的个数，而是在模拟的过程中动态算出即可。

初始时我们遍历字符串并统计字符串中共有多少个'a'，这就是```backA```的初始值。而```frontB```的初始值为$0$（首个位置前是不存在字符```'b'```的）

接着遍历模拟每一个位置，模拟完成后，如果这个位置后面有字符，就看后面的字符是'a'还是'b'。如果是'a'的话，下次模拟```backA```的值就应减一，否则（是'b'）```frontB```的值就加一

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumDeletions(string& s) {
        int fontB = 0;
        int backA = count(s.begin(), s.end(), 'a');
        int ans = s.size() - 1;
        for (int i = 0; i <= s.size(); i++) {
            ans = min(ans, backA + fontB);
            if (i < s.size()) {
                if (s[i] == 'a') {
                    backA--;
                }
                else {
                    fontB++;
                }
            }
        }
        return ans;        
    }
};
```

#### Python

```python
class Solution:
    def minimumDeletions(self, s: str) -> int:
        fontB = 0
        backA = s.count('a')
        ans = len(s) - 1
        for i in range(len(s) + 1):
            ans = min(ans, backA + fontB)
            if i < len(s):
                if s[i] == 'a':
                    backA -= 1
                else:
                    fontB += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/06/LeetCode%201653.%E4%BD%BF%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%B9%B3%E8%A1%A1%E7%9A%84%E6%9C%80%E5%B0%91%E5%88%A0%E9%99%A4%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129359377](https://letmefly.blog.csdn.net/article/details/129359377)
