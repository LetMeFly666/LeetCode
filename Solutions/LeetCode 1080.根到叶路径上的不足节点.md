---
title: 1080.根到叶路径上的不足节点
date: 2023-05-22 09:52:31
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 二叉树]
---

# 【LetMeFly】1080.根到叶路径上的不足节点

力扣题目链接：[https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/](https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/)

<p>给定一棵二叉树的根 <code>root</code>，请你考虑它所有&nbsp;<strong>从根到叶的路径</strong>：从根到任何叶的路径。（所谓一个叶子节点，就是一个没有子节点的节点）</p>

<p>假如通过节点 <code>node</code> 的每种可能的 &ldquo;根-叶&rdquo; 路径上值的总和全都小于给定的 <code>limit</code>，则该节点被称之为「不足节点」，需要被删除。</p>

<p>请你删除所有不足节点，并返回生成的二叉树的根。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/08/insufficient-1.png" style="height: 200px; width: 482px;">
输入：</strong>root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
<strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/08/insufficient-2.png" style="height: 200px; width: 258px;">
输出：</strong>[1,2,3,4,null,null,7,8,9,null,14]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/08/insufficient-3.png" style="height: 200px; width: 292px;">
输入：</strong>root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
<strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/08/insufficient-4.png" style="height: 200px; width: 264px;">
输出：</strong>[5,4,8,11,null,17,4,7,null,null,null,5]</pre>

<p><strong>示例 3：</strong></p>

<pre><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/06/08/insufficient-5.png" style="height: 100px; width: 140px;">
输入：</strong>root = [5,-6,-6], limit = 0<strong>
输出：</strong>[]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>给定的树有&nbsp;<code>1</code>&nbsp;到&nbsp;<code>5000</code>&nbsp;个节点</li>
	<li><code>-10^5&nbsp;&lt;= node.val &lt;= 10^5</code></li>
	<li><code>-10^9 &lt;= limit&nbsp;&lt;= 10^9</code></li>
</ol>

<p>&nbsp;</p>


    
## 方法一：深度优先搜索DFS

首先我们将“limit”理解为“need”，意思为“路径总和还需要need这么多才能不被删除”

接着我们就可以开始递归了。递归函数“dfs(TreeNode* root, int need)”的功能是：

从root到叶节点，是否所有的路径的和都小于need。如果是，则说明root需要被删除，返回“空”；否则，返回删除过左右子节点的root。

具体怎么判断呢？

+ 如果root是叶节点，那么就看$need - root.val$是否大于$0$。如果大于0，就说明要删掉root节点；否则直接返回root节点。
+ 否则（root不是叶节点），将root的左右子替换成递归后的结果，如果左右子都空，则删掉root；否则返回修改过左右子的root。

为了方便，我们也可以直接使用题目中自带的sufficientSubset函数作为dfs函数。

+ 时间复杂度$O(n)$，其中$n$是二叉树的节点个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, long long limit) {
        limit -= root->val;
        if (!root->left && !root->right) {  // 叶节点
            if (limit <= 0) {
                return root;
            }
            else {
                // delete root;
                return nullptr;
            }
        }
        TreeNode* left = root->left ? sufficientSubset(root->left, limit) : nullptr;
        TreeNode* right = root->right ? sufficientSubset(root->right, limit) : nullptr;
        if (!left && !right) {
            // delete root;
            return nullptr;
        }
        else {
            root->left = left;
            root->right = right;
            return root;
        }
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
    def sufficientSubset(self, root: Optional[TreeNode], limit: int) -> Optional[TreeNode]:
        limit -= root.val
        if not root.left and not root.right:
            if limit <= 0:
                return root
            else:
                return None
        left = self.sufficientSubset(root.left, limit) if root.left else None
        right = self.sufficientSubset(root.right, limit) if root.right else None
        if not left and not right:
            return None
        else:
            root.left = left
            root.right = right
            return root
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/22/LeetCode%201080.%E6%A0%B9%E5%88%B0%E5%8F%B6%E8%B7%AF%E5%BE%84%E4%B8%8A%E7%9A%84%E4%B8%8D%E8%B6%B3%E8%8A%82%E7%82%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130801361](https://letmefly.blog.csdn.net/article/details/130801361)
