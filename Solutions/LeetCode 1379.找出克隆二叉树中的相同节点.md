---
title: 1379.找出克隆二叉树中的相同节点
date: 2024-04-03 13:07:44
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】1379.找出克隆二叉树中的相同节点：二叉树遍历

力扣题目链接：[https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/](https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/)

<p>给你两棵二叉树，原始树 <code>original</code> 和克隆树 <code>cloned</code>，以及一个位于原始树 <code>original</code>&nbsp;中的目标节点&nbsp;<code>target</code>。</p>

<p>其中，克隆树 <code>cloned</code>&nbsp;是原始树 <code>original</code>&nbsp;的一个<strong> 副本 </strong>。</p>

<p>请找出在树&nbsp;<code>cloned</code>&nbsp;中，与&nbsp;<code>target</code>&nbsp;<strong>相同&nbsp;</strong>的节点，并返回对该节点的引用（在 C/C++ 等有指针的语言中返回 节点指针，其他语言返回节点本身）。</p>

<p>&nbsp;</p>

<p><strong>注意：</strong>你 <strong>不能</strong> 对两棵二叉树，以及 <code>target</code>&nbsp;节点进行更改。<strong>只能</strong> 返回对克隆树&nbsp;<code>cloned</code>&nbsp;中已有的节点的引用。</p>

<ul>
</ul>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e1.png" /></p>

<pre>
<strong>输入:</strong> tree = [7,4,3,null,null,6,19], target = 3
<strong>输出:</strong> 3
<strong>解释:</strong> 上图画出了树 original 和 cloned。target 节点在树 original 中，用绿色标记。答案是树 cloned 中的黄颜色的节点（其他示例类似）。</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e2.png" /></p>

<pre>
<strong>输入:</strong> tree = [7], target =  7
<strong>输出:</strong> 7
</pre>

<p><strong>示例 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/02/21/e3.png" /></p>

<pre>
<strong>输入:</strong> tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
<strong>输出:</strong> 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量范围为<meta charset="UTF-8" />&nbsp;<code>[1, 10<sup>4</sup>]</code>&nbsp;。</li>
	<li>同一棵树中，没有值相同的节点。</li>
	<li><code>target</code>&nbsp;节点是树&nbsp;<code>original</code>&nbsp;中的一个节点，并且不会是&nbsp;<code>null</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果树中允许出现值相同的节点，将如何解答？</p>


    
## 解题方法：二叉树遍历

这道题根被不需要管```original```树，只需要按照任意的方式遍历```cloned```树，并在遍历的过程中判断当前节点是否和```target```节点相同即可。

<details><summary>这里以（伪）广度优先搜索为例：</summary>

创建一个队列，队列中初始元素为```cloned```树的根节点。

之后开始不断地从队列中取出节点：

+ 如果当前节点和```target```的值相等，则直接返回该节点，算法结束。
+ 如果当前节点的左子节点非空，则将左子节点加入队列中。
+ 如果当前节点的右子节点非空，则将右子节点加入队列中。

</details>

+ 时间复杂度$O(N)$，其中$N$为二叉树节点个数。
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(cloned);
        while (true) {  // 一定会找到
            TreeNode* thisNode = q.front();
            q.pop();
            if (thisNode->val == target->val) {
                return thisNode;
            }
            if (thisNode->left) {
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                q.push(thisNode->right);
            }
        }
    }
};
```

#### Python

```python
# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        q = [cloned]
        while True:
            thisNode = q.pop()
            if thisNode.val == target.val:
                return thisNode
            if thisNode.left:
                q.append(thisNode.left)
            if thisNode.right:
                q.append(thisNode.right)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/03/LeetCode%201379.%E6%89%BE%E5%87%BA%E5%85%8B%E9%9A%86%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E7%9A%84%E7%9B%B8%E5%90%8C%E8%8A%82%E7%82%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137341930](https://letmefly.blog.csdn.net/article/details/137341930)
