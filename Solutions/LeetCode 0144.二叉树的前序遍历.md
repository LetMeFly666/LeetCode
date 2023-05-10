---
title: 144.二叉树的前序遍历
date: 2022-07-29 15:41:51
tags: [题解, LeetCode, 简单, 栈, 树, 深度优先搜索, 二叉树, 前序遍历, DFS]
---

# 【LetMeFly】144.二叉树的前序遍历：二叉树必会题

力扣题目链接：[https://leetcode.cn/problems/binary-tree-preorder-traversal/](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

<p>给你二叉树的根节点 <code>root</code> ，返回它节点值的 <strong>前序</strong><em> </em>遍历。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="width: 202px; height: 324px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3]
<strong>输出：</strong>[1,2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 4：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg" style="width: 202px; height: 202px;" />
<pre>
<strong>输入：</strong>root = [1,2]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 5：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg" style="width: 202px; height: 202px;" />
<pre>
<strong>输入：</strong>root = [1,null,2]
<strong>输出：</strong>[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 <= Node.val <= 100</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>递归算法很简单，你可以通过迭代算法完成吗？</p>


    
## 方法一：DFS

前序遍历的遍历顺序是：

```
根 → 左子树 → 右子树
```

这很明显地是个递归。

因此，我们可以构造一个```DFS```函数

```cpp
void DFS(TreeNode* root);
```

来处理以```root```为根时的遍历。

递归终止条件：```root```为空。

函数内容：

先遍历得到这个节点的值，然后递归左子树，再递归右子树。

+ 时间复杂度$O(N)$，其中$N$是二叉树节点的个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root)  // 递归终止条件
            return;
        ans.push_back(root->val);  // 先遍历得到这个节点的值
        dfs(root->left);  // 遍历左子树
        dfs(root->right);  // 遍历右子树
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);  // 前序遍历
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/29/LeetCode%200144.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126057536](https://letmefly.blog.csdn.net/article/details/126057536)
