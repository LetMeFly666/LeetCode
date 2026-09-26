---
title: 744.寻找比目标字母大的最小字母：遍历或二分
date: 2026-01-31 14:05:22
tags: [题解, LeetCode, 简单, 数组, 二分查找, 二分, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】744.寻找比目标字母大的最小字母：遍历或二分

力扣题目链接：[https://leetcode.cn/problems/find-smallest-letter-greater-than-target/](https://leetcode.cn/problems/find-smallest-letter-greater-than-target/)

<p>给你一个字符数组 <code>letters</code>，该数组按<strong>非递减顺序</strong>排序，以及一个字符 <code>target</code>。<code>letters</code>&nbsp;里<strong>至少有两个不同</strong>的字符。</p>

<p>返回&nbsp;<code>letters</code>&nbsp;中大于 <code>target</code> 的最小的字符。如果不存在这样的字符，则返回&nbsp;<code>letters</code> 的第一个字符。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>letters = ['c', 'f', 'j']，target = 'a'
<strong>输出:</strong> 'c'
<strong>解释：</strong>letters 中字典上比 'a' 大的最小字符是 'c'。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> letters = ['c','f','j'], target = 'c'
<strong>输出:</strong> 'f'
<strong>解释：</strong>letters 中字典顺序上大于 'c' 的最小字符是 'f'。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> letters = ['x','x','y','y'], target = 'z'
<strong>输出:</strong> 'x'
<strong>解释：</strong>letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= letters.length &lt;= 10<sup>4</sup></code></li>
	<li><code>letters[i]</code>&nbsp;是一个小写字母</li>
	<li><code>letters</code> 按<strong>非递减顺序</strong>排序</li>
	<li><code>letters</code> 最少包含两个不同的字母</li>
	<li><code>target</code> 是一个小写字母</li>
</ul>


    
## 解题方法：二分或遍历

二分：二分查找第一个大于`target`的元素位置即可（`upper_bound`）

遍历：从头到尾遍历就好。

+ 时间复杂度：二分$O(log n)$遍历$O(n)$
+ 空间复杂度：$O(1)$

### AC代码

C++和Python用的二分（因为调库很方便），Go、Java和Rust使用的遍历。

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-31 13:50:40
 */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-01-31 13:56:59
'''
from typing import List
from bisect import bisect_right

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        idx = bisect_right(letters, target)
        return letters[0] if idx == len(letters) else letters[idx]
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-31 14:01:16
 */
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        for (int i = 0; i < letters.length; i++) {
            if (letters[i] > target) {
                return letters[i];
            }
        }
        return letters[0];
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-01-31 13:59:57
 */
package main

func nextGreatestLetter(letters []byte, target byte) byte {
    for _, c := range letters {
        if c > target {
            return c
        }
    }
    return letters[0]
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-31 14:03:50
 */
impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        for i in 0..letters.len() {
            if letters[i] > target {
                return letters[i];
            }
        }
        letters[0]
    }
}
```

+ 执行用时分布0ms击败100.00%
+ 消耗内存分布2.72MB击败97.14%

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/157582186)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/31/LeetCode%200744.%E5%AF%BB%E6%89%BE%E6%AF%94%E7%9B%AE%E6%A0%87%E5%AD%97%E6%AF%8D%E5%A4%A7%E7%9A%84%E6%9C%80%E5%B0%8F%E5%AD%97%E6%AF%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
