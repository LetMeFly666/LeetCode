---
title: 2085.统计出现过一次的公共字符串
date: 2024-01-12 19:04:52
tags: [题解, LeetCode, 简单, 数组, 哈希表, map, 字符串, 计数]
---

# 【LetMeFly】2085.统计出现过一次的公共字符串：哈希表

力扣题目链接：[https://leetcode.cn/problems/count-common-words-with-one-occurrence/](https://leetcode.cn/problems/count-common-words-with-one-occurrence/)

<p>给你两个字符串数组&nbsp;<code>words1</code>&nbsp;和&nbsp;<code>words2</code>&nbsp;，请你返回在两个字符串数组中 <strong>都恰好出现一次</strong>&nbsp;的字符串的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
<b>输出：</b>2
<strong>解释：</strong>
- "leetcode" 在两个数组中都恰好出现一次，计入答案。
- "amazing" 在两个数组中都恰好出现一次，计入答案。
- "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
- "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
所以，有 2 个字符串在两个数组中都恰好出现了一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
<b>输出：</b>0
<b>解释：</b>没有字符串在两个数组中都恰好出现一次。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>words1 = ["a","ab"], words2 = ["a","a","a","ab"]
<b>输出：</b>1
<b>解释：</b>唯一在两个数组中都出现一次的字符串是 "ab" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words1.length, words2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words1[i].length, words2[j].length &lt;= 30</code></li>
	<li><code>words1[i]</code> 和&nbsp;<code>words2[j]</code>&nbsp;都只包含小写英文字母。</li>
</ul>


    
## 方法一：哈希表

使用两个哈希表，分别统计两个字符串数组中，每个字符串出现的次数。

（这样，对于一个字符串，我们就能在$O(1)$的时间复杂度内得到这个字符串在两个字符串数组中出现的次数。）

遍历其中一个哈希表，如果这个字符串在两个哈希表中出现的次数都为$1$，则答案个数$+1$。

+ 时间复杂度$O(size(words1) + size(words2))$，其中$size(words_i)$为字符串数组$words_i$的字符个数。
+ 空间复杂度$O(size(words1) + size(words2))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m1, m2;
        for (auto& s : words1) {
            m1[s]++;
        }
        for (auto& s : words2) {
            m2[s]++;
        }
        int ans = 0;
        for (auto&& [str, cnt] : m1) {
            if (cnt == 1 && m2[str] == 1) {
                ans++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        m1, m2 = defaultdict(int), defaultdict(int)
        for s in words1:
            m1[s] += 1
        for s in words2:
            m2[s] += 1
        ans = 0
        for s, cnt in m1.items():
            if cnt == 1 and m2[s] == 1:
                ans += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/12/LeetCode%202085.%E7%BB%9F%E8%AE%A1%E5%87%BA%E7%8E%B0%E8%BF%87%E4%B8%80%E6%AC%A1%E7%9A%84%E5%85%AC%E5%85%B1%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135560255](https://letmefly.blog.csdn.net/article/details/135560255)
