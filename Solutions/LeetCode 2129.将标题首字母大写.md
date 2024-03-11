---
title: 2129.将标题首字母大写
date: 2024-03-11 09:25:32
tags: [题解, LeetCode, 简单, 字符串]
---

# 【LetMeFly】2129.将标题首字母大写：模拟（一个变量记录是否该大写）

力扣题目链接：[https://leetcode.cn/problems/capitalize-the-title/](https://leetcode.cn/problems/capitalize-the-title/)

<p>给你一个字符串&nbsp;<code>title</code>&nbsp;，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 <strong>大写</strong>&nbsp;：</p>

<ul>
	<li>如果单词的长度为&nbsp;<code>1</code>&nbsp;或者&nbsp;<code>2</code>&nbsp;，所有字母变成小写。</li>
	<li>否则，将单词首字母大写，剩余字母变成小写。</li>
</ul>

<p>请你返回 <strong>大写后</strong>&nbsp;的<em>&nbsp;</em><code>title</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre><b>输入：</b>title = "capiTalIze tHe titLe"
<b>输出：</b>"Capitalize The Title"
<strong>解释：</strong>
由于所有单词的长度都至少为 3 ，将每个单词首字母大写，剩余字母变为小写。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>title = "First leTTeR of EACH Word"
<b>输出：</b>"First Letter of Each Word"
<strong>解释：</strong>
单词 "of" 长度为 2 ，所以它保持完全小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>title = "i lOve leetcode"
<b>输出：</b>"i Love Leetcode"
<strong>解释：</strong>
单词 "i" 长度为 1 ，所以它保留小写。
其他单词长度都至少为 3 ，所以其他单词首字母大写，剩余字母小写。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= title.length &lt;= 100</code></li>
	<li><code>title</code>&nbsp;由单个空格隔开的单词组成，且不含有任何前导或后缀空格。</li>
	<li>每个单词由大写和小写英文字母组成，且都是 <strong>非空</strong>&nbsp;的。</li>
</ul>


    
## 方法一：模拟（一个变量记录是否该大写）

*方法千万个，能过第一个。*

可以用一个变量shouldUpper来记录下一个字符是否应该大写。

遍历字符串：

> + 如果当前字符为空格：将shouldUpper赋值为“```还有至少3个字符```且```后三个字符都为字母```”
> + 否则，根据shouldUpper的值将当前字符修改为大写或小写，之后将shouldUpper修改为```false```。

+ 时间复杂度$O(len(title))$
+ 空间复杂度：对于可变字符串的编程语言如C++, $O(1)$；对于不可变字符串的编程语言如Python, $O(len(title))$

### AC代码

#### C++

```cpp
class Solution {
public:
    string capitalizeTitle(string title) {
        bool shouldUpper = title.size() >= 3 && title[1] != ' ' && title[2] != ' ';
        for (int i = 0; i < title.size(); i++) {
            if (title[i] == ' ') {
                shouldUpper = i + 3 < title.size() && title[i + 2] != ' ' && title[i + 3] != ' ';
                continue;
            }
            title[i] = shouldUpper ? toupper(title[i]) : tolower(title[i]);
            shouldUpper = false;
        }
        return title;
    }
};
```

#### Python

```python
class Solution:
    def capitalizeTitle(self, title: str) -> str:
        shouldUpper = len(title) >= 3 and title[1] != ' ' and title[2] != ' '
        ans_list = []
        for i in range(len(title)):
            if title[i] == ' ':
                shouldUpper = i + 3 < len(title) and title[i + 2] != ' ' and title[i + 3] != ' '
                ans_list.append(' ')  # 不同于可变数组的语言，这里记得也要加上空格
                continue
            ans_list.append(title[i].upper() if shouldUpper else title[i].lower())
            shouldUpper = False
        return ''.join(ans_list)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/11/LeetCode%202129.%E5%B0%86%E6%A0%87%E9%A2%98%E9%A6%96%E5%AD%97%E6%AF%8D%E5%A4%A7%E5%86%99/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136614914](https://letmefly.blog.csdn.net/article/details/136614914)
