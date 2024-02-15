---
title: 1832.判断句子是否为全字母句
date: 2022-12-13 16:31:55
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 统计]
---

# 【LetMeFly】1832.判断句子是否为全字母句

力扣题目链接：[https://leetcode.cn/problems/check-if-the-sentence-is-pangram/](https://leetcode.cn/problems/check-if-the-sentence-is-pangram/)

<p><strong>全字母句</strong> 指包含英语字母表中每个字母至少一次的句子。</p>

<p>给你一个仅由小写英文字母组成的字符串 <code>sentence</code> ，请你判断 <code>sentence</code> 是否为 <strong>全字母句</strong> 。</p>

<p>如果是，返回<em> </em><code>true</code> ；否则，返回<em> </em><code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "thequickbrownfoxjumpsoverthelazydog"
<strong>输出：</strong>true
<strong>解释：</strong><code>sentence</code> 包含英语字母表中每个字母至少一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "leetcode"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= sentence.length <= 1000</code></li>
	<li><code>sentence</code> 由小写英语字母组成</li>
</ul>


    
## 方法一：统计

我们只需要开辟大小为$26$的布尔类型的数组（初始值全为$false$），然后遍历原始字符串

在遍历过程中，直接将字符串对应的布尔值修改为$true$

最后，再遍历一遍布尔类型的数组，如果发现哪个布尔值仍未$false$，就说明这个布尔值对应的字母没有在字符串中出现过，也就是说这个字符串不是“全字母句”，直接返回$false$

否则，遍历结束未返回$false$，则返回$true$

+ 时间复杂度$O(len(sentence))$
+ 空间复杂度$O(C)$，其中$C=26$，这里写成$O(1)$也可

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkIfPangram(string& sentence) {
        bool visited[26] = {false};
        for (char c : sentence)
            visited[c - 'a'] = true;
        for (int i = 0; i < 26; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/13/LeetCode%201832.%E5%88%A4%E6%96%AD%E5%8F%A5%E5%AD%90%E6%98%AF%E5%90%A6%E4%B8%BA%E5%85%A8%E5%AD%97%E6%AF%8D%E5%8F%A5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128304160](https://letmefly.blog.csdn.net/article/details/128304160)
