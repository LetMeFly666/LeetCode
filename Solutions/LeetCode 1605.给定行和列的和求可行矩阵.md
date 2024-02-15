---
title: 1605.给定行和列的和求可行矩阵
date: 2023-03-14 12:54:05
tags: [题解, LeetCode, 中等, 贪心, 数组, 矩阵]
---

# 【LetMeFly】1605.给定行和列的和求可行矩阵

力扣题目链接：[https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/](https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/)

<p>给你两个非负整数数组 <code>rowSum</code> 和 <code>colSum</code> ，其中 <code>rowSum[i]</code> 是二维矩阵中第 <code>i</code> 行元素的和， <code>colSum[j]</code> 是第 <code>j</code> 列元素的和。换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。</p>

<p>请找到大小为 <code>rowSum.length x colSum.length</code> 的任意 <strong>非负整数</strong> 矩阵，且该矩阵满足 <code>rowSum</code> 和 <code>colSum</code> 的要求。</p>

<p>请你返回任意一个满足题目要求的二维矩阵，题目保证存在 <strong>至少一个</strong> 可行矩阵。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [3,8], colSum = [4,7]
<strong>输出：</strong>[[3,0],
      [1,7]]
<strong>解释：</strong>
第 0 行：3 + 0 = 3 == rowSum[0]
第 1 行：1 + 7 = 8 == rowSum[1]
第 0 列：3 + 1 = 4 == colSum[0]
第 1 列：0 + 7 = 7 == colSum[1]
行和列的和都满足题目要求，且所有矩阵元素都是非负的。
另一个可行的矩阵为：[[1,2],
                  [3,5]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [5,7,10], colSum = [8,6,8]
<strong>输出：</strong>[[0,5,0],
      [6,1,0],
      [2,0,8]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [14,9], colSum = [6,9,8]
<strong>输出：</strong>[[0,9,5],
      [6,0,3]]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [1,0], colSum = [1]
<strong>输出：</strong>[[1],
      [0]]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>rowSum = [0], colSum = [0]
<strong>输出：</strong>[[0]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= rowSum.length, colSum.length <= 500</code></li>
	<li><code>0 <= rowSum[i], colSum[i] <= 10<sup>8</sup></code></li>
	<li><code>sum(rows) == sum(columns)</code></li>
</ul>


    
## 方法一：贪心

这道题要是不证明的话还挺好做的，直接无脑贪心即可。

外层循环从上到下，内层循环从左到右遍历答案数组，将答案数组的当前位置的值设置为$\min(rowSum[i], colSum[j])$即可。（注意设置完成后rowSum[i]和colSum[j]要减去当前位置的值）

非要证明的话，应该比较麻烦吧。反正题目说“保证有解”

+ 时间复杂度$O(len(rowSum)\times len(colSum))$
+ 空间复杂度$O(1)$，力扣的返回值不计入算法的空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size()));
        for (int i = 0; i < rowSum.size(); i++) {
            for (int j = 0; j < colSum.size(); j++) {
                int thisVal = min(rowSum[i], colSum[j]);
                ans[i][j] = thisVal;
                rowSum[i] -= thisVal;
                colSum[j] -= thisVal;
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        ans = [[0 for i in range(len(colSum))] for j in range(len(rowSum))]
        for i in range(len(rowSum)):
            for j in range(len(colSum)):
                thisVal = min(rowSum[i], colSum[j])
                ans[i][j] = thisVal
                rowSum[i] -= thisVal
                colSum[j] -= thisVal
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/14/LeetCode%201605.%E7%BB%99%E5%AE%9A%E8%A1%8C%E5%92%8C%E5%88%97%E7%9A%84%E5%92%8C%E6%B1%82%E5%8F%AF%E8%A1%8C%E7%9F%A9%E9%98%B5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129524126](https://letmefly.blog.csdn.net/article/details/129524126)
