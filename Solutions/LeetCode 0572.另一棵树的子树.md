---
title: 572.另一棵树的子树
date: 2024-08-05 22:32:37
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, BFS, DFS, 二叉树, 字符串匹配, 哈希函数]
categories: [题解, LeetCode]
---

# 【LetMeFly】572.另一棵树的子树：深搜+广搜（n^2做法就能过，也有复杂度耕地的算法）

力扣题目链接：[https://leetcode.cn/problems/subtree-of-another-tree/](https://leetcode.cn/problems/subtree-of-another-tree/)

<div class="original__bRMd">
<div>
<p>给你两棵二叉树 <code>root</code> 和 <code>subRoot</code> 。检验 <code>root</code> 中是否包含和 <code>subRoot</code> 具有相同结构和节点值的子树。如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>二叉树 <code>tree</code> 的一棵子树包括 <code>tree</code> 的某个节点和这个节点的所有后代节点。<code>tree</code> 也可以看做它自身的一棵子树。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg" style="width: 532px; height: 400px;" />
<pre>
<strong>输入：</strong>root = [3,4,5,1,2], subRoot = [4,1,2]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg" style="width: 502px; height: 458px;" />
<pre>
<strong>输入：</strong>root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>root</code> 树上的节点数量范围是 <code>[1, 2000]</code></li>
	<li><code>subRoot</code> 树上的节点数量范围是 <code>[1, 1000]</code></li>
	<li><code>-10<sup>4</sup> <= root.val <= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> <= subRoot.val <= 10<sup>4</sup></code></li>
</ul>
</div>
</div>


    
## 解题方法：深搜+广搜（硬匹配）

如何判断两个树是否相同呢？

> 我们可以写一个函数`isSame(rootA, rootB)`来判断以rootA为根的树是否和以rootB为根的树相同。
>
> 首先如果rootA和rootB中有一个为空，那么他们都要为空才能相等；
>
> 否则（都不为空），rootA的值必须和rootB的值相等，并且他们的左子树相等（可递归判断），右子树也相等，两棵树才能相同。

因此，我们可以遍历以root为根的这棵树的每一个节点（深搜和广搜都可，本题解中C++代码以广搜为例，Python代码以深搜为例），判断以每个节点为根的树是否和以subRoot为根的树相同。一旦存在相同的子树，则立即返回true。

+ 时间复杂度$O(size(root)\times size(subRoot))$
+ 空间复杂度$O(size(root))$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a || !b) {
            return a == b;
        }
        return a->val == b->val && isSame(a->left, b->left) && isSame(a->right, b->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            if (isSame(thisNode, subRoot)) {
                return true;
            }
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
        return false;
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
    def isSame(self, a: Optional[TreeNode], b: Optional[TreeNode]) -> bool:
        if not a or not b:
            return a == b
        return a.val == b.val and self.isSame(a.left, b.left) and self.isSame(a.right, b.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not root:
            return False
        if self.isSame(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
```

## 解题方法拓展

假设两棵树的节点个数分别为m和n。

上述解题方法中，如果二叉树退化成链，且树中元素几乎全为1，则要比较接近$mn$次。

有没有什么能提升效率的方法呢？其实我们在深搜以root为根的树的时候可以统计一下每个节点距其子树最远叶子节点的距离，只有高度相同的树才有可能相同。这样，每个节点不会被比较多次，我们就将时间复杂度降低到了$O(m)$。（如果$n\gt m$则不会比完全以subRoot为根节点的树的节点）

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/05/LeetCode%200572.%E5%8F%A6%E4%B8%80%E6%A3%B5%E6%A0%91%E7%9A%84%E5%AD%90%E6%A0%91/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140939018](https://letmefly.blog.csdn.net/article/details/140939018)
