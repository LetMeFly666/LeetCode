---
title: 2559.统计范围内的元音字符串数：前缀和
date: 2023-06-02 21:49:55
tags: [题解, LeetCode, 中等, 数组, 字符串, 前缀和]
---

# 【LetMeFly】2559.统计范围内的元音字符串数

力扣题目链接：[https://leetcode.cn/problems/count-vowel-strings-in-ranges/](https://leetcode.cn/problems/count-vowel-strings-in-ranges/)

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> 以及一个二维整数数组 <code>queries</code> 。</p>

<p>每个查询 <code>queries[i] = [l<sub>i</sub>, r<sub>i</sub>]</code> 会要求我们统计在 <code>words</code> 中下标在 <code>l<sub>i</sub></code> 到 <code>r<sub>i</sub></code> 范围内（<strong>包含</strong> 这两个值）并且以元音开头和结尾的字符串的数目。</p>

<p>返回一个整数数组，其中数组的第 <code>i</code> 个元素对应第 <code>i</code> 个查询的答案。</p>

<p><strong>注意：</strong>元音字母是 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code> 和 <code>'u'</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
<strong>输出：</strong>[2,3,0]
<strong>解释：</strong>以元音开头和结尾的字符串是 "aba"、"ece"、"aa" 和 "e" 。
查询 [0,2] 结果为 2（字符串 "aba" 和 "ece"）。
查询 [1,4] 结果为 3（字符串 "ece"、"aa"、"e"）。
查询 [1,1] 结果为 0 。
返回结果 [2,3,0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
<strong>输出：</strong>[3,2,1]
<strong>解释：</strong>每个字符串都满足这一条件，所以返回 [3,2,1] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 40</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成</li>
	<li><code>sum(words[i].length) &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= queries[j][0] &lt;= queries[j][1] &lt;&nbsp;words.length</code></li>
</ul>


    
## 方法一：前缀和

这道题说白了就是给出多次询问，每次问你第l到第r个单词中，有多少个单词的首字母和尾字母都是元音字母。

暴力求解肯定会超时，因此这就需要使用一个技巧，叫“前缀和”。

假设words中有n个单词，那么我们创建一个长度为n+1的数组prefix，prefix[0] = 0。

令$prefix[i + 1]$代表```words的下标0到i的单词中首尾都是元音字母的单词个数```，

那么$prefix[r + 1] - prefix[l]$就是```words的l到r中首尾都是元音字母的单词个数```。

并且prefix[i + 1]可以由prefix[i]和words[i]很轻松地得到。

+ 时间复杂度$O(len(words) + len(queries))$
+ 空间复杂度$O(len(words))$

### AC代码

#### C++

```cpp
inline bool isYuan(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0);
        for (int i = 0; i < words.size(); i++) {
            prefix[i + 1] = prefix[i] + (isYuan(words[i][0]) && isYuan(words[i].back()));  // 这里&&外必须加括号，不然会先执行prefix[i] + isYuan(words[i][0])，再将结果于isYuan(words[i].back())做与运算
            // printf("prefix[%d] = %d, prefix[%d] = %d\n", i, prefix[i], i + 1, prefix[i + 1]);  //**********
        }
        // for (int t : prefix) {printf("%d ", t);} puts("");  //**********
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

def isYuan(c: str) -> bool:
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'

class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        prefix = [0] * (len(words) + 1)
        for i in range(len(words)):
            prefix[i + 1] = prefix[i] + (isYuan(words[i][0]) and isYuan(words[i][-1]))
        return [prefix[q[1] + 1] - prefix[q[0]] for q in queries]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/06/02/LeetCode%202559.%E7%BB%9F%E8%AE%A1%E8%8C%83%E5%9B%B4%E5%86%85%E7%9A%84%E5%85%83%E9%9F%B3%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131014779](https://letmefly.blog.csdn.net/article/details/131014779)
