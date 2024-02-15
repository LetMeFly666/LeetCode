---
title: 140.单词拆分 II
date: 2022-07-27 14:56:00
tags: [题解, LeetCode, 困难, 字典树, 记忆化搜索, 记忆化, 哈希表, 字符串, 动态规划, 回溯, 状态压缩]
---

# 【LetMeFly】140.单词拆分 II

力扣题目链接：[https://leetcode.cn/problems/word-break-ii/](https://leetcode.cn/problems/word-break-ii/)

<p>给定一个字符串 <code>s</code> 和一个字符串字典<meta charset="UTF-8" />&nbsp;<code>wordDict</code>&nbsp;，在字符串<meta charset="UTF-8" />&nbsp;<code>s</code>&nbsp;中增加空格来构建一个句子，使得句子中所有的单词都在词典中。<strong>以任意顺序</strong> 返回所有这些可能的句子。</p>

<p><strong>注意：</strong>词典中的同一个单词可能在分段中被重复使用多次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong>s = "<code>catsanddog</code>", wordDict = <code>["cat","cats","and","sand","dog"]</code>
<strong>输出:</strong><code>["cats and dog","cat sand dog"]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong>s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
<strong>输出:</strong>["pine apple pen apple","pineapple pen apple","pine applepen apple"]
<strong>解释:</strong> 注意你可以重复使用字典中的单词。
</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre>
<strong>输入:</strong>s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
<strong>输出:</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 10</code></li>
	<li><code>s</code>&nbsp;和&nbsp;<code>wordDict[i]</code>&nbsp;仅有小写英文字母组成</li>
	<li><code>wordDict</code>&nbsp;中所有字符串都 <strong>不同</strong></li>
</ul>


    
## 方法一：状态压缩（二进制暴力枚举）

待分割的字符串的最大长度为$20$，而$20\times 2^{20}=20,971,520$，加上很多情况下很快就会break（除非专门造的卡数据的数据），因此能够在规定时间内完成运行。

如果说到状态压缩，这道题与[131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning/)解法十分类似。

与(https://blog.letmefly.xyz/2022/07/23/LeetCode 0131.分割回文串/)[https://blog.letmefly.xyz/2022/07/23/LeetCode%200131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2/]解法相同，首先我们用$i$枚举在哪个下标切割。

长度为$n$的字符串一共有$n-1$个可以切割的地方。

之后用$j$从$0$到$n-1$，看这$n-1$个可切割位置到底哪个真正地进行了切割。然后把切割出来的子串与字典比对，看是否存在于字典中。若所有子串都存在于字典中，则用空格连接这种切割方式下的所有子串，并计入答案中。



+ 时间复杂度$O(n\times 2^n)$，其中$n$是字符串的长度。二进制状态压缩枚举的时间复杂度为$2^n$，对于某次枚举(切割方式)，需要判断这种切割方式是否每个子串都在字典中，时间复杂度$O(n)$（哈希表时间复杂度可以视为O(1)）
+ 空间复杂度$O(m + n)$，其中$m$是字典中的所有字符个数。**二进制状态压缩相比于基于递归的状态压缩**，优点是不需要递归（因此也就不需要消耗递归的空间），而答案不计入算法的复杂度，因此存放字典外的空间复杂度仅为单次枚举时候所需要的额外空间$O(n)$

### AC代码

#### C++

```cpp
#define judge(thisWord) \
    if (!st.count(thisWord))\
        goto loop;\
    thisBreak.push_back(thisWord);

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_set<string> st;
        for (string& s : wordDict) {
            st.insert(s);
        }
        int n = s.size() - 1;
        for (int i = 0; i < (1 << n); i++) {
            vector<string> thisBreak;
            string toInsert;
            string thisWord;

            int last = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    thisWord = s.substr(last, j - last + 1);
                    judge(thisWord);
                    last = j + 1;
                }
            }
            thisWord = s.substr(last, s.size() - last);
            judge(thisWord);

            for (int i = 0; i < thisBreak.size(); i++) {
                if (i)
                    toInsert += ' ';
                toInsert += thisBreak[i];
            }
            ans.push_back(toInsert);
            loop:;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/27/LeetCode%200140.%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126016024](https://letmefly.blog.csdn.net/article/details/126016024)
