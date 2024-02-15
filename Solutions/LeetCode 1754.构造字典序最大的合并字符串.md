---
title: 1754.构造字典序最大的合并字符串
date: 2022-12-24 10:21:20
tags: [题解, LeetCode, 中等, 贪心, 双指针, 字符串]
---

# 【LetMeFly】1754.构造字典序最大的合并字符串

力扣题目链接：[https://leetcode.cn/problems/largest-merge-of-two-strings/](https://leetcode.cn/problems/largest-merge-of-two-strings/)

<p>给你两个字符串 <code>word1</code> 和 <code>word2</code> 。你需要按下述方式构造一个新字符串 <code>merge</code> ：如果 <code>word1</code> 或 <code>word2</code> 非空，选择 <strong>下面选项之一</strong> 继续操作：</p>

<ul>
	<li>如果 <code>word1</code> 非空，将 <code>word1</code> 中的第一个字符附加到 <code>merge</code> 的末尾，并将其从 <code>word1</code> 中移除。

	<ul>
		<li>例如，<code>word1 = "abc" </code>且 <code>merge = "dv"</code> ，在执行此选项操作之后，<code>word1 = "bc"</code> ，同时 <code>merge = "dva"</code> 。</li>
	</ul>
	</li>
	<li>如果 <code>word2</code> 非空，将 <code>word2</code> 中的第一个字符附加到 <code>merge</code> 的末尾，并将其从 <code>word2</code> 中移除。
	<ul>
		<li>例如，<code>word2 = "abc" </code>且 <code>merge = ""</code> ，在执行此选项操作之后，<code>word2 = "bc"</code> ，同时 <code>merge = "a"</code> 。</li>
	</ul>
	</li>
</ul>

<p>返回你可以构造的字典序 <strong>最大</strong> 的合并字符串<em> </em><code>merge</code><em> 。</em></p>

<p>长度相同的两个字符串 <code>a</code> 和 <code>b</code> 比较字典序大小，如果在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置，<code>a</code> 中字符在字母表中的出现顺序位于 <code>b</code> 中相应字符之后，就认为字符串 <code>a</code> 按字典序比字符串 <code>b</code> 更大。例如，<code>"abcd"</code> 按字典序比 <code>"abcc"</code> 更大，因为两个字符串出现不同的第一个位置是第四个字符，而 <code>d</code> 在字母表中的出现顺序位于 <code>c</code> 之后。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word1 = "cabaa", word2 = "bcaaa"
<strong>输出：</strong>"cbcabaaaaa"
<strong>解释：</strong>构造字典序最大的合并字符串，可行的一种方法如下所示：
- 从 word1 中取第一个字符：merge = "c"，word1 = "abaa"，word2 = "bcaaa"
- 从 word2 中取第一个字符：merge = "cb"，word1 = "abaa"，word2 = "caaa"
- 从 word2 中取第一个字符：merge = "cbc"，word1 = "abaa"，word2 = "aaa"
- 从 word1 中取第一个字符：merge = "cbca"，word1 = "baa"，word2 = "aaa"
- 从 word1 中取第一个字符：merge = "cbcab"，word1 = "aa"，word2 = "aaa"
- 将 word1 和 word2 中剩下的 5 个 a 附加到 merge 的末尾。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word1 = "abcabc", word2 = "abdcaba"
<strong>输出：</strong>"abdcabcabcaba"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= word1.length, word2.length <= 3000</code></li>
	<li><code>word1</code> 和 <code>word2</code> 仅由小写英文组成</li>
</ul>


    
## 方法一：贪心

我们不断比较两个字符串$word1$和$word2$哪个字典序大，每次把字典序大的字符串，取一个字母添加到$merge$中

例如```cad```和```bac```

```
word1:  cad
word2:  bac
merge:
```

$cad>bac$

```
word1:  ad
word2:  bac
merge:  c
```

$ad<bac$

```
word1:  ad
word2:  ac
merge:  cb
```

这时候$word1$和$word2$的首字母都是$a$，但是$word1$的第二个字母$d$小于$word2$的第二个字母$c$，因此选择$word2$

```
word1:  ad
word2:  c
merge:  cba
```

$ad<c$

```
word1:  ad
word2:
merge:  cbac
```

此时$word2$为空，将$word1$添加到$merge$中即可

```
word1:
word2:
merge: cbacad
```

+ 时间复杂度$O(len(word1)\times len(word2))$
+ 空间复杂度$O(len(word1) + len(word2))$

### AC代码

#### C++

```cpp
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        while (word1.size() && word2.size()) {
            if (word1 > word2) {
                ans += word1[0];
                word1 = word1.substr(1);
            }
            else {
                ans += word2[0];
                word2 = word2.substr(1);
            }
        }
        if (word1.size())
            ans += word1;
        if (word2.size())
            ans += word2;
        return ans;
    }
};
```

<!-- ## 方法二：双指针 -->

<!-- 方法二是基于方法一的小优化。 -->

<!-- 方法一中，我们不断比较$word1$和$word2$字典序的大小，并且从二者中字典序大的字符串中，取**1个字符**添加到$merge$中 -->

<!-- 不难发现，假如$word1$和$word2$分别是： -->

<!-- ``` -->
<!-- word1:  aaaaaaaaaaaaaab -->
<!-- word2:  aaaaaaaaaaaaaac -->
<!-- ``` -->

<!-- 那么我们将会往$merge$中添加很多次的```a``` -->

<!-- 其实我们可以使用双指针，指针1和指针2分别指向$word1$和$word2$的待处理的位置。 -->

<!-- 接着，在两个指针所指的字符相同时，不断后移指针，直到比较出二者的字典序大小（或者指到了字符串末尾） -->

<!-- 这样实际上是我们手动实现了字符串的字典序比较，但是这样的好处是，我们可以得到字典序不同的第一个下标（$word1$到$b$，$word2$到$c$才比较出字典序的不同，因此直接把$word2$中从$a$到$c$添加到$merge$中即可。 -->

<!-- 好像Error了 -->

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/24/LeetCode%201754.%E6%9E%84%E9%80%A0%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%A4%A7%E7%9A%84%E5%90%88%E5%B9%B6%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128426600](https://letmefly.blog.csdn.net/article/details/128426600)
