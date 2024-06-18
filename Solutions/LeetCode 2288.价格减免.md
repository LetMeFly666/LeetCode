---
title: 2288.价格减免
date: 2024-06-18 19:22:49
tags: [题解, LeetCode, 中等, 字符串, 模拟, 字符串解析]
---

# 【LetMeFly】2288.价格减免：模拟

力扣题目链接：[https://leetcode.cn/problems/apply-discount-to-prices/](https://leetcode.cn/problems/apply-discount-to-prices/)

<p><strong>句子</strong> 是由若干个单词组成的字符串，单词之间用单个空格分隔，其中每个单词可以包含数字、小写字母、和美元符号 <code>'$'</code> 。如果单词的形式为美元符号后跟着一个非负实数，那么这个单词就表示一个 <strong>价格</strong> 。</p>

<ul>
	<li>例如 <code>"$100"</code>、<code>"$23"</code> 和 <code>"$6"</code> 表示价格，而 <code>"100"</code>、<code>"$"</code> 和 <code>"$1e5</code> 不是。</li>
</ul>

<p>给你一个字符串 <code>sentence</code> 表示一个句子和一个整数 <code>discount</code> 。对于每个表示价格的单词，都在价格的基础上减免 <code>discount%</code> ，并 <strong>更新</strong> 该单词到句子中。所有更新后的价格应该表示为一个 <strong>恰好保留小数点后两位</strong> 的数字。</p>

<p>返回表示修改后句子的字符串。</p>

<p>注意：所有价格 <strong>最多</strong> 为&nbsp; <code>10</code> 位数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
<strong>输出：</strong>"there are $0.50 $1.00 and 5$ candies in the shop"
<strong>解释：</strong>
表示价格的单词是 "$1" 和 "$2" 。 
- "$1" 减免 50% 为 "$0.50" ，所以 "$1" 替换为 "$0.50" 。
- "$2" 减免 50% 为 "$1" ，所以 "$1" 替换为 "$1.00" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
<strong>输出：</strong>"1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
<strong>解释：</strong>
任何价格减免 100% 都会得到 0 。
表示价格的单词分别是 "$3"、"$5"、"$6" 和 "$9"。
每个单词都替换为 "$0.00"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 10<sup>5</sup></code></li>
	<li><code>sentence</code> 由小写英文字母、数字、<code>' '</code> 和&nbsp;<code>'$'</code> 组成</li>
	<li><code>sentence</code> 不含前导和尾随空格</li>
	<li><code>sentence</code> 的所有单词都用单个空格分隔</li>
	<li>所有价格都是 <strong>正</strong> 整数且不含前导零</li>
	<li>所有价格 <strong>最多</strong> 为&nbsp; <code>10</code> 位数字</li>
	<li><code>0 &lt;= discount &lt;= 100</code></li>
</ul>


    
## 解题方法：模拟

那就说说尽量不使用库函数的方法。

**问题一**：如何划分单词？

> 两个指针，一个指向单词开头，另一个从单词开头开始往后遍历寻找单词尾，遇到空格或超出字符串范围停止。

**问题二**：如何判断一个单词是否为价格？

> 一个单词是“价格”，当前仅当：
>
> 1. 单词首字母为```$```；
> 2. 单词长度至少为```2```；
> 3. 单词除首字母外都是```数字```。

**问题三**：如何获得打折后的字符串？

> 首先获得原始价格：默认价格val为0开始遍历数字，每次$val = val \times 10 + 当前字符对应数字$。
>
> 若想避免浮点数误差，可以将$val$乘以$100-discount$，百位及其以上为整数部分，个位十位为小数部分。

+ 时间复杂度$O(len(sentence))$
+ 空间复杂度$O(len(sentence))$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isPrice(string& s, int l, int r) {  // [l, r)
        if (s[l] != '$') {
            return false;
        }
        if (l + 1 == r) {
            return false;
        }
        while (++l < r) {
            if (!isdigit(s[l])) {
                return false;
            }
        }
        return true;
    }

    string newPrice(string& s, int l, int r, int discount) {
        long long val = 0;
        for (; l < r; l++) {
            val = val * 10 + s[l] -'0';
        }
        val *= 100 - discount;
        return '$' + to_string(val / 100) + '.' + to_string(val / 10 % 10) + to_string(val % 10);
    }
public:
    string discountPrices(string sentence, int discount) {
        string ans;
        for (int l = 0, r = 0; l < sentence.size();) {
            while (r < sentence.size() && sentence[r] != ' ') {
                r++;
            }
            if (isPrice(sentence, l, r)) {
                ans += newPrice(sentence, l + 1, r, discount);
            }
            else {
                while (l < r) {
                    ans += sentence[l];
                    l++;
                }
            }
            if (r != sentence.size()) {
                ans += ' ';
            }
            l = r + 1;
            r++;
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def isPrice(self, s: str) -> bool:
        if s[0] != '$':
            return False
        if len(s) == 1:
            return False
        for c in s[1:]:
            if not c.isdigit():
                return False
        return True
    
    def newPrice(self, s: str, discount: int) -> str:
        val = int(s) * (100 - discount)
        return f'${val // 100}.{val % 100:02d}'
    
    def discountPrices(self, sentence: str, discount: int) -> str:
        splited = sentence.split(' ')
        for i in range(len(splited)):
            if self.isPrice(splited[i]):
                splited[i] = self.newPrice(splited[i][1:], discount)
        return ' '.join(splited)
```

### AC代码官解更简版

#### C++

```cpp
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream sin(sentence), sout;
        sout << fixed << setprecision(2);

        vector<string> words;
        string word;
        while (sin >> word) {
            if (word[0] == '$' && word.size() > 1 && all_of(word.begin() + 1, word.end(), ::isdigit)) {
                double price = stoll(word.substr(1, word.size() - 1)) * (1.0 - discount / 100.0);
                sout << '$' << price;
            }
            else {
                sout << word;
            }
            sout << " ";
        }
        string ans = sout.str();
        ans.pop_back();
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        words = sentence.split()
        for i, word in enumerate(words):
            if word[0] == "$" and word[1:].isnumeric():
                price = int(word[1:]) * (1 - discount / 100)
                words[i] = f"${price:.2f}"
        return " ".join(words)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/18/LeetCode%202288.%E4%BB%B7%E6%A0%BC%E5%87%8F%E5%85%8D/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139781687](https://letmefly.blog.csdn.net/article/details/139781687)
