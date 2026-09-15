---
title: 2472.不重叠回文子字符串的最大数目：动态规划（贪心）
date: 2026-09-15 17:39:07
tags: [题解, LeetCode, 困难, 贪心, 双指针, 字符串, 动态规划, DP, 回文, 回文串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2472.不重叠回文子字符串的最大数目：动态规划（贪心）

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/](https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

<p>给你一个字符串 <code>s</code> 和一个 <strong>正</strong> 整数 <code>k</code> 。</p>

<p>从字符串 <code>s</code> 中选出一组满足下述条件且 <strong>不重叠</strong> 的子字符串：</p>

<ul>
	<li>每个子字符串的长度 <strong>至少</strong> 为 <code>k</code> 。</li>
	<li>每个子字符串是一个 <strong>回文串</strong> 。</li>
</ul>

<p>返回最优方案中能选择的子字符串的 <strong>最大</strong> 数目。</p>

<p><strong>子字符串</strong> 是字符串中一个连续的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre>
<strong>输入：</strong>s = "abaccdbbd", k = 3
<strong>输出：</strong>2
<strong>解释：</strong>可以选择 s = "<em><strong>aba</strong></em>cc<em><strong>dbbd</strong></em>" 中斜体加粗的子字符串。"aba" 和 "dbbd" 都是回文，且长度至少为 k = 3 。
可以证明，无法选出两个以上的有效子字符串。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>s = "adbcda", k = 2
<strong>输出：</strong>0
<strong>解释：</strong>字符串中不存在长度至少为 2 的回文子字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>


    
## 解题方法：动态规划

创建一个动态规划数组`f`，其中`f[i]`表示前`i`个字符中能选择的k回文子字符串的最大数目。

那么显然，对于`f[i]`，我们有两种选择：

1. 不选择以`s[i-1]`结尾的回文子字符串，那么`f[i] = f[i-1]`。
2. 选择以`s[i-1]`结尾的回文子字符串，那么我们需要找到一个长度至少为`k`的回文子字符串`[j, i)`，那么`f[i] = f[j] + 1`。

对于第二种情况，我们有必要从$k$、$k+1$、$k+2$、...、$i$都试试吗？没有。最多试一下$k$和$k+1$保证奇数长度和偶数长度两种情况都考虑过就好了。

因为站在整体角度，如果存在$k+2$长的回文串的话，$k$长度也一定是回文串，没必要选$k+2$长。所以我们只需要考虑长度为$k$和$k+1$的回文串。

+ 时间复杂度$O(nk)$，其中$n=len(s)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-15 17:07:03
 */
class Solution {
private:
    bool ok(string& s, int l, int r) {  // [l, r)
        // len->i: 3->1 4->2 5->2 6->3
        for (int i = 0; i < (r - l) / 2; i++) {
            if (s[l + i] != s[r - i - 1]) {
                return false;
            }
        }
        return true;
    }
public:
    int maxPalindromes(string& s, int k) {
        int n = s.size();
        vector<int> f(n + 1);
        for (int i = k; i <= n; i++) {
            f[i] = f[i - 1];
            if (ok(s, i - k, i)) {
                f[i] = max(f[i], f[i - k] + 1);
            }
            if (i != k && ok(s, i - k - 1, i)) {
                f[i] = max(f[i], f[i - k - 1] + 1);
            }
        }
        return f.back();
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/165486525)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/15/LeetCode%202472.%E4%B8%8D%E9%87%8D%E5%8F%A0%E5%9B%9E%E6%96%87%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
