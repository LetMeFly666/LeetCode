---
title: 761.特殊的二进制字符串：分治（左右括号对移动）
date: 2026-02-20 11:23:43
tags: [题解, LeetCode, 困难, 字符串, 分治, 排序, 递归, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】761.特殊的二进制字符串：分治（左右括号对移动）

力扣题目链接：[https://leetcode.cn/problems/special-binary-string/](https://leetcode.cn/problems/special-binary-string/)

<p><strong>特殊的二进制字符串</strong> 是具有以下两个性质的二进制序列：</p>

<ul>
	<li><code>0</code> 的数量与 <code>1</code> 的数量相等。</li>
	<li>二进制序列的每一个前缀码中 <code>1</code> 的数量要大于等于 <code>0</code> 的数量。</li>
</ul>

<p>给定一个特殊的二进制字符串&nbsp;<code>s</code>。</p>

<p>一次移动操作包括选择字符串 <code>s</code> 中的两个连续的、非空的、特殊子串，并交换它们。两个字符串是连续的，如果第一个字符串的最后一个字符与第二个字符串的第一个字符的索引相差正好为 1。</p>

<p>返回在字符串上应用任意次操作后可能得到的字典序最大的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> S = "11011000"
<strong>输出:</strong> "11100100"
<strong>解释:</strong>
将子串 "10" （在 s[1] 出现） 和 "1100" （在 s[3] 出现）进行交换。
这是在进行若干次操作后按字典序排列最大的结果。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "10"
<b>输出：</b>"10"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>s[i]</code>&nbsp;为&nbsp;<code>'0'</code> 或&nbsp;<code>'1'</code>。</li>
	<li><code>s</code>&nbsp;是一个特殊的二进制字符串。</li>
</ul>


    
## 解题方法：分治

例如示例一：`11011000`，可以看成`(()(()))`。

我们要做的就是保持括号处于匹配状态下，让对应的01字符串字典序尽可能大。

匹配字符串有两种组合方式：

1. 拼接，如`() + (()) = ()(())`；
2. 嵌套，在`()(())`外面套一个括号变成`(()(()))`。

这解法不就来了，我们可以反其道而行之，把``(()(()))`拆成`(  ()   (())    )`：

> 对于最外层括号里的`()`和`(())`，当然是`(())`放到`()`前面比较好（`1100`放到`10`前面字典序更大）
>
> 这不就是天然的递归么，`(()(()))`只有一个“拼接的括号”，外层总体顺序不变，内层`()(())`递归：
>
> 内层`()(())`有两个“拼接的括号”，两个拼接的括号分别递归，直到递归字符串为空递归停止，并将两个递归完成的“拼接括号”排序重新拼接到一起，变成`(())()`。

+ 时间复杂度$O(n^2\log n)$，递归像树一样，每次执行有一个排序和字符串拼接

    ```
    (()(()))
       |
     ()(())
     /    \
    ''    ()
    ```

+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-20 11:21:04
 */
/*
11011000
(()(()))
(  ()   (())    )
*/
class Solution {
private:
    vector<pair<int, int>> split(string& s) {
        vector<pair<int, int>> ans;
        int diff = 0, from = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                diff++;
            } else {
                diff--;
            }
            if (!diff) {
                ans.push_back({from, i});
                from = i + 1;
            }
        }
        return ans;
    }
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) {
            return s;
        }
        vector<pair<int, int>> pairs = split(s);
        vector<string> parts;
        parts.reserve(pairs.size());
        for (auto [l, r] : pairs) {
            parts.push_back('1' + makeLargestSpecial(s.substr(l + 1, r - l - 1)) + '0');
        }
        sort(parts.begin(), parts.end(), greater<>());
        string ans;
        for (string& part : parts) {
            ans += part;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158235045)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/20/LeetCode%200761.%E7%89%B9%E6%AE%8A%E7%9A%84%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
