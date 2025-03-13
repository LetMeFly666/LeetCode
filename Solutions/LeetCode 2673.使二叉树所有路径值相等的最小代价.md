---
title: 2673.使二叉树所有路径值相等的最小代价
date: 2024-02-28 21:23:07
tags: [题解, LeetCode, 中等, 贪心, 树, 数组, 动态规划, 二叉树, 深度优先搜索, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】2673.使二叉树所有路径值相等的最小代价：自顶向下的DFS 或 自底向上的递推

力扣题目链接：[https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/](https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/)

<p>给你一个整数&nbsp;<code>n</code>&nbsp;表示一棵 <b>满二叉树</b>&nbsp;里面节点的数目，节点编号从 <code>1</code>&nbsp;到 <code>n</code>&nbsp;。根节点编号为 <code>1</code>&nbsp;，树中每个非叶子节点&nbsp;<code>i</code>&nbsp;都有两个孩子，分别是左孩子&nbsp;<code>2 * i</code>&nbsp;和右孩子&nbsp;<code>2 * i + 1</code>&nbsp;。</p>

<p>树中每个节点都有一个值，用下标从<b>&nbsp;0</b>&nbsp;开始、长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>cost</code>&nbsp;表示，其中&nbsp;<code>cost[i]</code>&nbsp;是第&nbsp;<code>i + 1</code>&nbsp;个节点的值。每次操作，你可以将树中&nbsp;<strong>任意</strong>&nbsp;节点的值&nbsp;<strong>增加</strong>&nbsp;<code>1</code>&nbsp;。你可以执行操作 <strong>任意</strong> 次。</p>

<p>你的目标是让根到每一个 <strong>叶子结点</strong>&nbsp;的路径值相等。请你返回 <strong>最少</strong>&nbsp;需要执行增加操作多少次。</p>

<p><b>注意：</b></p>

<ul>
	<li><strong>满二叉树</strong>&nbsp;指的是一棵树，它满足树中除了叶子节点外每个节点都恰好有 2 个节点，且所有叶子节点距离根节点距离相同。</li>
	<li><strong>路径值</strong> 指的是路径上所有节点的值之和。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/04/04/binaryytreeedrawio-4.png" /></p>

<pre>
<b>输入：</b>n = 7, cost = [1,5,2,2,3,3,1]
<b>输出：</b>6
<b>解释：</b>我们执行以下的增加操作：
- 将节点 4 的值增加一次。
- 将节点 3 的值增加三次。
- 将节点 7 的值增加两次。
从根到叶子的每一条路径值都为 9 。
总共增加次数为 1 + 3 + 2 = 6 。
这是最小的答案。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/04/04/binaryytreee2drawio.png" style="width: 205px; height: 151px;" /></p>

<pre>
<b>输入：</b>n = 3, cost = [5,3,3]
<b>输出：</b>0
<b>解释：</b>两条路径已经有相等的路径值，所以不需要执行任何增加操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n + 1</code> 是&nbsp;<code>2</code>&nbsp;的幂</li>
	<li><code>cost.length == n</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>4</sup></code></li>
</ul>

## 思路

对于某个节点，假设其左子树和右子树都已经“增加”过了（对于左子树，所有路径值相等，右子树同理），但是左子树根到叶路径之和（记为leftSum）和右子树的rightSum不等，我们应该怎么操作呢？

<details>
<summary>举例说明点我</summary>

> 例如如下二叉树中
> 
> ```
>    1
>  5   2
> 2 3 3 1
> ```
> 
> 的根节点```1```，假设其左子树已经由
> 
> ```
>  5
> 2 3
> ```
> 
> 变成了
> 
> ```
>  5
> 3 3
> ```
> 
> ，而右子树已经由
> 
> ```
>  2
> 3 1
> ```
> 变成了
> 
> ```
>  2
> 3 3
> ```
> 
> 那么我们应该如何进行下一步操作呢？
> 
> 对于根节点```1```：其左子树已经平衡，路径之和为```5 + 3 = 8```；其右子树已经平衡，路径之和为```2 + 3 = 5```。
> 
> 想要让左右子路径之和相等？当然只要```右子```的根节点```+3```即可。

也就是说：

</details>

将```左右子树路径和之差```加到```路径和较小的子树```的根节点上。

这是因为“加一操作”越靠近根，所能影响的路径数就越多。

## 方法一：自顶向下的DFS

首先要说明的是这种方法的空间复杂度不如方法二，但是比方法二更容易理解。

我们只需要写一个函数```dfs(n)```返回节点```n```（根节点下标从```0```开始）为根到叶节点的路径之和：

> 1. **递归**左子树得到```leftSum```，递归右子树得到```rightSum```
>
> 2. 将```leftSum```和```rightSum```之差累加到答案中
>
> 3. 返回```max(leftSum, rightSum) + cost[n]```作为该节点到叶节点的路径之和
>
> 终止条件：```n```超出数组范围

+ 时间复杂度$O(N)$，其中$N$为二叉树节点个数。
+ 空间复杂度$O(\log N)$，满二叉树的深度是$\log N$级别的。

### AC代码

#### C++

```cpp
class Solution {
private:
    int ans;

    int dfs(int n, vector<int>& cost) {
        if (n >= cost.size()) {
            return 0;
        }
        /*
               0
             1   2
            3 4 5 6
        */
        int leftSum = dfs(n * 2 + 1, cost);
        int rightSum = dfs(n * 2 + 2, cost);
        ans += max(leftSum, rightSum) - min(leftSum, rightSum);
        return max(leftSum, rightSum) + cost[n];
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        ans = 0;
        dfs(0, cost);
        return ans;
    }
};
```

## 方法二：自底向上的递推

![自底向上](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/direct/2332f2c002254d3da8b63c8c8fad9ee0.png)

<!-- ![自底向上](https://pic.leetcode.cn/1709128858-vXQXHL-%E6%97%A0%E6%A0%87%E9%A2%98.png) -->

在自顶向下的方法一中，递归占用了$O(N)$的空间复杂度。因为往下计算的过程中还要存储当前节点的信息。

因此我们可以倒过来，采用自底向上的方法：

> 1. 从最后一个非叶节点开始往根节点遍历
> 
> 2. 这个节点的两个子节点之差累加到答案
>
> 3. 这个节点的两个子节点的最大值累加到这个节点（路径累加）

这样相当于是把值存放到$cost$数组中了。

+ 时间复杂度$O(N)$，其中$N$为二叉树节点个数。
+ 空间复杂度$O(1)$，但是我们修改了$cost$数组的值。若其值不能被修改，则空间复杂度为$O(N)$（大于方法一的$O(\log N)$，因为方法一底部的值向上传递后可以被丢弃）

### AC代码

#### C++

```cpp
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n / 2 - 1; i >= 0; i--) {
            ans += abs(cost[i * 2 + 1] - cost[i * 2 + 2]);
            cost[i] += max(cost[i * 2 + 1], cost[i * 2 + 2]);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        ans = 0
        for i in range(n // 2 - 1, -1, -1):
            ans += abs(cost[i * 2 + 1] - cost[i * 2 + 2])
            cost[i] += max(cost[i * 2 + 1], cost[i * 2 + 2])
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/28/LeetCode%202673.%E4%BD%BF%E4%BA%8C%E5%8F%89%E6%A0%91%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84%E5%80%BC%E7%9B%B8%E7%AD%89%E7%9A%84%E6%9C%80%E5%B0%8F%E4%BB%A3%E4%BB%B7/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136357361](https://letmefly.blog.csdn.net/article/details/136357361)
