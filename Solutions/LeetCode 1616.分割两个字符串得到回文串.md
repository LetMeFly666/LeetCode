---
title: 1616.分割两个字符串得到回文串
date: 2023-03-18 13:19:01
tags: [题解, LeetCode, 中等, 贪心, 双指针, 字符串, 回文串, 回文]
---

# 【LetMeFly】1616.分割两个字符串得到回文串

力扣题目链接：[https://leetcode.cn/problems/split-two-strings-to-make-palindrome/](https://leetcode.cn/problems/split-two-strings-to-make-palindrome/)

<p>给你两个字符串&nbsp;<code>a</code> 和&nbsp;<code>b</code>&nbsp;，它们长度相同。请你选择一个下标，将两个字符串都在&nbsp;<strong>相同的下标 </strong>分割开。由&nbsp;<code>a</code>&nbsp;可以得到两个字符串：&nbsp;<code>a<sub>prefix</sub></code>&nbsp;和&nbsp;<code>a<sub>suffix</sub></code>&nbsp;，满足&nbsp;<code>a = a<sub>prefix</sub> + a<sub>suffix</sub></code><sub>&nbsp;</sub>，同理，由&nbsp;<code>b</code> 可以得到两个字符串&nbsp;<code>b<sub>prefix</sub></code> 和&nbsp;<code>b<sub>suffix</sub></code>&nbsp;，满足&nbsp;<code>b = b<sub>prefix</sub> + b<sub>suffix</sub></code>&nbsp;。请你判断&nbsp;<code>a<sub>prefix</sub> + b<sub>suffix</sub></code> 或者&nbsp;<code>b<sub>prefix</sub> + a<sub>suffix</sub></code>&nbsp;能否构成回文串。</p>

<p>当你将一个字符串&nbsp;<code>s</code>&nbsp;分割成&nbsp;<code>s<sub>prefix</sub></code> 和&nbsp;<code>s<sub>suffix</sub></code>&nbsp;时，&nbsp;<code>s<sub>suffix</sub></code> 或者&nbsp;<code>s<sub>prefix</sub></code> 可以为空。比方说，&nbsp;<code>s = "abc"</code>&nbsp;那么&nbsp;<code>"" + "abc"</code>&nbsp;，&nbsp;<code>"a" + "bc"&nbsp;</code>，&nbsp;<code>"ab" + "c"</code>&nbsp;和&nbsp;<code>"abc" + ""</code>&nbsp;都是合法分割。</p>

<p>如果 <strong>能构成回文字符串</strong> ，那么请返回&nbsp;<code>true</code>，否则返回<em>&nbsp;</em><code>false</code>&nbsp;。</p>

<p><strong>注意</strong>，&nbsp;<code>x + y</code>&nbsp;表示连接字符串&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>a = "x", b = "y"
<b>输出：</b>true
<b>解释：</b>如果 a 或者 b 是回文串，那么答案一定为 true ，因为你可以如下分割：
a<sub>prefix</sub> = "", a<sub>suffix</sub> = "x"
b<sub>prefix</sub> = "", b<sub>suffix</sub> = "y"
那么 a<sub>prefix</sub> + b<sub>suffix</sub> = "" + "y" = "y" 是回文串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = "abdef", b = "fecab"
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>a = "ulacfd", b = "jizalu"
<b>输出：</b>true
<b>解释：</b>在下标为 3 处分割：
a<sub>prefix</sub> = "ula", a<sub>suffix</sub> = "cfd"
b<sub>prefix</sub> = "jiz", b<sub>suffix</sub> = "alu"
那么 a<sub>prefix</sub> + b<sub>suffix</sub> = "ula" + "alu" = "ulaalu" 是回文串。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>5</sup></code></li>
	<li><code>a.length == b.length</code></li>
	<li><code>a</code> 和&nbsp;<code>b</code>&nbsp;都只包含小写英文字母</li>
</ul>


    
## 方法一：双指针

假设我们取了$a_{prefix}$和$b_{suffix}$，并且组成了$newStr$，那么$newStr$由三部分构成：

> $newStr = s_1 + s_2 + s_3$，且$s_1\in a_{prefix}$，$s_3 \in b_{suffix}$，$s_1$和$s_3$互为回文串，$s_2$自身为回文串。

举个例子：

a = "abkfkzz", b = "xxiouba"

我们令$a_{prefix} = abkfk$，令$b_{suffix} = ba$，则$newStr = abkfkba$

$newStr$由三部分组成：$abkfkba = ab + kfk + ba$

其中$s_1 = ab \in a_{perfix}$，$s_3 = ba \in b_{suffix}$，$ab$和$ba$互为回文串，$s_2 = kfk$自身为回文串。

**那么思路来了：**

一个指针指向$a$串的首部，另一个指针指向$b$串的尾部，当两个指针所指字符相等时，a指针后移b指针前移，直到两指针相遇或两指针所指不同为止。

+ 如果两指针相遇，则说明$a_{perfix}$和$b_{suffix}$已经互为回文，$s_2$为空即可，直接返回$true$
+ 如果两指针所指不同，则a指针前面的部分视为$s_1$，b指针后面的部分视为$s_3$（可以保证$s_1$和$s_3$互为回文），字符串a**或**字符串b 从a指针到b指针的部分 视为$s_2$，只需要判断$s_2$自身是否为回文串即可。若是则返回true，不是则返回false

上面判断了$a_{perfix} + b_{suffix}$的情况，$b_{perfix} + a_{suffix}$则同理

+ 时间复杂度$O(len(a))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool ifSelfPalindrome(string& s, int l, int r) {  // s[l, r]
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }

    bool ifOk(string& a, string& b) {
        int la = 0, lb = b.size() - 1;
        while (la < lb) {
            if (a[la] != b[lb]) {
                if (ifSelfPalindrome(a, la, lb) || ifSelfPalindrome(b, la, lb)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                la++, lb--;
            }
        }
        return true;  // la和lb相遇了
    }
public:
    bool checkPalindromeFormation(string& a, string& b) {
        return ifOk(a, b) || ifOk(b, a);
    }
};
```

#### Python

```python
class Solution:
    def ifSelfPalindrome(self, s: str, l: int, r: int) -> bool:  # s[l, r]
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    def ifOk(self, a: str, b: str) -> bool:
        la = 0
        lb = len(b) - 1
        while la < lb:
            if a[la] != b[lb]:
                if self.ifSelfPalindrome(a, la, lb) or self.ifSelfPalindrome(b, la, lb):
                    return True
                else:
                    return False
            la += 1
            lb -= 1
        return True

    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        return self.ifOk(a, b) or self.ifOk(b, a)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/18/LeetCode%201616.%E5%88%86%E5%89%B2%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%BE%97%E5%88%B0%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129635845](https://letmefly.blog.csdn.net/article/details/129635845)
