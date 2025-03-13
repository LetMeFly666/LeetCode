---
title: 792.匹配子序列的单词数
date: 2022-11-17 09:37:28
tags: [题解, LeetCode, 中等, 字典树, 哈希表, 字符串, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】792.匹配子序列的单词数

力扣题目链接：[https://leetcode.cn/problems/number-of-matching-subsequences/](https://leetcode.cn/problems/number-of-matching-subsequences/)

<p>给定字符串 <code>s</code>&nbsp;和字符串数组&nbsp;<code>words</code>, 返回&nbsp;&nbsp;<em><code>words[i]</code>&nbsp;中是<code>s</code>的子序列的单词个数</em>&nbsp;。</p>

<p>字符串的 <strong>子序列</strong> 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。</p>

<ul>
	<li>例如， <code>“ace”</code> 是 <code>“abcde”</code> 的子序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> s = "abcde", words = ["a","bb","acd","ace"]
<strong>输出:</strong> 3
<strong>解释:</strong> 有三个是&nbsp;s 的子序列的单词: "a", "acd", "ace"。
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>输入: </strong>s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
<strong>输出:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>words[i]</code>和 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">s</span></font>&nbsp;都只由小写字母组成。</li>
</ul>
<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​​</span></span></span>

    
## 方法一：二分查找

方法一的思路是每个字符串单独处理。

首先需要预处理字符串```s```，记录下来```s```中每个字母的出现位置。 假如```s = "aba"```，那么```a```出现的下标为```[0, 2]```，```b```出现的下标为```[1]```

这样，在处理```words```中每个字符串的时候，只需要从前到后遍历字符串，在```s```中二分查找当前遍历到的字母即可。

+ 时间复杂度$O(len(s) + N\times len(s))$，其中$N$是$words$中所有单词的个数
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        vector<int> a[26];
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a'].push_back(i);
        int ans = 0;
        for (string& word : words) {
            bool ok = true;
            int loc = -1;
            for (char c : word) {
                vector<int>::iterator it = lower_bound(a[c - 'a'].begin(), a[c - 'a'].end(), loc + 1);  // 在s中所有出现过字符c的下标中，找到大于loc的第一个下标
                if (it == a[c - 'a'].end()) {
                    ok = false;
                    break;
                }
                loc = *it;
            }
            ans += ok;
        }
        return ans;
    }
};
```

## 方法二：多指针

方法二的思路是遍历字符串```s```，在遍历的过程中，不断将这个字符对应的字符串的指针后移。

例如样例一：```s = "abcde", words = ["a","bb","acd","ace"]```

首先建立$4$个指针（因为有$4$个字符串）

```
a
↑

bb
↑

acd
↑

ace
↑
```

然后建立一个大小为26的队列数组，队列中存放二十六个字母对应的指针

```
[0]: 0, 2, 3  // 是因为四个指针(0, 1, 2, 3)中，第0、2、3个指针所指的元素为a
[1]: 1  // 是因为四个指针中，第1号指针所指元素为b
[2]:
[3]:
[4]:
...
[25]:
```

接下来遍历字符串```s```

```s```的第一个字母为```a```，看```a```的队列，有三个指针```0, 2, 3```

将它们分别后移一位：

+ ```0```号指针对应字符串为```a```，指针后移一位达到了字符串的末尾，也就是说```0```号指针把字符串```a```“指完了”，因此```a```是```s```的子序列
+ ```2```号指针对应字符串为```acd```，指针后移一位，移动到```c```。因此队列```[2]: 2```
+ ```3```号指针对应字符串为```ace```，指针后移一位，移动到```c```。因此队列```[2]: 3```

```
[0]:
[1]: 1  // 是因为四个指针中，第1号指针所指元素为b
[2]: 2, 3
[3]:
[4]:
...
[25]:
```

```s```的第二个字母为```b```，看```b```的队列，有一个指针```1```

将它后移一位：

+ ```1```号指针对应字符串为```bb```，指针后移一位，移动到第二个```b```。因此队列```[1]: 1```

```
[0]:
[1]: 1
[2]: 2, 3
[3]:
[4]:
...
[25]:
```

```s```的第三个字母为```c```，看```c```的队列，有两个指针```2, 3```

将它们分别后移一位：

+ ```2```号指针对应字符串为```acd```，指针后移一位，移动到```d```。因此队列```[3]: 2```
+ ```3```号指针对应字符串为```ace```，指针后移一位，移动到```e```。因此队列```[4]: 3```

```
[0]:
[1]: 1
[2]:
[3]: 2
[4]: 3
...
[25]:
```

```s```的第四个字母为```d```，看```d```的队列，有一个指针```2```

将它后移一位：

+ ```2```号指针对应字符串为```acd```，指针后移一位达到了字符串的末尾，也就是说```2```号指针把字符串```acd```“指完了”，因此```acd```是```s```的子序列

```
[0]:
[1]: 1
[2]:
[3]:
[4]: 3
...
[25]:
```

```s```的第五个字母为```e```，看```e```的队列，有一个指针```3```

将它后移一位：

+ ```3```号指针对应字符串为```ace```，指针后移一位达到了字符串的末尾，也就是说```3```号指针把字符串```ace```“指完了”，因此```ace```是```s```的子序列

```
[0]:
[1]: 1
[2]:
[3]:
[4]:
...
[25]:
```

字符串```s```遍历结束，```words```中三个字符串是```s```的子序列

+ 时间复杂度$O(len(s) + N)$，其中$N$是$words$中所有单词的个数
+ 空间复杂度$O(N + C)$，其中$C$是字符种类数小写字母个数$26$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        queue<int> q[26];  // q[0]: 下一个是'a'的word在words中的index
        for (int index = 0; index < words.size(); index++)
            q[words[index][0] - 'a'].push(index);
        vector<int> loc(words.size(), 0);  // loc[0]: words[0]该匹配哪个单词了
        int ans = 0;
        for (char c : s) {
            for (int i = q[c - 'a'].size(); i > 0; i--) {
                int index = q[c - 'a'].front();
                q[c - 'a'].pop();
                loc[index]++;
                if (loc[index] == words[index].size()) {
                    ans++;
                    continue;
                }
                q[words[index][loc[index]] - 'a'].push(index);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/17/LeetCode%200792.%E5%8C%B9%E9%85%8D%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E5%8D%95%E8%AF%8D%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127908867](https://letmefly.blog.csdn.net/article/details/127908867)
