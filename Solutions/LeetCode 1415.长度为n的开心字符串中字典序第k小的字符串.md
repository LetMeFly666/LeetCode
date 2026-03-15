---
title: 1415.长度为 n 的开心字符串中字典序第 k 小的字符串：DFS构造 / 数学O(n)
date: 2026-03-14 23:31:04
tags: [题解, LeetCode, 中等, 字符串, 回溯, 深度优先搜索, DFS, 模拟, 数学, 构造]
categories: [题解, LeetCode]
---

# 【LetMeFly】1415.长度为 n 的开心字符串中字典序第 k 小的字符串：DFS构造 / 数学O(n)

力扣题目链接：[https://leetcode.cn/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/](https://leetcode.cn/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

<p>一个 「开心字符串」定义为：</p>

<ul>
	<li>仅包含小写字母&nbsp;<code>[&#39;a&#39;, &#39;b&#39;, &#39;c&#39;]</code>.</li>
	<li>对所有在&nbsp;<code>1</code>&nbsp;到&nbsp;<code>s.length - 1</code>&nbsp;之间的&nbsp;<code>i</code>&nbsp;，满足&nbsp;<code>s[i] != s[i + 1]</code>&nbsp;（字符串的下标从 1 开始）。</li>
</ul>

<p>比方说，字符串&nbsp;<strong>&quot;abc&quot;</strong>，<strong>&quot;ac&quot;，&quot;b&quot;</strong> 和&nbsp;<strong>&quot;abcbabcbcb&quot;</strong>&nbsp;都是开心字符串，但是&nbsp;<strong>&quot;aa&quot;</strong>，<strong>&quot;baa&quot;</strong>&nbsp;和&nbsp;<strong>&quot;ababbc&quot;</strong>&nbsp;都不是开心字符串。</p>

<p>给你两个整数 <code>n</code>&nbsp;和 <code>k</code>&nbsp;，你需要将长度为 <code>n</code>&nbsp;的所有开心字符串按字典序排序。</p>

<p>请你返回排序后的第 k 个开心字符串，如果长度为 <code>n</code>&nbsp;的开心字符串少于 <code>k</code>&nbsp;个，那么请你返回 <strong>空字符串</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 3
<strong>输出：</strong>&quot;c&quot;
<strong>解释：</strong>列表 [&quot;a&quot;, &quot;b&quot;, &quot;c&quot;] 包含了所有长度为 1 的开心字符串。按照字典序排序后第三个字符串为 &quot;c&quot; 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 1, k = 4
<strong>输出：</strong>&quot;&quot;
<strong>解释：</strong>长度为 1 的开心字符串只有 3 个。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 3, k = 9
<strong>输出：</strong>&quot;cab&quot;
<strong>解释：</strong>长度为 3 的开心字符串总共有 12 个 [&quot;aba&quot;, &quot;abc&quot;, &quot;aca&quot;, &quot;acb&quot;, &quot;bab&quot;, &quot;bac&quot;, &quot;bca&quot;, &quot;bcb&quot;, &quot;cab&quot;, &quot;cac&quot;, &quot;cba&quot;, &quot;cbc&quot;] 。第 9 个字符串为 &quot;cab&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 2, k = 7
<strong>输出：</strong>&quot;&quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 10, k = 100
<strong>输出：</strong>&quot;abacbabacb&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>


    
## 解题方法一：DFS构造

写一个`dfs`函数接收已经构造的字符串并继续构造字符串：

+ 如果之前字符串已经长度为`n`了，就看看这是不是第`k`次长度为`n`。如果是，则说明找到了答案；否则，不继续向后追加字符串，结束这层递归在其他层递归继续寻找答案。
+ 否则，尝试把`abc`中每个和上一个字符(如有)不同的字符拼接到字符串上并递归。

特别的，我们可以控制这个函数的返回值，返回`true`代表已经找到了最终答案，可以不再进行后续递归。

+ 时间复杂度$O(nk)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-14 23:29:38
 */
class Solution {
private:
    int n, k;
    string ans;
    char can[3] = {'a', 'b', 'c'};

    // dfs and return if can stop
    bool dfs() {
        if (ans.size() == n) {
            k--;
            if (!k) {
                return true;
            }
            return false;
        }

        char last = ans.empty() ? '0' : ans.back();
        for (int i = 0; i < 3; i++) {
            if (can[i] == last) {
                continue;
            }
            ans += can[i];
            if (dfs()) {
                return true;
            }
            ans.pop_back();
        }
        return false;
    }
public:
    string getHappyString(int n, int k) {
        this->n = n, this->k = k;
        dfs();
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
1 3

c
*/
int main() {
    int a, b;
    while (cin >> a >> b) {
        Solution sol;
        cout << sol.getHappyString(a, b) << endl;
    }
    return 0;
}
#endif
```

## 解题方法二：数学直接找

长度为$n$的字符串一共有多少种开心字符串呢？

> 第一个字符有$3$种选择，后续每个字符有$2$种选择，共计$3\times2^{n-1}$种。
>
> 如果$k\gt 3\times2^{n-1}$则答案不存在，返回空串。

第$k$个开心字符串的每一位分别应该对应哪个字符呢？很简单，我们只需要计算下这个字符后面字符串有多少种。

举个例子：

+ 假设后面字符串有$2^2$共4种，而当前$k=3\leq 4$，那么当前字符选哪个？当然选能选的字符中第一个就够了；
+ 假设后面字符串有$2^2$共4种，而当前$k=5\lt 4$，那么当前字符选哪个？当然选能选的字符中第二个，因为选第一个的话后面最多$4$种情况，到不了$k=5$。

> PS: 上面的“能选的字符”指的是属于`abc`且和前一个字符不同的字符。

选完这个字符后，令$k$对剩余种类数取模，并更新剩余字符的种类数。

为什么取模呢？

+ 仍然假设后面字符串有$2^2$共4种，而当前$k=5\lt 4$，假设当前可选字符为`ab`，那么相当于当前选`a`时候后面共有$4$个开心字符串，后面选完了当前字符**确定**选`b`了，后面还需要$5\%4=1$个开心字符串，使得总开心字符串数是当前$k=5$个。

我们也可以将$k-1$以便后面的取模整除运算。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-14 23:21:37
 */
class Solution {
public:
    string getHappyString(int n, int k) {
        int remain = 1 << (n - 1);
        if (k > 3 * remain) {
            return "";
        }
        
        k--;
        char toChoose[3] = {'a', 'b', 'c'};
        string ans;
        ans.push_back(toChoose[k / remain]);
        for (int i = 1; i < n; i++) {
            k %= remain;
            remain >>= 1;
            int th = k / remain;
            if (toChoose[th] >= ans.back()) {
                th++;
            }
            ans.push_back(toChoose[th]);
        }
        return ans;
    }
};
```

感觉描述得还不错哈哈。

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159055459)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/14/LeetCode%201415.%E9%95%BF%E5%BA%A6%E4%B8%BAn%E7%9A%84%E5%BC%80%E5%BF%83%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E5%AD%97%E5%85%B8%E5%BA%8F%E7%AC%ACk%E5%B0%8F%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
