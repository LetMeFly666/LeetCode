---
title: 2267.检查是否有合法括号字符串路径：动态规划（bitset记状态）
date: 2026-09-29 09:03:34
tags: [题解, LeetCode, 困难, 数组, 动态规划, 矩阵, 括号匹配]
categories: [题解, LeetCode]
index_img: https://files.letmefly.xyz/d/n/leetcode/2267-example1drawio.png
---

# 【LetMeFly】2267.检查是否有合法括号字符串路径：动态规划（bitset记状态）

力扣题目链接：[https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/](https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/)

<p>一个括号字符串是一个 <strong>非空</strong>&nbsp;且只包含&nbsp;<code>'('</code>&nbsp;和&nbsp;<code>')'</code>&nbsp;的字符串。如果下面&nbsp;<strong>任意</strong>&nbsp;条件为&nbsp;<strong>真</strong>&nbsp;，那么这个括号字符串就是&nbsp;<strong>合法的</strong>&nbsp;。</p>

<ul>
	<li>字符串是&nbsp;<code>()</code>&nbsp;。</li>
	<li>字符串可以表示为&nbsp;<code>AB</code>（<code>A</code>&nbsp;连接&nbsp;<code>B</code>），<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是合法括号序列。</li>
	<li>字符串可以表示为&nbsp;<code>(A)</code>&nbsp;，其中&nbsp;<code>A</code>&nbsp;是合法括号序列。</li>
</ul>

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的括号网格图矩阵&nbsp;<code>grid</code>&nbsp;。网格图中一个&nbsp;<strong>合法括号路径</strong>&nbsp;是满足以下所有条件的一条路径：</p>

<ul>
	<li>路径开始于左上角格子&nbsp;<code>(0, 0)</code>&nbsp;。</li>
	<li>路径结束于右下角格子&nbsp;<code>(m - 1, n - 1)</code>&nbsp;。</li>
	<li>路径每次只会向 <strong>下</strong>&nbsp;或者向 <strong>右</strong>&nbsp;移动。</li>
	<li>路径经过的格子组成的括号字符串是<strong>&nbsp;合法</strong>&nbsp;的。</li>
</ul>

<p>如果网格图中存在一条 <strong>合法括号路径</strong>&nbsp;，请返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://files.letmefly.xyz/d/n/leetcode/2267-example1drawio.png" style="width: 521px; height: 300px;" /></p>

<pre>
<b>输入：</b>grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
<b>输出：</b>true
<b>解释：</b>上图展示了两条路径，它们都是合法括号字符串路径。
第一条路径得到的合法字符串是 "()(())" 。
第二条路径得到的合法字符串是 "((()))" 。
注意可能有其他的合法括号字符串路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://files.letmefly.xyz/d/n/leetcode/2267-example2drawio.png" style="width: 165px; height: 165px;" /></p>

<pre>
<b>输入：</b>grid = [[")",")"],["(","("]]
<b>输出：</b>false
<b>解释：</b>两条可行路径分别得到 "))(" 和 ")((" 。由于它们都不是合法括号字符串，我们返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>'('</code>&nbsp;，要么是&nbsp;<code>')'</code> 。</li>
</ul>


    
## 解题方法：动态规划

创建一个二维数组`DP`，其中`DP[i][j]`表示从起点到达位置`(i,j)`时，所有可能的括号状态。

怎么表示所有的状态？不难发现，我们只需要记录**左括号比右括号多几个**（不能为负数），使用一个有$m+n+1$位的大整数bitset来表示即可。其中bitset的第$k$位为1则表示到该位置存在左括号比右括号多$k$个的路径。

状态怎么转移？一个位置要么从左边要么从上方来，如果这个位置是`(`，到其上方为止左括号比右括号可能多$1, 3, 7$个，那么到该位置位置左括号比右括号可能多$2, 4, 8$个，即上方的bitset左移一位。如果这个位置是`)`，即上方的bitset右移一位。

初始值`grid[0][0]`如果是`(`则有`dp[0][0]`的第1位为1，最终若`dp[m-1][n-1]`的第0位为1，则说明存在一条路径左右括号数量相等，返回`true`。

有同学担心`)(`这种左右括号数量相等但其实不合法的情况怎么办，其实不用担心，遇到`)`时候左括号比右括号数量多`-1`个，而bitset没有`-1`位，相当于这种情况在bitset右移的时候直接给抹掉了。

+ 时间复杂度$O(mn \frac{m+n}{W})$，其中$W$是机器字长，现多为64。
+ 空间复杂度$O(mn \frac{m+n}{W})$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-29 08:53:56
 */
typedef bitset<201> states;
class Solution {
private:
    void modify(states& now, states& from, bool is_more) {
        if (is_more) {
            now |= from << 1;
        } else {
            now |= from >> 1;
        }
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<states>> dp(n, vector<states>(m));
        if (grid[0][0] == ')') {
            return false;
        }
        dp[0][0].set(1);
        vector<array<int, 2>> care_list = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 2}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool is_more = grid[i][j] == '(';
                if (i) {
                    modify(dp[i][j], dp[i - 1][j], is_more);
                }
                if (j) {
                    modify(dp[i][j], dp[i][j - 1], is_more);
                }
            }
        }
        return dp[n - 1][m - 1].test(0);
    }
};

#ifdef _DEBUG
/*
[["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]

true
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<char>> v = stringToVectorVectorC(s);
        debug(v);
        Solution sol;
        cout << sol.hasValidPath(v) << endl;
    }
    return 0;
}
#endif
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166829770)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/29/LeetCode%202267.%E6%A3%80%E6%9F%A5%E6%98%AF%E5%90%A6%E6%9C%89%E5%90%88%E6%B3%95%E6%8B%AC%E5%8F%B7%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%B7%AF%E5%BE%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
