---
title: 3216.交换后字典序最小的字符串
date: 2024-10-30 12:49:17
tags: [题解, LeetCode, 简单, 贪心, 字符串, 模拟, 遍历]
---

# 【LetMeFly】3216.交换后字典序最小的字符串：贪心(模拟)

力扣题目链接：[https://leetcode.cn/problems/lexicographically-smallest-string-after-a-swap/](https://leetcode.cn/problems/lexicographically-smallest-string-after-a-swap/)

<p>给你一个仅由数字组成的字符串 <code>s</code>，在最多交换一次 <strong>相邻 </strong>且具有相同 <strong>奇偶性 </strong>的数字后，返回可以得到的<span data-keyword="lexicographically-smaller-string">字典序最小的字符串</span>。</p>

<p>如果两个数字都是奇数或都是偶数，则它们具有相同的奇偶性。例如，5 和 9、2 和 4 奇偶性相同，而 6 和 9 奇偶性不同。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "45320"</span></p>

<p><strong>输出：</strong> <span class="example-io">"43520"</span></p>

<p><strong>解释：</strong></p>

<p><code>s[1] == '5'</code> 和 <code>s[2] == '3'</code> 都具有相同的奇偶性，交换它们可以得到字典序最小的字符串。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "001"</span></p>

<p><strong>输出：</strong> <span class="example-io">"001"</span></p>

<p><strong>解释：</strong></p>

<p>无需进行交换，因为 <code>s</code> 已经是字典序最小的。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由数字组成。</li>
</ul>

## 解题方法：贪心

想要字符串字典序尽可能小，那是自然是越靠前的字符越小越好。

也就是说，前面字符能变小的话(哪怕只能变小一丢丢)，不论后面字符能变小多少，就一定还是变小前面的而不变后面的。

因此只需要从前到后遍历字符串，如果相邻两个字符串满足交换规则且前面字符串大于后面字符串，就交换二者并返回。

+ 时间复杂度$O(len(s))$
+ 空间复杂度：对于可变字符串的编程语言如C++，$O(1)$；对于不可变字符串的编程语言如Python、Go、Java，$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] > s[i] && s[i - 1] % 2 == s[i] % 2) {
                swap(s[i - 1], s[i]);
                return s;
            }
        }
        return s;
    }
};
```

#### Python

```python
class Solution:
    def getSmallestString(self, s: str) -> str:
        temp = list(s)
        for i in range(1, len(s)):
            if ord(temp[i - 1]) > ord(temp[i]) and ord(temp[i - 1]) % 2 == ord(temp[i]) % 2:
                temp[i - 1], temp[i] = temp[i], temp[i - 1]
                break
        return ''.join(temp)

```

#### Go

```go
package main

func getSmallestString(s string) string {
    temp := []byte(s)
    for i := 1; i < len(s); i++ {
        if s[i - 1] > s[i] && s[i - 1] % 2 == s[i] % 2 {
            temp[i - 1], temp[i] = s[i], s[i - 1]
            return string(temp)
        }
    }
    return s
}
```

#### Java

```java
class Solution {
    public String getSmallestString(String s) {
        char[] tempS = s.toCharArray();
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) > s.charAt(i) && s.charAt(i - 1) % 2 == s.charAt(i) % 2) {
                char temp = s.charAt(i);
                tempS[i] = tempS[i - 1];
                tempS[i - 1] = temp;
                // return tempS.toString();  // 不可，不然"45320"会变成"[C@5010be6"
                return new String(tempS);
            }
        }
        return s;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/30/LeetCode%203216.%E4%BA%A4%E6%8D%A2%E5%90%8E%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143362223](https://letmefly.blog.csdn.net/article/details/143362223)
