---
title: 1038.从二叉搜索树到更大和树
date: 2023-12-04 14:05:40
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 二叉搜索树, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】1038.从二叉搜索树到更大和树：（反）中序遍历

力扣题目链接：[https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/](https://leetcode.cn/problems/binary-search-tree-to-greater-sum-tree/)

<p><span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">给定一个二叉搜索树</font></span></span></span></span>&nbsp;<code>root</code>&nbsp;(BST)<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">，请将它的每个</font></span></span></span></span>节点<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">的值替换成树中大于或者等于该</font></span></span></span></span>节点<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">值的所有</font></span></span></span></span>节点<span style="font-size:10.5pt"><span style="font-family:Calibri"><span style="font-size:10.5000pt"><span style="font-family:宋体"><font face="宋体">值之和。</font></span></span></span></span></p>

<p>提醒一下， <em>二叉搜索树</em> 满足下列约束条件：</p>

<ul>
	<li>节点的左子树仅包含键<strong> 小于 </strong>节点键的节点。</li>
	<li>节点的右子树仅包含键<strong> 大于</strong> 节点键的节点。</li>
	<li>左右子树也必须是二叉搜索树。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png" style="height:273px; width:400px" /></strong></p>

<pre>
<strong>输入：</strong>[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
<strong>输出：</strong>[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [0,null,1]
<strong>输出：</strong>[1,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在&nbsp;<code>[1, 100]</code>&nbsp;范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li>树中的所有值均 <strong>不重复</strong>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>该题目与 538:&nbsp;<a href="https://leetcode-cn.com/problems/convert-bst-to-greater-tree/">https://leetcode-cn.com/problems/convert-bst-to-greater-tree/&nbsp; </a>相同</p>


    
## 方法一：（反）中序遍历

二叉搜索树的中序遍历（```左子→根→右子```）得到的序列是非递减序列。反之，```右子→根→左子```得到的序列就是非递增序列。

“反中序遍历”的过程中，我们只需要使用一个遍历记录“当前所有遍历过的元素的和”，即为大于等于当前元素的所有元素的和。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点个数
+ 空间复杂度$O(n)$，最坏情况下二叉树退化成一条链，递归占用空间$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int last;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->right);
        last += root->val;
        root->val = last;
        dfs(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        last = 0;
        dfs(root);
        return root;
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
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.dfs(root.right)
        self.last += root.val
        root.val = self.last
        self.dfs(root.left)
    
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.last = 0
        self.dfs(root)
        return root
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/04/LeetCode%201038.%E4%BB%8E%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E5%88%B0%E6%9B%B4%E5%A4%A7%E5%92%8C%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134782862](https://letmefly.blog.csdn.net/article/details/134782862)
