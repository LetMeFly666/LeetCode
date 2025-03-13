---
title: 2451.差值数组不同的字符串
date: 2023-05-25 08:26:56
tags: [题解, LeetCode, 简单, 哈希表, map, 计数, 数学, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2451.差值数组不同的字符串

力扣题目链接：[https://leetcode.cn/problems/odd-string-difference/](https://leetcode.cn/problems/odd-string-difference/)

<p>给你一个字符串数组 <code>words</code>&nbsp;，每一个字符串长度都相同，令所有字符串的长度都为 <code>n</code>&nbsp;。</p>

<p>每个字符串&nbsp;<code>words[i]</code>&nbsp;可以被转化为一个长度为&nbsp;<code>n - 1</code>&nbsp;的&nbsp;<strong>差值整数数组</strong>&nbsp;<code>difference[i]</code>&nbsp;，其中对于&nbsp;<code>0 &lt;= j &lt;= n - 2</code>&nbsp;有&nbsp;<code>difference[i][j] = words[i][j+1] - words[i][j]</code>&nbsp;。注意两个字母的差值定义为它们在字母表中&nbsp;<strong>位置</strong>&nbsp;之差，也就是说&nbsp;<code>'a'</code>&nbsp;的位置是&nbsp;<code>0</code>&nbsp;，<code>'b'</code>&nbsp;的位置是&nbsp;<code>1</code>&nbsp;，<code>'z'</code>&nbsp;的位置是&nbsp;<code>25</code>&nbsp;。</p>

<ul>
	<li>比方说，字符串&nbsp;<code>"acb"</code>&nbsp;的差值整数数组是&nbsp;<code>[2 - 0, 1 - 2] = [2, -1]</code>&nbsp;。</li>
</ul>

<p><code>words</code>&nbsp;中所有字符串 <strong>除了一个字符串以外</strong>&nbsp;，其他字符串的差值整数数组都相同。你需要找到那个不同的字符串。</p>

<p>请你返回<em>&nbsp;</em><code>words</code>中&nbsp;<strong>差值整数数组</strong>&nbsp;不同的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["adc","wzy","abc"]
<b>输出：</b>"abc"
<b>解释：</b>
- "adc" 的差值整数数组是 [3 - 0, 2 - 3] = [3, -1] 。
- "wzy" 的差值整数数组是 [25 - 22, 24 - 25]= [3, -1] 。
- "abc" 的差值整数数组是 [1 - 0, 2 - 1] = [1, 1] 。
不同的数组是 [1, 1]，所以返回对应的字符串，"abc"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["aaa","bob","ccc","ddd"]
<b>输出：</b>"bob"
<b>解释：</b>除了 "bob" 的差值整数数组是 [13, -13] 以外，其他字符串的差值整数数组都是 [0, 0] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= words.length &lt;= 100</code></li>
	<li><code>n == words[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 20</code></li>
	<li><code>words[i]</code>&nbsp;只含有小写英文字母。</li>
</ul>


    
## 方法一：计数

两层循环，第一层循环从0到n-1，枚举某个单词的每个位置。

第二层循环遍历单词表中的每个单词，使用一个哈希表，统计每个单词在当前位置的“difference”。

再遍历一次单词表，如果某个单词当前位置的“difference”只出现了一次，就返回这个单词。

+ 时间复杂度$O(字母个数总和)$
+ 空间复杂度$O(1)$，哈希表中最多存在两个键值

### AC代码

#### C++

```cpp
class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].size();
        for (int j = 0; j < n - 1; j++) {
            unordered_map<int, int> ma;
            for (int i = 0; i < words.size(); i++) {
                ma[words[i][j + 1] - words[i][j]]++;
            }
            for (int i = 0; i < words.size(); i++) {
                if (ma[words[i][j + 1] - words[i][j]] == 1) {
                    return words[i];
                }
            }
        }
        return "";  // FAKE RETURN
    }
};
```

其实哈希表中最多只有两个键值，如果改成手动哈希表的话效率会更高一丢丢（虽然已经100%、99.43%了）

#### Python

```python
from typing import List
from collections import defaultdict

class Solution:
    def oddString(self, words: List[str]) -> str:
        n = len(words[0])
        for j in range(0, n - 1):
            ma = defaultdict(int)
            for word in words:
                ma[ord(word[j + 1]) - ord(word[j])] += 1
            for word in words:
                if ma[ord(word[j + 1]) - ord(word[j])] == 1:
                    return word
        return ""  # FAKE RETURN
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/05/25/LeetCode%202451.%E5%B7%AE%E5%80%BC%E6%95%B0%E7%BB%84%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130859334](https://letmefly.blog.csdn.net/article/details/130859334)
