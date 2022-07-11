---
title: 112.路径总和
date: 2022-07-11 12:05:28
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, 二叉树, BFS]
---

# 【LetMeFly】112.路径总和：BFS + 更改节点的值

力扣题目链接：[https://leetcode.cn/problems/path-sum/](https://leetcode.cn/problems/path-sum/)

<p>给你二叉树的根节点&nbsp;<code>root</code> 和一个表示目标和的整数&nbsp;<code>targetSum</code> 。判断该树中是否存在 <strong>根节点到叶子节点</strong> 的路径，这条路径上所有节点值相加等于目标和&nbsp;<code>targetSum</code> 。如果存在，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p><strong>叶子节点</strong> 是指没有子节点的节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg" style="width: 500px; height: 356px;" />
<pre>
<strong>输入：</strong>root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
<strong>输出：</strong>true
<strong>解释：</strong>等于目标和的根节点到叶节点路径如上图所示。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg" />
<pre>
<strong>输入：</strong>root = [1,2,3], targetSum = 5
<strong>输出：</strong>false
<strong>解释：</strong>树中存在两条根节点到叶子节点的路径：
(1 --&gt; 2): 和为 3
(1 --&gt; 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [], targetSum = 0
<strong>输出：</strong>false
<strong>解释：</strong>由于树是空的，所以不存在根节点到叶子节点的路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[0, 5000]</code> 内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>


    
## 方法一：BFS + 更改节点的值

我们只需要BFS遍历一遍每个节点

同时，在遍历子节点的时候，直接将父节点的值加到子节点上

如果遍历到了叶子节点，并且叶子节点的值等于目标值，就返回true

全部遍历结束后，就返回false

+ 时间复杂度$O(N)$，其中$N$是节点的个数，我们只需要遍历一遍每个节点即可
+ 空间复杂度$O(N)$，注意这种方法修改了节点的原本的值。若题目要求不得修改原本的值，则在BSF的时候可以将节点和累计和（如```pair<TreeNode*, int>```）入队。但是空间复杂度不变。

### AC代码

#### C++

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (q.size()) {
            TreeNode* thisNode = q.front();
            q.pop();
            if (thisNode->val == targetSum && (!thisNode->left) && (!thisNode->right))
                return true;
            if (thisNode->left) {
                thisNode->left->val += thisNode->val;
                q.push(thisNode->left);
            }
            if (thisNode->right) {
                thisNode->right->val += thisNode->val;
                q.push(thisNode->right);
            }
        }
        return false;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/11/LeetCode%200112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125718939](https://letmefly.blog.csdn.net/article/details/125718939)
