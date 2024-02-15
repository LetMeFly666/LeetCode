---
title: 2788.按分隔符拆分字符串
date: 2024-01-20 23:18:08
tags: [题解, LeetCode, 简单, 数组, 字符串, 字符串解析, 模拟, 遍历]
---

# 【LetMeFly】2788.按分隔符拆分字符串：模拟（字符串处理）

力扣题目链接：[https://leetcode.cn/problems/split-strings-by-separator/](https://leetcode.cn/problems/split-strings-by-separator/)

<p>给你一个字符串数组 <code>words</code> 和一个字符 <code>separator</code> ，请你按 <code>separator</code> 拆分 <code>words</code> 中的每个字符串。</p>

<p>返回一个由拆分后的新字符串组成的字符串数组，<strong>不包括空字符串</strong> 。</p>

<p><strong>注意</strong></p>

<ul>
	<li><code>separator</code> 用于决定拆分发生的位置，但它不包含在结果字符串中。</li>
	<li>拆分可能形成两个以上的字符串。</li>
	<li>结果字符串必须保持初始相同的先后顺序。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["one.two.three","four.five","six"], separator = "."
<strong>输出：</strong>["one","two","three","four","five","six"]
<strong>解释：</strong>在本示例中，我们进行下述拆分：

"one.two.three" 拆分为 "one", "two", "three"
"four.five" 拆分为 "four", "five"
"six" 拆分为 "six" 

因此，结果数组为 ["one","two","three","four","five","six"] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["$easy$","$problem$"], separator = "$"
<strong>输出：</strong>["easy","problem"]
<strong>解释：</strong>在本示例中，我们进行下述拆分：

"$easy$" 拆分为 "easy"（不包括空字符串）
"$problem$" 拆分为 "problem"（不包括空字符串）

因此，结果数组为 ["easy","problem"] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["|||"], separator = "|"
<strong>输出：</strong>[]
<strong>解释：</strong>在本示例中，"|||" 的拆分结果将只包含一些空字符串，所以我们返回一个空数组 [] 。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>words[i]</code> 中的字符要么是小写英文字母，要么就是字符串 <code>".,|$#@"</code> 中的字符（不包括引号）</li>
	<li><code>separator</code> 是字符串 <code>".,|$#@"</code> 中的某个字符（不包括引号）</li>
</ul>


    
## 方法一：模拟

新建一个空的字符串数组作为答案，遍历字符串数组的所有字符串，使用一个变量```last```记录上一个```separator```的位置（初始值为```-1```）。

接着遍历这个字符串的每一个字符，如果遍历到了字符串尾或当前字符为```separator```，就看当前下标和```last```之间是否有字符存在。若有，则添加到答案数组中。

最终返回答案数组即为答案。

+ 时间复杂度$O(sum_character(words))$，时间复杂度为字符串数组中字符串的个数
+ 空间复杂度$O(1)$，力扣的算法返回值不计入算法的空间复杂的

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (string& word : words) {
            int last = -1;
            for (int i = 0; i <= word.size(); i++) {
                if (i == word.size() || word[i] == separator) {
                    if (i - last > 1) {
                        ans.push_back(word.substr(last + 1, i - last - 1));
                    }
                    last = i;
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for word in words:
            splited = word.split(separator)
            for this in splited:  # 过滤空串
                if this:
                    ans.append(this)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/20/LeetCode%202788.%E6%8C%89%E5%88%86%E9%9A%94%E7%AC%A6%E6%8B%86%E5%88%86%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135724019](https://letmefly.blog.csdn.net/article/details/135724019)
