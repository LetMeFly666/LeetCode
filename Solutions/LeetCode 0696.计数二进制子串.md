---
title: 696.计数二进制子串：一次遍历
date: 2026-02-19 11:34:08
tags: [题解, LeetCode, 简单, 字符串, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】696.计数二进制子串：一次遍历

力扣题目链接：[https://leetcode.cn/problems/count-binary-substrings/](https://leetcode.cn/problems/count-binary-substrings/)

<p>给定一个字符串&nbsp;<code>s</code>，统计并返回具有相同数量 <code>0</code> 和 <code>1</code> 的非空（连续）子字符串的数量，并且这些子字符串中的所有 <code>0</code> 和所有 <code>1</code> 都是成组连续的。</p>

<p>重复出现（不同位置）的子串也要统计它们出现的次数。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "00110011"
<strong>输出：</strong>6
<strong>解释：</strong>6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "10101"
<strong>输出：</strong>4
<strong>解释：</strong>有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 为 <code>'0'</code> 或 <code>'1'</code></li>
</ul>


    
## 解题方法：遍历

3个连续的`1`紧接着2个连续的`0`一共可以组成2个等01连续子串（`11100`的等01连续子串有`1100`和`10`），因此我们只需要一次遍历，将字符串变成“连续两个1、连续3个0、连续5个1、...”这种就行了。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-19 11:22:35
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        for (int i = 1, n = s.size(), cnt = 1, lastCnt = 0; i <= n; i++, cnt++) {
            if (i == n || s[i] != s[i - 1]) {
                ans += min(cnt, lastCnt);
                lastCnt = cnt;
                cnt = 0;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-02-19 11:33:22
'''
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        ans = lastCnt = 0
        cnt = 1
        for i in range(1, len(s) + 1):
            if i == len(s) or s[i] != s[i - 1]:
                ans += min(lastCnt, cnt)
                lastCnt = cnt
                cnt = 0
            cnt += 1
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-02-19 11:30:02
 */
class Solution {
    public int countBinarySubstrings(String s) {
        int ans = 0;
        for (int i = 1, n = s.length(), cnt = 1, lastCnt = 0; i <= n; i++) {
            if (i == n || s.charAt(i) != s.charAt(i - 1)) {
                ans += Math.min(cnt, lastCnt);
                lastCnt = cnt;
                cnt = 0;
            }
            cnt++;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-02-19 11:31:44
 */
package main

func countBinarySubstrings(s string) (ans int) {
    lastCnt, cnt := 0, 1
    for i := 1; i <= len(s); i++ {
        if i == len(s) || s[i] != s[i - 1] {
            ans += min(lastCnt, cnt);
            lastCnt = cnt;
            cnt = 0;
        }
        cnt++;
    }
    return;
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-02-19 11:27:37
 */
impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let s = s.as_bytes();  // the type `str` cannot be indexed by `usize`
        let mut ans = 0;
        let mut cnt = 1;
        let mut last_cnt = 0;
        for i in 1..(s.len() + 1) {
            if i == s.len() || s[i] != s[i - 1] {
                ans += cnt.min(last_cnt);
                last_cnt = cnt;
                cnt = 0;
            }
            cnt += 1;
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158206741)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/19/LeetCode%200696.%E8%AE%A1%E6%95%B0%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%90%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
