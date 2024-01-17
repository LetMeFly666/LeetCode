---
title: 2744.最大字符串配对数目
date: 2024-01-17 22:37:15
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, map, 字符串, 模拟]
---

# 【LetMeFly】2744.最大字符串配对数目：哈希表

力扣题目链接：[https://leetcode.cn/problems/find-maximum-number-of-string-pairs/](https://leetcode.cn/problems/find-maximum-number-of-string-pairs/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>words</code>&nbsp;，数组中包含 <strong>互不相同</strong>&nbsp;的字符串。</p>

<p>如果字符串&nbsp;<code>words[i]</code>&nbsp;与字符串 <code>words[j]</code>&nbsp;满足以下条件，我们称它们可以匹配：</p>

<ul>
	<li>字符串&nbsp;<code>words[i]</code>&nbsp;等于&nbsp;<code>words[j]</code>&nbsp;的反转字符串。</li>
	<li><code>0 &lt;= i &lt; j &lt; words.length</code></li>
</ul>

<p>请你返回数组 <code>words</code>&nbsp;中的&nbsp;<strong>最大</strong>&nbsp;匹配数目。</p>

<p>注意，每个字符串最多匹配一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["cd","ac","dc","ca","zz"]
<b>输出：</b>2
<strong>解释：</strong>在此示例中，我们可以通过以下方式匹配 2 对字符串：
- 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc" 并且等于 words[2]。
- 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca" 并且等于 words[3]。
可以证明最多匹配数目是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["ab","ba","cc"]
<b>输出：</b>1
<b>解释：</b>在此示例中，我们可以通过以下方式匹配 1 对字符串：
- 我们将第 0 个字符串与第 1 个字符串匹配，因为 words[1] 的反转字符串 "ab" 与 words[0] 相等。
可以证明最多匹配数目是 1 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>words = ["aa","ab"]
<b>输出：</b>0
<strong>解释：</strong>这个例子中，无法匹配任何字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>words[i].length == 2</code></li>
	<li><code>words</code>&nbsp;包含的字符串互不相同。</li>
	<li><code>words[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 方法一：哈希表

使用哈希表统计每个单词的出现次数。遍历单词数组，假设当前单词是word，将word反转后的字符串在哈希表中出现的次数累加到答案中。之后，将这个单词在哈希表中出现的次数加一。

+ 时间复杂度$O(len(words))$
+ 空间复杂度$O(len(words))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int> ma;
        int ans = 0;
        for (string& word : words) {
            ans += ma[string(1, word[1]) + word[0]];
            ma[word]++;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List
from collections import defaultdict

class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        ma = defaultdict(int)
        ans = 0
        for word in words:
            ans += ma[word[1] + word[0]]
            ma[word] += 1
        return ans
```

# 后记

What the Fantastic?

从昨天（2024.1.14）下午开始，本来很好用的ssh连接github的方式，突然一丁点都不能用了。。。不论是我实验室主机、实验室的另一台主机、阿里云服务器、实验室主机通过手机USB共享的流量（移动数据 和 校园网wifi）（都是来自北京的网），都：

```
ssh: connect to host github.com port 22: Connection timed out
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.
```

我写了个脚本不停地尝试重连，一次都没成功过。Github的ip地址被解析成了新加坡的一个IP，是微软的ip地址好像。

突然之间ssh连Github的方式也被完全地DNS污染了？之前还是10分钟能连上个4分钟，现在直接一下都不让访问了？

目前可用的方式：ssh的方式连ssh.github.com。别再疯了球球了。

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/01/17/LeetCode%202744.%E6%9C%80%E5%A4%A7%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%85%8D%E5%AF%B9%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135662583](https://letmefly.blog.csdn.net/article/details/135662583)
