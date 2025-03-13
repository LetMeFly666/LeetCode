---
title: 1448.统计二叉树中好节点的数目
date: 2023-08-25 11:12:00
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】1448.统计二叉树中好节点的数目

力扣题目链接：[https://leetcode.cn/problems/count-good-nodes-in-binary-tree/](https://leetcode.cn/problems/count-good-nodes-in-binary-tree/)

<p>给你一棵根为&nbsp;<code>root</code>&nbsp;的二叉树，请你返回二叉树中好节点的数目。</p>

<p>「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/16/test_sample_1.png" style="height: 156px; width: 263px;"></strong></p>

<pre><strong>输入：</strong>root = [3,1,4,3,null,1,5]
<strong>输出：</strong>4
<strong>解释：</strong>图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -&gt; (3,4) 是路径中的最大值。
节点 5 -&gt; (3,4,5) 是路径中的最大值。
节点 3 -&gt; (3,1,3) 是路径中的最大值。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/16/test_sample_2.png" style="height: 161px; width: 157px;"></strong></p>

<pre><strong>输入：</strong>root = [3,3,null,4,2]
<strong>输出：</strong>3
<strong>解释：</strong>节点 2 -&gt; (3, 3, 2) 不是好节点，因为 &quot;3&quot; 比它大。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [1]
<strong>输出：</strong>1
<strong>解释：</strong>根节点是好节点。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树中节点数目范围是&nbsp;<code>[1, 10^5]</code>&nbsp;。</li>
	<li>每个节点权值的范围是&nbsp;<code>[-10^4, 10^4]</code>&nbsp;。</li>
</ul>


    
## 方法一：深度优先搜索（DFS）

给当前函数```goodNodes```添加一个默认值为“无穷小”的参数```parentMax```，用来记录当前节点的祖先节点中的最大值。

如果```root```为空，则返回0；

否则，更新```parentMax```为祖先节点和当前节点的最大值，并递归左右子即可。

+ 时间复杂度$O(n)$，其中$n$是二叉树的最大深度
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int goodNodes(TreeNode* root, int parentMax=-100000) {
        if (!root) {
            return 0;
        }
        int nowMax = max(parentMax, root->val);
        return (root->val >= parentMax) + goodNodes(root->left, nowMax) + goodNodes(root->right, nowMax);
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
    def goodNodes(self, root: Optional[TreeNode], parentMax=-100000) -> int:
        if not root:
            return 0
        nowMax = max(root.val, parentMax)
        return (root.val >= parentMax) + self.goodNodes(root.left, nowMax) + self.goodNodes(root.right, nowMax)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/08/25/LeetCode%201448.%E7%BB%9F%E8%AE%A1%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%A5%BD%E8%8A%82%E7%82%B9%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132491754](https://letmefly.blog.csdn.net/article/details/132491754)
