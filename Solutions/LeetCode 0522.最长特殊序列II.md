---
title: 522.最长特殊序列 II
date: 2024-06-17 22:57:04
tags: [题解, LeetCode, 中等, 数组, 哈希表, 双指针, 字符串, 排序, 子序列]
---

# 【LetMeFly】522.最长特殊序列 II：两句话讲明思路(子序列判断)

力扣题目链接：[https://leetcode.cn/problems/longest-uncommon-subsequence-ii/](https://leetcode.cn/problems/longest-uncommon-subsequence-ii/)

<p>给定字符串列表&nbsp;<code>strs</code> ，返回其中 <strong>最长的特殊序列</strong>&nbsp;的长度。如果最长特殊序列不存在，返回 <code>-1</code> 。</p>

<p><strong>特殊序列</strong> 定义如下：该序列为某字符串 <strong>独有的子序列（即不能是其他字符串的子序列）</strong>。</p>

<p>&nbsp;<code>s</code>&nbsp;的&nbsp;<strong>子序列</strong>可以通过删去字符串&nbsp;<code>s</code>&nbsp;中的某些字符实现。</p>

<ul>
	<li>例如，<code>"abc"</code>&nbsp;是 <code>"aebdc"</code>&nbsp;的子序列，因为您可以删除<code>"a<u>e</u>b<u>d</u>c"</code>中的下划线字符来得到 <code>"abc"</code>&nbsp;。<code>"aebdc"</code>的子序列还包括<code>"aebdc"</code>、 <code>"aeb"</code>&nbsp;和 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">""</span></font>&nbsp;(空字符串)。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> strs = ["aba","cdc","eae"]
<strong>输出:</strong> 3
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> strs = ["aaa","aaa","aa"]
<strong>输出:</strong> -1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= strs.length &lt;= 50</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 10</code></li>
	<li><code>strs[i]</code>&nbsp;只包含小写英文字母</li>
</ul>


    
## 解题方法：子序列判断

### 解题思路

1. 若字符串```a```的某个子序列是“独有的子序列”，则```a```更是“独有的子序列”，因此“最长独有的子序列”一定是字符串列表中的某完整字符串(如有)；
2. 一个字符串是“独有的子序列”，当前仅当它不是任何一个其他字符串的子序列。

### 解题方法

按字符串长度从长到短排序，依次判断每个字符串是否不是其他任何一个字符串的子序列。若该字符串不是任何一个其他字符串的子序列，则返回该字符串的长度。否则返回-1。

### 时空复杂度分析

+ 时间复杂度$O(n^2l\log n)$，其中$n=len(strs)$，$l$是字符串平均长度
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isSub(string& a, string& b) {
        for (int ia = 0, ib = 0; ia < a.size(); ia++, ib++) {
            while (ib < b.size() && b[ib] != a[ia]) {
                ib++;
            }
            if (ib == b.size()) {
                return false;
            }
        }
        return true;
    }

    bool ok(vector<string>& strs, int index) {
        for (int i = 0; i < strs.size(); i++) {
            if (i != index && isSub(strs[index], strs[i])) {
                return false;
            }
        }
        return true;
    }
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++) {
            if (ok(strs, i)) {
                return strs[i].size();
            }
        }
        return -1;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/17/LeetCode%200522.%E6%9C%80%E9%95%BF%E7%89%B9%E6%AE%8A%E5%BA%8F%E5%88%97II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139756781](https://letmefly.blog.csdn.net/article/details/139756781)
