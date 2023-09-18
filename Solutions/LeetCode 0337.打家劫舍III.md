---
title: 337.打家劫舍 III
date: 2022-09-27 09:20:38
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 动态规划, 二叉树, 树上dp]
---

# 【LetMeFly】337.打家劫舍 III

力扣题目链接：[https://leetcode.cn/problems/house-robber-iii/](https://leetcode.cn/problems/house-robber-iii/)

<p>小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;。</p>

<p>除了<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 <strong>两个直接相连的房子在同一天晚上被打劫</strong> ，房屋将自动报警。</p>

<p>给定二叉树的&nbsp;<code>root</code>&nbsp;。返回&nbsp;<em><strong>在不触动警报的情况下</strong>&nbsp;，小偷能够盗取的最高金额</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/rob1-tree.jpg" /></p>

<pre>
<strong>输入: </strong>root = [3,2,3,null,3,null,1]
<strong>输出:</strong> 7 
<strong>解释:</strong>&nbsp;小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7</pre>

<p><strong>示例 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/03/10/rob2-tree.jpg" /></p>

<pre>
<strong>输入: </strong>root = [3,4,5,1,3,null,1]
<strong>输出:</strong> 9
<strong>解释:</strong>&nbsp;小偷一晚能够盗取的最高金额 4 + 5 = 9
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li>树的节点数在&nbsp;<code>[1, 10<sup>4</sup>]</code> 范围内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：树上dp

对于二叉树的某个节点，我们尝试计算出“打劫这个节点”、“不打劫这个节点”的情况下，扫荡完 以这个节点为根节点的二叉树 所获总金额的最大值（记为state）。那么，根节点的state中，“打劫”或“不打劫”中较大的那个即为答案。

那么怎么确定以某个节点为根节点的二叉树中，打劫或不打劫根节点所能获得的最大值 呢？

很容易用递归实现。

+ 如果要打劫这个节点，那么这个节点的左子节点和右子节点都不能打劫，打劫这个根节点的前提下整棵二叉子树的最大获利值为“不打劫左子树的最大获利 + 不打劫右子树的最大获利 + 这个节点的值”
+ 如果不打劫这个节点，那么这个节点的左子节点和右子节点可以打劫，也可以不打劫。不打劫这个根节点的前提下整棵二叉子树的最大获利值为“左子树最大获利 + 右子树最大获利”

如果这个节点为空，那么最大获利就都是“0”

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    pair<int, int> chooseOrNot(TreeNode* root) {  // <选择，不选>节点root的情况下的最大打劫值
        if (!root)
            return {0, 0};
        pair<int, int> left = chooseOrNot(root->left);
        pair<int, int> right = chooseOrNot(root->right);
        return {left.second + right.second + root->val, max(left.first, left.second) + max(right.first, right.second)};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> state = chooseOrNot(root);
        return max(state.first, state.second);
    }
};
```

#### Python

```python
# from typing import List, Optional, Tuple

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> Tuple[int, int]:
        if not root:
            return 0, 0
        robleft, notleft = self.dfs(root.left)
        robright, notright = self.dfs(root.right)
        robthis = root.val + notleft + notright
        notthis = max(robleft, notleft) + max(robright, notright)
        return robthis, notthis
    
    def rob(self, root: List[TreeNode]) -> int:
        return max(self.dfs(root))
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/27/LeetCode%200337.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8DIII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127065525](https://letmefly.blog.csdn.net/article/details/127065525)
