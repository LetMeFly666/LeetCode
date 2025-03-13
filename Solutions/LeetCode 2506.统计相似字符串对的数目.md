---
title: 2506.统计相似字符串对的数目：哈希表+位运算
date: 2025-02-22 11:54:41
tags: [题解, LeetCode, 简单, 位运算, 数组, 哈希表, map, 字符串, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2506.统计相似字符串对的数目：哈希表+位运算

力扣题目链接：[https://leetcode.cn/problems/count-pairs-of-similar-strings/](https://leetcode.cn/problems/count-pairs-of-similar-strings/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 。</p>

<p>如果两个字符串由相同的字符组成，则认为这两个字符串 <strong>相似</strong> 。</p>

<ul>
	<li>例如，<code>"abca"</code> 和 <code>"cba"</code> 相似，因为它们都由字符 <code>'a'</code>、<code>'b'</code>、<code>'c'</code> 组成。</li>
	<li>然而，<code>"abacba"</code> 和 <code>"bcfd"</code> 不相似，因为它们不是相同字符组成的。</li>
</ul>

<p>请你找出满足字符串&nbsp;<code>words[i]</code><em> </em>和<em> </em><code>words[j]</code> 相似的下标对<em> </em><code>(i, j)</code><em> </em>，并返回下标对的数目，其中 <code>0 &lt;= i &lt; j &lt;= words.length - 1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["aba","aabb","abcd","bac","aabc"]
<strong>输出：</strong>2
<strong>解释：</strong>共有 2 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
- i = 3 且 j = 4 ：words[3] 和 words[4] 只由字符 'a'、'b' 和 'c' 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["aabb","ab","ba"]
<strong>输出：</strong>3
<strong>解释：</strong>共有 3 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。 
- i = 0 且 j = 2 ：words[0] 和 words[2] 只由字符 'a' 和 'b' 组成。 
- i = 1 且 j = 2 ：words[1] 和 words[2] 只由字符 'a' 和 'b' 组成。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["nba","cba","dba"]
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足条件的下标对，返回 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
</ul>


    
## 解题方法：哈希表+位运算

这道题不考虑每个字符的出现次数，只考虑是否出现过。一共26个字母，因此可以使用一个整数二进制下的低26位分别代表每个字母是否出现过（可以将之称为`状态码`）。

使用一个哈希表统计每种`状态码`的出现次数。遍历字符串数组，对于一个字符串，计算出它的`状态码`后：

1. 先累加这种`状态码`的出现次数到答案中
2. 更新哈希表中这种`状态码`的出现次数+1

即可。

+ 时间复杂度$O(N)$，其中$N$是总字符数。
+ 空间复杂度$O(len(words))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-22 11:13:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-22 11:15:31
 */
class Solution {
private:
    inline int code(string& s) {
        int ans = 0;
        for (char c : s) {
            ans |= 1 << (c - 'a');
        }
        return ans;
    }
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> ma;
        int ans = 0;
        for (string& s : words) {
            int c = code(s);
            ans += ma[c];
            ma[c]++;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-22 11:16:23
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-22 11:19:02
'''
from typing import List
from collections import defaultdict

class Solution:
    def code(self, word: str) -> int:
        ans = 0
        for c in word:
            ans |= 1 << (ord(c) - 97)
        return ans
    
    def similarPairs(self, words: List[str]) -> int:
        ans = 0
        ma = defaultdict(int)
        for s in words:
            c = self.code(s)
            ans += ma[c]
            ma[c] += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-22 11:16:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-22 11:23:31
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    private int code(String s) {
        int ans = 0;
        for (char c : s.toCharArray()) {
            ans |= 1 << (c - 'a');
        }
        return ans;
    }

    public int similarPairs(String[] words) {
        Map<Integer, Integer> ma = new HashMap<>();
        int ans = 0;
        for (String s : words) {
            int c = code(s);
            ans += ma.getOrDefault(c, 0);
            ma.merge(c, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-22 11:16:35
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-22 11:27:11
 */
package main


func code_CPOSS(s string) (ans int) {
    for _, c := range s {
        ans |= 1 << (c - 'a')
    }
    return
}

func similarPairs(words []string) (ans int) {
    ma := map[int]int{}
    for _, s := range words {
        c := code_CPOSS(s)
        ans += ma[c]
        ma[c]++
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145792949)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/22/LeetCode%202506.%E7%BB%9F%E8%AE%A1%E7%9B%B8%E4%BC%BC%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%AF%B9%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)

PS: CSDN昨日(2025.02.21)[主页](https://www.csdn.net/)改版(更新)了。
