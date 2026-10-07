---
title: 301.删除无效的括号：二进制枚举 / 回溯
date: 2026-10-07 14:31:23
tags: [题解, LeetCode, 困难, 深度优先搜索, DFS, 字符串, 回溯, 二进制枚举, 括号匹配]
categories: [题解, LeetCode]
---

# 【LetMeFly】301.删除无效的括号：二进制枚举 / 回溯

力扣题目链接：[https://leetcode.cn/problems/remove-invalid-parentheses/](https://leetcode.cn/problems/remove-invalid-parentheses/)

<p>给你一个由若干括号和字母组成的字符串 <code>s</code> ，删除最小数量的无效括号，使得输入的字符串有效。</p>

<p>返回所有可能的结果。答案可以按 <strong>任意顺序</strong> 返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "()())()"
<strong>输出：</strong>["(())()","()()()"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "(a)())()"
<strong>输出：</strong>["(a())()","(a)()()"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = ")("
<strong>输出：</strong>[""]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 25</code></li>
	<li><code>s</code> 由小写英文字母以及括号 <code>'('</code> 和 <code>')'</code> 组成</li>
	<li><code>s</code> 中至多含 <code>20</code> 个括号</li>
</ul>


    
## 解题方法一：二进制枚举

首先遍历一遍原始字符串得到括号的下标有哪些、得到至少需要移除多少个括号。

> 关于至少需要移除多少个字符，可以参考昨天的题目《[921.使括号有效的最少添加：一次遍历（贪心）](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/)》。
> 
> 简言之就是使用一个变量`left`记录左括号比右括号多几个，`left < 0`则说明需要移除当前右括号；以及最终剩下`left`个未配对的左括号也需要被移除。

假设括号有`m`个，那么我们可以使用一个`m`位的二进制数$i\in [0, 2^m)$来表示保留哪个括号（其中`i`二进制下第`j`位为`1`的话表示整个字符串第`j`个括号被保留）。

假设要移除`k`个括号，如果`i`二进制下恰好有`len(s) - k`个`1`，则构造对应的字符串，并遍历一遍看看该字符串是否合法。

> 关于一个括号序列字符串是否合法，类似问题“至少需要移除多少个字符使得括号序列合法”，如果至少需要移除`0`个括号则说明原始字符串合法。

### 时空复杂度

+ 时间复杂度$O(2^m+n\times2^k)$
+ 空间复杂度$O(n\times C_m^k)$

其中$n=len(s)$，$m$是字符串中的括号数量，$k$是至少需要移除括号的数量。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-07 11:47:10
 */
class Solution {
private:
    vector<int> idxs;  // 括号位置
    int mini_remove;

    void getInfo(const string& s) {
        int left = 0;
        mini_remove = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                idxs.push_back(i);
                left++;
            } else if (s[i] == ')') {
                idxs.push_back(i);
                if (left) {
                    left--;
                } else {
                    mini_remove++;
                }
            }
        }
        mini_remove += left;
    }

    string genS(const string& s, int mask) {
        string this_s;
        this_s.reserve(s.size() - mini_remove);
        vector<int> deleted;
        deleted.reserve(idxs.size());
        for (int i = 0; i < idxs.size(); i++) {
            if (mask >> i & 1) {
                deleted.push_back(idxs[i]);
            }
        }
        for (int is = 0, ic = 0; is < s.size(); is++) {
            if (ic < deleted.size() && is == deleted[ic]) {
                ic++;
            } else {
                this_s.push_back(s[is]);
            }
        }
        return this_s;
    }

    bool ok(const string& s) {
        int left = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                if (left) {
                    left--;
                } else {
                    return false;
                }
            }
        }
        return !left;
    }
public:
    vector<string> removeInvalidParentheses(const string& s) {
        unordered_set<string> se;
        getInfo(s);
        int parentheses = idxs.size();
        
        for (int i = 0, to = 1 << parentheses; i < to; i++) {
            if (__builtin_popcount(i) != mini_remove) {
                continue;
            }
            string this_s = genS(s, i);
            if (ok(this_s)) {
                se.insert(this_s);
            }
        }
        return vector<string>(se.begin(), se.end());
    }
};
```

## 解题方法二：回溯

类似方法一，遍历一次原始字符串得到需要移除多少左括号、需要移除多少右括号。

写一个回溯函数`dfs(s, idx, left, left_removed, right_removed)`，其中：

+ `s`是原始字符串
+ `idx`是当前遍历到的下标
+ `left`是当前已经保留的左括号比右括号多几个
+ `left_removed`是当前已经移除的左括号数量
+ `right_removed`是当前已经移除的右括号数量

如果`idx == s.size()`，则说明已经遍历完了原始字符串，终止递归。递归终止之前看下如果`left`为零、`left_removed`和`right_removed`分别等于需要移除的左右括号数量，则说明**找到了一种可行的移除方案**，放入答案集合中。

否则开始回溯尝试：

1. 如果当前字符是左括号`(`，并且还有左括号可以移除（`left_removed < remove_left`），则尝试移除当前左括号；
2. 如果当前字符是右括号`)`，并且还有右括号可以移除（`right_removed < remove_right`），则尝试移除当前右括号；
3. 尝试不移除当前字符（只要不是 “`left==0`并且当前字符是右括号”就可以尝试保留当前字符）。递归结束回来记得弹出当前保留的字符。

### 时空复杂度

+ 时间复杂度$O()$，其中$n=len(s)$，$m$是字符串中的括号数量，$k$是至少需要移除括号的数量
+ 空间复杂度$O()$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-07 14:28:52
 */
class Solution {
private:
    int remove_left, remove_right;
    string now;
    unordered_set<string> ans;

    void getInfo(const string& s) {
        remove_left = remove_right = 0;
        for (char c : s) {
            if (c == '(') {
                remove_left++;
            } else if (c == ')') {
                if (remove_left) {
                    remove_left--;
                } else {
                    remove_right++;
                }
            }
        }
    }

    void dfs(const string& s, int idx, int left, int left_removed, int right_removed) {
        if (idx == s.size()) {
            if (left == 0 && left_removed == remove_left && right_removed == remove_right) {
                ans.insert(now);
            }
            return;
        }
        
        if (s[idx] == '(' && left_removed < remove_left) {
            dfs(s, idx + 1, left, left_removed + 1, right_removed);
        }
        if (s[idx] == ')' && right_removed < remove_right) {
            dfs(s, idx + 1, left, left_removed, right_removed + 1);
        }
        // don't remove
        left += s[idx] == '(' ? 1 : s[idx] == ')' ? -1 : 0;
        if (left < 0) {
            return;
        }
        now.push_back(s[idx]);
        dfs(s, idx + 1, left, left_removed, right_removed);
        now.pop_back();
    }
public:
    vector<string> removeInvalidParentheses(const string& s) {
        getInfo(s);
        now.reserve(s.size() - remove_left - remove_right);
        dfs(s, 0, 0, 0, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};
```


## End

今日LeetCode.每日一题连续1906天了。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/167221265)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/07/LeetCode%200301.%E5%88%A0%E9%99%A4%E6%97%A0%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
