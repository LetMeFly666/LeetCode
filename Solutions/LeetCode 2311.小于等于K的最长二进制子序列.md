---
title: 2311.小于等于 K 的最长二进制子序列：贪心（先选0再选1）-好像还是比灵神写的清晰些
date: 2025-06-26 22:46:22
tags: [题解, LeetCode, 中等, 贪心, 字符串, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】2311.小于等于 K 的最长二进制子序列：贪心（先选0再选1）-好像还是比灵神写的清晰些

力扣题目链接：[https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/](https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/)

<p>给你一个二进制字符串&nbsp;<code>s</code>&nbsp;和一个正整数&nbsp;<code>k</code>&nbsp;。</p>

<p>请你返回 <code>s</code>&nbsp;的 <strong>最长</strong>&nbsp;子序列，且该子序列对应的 <strong>二进制</strong>&nbsp;数字小于等于 <code>k</code>&nbsp;。</p>

<p>注意：</p>

<ul>
	<li>子序列可以有 <strong>前导 0</strong>&nbsp;。</li>
	<li>空字符串视为&nbsp;<code>0</code>&nbsp;。</li>
	<li><strong>子序列</strong>&nbsp;是指从一个字符串中删除零个或者多个字符后，不改变顺序得到的剩余字符序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "1001010", k = 5
<b>输出：</b>5
<b>解释：</b>s 中小于等于 5 的最长子序列是 "00010" ，对应的十进制数字是 2 。
注意 "00100" 和 "00101" 也是可行的最长子序列，十进制分别对应 4 和 5 。
最长子序列的长度为 5 ，所以返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "00101001", k = 1
<b>输出：</b>6
<b>解释：</b>"000001" 是 s 中小于等于 1 的最长子序列，对应的十进制数字是 1 。
最长子序列的长度为 6 ，所以返回 6 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> 要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code> 。</li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：贪心

二话不说选中所有0，接着从右往左开始选1，全程保证所选元素不超过$k$。

Why?

选1可能导致没法选后面的0，选0不会影响后面的选择。如果选1导致无法选后面的0，那么不如舍弃这个1直接替换成0。综上**先选0更优**。

选1好说，当然是**从低位往高位选1**啦。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-26 22:16:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-26 22:43:01
 */
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0, val = 0, k_length = 32 - __builtin_clz(k), n = s.size();  // k=0时k_length=0计算错误也不受影响
        for (int i = 0; i < n; i++) {
            if (s[n - i - 1] == '0') {
                ans++;
                continue;
            }
            if (i < k_length && val + (1 << i) <= k) {
                val += 1 << i;
                ans++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-06-26 22:16:30
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-26 22:38:54
'''
class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        ans, val, k_length = 0, 0, k.bit_length()
        for i, c in enumerate(s[::-1]):
            if c == '0':
                ans += 1
                continue
            if i < k_length and val + (1 << i) <= k:
                ans += 1
                val += 1 << i
        return ans
```

Python也可以理解为[依次删除左边1直到int(s)<=k](https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/solutions/3701151/xiao-yu-deng-yu-k-de-zui-chang-er-jin-zh-7vk8/comments/3064179/)。

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-26 22:16:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-26 22:45:37
 */
class Solution {
    public int longestSubsequence(String s, int k) {
        int ans = 0, n = s.length(), lenK = 32 - Integer.numberOfLeadingZeros(k), val = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(n - i - 1) == '0') {
                ans++;
                continue;
            }
            if (i < lenK && val + (1 << i) <= k) {
                val += 1 << i;
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-06-26 22:16:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-26 22:39:55
 */
package main

import "math/bits"

func longestSubsequence(s string, k int) (ans int) {
    val, n, lenK := 0, len(s), bits.Len(uint(k))
    for i := 0; i < n; i++ {
        if s[n - i - 1] == '0' {
            ans++
            continue
        }
        if i < lenK && val + (1 << i) <= k {
            ans++
            val += 1 << i
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148935308)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/26/LeetCode%202311.%E5%B0%8F%E4%BA%8E%E7%AD%89%E4%BA%8EK%E7%9A%84%E6%9C%80%E9%95%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
