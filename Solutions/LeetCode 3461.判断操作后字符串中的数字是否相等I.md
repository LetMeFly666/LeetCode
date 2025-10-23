---
title: 3461.判断操作后字符串中的数字是否相等 I：简单题简单做的时候到了
date: 2025-10-23 23:50:07
tags: [题解, LeetCode, 简单, 数学, 字符串, 组合数学, 数论, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3461.判断操作后字符串中的数字是否相等 I：简单题简单做的时候到了

力扣题目链接：[https://leetcode.cn/problems/check-if-digits-are-equal-in-string-after-operations-i/](https://leetcode.cn/problems/check-if-digits-are-equal-in-string-after-operations-i/)

<p>给你一个由数字组成的字符串 <code>s</code>&nbsp;。重复执行以下操作，直到字符串恰好包含&nbsp;<strong>两个&nbsp;</strong>数字：</p>

<ul>
	<li>从第一个数字开始，对于 <code>s</code> 中的每一对连续数字，计算这两个数字的和&nbsp;<strong>模&nbsp;</strong>10。</li>
	<li>用计算得到的新数字依次替换 <code>s</code>&nbsp;的每一个字符，并保持原本的顺序。</li>
</ul>

<p>如果 <code>s</code>&nbsp;最后剩下的两个数字 <strong>相同</strong> ，返回 <code>true</code>&nbsp;。否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "3902"</span></p>

<p><strong>输出：</strong> <span class="example-io">true</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>一开始，<code>s = "3902"</code></li>
	<li>第一次操作：
	<ul>
		<li><code>(s[0] + s[1]) % 10 = (3 + 9) % 10 = 2</code></li>
		<li><code>(s[1] + s[2]) % 10 = (9 + 0) % 10 = 9</code></li>
		<li><code>(s[2] + s[3]) % 10 = (0 + 2) % 10 = 2</code></li>
		<li><code>s</code> 变为 <code>"292"</code></li>
	</ul>
	</li>
	<li>第二次操作：
	<ul>
		<li><code>(s[0] + s[1]) % 10 = (2 + 9) % 10 = 1</code></li>
		<li><code>(s[1] + s[2]) % 10 = (9 + 2) % 10 = 1</code></li>
		<li><code>s</code> 变为 <code>"11"</code></li>
	</ul>
	</li>
	<li>由于 <code>"11"</code> 中的数字相同，输出为 <code>true</code>。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "34789"</span></p>

<p><strong>输出：</strong> <span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>一开始，<code>s = "34789"</code>。</li>
	<li>第一次操作后，<code>s = "7157"</code>。</li>
	<li>第二次操作后，<code>s = "862"</code>。</li>
	<li>第三次操作后，<code>s = "48"</code>。</li>
	<li>由于 <code>'4' != '8'</code>，输出为 <code>false</code>。</li>
</ul>

<p>&nbsp;</p>
</div>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由数字组成。</li>
</ul>


    
## 解题方法：模拟：等II的时候再使用更低时间复杂度的算法吧

当数组长度大于2时，不断取相邻两个元素求和并对10取模，最终返回剩下的两个元素是否相同。

tips1：若真的使用字符来一直模拟，可以提前算出两个`'0'`和一个<code>`</code>的ASCII码相等。

tips：也可以使用int8或int数组来存储，不用真的一直字符串操作。

+ 时间复杂度$O(len(s)^2)$
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-23 23:24:34
 */
/*
>>> ord('0')
48
>>> ord('0') * 2
96
>>> chr(96)   
'`'
>>> ord('`')
96
*/
class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string newS;
            for (int i = 1; i < s.size(); i++) {
                // cout << '(' << s[i - 1] << '+' << s[i] << " - '`') % 10 + '0' = " << char((s[i - 1] + s[i] - '`') % 10 + '0') << endl;
                newS.push_back((s[i - 1] + s[i] - '`') % 10 + '0');
            }
            s = move(newS);
            // cout << s << endl;
        }
        return s[0] == s[1];
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-10-23 23:28:23
'''
class Solution:
    def hasSameDigits(self, s: str) -> bool:
        a = list(map(lambda c: ord(c) - ord('0'), s))
        while len(a) > 2:
            b = [0] * (len(a) - 1)
            for i in range(len(a) - 1):
                b[i] = (a[i] + a[i + 1]) % 10
            a = b
        return a[0] == a[1]
```

#### Java

```java
/*
 * @LastEditTime: 2025-10-23 23:42:40
 */
class Solution {
    public boolean hasSameDigits(String s) {
        int[] a = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            a[i] = (s.charAt(i) - '0');
        }
        while (a.length > 2) {
            int[] b = new int[a.length - 1];
            for (int i = 0; i < b.length; i++) {
                b[i] = (a[i] + a[i + 1]) % 10;
            }
            a = b;
        }
        return a[0] == a[1];
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-10-23 23:32:07
 */
package main

func hasSameDigits(s string) bool {
    a := make([]byte, len(s))
    for i := range s {
        a[i] = s[i] - '0'
    }
    for len(a) > 2 {
        b := make([]byte,len(a) - 1)
        for i := range b {
            b[i] = (a[i] + a[i + 1]) % 10
        }
        a = b
    }
    return a[0] == a[1]
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-10-23 23:46:40
 */
impl Solution {
    pub fn has_same_digits(s: String) -> bool {
        let mut a: Vec<u8> = s.chars()
            .map(|c| c.to_digit(10).unwrap() as u8)
            .collect();
        while a.len() > 2 {
            let mut b = Vec::with_capacity(a.len() - 1);
            for i in 0..a.len() - 1 {
                b.push((a[i] + a[i + 1]) % 10);
            }
            a = b;
        }
        a[0] == a[1]
    }
}
```

## End

今天发现CSDN给我发私信说准备把我一些文章变为VIP可见，实在受之有愧，拒绝之。

![突然发现的通知](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/f359a47bf52746bd970139258bb99da0.jpeg)

![拒绝之](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/2896694c1aa5453d991acba075607fbd.jpeg)

可能是因为快1024了官方想要再整一些活动吧。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/153800840)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/10/23/LeetCode%203461.%E5%88%A4%E6%96%AD%E6%93%8D%E4%BD%9C%E5%90%8E%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%95%B0%E5%AD%97%E6%98%AF%E5%90%A6%E7%9B%B8%E7%AD%89I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
