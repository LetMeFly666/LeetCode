---
title: 1790.仅执行一次字符串交换能否使两个字符串相等
date: 2022-10-11 10:15:40
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数]
---

# 【LetMeFly】1790.仅执行一次字符串交换能否使两个字符串相等

力扣题目链接：[https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/](https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/)

<p>给你长度相等的两个字符串 <code>s1</code> 和 <code>s2</code> 。一次<strong> 字符串交换 </strong>操作的步骤如下：选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。</p>

<p>如果对 <strong>其中一个字符串</strong> 执行 <strong>最多一次字符串交换</strong> 就可以使两个字符串相等，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s1 = "bank", s2 = "kanb"
<strong>输出：</strong>true
<strong>解释：</strong>例如，交换 s2 中的第一个和最后一个字符可以得到 "bank"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s1 = "attack", s2 = "defend"
<strong>输出：</strong>false
<strong>解释：</strong>一次字符串交换无法使两个字符串相等
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s1 = "kelb", s2 = "kelb"
<strong>输出：</strong>true
<strong>解释：</strong>两个字符串已经相等，所以不需要进行字符串交换
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s1 = "abcd", s2 = "dcba"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 100</code></li>
	<li><code>s1.length == s2.length</code></li>
	<li><code>s1</code> 和 <code>s2</code> 仅由小写英文字母组成</li>
</ul>


    
## 方法一：存不同之处的下标

首先，如果两个字符串长度不同，直接返回```false```

遍历一遍字符串，用一个数组```diff```把两个字符串对应位置字母不同处的下标记录下来。

如果```diff```为空，那就说明两个字符串原本就相同，直接返回```true```

否则就得进行**一次交换**

一次交换能交换好的前提是```diff```中存放的“不同元素”个数为2，且其中一个字符串这两个位置交换后和另一个字符串相等。

如果满足上述前提，就返回```true```，否则返回```false```

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(Diff)$，其中$Diff$是两个字符串中，对应位置元素不同的个数。这里经过优化可以将复杂度降为$O(1)$，因为最多有两个不同元素的位置，因此如果```diff```中已经存在了两个元素，并且又遇到了不对应的元素，就直接返回```false```

### AC代码

#### C++

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        if (diff.empty())
            return true;
        if (diff.size() == 2 && (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]))
            return true;
        return false;
    }
};
```

## 方法二：费力不讨好的优化

与方法一类似，方法一中，我们知道最多有两个位置元素不同。因此我们可以不使用动态数组，而是直接使用两个变量来解决。这样，理论上开销应该会小一丢丢。

用两个变量```firstDiffLoc```和```secondDiffLoc```分别记录第一个和第二个元素不同的位置。二者初始值都是```-1```

因此，要判断已经有几个不同元素的位置，只需要判断这两个变量是否为```-1```即可。

+ 时间复杂度$O(n)$，其中$n$是字符串长度
+ 空间复杂度$O(1)$

因本题数据量只有100，因此上述方法是“费力不讨好系列”，效果并不明显，甚至时间占用增加了。

### AC代码

#### C++

```cpp
class Solution {
public:
    bool areAlmostEqual(string& s1, string& s2) {
        if (s1.size() != s2.size())
            return false;
        int firstDiffLoc = -1, secondDiffLoc = -1;
        for (int i = s1.size() - 1; i >= 0; i--) {
            if (s1[i] != s2[i]) {
                if (firstDiffLoc == -1) {
                    firstDiffLoc = i;
                }
                else if (secondDiffLoc == -1) {
                    secondDiffLoc = i;
                }
                else {
                    return false;
                }
            }
        }
        if (firstDiffLoc == -1)  // 全相同
            return true;
        if (secondDiffLoc != -1 && (s1[firstDiffLoc] == s2[secondDiffLoc] && s1[secondDiffLoc] == s2[firstDiffLoc]))  // 正好两个不同，且不同的那两个互换后相同了
            return true;
        return false;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/11/LeetCode%201790.%E4%BB%85%E6%89%A7%E8%A1%8C%E4%B8%80%E6%AC%A1%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%BA%A4%E6%8D%A2%E8%83%BD%E5%90%A6%E4%BD%BF%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9B%B8%E7%AD%89/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127258599](https://letmefly.blog.csdn.net/article/details/127258599)
