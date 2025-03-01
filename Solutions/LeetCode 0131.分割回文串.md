---
title: 131.分割回文串：二进制枚举OR回溯
date: 2022-07-23 12:01:28
tags: [题解, LeetCode, 中等, 字符串, 动态规划, 回溯, 状态压缩, 二进制枚举, 回文, 回文串]
---

# 【LetMeFly】131.分割回文串：二进制枚举OR回溯

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


    
## 方法一：二进制枚举（状态压缩，暴力解法）

字符串的长度最大为16，$2^{16}\times 16^2=16,777,216$，实际并不会弯完全执行，可在$1s$内解决。

因此不如枚举“分割位置”，然后判断分割后的子串是否都是回文串。

因为长度为$n$的字符串最多切$n-1$刀，那么我们可以用$i$从$0$到$2^{n-1}$枚举切割状态。

如果二进制下$i$的第$j$位为$1$，那么就在原字符串第$i+1$个字符后面切一刀。

+ 时间复杂度$O(2^n\times n)$，其中$n$是字符串的长度
+ 空间复杂度$O(n)$，只需要把某次的切割结果存起来（答案不计入算法空间复杂度）

### AC代码

#### C++ - 多层嵌套版

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-07-23 11:50:50
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-07-23 11:56:43
 */
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

#### C++ - 函数调用版

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 15:34:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:01:13
 * @Description: 头脑不清醒这题写了半小时好难受
 */
/*
s = aba
n = 3
status = 4(共4种状态)
*/

class Solution {
private:
    int n;
    string s;

    bool isok(int l, int r) {  // [l, r)
        for (r--; l < r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }

    bool isOk_all(int code) {
        int l = 0;
        for (int r = 0; r < n - 1; r++) {
            if (code >> r & 1) {
                if (!isok(l, r + 1)) {
                    return false;
                }
                l = r + 1;
            }
        }
        return isok(l, n);
    }

    void store(vector<vector<string>>& ans, int code) {
        ans.push_back({});
        int l = 0;
        for (int r = 0; r < n - 1; r++) {
            if (code >> r & 1) {
                ans.back().push_back(s.substr(l, r - l + 1));
                l = r + 1;
            }
        }
        ans.back().push_back(s.substr(l, n - l + 1));
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        this->s = move(s);
        int status = 1 << (n - 1);
        vector<vector<string>> ans;
        for (int c = 0; c < status; c++) {
            if (isOk_all(c)) {
                store(ans, c);
            }
        }
        return ans;
    }
};
```

## 方法二：回溯

写一个函数`dfs(start)`来分割字符串`s`从下标`start`开始的子字符串。

首先，如果`start`已经越界，则说明找到了一种合理的分割方法，将这种分割方案加入答案数组种并返回。

依次枚举这次的子字符串。尝试将找到的下标从`start`开始的**回文**字符串加入本次分割方案，继续`dfs`，并在`dfs`结束后回滚(撤销这次子回文串的选择)。

+ 时间复杂度$O(2^n\times n^2)$，其中$n$是字符串的长度
+ 空间复杂度$O(n^2)$

### AC代码

#### C++


```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 16:02:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:11:13
 * @Descriptions: AC,91.81%,95.10%
 */
class Solution {
private:
    string s;
    vector<string> now;
    vector<vector<string>> ans;

    bool isok(int l, int r) {  // [l, r]
        for (; l < r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }

    void dfs(int l) {
        if (l == s.size()) {
            ans.push_back(now);
            return;
        }
        for (int r = l; r < s.size(); r++) {
            if (isok(l, r)) {
                now.push_back(s.substr(l, r - l + 1));
                dfs(r + 1);
                now.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = move(s);
        dfs(0);
        return move(ans);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-01 16:13:32
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-01 16:17:40
'''
from typing import List

class Solution:
    def ok(self, s: str) -> bool:
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - i - 1]:
                return False
        return True

    def dfs(self, l: int) -> None:
        if l == len(self.s):
            self.ans.append([i for i in self.now])
            return
        for r in range(l, len(self.s)):
            temp = self.s[l:r + 1]
            if self.ok(temp):
                self.now.append(temp)
                self.dfs(r + 1)
                self.now.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.ans: List[List[str]] = []
        self.now: List[str] = []
        self.s = s
        self.dfs(0)
        return self.ans
```

#### Golang

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 16:28:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:41:12
 */
package main

type Solution_PP struct {
    s string
    ans [][]string
    now []string
    
}

func (this* Solution_PP) ok(s string) bool {
    for i := 0; i < len(s) / 2; i++ {
        if s[i] != s[len(s) - i - 1] {
            return false
        }
    }
    return true
}

func (this* Solution_PP) dfs(l int) {
    if l == len(this.s) {
        this.ans = append(this.ans, append([]string{}, this.now...))
        return
    }
    for r := l; r < len(this.s); r++ {
        temp := this.s[l:r + 1]
        if this.ok(temp) {
            this.now = append(this.now, temp)
            this.dfs(r + 1)
            this.now = this.now[:len(this.now) - 1]
        }
    }
}

func partition(s string) [][]string {
    solution := Solution_PP{s: s}
    solution.dfs(0)
    return solution.ans
}
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-01 16:18:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-01 16:27:47
 */
import java.util.List;
import java.util.ArrayList;


class Solution {
    private List<List<String>> ans;
    private List<String> now;
    private String s;
    
    private boolean ok(int l, int r) {  // [l, r]
        for (; l < r; l++, r--) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
        }
        return true;
    }

    private void dfs(int l) {
        if (l == s.length()) {
            ans.add(new ArrayList<>(now));
            return;
        }
        for (int r = l; r < s.length(); r++) {
            if (ok(l, r)) {
                now.add(s.substring(l, r + 1));
                dfs(r + 1);
                now.remove(now.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        ans = new ArrayList<>();
        now = new ArrayList<>();
        this.s = s;
        dfs(0);
        return ans;
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/125946017)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2022/07/23/LeetCode%200131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)