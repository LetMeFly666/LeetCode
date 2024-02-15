---
title: 131.分割回文串
date: 2022-07-23 12:01:28
tags: [题解, LeetCode, 中等, 字符串, 动态规划, 回溯, 状态压缩]
---

# 【LetMeFly】131.分割回文串：暴力解法

力扣题目链接：[https://leetcode.cn/problems/palindrome-partitioning/](https://leetcode.cn/problems/palindrome-partitioning/)

<p>给你一个字符串 <code>s</code>，请你将<em> </em><code>s</code><em> </em>分割成一些子串，使每个子串都是 <strong>回文串</strong> 。返回 <code>s</code> 所有可能的分割方案。</p>

<p><strong>回文串</strong> 是正着读和反着读都一样的字符串。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aab"
<strong>输出：</strong>[["a","a","b"],["aa","b"]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a"
<strong>输出：</strong>[["a"]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 16</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>


    
## 方法一：状态压缩，暴力解法

字符串的长度最大为16，$2^{16}\times 16^2=16,777,216$，实际并不会弯完全执行，可在$1s$内解决。

因此不如枚举“分割位置”，然后判断分割后的子串是否都是回文串。

因为长度为$n$的字符串最多切$n-1$刀，那么我们可以用$i$从$0$到$2^{n-1}$枚举切割状态。

如果二进制下$i$的第$j$位为$1$，那么就在原字符串第$i+1$个字符后面切一刀。

+ 时间复杂度$O(2^n\times n^2)$，其中$n$是字符串的长度
+ 空间复杂度$O(n)$，只需要把某次的切割结果存起来（答案不计入算法空间复杂度）

### AC代码

#### C++

```cpp
class Solution {
private:
    inline bool ok(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size() - 1;  // 不如n直接-1
        vector<vector<string>> ans;
        for (int i = 0; i < (1 << n); i++) {  // 枚举切割状态
            int lastLoc = 0;
            vector<string> thisSplited;
            string thisStr;
            for (int j = 0; j < n; j++) {  // 看第j位是否为1
                if (i & (1 << j)) {
                    thisStr = s.substr(lastLoc, j + 1 - lastLoc);
                    if (!ok(thisStr)) {
                        goto loop;
                    }
                    thisSplited.push_back(thisStr);
                    lastLoc = j + 1;
                }
            }
            thisStr = s.substr(lastLoc, s.size() - lastLoc);  // 切k刀会生成k+1个子串，记得把最后一个子串统计进来
            if (!ok(thisStr))
                goto loop;
            thisSplited.push_back(thisStr);
            ans.push_back(thisSplited);
            loop:;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/23/LeetCode%200131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125946017](https://letmefly.blog.csdn.net/article/details/125946017)
