---
title: 111.二叉树的最小深度
date: 2022-07-11 11:42:42
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, 二叉树, DFS, 树的深度]
categories: [题解, LeetCode]
---

# 【LetMeFly】111.二叉树的最小深度：DFS + 遇到叶节点更新最小深度

力扣题目链接：[https://leetcode.cn/problems/minimum-depth-of-binary-tree/](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

<p>给定一个二叉树，找出其最小深度。</p>

<p>最小深度是从根节点到最近叶子节点的最短路径上的节点数量。</p>

<p><strong>说明：</strong>叶子节点是指没有子节点的节点。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg" style="width: 432px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [2,null,3,null,4,null,5,null,6]
<strong>输出：</strong>5
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数的范围在 <code>[0, 10<sup>5</sup>]</code> 内</li>
	<li><code>-1000 <= Node.val <= 1000</code></li>
</ul>


    
## 方法一：DFS + 遇到叶节点更新最小深度

我们只需要DFS遍历一遍树的节点，在遍历的同时，将当前节点的深度作为参数传递给DFS函数。

如果当前节点是叶节点（当前节点的深度是叶节点的深度之一），就更新当前深度的最小值

然后若左/右子不空，继续DFS即可。

+ 时间复杂度$O(N)$，其中$N$是节点的数量
+ 空间复杂度$O(H)$，其中$H$是最大的节点深度

### AC代码

#### C++

```cpp
class Solution {
private:
    int minDeepth = INT_MAX;  // 初始最小节点深度是一个很大的值

    void dfs(TreeNode* root, int nowDeepth) {
        if (!root->left && !root->right)  // 当前节点是叶节点
            minDeepth = min(minDeepth, nowDeepth);  // 更新叶节点深度的最小值
        if (root->left)  // 若左节点不空
            dfs(root->left, nowDeepth + 1);
        if (root->right)  // 若右节点不空
            dfs(root->right, nowDeepth + 1);
    }
public:
    int minDepth(TreeNode* root) {
        if (!root)  // 空树
            return 0;
        dfs(root, 1);  // 从根节点开始DFS
        return minDeepth;  // 返回最小深度
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/11/LeetCode%200111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125718620](https://letmefly.blog.csdn.net/article/details/125718620)
