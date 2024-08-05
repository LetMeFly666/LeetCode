---
title: 2236.判断根结点是否等于子结点之和
date: 2023-08-20 09:11:19
tags: [题解, LeetCode, 简单, 树, 二叉树, 模拟]
---

# 【LetMeFly】2236.判断根结点是否等于子结点之和

力扣题目链接：[https://leetcode.cn/problems/root-equals-sum-of-children/](https://leetcode.cn/problems/root-equals-sum-of-children/)

<p>给你一个 <strong>二叉树 </strong>的根结点&nbsp;<code>root</code>，该二叉树由恰好&nbsp;<code>3</code>&nbsp;个结点组成：根结点、左子结点和右子结点。</p>

<p>如果根结点值等于两个子结点值之和，返回&nbsp;<code>true</code>&nbsp;，否则返回<em>&nbsp;</em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/08/graph3drawio.png" style="width: 281px; height: 199px;" />
<pre>
<strong>输入：</strong>root = [10,4,6]
<strong>输出：</strong>true
<strong>解释：</strong>根结点、左子结点和右子结点的值分别是 10 、4 和 6 。
由于 10 等于 4 + 6 ，因此返回 true 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/04/08/graph3drawio-1.png" style="width: 281px; height: 199px;" />
<pre>
<strong>输入：</strong>root = [5,3,1]
<strong>输出：</strong>false
<strong>解释：</strong>根结点、左子结点和右子结点的值分别是 5 、3 和 1 。
由于 5 不等于 3 + 1 ，因此返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树只包含根结点、左子结点和右子结点</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


    
## 方法一：模拟

判断$root.val$是否等于$root.left.val + root.right.val$。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool checkTree(TreeNode* root) {
        return root->val == root->left->val + root->right->val;
    }
};
```

#### Python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def checkTree(self, root: TreeNode) -> bool:
        return root.val == root.left.val + root.right.val
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/20/LeetCode%202236.%E5%88%A4%E6%96%AD%E6%A0%B9%E7%BB%93%E7%82%B9%E6%98%AF%E5%90%A6%E7%AD%89%E4%BA%8E%E5%AD%90%E7%BB%93%E7%82%B9%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132388754](https://letmefly.blog.csdn.net/article/details/132388754)
