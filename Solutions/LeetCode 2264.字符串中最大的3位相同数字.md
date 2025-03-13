---
title: 2264.字符串中最大的 3 位相同数字
date: 2025-01-08 15:48:37
tags: [题解, LeetCode, 简单, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2264.字符串中最大的 3 位相同数字：遍历

力扣题目链接：[https://leetcode.cn/problems/largest-3-same-digit-number-in-string/](https://leetcode.cn/problems/largest-3-same-digit-number-in-string/)

<p>给你一个字符串 <code>num</code> ，表示一个大整数。如果一个整数满足下述所有条件，则认为该整数是一个 <strong>优质整数</strong> ：</p>

<ul>
	<li>该整数是 <code>num</code> 的一个长度为 <code>3</code> 的 <strong>子字符串</strong> 。</li>
	<li>该整数由唯一一个数字重复 <code>3</code> 次组成。</li>
</ul>

<p>以字符串形式返回 <strong>最大的优质整数</strong> 。如果不存在满足要求的整数，则返回一个空字符串 <code>""</code> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>子字符串</strong> 是字符串中的一个连续字符序列。</li>
	<li><code>num</code> 或优质整数中可能存在 <strong>前导零</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "6<em><strong>777</strong></em>133339"
<strong>输出：</strong>"777"
<strong>解释：</strong>num 中存在两个优质整数："777" 和 "333" 。
"777" 是最大的那个，所以返回 "777" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = "23<em><strong>000</strong></em>19"
<strong>输出：</strong>"000"
<strong>解释：</strong>"000" 是唯一一个优质整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = "42352338"
<strong>输出：</strong>""
<strong>解释：</strong>不存在长度为 3 且仅由一个唯一数字组成的整数。因此，不存在优质整数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= num.length &lt;= 1000</code></li>
	<li><code>num</code> 仅由数字（<code>0</code> - <code>9</code>）组成</li>
</ul>


    
## 解题方法：遍历

使用一个变量记录最大的优质整数的字符，遍历字符串并不断更新这个最大值即可。

+ 时间复杂度$O(len(num))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-08 15:25:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-08 15:33:22
 */
class Solution {
public:
    string largestGoodInteger(string& num) {
        char M = '/';  // ASCII在0前一个
        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                M = max(M, num[i]);
            }
        }
        return M == '/' ? string() : string(3, M);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-08 15:34:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-08 15:36:15
'''
class Solution:
    def largestGoodInteger(self, s: str) -> str:
        M = '/'
        for i in range(2, len(s)):
            if s[i] == s[i - 1] == s[i - 2]:
                M = max(M, s[i])
        return '' if M == '/' else M * 3
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-08 15:37:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-08 15:41:37
 */
class Solution {
    public String largestGoodInteger(String num) {
        char M = '/';
        for (int i = 2; i < num.length(); i++) {
            if (num.charAt(i) == num.charAt(i - 1) && num.charAt(i) == num.charAt(i - 2)) {
                M = (char) Math.max(M, num.charAt(i));
            }
        }
        return M == '/' ? "" : "" + M + M + M;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-08 15:43:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-08 15:46:23
 */
package main

func largestGoodInteger(num string) string {
    M := byte('/')
    for i := 2; i < len(num); i++ {
        if num[i] > M && num[i] == num[i - 1] && num[i] == num[i - 2] {
            M = num[i]
        }
    }
    if M == '/' {
        return ""
    }
    return string(M) + string(M) + string(M)
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/08/LeetCode%202264.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%843%E4%BD%8D%E7%9B%B8%E5%90%8C%E6%95%B0%E5%AD%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145011261](https://letmefly.blog.csdn.net/article/details/145011261)
