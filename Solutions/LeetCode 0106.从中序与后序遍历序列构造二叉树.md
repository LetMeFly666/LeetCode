---
title: 106.从中序与后序遍历序列构造二叉树
date: 2024-02-21 09:56:20
tags: [题解, LeetCode, 中等, 树, 数组, 哈希表, 哈希, map, 递归, 分治, 二叉树]
---

# 【LetMeFly】106.从中序与后序遍历序列构造二叉树：分治（递归）——五彩斑斓的题解（若不是彩色的可以点击原文链接查看）

力扣题目链接：[https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

<p>给定两个整数数组 <code>inorder</code> 和 <code>postorder</code> ，其中 <code>inorder</code> 是二叉树的中序遍历， <code>postorder</code> 是同一棵树的后序遍历，请你构造并返回这颗&nbsp;<em>二叉树</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree.jpg" />
<pre>
<b>输入：</b>inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
<b>输出：</b>[3,9,20,null,null,15,7]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>inorder = [-1], postorder = [-1]
<b>输出：</b>[-1]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= inorder.length &lt;= 3000</code></li>
	<li><code>postorder.length == inorder.length</code></li>
	<li><code>-3000 &lt;= inorder[i], postorder[i] &lt;= 3000</code></li>
	<li><code>inorder</code>&nbsp;和&nbsp;<code>postorder</code>&nbsp;都由 <strong>不同</strong> 的值组成</li>
	<li><code>postorder</code>&nbsp;中每一个值都在&nbsp;<code>inorder</code>&nbsp;中</li>
	<li><code>inorder</code>&nbsp;<strong>保证</strong>是树的中序遍历</li>
	<li><code>postorder</code>&nbsp;<strong>保证</strong>是树的后序遍历</li>
</ul>


    
## 方法一：分治（递归）

类似于[从前序与中序建树](https://blog.letmefly.xyz/2024/02/20/LeetCode%200105.%E4%BB%8E%E5%89%8D%E5%BA%8F%E4%B8%8E%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91/)，我们知道：

+ 中序遍历：<font color='red'>左子树</font> <font color='gray'>根</font> <font color='blue'>右子树</font>
+ 后序遍历：<font color='red'>左子树</font> <font color='blue'>右子树</font> <font color='gray'>根</font>

写一个函数```dfs```接收```中序遍历数组```和```后序遍历数组```作为参数：

> 1. 根据```后序遍历数组```的最后一个元素为```根节点```建立节点
> 2. 找到```根节点```在```中序遍历数组```中的位置
>    > 以此可得到<font color='red'>左子树</font>和<font color='blue'>右子树</font>的长度信息
>    > 
>    > 以此可确定<font color='red'>左子树</font>和<font color='blue'>右子树</font>在两个数组中的位置
> 3. 递归建立<font color='red'>左子树</font>和<font color='blue'>右子树</font>

递归的终止条件为“中序遍历数组为空”，此时返回空节点。

**Tips:** 可以在预处理时建立一个哈希表，以便能快速地找到根节点在中序遍历数组中的位置。

+ 时间复杂度$O(N)$，其中$N$是节点个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<int, vector<int>::iterator> ma;

    TreeNode* dfs(vector<int>::iterator inLeft, vector<int>::iterator inRight, vector<int>::iterator postLeft, vector<int>::iterator postRight) {
        if (inLeft >= inRight) {
            return nullptr;
        }
        TreeNode* thisNode = new TreeNode(*(postRight - 1));
        vector<int>::iterator loc = ma[*(postRight - 1)];
        thisNode->left = dfs(inLeft, loc, postLeft, postLeft + (loc - inLeft));
        thisNode->right = dfs(loc + 1, inRight, postLeft + (loc - inLeft), postRight - 1);
        return thisNode;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (vector<int>::iterator it = inorder.begin(); it != inorder.end(); it++) {
            ma[*it] = it;
        }
        return dfs(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
```

#### Python

```python
# from typing import List, Optional

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, inorder: List[int], inLeft: int, inRight: int, postorder: List[int], postLeft: int, postRight: int) -> Optional[TreeNode]:
        if inLeft >= inRight:
            return None
        thisNode = TreeNode(postorder[postRight - 1])
        loc = self.ma[postorder[postRight - 1]]
        thisNode.left = self.dfs(inorder, inLeft, loc, postorder, postLeft, postLeft + (loc - inLeft))
        thisNode.right = self.dfs(inorder, loc + 1, inRight, postorder, postLeft + (loc - inLeft), postRight - 1)
        return thisNode
    
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        self.ma = dict()
        for i in range(len(inorder)):
            self.ma[inorder[i]] = i
        return self.dfs(inorder, 0, len(inorder), postorder, 0, len(postorder))
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/21/LeetCode%200106.%E4%BB%8E%E4%B8%AD%E5%BA%8F%E4%B8%8E%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136204741](https://letmefly.blog.csdn.net/article/details/136204741)
