---
title: 2712.使所有字符相等的最小成本：脑筋急转弯(遍历)
date: 2025-03-27 22:57:27
tags: [题解, LeetCode, 中等, 贪心, 字符串, 脑筋急转弯]
categories: [题解, LeetCode]
---

# 【LetMeFly】2712.使所有字符相等的最小成本：脑筋急转弯(遍历)

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/](https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/)

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的二进制字符串 <code>s</code> ，你可以对其执行两种操作：</p>

<ul>
	<li>选中一个下标 <code>i</code> 并且反转从下标 <code>0</code> 到下标 <code>i</code>（包括下标 <code>0</code> 和下标 <code>i</code> ）的所有字符，成本为 <code>i + 1</code> 。</li>
	<li>选中一个下标 <code>i</code> 并且反转从下标 <code>i</code> 到下标 <code>n - 1</code>（包括下标 <code>i</code> 和下标 <code>n - 1</code> ）的所有字符，成本为 <code>n - i</code> 。</li>
</ul>

<p>返回使字符串内所有字符 <strong>相等</strong> 需要的 <strong>最小成本</strong> 。</p>

<p><strong>反转</strong> 字符意味着：如果原来的值是 '0' ，则反转后值变为 '1' ，反之亦然。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "0011"
<strong>输出：</strong>2
<strong>解释：</strong>执行第二种操作，选中下标 <code>i = 2</code> ，可以得到 <code>s = "0000" ，成本为 2</code> 。可以证明 2 是使所有字符相等的最小成本。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "010101"
<strong>输出：</strong>9
<strong>解释：</strong>执行第一种操作，选中下标 i = 2 ，可以得到 s = "101101" ，成本为 3 。
执行第一种操作，选中下标 i = 1 ，可以得到 s = "011101" ，成本为 2 。
执行第一种操作，选中下标 i = 0 ，可以得到 s = "111101" ，成本为 1 。
执行第二种操作，选中下标 i = 4 ，可以得到 s = "111110" ，成本为 2 。
执行第二种操作，选中下标 i = 5 ，可以得到 s = "111111" ，成本为 1 。
使所有字符相等的总成本等于 9 。可以证明 9 是使所有字符相等的最小成本。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


    
## 解题方法：遍历

如果$s[i - 1]\neq s[i]$，那么要么翻转$s[0,\dots,i - 1]$，要么翻转$s[i, \dots, n-1]$，才能使$s[i - 1]$和$s[i]$相等。所需要的最小成本是$\min(i, n - i)$。

并且翻转只会改变$s[i - 1]$和$s[i]$是否相同，不会影响其他相邻字符是否相同（相同的字符一起翻转后还是相同，不同的翻转后还是不同）。

累加所有相邻不相同位置的最小翻转成本即为答案。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-27 11:26:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-27 21:52:03
 */
typedef long long ll;
/*
010101
110101
000101
000100
000111
000000
*/
class Solution {
public:
    ll minimumCost(string s) {
        ll ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                ans += min(i, n - i);
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
Date: 2025-03-27 22:02:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-27 22:05:06
'''
class Solution:
    def minimumCost(self, s: str) -> int:
        ans = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                ans += min(i, len(s) - i)
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-27 22:08:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-27 22:11:31
 */
class Solution {
    public long minimumCost(String s) {
        long ans = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(i, s.length() - i);
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
 * @Date: 2025-03-27 22:14:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-27 22:53:45
 * @Description: AC,100.00%,100.00%
 */
package main

func minimumCost(s string) (ans int64) {
    for i := 1; i < len(s); i++ {
        if s[i] != s[i - 1] {
            ans += int64(min(i, len(s) - i))
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146578546)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/27/LeetCode%202712.%E4%BD%BF%E6%89%80%E6%9C%89%E5%AD%97%E7%AC%A6%E7%9B%B8%E7%AD%89%E7%9A%84%E6%9C%80%E5%B0%8F%E6%88%90%E6%9C%AC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
