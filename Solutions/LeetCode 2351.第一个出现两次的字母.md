---
title: 2351.第一个出现两次的字母
date: 2023-01-01 09:30:09
tags: [题解, LeetCode, 简单, 数组, 计数, 统计]
categories: [题解, LeetCode]
---

# 【LetMeFly】2351.第一个出现两次的字母

<p>给你一个由小写英文字母组成的字符串 <code>s</code> ，请你找出并返回第一个出现 <strong>两次</strong> 的字母。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果 <code>a</code> 的 <strong>第二次</strong> 出现比 <code>b</code> 的 <strong>第二次</strong> 出现在字符串中的位置更靠前，则认为字母 <code>a</code> 在字母 <code>b</code> 之前出现两次。</li>
	<li><code>s</code> 包含至少一个出现两次的字母。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abccbaacz"
<strong>输出：</strong>"c"
<strong>解释：</strong>
字母 'a' 在下标 0 、5 和 6 处出现。
字母 'b' 在下标 1 和 4 处出现。
字母 'c' 在下标 2 、3 和 7 处出现。
字母 'z' 在下标 8 处出现。
字母 'c' 是第一个出现两次的字母，因为在所有字母中，'c' 第二次出现的下标是最小的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcdd"
<strong>输出：</strong>"d"
<strong>解释：</strong>
只有字母 'd' 出现两次，所以返回 'd' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
	<li><code>s</code> 包含至少一个重复字母</li>
</ul>


    
## 方法一：计数

开辟一个大小为$26$的布尔类型的数组，初始值全部为$false$

从前到后遍历字符串，遇到哪个字符出现过，就直接返回这个字符

否则，就将这个字符标记为“出现过”

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(C)$，其中$C=26$

### AC代码

#### C++

```cpp
class Solution {
public:
    char repeatedCharacter(string s) {
        bool appeared[26] = {false};
        for (char c : s) {
            if (appeared[c - 'a'])
                return c;
            appeared[c - 'a'] = true;
        }
        return 0;  // FakeReturn
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/01/2351.%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%87%BA%E7%8E%B0%E4%B8%A4%E6%AC%A1%E7%9A%84%E5%AD%97%E6%AF%8D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128510526](https://letmefly.blog.csdn.net/article/details/128510526)
