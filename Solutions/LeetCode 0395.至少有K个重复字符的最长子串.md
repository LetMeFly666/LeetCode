---
title: 395.至少有 K 个重复字符的最长子串
date: 2022-10-13 10:18:05
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 分治, 滑动窗口, 递归]
categories: [题解, LeetCode]
---

# 【LetMeFly】395.至少有 K 个重复字符的最长子串

力扣题目链接：[https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/](https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/)

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> ，请你找出 <code>s</code> 中的最长子串， 要求该子串中的每一字符出现次数都不少于 <code>k</code> 。返回这一子串的长度。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabb", k = 3
<strong>输出：</strong>3
<strong>解释：</strong>最长子串为 "aaa" ，其中 'a' 重复了 3 次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ababbc", k = 2
<strong>输出：</strong>5
<strong>解释：</strong>最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>1 <= k <= 10<sup>5</sup></code></li>
</ul>


    
~~本题编号是0395呢~~

## 方法一：递归

我们来看要实现的```longestSubstring```函数。

它接受参数“字符串s”和“出现次数k”，返回串中字母每个都在串中出现至少$k$次的最长子串长度

首先，我们遍历字符串中出现的每一种字母。对于某种字母，如果这种字母出现次数本来就不足$k$次，那么只要是包含这种字母的子串，必定不满足题目要求。

因此，我们就可以以这种字母为分界，研究不包含这种字母的部分是否是满足题意的子串（递归）

例如```aaabcccc, k = 3```，我们遍历字符串```aaabcccc```中出现过的每一种字母```a```、```b```、```c```

+ 对于字母```a```，其出现次数满足“最少出现3次”
+ 对于字母```b```，其出现次数不满足“最少出现3次”，因此以```b```为分隔，递归判断各个子串是否符合要求
    
	以```b```为分隔，可以将原始字符串分割成两个子串，分别是```aaa```和```cccc```，我们对这两个子串分别计算```longestSubstring```，最优结果即为答案
	+ 对于字符串```aaa```：其中只包含字母```a```，且```a```出现的次数满足“最少出现3次”。也就是说这是一个满足题意的字符串，返回答案“3”
	+ 对于字符串```cccc```：其中只包含字母```c```，且```c```出现的次数满足“最少出现3次”。也就是说这是一个满足题意的字符串，返回答案“4”
	
	因此递归结束后，最佳答案是```4```
+ 对于字母```c```，其出现次数满足“最少出现3次”

<!-- 对于

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$ -->

### AC代码

#### Python

```Python
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(substr, k) for substr in s.split(c))
        return len(s)
```

#### C++

```cpp
class Solution {
private:
    unordered_set<char> differentChar(string& s) {
        unordered_set<char> se;
        for (char c : s) {
            se.insert(c);
        }
        return se;
    }
public:
    int longestSubstring(string s, int k) {
        // printf("cal(%s)\n", s.c_str());
        for (char c : differentChar(s)) {
            if (count(s.begin(), s.end(), c) < k) {
                int ans = 0;
                int l = 0;
                for (int i = 0; i <= s.size(); i++) {
                    if (i == s.size() || s[i] == c) {
                        if (l < i) {
                            ans = max(ans, longestSubstring(s.substr(l, i - l), k));
                        }
                        l = i + 1;
                    }
                }
                return ans;
            }
        }
        return s.size();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/13/LeetCode%200395.%E8%87%B3%E5%B0%91%E6%9C%89K%E4%B8%AA%E9%87%8D%E5%A4%8D%E5%AD%97%E7%AC%A6%E7%9A%84%E6%9C%80%E9%95%BF%E5%AD%90%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127296624](https://letmefly.blog.csdn.net/article/details/127296624)
