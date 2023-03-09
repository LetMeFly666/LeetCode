---
title: 2379.得到 K 个黑块的最少涂色次数
date: 2023-03-09 09:11:20
tags: [题解, LeetCode, 简单, 字符串, 滑动窗口]
---

# 【LetMeFly】2379.得到 K 个黑块的最少涂色次数

力扣题目链接：[https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/](https://leetcode.cn/problems/minimum-recolors-to-get-k-consecutive-black-blocks/)

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>blocks</code>&nbsp;，<code>blocks[i]</code>&nbsp;要么是&nbsp;<code>'W'</code>&nbsp;要么是&nbsp;<code>'B'</code>&nbsp;，表示第&nbsp;<code>i</code>&nbsp;块的颜色。字符&nbsp;<code>'W'</code> 和&nbsp;<code>'B'</code>&nbsp;分别表示白色和黑色。</p>

<p>给你一个整数&nbsp;<code>k</code>&nbsp;，表示想要&nbsp;<strong>连续</strong>&nbsp;黑色块的数目。</p>

<p>每一次操作中，你可以选择一个白色块将它 <strong>涂成</strong>&nbsp;黑色块。</p>

<p>请你返回至少出现 <strong>一次</strong>&nbsp;连续 <code>k</code>&nbsp;个黑色块的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>blocks = "WBBWWBBWBW", k = 7
<b>输出：</b>3
<strong>解释：</strong>
一种得到 7 个连续黑色块的方法是把第 0 ，3 和 4 个块涂成黑色。
得到 blocks = "BBBBBBBWBW" 。
可以证明无法用少于 3 次操作得到 7 个连续的黑块。
所以我们返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>blocks = "WBWBBBW", k = 2
<b>输出：</b>0
<strong>解释：</strong>
不需要任何操作，因为已经有 2 个连续的黑块。
所以我们返回 0 。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>n == blocks.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>blocks[i]</code>&nbsp;要么是&nbsp;<code>'W'</code>&nbsp;，要么是&nbsp;<code>'B'</code> 。</li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


    
## 方法一：滑动窗口

首先统计字符串前$k$个字符中有多少个```'W'```

之后从第$k + 1$个字符开始遍历到字符串末尾，遍历过程中，逐渐加上新遇到的```'W'```，减去“k”个字符以外的```'W'```，更新答案的最小值即可。

+ 时间复杂度$O(len(blocks))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumRecolors(string& blocks, int k) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += blocks[i] == 'W';
        }
        int ans = cnt;
        for (int i = k; i < blocks.size(); i++) {
            cnt += blocks[i] == 'W';
            cnt -= blocks[i - k] == 'W';
            ans = min(ans, cnt);
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        cnt = 0
        for i in range(k):
            cnt += blocks[i] == 'W'
        ans = cnt
        for i in range(k, len(blocks)):
            cnt += blocks[i] == 'W'
            cnt -= blocks[i - k] == 'W'
            ans = min(ans, cnt)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/09/LeetCode%202379.%E5%BE%97%E5%88%B0K%E4%B8%AA%E9%BB%91%E5%9D%97%E7%9A%84%E6%9C%80%E5%B0%91%E6%B6%82%E8%89%B2%E6%AC%A1%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129416090](https://letmefly.blog.csdn.net/article/details/129416090)
