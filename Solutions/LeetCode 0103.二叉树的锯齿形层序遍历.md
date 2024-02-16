---
title: 103.二叉树的锯齿形层序遍历
date: 2024-02-16 10:50:09
tags: [题解, LeetCode, 中等, 树, 广度优先搜索, BFS, 二叉树, 层序遍历, 层次遍历]
---

# 【LetMeFly】103.二叉树的锯齿形层序遍历：层序遍历 + 适时翻转

力扣题目链接：[https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/)

<p>给你二叉树的根节点 <code>root</code> ，返回其节点值的 <strong>锯齿形层序遍历</strong> 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[3],[20,9],[15,7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[[1]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


    
## 方法一：层序遍历 + 适时翻转

### 前言

相信大家已经做过关于[层序遍历](https://blog.letmefly.xyz/tags/%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86/)的练习了，没有做过的建议先做一做，可以参考这篇题解：[LeetCode 102.二叉树的层序遍历 + 针对C++的使用空间优化 （可能不同于常规做法）](https://blog.letmefly.xyz/2022/07/03/LeetCode%200102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/)

### 思路

这道题与之不同的是，每隔一层需要变化一下遍历方向。

真的要变换遍历方向吗？其实不然：

> 我们只需要在正常遍历的基础上使用一个变量来记录当前这一层是否需要翻转，若需翻转则在这一层遍历结束后reverse一下最后一层即可。

+ 时间复杂度$O(N)$，其中$N$是节点个数
+ 空间复杂度$O(N2)$，其中$N2$是节点最多的一层的节点数

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool ifReverse = false;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (q.size()) {
            ans.push_back({});
            for (int _ = q.size(); _ > 0; _--) {
                TreeNode* thisNode = q.front();
                q.pop();
                ans.back().push_back(thisNode->val);
                if (thisNode->left) {
                    q.push(thisNode->left);
                }
                if (thisNode->right) {
                    q.push(thisNode->right);
                }
            }
            if (ifReverse) {
                reverse(ans.back().begin(), ans.back().end());
            }
            ifReverse = !ifReverse;
        }
        return ans;
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
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        ifReverse = False
        q = []
        if root:
            q.append(root)
        while q:
            ans.append([])
            for _ in range(len(q)):
                thisNode = q[0]
                q = q[1:]
                ans[-1].append(thisNode.val)
                if thisNode.left:
                    q.append(thisNode.left)
                if thisNode.right:
                    q.append(thisNode.right)
            if ifReverse:
                ans[-1].reverse()
            ifReverse = not ifReverse
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/16/LeetCode%200103.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%94%AF%E9%BD%BF%E5%BD%A2%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136126902](https://letmefly.blog.csdn.net/article/details/136126902)
