---
title: 451.根据字符出现频率排序
date: 2022-10-21 20:41:20
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 桶排序, 计数, 排序, 堆（优先队列）, 排序]
---

# 【LetMeFly】451.根据字符出现频率排序

力扣题目链接：[https://leetcode.cn/problems/sort-characters-by-frequency/](https://leetcode.cn/problems/sort-characters-by-frequency/)

<p>给定一个字符串 <code>s</code> ，根据字符出现的 <strong>频率</strong> 对其进行 <strong>降序排序</strong> 。一个字符出现的 <strong>频率</strong> 是它出现在字符串中的次数。</p>

<p>返回 <em>已排序的字符串&nbsp;</em>。如果有多个答案，返回其中任何一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>s = "tree"
<strong>输出: </strong>"eert"
<strong>解释: </strong>'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong>s = "cccaaa"
<strong>输出: </strong>"cccaaa"
<strong>解释: </strong>'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入: </strong>s = "Aabb"
<strong>输出: </strong>"bbAa"
<strong>解释: </strong>此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;由大小写英文字母和数字组成</li>
</ul>


    
## 方法一：排序

单字节字符一共有$2^8=256$种，因此我们开辟一个长度为$256$的空间，用于记录每个元素的出现次数

```cpp
int cnt[256] = {0};
```

之后遍历一遍字符串，统计每个字符出现的次数

```cpp
for (char c : s)
    cnt[c]++;
```

最后，调用系统内置函数，按照“出现次数多的最优先”，“ASCII大的次优先”的顺序进行排序

```cpp
sort(s.begin(), s.end(), [&](const char& a, const char& b) {
    return cnt[a] == cnt[b] ? a > b : cnt[a] > cnt[b];
});
```

并返回排序后的字符串即可

```cpp
return s;
```

+ 时间复杂度$O(n\log n)$，其中$n$是字符串长度
+ 空间复杂度$O(\log n + C)$，其中$C$是字符集大小，此处取$256$

### AC代码

#### C++

```cpp
class Solution {
public:
    string frequencySort(string& s) {
        int cnt[256] = {0};
        for (char c : s)
            cnt[c]++;
        sort(s.begin(), s.end(), [&](const char& a, const char& b) {
            return cnt[a] == cnt[b] ? a > b : cnt[a] > cnt[b];
        });
        return s;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/21/LeetCode%200451.%E6%A0%B9%E6%8D%AE%E5%AD%97%E7%AC%A6%E5%87%BA%E7%8E%B0%E9%A2%91%E7%8E%87%E6%8E%92%E5%BA%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127453657](https://letmefly.blog.csdn.net/article/details/127453657)
