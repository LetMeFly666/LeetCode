---
title: 938.二叉搜索树的范围和
date: 2024-02-26 18:56:24
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, DFS, 中序遍历, 二叉搜索树, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】938.二叉搜索树的范围和：深度优先搜索（可中序遍历）

力扣题目链接：[https://leetcode.cn/problems/range-sum-of-bst/](https://leetcode.cn/problems/range-sum-of-bst/)

<p>给定二叉搜索树的根结点 <code>root</code>，返回值位于范围 <em><code>[low, high]</code></em> 之间的所有结点的值的和。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg" style="width: 400px; height: 222px;" />
<pre>
<strong>输入：</strong>root = [10,5,15,3,7,null,18], low = 7, high = 15
<strong>输出：</strong>32
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg" style="width: 400px; height: 335px;" />
<pre>
<strong>输入：</strong>root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
<strong>输出：</strong>23
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 2 * 10<sup>4</sup>]</code> 内</li>
	<li><code>1 <= Node.val <= 10<sup>5</sup></code></li>
	<li><code>1 <= low <= high <= 10<sup>5</sup></code></li>
	<li>所有 <code>Node.val</code> <strong>互不相同</strong></li>
</ul>


    
## 方法一：深度优先搜索（可中序遍历）

二叉搜索树有一个性质：其中序遍历得到的序列递增。

但其实我们不使用这个性质也可以，只需要将其当作一个普通的二叉树。

遍历二叉树（可以中序也可以其他）并且在遍历途中判断当前节点的值是否在```[low, high]```之间。如果是则累加之。

+ 时间复杂度$O(N)$，其中$N$是二叉树节点的个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {  // AC,96.46%,73.98%
private:
    int ans;

    void dfs(TreeNode* root, int l, int r) {
        if (!root) {
            return;
        }
        dfs(root->left, l, r);
        if (root->val >= l && root->val <= r) {
            ans += root->val;
        }
        dfs(root->right, l, r);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        ans = 0;
        dfs(root, low, high);
        return ans;
    }
};
```

#### Python

```python
# from typing import Optional

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode], l: int, r: int) -> None:
        if not root:
            return
        self.dfs(root.left, l, r)
        if l <= root.val <= r:
            self.ans += root.val
        self.dfs(root.right, l, r)

    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.ans = 0
        self.dfs(root, low, high)
        return self.ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/26/LeetCode%200938.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E8%8C%83%E5%9B%B4%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136306565](https://letmefly.blog.csdn.net/article/details/136306565)
