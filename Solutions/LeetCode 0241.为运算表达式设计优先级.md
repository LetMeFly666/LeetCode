---
title: 241.为运算表达式设计优先级
date: 2022-07-01 10:53:51
tags: [题解, LeetCode, 中等, 递归, 记忆化搜索, 数学, 字符串, 动态规划, 深度优先搜索, DFS]
---

# 【LetMeFly】241.为运算表达式设计优先级

力扣题目链接：[https://leetcode.cn/problems/different-ways-to-add-parentheses/](https://leetcode.cn/problems/different-ways-to-add-parentheses/)

<p>给你一个由数字和运算符组成的字符串&nbsp;<code>expression</code> ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 <strong>按任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>expression = "2-1-1"
<strong>输出：</strong>[0,2]
<strong>解释：</strong>
((2-1)-1) = 0 
(2-(1-1)) = 2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>expression = "2*3-4*5"
<strong>输出：</strong>[-34,-14,-10,-10,10]
<strong>解释：</strong>
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 20</code></li>
	<li><code>expression</code> 由数字和算符 <code>'+'</code>、<code>'-'</code> 和 <code>'*'</code> 组成。</li>
	<li>输入表达式中的所有整数值在范围 <code>[0, 99]</code>&nbsp;</li>
</ul>


## 方法一：DFS

这道题让人很容易想到递归。

我们用函数```dfs(string s, int l, int r)```来计算字符串```s```的```[l, r)```部分都能表示什么值。

```cpp
vector<int> dfs(string& s, int l, int r) {  // [l, r)
    vector<int> ans;

    // Code here

    return ans;
}
```

因此我们只需要调用```dfs(s, 0, s.size())```即可。

```cpp
vector<int> diffWaysToCompute(string& expression) {
    return dfs(expression, 0, expression.size());
}
```

那么接下来的问题就是```dfs```函数怎么写。

其实也不难。

+ 如果字符串```s```的```[l, r)```中没有出现运算符的话，递归结束，我们只需要返回唯一的值即可。(例如```125```)
    ```cpp
    if (!hasOp) {  // 不存在运算符
        ans.push_back(atoi(s.substr(l, r - l).c_str()));
    }
    ```
+ 否则，我们以所有的运算符为分界，分别求出运算符左边的所有可能的值、右边所有可能的值，然后一一对应做运算，就得到了新的值。
    ```cpp
    if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
        hasOp = true;
        vector<int> left = dfs(s, l, i);
        vector<int> right = dfs(s, i + 1, r);
            for (auto& a : left)
                for (auto& b : right)
                    ans.push_back(a OP b);  // 其中OP为+、-或*
    }
    ```

同时，我们使用哈希表```map```记录一下已经求过的值即可。

```cpp
map<pair<int, int>, vector<int>> ma;

vector<int> dfs(string& s, int l, int r) {
    if (ma.count({l ,r}))  // 已经计算过[l, r)的话就不需要再计算一遍
        return ma[{l, r}];
    
    // Code Here

    return ma[{l, r}] = ans;  // 这是第一次计算的话，返回结果前用顺便哈希表记录一下，避免下次重复计算
}
```

+ 时间复杂度$O(2^n)$，其中$n$是原字符串中包含的运算符的个数
+ 空间复杂度$O(2^n)$

具体复杂度这里暂不给出证明，但是肯定能过。

### AC代码

#### C++

```cpp
class Solution {
private:
    map<pair<int, int>, vector<int>> ma;

    vector<int> dfs(string& s, int l, int r) {  // [l, r)
        if (ma.count({l ,r}))
            return ma[{l, r}];
        vector<int> ans;
        bool hasOp = false;
        for (int i = l; i < r; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                hasOp = true;
                vector<int> left = dfs(s, l, i);
                vector<int> right = dfs(s, i + 1, r);
                if (s[i] == '+')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.push_back(a + b);
                else if (s[i] == '-')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.push_back(a - b);
                else if (s[i] == '*')
                    for (auto& a : left)
                        for (auto& b : right)
                            ans.push_back(a * b);
            }
        }
        if (!hasOp) {
            ans.push_back(atoi(s.substr(l, r - l).c_str()));
        }
        return ma[{l, r}] = ans;
    }
public:
    vector<int> diffWaysToCompute(string& expression) {
        return dfs(expression, 0, expression.size());
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/01/LeetCode%200241.%E4%B8%BA%E8%BF%90%E7%AE%97%E8%A1%A8%E8%BE%BE%E5%BC%8F%E8%AE%BE%E8%AE%A1%E4%BC%98%E5%85%88%E7%BA%A7/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125555659](https://letmefly.blog.csdn.net/article/details/125555659)

