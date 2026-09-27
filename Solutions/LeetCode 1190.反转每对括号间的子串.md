---
title: 1190.反转每对括号间的子串：递归 / 指针横跳
date: 2026-09-27 09:12:50
tags: [题解, LeetCode, 中等, 栈, 字符串, 递归, 深度优先搜索, DFS, 双指针, 括号匹配]
categories: [题解, LeetCode]
---

# 【LetMeFly】1190.反转每对括号间的子串：递归 / 指针横跳

力扣题目链接：[https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/](https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/)

<p>给出一个字符串&nbsp;<code>s</code>（仅含有小写英文字母和括号）。</p>

<p>请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。</p>

<p>注意，您的结果中 <strong>不应</strong> 包含任何括号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "(abcd)"
<strong>输出：</strong>"dcba"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(u(love)i)"
<strong>输出：</strong>"iloveu"
<strong>解释：</strong>先反转子字符串 "love" ，然后反转整个字符串。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "(ed(et(oc))el)"
<strong>输出：</strong>"leetcode"
<strong>解释：</strong>先反转子字符串 "oc" ，接着反转 "etco" ，然后反转整个字符串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 中只有小写英文字母和括号</li>
	<li>题目测试用例确保所有括号都是成对出现的</li>
</ul>


    
## 解题方法一：递归

写一个`dfs`函数遍历传入的字符串，遇到字母则直接拼接到答案中，遇到左括号则找到对应的右括号，然后递归`middle = dfs(该括号中的子串)`，把`middle`反转后拼接到答案中。直到遍历完整个字符串为止。

+ 时间复杂度$O(len(s)^2)$
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-27 08:49:50
 */
/*
(ed(et(oc))el)
[ed          ]
[ed        te]
[ed oc     te]
[ed oc  le te]
    两栈不可
*/
class Solution {
private:
    size_t find_end(string_view s, size_t left) {
        size_t idx = left + 1;
        for (size_t layer = 1; layer; idx++) {
            if (s[idx] == '(') {
                layer++;
            } else if (s[idx] == ')') {
                layer--;
            }
        }
        return --idx;
    }

    string dfs(string_view s) {
        string ans;
        for (size_t i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                size_t end = find_end(s, i);
                string res = dfs(s.substr(i + 1, end - i - 1));
                reverse(res.begin(), res.end());
                ans += res;
                i = end;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
public:
    string reverseParentheses(const string& s) {
        return dfs(s);
    }
};
```

## 解题方法二：指针横跳

按照题目意思模拟。使用一个指针从左到右遍历字符串，遇到左括号则跳转到对应的右括号的位置向左遍历；遇到右括号则跳转到对应的左括号的位置向右遍历。遇到字母则直接拼接到答案中。

我们可以预处理得到每个括号与之配对的括号的位置。创建一个$mate$数组，$mate[i]$表示与下标为$i$的括号匹配的括号的下标。使用一个栈，遍历字符串，遇到左括号则将其下标入栈，遇到右括号则将栈顶的下标出栈，即**说明二者是一对** 。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(len(s))$

> 该算法暂未规范名称，暂时归类到[双指针](https://blog.letmefly.xyz/tags/%E5%8F%8C%E6%8C%87%E9%92%88/)标签下。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-27 09:12:03
 */
class Solution {
public:
    string reverseParentheses(const string& s) {
        int n = s.size();
        vector<int> mate(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int girlfriend = st.top();
                st.pop();
                mate[girlfriend] = i;
                mate[i] = girlfriend;
            }
        }

        string ans;
        ans.reserve(n);
        for (int i = 0, direction = 1; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = mate[i];
                direction = -direction;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166726925)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/27/LeetCode%201190.%E5%8F%8D%E8%BD%AC%E6%AF%8F%E5%AF%B9%E6%8B%AC%E5%8F%B7%E9%97%B4%E7%9A%84%E5%AD%90%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
