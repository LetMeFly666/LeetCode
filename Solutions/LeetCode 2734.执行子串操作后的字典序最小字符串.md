---
title: 2734.执行子串操作后的字典序最小字符串
date: 2024-06-27 23:07:00
tags: [题解, LeetCode, 中等, 贪心, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2734.执行子串操作后的字典序最小字符串：贪心

力扣题目链接：[https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/](https://leetcode.cn/problems/lexicographically-smallest-string-after-substring-operation/)

<p>给你一个仅由小写英文字母组成的字符串 <code>s</code> 。在一步操作中，你可以完成以下行为：</p>

<ul>
	<li>选择&nbsp;<code>s</code> 的任一非空子字符串，可能是整个字符串，接着将字符串中的每一个字符替换为英文字母表中的前一个字符。例如，'b' 用 'a' 替换，'a' 用 'z' 替换。</li>
</ul>

<p>返回执行上述操作 <strong>恰好一次</strong> 后可以获得的 <strong>字典序最小</strong> 的字符串。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>
现有长度相同的两个字符串 <code>x</code> 和 字符串 <code>y</code> ，在满足&nbsp;<code>x[i] != y[i]</code> 的第一个位置 <code>i</code> 上，如果&nbsp; <code>x[i]</code> 在字母表中先于 <code>y[i]</code> 出现，则认为字符串 <code>x</code> 比字符串 <code>y</code> <strong>字典序更小</strong> 。

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "cbabc"
<strong>输出：</strong>"baabc"
<strong>解释：</strong>我们选择从下标 0 开始、到下标 1 结束的子字符串执行操作。 
可以证明最终得到的字符串是字典序最小的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "acbbc"
<strong>输出：</strong>"abaab"
<strong>解释：</strong>我们选择从下标 1 开始、到下标 4 结束的子字符串执行操作。
可以证明最终得到的字符串是字典序最小的。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>"kddsbncd"
<strong>解释：</strong>我们选择整个字符串执行操作。
可以证明最终得到的字符串是字典序最小的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>


    
## 解题方法：贪心

定理一：前面字符的修改比后面字符修改的影响大。

> 例如对于字符串```czzzzzz```，假设给你两种选择让你选一个：
>
> 1. 把后面的```z```全改成```a```（```caaaaaa```）
> 2. 将一个```c```改成```b```（```bzzzzzz```）
>
> 那当然选择方案```1.```。

定理二：对```a```操作是无意义的。

> 对于其他任何字符串而言，一次“操作”都会让字符的字典序变地更小。
>
> 而对```a```进行一次操作后只会让```a```变成```z```（变地更大）。
>
> 并且由```定理一```可知，为了让```a```后面的字符变地更小而连上```a```是无意义的。
>
> > 例如```zzzazzzzz```最优解是变成```yyyazzzzz```，而不能为了将后面的```zzzzz```变成```yyyyy```而将```a```变成```b```。

因此，我们可以从第一个非```a```字符开始，到```a```字符或字符串末尾或为止，对其组成的子字符串进行一次操作。

特别的，题目要求对子字符串非空。因此若字符串为“全```a```”，那么就将最后一个```a```变成```z```。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string smallestString(string s) {
        bool changing = false;
        int loc = 0;
        while (loc < s.size() && s[loc] == 'a') {
            loc++;
        }
        if (loc == s.size()) {  // 特判：全a的情况
            s.back() = 'z';
            return s;
        }
        for (; loc < s.size() && s[loc] != 'a'; loc++) {
            s[loc]--;
        }
        return s;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/27/LeetCode%202734.%E6%89%A7%E8%A1%8C%E5%AD%90%E4%B8%B2%E6%93%8D%E4%BD%9C%E5%90%8E%E7%9A%84%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140027022](https://letmefly.blog.csdn.net/article/details/140027022)
