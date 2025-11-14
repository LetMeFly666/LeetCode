---
title: 2536.子矩阵元素加 1：二维差分数组
date: 2025-11-14 19:17:41
tags: [题解, LeetCode, 中等, 数组, 矩阵, 前缀和, 差分数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】2536.子矩阵元素加 1：二维差分数组

力扣题目链接：[https://leetcode.cn/problems/increment-submatrices-by-one/](https://leetcode.cn/problems/increment-submatrices-by-one/)

<p>给你一个正整数 <code>n</code> ，表示最初有一个 <code>n x n</code> 、下标从 <strong>0</strong> 开始的整数矩阵 <code>mat</code> ，矩阵中填满了 0 。</p>

<p>另给你一个二维整数数组 <code>query</code> 。针对每个查询 <code>query[i] = [row1<sub>i</sub>, col1<sub>i</sub>, row2<sub>i</sub>, col2<sub>i</sub>]</code> ，请你执行下述操作：</p>

<ul>
	<li>找出 <strong>左上角</strong> 为 <code>(row1<sub>i</sub>, col1<sub>i</sub>)</code> 且 <strong>右下角</strong> 为 <code>(row2<sub>i</sub>, col2<sub>i</sub>)</code> 的子矩阵，将子矩阵中的 <strong>每个元素</strong> 加 <code>1</code> 。也就是给所有满足 <code>row1<sub>i</sub> &lt;= x &lt;= row2<sub>i</sub></code> 和 <code>col1<sub>i</sub> &lt;= y &lt;= col2<sub>i</sub></code> 的 <code>mat[x][y]</code> 加 <code>1</code> 。</li>
</ul>

<p>返回执行完所有操作后得到的矩阵 <code>mat</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/11/24/p2example11.png" style="width: 531px; height: 121px;" /></p>

<pre>
<strong>输入：</strong>n = 3, queries = [[1,1,2,2],[0,0,1,1]]
<strong>输出：</strong>[[1,1,0],[1,2,1],[0,1,1]]
<strong>解释：</strong>上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵、执行完第二个操作后的矩阵。
- 第一个操作：将左上角为 (1, 1) 且右下角为 (2, 2) 的子矩阵中的每个元素加 1 。 
- 第二个操作：将左上角为 (0, 0) 且右下角为 (1, 1) 的子矩阵中的每个元素加 1 。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/11/24/p2example22.png" style="width: 261px; height: 82px;" /></p>

<pre>
<strong>输入：</strong>n = 2, queries = [[0,0,1,1]]
<strong>输出：</strong>[[1,1],[1,1]]
<strong>解释：</strong>上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵。 
- 第一个操作：将矩阵中的每个元素加 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= row1<sub>i</sub> &lt;= row2<sub>i</sub> &lt; n</code></li>
	<li><code>0 &lt;= col1<sub>i</sub> &lt;= col2<sub>i</sub> &lt; n</code></li>
</ul>

Long time no see. 

## 解题方法：二维差分数组

使用二维差分数组`diff`，其中令`diff[i][j]`表示原数组`mat[i][j]`到`mat[n-1][n-1]`每个元素变化值。

例如将`mat[x1][y1]`到`mat[x2][y2]`每个元素值加一，反映到差分数组上就表现为：

1. $diff[x1][y1] += 1$，先从`mat[x1][y1]`到`mat[n-1][n-1]`每个元素都加一
2. $diff[x2+1][y1] -= 1$，由于从`mat[x2+1][y1]`到`mat[n-1][n-1]`每个元素无需改变，第一步加的范围太大了，不该变的撤销变化
3. $diff[x1][y2+1] -= 1$，与2同理，由于从`mat[x1][y2+1]`到`mat[n-1][n-1]`每个元素无需改变，第一步加的范围太大了，不该变的撤销变化
4. $diff[x2+1][y2+1] += 1$，由于第二步和第三步都包含范围`mat[x2+1][y2+1]`，所以这块“重复撤销”了，再加回来

对于每个query，以$O(1)$的时间复杂度可以计算出diff数组的变化。最终处理完所有query，再由diff差分数组反推出原数组mat就好了。

二维数组思考困难的话可以以一位数组为例，一位差分数组的前缀和数组就是原始数组，二维数组也是如此。只需要对diff数组求前缀和，就能得到原始mat数组了。

前缀和`prefix[i][j]`代表从`diff[0][0]`到`diff[i][j]`的所有元素之和。求前缀和的过程可以由左上到右下的顺序求得。

和求差分数组过程类似，$prefix[i][j] = diff[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]$。

解释为：从`diff[0][0]`到`diff[i][j]`的所有元素之和 $=$ 从`diff[0][0]`到`diff[i-1][j]`的所有元素之和 $+$ 从`diff[0][0]`到`diff[i][j-]`的所有元素之和 $-$ 从`diff[0][0]`到`diff[i-1][j-1]`的所有元素之和（算重了）。

+ 时间复杂度$O(n^2+len(queries))$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-11-14 18:07:20
 */
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1));
        for (vector<int>& q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            diff[x1][y1]++;
            diff[x2 + 1][y1]--;
            diff[x1][y2 + 1]--;
            diff[x2 + 1][y2 + 1]++;
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = diff[i][j] 
                            + (i == 0 ? 0 : ans[i - 1][j])
                            + (j == 0 ? 0 : ans[i][j - 1])
                            - ((i == 0 || j == 0) ? 0 : ans[i - 1][j - 1]);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-11-14 17:51:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-11-14 19:16:40
'''
from typing import List

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        diff = [[0] * (n + 1) for _ in range(n + 1)]
        for x1, y1, x2, y2 in queries:
            diff[x1][y1] += 1
            diff[x2 + 1][y1] -= 1
            diff[x1][y2 + 1] -= 1
            diff[x2 + 1][y2 + 1] += 1
        ans = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                ans[i][j] = diff[i][j] + \
                            (0 if not i else ans[i - 1][j]) + \
                            (0 if not j else ans[i][j - 1]) - \
                            (0 if not i or not j else ans[i - 1][j - 1])
        return ans
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/11/14/LeetCode%202536.%E5%AD%90%E7%9F%A9%E9%98%B5%E5%85%83%E7%B4%A0%E5%8A%A01/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
