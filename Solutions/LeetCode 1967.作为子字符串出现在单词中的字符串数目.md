---
title: 1967.作为子字符串出现在单词中的字符串数目：遍历枚举
date: 2026-06-29 15:36:27
tags: [题解, LeetCode, 简单, 数组, 字符串, 子串, 遍历, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】1967.作为子字符串出现在单词中的字符串数目：遍历枚举

力扣题目链接：[https://leetcode.cn/problems/number-of-strings-that-appear-as-substrings-in-word/](https://leetcode.cn/problems/number-of-strings-that-appear-as-substrings-in-word/)

<p>给你一个字符串数组 <code>patterns</code> 和一个字符串 <code>word</code> ，统计 <code>patterns</code> 中有多少个字符串是 <code>word</code> 的子字符串。返回字符串数目。</p>

<p><strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>patterns = ["a","abc","bc","d"], word = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>
- "a" 是 "<em><strong>a</strong></em>bc" 的子字符串。
- "abc" 是 "<em><strong>abc</strong></em>" 的子字符串。
- "bc" 是 "a<em><strong>bc</strong></em>" 的子字符串。
- "d" 不是 "abc" 的子字符串。
patterns 中有 3 个字符串作为子字符串出现在 word 中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>patterns = ["a","b","c"], word = "aaaaabbbbb"
<strong>输出：</strong>2
<strong>解释：</strong>
- "a" 是 "a<em><strong>a</strong></em>aaabbbbb" 的子字符串。
- "b" 是 "aaaaabbbb<em><strong>b</strong></em>" 的子字符串。
- "c" 不是 "aaaaabbbbb" 的字符串。
patterns 中有 2 个字符串作为子字符串出现在 word 中。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>patterns = ["a","a","a"], word = "ab"
<strong>输出：</strong>3
<strong>解释：</strong>patterns 中的每个字符串都作为子字符串出现在 word "<em><strong>a</strong></em>b" 中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= patterns.length &lt;= 100</code></li>
	<li><code>1 &lt;= patterns[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>patterns[i]</code> 和 <code>word</code> 由小写英文字母组成</li>
</ul>


    
## 解题方法：遍历枚举

遍历一遍parttens字符串，看看哪个pattern被包含在word中。

|语言|库函数|
|:--:|:--:|
|C++23|`word.contains(p)`|
|java|`word.contains(p)`|
|rust|`word.contains(p)`|
|python|`p in word`|
|go|`strings.Contains(word, p)`|

+ 时间复杂度$O(nL)$，其中$n=len(word)$，$L=\sum len(patterns_i)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-29 15:07:50
 */
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string& word) {
        int ans = 0;
        for (string& p : patterns) {
            ans += word.contains(p);
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-06-29 15:19:06
'''
from typing import List

class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum(p in word for p in patterns)
```

#### Java

```java
/*
 * @LastEditTime: 2026-06-29 15:23:03
 */
class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int ans = 0;
        for (String p : patterns) {
            if (word.contains(p)) {
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
 * @LastEditTime: 2026-06-29 15:20:20
 */
package main

import "strings"

func numOfStrings(patterns []string, word string) (ans int) {
    for _, p := range patterns {
        if strings.Contains(word, p) {
            ans++
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-06-29 15:22:08
 */
impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        let mut ans = 0;
        for p in patterns.iter() {
            if word.contains(p) {
                ans += 1;
            }
        }
        ans
    }
}
```

+ 执行用时分布0ms，击败100.00%；
+ 消耗内存分布2.17MB，击败100.00%。


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162424300)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/29/LeetCode%201967.%E4%BD%9C%E4%B8%BA%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%87%BA%E7%8E%B0%E5%9C%A8%E5%8D%95%E8%AF%8D%E4%B8%AD%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
