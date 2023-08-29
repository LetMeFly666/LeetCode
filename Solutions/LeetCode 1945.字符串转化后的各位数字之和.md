---
title: 1945.字符串转化后的各位数字之和
date: 2022-12-15 21:11:27
tags: [题解, LeetCode, 简单, 字符串, 模拟]
---

# 【LetMeFly】1945.字符串转化后的各位数字之和

力扣题目链接：[https://leetcode.cn/problems/sum-of-digits-of-string-after-convert/](https://leetcode.cn/problems/sum-of-digits-of-string-after-convert/)

<p>给你一个由小写字母组成的字符串 <code>s</code> ，以及一个整数 <code>k</code> 。</p>

<p>首先，用字母在字母表中的位置替换该字母，将 <code>s</code> <strong>转化</strong> 为一个整数（也就是，<code>'a'</code> 用 <code>1</code> 替换，<code>'b'</code> 用 <code>2</code> 替换，... <code>'z'</code> 用 <code>26</code> 替换）。接着，将整数 <strong>转换</strong> 为其 <strong>各位数字之和</strong> 。共重复 <strong>转换</strong> 操作 <strong><code>k</code> 次</strong> 。</p>

<p>例如，如果 <code>s = "zbax"</code> 且 <code>k = 2</code> ，那么执行下述步骤后得到的结果是整数 <code>8</code> ：</p>

<ul>
	<li><strong>转化：</strong><code>"zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124</code></li>
	<li><strong>转换 #1</strong>：<code>262124&nbsp;➝ 2 + 6 + 2 + 1 + 2 + 4&nbsp;➝ 17</code></li>
	<li><strong>转换 #2</strong>：<code>17 ➝ 1 + 7 ➝ 8</code></li>
</ul>

<p>返回执行上述操作后得到的结果整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "iiii", k = 1
<strong>输出：</strong>36
<strong>解释：</strong>操作如下：
- 转化："iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- 转换 #1：9999 ➝ 9 + 9 + 9 + 9 ➝ 36
因此，结果整数为 36 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode", k = 2
<strong>输出：</strong>6
<strong>解释：</strong>操作如下：
- 转化："leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- 转换 #1：12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- 转换 #2：33 ➝ 3 + 3 ➝ 6
因此，结果整数为 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>


    
## 方法一：计算

字符串长度可能为$100$，$C++$等语言中很难**直接**存放下$10^{200}$的数

这里有两种方案，一种是将数字以字符串的形式存放，另一种是，不存放$10^{200}$这么大的数字，而是直接存放**这个数字的每位之和**

这个数字的每位之和最大不超过$9\times200$，很容易用整数型变量存下。

接下来就是进行$k-1$次**特殊计算**

计算的时候，我们将这个数的每一位不断取出，并累加到一个临时变量中，然后使用这个临时变量代替这个数即可

```cpp
// 一次求和操作
int temp = 0;
while (ans) {
    temp += ans % 10;
    ans /= 10;
}
ans = temp;
```

+ 时间复杂度$O(\len(s) + k)$，每次**求和操作**的时间复杂度可以视为$O(1)$，因为这个数最多不超过$1800$，最多进行$4$次加法运算
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int getLucky(string& s, int k) {
        int ans = 0;
        for (char c : s) {
            ans += (c - 'a' + 1) / 10 + (c - 'a' + 1) % 10;
        }
        while (--k) {
            int temp = 0;
            while (ans) {
                temp += ans % 10;
                ans /= 10;
            }
            ans = temp;
        }
        return ans;
    }
};
```

执行结果：

![result](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/46c814525c5f4fa78291e38021c5586d.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/12/15/LeetCode%201945.%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%BD%AC%E5%8C%96%E5%90%8E%E7%9A%84%E5%90%84%E4%BD%8D%E6%95%B0%E5%AD%97%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128335606](https://letmefly.blog.csdn.net/article/details/128335606)
