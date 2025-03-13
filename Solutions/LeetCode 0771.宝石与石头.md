---
title: 771.宝石与石头
date: 2023-07-24 08:48:00
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 统计]
categories: [题解, LeetCode]
---

# 【LetMeFly】771.宝石与石头

力扣题目链接：[https://leetcode.cn/problems/jewels-and-stones/](https://leetcode.cn/problems/jewels-and-stones/)

<p>&nbsp;给你一个字符串 <code>jewels</code>&nbsp;代表石头中宝石的类型，另有一个字符串 <code>stones</code> 代表你拥有的石头。&nbsp;<code>stones</code>&nbsp;中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。</p>

<p>字母区分大小写，因此 <code>"a"</code> 和 <code>"A"</code> 是不同类型的石头。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>jewels = "aA", stones = "aAAbbbb"
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>jewels = "z", stones = "ZZ"
<strong>输出：</strong>0<strong>
</strong></pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;jewels.length, stones.length &lt;= 50</code></li>
	<li><code>jewels</code> 和 <code>stones</code> 仅由英文字母组成</li>
	<li><code>jewels</code> 中的所有字符都是 <strong>唯一的</strong></li>
</ul>


    
## 方法一：统计

对于无法直接```判断一个字符是否在字符串中出现过```的编程语言，可以写一个返回值为布尔类型的函数来实现上述功能。

```cpp
bool isIn(char c, string& s) {
    for (char _ : s) {
        if (c == _) {
            return true;
        }
    }
    return false;
}
```

接着，我们只需要遍历stones字符串，并统计在jewels中出现过的字符个数就行了。

+ 时间复杂度$O(len(jewels)\times len(stones))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isIn(char c, string& s) {
        for (char _ : s) {
            if (c == _) {
                return true;
            }
        }
        return false;
    }
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for (char stone : stones) {
            ans += isIn(stone, jewels);
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(stone in jewels for stone in stones)
```

<center><font size="6px" face="楷体">それわ, steins;gate!</font></center>

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/24/LeetCode%200771.%E5%AE%9D%E7%9F%B3%E4%B8%8E%E7%9F%B3%E5%A4%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131888350](https://letmefly.blog.csdn.net/article/details/131888350)
