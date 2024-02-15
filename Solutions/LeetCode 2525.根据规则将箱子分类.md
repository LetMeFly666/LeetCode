---
title: 2525.根据规则将箱子分类
date: 2023-10-20 12:16:14
tags: [题解, LeetCode, 简单, 数学]
---

# 【LetMeFly】2525.根据规则将箱子分类：优雅解法？

力扣题目链接：[https://leetcode.cn/problems/categorize-box-according-to-criteria/](https://leetcode.cn/problems/categorize-box-according-to-criteria/)

<p>给你四个整数&nbsp;<code>length</code>&nbsp;，<code>width</code>&nbsp;，<code>height</code>&nbsp;和&nbsp;<code>mass</code>&nbsp;，分别表示一个箱子的三个维度和质量，请你返回一个表示箱子 <strong>类别</strong> 的字符串。</p>

<ul>
	<li>如果满足以下条件，那么箱子是&nbsp;<code>"Bulky"</code>&nbsp;的：

	<ul>
		<li>箱子 <strong>至少有一个</strong> 维度大于等于 <code>10<sup>4</sup></code>&nbsp;。</li>
		<li>或者箱子的 <strong>体积</strong> 大于等于&nbsp;<code>10<sup>9</sup></code>&nbsp;。</li>
	</ul>
	</li>
	<li>如果箱子的质量大于等于&nbsp;<code>100</code>&nbsp;，那么箱子是&nbsp;<code>"Heavy"</code>&nbsp;的。</li>
	<li>如果箱子同时是&nbsp;<code>"Bulky"</code> 和&nbsp;<code>"Heavy"</code>&nbsp;，那么返回类别为&nbsp;<code>"Both"</code>&nbsp;。</li>
	<li>如果箱子既不是&nbsp;<code>"Bulky"</code>&nbsp;，也不是&nbsp;<code>"Heavy"</code>&nbsp;，那么返回类别为&nbsp;<code>"Neither"</code>&nbsp;。</li>
	<li>如果箱子是&nbsp;<code>"Bulky"</code>&nbsp;但不是&nbsp;<code>"Heavy"</code>&nbsp;，那么返回类别为&nbsp;<code>"Bulky"</code>&nbsp;。</li>
	<li>如果箱子是&nbsp;<code>"Heavy"</code>&nbsp;但不是&nbsp;<code>"Bulky"</code>&nbsp;，那么返回类别为&nbsp;<code>"Heavy"</code>&nbsp;。</li>
</ul>

<p><strong>注意</strong>，箱子的体积等于箱子的长度、宽度和高度的乘积。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>length = 1000, width = 35, height = 700, mass = 300
<b>输出：</b>"Heavy"
<b>解释：</b>
箱子没有任何维度大于等于 10<sup>4 </sup>。
体积为 24500000 &lt;= 10<sup>9 </sup>。所以不能归类为 "Bulky" 。
但是质量 &gt;= 100 ，所以箱子是 "Heavy" 的。
由于箱子不是 "Bulky" 但是是 "Heavy" ，所以我们返回 "Heavy" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>length = 200, width = 50, height = 800, mass = 50
<b>输出：</b>"Neither"
<b>解释：</b>
箱子没有任何维度大于等于 10<sup>4</sup>&nbsp;。
体积为 8 * 10<sup>6</sup> &lt;= 10<sup>9</sup>&nbsp;。所以不能归类为 "Bulky" 。
质量小于 100 ，所以不能归类为 "Heavy" 。
由于不属于上述两者任何一类，所以我们返回 "Neither" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= length, width, height &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= mass &lt;= 10<sup>3</sup></code></li>
</ul>


    
## 方法一：优雅解法？

判断箱子是否符合```bulky```或```heavy```很简单，对于一些编程语言注意不要“32位整数溢出”就可以了。

得到了值为```0```或```1```的两个变量```bulky```和```heavy```，怎么“优雅”地转为字符串返回呢？

可以预先定义一个字符串数组```dic = ['Neither', 'Heavy', 'Bulky', 'Both']```，这样直接返回```dic[bulky * 2 + heavy]```就可以了。本质上是将这两个变量看成了```dic```下标二进制下的低两位，这样就避免了四个```if-else```的出现。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
const string dict[4] = {"Neither", "Heavy", "Bulky", "Both"};

typedef long long ll;
class Solution {
public:
    string categorizeBox(ll length, ll width, ll height, ll mass) {
        bool bulky = length >= 10000 || width >= 10000 || height >= 10000 || length * width * height >= 1000000000;
        bool heavy = mass >= 100;
        return dict[bulky * 2 + heavy];
    }
};
```

#### Python

```python
dic = ['Neither', 'Heavy', 'Bulky', 'Both']
class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        bulky = length >= 10000 or width >= 10000 or height >= 10000 or length * width * height >= 1000000000
        heavy = mass >= 100
        return dic[bulky * 2 + heavy]

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/20/LeetCode%202525.%E6%A0%B9%E6%8D%AE%E8%A7%84%E5%88%99%E5%B0%86%E7%AE%B1%E5%AD%90%E5%88%86%E7%B1%BB/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133943695](https://letmefly.blog.csdn.net/article/details/133943695)
