---
title: 2900.最长相邻不相等子序列 I：阅读理解题——O(n)一次遍历(贪心)
date: 2025-05-15 13:27:30
tags: [题解, LeetCode, 简单, 贪心, 数组, 字符串, 动态规划]
categories: [题解, LeetCode]
---

# 【LetMeFly】2900.最长相邻不相等子序列 I：阅读理解题——O(n)一次遍历(贪心)

力扣题目链接：[https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/)

<p>给你一个下标从&nbsp;<strong>0</strong>&nbsp;开始的字符串数组&nbsp;<code>words</code>&nbsp;，和一个下标从 <strong>0</strong>&nbsp;开始的 <strong>二进制</strong>&nbsp;数组&nbsp;<code>groups</code>&nbsp;，两个数组长度都是&nbsp;<code>n</code>&nbsp;。</p>

<p>你需要从&nbsp;<code>words</code>&nbsp;中选出&nbsp;<strong>最长<span data-keyword="subsequence-array">子序列</span></strong>。如果对于序列中的任何两个连续串，二进制数组&nbsp;<code>groups</code>&nbsp;中它们的对应元素不同，则&nbsp;<code>words</code> 的子序列是不同的。</p>

<p>正式来说，你需要从下标&nbsp;<code>[0, 1, ..., n - 1]</code>&nbsp;中选出一个&nbsp;<strong>最长子序列</strong>&nbsp;，将这个子序列记作长度为 <code>k</code> 的&nbsp;<code>[i<sub>0</sub>, i<sub>1</sub>, ..., i<sub>k - 1</sub>]</code>&nbsp;，对于所有满足&nbsp;<code>0 &lt;= j&nbsp;&lt; k - 1</code>&nbsp;的&nbsp;<code>j</code>&nbsp;都有&nbsp;<code>groups[i<sub>j</sub>] != groups[i<sub>j + 1</sub>]</code>&nbsp;。</p>

<p>请你返回一个字符串数组，它是下标子序列&nbsp;<strong>依次</strong>&nbsp;对应&nbsp;<code>words</code>&nbsp;数组中的字符串连接形成的字符串数组。如果有多个答案，返回 <strong>任意</strong> 一个。</p>

<p><b>注意：</b><code>words</code>&nbsp;中的元素是不同的&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["e","a","b"], groups = [0,0,1]
<b>输出：</b>["e","b"]
<strong>解释：</strong>一个可行的子序列是 [0,2] ，因为 groups[0] != groups[2] 。
所以一个可行的答案是 [words[0],words[2]] = ["e","b"] 。
另一个可行的子序列是 [1,2] ，因为 groups[1] != groups[2] 。
得到答案为 [words[1],words[2]] = ["a","b"] 。
这也是一个可行的答案。
符合题意的最长子序列的长度为 2 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["a","b","c","d"], groups = [1,0,1,1]
<b>输出：</b>["a","b","c"]
<b>解释：</b>一个可行的子序列为 [0,1,2] 因为 groups[0] != groups[1] 且 groups[1] != groups[2] 。
所以一个可行的答案是 [words[0],words[1],words[2]] = ["a","b","c"] 。
另一个可行的子序列为 [0,1,3] 因为 groups[0] != groups[1] 且 groups[1] != groups[3] 。
得到答案为 [words[0],words[1],words[3]] = ["a","b","d"] 。
这也是一个可行的答案。
符合题意的最长子序列的长度为 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == words.length == groups.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>groups[i]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
	<li><code>words</code>&nbsp;中的字符串 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>words[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：贪心

这道题描述得很复杂，大概是为了给II做铺垫。读懂题意了倒是也很简单：

> 先不管words数组，只看groups数组。在groups数组中选一些元素使得挑选结果为`0101..`或`101010...`。
>
> 想让挑选的元素尽可能地多，最终返回挑选元素对应下标在words中对应的字符串们。

怎么挑？贪心，能选就选呗。

一次遍历groups数组，若当前元素和上一个元素不同，则挑选之。

+ 时间复杂度$O(len(groups))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-15 10:32:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-15 10:36:32
 * @Description: AC,100.00%,97.33%
 */
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        for (int i = 0; i < groups.size(); i++) {
            if (!i || groups[i] != groups[i - 1]) {
                ans.push_back(words[i]);
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
Date: 2025-05-15 10:32:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-15 13:21:42
'''
from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        ans = []
        for i, g in enumerate(groups):
            if not i or g != groups[i - 1]:
                ans.append(words[i])
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-15 10:32:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-15 13:22:29
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < groups.length; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                ans.add(words[i]);
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
 * @Date: 2025-05-15 10:32:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-15 13:23:52
 */
package main

func getLongestSubsequence(words []string, groups []int) (ans []string) {
    for i, g := range groups {
		if i == 0 || g != groups[i - 1] {
			ans = append(ans, words[i])
		}
	}
	return 
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147990003)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/15/LeetCode%202900.%E6%9C%80%E9%95%BF%E7%9B%B8%E9%82%BB%E4%B8%8D%E7%9B%B8%E7%AD%89%E5%AD%90%E5%BA%8F%E5%88%97I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
