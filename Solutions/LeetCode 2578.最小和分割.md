---
title: 2578.最小和分割
date: 2023-10-09 09:13:42
tags: [题解, LeetCode, 简单, 贪心, 数学, 排序]
---

# 【LetMeFly】2578.最小和分割：贪心（数学）

力扣题目链接：[https://leetcode.cn/problems/split-with-minimum-sum/](https://leetcode.cn/problems/split-with-minimum-sum/)

<p>给你一个正整数&nbsp;<code>num</code>&nbsp;，请你将它分割成两个非负整数&nbsp;<code>num1</code> 和&nbsp;<code>num2</code>&nbsp;，满足：</p>

<ul>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;直接连起来，得到&nbsp;<code>num</code>&nbsp;各数位的一个排列。

	<ul>
		<li>换句话说，<code>num1</code> 和&nbsp;<code>num2</code>&nbsp;中所有数字出现的次数之和等于&nbsp;<code>num</code>&nbsp;中所有数字出现的次数。</li>
	</ul>
	</li>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;可以包含前导 0 。</li>
</ul>

<p>请你返回&nbsp;<code>num1</code> 和 <code>num2</code>&nbsp;可以得到的和的 <strong>最小</strong> 值。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>num</code>&nbsp;保证没有前导 0 。</li>
	<li><code>num1</code> 和&nbsp;<code>num2</code>&nbsp;中数位顺序可以与&nbsp;<code>num</code>&nbsp;中数位顺序不同。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = 4325
<b>输出：</b>59
<b>解释：</b>我们可以将 4325 分割成 <code>num1 </code>= 24 和 num2<code> = </code>35 ，和为 59 ，59 是最小和。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = 687
<b>输出：</b>75
<b>解释：</b>我们可以将 687 分割成 <code>num1</code> = 68 和 <code>num2 </code>= 7 ，和为最优值 75 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 &lt;= num &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：贪心（数学）

先说结论：将给定数字转为字符串后将其中字符从小到大排序，然后依次分配给两个新数字即可。

不严谨的原理描述：

+ 越高位数字尽量越小，因此要从小到大排序
+ 最终返回的是两数之和，所以首先位数越小越好，因此尽可能两个数字长度相等
+ 若两个数长度不相等，更长的那个数字的最高位要尽可能小（例如将```23456```分成```246```和```35```，唯一的百位是最小的```2```）

结论中描述的分法恰好满足。

+ 时间复杂度$O(k\log k)$，其中$k = \log num$
+ 空间复杂度$O(\log k)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string n1, n2;
        for (int i = 0; i < s.size(); i++) {
            (i % 2 ? n2 : n1) += s[i];
        }
        // cout << "n1: " << n1 << ", n2: " << n2 << endl;  //**********
        return atoi(n1.c_str()) + atoi(n2.c_str());
    }
};
```

#### Python

```python
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        n = ['', '']
        for i in range(len(s)):
            n[i % 2] += s[i]
        return int(n[0]) + int(n[1])
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/09/LeetCode%202578.%E6%9C%80%E5%B0%8F%E5%92%8C%E5%88%86%E5%89%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133694187](https://letmefly.blog.csdn.net/article/details/133694187)
