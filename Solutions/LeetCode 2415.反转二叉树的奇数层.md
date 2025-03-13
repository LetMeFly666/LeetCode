---
title: 2415.反转二叉树的奇数层
date: 2023-12-15 16:09:22
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 广度优先搜索, 二叉树, 完全二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】2415.反转二叉树的奇数层：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/](https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/)

<p>给你一棵 <strong>完美</strong> 二叉树的根节点 <code>root</code> ，请你反转这棵树中每个 <strong>奇数</strong> 层的节点值。</p>

<ul>
	<li>例如，假设第 3 层的节点值是 <code>[2,1,3,4,7,11,29,18]</code> ，那么反转后它应该变成 <code>[18,29,11,7,4,3,1,2]</code> 。</li>
</ul>

<p>反转后，返回树的根节点。</p>

<p><strong>完美</strong> 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。</p>

<p>节点的 <strong>层数</strong> 等于该节点到根节点之间的边数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/07/28/first_case1.png" style="width: 626px; height: 191px;" />
<pre>
<strong>输入：</strong>root = [2,3,5,8,13,21,34]
<strong>输出：</strong>[2,5,3,8,13,21,34]
<strong>解释：</strong>
这棵树只有一个奇数层。
在第 1 层的节点分别是 3、5 ，反转后为 5、3 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/07/28/second_case3.png" style="width: 591px; height: 111px;" />
<pre>
<strong>输入：</strong>root = [7,13,11]
<strong>输出：</strong>[7,11,13]
<strong>解释：</strong> 
在第 1 层的节点分别是 13、11 ，反转后为 11、13 。 
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
<strong>输出：</strong>[0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
<strong>解释：</strong>奇数层由非零值组成。
在第 1 层的节点分别是 1、2 ，反转后为 2、1 。
在第 3 层的节点分别是 1、1、1、1、2、2、2、2 ，反转后为 2、2、2、2、1、1、1、1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数目在范围 <code>[1, 2<sup>14</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>root</code> 是一棵 <strong>完美</strong> 二叉树</li>
</ul>


    
## 方法一：深度优先搜索(DFS)

这道题不要真的交换节点，因为交换节点会导致被交换节点的子节点顺序也发生变化。所谓“交换节点”，其实只需要“交换节点的值”即可。

不难发现，若某层需要发生交换，只需要“第1个节点跟最后一个节点换”、“第2个节点跟倒数第二个节点换”、...

因此写一个函数```dfs```，接收三个参数“节点1”、“节点2”、“是否需要交换”。在递归时，将“节点1的left 和 节点2的right”放到一起递归，“节点1的right 和 节点2的left”放到一起递归即可。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    void dfs(TreeNode* left, TreeNode* right, bool shouldReverse) {
        if (!left) {
            return ;
        }
        if (shouldReverse) {
            swap(left->val, right->val);
        }
        dfs(left->left, right->right, !shouldReverse);
        dfs(left->right, right->left, !shouldReverse);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
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
    def dfs(self, left: Optional[TreeNode], right: Optional[TreeNode], shouldReverse: bool) -> None:
        if not left:
            return
        if shouldReverse:
            left.val, right.val = right.val, left.val
        self.dfs(left.left, right.right, not shouldReverse)
        self.dfs(left.right, right.left, not shouldReverse)

    def reverseOddLevels(self, root: TreeNode) -> TreeNode:
        self.dfs(root.left, root.right, True)
        return root

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/15/LeetCode%202415.%E5%8F%8D%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%A5%87%E6%95%B0%E5%B1%82/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135020080](https://letmefly.blog.csdn.net/article/details/135020080)
