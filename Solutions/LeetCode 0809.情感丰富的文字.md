---
title: 809.情感丰富的文字
date: 2022-11-25 11:15:22
tags: [题解, LeetCode, 中等, 数组, 双指针, 字符串, 阅读理解, 连续]
---

# 【LetMeFly】809.情感丰富的文字

力扣题目链接：[https://leetcode.cn/problems/expressive-words/](https://leetcode.cn/problems/expressive-words/)

<p>有时候人们会用重复写一些字母来表示额外的感受，比如 <code>"hello" -> "heeellooo"</code>, <code>"hi" -> "hiii"</code>。我们将相邻字母都相同的一串字符定义为相同字母组，例如："h", "eee", "ll", "ooo"。</p>

<p>对于一个给定的字符串 S ，如果另一个单词能够通过将一些字母组扩张从而使其和 S 相同，我们将这个单词定义为可扩张的（stretchy）。扩张操作定义如下：选择一个字母组（包含字母 <code>c</code> ），然后往其中添加相同的字母 <code>c</code> 使其长度达到 3 或以上。</p>

<p>例如，以 "hello" 为例，我们可以对字母组 "o" 扩张得到 "hellooo"，但是无法以同样的方法得到 "helloo" 因为字母组 "oo" 长度小于 3。此外，我们可以进行另一种扩张 "ll" -> "lllll" 以获得 "helllllooo"。如果 <code>S = "helllllooo"</code>，那么查询词 "hello" 是可扩张的，因为可以对它执行这两种扩张操作使得 <code>query = "hello" -> "hellooo" -> "helllllooo" = S</code>。</p>

<p>输入一组查询单词，输出其中可扩张的单词数量。</p>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong> 
S = "heeellooo"
words = ["hello", "hi", "helo"]
<strong>输出：</strong>1
<strong>解释</strong>：
我们能通过扩张 "hello" 的 "e" 和 "o" 来得到 "heeellooo"。
我们不能通过扩张 "helo" 来得到 "heeellooo" 因为 "ll" 的长度小于 3 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= len(S) <= 100</code>。</li>
	<li><code>0 <= len(words) <= 100</code>。</li>
	<li><code>0 <= len(words[i]) <= 100</code>。</li>
	<li><code>S</code> 和所有在 <code>words</code> 中的单词都只由小写字母组成。</li>
</ul>


    
## 方法一：模拟 + 划分

### 题目分析

这道题题目挺难读懂的，因此叫“[阅读理解](https://blog.letmefly.xyz/tags/%E9%98%85%E8%AF%BB%E7%90%86%E8%A7%A3/)题”

说白了就是：假如字符串中有连续的$n_1$个```'a'```，那么我们可以将这$n_1$个```'a'```增加至```$n_2$个（其中$n_1\geq1,n_2\geq3$

例如```baac```是“1个```b```，2个```a```，1个```c```”，我们可以把$2$个```'a'```拓展为$3$个，字符串就变成了```baaac```。这就是题目中所谓的“拓展”

题目给定了一个字符串$s$和一个字符串数组$words$，问你$words$中有多少个字符串可以“拓展”得到$s$

### 解题思路

我们可以预处理一遍字符串，将字符串变成“1个```b```，2个```a```，1个```c```”的样子。

```cpp
void string2vectorPair(string& s, vector<pii>& p) {
    char lastChar = s[0];  // 上一个字母
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] != lastChar) {  // 这个字母和上一个字母不相同 或 达到了字符串尾
            p.push_back({lastChar, cnt});  // 获得了连续的“xxx”
            if (i != n)
                lastChar = s[i];
            cnt = 0;
        }
        cnt++;
    }
}
```

接下来将字符串数组中的每个“拆分后数组”和原始字符串相比较，如果二者长度相同，并且里面每一个对于的“小连续”都能拓展成对应的“大连续”，那么答案就加一。

+ 时间复杂度$O(len(s) + C)$，其中$C$是字符串数组中的总字符个数
+ 空间复杂度$O(len(s) + max(len(word)))$，其中$word$是$words$中的每一个字符串

### AC代码

#### C++

```cpp
typedef pair<char, int> pii;
class Solution {
private:
    void string2vectorPair(string& s, vector<pii>& p) {
        char lastChar = s[0];
        int n = s.size();
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (i == n || s[i] != lastChar) {
                p.push_back({lastChar, cnt});
                if (i != n)
                    lastChar = s[i];
                cnt = 0;
            }
            cnt++;
        }
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pii> origin;
        string2vectorPair(s, origin);
        int ans = 0;
        for (string& s : words) {
            vector<pii> thisWord;
            string2vectorPair(s, thisWord);
            if (origin.size() != thisWord.size())
                continue;
            bool can = true;
            for (int i = 0; i < origin.size(); i++) {
                if (origin[i] == thisWord[i] || (origin[i].first == thisWord[i].first && origin[i].second > thisWord[i].second && origin[i].second >= 3))
                    continue;
                can = false;
                break;
            }
            ans += can;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/25/LeetCode%200809.%E6%83%85%E6%84%9F%E4%B8%B0%E5%AF%8C%E7%9A%84%E6%96%87%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128035958](https://letmefly.blog.csdn.net/article/details/128035958)
