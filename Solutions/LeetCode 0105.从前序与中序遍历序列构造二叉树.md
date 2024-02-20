---
title: 105.从前序与中序遍历序列构造二叉树
date: 2024-02-20 11:21:23
tags: [题解, LeetCode, 中等, 树, 数组, 哈希表, 哈希, map, 递归, 分治, 二叉树]
---

# 【LetMeFly】105.从前序与中序遍历序列构造二叉树：分治（递归）——五彩斑斓的题解（若不是彩色的可以点击原文链接查看）

力扣题目链接：[https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

<p>给定两个整数数组&nbsp;<code>preorder</code> 和 <code>inorder</code>&nbsp;，其中&nbsp;<code>preorder</code> 是二叉树的<strong>先序遍历</strong>， <code>inorder</code>&nbsp;是同一棵树的<strong>中序遍历</strong>，请构造二叉树并返回其根节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" style="height: 302px; width: 277px;" />
<pre>
<strong>输入</strong><strong>:</strong> preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
<strong>输出:</strong> [3,9,20,null,null,15,7]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> preorder = [-1], inorder = [-1]
<strong>输出:</strong> [-1]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 3000</code></li>
	<li><code>inorder.length == preorder.length</code></li>
	<li><code>-3000 &lt;= preorder[i], inorder[i] &lt;= 3000</code></li>
	<li><code>preorder</code>&nbsp;和&nbsp;<code>inorder</code>&nbsp;均 <strong>无重复</strong> 元素</li>
	<li><code>inorder</code>&nbsp;均出现在&nbsp;<code>preorder</code></li>
	<li><code>preorder</code>&nbsp;<strong>保证</strong> 为二叉树的前序遍历序列</li>
	<li><code>inorder</code>&nbsp;<strong>保证</strong> 为二叉树的中序遍历序列</li>
</ul>


    
## 方法一：分治（递归）

+ 前序遍历：<font color='gray'>根</font> <font color='red'>左子树</font> <font color='blue'>右子树</font>
+ 中序遍历：<font color='red'>左子树</font> <font color='gray'>根</font> <font color='blue'>右子树</font>

写一个函数```dfs```接收```前序遍历数组```和```中序遍历数组```作为参数：

> 1. 根据```前序遍历数组```的第一个元素为```根节点```建立节点
> 2. 找到```根节点```在中序遍历数组中的位置
>    > 以此可得到左子树和右子树的长度信息
>    > 
>    > 以此可确定<font color='red'>左子树</font>和<font color='blue'>右子树</font>在两个数组中的位置
> 3. 递归建立左子树和右子树

递归的终止条件为“前序遍历数组为空”，此时返回空节点。

**Tips:** 可以在预处理时建立一个哈希表，以便能快速地找到根节点在中序遍历数组中的位置。

+ 时间复杂度$O(N)$，其中$N$是节点个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<int, vector<int>::iterator> ma;

    TreeNode* dfs(vector<int>::iterator preLeft, vector<int>::iterator preRight, vector<int>::iterator inLeft, vector<int>::iterator inRight) {
        if (preRight <= preLeft) {
            return nullptr;
        }
        TreeNode* thisNode = new TreeNode(*preLeft);
        vector<int>::iterator loc = ma[*preLeft];
        int leftLength = loc - inLeft;
        thisNode->left = dfs(preLeft + 1, preLeft + leftLength + 1, inLeft, loc);
        thisNode->right = dfs(preLeft + leftLength + 1, preRight, loc + 1, inRight);
        return thisNode;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); it++) {
            ma[*it] = it;
        }
        return dfs(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
```

#### Python

```python
from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:  # AC,98.61%,91.88%
    def dfs(self, preLeft: int, preRight: int, inLeft: int, inRight: int) -> Optional[TreeNode]:
        if preRight <= preLeft:
            return None
        thisNode = TreeNode(self.preorder[preLeft])
        loc = self.ma[self.preorder[preLeft]]
        leftLength = loc - inLeft
        thisNode.left = self.dfs(preLeft + 1, preLeft + leftLength + 1, inLeft, loc - 1)
        thisNode.right = self.dfs(preLeft + leftLength + 1, preRight, loc + 1, inRight)
        return thisNode
    
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.preorder = preorder
        self.inorder = inorder
        self.ma = dict()
        for i in range(len(inorder)):
            self.ma[inorder[i]] = i
        return self.dfs(0, len(preorder), 0, len(inorder))
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/20/LeetCode%200105.%E4%BB%8E%E5%89%8D%E5%BA%8F%E4%B8%8E%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136186356](https://letmefly.blog.csdn.net/article/details/136186356)
