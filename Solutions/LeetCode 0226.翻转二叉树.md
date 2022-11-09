---
title: 226.翻转二叉树
date: 2022-09-06 13:11:09
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, 二叉树, BFS]
---

# 【LetMeFly】226.翻转二叉树

力扣题目链接：[https://leetcode.cn/problems/invert-binary-tree/](https://leetcode.cn/problems/invert-binary-tree/)

<p>给你一棵二叉树的根节点 <code>root</code> ，翻转这棵二叉树，并返回其根节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg" style="height: 165px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>root = [4,2,7,1,3,6,9]
<strong>输出：</strong>[4,7,2,9,6,3,1]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg" style="width: 500px; height: 120px;" /></p>

<pre>
<strong>输入：</strong>root = [2,1,3]
<strong>输出：</strong>[2,3,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目范围在 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


    
## 方法一：广搜

使用一个队列

首先将根节点入队，每次出队时，先记录下原始的左右节点，之后交换当前节点的左右节点。

如果左或右节点不空，就入队。

直到队列为空。

+ 时间复杂度$O(n)$，其中$n$是节点个数
+ 空间复杂度$O(n)$，空间复杂度来自队列

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            TreeNode* left = thisNode->left;
            TreeNode* right = thisNode->right;
            thisNode->left = right, thisNode->right = left;
            if (left)
                q.push(left);
            if (right)
                q.push(right);
        }
        return root;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/06/LeetCode%200226.%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/](https://letmefly.blog.csdn.net/article/details/)
