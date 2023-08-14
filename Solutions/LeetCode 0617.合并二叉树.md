---
title: 617.合并二叉树
date: 2023-08-14 08:02:44
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, 二叉树, DFS]
---

# 【LetMeFly】617.合并二叉树

力扣题目链接：[https://leetcode.cn/problems/merge-two-binary-trees/](https://leetcode.cn/problems/merge-two-binary-trees/)

<p>给你两棵二叉树： <code>root1</code> 和 <code>root2</code> 。</p>

<p>想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，<strong>不为</strong> null 的节点将直接作为新二叉树的节点。</p>

<p>返回合并后的二叉树。</p>

<p><strong>注意:</strong> 合并过程必须从两个树的根节点开始。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/merge.jpg" style="height: 163px; width: 600px;" />
<pre>
<strong>输入：</strong>root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
<strong>输出：</strong>[3,4,5,5,4,null,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root1 = [1], root2 = [1,2]
<strong>输出：</strong>[2,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>两棵树中的节点数目在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：深度优先搜索DFS

很简单，对于```mergeTrees(root1, root2)```函数，root1和2的空与非空一共有4种情况：
   + 如果```!root1 && !root2```：返回```NULL```
   + 如果```root1 && root2```：返回节点的值为二者值之和，返回节点的left为mergeTrees(root1.left, root2.left)，返回节点的right同理
   + 如果```root1 && !root2```：直接返回root1
   + 如果```!root1 && root2```：直接返回root2

这里其实偷了个懒，没有新建节点，直接把root1覆盖并返回了。

+ 时间复杂度$O(min(size(root1), size(root2)))$
+ 空间复杂度$O(min(size(root1), size(root2)))$

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        }
        if (root1 && root2) {
            root1->val += root2->val;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
        return root1 ? root1 : root2;
    }
};
```

#### Python

```python
# from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root1 and not root2:
            return None
        if root1 and root2:
            root1.val += root2.val
            root1.left = self.mergeTrees(root1.left, root2.left)
            root1.right = self.mergeTrees(root1.right, root2.right)
            return root1
        return root1 if root1 else root2
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/08/14/LeetCode%200617.%E5%90%88%E5%B9%B6%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132268393](https://letmefly.blog.csdn.net/article/details/132268393)
