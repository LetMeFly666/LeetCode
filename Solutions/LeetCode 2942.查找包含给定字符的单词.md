---
title: 2942.查找包含给定字符的单词：使用库函数完成
date: 2025-05-24 21:41:41
tags: [题解, LeetCode, 简单, 数组, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2942.查找包含给定字符的单词：使用库函数完成

力扣题目链接：[https://leetcode.cn/problems/find-words-containing-character/](https://leetcode.cn/problems/find-words-containing-character/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串数组&nbsp;<code>words</code>&nbsp;和一个字符&nbsp;<code>x</code>&nbsp;。</p>

<p>请你返回一个 <strong>下标数组</strong>&nbsp;，表示下标在数组中对应的单词包含字符 <code>x</code>&nbsp;。</p>

<p><b>注意</b>&nbsp;，返回的数组可以是&nbsp;<strong>任意</strong>&nbsp;顺序。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["leet","code"], x = "e"
<b>输出：</b>[0,1]
<b>解释：</b>"e" 在两个单词中都出现了："l<em><strong>ee</strong></em>t" 和 "cod<em><strong>e</strong></em>" 。所以我们返回下标 0 和 1 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["abc","bcd","aaaa","cbc"], x = "a"
<b>输出：</b>[0,2]
<b>解释：</b>"a" 在 "<em><strong>a</strong></em>bc" 和 "<em><strong>aaaa</strong></em>" 中出现了，所以我们返回下标 0 和 2 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>words = ["abc","bcd","aaaa","cbc"], x = "z"
<b>输出：</b>[]
<b>解释：</b>"z" 没有在任何单词中出现。所以我们返回空数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>x</code>&nbsp;是一个小写英文字母。</li>
	<li><code>words[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：模拟

遍历字符串数组中的每个字符串，如果字符串中包含字符`x`，则将字符串对应下标添加到答案数组中。

+ 时间复杂度$O(\sum)$，其中$\sum$是字符数之和
+ 空间复杂度$O(1)$，力扣函数返回值不计入空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-24 21:30:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 21:34:02
 */
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
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
Date: 2025-05-24 21:30:36
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-24 21:37:05
'''
from typing import List

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        return [i for i in range(len(words)) if x in words[i]]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-24 21:30:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 21:38:47
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            if (words[i].indexOf(x) >= 0) {
                ans.add(i);
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
 * @Date: 2025-05-24 21:30:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-24 21:40:52
 */
package main

import "strings"

func findWordsContaining(words []string, x byte) (ans []int) {
    for i, word := range words {
        if strings.IndexByte(word, x) >= 0 {
            ans = append(ans, i)
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148197875)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/24/LeetCode%202942.%E6%9F%A5%E6%89%BE%E5%8C%85%E5%90%AB%E7%BB%99%E5%AE%9A%E5%AD%97%E7%AC%A6%E7%9A%84%E5%8D%95%E8%AF%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
