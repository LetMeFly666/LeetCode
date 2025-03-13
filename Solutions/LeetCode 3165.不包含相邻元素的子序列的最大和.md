---
title: 3165.不包含相邻元素的子序列的最大和
date: 2024-11-02 15:51:52
tags: [题解, LeetCode, 困难, 线段树, 数组, 分治, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】3165.不包含相邻元素的子序列的最大和：单点修改的线段树（动态规划）

力扣题目链接：[https://leetcode.cn/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/](https://leetcode.cn/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/)

<p>给你一个整数数组 <code>nums</code> 和一个二维数组 <code>queries</code>，其中 <code>queries[i] = [pos<sub>i</sub>, x<sub>i</sub>]</code>。</p>

<p>对于每个查询 <code>i</code>，首先将 <code>nums[pos<sub>i</sub>]</code> 设置为 <code>x<sub>i</sub></code>，然后计算查询 <code>i</code> 的答案，该答案为 <code>nums</code> 中 <strong>不包含相邻元素 </strong>的 <span data-keyword="subsequence-array">子序列</span> 的 <strong>最大 </strong>和。</p>

<p>返回所有查询的答案之和。</p>

<p>由于最终答案可能非常大，返回其对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p><strong>子序列</strong> 是指从另一个数组中删除一些或不删除元素而不改变剩余元素顺序得到的数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,5,9], queries = [[1,-2],[0,-3]]</span></p>

<p><strong>输出：</strong><span class="example-io">21</span></p>

<p><strong>解释：</strong><br />
执行第 1 个查询后，<code>nums = [3,-2,9]</code>，不包含相邻元素的子序列的最大和为 <code>3 + 9 = 12</code>。<br />
执行第 2 个查询后，<code>nums = [-3,-2,9]</code>，不包含相邻元素的子序列的最大和为 9 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [0,-1], queries = [[0,-5]]</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong><br />
执行第 1 个查询后，<code>nums = [-5,-1]</code>，不包含相邻元素的子序列的最大和为 0（选择空子序列）。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>queries[i] == [pos<sub>i</sub>, x<sub>i</sub>]</code></li>
	<li><code>0 &lt;= pos<sub>i</sub> &lt;= nums.length - 1</code></li>
	<li><code>-10<sup>5</sup> &lt;= x<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：线段树 + DP

对于单次操作，我们可以使用分治的方法来求解。对于一个子区间，我们比较关注的有：区间第一个元素是否被选取、区间最后一个元素是否被选取。也就是说，对于一个子区间，一共有以下4种情况：

+ 开头一定不选，结尾一定不选，记为$f00$
+ 开头一定不选，结尾可选(也可不选)，记为$f01$
+ 开头可选(也可不选)，结尾一定不选，记为$f10$
+ 开头可选(也可不选)，结尾可选(也可不选)，记为$f11$

那么对于区间$[left, right]$，如何进行分治操作呢？

+ 如果$left==right$，那么这个区间就只有一个元素，这个区间的$f00=f01=f10=0$，$f11=\max(0, nums[left])$。
+ 否则，令$mid = \lfloor\frac{left+right}{2}\rfloor$，递归计算$[left, mid]$和$[mid + 1, right]$两个子区间的4个值并汇总得到这个区间的4个值。

   假设左区间为$p$，右区间为$q$，则汇总方式为：

   + $f00 = \max(f_p00+f_q10, f_p01+f_q00)$
   + $f01 = \max(f_p00+f_q11, f_p01+f_q01)$
   + $f10 = \max(f_p10+f_q10, f_p11+f_q00)$
   + $f11 = \max(f_p10+f_q11, f_p11+f_q01)$

那么如何应对$len(queries)$次的修改呢？那就需要引入[线段树](https://blog.letmefly.xyz/tags/%E7%BA%BF%E6%AE%B5%E6%A0%91)了。

+ 对于修改操作，使用线段树实现单点修改，线段树的每个节点维护对应区间的4个值
+ 对于查询操作，线段树根节点（整个区间）的$f11$记为所求

### 时空复杂度分析

+ 时间复杂度$O(n+q\log n)$，其中$n=len(nums)$，$q=len(queries)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
const unsigned int mod = 1e9 + 7;

class Solution {
private:
    vector<array<unsigned int, 4>> tree;  // 00, 01, 10, 11

    void maintain(int index) {
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;
        tree[index] = {
            max(tree[leftIndex][1] + tree[rightIndex][0], tree[leftIndex][0] + tree[rightIndex][2]),
            max(tree[leftIndex][0] + tree[rightIndex][3], tree[leftIndex][1] + tree[rightIndex][1]),
            max(tree[leftIndex][2] + tree[rightIndex][2], tree[leftIndex][3] + tree[rightIndex][0]),
            max(tree[leftIndex][2] + tree[rightIndex][3], tree[leftIndex][3] + tree[rightIndex][1])
        };
    }

    void buildTree(vector<int>& nums, int index, int left, int right) {
        if (left == right) {
            tree[index] = {0, 0, 0, (unsigned int)max(nums[left], 0)};
            return;
        }
        int mid = (left + right) / 2;
        buildTree(nums, 2 * index + 1, left, mid);
        buildTree(nums, 2 * index + 2, mid + 1, right);
        maintain(index);
    }

    void update(int index, int left, int right, int modifiedI, int val) {
        if (left == right) {
            tree[index][3] = max(0, val);
            return;
        }
        int mid = (left + right) / 2;
        if (modifiedI <= mid) {
            update(2 * index + 1, left, mid, modifiedI, val);
        } else {
            update(2 * index + 2, mid + 1, right, modifiedI, val);
        }
        maintain(index);
    }
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        tree.resize(nums.size() * 4);
        buildTree(nums, 0, 0, nums.size() - 1);
        unsigned int ans = 0;
        for (vector<int>& query : queries) {
            update(0, 0, nums.size() - 1, query[0], query[1]);
            ans = (ans + tree[0][3]) % mod;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

MOD = 1_000_000_007
class Solution:
    def maintain(self, index: int) -> None:
        leftNode = self.tree[2 * index + 1]
        rightNode = self.tree[2 * index + 2]
        self.tree[index] = [
            max(leftNode[0] + rightNode[2], leftNode[1] + rightNode[0]),
            max(leftNode[0] + rightNode[3], leftNode[1] + rightNode[1]),
            max(leftNode[2] + rightNode[2], leftNode[3] + rightNode[0]),
            max(leftNode[2] + rightNode[3], leftNode[3] + rightNode[1])
        ]
    
    def build(self, index: int, left: int, right: int) -> None:
        if left == right:
            self.tree[index][3] = self.nums[left]
            return
        mid = (left + right) >> 1
        self.build(2 * index + 1, left, mid)
        self.build(2 * index + 2, mid + 1, right)
        self.maintain(index)

    def update(self, index: int, left: int, right: int, modifiedI: int, val: int) -> None:
        if left == right:
            self.tree[index][3] = max(0, val)
            return
        mid = (left + right) >> 1
        if modifiedI <= mid:
            self.update(2 * index + 1, left, mid, modifiedI, val)
        else:
            self.update(2 * index + 2, mid + 1, right, modifiedI, val)
        self.maintain(index)

    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        self.tree = [[0, 0, 0, 0] for _ in range(len(nums) * 4)]  # 00, 01, 10, 11
        self.nums = nums
        self.build(0, 0, len(nums) - 1)
        ans = 0
        for q, v in queries:
            self.update(0, 0, len(nums) - 1, q, v)
            ans = (ans + self.tree[0][3]) % MOD
        return ans

```

#### Java

```java
class Solution {
    private long[][] tree;  // 诶，如果不是long的话会有两组数据无法通过
    private final int mod = 1000000007;

    private void maintain(int index) {
        long[] leftNode = tree[2 * index + 1];
        long[] rightNode = tree[2 * index + 2];
        tree[index][0] = Math.max(leftNode[0] + rightNode[2], leftNode[1] + rightNode[0]);
        tree[index][1] = Math.max(leftNode[0] + rightNode[3], leftNode[1] + rightNode[1]);
        tree[index][2] = Math.max(leftNode[2] + rightNode[2], leftNode[3] + rightNode[0]);
        tree[index][3] = Math.max(leftNode[2] + rightNode[3], leftNode[3] + rightNode[1]);
    }

    private void build(int[] nums, int index, int left, int right) {
        if (left == right) {
            tree[index][3] = Math.max(0, nums[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(nums, 2 * index + 1, left, mid);
        build(nums, 2 * index + 2, mid + 1, right);
        maintain(index);
    }

    private void update(int index, int left, int right, int modifiedI, int val) {
        if (left == right) {
            tree[index][3] = Math.max(0, val);
            return;
        }
        int mid = (left + right) / 2;
        if (modifiedI <= mid) {
            update(2 * index + 1, left, mid, modifiedI, val);
        } else {
            update(2 * index + 2, mid + 1, right, modifiedI, val);
        }
        maintain(index);
    }

    public int maximumSumSubsequence(int[] nums, int[][] queries) {
        tree = new long[4 * nums.length][4];  // 00, 01, 10, 11
        build(nums, 0, 0, nums.length - 1);
        long ans = 0;
        for (int[] query : queries) {
            update(0, 0, nums.length - 1, query[0], query[1]);
            ans = (ans + tree[0][3]) % mod;
        }
        return (int)ans;
    }
}
```

#### Go

```go
package main

type data struct {
    _00 int
    _01 int
    _10 int
    _11 int
}

type seg []data

func max(a int, b int) int {
    if a >= b {
        return a
    }
    return b
}

func maintain(tree seg, index int) {
    leftNode := tree[index * 2 + 1]
    rightNode := tree[index * 2 + 2]
    tree[index] = data{
        max(leftNode._00 + rightNode._10, leftNode._01 + rightNode._00),
        max(leftNode._00 + rightNode._11, leftNode._01 + rightNode._01),
        max(leftNode._10 + rightNode._10, leftNode._11 + rightNode._00),
        max(leftNode._10 + rightNode._11, leftNode._11 + rightNode._01),
    }
}

func build(tree seg, nums []int, index int, left int, right int) {
    if left == right {
        tree[index]._11 = max(0, nums[left])
        return
    }
    mid := (left + right) >> 1
    build(tree, nums, 2 * index + 1, left, mid)
    build(tree, nums, 2 * index + 2, mid + 1, right)
    maintain(tree, index)
}

func update(tree seg, index int, left int, right int, modified int, val int) {
    if left == right {
        tree[index]._11 = max(0, val)
        return
    }
    mid := (left + right) >> 1
    if modified <= mid {
        update(tree, 2 * index + 1, left, mid, modified, val)
    } else {
        update(tree, 2 * index + 2, mid + 1, right, modified, val)
    }
    maintain(tree, index)
}

func maximumSumSubsequence(nums []int, queries [][]int) int {
    tree := make(seg, len(nums) * 4)
    build(tree, nums, 0, 0, len(nums) - 1)
    ans := 0
    for _, query := range queries {
        update(tree, 0, 0, len(nums) - 1, query[0], query[1])
        ans = (ans + tree[0]._11) % 1_000_000_007
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/02/LeetCode%203165.%E4%B8%8D%E5%8C%85%E5%90%AB%E7%9B%B8%E9%82%BB%E5%85%83%E7%B4%A0%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143452715](https://letmefly.blog.csdn.net/article/details/143452715)
