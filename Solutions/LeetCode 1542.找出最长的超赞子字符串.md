---
title: 1542.找出最长的超赞子字符串
date: 2024-05-20 23:43:31
tags: [题解, LeetCode, 困难, 位运算, 哈希表, 哈希, map, 字符串, 前缀和]
---

# 【LetMeFly】1542.找出最长的超赞子字符串：前缀异或和（位运算）

力扣题目链接：[https://leetcode.cn/problems/find-longest-awesome-substring/](https://leetcode.cn/problems/find-longest-awesome-substring/)

<p>给你一个字符串 <code>s</code> 。请返回 <code>s</code> 中最长的 <strong>超赞子字符串</strong> 的长度。</p>

<p>「超赞子字符串」需满足满足下述两个条件：</p>

<ul>
	<li>该字符串是 <code>s</code> 的一个非空子字符串</li>
	<li>进行任意次数的字符交换后，该字符串可以变成一个回文字符串</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;3242415&quot;
<strong>输出：</strong>5
<strong>解释：</strong>&quot;24241&quot; 是最长的超赞子字符串，交换其中的字符后，可以得到回文 &quot;24142&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;12345678&quot;
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;213123&quot;
<strong>输出：</strong>6
<strong>解释：</strong>&quot;213123&quot; 是最长的超赞子字符串，交换其中的字符后，可以得到回文 &quot;231132&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;00&quot;
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> 仅由数字组成</li>
</ul>


    
## 解题方法：前缀和+哈希表+位运算

回文串有两种情况：

> 1. 所有字符都出现了偶数次、
> 2. 有且仅有一个字符出现了奇数次。

也就是说我们只用关心每个字符出现次数是奇数还是偶数即可。因此我们可以使用一个数$mask$，$mask$的第$i$位表示数字$i$出现次数是否为奇数次。

> 加入在$mask$的基础上又出现了$i$，则新的$mask$的计算公式为：```mask ^= 1 << i```。

我们只需要遍历一遍字符串，并且使用哈希表，哈希表$ma[mask]$为前面所有数字结果为$mask$的第一次出现位置。则遍历过程中有“

> + 若当前$mask$出现过，则这两次出现位置之间所有字符都出现了偶数次，满足回文串要求；
> + 若当前$mask$变化一位后在哈希表中存在，则这两次出现位置之间的字符串只有一个出现了奇数次，满足回文串要求。

遍历结束，算法结束。

+ 时间复杂度$O(len(s)\times C)$，其中$C$是字符个数，这里$C=10$
+ 空间复杂度$O(\min\{len(s), 2^C\})$

### AC代码

#### C++

```cpp
class Solution {
public:
    int longestAwesome(string s) {
        int mask = 0, ans = 1;
        unordered_map<int, int> ma;
        ma[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            mask ^= (1 << (s[i] - '0'));
            if (ma.count(mask)) {
                ans = max(ans, i - ma[mask]);
            }
            else {
                ma[mask] = i;
            }
            // 一个奇数次字符
            for (int j = 0; j < 10; j++) {
                int mask2 = mask ^ (1 << j);
                if (ma.count(mask2)) {
                    ans = max(ans, i - ma[mask2]);
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def longestAwesome(self, s: str) -> int:
        mask, ans = 0, 1
        ma = {0: -1}
        for i in range(len(s)):
            mask ^= 1 << (ord(s[i]) - ord('0'))
            if mask in ma:
                ans = max(ans, i - ma[mask])
            else:
                ma[mask] = i
            for j in range(10):
                mask2 = mask ^ (1 << j)
                if mask2 in ma:
                    ans = max(ans, i - ma[mask2])
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/20/LeetCode%201542.%E6%89%BE%E5%87%BA%E6%9C%80%E9%95%BF%E7%9A%84%E8%B6%85%E8%B5%9E%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139077950](https://letmefly.blog.csdn.net/article/details/139077950)
