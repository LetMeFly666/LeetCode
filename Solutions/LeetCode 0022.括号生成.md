---
title: 22.括号生成：暴力枚举 / 回溯
date: 2026-10-02 16:55:48
tags: [题解, LeetCode, 中等, 字符串, 暴力枚举, 二进制枚举, 回溯, 括号匹配, 字符串构造]
categories: [题解, LeetCode]
---

# 【LetMeFly】22.括号生成：暴力枚举 / 回溯

力扣题目链接：[https://leetcode.cn/problems/generate-parentheses/](https://leetcode.cn/problems/generate-parentheses/)

<p>数字 <code>n</code>&nbsp;代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 <strong>有效的 </strong>括号组合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>["((()))","(()())","(())()","()(())","()()()"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>["()"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


    
## 解题方法一：暴力枚举（二进制状态压缩）

$n$对括号组成的字符串长度$2n$，我们枚举长度为$2n$的字符串所有的$2^{2n}$种左右括号的可能，如果是合法括号序列则加入答案中。

+ 时间复杂度$O(4^{n}\times n)$。共有$2^{2n}$种可能，每种可能需要$O(n)$的时间去判断是否合法。不过实际上会有很多状态提前退出枚举。
+ 空间复杂度$O(n)$，空间复杂度来自临时构造的字符串，力扣返回值不计入算法空间复杂度。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-02 16:43:41
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n *= 2;
        for (int i = 0, to = 1 << n; i < to; i++) {
            string s(n, '0');
            bool ok = true;
            int cnt_left = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    cnt_left++;
                    s[j] = '(';
                } else if (!cnt_left) {
                    ok = false;
                    break;
                } else {
                    cnt_left--;
                    s[j] = ')';
                }
            }
            if (cnt_left) {
                continue;
            }
            if (ok) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
```

## 解题方法二：回溯

写一个函数`dfs`尝试字符串当前位置的每一种可能。`dfs`接收参数：`s, idx, diff, left, right`表示字符串当前应该填充`s[idx]`位置，还有`left`个左括号和`right`个右括号，当前左括号比右括号多`diff`个。

+ 如果`left`和`right`都为0，说明已经填充完毕，加入答案中。
+ 如果`left`非零，可尝试填充左括号。
+ 如果`diff`非零且`right`非零，可尝试填充右括号。

以上。

+ 时间复杂度$O(4^{n})$。实际上只会枚举所有合法括号序列。
+ 空间复杂度$O(n)$，临时构造的字符串、最大递归深度的空间复杂度都是$O(n)$，力扣返回值不计入算法空间复杂度。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-02 16:54:44
 */
class Solution {
private:
    vector<string> ans;

    void dfs(string& s, int idx, int diff, int left, int right) {
        if (!left && !right) {
            ans.push_back(s);
        }
        if (left) {
            s[idx] = '(';
            dfs(s, idx + 1, diff + 1, left - 1, right);
        }
        if (diff && right) {
            s[idx] = ')';
            dfs(s, idx + 1, diff - 1, left, right - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s(n * 2, ' ');
        dfs(s, 0, 0, n, n);
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166993148)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/02/LeetCode%200022.%E6%8B%AC%E5%8F%B7%E7%94%9F%E6%88%90/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
