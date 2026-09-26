---
title: 1096.花括号展开 II：一个一百行的解题方法（DFS）
date: 2026-09-26 11:33:01
tags: [题解, LeetCode, 困难, 栈, 广度优先搜索, 哈希表, 字符串, 回溯, 排序, 深度优先搜索, DFS]
categories: [题解, LeetCode]
disableNunjucks: true
---

# 【LetMeFly】1096.花括号展开 II：一个一百行的解题方法（DFS）

力扣题目链接：[https://leetcode.cn/problems/brace-expansion-ii/](https://leetcode.cn/problems/brace-expansion-ii/)

<p>如果你熟悉 Shell 编程，那么一定了解过花括号展开，它可以用来生成任意字符串。</p>

<p>花括号展开的表达式可以看作一个由 <strong>花括号</strong>、<strong>逗号</strong> 和 <strong>小写英文字母</strong> 组成的字符串，定义下面几条语法规则：</p>

<ul>
	<li>如果只给出单一的元素&nbsp;<code>x</code>，那么表达式表示的字符串就只有&nbsp;<code>"x"</code>。<code>R(x) = {x}</code>

	<ul>
		<li>例如，表达式 <code>"a"</code> 表示字符串 <code>"a"</code>。</li>
		<li>而表达式 <code>"w"</code> 就表示字符串 <code>"w"</code>。</li>
	</ul>
	</li>
	<li>当两个或多个表达式并列，以逗号分隔，我们取这些表达式中元素的并集。<code>R({e_1,e_2,...}) = R(e_1)&nbsp;∪ R(e_2)&nbsp;∪ ...</code>
	<ul>
		<li>例如，表达式 <code>"{a,b,c}"</code> 表示字符串&nbsp;<code>"a","b","c"</code>。</li>
		<li>而表达式 <code>"{{a,b},{b,c}}"</code> 也可以表示字符串&nbsp;<code>"a","b","c"</code>。</li>
	</ul>
	</li>
	<li>要是两个或多个表达式相接，中间没有隔开时，我们从这些表达式中各取一个元素依次连接形成字符串。<code>R(e_1 + e_2) = {a + b for (a, b) in&nbsp;R(e_1)&nbsp;× R(e_2)}</code>
	<ul>
		<li>例如，表达式 <code>"{a,b}{c,d}"</code> 表示字符串&nbsp;<code>"ac","ad","bc","bd"</code>。</li>
	</ul>
	</li>
	<li>表达式之间允许嵌套，单一元素与表达式的连接也是允许的。
	<ul>
		<li>例如，表达式 <code>"a{b,c,d}"</code> 表示字符串&nbsp;<code>"ab","ac","ad"​​​​​​</code>。</li>
		<li>例如，表达式 <code>"a{b,c}{d,e}f{g,h}"</code> 可以表示字符串&nbsp;<code>"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"</code>。</li>
	</ul>
	</li>
</ul>

<p>给出表示基于给定语法规则的表达式&nbsp;<code>expression</code>，返回它所表示的所有字符串组成的有序列表。</p>

<p>假如你希望以「集合」的概念了解此题，也可以通过点击 “<strong>显示英文描述</strong>” 获取详情。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>expression = "{a,b}{c,{d,e}}"
<strong>输出：</strong>["ac","ad","ae","bc","bd","be"]</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>expression = "{{a,z},a{b,c},{ab,z}}"
<strong>输出：</strong>["a","ab","ac","z"]
<strong>解释：</strong>输出中 <strong>不应 </strong>出现重复的组合结果。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 60</code></li>
	<li><code>expression[i]</code> 由 <code>'{'</code>，<code>'}'</code>，<code>','</code>&nbsp;或小写英文字母组成</li>
	<li>给出的表达式&nbsp;<code>expression</code>&nbsp;用以表示一组基于题目描述中语法构造的字符串</li>
</ul>


    
## 解题方法：深度优先搜索

### 解题思路

这种题最容易想到的就是递归。怎么递归？

1. 如果最外层是加法运算，如 `<A,B,C>`，则返回 `dfs(A) + dfs(B) + dfs(C)`。例如：

    + `{a,b},c`：`dfs({a,b}) + dfs(c)`
    + `a,b,c`：`dfs(a) + dfs(b) + dfs(c)`
    + `a,{b,c}`：`dfs(a) + dfs({b,c})`
    + `{a,b{c}},{d,ef}`：`dfs({a,b{c}}) + dfs({d,ef})`

    仅限于最外层是加法的运算。

2. 否则（说明可能有两种情况，要么最外层是乘法运算，要么就只有一个“运算单元”）如果最外层是乘法运算，如`ABC`，则返回 `dfs(A) * dfs(B) * dfs(C)`。例如：

    + `{a,b}{c,d}`：`dfs({a,b}) * dfs({c,d})`
    + `a{b,c}`：`dfs(a) * dfs({b,c})`
    + `{a,b}c`：`dfs({a,b}) * dfs(c)`
    + `{a}b`：`dfs({a}) * dfs(b)`
    + `{a}`：`dfs({a})`。注意这种被大括号包括的特殊情况

3. 否则（说明只有一个单一的“运算单元”）。如果字符串第一个字符是`{`，则再次递归大括号中间的字符串；否则说明该字符串是不含`{`也不含`,`的单一字符串，直接返回该字符串。例如：

    + `{a}`：`dfs(a)`
    + `{a,bc}`：`dfs(a,bc)`
    + `a`：`a`。不再递归
    + `ab`：`ab`。不再递归

以上。

其实相当于递归终止条件是不含`{`也不含`,`的单一字符串。

### 解题细节

怎么判断最外层是否是加法运算？

> 使用一个变量`layer`记录当前的括号层数，初始值是`0`。遇到`{`则`layer++`，遇到`}`则`layer--`。当遇到`,`时，如果此时`layer==0`，说明这个`,`是最外层的加法运算符，视为最外层为加法运算。
> 
> 同时我们也可以返回所有最外层`,`的下标。

怎么判断最外层是否是乘法运算？

> （如果前面判断是否是加法运算时候返回了一个空数组，说明没有最外层的逗号，才会执行该判断最外层是否是乘法运算的算法）。
> 
> 同样使用一个变量`layer`记录当前的括号层数，初始值是`0`。遇到`{`则`layer++`，遇到`}`则`layer--`。当遇到一个字符时，如果此时`layer==0`，并且该字符的前一个字符是`}`或者该字符是`{`，说明不只有一个“运算单元”，视为最外层为乘法运算。
> 
> 同时我们也可以返回所有（除了起始下标`0`外的）最外层“运算单元”起始位置的下标，例如`{a,b}{c,d}e`相当于三个运算单元`{a,b}`、`{c,d}`和`e`相乘，返回下标`[5, 10]`。

如果返回下标为空数组，说明只有一个“运算单元”，依据第一个字符是否为`{`来决定是否需要继续递归；否则说明该字符串总体上是不只一个运算单元的相乘，递归每个运算单元并相乘。

### 时空复杂度(我不会算)

+ 时间复杂度$O(unknown)$
+ 空间复杂度$O(unknown)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-26 11:31:38
 */
// struct Res : unordered_set<string> {
//     Res() : unordered_set<string>{""} {}
// };
typedef unordered_set<string> Res;

Res operator* (const Res& a, const Res& b) {
    Res res;
    for (const string& s1 : a) {
        for (const string& s2 : b) {
            res.insert(s1 + s2);
        }
    }
    return res;
}

Res operator+= (Res& a, const Res& b) {
    a.insert(b.begin(), b.end());
    return a;
}

typedef vector<int> Idx;

class Solution {
private:
    // 最外层是加法运算
    Idx getAdd(string_view s) {
        Idx idxs;
        int layer = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (s[i] == '{') {
                layer++;
            } else if (s[i] == '}') {
                layer--;
            } else if (s[i] == ',' && !layer) {
                idxs.push_back(i);
            }
        }
        return idxs;
    }

    Idx getMul(string_view s) {
        Idx idxs;
        int layer = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (!layer && i && (s[i - 1] == '}' || s[i] == '{')) {
                idxs.push_back(i);
            }
            if (s[i] == '{') {
                layer++;
            } else if (s[i] == '}') {
                layer--;
            }
        }
        return idxs;
    }

    Res dfs(string_view s) {
        Res res;
        Idx idxs = getAdd(s);
        if (idxs.size()) {  // 最外层是加法运算
            idxs.push_back(s.size());
            int last_idx = -1;
            for (int idx : idxs) {
                res += dfs(s.substr(last_idx + 1, idx - last_idx - 1));
                last_idx = idx;
            }
            return res;
        }
        // 最外层是乘法运算(或单个字符串)
        idxs = getMul(s);
        if (idxs.empty() && s.size() && s[0] != '{') {  // 没有括号，那就是单个字符串
            res.insert(string(s));
            return res;
        }
        if (idxs.empty()) {  // 只有最外层一个大括号，如 {a,b}
            return dfs(s.substr(1, s.size() - 2));
        }
        idxs.push_back(s.size());
        int last_idx = 0;
        res.insert("");
        for (int idx : idxs) {
            res = res * dfs(s.substr(last_idx, idx - last_idx));
            last_idx = idx;
        }
        return res;
    }
public:
    vector<string> braceExpansionII(string expression) {
        Res res = dfs(expression);
        vector<string> ans(res.begin(), res.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
c{a{b}}d
{{a,z},a{b,c},{ab,z}}
{ab,c}{d},{e}
a{b,c}
{a,b}c
{a}b
{a}
d,a{b,c}
*/

#ifdef _DEBUG
int main() {
    string s;
    while (cin >> s) {
        Solution sol;
        debug(sol.braceExpansionII(s));
    }
    return 0;
}
#endif
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/166688927)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/25/LeetCode%201096.%E8%8A%B1%E6%8B%AC%E5%8F%B7%E5%B1%95%E5%BC%80II/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
