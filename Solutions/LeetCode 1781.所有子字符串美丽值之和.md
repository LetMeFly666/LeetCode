---
title: 1781.所有子字符串美丽值之和
date: 2022-12-12 11:42:31
tags: [题解, LeetCode, 中等, 哈希表, 字符串, 计数, 前缀和, 遍历]
---

# 【LetMeFly】1781.所有子字符串美丽值之和

力扣题目链接：[https://leetcode.cn/problems/sum-of-beauty-of-all-substrings/](https://leetcode.cn/problems/sum-of-beauty-of-all-substrings/)

<p>一个字符串的 <strong>美丽值</strong> 定义为：出现频率最高字符与出现频率最低字符的出现次数之差。</p>

<ul>
	<li>比方说，<code>"abaacc"</code> 的美丽值为 <code>3 - 1 = 2</code> 。</li>
</ul>

<p>给你一个字符串 <code>s</code> ，请你返回它所有子字符串的 <strong>美丽值</strong> 之和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aabcb"
<b>输出：</b>5
<strong>解释：</strong>美丽值不为零的字符串包括 ["aab","aabc","aabcb","abcb","bcb"] ，每一个字符串的美丽值都为 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "aabcbaa"
<b>输出：</b>17
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <=<sup> </sup>500</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>


    
## 方法一：前缀和

我们分别统计出26种字母的[前缀和](https://leetcode.letmefly.xyz/tags/%E5%89%8D%E7%BC%80%E5%92%8C/)

这样，我们只需要枚举子串区间（两重循环枚举子串首尾），再统计出这个区间中，字母的最大和最小出现频率，累加到答案中即可。

+ 时间复杂度$O(len(s)^2C)$，其中$C=26$
+ 空间复杂度$O(len(s)C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<vector<int>> prefix(26, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int c = 0; c < 26; c++) {
                prefix[c][i] = prefix[c][i - 1];
            }
            prefix[s[i - 1] - 'a'][i]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int M = 0, m = 1000;
                for (int c = 0; c < 26; c++) {
                    int thisC = prefix[c][j + 1] - prefix[c][i];
                    M = max(M, thisC);
                    if (thisC) {  // 不能出现0次
                        m = min(m, thisC);
                    }
                }
                // printf("i = %d, j = %d, M = %d, m = %d\n", i, j, M, m);  //***********
                ans += M - m;
            }
        }
        return ans;
    }
};
```

## 方法二：边遍历边计算

方法一中，我们预处理使用前缀和计算出了每种元素的出现情况。但是每种字母的前缀和都需要$O(len(s))$的空间复杂度来保存

方法二中，我们不提前预处理计算出字母的出现情况，而是在枚举字符串终点的同时计算。这样，空间复杂度就减小了一个维度。

+ 时间复杂度$O(len(s)^2C)$，其中$C=26$
+ 空间复杂度$O(C)$，相比于前缀和，我们没有提前计算出每个元素的前缀和情况，而是枚举子串终点的过程中计算。因此，空间复杂度少了一个维度（字符串的长度）

### AC代码

#### C++

```cpp
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int cnt[26] = {0};  // 只需要开辟O(C)的空间
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;  // 枚举子串终点的同时统计元素出现的次数
                int M = 0, m = 1000;
                for (int d = 0; d < 26; d++) {
                    M = max(M, cnt[d]);
                    if (cnt[d])
                        m = min(m, cnt[d]);
                }
                ans += M - m;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/12/LeetCode%201781.%E6%89%80%E6%9C%89%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%BE%8E%E4%B8%BD%E5%80%BC%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128285137](https://letmefly.blog.csdn.net/article/details/128285137)
