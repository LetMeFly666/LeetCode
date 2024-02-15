---
title: 1023.驼峰式匹配
date: 2023-04-14 13:55:28
tags: [题解, LeetCode, 中等, 字典树, 双指针, 字符串, 字符串匹配]
---

# 【LetMeFly】1023.驼峰式匹配

力扣题目链接：[https://leetcode.cn/problems/camelcase-matching/](https://leetcode.cn/problems/camelcase-matching/)

<p>如果我们可以将<strong>小写字母</strong>插入模式串&nbsp;<code>pattern</code>&nbsp;得到待查询项&nbsp;<code>query</code>，那么待查询项与给定模式串匹配。（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）</p>

<p>给定待查询列表&nbsp;<code>queries</code>，和模式串&nbsp;<code>pattern</code>，返回由布尔值组成的答案列表&nbsp;<code>answer</code>。只有在待查项&nbsp;<code>queries[i]</code> 与模式串&nbsp;<code>pattern</code> 匹配时，&nbsp;<code>answer[i]</code>&nbsp;才为 <code>true</code>，否则为 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>queries = [&quot;FooBar&quot;,&quot;FooBarTest&quot;,&quot;FootBall&quot;,&quot;FrameBuffer&quot;,&quot;ForceFeedBack&quot;], pattern = &quot;FB&quot;
<strong>输出：</strong>[true,false,true,true,false]
<strong>示例：</strong>
&quot;FooBar&quot; 可以这样生成：&quot;F&quot; + &quot;oo&quot; + &quot;B&quot; + &quot;ar&quot;。
&quot;FootBall&quot; 可以这样生成：&quot;F&quot; + &quot;oot&quot; + &quot;B&quot; + &quot;all&quot;.
&quot;FrameBuffer&quot; 可以这样生成：&quot;F&quot; + &quot;rame&quot; + &quot;B&quot; + &quot;uffer&quot;.</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>queries = [&quot;FooBar&quot;,&quot;FooBarTest&quot;,&quot;FootBall&quot;,&quot;FrameBuffer&quot;,&quot;ForceFeedBack&quot;], pattern = &quot;FoBa&quot;
<strong>输出：</strong>[true,false,true,false,false]
<strong>解释：</strong>
&quot;FooBar&quot; 可以这样生成：&quot;Fo&quot; + &quot;o&quot; + &quot;Ba&quot; + &quot;r&quot;.
&quot;FootBall&quot; 可以这样生成：&quot;Fo&quot; + &quot;ot&quot; + &quot;Ba&quot; + &quot;ll&quot;.
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输出：</strong>queries = [&quot;FooBar&quot;,&quot;FooBarTest&quot;,&quot;FootBall&quot;,&quot;FrameBuffer&quot;,&quot;ForceFeedBack&quot;], pattern = &quot;FoBaT&quot;
<strong>输入：</strong>[false,true,false,false,false]
<strong>解释： </strong>
&quot;FooBarTest&quot; 可以这样生成：&quot;Fo&quot; + &quot;o&quot; + &quot;Ba&quot; + &quot;r&quot; + &quot;T&quot; + &quot;est&quot;.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>1 &lt;= queries.length &lt;= 100</code></li>
	<li><code>1 &lt;= queries[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= pattern.length &lt;= 100</code></li>
	<li>所有字符串都仅由大写和小写英文字母组成。</li>
</ol>


    
## 方法一：字符串匹配

这道题题目意思稍微有点难以理解，说白了就是：给你n个字符串，返回每个字符串是否符合pattern

怎么样才叫做一个字符串符合pattern呢？

字符串删除数个**小写字母**后和pattern完全相同就记为“符合”。

这样，对于一个字符串是否符合pattern，我们就有了思路：

使用一个指针来指向pattern的第一个下标（下标0），之后遍历字符串，如果字符串当前字符与指针所指字符匹配，就将指针后移；否则，就尝试删除字符串中的这个字符，怎么删除呢，如果这个字符恰好是小写字母就可用删除，否则（大写字母）的话就没法删除了，就不匹配了。

+ 时间复杂度$O(\sum len(queries[i]) + len(queries)\times len(pattern))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isOK(string& q, string& pattern) {
        int locP = 0;
        for (char c : q) {
            if (locP < pattern.size() && pattern[locP] == c) {
                locP++;
            }
            else if (isupper(c)) {
                return false;
            }
        }
        return locP == pattern.size();
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string& pattern) {
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = isOK(queries[i], pattern);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def isOK(self, q: str, pattern: str) -> bool:
        locP = 0
        for c in q:
            if locP < len(pattern) and pattern[locP] == c:
                locP += 1
            elif c.isupper():
                return False
        return locP == len(pattern)

    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        ans = [False] * len(queries)
        for i in range(len(queries)):
            ans[i] = self.isOK(queries[i], pattern)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/14/LeetCode%201023.%E9%A9%BC%E5%B3%B0%E5%BC%8F%E5%8C%B9%E9%85%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130152288](https://letmefly.blog.csdn.net/article/details/130152288)
