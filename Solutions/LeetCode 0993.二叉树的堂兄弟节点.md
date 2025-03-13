---
title: 993.二叉树的堂兄弟节点
date: 2024-02-08 12:02:31
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】993.二叉树的堂兄弟节点：深度优先搜索(BFS)

力扣题目链接：[https://leetcode.cn/problems/cousins-in-binary-tree/](https://leetcode.cn/problems/cousins-in-binary-tree/)

<p>在二叉树中，根节点位于深度 <code>0</code> 处，每个深度为 <code>k</code> 的节点的子节点位于深度 <code>k+1</code> 处。</p>

<p>如果二叉树的两个节点深度相同，但<strong> 父节点不同</strong> ，则它们是一对<em>堂兄弟节点</em>。</p>

<p>我们给出了具有唯一值的二叉树的根节点 <code>root</code> ，以及树中两个不同节点的值 <code>x</code> 和 <code>y</code> 。</p>

<p>只有与值 <code>x</code> 和 <code>y</code> 对应的节点是堂兄弟节点时，才返回 <code>true</code> 。否则，返回 <code>false</code>。</p>

<p> </p>

<p><strong>示例 1：<br />
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/16/q1248-01.png" style="height: 160px; width: 180px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4], x = 4, y = 3
<strong>输出：</strong>false
</pre>

<p><strong>示例 2：<br />
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/16/q1248-02.png" style="height: 160px; width: 201px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4,null,5], x = 5, y = 4
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/16/q1248-03.png" style="height: 160px; width: 156px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,null,4], x = 2, y = 3
<strong>输出：</strong>false</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树的节点数介于 <code>2</code> 到 <code>100</code> 之间。</li>
	<li>每个节点的值都是唯一的、范围为 <code>1</code> 到 <code>100</code> 的整数。</li>
</ul>

<p> </p>


    
## 方法一：深度优先搜索(BFS)

两个节点是堂兄弟节点**当且仅当**两节点深度相同且父节点不同。

因此，我们写一个深度优先搜索函数，若搜到了```x```节点或```y```节点，则记录其父节点和深度。

最终看是否是堂兄弟节点即可。

+ 时间复杂度$O(size(tree))$
+ 空间复杂度$O(size(tree))$

### AC代码

#### C++

```cpp
class Solution {
private:
    int x, y;
    TreeNode* x_father, *y_father;
    int x_depth, y_depth;

    void dfs(TreeNode* root, int depth, TreeNode* father) {
        if (!root) {
            return ;
        }
        if (root->val == x) {
            x_father = father;
            x_depth = depth;
        }
        if (root->val == y) {
            y_father = father;
            y_depth = depth;
        }
        dfs(root->left, depth + 1, root);
        dfs(root->right, depth + 1, root);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x, this->y = y;
        dfs(root, 0, nullptr);
        return x_father != y_father && x_depth == y_depth;
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
    def dfs(self, root: Optional[TreeNode], depth: int, father: Optional[TreeNode]) -> None:
        if not root:
            return
        if root.val == self.x:
            self.x_father = father
            self.x_depth = depth
        if root.val == self.y:
            self.y_father = father
            self.y_depth = depth
        self.dfs(root.left, depth + 1, root)
        self.dfs(root.right, depth + 1, root)
    
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        self.x = x
        self.y = y
        self.dfs(root, 0, None)
        return self.x_father != self.y_father and self.x_depth == self.y_depth

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/08/LeetCode%200993.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%A0%82%E5%85%84%E5%BC%9F%E8%8A%82%E7%82%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136078040](https://letmefly.blog.csdn.net/article/details/136078040)
