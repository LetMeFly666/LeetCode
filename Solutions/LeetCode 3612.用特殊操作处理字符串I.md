---
title: 3612.用特殊操作处理字符串 I：I先模拟
date: 2026-06-16 00:10:42
tags: [题解, LeetCode, 中等, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3612.用特殊操作处理字符串 I：I先模拟

力扣题目链接：[https://leetcode.cn/problems/process-string-with-special-operations-i/](https://leetcode.cn/problems/process-string-with-special-operations-i/)

<p>给你一个字符串 <code>s</code>，它由小写英文字母和特殊字符：<code>*</code>、<code>#</code> 和 <code>%</code> 组成。</p>

<p>请根据以下规则从左到右处理 <code>s</code>&nbsp;中的字符，构造一个新的字符串 <code>result</code>：</p>

<ul>
	<li>如果字符是 <strong>小写</strong> 英文字母，则将其添加到 <code>result</code> 中。</li>
	<li>字符 <code>'*'</code> 会&nbsp;<strong>删除</strong> <code>result</code> 中的最后一个字符（如果存在）。</li>
	<li>字符 <code>'#'</code> 会&nbsp;<strong>复制&nbsp;</strong>当前的 <code>result</code> 并&nbsp;<strong>追加&nbsp;</strong>到其自身后面。</li>
	<li>字符 <code>'%'</code> 会&nbsp;<strong>反转&nbsp;</strong>当前的 <code>result</code>。</li>
</ul>

<p>在处理完 <code>s</code> 中的所有字符后，返回最终的字符串 <code>result</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "a#b%*"</span></p>

<p><strong>输出：</strong> <span class="example-io">"ba"</span></p>

<p><strong>解释：</strong></p>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;"><code>i</code></th>
			<th style="border: 1px solid black;"><code>s[i]</code></th>
			<th style="border: 1px solid black;">操作</th>
			<th style="border: 1px solid black;">当前 <code>result</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;"><code>'a'</code></td>
			<td style="border: 1px solid black;">添加 <code>'a'</code></td>
			<td style="border: 1px solid black;"><code>"a"</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;"><code>'#'</code></td>
			<td style="border: 1px solid black;">复制 <code>result</code></td>
			<td style="border: 1px solid black;"><code>"aa"</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;"><code>'b'</code></td>
			<td style="border: 1px solid black;">添加 <code>'b'</code></td>
			<td style="border: 1px solid black;"><code>"aab"</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">3</td>
			<td style="border: 1px solid black;"><code>'%'</code></td>
			<td style="border: 1px solid black;">反转 <code>result</code></td>
			<td style="border: 1px solid black;"><code>"baa"</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">4</td>
			<td style="border: 1px solid black;"><code>'*'</code></td>
			<td style="border: 1px solid black;">删除最后一个字符</td>
			<td style="border: 1px solid black;"><code>"ba"</code></td>
		</tr>
	</tbody>
</table>

<p>因此，最终的 <code>result</code> 是 <code>"ba"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "z*#"</span></p>

<p><strong>输出：</strong> <span class="example-io">""</span></p>

<p><strong>解释：</strong></p>

<table style="border: 1px solid black;">
	<thead>
		<tr>
			<th style="border: 1px solid black;"><code>i</code></th>
			<th style="border: 1px solid black;"><code>s[i]</code></th>
			<th style="border: 1px solid black;">操作</th>
			<th style="border: 1px solid black;">当前 <code>result</code></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="border: 1px solid black;">0</td>
			<td style="border: 1px solid black;"><code>'z'</code></td>
			<td style="border: 1px solid black;">添加 <code>'z'</code></td>
			<td style="border: 1px solid black;"><code>"z"</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">1</td>
			<td style="border: 1px solid black;"><code>'*'</code></td>
			<td style="border: 1px solid black;">删除最后一个字符</td>
			<td style="border: 1px solid black;"><code>""</code></td>
		</tr>
		<tr>
			<td style="border: 1px solid black;">2</td>
			<td style="border: 1px solid black;"><code>'#'</code></td>
			<td style="border: 1px solid black;">复制字符串</td>
			<td style="border: 1px solid black;"><code>""</code></td>
		</tr>
	</tbody>
</table>

<p>因此，最终的 <code>result</code> 是 <code>""</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> 只包含小写英文字母和特殊字符 <code>*</code>、<code>#</code> 和 <code>%</code>。</li>
</ul>


    
## 解题方法：模拟

字符串长度最大20所以暴力模拟就好。遍历字符串：

+ 如果字符是`#`就复制
+ 如果字符是`%`就翻转
+ 如果字符是`*`就看答案字符串是否为空，非空则删除最后一个字符
+ 否则添加当前字符到答案字符串中

以上。

+ 时间复杂度：单次删除、追加$O(1)$，单次复制、翻转$O(n)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-16 00:08:11
 */
class Solution {
public:
    string processStr(string s) {
        string ans;
        for (char c : s) {
            if (c == '#') {
                ans = ans + ans;
            } else if (c == '%') {
                reverse(ans.begin(), ans.end());
            } else if (c == '*') {
                if (ans.size()) {
                    ans.pop_back();
                }
            } else {
                ans += c;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162016929)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/16/LeetCode%203612.%E7%94%A8%E7%89%B9%E6%AE%8A%E6%93%8D%E4%BD%9C%E5%A4%84%E7%90%86%E5%AD%97%E7%AC%A6%E4%B8%B2I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
