---
title: 2679.矩阵中的和：排序 + 模拟
date: 2023-07-04 06:57:45
tags: [题解, LeetCode, 中等, 数组, 矩阵, 排序, 模拟, 堆（优先队列）]
---

# 【LetMeFly】2679.矩阵中的和：排序 + 模拟

力扣题目链接：[https://leetcode.cn/problems/sum-in-a-matrix/](https://leetcode.cn/problems/sum-in-a-matrix/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>nums</code>&nbsp;。一开始你的分数为&nbsp;<code>0</code>&nbsp;。你需要执行以下操作直到矩阵变为空：</p>

<ol>
	<li>矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。</li>
	<li>在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 <strong>分数</strong>&nbsp;中。</li>
</ol>

<p>请你返回最后的 <strong>分数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
<b>输出：</b>15
<b>解释：</b>第一步操作中，我们删除 7 ，6 ，6 和 3 ，将分数增加 7 。下一步操作中，删除 2 ，4 ，5 和 2 ，将分数增加 5 。最后删除 1 ，2 ，3 和 1 ，将分数增加 3 。所以总得分为 7 + 5 + 3 = 15 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [[1]]
<b>输出：</b>1
<b>解释：</b>我们删除 1 并将分数增加 1 ，所以返回 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 300</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 500</code></li>
	<li><code>0 &lt;= nums[i][j] &lt;= 10<sup>3</sup></code></li>
</ul>


    
## 方法一：排序 + 模拟

其实只需要按照题目的意思进行模拟即可。每次在每一行中选择一个未选择过的最大的数，在所有行被选出的数中，将最大的那个累加到答案中。

那么唯一的问题是：如何快速选取某一行中，未被选择过的数中最大的数。

其实很简单，我们只需要将矩阵每一行从小到大排序，这样对于某一行，只需要从后往前选择就可以了。

+ 时间复杂度$O(nm\log m)$，其中$size(nums) = n\times m$
+ 空间复杂度$O(m\times m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        for (int i = 0; i < n; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        int ans = 0;
        for (int j = m - 1; j >= 0; j--) {
            int M = 0;
            for (int i = 0; i < n; i++) {
                M = max(M, nums[i][j]);
            }
            ans += M;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        n, m = len(nums), len(nums[0])
        for line in nums:
            line.sort()
        ans = 0
        for j in range(m - 1, -1, -1):
            M = 0
            for i in range(n):
                M = max(M, nums[i][j])
            ans += M
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/04/LeetCode%202679.%E7%9F%A9%E9%98%B5%E4%B8%AD%E7%9A%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131526894](https://letmefly.blog.csdn.net/article/details/131526894)
