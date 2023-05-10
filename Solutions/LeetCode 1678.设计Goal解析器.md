---
title: 1678.设计 Goal 解析器
date: 2022-11-06 08:09:40
tags: [题解, LeetCode, 简单, 字符串, 遍历, 模拟]
---

# 【LetMeFly】1678.设计 Goal 解析器

力扣题目链接：[https://leetcode.cn/problems/goal-parser-interpretation/](https://leetcode.cn/problems/goal-parser-interpretation/)

<p>请你设计一个可以解释字符串 <code>command</code> 的 <strong>Goal 解析器</strong> 。<code>command</code> 由 <code>"G"</code>、<code>"()"</code> 和/或 <code>"(al)"</code> 按某种顺序组成。Goal 解析器会将 <code>"G"</code> 解释为字符串 <code>"G"</code>、<code>"()"</code> 解释为字符串 <code>"o"</code> ，<code>"(al)"</code> 解释为字符串 <code>"al"</code> 。然后，按原顺序将经解释得到的字符串连接成一个字符串。</p>

<p>给你字符串 <code>command</code> ，返回<em> </em><strong>Goal<em><strong> </strong></em>解析器 </strong>对<em> </em><code>command</code> 的解释结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>command = "G()(al)"
<strong>输出：</strong>"Goal"
<strong>解释：</strong>Goal 解析器解释命令的步骤如下所示：
G -&gt; G
() -&gt; o
(al) -&gt; al
最后连接得到的结果是 "Goal"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>command = "G()()()()(al)"
<strong>输出：</strong>"Gooooal"
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>command = "(al)G(al)()()G"
<strong>输出：</strong>"alGalooG"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= command.length &lt;= 100</code></li>
	<li><code>command</code> 由 <code>"G"</code>、<code>"()"</code> 和/或 <code>"(al)"</code> 按某种顺序组成</li>
</ul>


    
## 方法一：遍历 + 模拟

我们直接按照规则进行模拟即可

从前到后遍历字符串：

+ 遇到```G```就将```G```添加到答案字符串中
+ 遇到```(```就看下一个字符是```)```还是```a```
   + 如果下一个字符是```)```，就说明遇到了```()```，将```o```添加到答案字符串中，并将“遍历指针”后移一位（```)```）
   + 否则说明遇到了```(al)```，将```al```添加到答案字符串中，并将“遍历指针”后移三位（```al)```）

+ 时间复杂度$O(n)$，其中$n$是原始字符串的长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string interpret(string& command) {
        string ans;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                ans += 'G';
            }
            else {  // (
                if (command[i + 1] == ')')  // ()
                    ans += 'o', i += 1;
                else  // (al)
                    ans += "al", i += 3;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/11/06/LeetCode%201678.%E8%AE%BE%E8%AE%A1Goal%E8%A7%A3%E6%9E%90%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127712058](https://letmefly.blog.csdn.net/article/details/127712058)
