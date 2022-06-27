---
title: 91.解码方法
date: 2022-06-27 16:44:37
tags: [题解, LeetCode, 中等, 字符串, 动态规划]
---

# 【LetMeFly】91.解码方法 - 动态规划+原地滚动(比较高效的算法)

力扣题目链接：[https://leetcode.cn/problems/decode-ways/](https://leetcode.cn/problems/decode-ways/)

<p>一条包含字母&nbsp;<code>A-Z</code> 的消息通过以下映射进行了 <strong>编码</strong> ：</p>

<pre>
'A' -&gt; "1"
'B' -&gt; "2"
...
'Z' -&gt; "26"</pre>

<p>要 <strong>解码</strong> 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，<code>"11106"</code> 可以映射为：</p>

<ul>
	<li><code>"AAJF"</code> ，将消息分组为 <code>(1 1 10 6)</code></li>
	<li><code>"KJF"</code> ，将消息分组为 <code>(11 10 6)</code></li>
</ul>

<p>注意，消息不能分组为&nbsp; <code>(1 11 06)</code> ，因为 <code>"06"</code> 不能映射为 <code>"F"</code> ，这是由于 <code>"6"</code> 和 <code>"06"</code> 在映射中并不等价。</p>

<p>给你一个只含数字的 <strong>非空 </strong>字符串 <code>s</code> ，请计算并返回 <strong>解码</strong> 方法的 <strong>总数</strong> 。</p>

<p>题目数据保证答案肯定是一个 <strong>32 位</strong> 的整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "12"
<strong>输出：</strong>2
<strong>解释：</strong>它可以解码为 "AB"（1 2）或者 "L"（12）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "226"
<strong>输出：</strong>3
<strong>解释：</strong>它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0"
<strong>输出：</strong>0
<strong>解释：</strong>没有字符映射到以 0 开头的数字。
含有 0 的有效映射是 'J' -&gt; "10" 和 'T'-&gt; "20" 。
由于没有字符，因此没有有效的方法对此进行解码，因为所有数字都需要映射。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 只包含数字，并且可能包含前导零。</li>
</ul>

![比较高效的算法](https://img-blog.csdnimg.cn/9f1dda529e7c4a96b1cc6d0c37790e75.jpeg#pic_center)

## 方法一：动态规划

<small><del>第一次的时候尝试使用递归，结果超时了，然后就想到了这个算法</del></small>

给定一个或者两个字符，我们很容易判断它(们)是否为一个有效的编码：

```cpp
bool isNum(string& s, int loc) {  // 判断s[loc]是否为有效编码
    return s[loc] != '0';
}

bool isNum(string& s, int l, int r) {  // 判断“s[l]s[r]”是否为有效编码
    if (s[l] == '0')  // 两位的编码，第一位不能是0
        return false;
    if (s[l] == '1') {  // 如果第一位是1，那么第二位是几都可以(0~9)
        return true;
    }
    if (s[l] == '2') {  // 如果第一位是2，那么第二位只能是0~6
        return s[r] < '7';
    }
    return false;
}
```

所以我们可以用$dp[i]$表示“原字符串从下标$i$开始到字符串结尾”这一段字符串有多少种解码方式

$dp[i]$初值为$0$，状态转移方程为：

$
dp[i] +=
\begin{cases}
 dp[i + 1]  & \text{ 如果 } “s[i]”是有效编码 \\
 dp[i + 2] & \text{ 如果 } “s[i]s[i+1]”是有效编码
\end{cases}
$

上述方程意思为：

+ 如果当前字符$s[i]$是有效编码，“从$s[i]$到字符串末尾”的字符串就能解码为：“$s[i] + s[i + 1]到末尾$”
+ 如果当前字符及其下一个字符$s[i]s[i+1]$是有效编码，“从$s[i]$到字符串末尾”的字符串就能解码为：“$s[i]s[i+1] + s[i + 2]到末尾$”

最终$dp[0]$即为答案（从下标$0$到末尾的字符串 的解码方式）

+ 时间复杂度$O(N)$，其中$N$是原字符串长度
+ 空间复杂度$O(N)$

## 方法二：动态规划 + 原地滚动

从方法一中我们可以看出，求$dp[i]$时只会用到$dp[i+1]$和$dp[i+2]$。

因此我们无需开辟一个额外的长度为```字符串长度```的数组，只需要额外两个变量来记录$dp[i+1]$和$dp[i+2]$即可。

这个方法就叫**原地滚动**。

+ 时间复杂度$O(N)$，其中$N$是原字符串长度
+ 空间复杂度$O(1)$，只需要常数个空间

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isNum(string& s, int loc) {
        return s[loc] != '0';
    }

    bool isNum(string& s, int l, int r) {
        if (s[l] == '0')
            return false;
        if (s[l] == '1') {
            return true;
        }
        if (s[l] == '2') {
            return s[r] < '7';
        }
        return false;
    }
public:
    int numDecodings(string& s) {
        if (s.size() == 1)
            return isNum(s, s.size() - 1);
        int last1 = isNum(s, s.size() - 1);
        int last2 = isNum(s, s.size() - 2, s.size() - 1) + isNum(s, s.size() - 2) * last1;
        for (int i = s.size() - 3; i >= 0; i--) {
            int thisNum = isNum(s, i) * last2 + isNum(s, i, i + 1) * last1;
            last1 = last2, last2 = thisNum;
        }
        return last2;
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/06/27/LeetCode%200091.%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125487393](https://letmefly.blog.csdn.net/article/details/125487393)

    