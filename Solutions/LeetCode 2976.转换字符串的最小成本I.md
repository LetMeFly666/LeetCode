---
title: 2976.转换字符串的最小成本 I：floyd算法(全源最短路)
date: 2026-01-31 12:57:34
tags: [题解, LeetCode, 中等, 图, floyd, 数组, 字符串, 最短路]
categories: [题解, LeetCode]
---

# 【LetMeFly】2976.转换字符串的最小成本 I：floyd算法(全源最短路)

力扣题目链接：[https://leetcode.cn/problems/minimum-cost-to-convert-string-i/](https://leetcode.cn/problems/minimum-cost-to-convert-string-i/)

<p>给你两个下标从 <strong>0</strong> 开始的字符串 <code>source</code> 和 <code>target</code> ，它们的长度均为 <code>n</code> 并且由 <strong>小写 </strong>英文字母组成。</p>

<p>另给你两个下标从 <strong>0</strong> 开始的字符数组 <code>original</code> 和 <code>changed</code> ，以及一个整数数组 <code>cost</code> ，其中 <code>cost[i]</code> 代表将字符 <code>original[i]</code> 更改为字符 <code>changed[i]</code> 的成本。</p>

<p>你从字符串 <code>source</code> 开始。在一次操作中，<strong>如果 </strong>存在 <strong>任意</strong> 下标 <code>j</code> 满足 <code>cost[j] == z</code>&nbsp; 、<code>original[j] == x</code> 以及 <code>changed[j] == y</code> 。你就可以选择字符串中的一个字符 <code>x</code> 并以 <code>z</code> 的成本将其更改为字符 <code>y</code> 。</p>

<p>返回将字符串 <code>source</code> 转换为字符串 <code>target</code> 所需的<strong> 最小 </strong>成本。如果不可能完成转换，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong>，可能存在下标 <code>i</code> 、<code>j</code> 使得 <code>original[j] == original[i]</code> 且 <code>changed[j] == changed[i]</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
<strong>输出：</strong>28
<strong>解释：</strong>将字符串 "abcd" 转换为字符串 "acbe" ：
- 更改下标 1 处的值 'b' 为 'c' ，成本为 5 。
- 更改下标 2 处的值 'c' 为 'e' ，成本为 1 。
- 更改下标 2 处的值 'e' 为 'b' ，成本为 2 。
- 更改下标 3 处的值 'd' 为 'e' ，成本为 20 。
产生的总成本是 5 + 1 + 2 + 20 = 28 。
可以证明这是可能的最小成本。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
<strong>输出：</strong>12
<strong>解释：</strong>要将字符 'a' 更改为 'b'：
- 将字符 'a' 更改为 'c'，成本为 1 
- 将字符 'c' 更改为 'b'，成本为 2 
产生的总成本是 1 + 2 = 3。
将所有 'a' 更改为 'b'，产生的总成本是 3 * 4 = 12 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
<strong>输出：</strong>-1
<strong>解释：</strong>无法将 source 字符串转换为 target 字符串，因为下标 3 处的值无法从 'd' 更改为 'e' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= source.length == target.length &lt;= 10<sup>5</sup></code></li>
	<li><code>source</code>、<code>target</code> 均由小写英文字母组成</li>
	<li><code>1 &lt;= cost.length== original.length == changed.length &lt;= 2000</code></li>
	<li><code>original[i]</code>、<code>changed[i]</code> 是小写英文字母</li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>original[i] != changed[i]</code></li>
</ul>


    
## 解题方法：floyd算法

如何将`source`字符串变为`target`字符串？必须一个字符一个字符地通过`cost[i]`的代价将`original[i]`变为`changed[i]`来实现。

不难发现`source`中每个字符是独立的，b

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2026-01-31 12:12:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-31 12:22:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll floyd[26][26];
        memset(floyd, 0x3f, sizeof(floyd));
        for (int i = 0; i < 26; i++) {
            floyd[i][i] = 0;
        }
        for (int i = 0; i < original.size(); i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            floyd[x][y] = min(floyd[x][y], (ll)cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
                }
            }
        }
        
        ll ans = 0;
        for (int i = 0; i < source.size(); i++) {
            ll cost = floyd[source[i] - 'a'][target[i] - 'a'];
            if (cost > 1000000000000) {
                return -1;
            }
            ans += cost;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/31/LeetCode%202976.%E8%BD%AC%E6%8D%A2%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%8F%E6%88%90%E6%9C%ACI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
