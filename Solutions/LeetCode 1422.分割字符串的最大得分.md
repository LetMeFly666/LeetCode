---
title: 1422.分割字符串的最大得分
date: 2022-08-14 10:21:06
tags: [题解, LeetCode, 简单, 字符串, 前缀和]
---

# 【LetMeFly】1422.分割字符串的最大得分

力扣题目链接：[https://leetcode.cn/problems/maximum-score-after-splitting-a-string/](https://leetcode.cn/problems/maximum-score-after-splitting-a-string/)

<p>给你一个由若干 0 和 1 组成的字符串 <code>s</code> ，请你计算并返回将该字符串分割成两个 <strong>非空</strong> 子字符串（即&nbsp;<strong>左</strong> 子字符串和 <strong>右</strong> 子字符串）所能获得的最大得分。</p>

<p>「分割字符串的得分」为 <strong>左</strong> 子字符串中 <strong>0</strong> 的数量加上 <strong>右</strong> 子字符串中 <strong>1</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;011101&quot;
<strong>输出：</strong>5 
<strong>解释：</strong>
将字符串 s 划分为两个非空子字符串的可行方案有：
左子字符串 = &quot;0&quot; 且 右子字符串 = &quot;11101&quot;，得分 = 1 + 4 = 5 
左子字符串 = &quot;01&quot; 且 右子字符串 = &quot;1101&quot;，得分 = 1 + 3 = 4 
左子字符串 = &quot;011&quot; 且 右子字符串 = &quot;101&quot;，得分 = 1 + 2 = 3 
左子字符串 = &quot;0111&quot; 且 右子字符串 = &quot;01&quot;，得分 = 1 + 1 = 2 
左子字符串 = &quot;01110&quot; 且 右子字符串 = &quot;1&quot;，得分 = 2 + 1 = 3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;00111&quot;
<strong>输出：</strong>5
<strong>解释：</strong>当 左子字符串 = &quot;00&quot; 且 右子字符串 = &quot;111&quot; 时，我们得到最大得分 = 2 + 3 = 5
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;1111&quot;
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 500</code></li>
	<li>字符串 <code>s</code> 仅由字符 <code>&#39;0&#39;</code> 和 <code>&#39;1&#39;</code> 组成。</li>
</ul>



## 方法0：暴力

直接暴力枚举每一个可以分割的位置，在每次枚举时，暴力统计一下分割位置前面和后面分别有多少个'0' / '1'

+ 时间复杂度$O(n^2)$，其中$n$是字符串长度
+ 空间复杂度$O(1)$
    
## 方法一：前缀和

```frontZero[i]```表示下标```0```~```i```的```'0'```的个数

```backOne[i]```表示下标```i```~```n - 1```的```'1'```的个数

我们预处理遍历一遍原始字符串，统计出上述两个数组。

之和，只需要枚举分割的位置，并借助上述两个数组使用$O(1)$的时间计算出这种分割方案的得分。

+ 时间复杂度$O(n)$，其中$n$是字符串的长度
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxScore(string& s) {
        int n = s.size();
		// 预处理
        vector<int> frontZero(n);
        vector<int> backOne(n);
        frontZero[0] = s[0] == '0';
        for (int i = 1; i < n; i++) {
            frontZero[i] = frontZero[i - 1] + (s[i] == '0');
        }
        backOne[n - 1] = s[n - 1] == '1';
        for (int i = n - 2; i >= 0; i--) {
            backOne[i] = backOne[i + 1] + (s[i] == '1');
        }
		// 模拟分割位置
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, frontZero[i - 1] + backOne[i]);
        }
        return ans;
    }
};
```

## 方法二：直接计算

方法一中，我们通过预处理，先用两个数数组把第$i$个位置前后的零/一存了下来，因此消耗了$O(n)$的空间复杂度。

那么，我们有没有什么办法使用$O(1)$的额外空间来存储上述信息呢？

**注意**，方法一中模拟分割位置时是从前往后依次模拟的。也就是说，我们可以在上次模拟结果的基础上，快速求出这次的“零、一信息”

具体方法为：

首先遍历一遍原始字符串，并求出从第一个元素分割的情况下的得分。

之后从第二个元素开始往后模拟，如果这个元素是```'0'```，那么把这个元素划分到“左字符串”的话，将会比上一种方案多一个“前字符串的0”，因此会在上一个方案的基础上多得```一分```；同理，如果这个元素是“1”，那么“后字符串”将少一个“1”，将会少得```一分```

每次模拟分割位置并在上次分割的基础上计算出新的得分后，更新最大得分，就能得到答案。

+ 时间复杂度$O(n)$，其中$n$是字符串的长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxScore(string s) {
        int score = s[0] == '0';
        int n = s.size();
        for (int i = 1; i < n; i++) {
            score += s[i] == '1';
        }
        int ans = score;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '0')
                score++;
            else
                score--;
            ans = max(ans, score);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/14/LeetCode%201422.%E5%88%86%E5%89%B2%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BE%97%E5%88%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126329351](https://letmefly.blog.csdn.net/article/details/126329351)
