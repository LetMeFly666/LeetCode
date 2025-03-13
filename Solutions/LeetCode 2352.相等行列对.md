---
title: 2352.相等行列对：手动哈希
date: 2023-06-06 10:17:07
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, map, 手动哈希, 矩阵, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2352.相等行列对：手动哈希

力扣题目链接：[https://leetcode.cn/problems/equal-row-and-column-pairs/](https://leetcode.cn/problems/equal-row-and-column-pairs/)

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>n x n</code> 的整数矩阵 <code>grid</code> ，返回满足 <code>R<sub>i</sub></code><em> </em>行和<em> </em><code>C<sub>j</sub></code><em> </em>列相等的行列对<em> </em><code>(R<sub>i</sub>, C<sub>j</sub>)</code><em> </em>的数目<em>。</em></p>

<p>如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/06/01/ex1.jpg" style="width: 150px; height: 153px;" /></p>

<pre>
<strong>输入：</strong>grid = [[3,2,1],[1,7,6],[2,7,7]]
<strong>输出：</strong>1
<strong>解释：</strong>存在一对相等行列对：
- (第 2 行，第 1 列)：[2,7,7]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/06/01/ex2.jpg" style="width: 200px; height: 209px;" /></p>

<pre>
<strong>输入：</strong>grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
<strong>输出：</strong>3
<strong>解释：</strong>存在三对相等行列对：
- (第 0 行，第 0 列)：[3,1,2,2]
- (第 2 行, 第 2 列)：[2,4,2,2]
- (第 3 行, 第 2 列)：[2,4,2,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：手动哈希

将每一行映射成一个数并用哈希表存下，将每一列以同样的规则映射成一个数，看行列有多少相等的数即可。

怎么将一行或一列映射成一个数呢？

我们可以使用手动取模的方式，具体原理可以参考[哈希讲解](https://letmefly.blog.csdn.net/article/details/116560539)

方法很简单，使用公式$hash_ = hash_ * 131 + a[i]$即可

+ 时间复杂度$O(n^2)$，其中$grid$的$size$为$n\times n$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
typedef unsigned long long ull;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<ull, int> ma;
        for (int i = 0; i < n; i++) {
            ull hash_ = 0;
            for (int j = 0; j < n; j++) {
                hash_ = hash_ * 131 + grid[i][j];
            }
            ma[hash_]++;
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            ull hash_ = 0;
            for (int i = 0; i < n; i++) {
                hash_ = hash_ * 131 + grid[i][j];
            }
            ans += ma[hash_];
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/06/LeetCode%202352.%E7%9B%B8%E7%AD%89%E8%A1%8C%E5%88%97%E5%AF%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131062292](https://letmefly.blog.csdn.net/article/details/131062292)
