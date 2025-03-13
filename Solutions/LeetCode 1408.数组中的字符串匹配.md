---
title: 1408.数组中的字符串匹配
date: 2022-08-06 08:52:25
tags: [题解, LeetCode, 简单, 字符串, 字符串匹配, 暴力, find]
categories: [题解, LeetCode]
---

# 【LetMeFly】1408.数组中的字符串匹配

力扣题目链接：[https://leetcode.cn/problems/string-matching-in-an-array/](https://leetcode.cn/problems/string-matching-in-an-array/)

<p>给你一个字符串数组 <code>words</code> ，数组中的每个字符串都可以看作是一个单词。请你按 <strong>任意</strong> 顺序返回 <code>words</code> 中是其他单词的子字符串的所有单词。</p>

<p>如果你可以删除 <code>words[j]</code>&nbsp;最左侧和/或最右侧的若干字符得到 <code>word[i]</code> ，那么字符串 <code>words[i]</code> 就是 <code>words[j]</code> 的一个子字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = [&quot;mass&quot;,&quot;as&quot;,&quot;hero&quot;,&quot;superhero&quot;]
<strong>输出：</strong>[&quot;as&quot;,&quot;hero&quot;]
<strong>解释：</strong>&quot;as&quot; 是 &quot;mass&quot; 的子字符串，&quot;hero&quot; 是 &quot;superhero&quot; 的子字符串。
[&quot;hero&quot;,&quot;as&quot;] 也是有效的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = [&quot;leetcode&quot;,&quot;et&quot;,&quot;code&quot;]
<strong>输出：</strong>[&quot;et&quot;,&quot;code&quot;]
<strong>解释：</strong>&quot;et&quot; 和 &quot;code&quot; 都是 &quot;leetcode&quot; 的子字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>words = [&quot;blue&quot;,&quot;green&quot;,&quot;bu&quot;]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code> 仅包含小写英文字母。</li>
	<li>题目数据 <strong>保证</strong> 每个 <code>words[i]</code> 都是独一无二的。</li>
</ul>


    
## 方法一：字符串暴力匹配

两层循环遍历字符串数组，如果第一层循环到的字符串是第二层循环到的字符串的子串，就把第一层循环的字符串添加到答案中，并结束第二层循环。

+ 时间复杂度$O(n^2\tiems L^2)$，其中$n$是原始字符串数组的长度，$L$是平均每个字符串的长度
+ 空间复杂度$O(1)$，答案不计入算法复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                if (words[j].find(words[i]) < words[j].size()) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/06/LeetCode%201408.%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%8C%B9%E9%85%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126189255](https://letmefly.blog.csdn.net/article/details/126189255)
