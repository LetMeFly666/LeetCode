---
title: 676.实现一个魔法字典
date: 2022-07-11 11:23:30
tags: [题解, LeetCode, 中等, 设计, 字典树, 哈希表, 字符串, set]
categories: [题解, LeetCode]
---

# 【LetMeFly】676.实现一个魔法字典：易实现但效率不是那么高的方法

力扣题目链接：[https://leetcode.cn/problems/implement-magic-dictionary/](https://leetcode.cn/problems/implement-magic-dictionary/)

<p>设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 <strong>互不相同</strong> 。 如果给出一个单词，请判定能否只将这个单词中<strong>一个</strong>字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。</p>

<p>实现 <code>MagicDictionary</code> 类：</p>

<ul>
    <li><code>MagicDictionary()</code> 初始化对象</li>
    <li><code>void buildDict(String[] dictionary)</code> 使用字符串数组 <code>dictionary</code> 设定该数据结构，<code>dictionary</code> 中的字符串互不相同</li>
    <li><code>bool search(String searchWord)</code> 给定一个字符串 <code>searchWord</code> ，判定能否只将字符串中<strong> 一个 </strong>字母换成另一个字母，使得所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p> </p>

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
<strong>输出</strong>
[null, null, false, true, false, false]

<strong>解释</strong>
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // 返回 False
magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
magicDictionary.search("hell"); // 返回 False
magicDictionary.search("leetcoded"); // 返回 False
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
    <li><code>1 <= dictionary.length <= 100</code></li>
    <li><code>1 <= dictionary[i].length <= 100</code></li>
    <li><code>dictionary[i]</code> 仅由小写英文字母组成</li>
    <li><code>dictionary</code> 中的所有字符串 <strong>互不相同</strong></li>
    <li><code>1 <= searchWord.length <= 100</code></li>
    <li><code>searchWord</code> 仅由小写英文字母组成</li>
    <li><code>buildDict</code> 仅在 <code>search</code> 之前调用一次</li>
    <li>最多调用 <code>100</code> 次 <code>search</code></li>
</ul>
</div>
</div>
</div>


    
## 方法一：set + 模拟

我们直接尝试修改待匹配字符串的每一个字符，如果修改后与字典中某个字符串相同，就返回yes

```cpp
bool search(string searchWord) {
    for (char& c : searchWord) {  // 准备修改原字符串中的每一个字符
        char originalC = c;  // 先记录下来原来的这个字符
        for (int i = 0; i < 26; i++) {  // 从a到z逐个尝试
            c = 'a' + i;  // 修改c
            if (c == originalC)  // 如果这个字符就是原本的字符，相当于没有修改
                continue;
            if (se.count(searchWord))  // 如果把c修改后在原始字典中存在了
                return true;  // 返回true
        }
        c = originalC;  // 把c修改为原来的字符，准备尝试修改字符串下一个字符
    }
    return false;  // 全部尝试过了还没匹配的字符，就返回false
}
```

+ 时间复杂度$O(nlC)$，其中$n$是原始数组中字符串的个数，$l$是原始数组中字符串的平均长度（$nl$其实就是原始字符串中所有字符的个数和），$C$是字符集的大小（也就是$26$个英文字母的$26$）
+ 空间复杂度$O(nl)$

### AC代码

#### C++

```cpp
class MagicDictionary {
private:
    unordered_set<string> se;
public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        for (string& s : dictionary) {
            se.insert(s);
        }
    }
    
    bool search(string searchWord) {
        for (char& c : searchWord) {
            char originalC = c;
            for (int i = 0; i < 26; i++) {
                c = 'a' + i;
                if (c == originalC)
                    continue;
                if (se.count(searchWord))
                    return true;
            }
            c = originalC;
        }
        return false;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/11/LeetCode%200676.%E5%AE%9E%E7%8E%B0%E4%B8%80%E4%B8%AA%E9%AD%94%E6%B3%95%E5%AD%97%E5%85%B8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125718347](https://letmefly.blog.csdn.net/article/details/125718347)
