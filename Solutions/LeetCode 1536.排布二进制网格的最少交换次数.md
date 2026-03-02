---
title: 1536.排布二进制网格的最少交换次数：后缀0（贪心）
date: 2026-03-02 09:33:13
tags: [题解, LeetCode, 中等, 贪心, 数组, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】1536.排布二进制网格的最少交换次数：后缀0（贪心）

力扣题目链接：[https://leetcode.cn/problems/minimum-swaps-to-arrange-a-binary-grid/](https://leetcode.cn/problems/minimum-swaps-to-arrange-a-binary-grid/)

<p>给你一个&nbsp;<code>n&nbsp;x n</code>&nbsp;的二进制网格&nbsp;<code>grid</code>，每一次操作中，你可以选择网格的&nbsp;<strong>相邻两行</strong>&nbsp;进行交换。</p>

<p>一个符合要求的网格需要满足主对角线以上的格子全部都是 <strong>0</strong>&nbsp;。</p>

<p>请你返回使网格满足要求的最少操作次数，如果无法使网格符合要求，请你返回 <strong>-1</strong>&nbsp;。</p>

<p>主对角线指的是从&nbsp;<code>(1, 1)</code>&nbsp;到&nbsp;<code>(n, n)</code>&nbsp;的这些格子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/08/02/fw.jpg" style="height: 141px; width: 750px;"></p>

<pre><strong>输入：</strong>grid = [[0,0,1],[1,1,0],[1,0,0]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/08/02/e2.jpg" style="height: 270px; width: 270px;"></p>

<pre><strong>输入：</strong>grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
<strong>输出：</strong>-1
<strong>解释：</strong>所有行都是一样的，交换相邻行无法使网格符合要求。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/08/02/e3.jpg" style="height: 210px; width: 210px;"></p>

<pre><strong>输入：</strong>grid = [[1,0,0],[1,1,0],[1,1,1]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 200</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code>&nbsp;。</li>
</ul>


    
## 解题方法：贪心

其实我们只需要关注每一行最后有多少个连续的$0$。

> 我们可以使用一个数组，遍历一次`grid`，把后缀$0$的信息存入`suffix`数组中。然后$grid$就可以扔掉了。

从第一行开始遍历到最后一行，遍历到第$i$行时，这一行至少有$n-i-1$个后缀0，就用$j$从第$i$行往下遍历，找到第一个满足条件的行，一行一行的置换上来。

问：第$i$行太多后缀0会不会浪费？

答：不会。因为后面行的需求只会越来越小。

相当于每一行都要尽可能少的次数来满足达成后缀条件。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-02 09:32:18
 */
class Solution {
private:
    inline int countSuffix(vector<int>& row) {
        int ans = 0;
        for (int i = row.size() - 1; i >= 0; i--, ans++) {
            if (row[i] != 0) {
                break;
            }
        }
        return ans;
    }

    int change(vector<int>& suffix, int u, int d) {
        for (int i = d - 1; i >= u; i--) {
            swap(suffix[i], suffix[i + 1]);
        }
        return d - u;
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> suffix(n);
        for (int i = 0; i < n; i++) {
            suffix[i] = countSuffix(grid[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (suffix[j] >= n - i - 1) {
                    ans += change(suffix, i, j);
                    goto loop;
                }
            }
            return -1;
            loop:;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158569710)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/02/LeetCode%201536.%E6%8E%92%E5%B8%83%E4%BA%8C%E8%BF%9B%E5%88%B6%E7%BD%91%E6%A0%BC%E7%9A%84%E6%9C%80%E5%B0%91%E4%BA%A4%E6%8D%A2%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
