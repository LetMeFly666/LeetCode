---
title: 3546.等和矩阵分割 I：记总记当前（遍历）
date: 2026-03-25 22:08:15
tags: [题解, LeetCode, 中等, 数组, 枚举, 矩阵, 前缀和, 遍历]
categories: [题解, LeetCode]
index_img: https://pic.leetcode.cn/1746839596-kWigaF-lc.jpeg
---

# 【LetMeFly】3546.等和矩阵分割 I：记总记当前（遍历）

力扣题目链接：[https://leetcode.cn/problems/equal-sum-grid-partition-i/](https://leetcode.cn/problems/equal-sum-grid-partition-i/)

<p>给你一个由正整数组成的 <code>m x n</code> 矩阵 <code>grid</code>。你的任务是判断是否可以通过&nbsp;<strong>一条水平或一条垂直分割线&nbsp;</strong>将矩阵分割成两部分，使得：</p>

<ul>
	<li>分割后形成的每个部分都是&nbsp;<strong>非空&nbsp;</strong>的。</li>
	<li>两个部分中所有元素的和&nbsp;<strong>相等&nbsp;</strong>。</li>
</ul>

<p>如果存在这样的分割，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> grid = [[1,4],[2,3]]</p>

<p><strong>输出：</strong> true</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://pic.leetcode.cn/1746839596-kWigaF-lc.jpeg" style="height: 200px; width: 200px;" /></p>

<p>在第 0 行和第 1 行之间进行水平分割，得到两个非空部分，每部分的元素之和为 5。因此，答案是 <code>true</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> grid = [[1,3],[2,4]]</p>

<p><strong>输出：</strong> false</p>

<p><strong>解释：</strong></p>

<p>无论是水平分割还是垂直分割，都无法使两个非空部分的元素之和相等。因此，答案是 <code>false</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m == grid.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= n == grid[i].length &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>


    
## 解题方法：三次遍历

第一次遍历计算整个grid的元素之和，若非偶数直接返回`false`，若为偶数则直接除以$2$。

接着从上往下遍历grid，每次累加一整行的元素，若恰好等于除以二后的总和则返回true，大于则break。

最后从左往右遍历，方法和从上往下遍历同理。

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-25 22:05:04
 */
#define CHECK_AND_BREAK(now, sum) \
    if ((now) == (sum)) {         \
        return true;              \
    }                             \
    if ((now) > (sum)) {          \
        break;                    \
    }
typedef long long ll;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll sum = 0;
        for (vector<int>& row : grid) {
            for (int& v : row) {
                sum += v;
            }
        }
        if (sum % 2) {
            return false;
        }
        sum /= 2;

        ll now = 0;
        for (vector<int>& row : grid) {
            for (int& v : row) {
                now += v;
            }
            CHECK_AND_BREAK(now, sum)
        }

        now = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size(); i++) {
                now += grid[i][j];
            }
            CHECK_AND_BREAK(now, sum)
        }

        return false;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/159476515)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/25/LeetCode%203546.%E7%AD%89%E5%92%8C%E7%9F%A9%E9%98%B5%E5%88%86%E5%89%B2I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
