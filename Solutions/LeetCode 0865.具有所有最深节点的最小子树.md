---
title: 865.具有所有最深节点的最小子树：深度优先搜索（一次DFS）
date: 2026-01-09 21:00:40
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 二叉树, 树]
categories: [题解, LeetCode]
---

# 【LetMeFly】865.具有所有最深节点的最小子树：深度优先搜索（一次DFS）

力扣题目链接：[https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/](https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/)

<p>给定一个根为&nbsp;<code>root</code>&nbsp;的二叉树，每个节点的深度是 <strong>该节点到根的最短距离</strong> 。</p>

<p>返回包含原始树中所有 <strong>最深节点</strong> 的 <em>最小子树</em> 。</p>

<p>如果一个节点在 <strong>整个树 </strong>的任意节点之间具有最大的深度，则该节点是 <strong>最深的</strong> 。</p>

<p>一个节点的 <strong>子树</strong> 是该节点加上它的所有后代的集合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png" style="width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4]
<strong>输出：</strong>[2,7,4]
<strong>解释：</strong>
我们返回值为 2 的节点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的节点。
注意，节点 5、3 和 2 包含树中最深的节点，但节点 2 的子树最小，因此我们返回它。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
<strong>解释：</strong>根节点是树中最深的节点。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0,1,3,null,2]
<strong>输出：</strong>[2]
<strong>解释：</strong>树中最深的节点为 2 ，有效子树为节点 2、1 和 0 的子树，但节点 2 的子树最小。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量在<meta charset="UTF-8" />&nbsp;<code>[1, 500]</code>&nbsp;范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 500</code></li>
	<li>每个节点的值都是 <strong>独一无二</strong> 的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与力扣 1123 重复：<a href="https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves/" target="_blank">https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves</a></p>


    
## 解题方法：DFS

思考在深度优先搜索过程中，搜索到节点`node`时，哪些情况下哪些节点会是以`node`为根的子树的答案。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2026-01-09 13:11:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2026-01-09 13:19:41
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef pair<TreeNode*, int> result;
class Solution {
private:
    result dfs(TreeNode* root) {
        result left = root->left ? dfs(root->left) : result{nullptr, 0};
        result right = root->right ? dfs(root->right) : result{nullptr, 0};
        TreeNode* node = left.second == right.second ? root : (left.second > right.second ? left.first : right.first);
        return {node, max(left.second, right.second) + 1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2026-01-09 20:55:06
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-09 20:58:21
'''
from typing import Optional, Tuple

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

empty_result = (None, 0)

class Solution:
    def dfs(self, root: TreeNode) -> Tuple[Optional[TreeNode], int]:
        left = self.dfs(root.left) if root.left else empty_result
        right = self.dfs(root.right) if root.right else empty_result
        return [root if left[1] == right[1] else left[0] if left[1] > right[1] else right[0], max(left[1], right[1]) + 1]

    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        return self.dfs(root)[0]
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/09/LeetCode%200865.%E5%85%B7%E6%9C%89%E6%89%80%E6%9C%89%E6%9C%80%E6%B7%B1%E8%8A%82%E7%82%B9%E7%9A%84%E6%9C%80%E5%B0%8F%E5%AD%90%E6%A0%91/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
