---
title: 392.判断子序列
date: 2022-10-12 11:06:11
tags: [题解, LeetCode, 简单, 双指针, 字符串, 动态规划]
---

# 【LetMeFly】392.判断子序列

力扣题目链接：[https://leetcode.cn/problems/is-subsequence/](https://leetcode.cn/problems/is-subsequence/)

<p>给定字符串 <strong>s</strong> 和 <strong>t</strong> ，判断 <strong>s</strong> 是否为 <strong>t</strong> 的子序列。</p>

<p>字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，<code>"ace"</code>是<code>"abcde"</code>的一个子序列，而<code>"aec"</code>不是）。</p>

<p><strong>进阶：</strong></p>

<p>如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？</p>

<p><strong>致谢：</strong></p>

<p>特别感谢<strong> </strong><a href="https://leetcode.com/pbrother/">@pbrother </a>添加此问题并且创建所有测试用例。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abc", t = "ahbgdc"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "axc", t = "ahbgdc"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= s.length <= 100</code></li>
	<li><code>0 <= t.length <= 10^4</code></li>
	<li>两个字符串都只由小写字符组成。</li>
</ul>


    
## 方法一：双指针

使用“指针”```loct```来记录字符串```t```处理到到了哪个元素

之后用“指针”```locs```遍历一遍字符串```s```

在```loct```在合法范围内时，不断后移```loct```，直到```t[loct]```等于```s[locs]```

中间过程中，但凡```loct```超出合法范围，就返回```false```

若```t```中每个元素都在```s```中找到了对应位置（遍历结束），就返回```true```

+ 时间复杂度$O(len(s) + len(t))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        int loct = 0;
        for (int locs = 0; locs < s.size(); locs++) {
            while (loct < t.size() && t[loct] != s[locs])
                loct++;
            if (loct == t.size())
                return false;
            loct++;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/12/LeetCode%200392.%E5%88%A4%E6%96%AD%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127279017](https://letmefly.blog.csdn.net/article/details/127279017)
