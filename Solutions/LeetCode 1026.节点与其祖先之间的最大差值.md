---
title: 1026.节点与其祖先之间的最大差值
date: 2023-04-18 12:09:06
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】1026.节点与其祖先之间的最大差值

力扣题目链接：[https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/)

<p>给定二叉树的根节点 <code>root</code>，找出存在于 <strong>不同</strong> 节点 <code>A</code> 和 <code>B</code> 之间的最大值 <code>V</code>，其中 <code>V = |A.val - B.val|</code>，且 <code>A</code> 是 <code>B</code> 的祖先。</p>

<p>（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg" style="width: 400px; height: 390px;" /></p>

<pre>
<strong>输入：</strong>root = [8,3,10,1,6,null,14,null,null,4,7,13]
<strong>输出：</strong>7
<strong>解释： </strong>
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/09/tmp-tree-1.jpg" style="width: 250px; height: 349px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,null,0,3]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在 <code>2</code> 到 <code>5000</code> 之间。</li>
	<li><code>0 <= Node.val <= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：深度优先搜索DFS

有关[深度优先搜索](https://blog.letmefly.xyz/tags/DFS/)的题解有很多，本题也可以参考[二叉树的前序遍历的深度优先搜索的方式](https://blog.letmefly.xyz/2022/07/29/LeetCode%200144.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86/)进行求解。

在深度优先搜索的过程中，我们额外传递两个参数：分别是当前所有祖先节点的最大值 和 最小值。

这样，我们求出当前节点与最大值或最小值的绝对值之差，在所有节点的绝对值之差中，最大的那个即为答案。

+ 时间复杂度$O(节点个数)$
+ 空间复杂度$O(树的深度)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int ans = 0;

    void dfs(TreeNode* root, int M, int m) {
        if (!root) {
            return;
        }
        ans = max(ans, abs(root->val - M));
        ans = max(ans, abs(root->val - m));
        M = max(M, root->val);
        m = min(m, root->val);
        dfs(root->left, M, m);
        dfs(root->right, M, m);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
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
    def __init__(self) -> None:
        self.ans = 0
    
    def dfs(self, root: Optional[TreeNode], M: int, m: int) -> None:
        if not root:
            return
        self.ans = max(self.ans, abs(root.val - M), abs(root.val - m))
        M = max(M, root.val)
        m = min(m, root.val)
        self.dfs(root.left, M, m)
        self.dfs(root.right, M, m)

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, root.val, root.val)
        return self.ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/04/18/LeetCode%201026.%E8%8A%82%E7%82%B9%E4%B8%8E%E5%85%B6%E7%A5%96%E5%85%88%E4%B9%8B%E9%97%B4%E7%9A%84%E6%9C%80%E5%A4%A7%E5%B7%AE%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130218910](https://letmefly.blog.csdn.net/article/details/130218910)
