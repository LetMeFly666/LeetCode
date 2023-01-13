---
title: 2287.重排字符形成目标字符串
date: 2023-01-13 15:49:33
tags: [题解, LeetCode, 简单, 哈希表, 字符串, 计数]
---

# 【LetMeFly】2287.重排字符形成目标字符串

力扣题目链接：[https://leetcode.cn/problems/rearrange-characters-to-make-target-string/](https://leetcode.cn/problems/rearrange-characters-to-make-target-string/)

<p>给你两个下标从 <strong>0</strong> 开始的字符串 <code>s</code> 和 <code>target</code> 。你可以从 <code>s</code> 取出一些字符并将其重排，得到若干新的字符串。</p>

<p>从 <code>s</code> 中取出字符并重新排列，返回可以形成 <code>target</code> 的 <strong>最大</strong> 副本数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "ilovecodingonleetcode", target = "code"
<strong>输出：</strong>2
<strong>解释：</strong>
对于 "code" 的第 1 个副本，选取下标为 4 、5 、6 和 7 的字符。
对于 "code" 的第 2 个副本，选取下标为 17 、18 、19 和 20 的字符。
形成的字符串分别是 "ecod" 和 "code" ，都可以重排为 "code" 。
可以形成最多 2 个 "code" 的副本，所以返回 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcba", target = "abc"
<strong>输出：</strong>1
<strong>解释：</strong>
选取下标为 0 、1 和 2 的字符，可以形成 "abc" 的 1 个副本。 
可以形成最多 1 个 "abc" 的副本，所以返回 1 。
注意，尽管下标 3 和 4 分别有额外的 'a' 和 'b' ，但不能重用下标 2 处的 'c' ，所以无法形成 "abc" 的第 2 个副本。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "abbaccaddaeea", target = "aaaaa"
<strong>输出：</strong>1
<strong>解释：</strong>
选取下标为 0 、3 、6 、9 和 12 的字符，可以形成 "aaaaa" 的 1 个副本。
可以形成最多 1 个 "aaaaa" 的副本，所以返回 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= target.length &lt;= 10</code></li>
	<li><code>s</code> 和 <code>target</code> 由小写英文字母组成</li>
</ul>


    
## 方法一：字符串计数

这道题的关键就是计算出每种字符在两个字符串中分别出现了多少次。

对于这个统计每个字符出现了多少次，大致有两种方法：

1. 开辟一个大小为26的整型数组，遍历字符串的同时将每个字符累加到数组中的对应位置
2. 使用编程语言自带的哈希表

我们让答案的初始值是一个很大的值（例如s.size）

1. 假如使用了方法一，那么我们从0枚举到25，如果target中存在这个字符，则更新答案，取 ```答案的原始值```和```s中这个字符的出现次数除以target中这个字符的出现次数向下取整``` 中的最小值作为答案
2. 假如使用了方法二，我们可以直接枚举target哈希表中的所有字符，以同样的方法更新答案。

遍历结束后，返回答案即可


+ 时间复杂度$O(len(s) + len(target) + C)$，其中$C=26$，也可以认为是0
+ 空间复杂度$O(C)$，其中$C=26$，也可以认为是1

### AC代码

#### C++

```cpp
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cntS[26] = {0}, cntT[26] = {0};
        for (char c : s)
            cntS[c - 'a']++;
        for (char c : target)
            cntT[c - 'a']++;
        int ans = s.size();
        for (int i = 0; i < 26; i++) {
            if (cntT[i]) {
                ans = min(ans, cntS[i] / cntT[i]);
            }
        }
        return ans;
    }
};
```

#### Python

**方法一：**

```python
class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cntS = Counter(s)
        cntT = Counter(target)
        ans = len(s)
        for i in range(26):
            thisChar = chr(ord('a') + i)
            if cntT.get(thisChar):
                ans = min(ans, cntS.get(thisChar, 0) // cntT.get(thisChar))
        return ans
```

**方法二：**

```python
class Solution:
    def rearrangeCharacters(self, s: str, target: str) -> int:
        cntS = Counter(s)
        ans = len(s)
        for thisChar, thisTimes in Counter(target).items():
            ans = min(ans, cntS.get(thisChar, 0) // thisTimes)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/01/13/LeetCode%202287.%E9%87%8D%E6%8E%92%E5%AD%97%E7%AC%A6%E5%BD%A2%E6%88%90%E7%9B%AE%E6%A0%87%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128675652](https://letmefly.blog.csdn.net/article/details/128675652)
