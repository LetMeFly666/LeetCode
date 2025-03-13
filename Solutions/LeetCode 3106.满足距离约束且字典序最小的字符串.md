---
title: 3106.满足距离约束且字典序最小的字符串
date: 2024-07-28 22:44:30
tags: [题解, LeetCode, 中等, 贪心, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】3106.满足距离约束且字典序最小的字符串：模拟（贪心）

力扣题目链接：[https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint/](https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint/)

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> 。</p>

<p>定义函数 <code>distance(s<sub>1</sub>, s<sub>2</sub>)</code> ，用于衡量两个长度为 <code>n</code> 的字符串 <code>s<sub>1</sub></code> 和 <code>s<sub>2</sub></code> 之间的距离，即：</p>

<ul>
	<li>字符 <code>'a'</code> 到 <code>'z'</code> 按 <strong>循环 </strong>顺序排列，对于区间 <code>[0, n - 1]</code> 中的 <code>i</code> ，计算所有「 <code>s<sub>1</sub>[i]</code> 和 <code>s<sub>2</sub>[i]</code> 之间<strong> 最小距离</strong>」的 <strong>和 </strong>。</li>
</ul>

<p>例如，<code>distance("ab", "cd") == 4</code> ，且 <code>distance("a", "z") == 1</code> 。</p>

<p>你可以对字符串 <code>s</code> 执行<strong> 任意次 </strong>操作。在每次操作中，可以将 <code>s</code> 中的一个字母 <strong>改变 </strong>为<strong> 任意 </strong>其他小写英文字母。</p>

<p>返回一个字符串，表示在执行一些操作后你可以得到的 <strong>字典序最小</strong> 的字符串 <code>t</code> ，且满足 <code>distance(s, t) &lt;= k</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "zbbz", k = 3
<strong>输出：</strong>"aaaz"
<strong>解释：</strong>在这个例子中，可以执行以下操作：
将 s[0] 改为 'a' ，s 变为 "abbz" 。
将 s[1] 改为 'a' ，s 变为 "aabz" 。
将 s[2] 改为 'a' ，s 变为 "aaaz" 。
"zbbz" 和 "aaaz" 之间的距离等于 k = 3 。
可以证明 "aaaz" 是在任意次操作后能够得到的字典序最小的字符串。
因此，答案是 "aaaz" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "xaxcd", k = 4
<strong>输出：</strong>"aawcd"
<strong>解释：</strong>在这个例子中，可以执行以下操作：
将 s[0] 改为 'a' ，s 变为 "aaxcd" 。
将 s[2] 改为 'w' ，s 变为 "aawcd" 。
"xaxcd" 和 "aawcd" 之间的距离等于 k = 4 。
可以证明 "aawcd" 是在任意次操作后能够得到的字典序最小的字符串。
因此，答案是 "aawcd" 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "lol", k = 0
<strong>输出：</strong>"lol"
<strong>解释：</strong>在这个例子中，k = 0，更改任何字符都会使得距离大于 0 。
因此，答案是 "lol" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2000</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>


    
## 解题方法：贪心

首先需要明确，越靠前的位置越重要。所以要**不惜一切代价将前面字符尽可能地变小**。

字符变小的方式有两种：

1. 往小的方向变。每消耗一次操作次数字符就会变小一点，直到变成了`a`为止。
2. 往大的方向变。这样做的前提是剩下的操作次数足够让当前字符变大到`z`再变成`a`。

因此贪心思路出来了：

> 在还剩有操作次数时，从前到后开始变化字符：
>
> > 对于当前字符，如果剩余操作次数足够往大的方向变到`a`，且这样做比往小的方向变到`a`所需次数更少，则往大的方向变到`a`为止；
> >
> > 否则，往小的方向变，直到变到`a`或用完了操作次数为止。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string getSmallestString(string s, int k) {
        for (char &c : s) {
            int left = c - 'a', right = 'z' - c + 1;
            if (k >= right && right < left) {
                c = 'a';
                k -= right;
            }
            else {
                int move = min(left, k);
                c -= move;
                k -= move;
            }
            if (k == 0) {
                break;
            }
        }
        return s;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/28/LeetCode%203106.%E6%BB%A1%E8%B6%B3%E8%B7%9D%E7%A6%BB%E7%BA%A6%E6%9D%9F%E4%B8%94%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140758056](https://letmefly.blog.csdn.net/article/details/140758056)
