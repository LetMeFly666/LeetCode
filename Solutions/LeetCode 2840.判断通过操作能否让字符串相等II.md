---
title: 2840.判断通过操作能否让字符串相等 II：字符串排序或哈希表
date: 2026-03-30 09:33:41
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2840.判断通过操作能否让字符串相等 II：字符串排序或哈希表

力扣题目链接：[https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/](https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii/)

<p>给你两个字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;，两个字符串长度都为&nbsp;<code>n</code>&nbsp;，且只包含&nbsp;<strong>小写&nbsp;</strong>英文字母。</p>

<p>你可以对两个字符串中的 <strong>任意一个</strong>&nbsp;执行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>选择两个下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，满足 <code>i &lt; j</code>&nbsp;且 <code>j - i</code>&nbsp;是 <strong>偶数</strong>，然后 <strong>交换</strong> 这个字符串中两个下标对应的字符。</li>
</ul>

<p>&nbsp;</p>

<p>如果你可以让字符串<em>&nbsp;</em><code>s1</code><em> </em>和<em>&nbsp;</em><code>s2</code>&nbsp;相等，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s1 = "abcdba", s2 = "cabdab"
<b>输出：</b>true
<b>解释：</b>我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbadba" 。
- 选择下标 i = 2 ，j = 4 ，得到字符串 s1 = "cbbdaa" 。
- 选择下标 i = 1 ，j = 5 ，得到字符串 s1 = "cabdab" = s2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s1 = "abe", s2 = "bea"
<b>输出：</b>false
<b>解释：</b>无法让两个字符串相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s1.length == s2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s1</code> 和&nbsp;<code>s2</code>&nbsp;只包含小写英文字母。</li>
</ul>


# 解题思路：奇偶分别判

奇数下标元素可以任意交换，偶数下标也可以任意交换，所以只需要分别看看在所有奇数位置组成的字符串和偶数位置组成的字符串是否等价就好了。

## 方法一：字符串排序

将奇数位置和偶数位置字符分别摘出来组成临时字符串，排序，看是否相等。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-30 09:28:44
 */
class Solution {
public:
    bool checkStrings(const string& s1, const string& s2) {
        int n = s1.size();
        string odd1, odd2, even1, even2;
        odd1.reserve(n / 2);
        odd2.reserve(n / 2);
        even1.reserve(n / 2);
        even2.reserve(n / 2);
        for (int i = 0; i < n; i++) {
            if (i % 2) {
                odd1.push_back(s1[i]);
                odd2.push_back(s2[i]);
            } else {
                even1.push_back(s1[i]);
                even2.push_back(s2[i]);
            }
        }
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());
        return odd1 == odd2 && even1 == even2;
    }
};
```

## 方法二：哈希表

哈希表统计两个字符串在奇数位置和偶数位置出现字符次数的diff，若最终哈希表中元素全部为$0$则返回true。

+ 时间复杂度$O(n + C)$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-30 09:32:52
 */
class Solution {
public:
    bool checkStrings(const string& s1, const string& s2) {
        int n = s1.size();
        int cnt[2][26] = {0};
        for (int i = 0; i < n; i++) {
            cnt[i % 2][s1[i] - 'a']++;
            cnt[i % 2][s2[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; i++) {
            if (cnt[0][i] || cnt[1][i]) {
                return false;
            }
        }
        return true;
    }
};
```

AC,98.21%,100.00%

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159634187)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/30/LeetCode%202840.%E5%88%A4%E6%96%AD%E9%80%9A%E8%BF%87%E6%93%8D%E4%BD%9C%E8%83%BD%E5%90%A6%E8%AE%A9%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9B%B8%E7%AD%89II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
