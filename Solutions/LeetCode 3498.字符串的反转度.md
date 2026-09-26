---
title: 3498.字符串的反转度：一次遍历
date: 2026-09-20 10:45:25
tags: [题解, LeetCode, 简单, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3498.字符串的反转度：一次遍历

力扣题目链接：[https://leetcode.cn/problems/reverse-degree-of-a-string/](https://leetcode.cn/problems/reverse-degree-of-a-string/)

<p>给你一个字符串 <code>s</code>，计算其 <strong>反转度</strong>。</p>

<p><strong>反转度</strong>的计算方法如下：</p>

<ol>
	<li>对于每个字符，将其在 <strong>反转</strong> 字母表中的位置（<code>'a'</code> = 26, <code>'b'</code> = 25, ..., <code>'z'</code> = 1）与其在字符串中的位置（下标从<strong>1 </strong>开始）相乘。</li>
	<li>将这些乘积加起来，得到字符串中所有字符的和。</li>
</ol>

<p>返回 <strong>反转度</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "abc"</span></p>

<p><strong>输出：</strong> <span class="example-io">148</span></p>

<p><strong>解释：</strong></p>

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">字母</th>
			<th style="border: 1px solid black;">反转字母表中的位置</th>
			<th style="border: 1px solid black;">字符串中的位置</th>
			<th style="border: 1px solid black;">乘积</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>'a'</code></td>
			<td style="border: 1px solid black;">26</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">26</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>'b'</code></td>
			<td style="border: 1px solid black;">25</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">50</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>'c'</code></td>
			<td style="border: 1px solid black;">24</td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">72</td>
		</tr>
	</tbody>
</table>

<p>反转度是 <code>26 + 50 + 72 = 148</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "zaza"</span></p>

<p><strong>输出：</strong> <span class="example-io">160</span></p>

<p><strong>解释：</strong></p>

<table style="border: 1px solid black;">
	<tbody>
		<tr>
			<th style="border: 1px solid black;">字母</th>
			<th style="border: 1px solid black;">反转字母表中的位置</th>
			<th style="border: 1px solid black;">字符串中的位置</th>
			<th style="border: 1px solid black;">乘积</th>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>'z'</code></td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">1</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>'a'</code></td>
			<td style="border: 1px solid black;">26</td>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;">52</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>'z'</code></td>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;">3</td>
		</tr>
		<tr>
			<td style="border: 1px solid black;"><code>'a'</code></td>
			<td style="border: 1px solid black;">26</td>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;">104</td>
		</tr>
	</tbody>
</table>
</div>

<p>反转度是 <code>1 + 52 + 3 + 104 = 160</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 仅包含小写字母。</li>
</ul>


    
## 解题方法：一次遍历

遍历字符串，下标为$i$的字符`c`累加到答案中的值为$(i+1) \times (26 - (c - 'a'))$。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-20 10:27:58
 */
class Solution {
public:
    int reverseDegree(const string& s) {
        int ans = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            // cout << (27 - s[i] + 'a') << " * " << i + 1 << endl;
            ans += (i + 1) * (26 - s[i] + 'a');
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-09-20 10:42:23
'''
class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum((i + 1) * (26 - ord(c) + ord('a')) for i, c in enumerate(s))
```

#### Java

```java
/*
 * @LastEditTime: 2026-09-20 10:40:05
 */
class Solution {
    public int reverseDegree(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += (i + 1) * (26 - s.charAt(i) + 'a');
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-09-20 10:34:15
 */
package main

func reverseDegree(s string) (ans int) {
    for i, c := range s {
        ans += (i + 1) * (26 - int(c - 'a'))
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-09-20 10:44:41
 */
impl Solution {
    pub fn reverse_degree(s: String) -> i32 {
        let mut ans = 0;
        for (i, c) in s.chars().enumerate() {
            ans += (i as i32 + 1) * (26 - c as i32 + 'a' as i32);
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166115675)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/20/LeetCode%203498.%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%8F%8D%E8%BD%AC%E5%BA%A6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
