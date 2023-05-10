---
title: 2027.转换字符串的最少操作次数
date: 2022-12-27 11:08:36
tags: [题解, LeetCode, 简单, 贪心, 字符串]
---

# 【LetMeFly】2027.转换字符串的最少操作次数

力扣题目链接：[https://leetcode.cn/problems/minimum-moves-to-convert-string/](https://leetcode.cn/problems/minimum-moves-to-convert-string/)

<p>给你一个字符串 <code>s</code> ，由 <code>n</code> 个字符组成，每个字符不是 <code>'X'</code> 就是 <code>'O'</code> 。</p>

<p>一次<strong> 操作</strong> 定义为从 <code>s</code> 中选出 <strong>三个连续字符 </strong>并将选中的每个字符都转换为 <code>'O'</code> 。注意，如果字符已经是 <code>'O'</code> ，只需要保持 <strong>不变</strong> 。</p>

<p>返回将 <code>s</code> 中所有字符均转换为 <code>'O'</code> 需要执行的&nbsp;<strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "XXX"
<strong>输出：</strong>1
<strong>解释：<em>XXX</em></strong> -&gt; OOO
一次操作，选中全部 3 个字符，并将它们转换为 <code>'O' 。</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "XXOX"
<strong>输出：</strong>2
<strong>解释：<em>XXO</em></strong>X -&gt; O<em><strong>OOX</strong></em> -&gt; OOOO
第一次操作，选择前 3 个字符，并将这些字符转换为 <code>'O'</code> 。
然后，选中后 3 个字符，并执行转换。最终得到的字符串全由字符 <code>'O'</code> 组成。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "OOOO"
<strong>输出：</strong>0
<strong>解释：</strong>s 中不存在需要转换的 <code>'X' 。</code>
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 为 <code>'X'</code> 或 <code>'O'</code></li>
</ul>


    
## 方法一：贪心

这道题主要有两点：

1. 所有的```X```都需要变成```O```
2. 一次将三个字符变成```O```

知道了这两点就好说了，我们从前到后遍历字符串，一旦遇到```X```就从这个```X```开始，把连续三个字符变成```O```

也不用管这个```X```后面的两个字符是什么，反正无脑变成```O```就行了

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X') {
                ans++;
                i += 2;
            }
        }
        return ans;
    }
};
```

**Q&A**

问：如果```X```后面没有字符了怎么办？

答：不用特殊考虑，我们就当```X```后面有字符，实际上更改```X```前面的字符就行了（题目中说$len(s)\geq3）$

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/27/LeetCode%202027.%E8%BD%AC%E6%8D%A2%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128453481](https://letmefly.blog.csdn.net/article/details/128453481)
