---
title: 2965.找出缺失和重复的数字
date: 2024-05-31 16:37:37
tags: [题解, LeetCode, 简单, 数组, 哈希表, 数学, 矩阵, 计数, 位运算, XOR]
categories: [题解, LeetCode]
---

# 【LetMeFly】2965.找出缺失和重复的数字：小数据？我选择暴力（附优化方法清单：O(1)空间方法×3）

力扣题目链接：[https://leetcode.cn/problems/find-missing-and-repeated-values/](https://leetcode.cn/problems/find-missing-and-repeated-values/)

<p>给你一个下标从<strong> 0 </strong>开始的二维整数矩阵 <code><font face="monospace">grid</font></code>，大小为 <code>n * n</code> ，其中的值在 <code>[1, n<sup>2</sup>]</code> 范围内。除了 <code>a</code> 出现 <strong>两次</strong>，<code>b</code> <strong>缺失</strong> 之外，每个整数都<strong> 恰好出现一次</strong> 。</p>

<p>任务是找出重复的数字<code>a</code> 和缺失的数字 <code>b</code> 。</p>

<p>返回一个下标从 0 开始、长度为 <code>2</code> 的整数数组 <code>ans</code> ，其中 <code>ans[0]</code> 等于 <code>a</code> ，<code>ans[1]</code> 等于 <code>b</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,3],[2,2]]
<strong>输出：</strong>[2,4]
<strong>解释：</strong>数字 2 重复，数字 4 缺失，所以答案是 [2,4] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[9,1,7],[8,9,2],[3,4,6]]
<strong>输出：</strong>[9,5]
<strong>解释：</strong>数字 9 重复，数字 5 缺失，所以答案是 [9,5] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == grid.length == grid[i].length &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= n * n</code></li>
	<li>对于所有满足<code>1 &lt;= x &lt;= n * n</code> 的 <code>x</code> ，恰好存在一个 <code>x</code> 与矩阵中的任何成员都不相等。</li>
	<li>对于所有满足<code>1 &lt;= x &lt;= n * n</code> 的 <code>x</code> ，恰好存在一个 <code>x</code> 与矩阵中的两个成员相等。</li>
	<li>除上述的两个之外，对于所有满足<code>1 &lt;= x &lt;= n * n</code> 的 <code>x</code> ，都恰好存在一对 <code>i, j</code> 满足 <code>0 &lt;= i, j &lt;= n - 1</code> 且 <code>grid[i][j] == x</code> 。</li>
</ul>


    
## 解题方法：计数（模拟）

开辟一个$n^2+1$的数组，用来记录每个数分别出现了多少次。

遍历原始数组即可完成计数数组，遍历计数数组即可得到答案。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> times(grid.size() * grid.size() + 1);
        for (vector<int>& line : grid) {
            for (int t : line) {
                times[t]++;
            }
        }
        vector<int> ans(2);
        for (int i = 1; i < times.size(); i++) {
            if (times[i] == 2) {
                ans[0] = i;
            }
            else if (times[i] == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
};
```

时间击败92.71%的提交，空间击败90.28%的提交。

## 其他方法

本题时间复杂度不可优化，说啥也得至少遍历一遍原始数组。如何优化空间复杂度呢？大致分为三种：

优化方法一：空间的原地使用：

> 例如$t$出现过就将数组中第$t$个元素置为负数，若某次将某元素置为负数时发现已经是负数了，则说明这个数出现了两次。到最后也没被置为负数的位置说明对应的数没有出现。

优化方法二：数学方法：

> $\sum_{i=1}^{n^2}i-\sum grid=b-a$，一个方程不足以解出两个变量，因此可以再加一个方程。
>
> 例如$\sum_{i=1}^{n^2}i^2-\sum_{i\in grid} i^2=b^2-a^2$，联立两方程即可得到$a$和$b$的值。

优化方法三：位运算：

> 根据异或的性质，异或一个数偶数次相当于没有异或。因此假设异或grid中的每个元素再异或从1到$n^2$得到结果$t$，则$t=a\oplus b$（相当于$a$一共异或了3次而$b$一共异或了1次）。
>
> 到这里很多同学都看出了这题本质和[260. 只出现一次的数字 III](https://leetcode.cn/problems/single-number-iii/)相同。
>
> 如何拆分$a$和$b$？依据两个原则分别异或即可。假设$t$二进制下第一个$1$是第$2$位，则**所有数**依据第$2$位是否为$1$分为两种。每组中所有元素相互异或，最终的两个结果就是$a$和$b$。
>
> > 这里“所有数”是指$1$到$n^2$的所有数以及原始数组中的所有数。
> >
> > 为什么这样能将$a$和$b$分开？因为根据异或结果$t$可得，$a$和$b$二进制下第$2$位绝对不同，因此$a$和$b$会被分到两个不同的组中。每个组中除了$a$或$b$都出现偶数次，因此两组的异或结果就是$a$和$b$。

## End

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/31/LeetCode%202965.%E6%89%BE%E5%87%BA%E7%BC%BA%E5%A4%B1%E5%92%8C%E9%87%8D%E5%A4%8D%E7%9A%84%E6%95%B0%E5%AD%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139357662](https://letmefly.blog.csdn.net/article/details/139357662)
