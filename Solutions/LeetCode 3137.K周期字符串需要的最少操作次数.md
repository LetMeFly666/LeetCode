---
title: 3137.K 周期字符串需要的最少操作次数
date: 2024-08-17 17:32:05
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 计数]
---

# 【LetMeFly】3137.K 周期字符串需要的最少操作次数：哈希表计数

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-operations-to-make-word-k-periodic/](https://leetcode.cn/problems/minimum-number-of-operations-to-make-word-k-periodic/)

<p>给你一个长度为 <code>n</code> 的字符串 <code>word</code> 和一个整数 <code>k</code> ，其中 <code>k</code> 是 <code>n</code> 的因数。</p>

<p>在一次操作中，你可以选择任意两个下标 <code>i</code> 和 <code>j</code>，其中 <code>0 &lt;= i, j &lt; n</code> ，且这两个下标都可以被 <code>k</code> 整除，然后用从 <code>j</code> 开始的长度为 <code>k</code> 的子串替换从 <code>i</code> 开始的长度为 <code>k</code> 的子串。也就是说，将子串 <code>word[i..i + k - 1]</code> 替换为子串 <code>word[j..j + k - 1]</code> 。</p>

<p>返回使 <code>word</code> 成为 <strong>K 周期字符串</strong> 所需的<strong> 最少</strong> 操作次数。</p>

<p>如果存在某个长度为 <code>k</code> 的字符串 <code>s</code>，使得 <code>word</code> 可以表示为任意次数连接 <code>s</code> ，则称字符串 <code>word</code> 是 <strong>K 周期字符串</strong> 。例如，如果 <code>word == "ababab"</code>，那么 <code>word</code> 就是 <code>s = "ab"</code> 时的 2 周期字符串 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">word = "leetcodeleet", k = 4</span></p>

<p><strong>输出：</strong><span class="example-io" style="
font-family: Menlo,sans-serif;
font-size: 0.85rem;
">1</span></p>

<p><strong>解释：</strong>可以选择 i = 4 和 j = 0 获得一个 4 周期字符串。这次操作后，word 变为 "leetleetleet" 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="
    border-color: var(--border-tertiary);
    border-left-width: 2px;
    color: var(--text-secondary);
    font-size: .875rem;
    margin-bottom: 1rem;
    margin-top: 1rem;
    overflow: visible;
    padding-left: 1rem;
">
<p><strong>输入：</strong><span class="example-io" style="
    font-family: Menlo,sans-serif;
    font-size: 0.85rem;
">word = "leetcoleet", k = 2</span></p>

<p><strong>输出：</strong>3</p>

<p><strong>解释：</strong>可以执行以下操作获得一个 2 周期字符串。</p>

<table border="1" bordercolor="#ccc" cellpadding="5" cellspacing="0" height="146" style="border-collapse:collapse; text-align: center; vertical-align: middle;">
	<tbody>
		<tr>
			<th>i</th>
			<th>j</th>
			<th>word</th>
		</tr>
		<tr>
			<td style="padding: 5px 15px;">0</td>
			<td style="padding: 5px 15px;">2</td>
			<td style="padding: 5px 15px;">etetcoleet</td>
		</tr>
		<tr>
			<td style="padding: 5px 15px;">4</td>
			<td style="padding: 5px 15px;">0</td>
			<td style="padding: 5px 15px;">etetetleet</td>
		</tr>
		<tr>
			<td style="padding: 5px 15px;">6</td>
			<td style="padding: 5px 15px;">0</td>
			<td style="padding: 5px 15px;">etetetetet</td>
		</tr>
	</tbody>
</table>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= word.length</code></li>
	<li><code>k</code> 能整除 <code>word.length</code> 。</li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
</ul>


    
## 解题方法：哈希表计数

题目意思是将字符串分成$\frac{len(word)}{k}$个块，然后每次可以使用一个块去覆盖另一个块，问至少需要多少次能把所有块变成一样的。

那当然是哪一块最多，就尽量把所有的其他块变成那一块。因此，使用哈希表统计每种块的出现次数，将其他所有块变成这一块就好了。

+ 时间复杂度$O(len(word))$
+ 空间复杂度$O(k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string& word, int k) {
        unordered_map<string, int> ma;
        int maxTimes = 1;
        for (int i = 0; i < word.size(); i += k) {
            maxTimes = max(maxTimes, ++ma[word.substr(i, k)]);
        }
        return word.size() / k - maxTimes;
    }
};
```

#### Go

```go
package main

func minimumOperationsToMakeKPeriodic(word string, k int) int {
    maxTimes := 1
    ma := map[string]int{}
    for i := 0; i < len(word); i += k {
        ma[word[i: i + k]]++
        maxTimes = max(maxTimes, ma[word[i: i + k]])
    }
    return len(word) / k - maxTimes
}
```

#### Python

```python
from typing import List
from collections import defaultdict

class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        ma = defaultdict(int)
        maxTimes = 1
        for i in range(0, len(word), k):
            ma[word[i: i + k]] += 1
            maxTimes = max(maxTimes, ma[word[i: i + k]])
        return len(word) // k - maxTimes

```

使用Counter一行版：

```python
from collections import Counter

class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        return len(word) // k - max(Counter(word[i : i + k] for i in range(0, len(word), k)).values())
```

#### Java

```java
import java.util.HashMap;

class Solution {
    public int minimumOperationsToMakeKPeriodic(String word, int k) {
        int maxTimes = 1;
        HashMap<String, Integer> ma = new HashMap<String, Integer>();
        for (int i = 0; i < word.length(); i += k) {
            // maxTimes = ma.merge(word.substring(i, i + k), 1, (a, b) -> {a += b; maxTimes = Math.max(maxTimes, a); return a;});
            maxTimes = Math.max(maxTimes, ma.merge(word.substring(i, i + k), 1, Integer::sum));
        }
        return word.length() / k - maxTimes;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/17/LeetCode%203137.K%E5%91%A8%E6%9C%9F%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141284611](https://letmefly.blog.csdn.net/article/details/141284611)
