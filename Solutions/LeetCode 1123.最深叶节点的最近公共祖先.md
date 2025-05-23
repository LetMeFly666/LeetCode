---
title: 1123.最深叶节点的最近公共祖先
date: 2023-09-06 22:56:17
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 广度优先搜索, 哈希表, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】1123.最深叶节点的最近公共祖先

力扣题目链接：[https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/](https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/)

<p>给你一个有根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;的二叉树，返回它&nbsp;<em>最深的叶节点的最近公共祖先</em>&nbsp;。</p>

<p>回想一下：</p>

<ul>
	<li><strong>叶节点</strong> 是二叉树中没有子节点的节点</li>
	<li>树的根节点的&nbsp;<strong>深度&nbsp;</strong>为&nbsp;<code>0</code>，如果某一节点的深度为&nbsp;<code>d</code>，那它的子节点的深度就是&nbsp;<code>d+1</code></li>
	<li>如果我们假定 <code>A</code> 是一组节点&nbsp;<code>S</code>&nbsp;的 <strong>最近公共祖先</strong>，<code>S</code>&nbsp;中的每个节点都在以 <code>A</code> 为根节点的子树中，且 <code>A</code>&nbsp;的深度达到此条件下可能的最大值。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png" style="height: 340px; width: 400px;" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4]
<strong>输出：</strong>[2,7,4]
<strong>解释：</strong>我们返回值为 2 的节点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的节点。
注意，节点 6、0 和 8 也是叶节点，但是它们的深度是 2 ，而节点 7 和 4 的深度是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
<strong>解释：</strong>根节点是树中最深的节点，它是它本身的最近公共祖先。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0,1,3,null,2]
<strong>输出：</strong>[2]
<strong>解释：</strong>树中最深的叶节点是 2 ，最近公共祖先是它自己。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数将在<meta charset="UTF-8" />&nbsp;<code>[1, 1000]</code>&nbsp;的范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li>每个节点的值都是&nbsp;<strong>独一无二</strong>&nbsp;的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与力扣 865 重复：<a href="https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes/">https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes/</a></p>


    
## 方法一：深度优先搜索(DFS)

们把最深的叶节点的最近公共祖先，称之为 $\textit{lca}$节点。

编写一个函数```dfs(root)```，返回以```root```为根的子树的```{lca, 深度}```。

+ 如果左子树更深，则返回```{左子的lac, 左子深度 + 1}```
+ 如果右子树更深，则返回```{右子的lac, 右子深度 + 1}```
+ 否则（左右子树深度相同），则返回```{root，左子深度 + 1}```

+ 时间复杂度$O(n)$，其中$n$为二叉树节点个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2023-09-06 22:43:49
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-09-06 22:49:44
 */
typedef pair<TreeNode*, int> pti;
class Solution {
private:
    pti dfs(TreeNode* root) {
        if (!root) {
            return {nullptr, 0};
        }
        pti left = dfs(root->left);
        pti right = dfs(root->right);
        if (left.second == right.second) {
            return {root, left.second + 1};
        }
        else if (left.second < right.second) {
            return {right.first, right.second + 1};
        }
        else {
            return {left.first, left.second + 1};
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-05 00:49:25
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-05 00:58:30
'''
from typing import Tuple, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> Tuple[Optional[TreeNode], int]:
        if not root:
            return (root, 0)
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        if left[1] > right[1]:
            return (left[0], left[1] + 1)
        elif left[1] < right[1]:
            return (right[0], right[1] + 1)
        return (root, left[1] + 1)
        
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.dfs(root)[0]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-05 00:59:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-05 01:03:59
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private Pair<TreeNode, Integer> dfs(TreeNode root) {
        if (root == null) {
            return new Pair<>(root, 0);
        }
        Pair<TreeNode, Integer> left = dfs(root.left);
        Pair<TreeNode, Integer> right = dfs(root.right);
        if (left.getValue() > right.getValue()) {
            return new Pair<>(left.getKey(), left.getValue() + 1);
        } else if (left.getValue() < right.getValue()) {
            return new Pair<>(right.getKey(), right.getValue() + 1);
        }
        return new Pair<>(root, left.getValue() + 1);
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).getKey();
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-05 01:05:07
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-05 01:11:09
 */
package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type pair struct{
    node *TreeNode
    depth int
}

func dfs(root* TreeNode) pair {
    if root == nil {
        return pair{root, 0}
    }
    left := dfs(root.Left)
    right := dfs(root.Right)
    if left.depth > right.depth {
        return pair{left.node, left.depth + 1}
    } else if left.depth < right.depth {
        return pair{right.node, right.depth + 1}
    }
    return pair{root, left.depth + 1}
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
    return dfs(root).node
}
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/06/LeetCode%201123.%E6%9C%80%E6%B7%B1%E5%8F%B6%E8%8A%82%E7%82%B9%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132725441](https://letmefly.blog.csdn.net/article/details/132725441)
