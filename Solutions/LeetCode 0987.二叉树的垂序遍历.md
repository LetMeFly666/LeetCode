---
title: 987.二叉树的垂序遍历
date: 2024-02-13 11:03:40
tags: [题解, LeetCode, 困难, 树, 深度优先搜索, 广度优先搜索, BFS, 哈希表, 二叉树]
---

# 【LetMeFly】987.二叉树的垂序遍历：遍历时存节点信息，遍历完自定义排序

力扣题目链接：[https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/](https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/)

<p>给你二叉树的根结点 <code>root</code> ，请你设计算法计算二叉树的<em> </em><strong>垂序遍历</strong> 序列。</p>

<p>对位于 <code>(row, col)</code> 的每个结点而言，其左右子结点分别位于 <code>(row + 1, col - 1)</code> 和 <code>(row + 1, col + 1)</code> 。树的根结点位于 <code>(0, 0)</code> 。</p>

<p>二叉树的 <strong>垂序遍历</strong> 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。如果同行同列上有多个结点，则按结点的值从小到大进行排序。</p>

<p>返回二叉树的 <strong>垂序遍历</strong> 序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/29/vtree1.jpg" style="width: 431px; height: 304px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[9],[3,15],[20],[7]]
<strong>解释：</strong>
列 -1 ：只有结点 9 在此列中。
列  0 ：只有结点 3 和 15 在此列中，按从上到下顺序。
列  1 ：只有结点 20 在此列中。
列  2 ：只有结点 7 在此列中。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/29/vtree2.jpg" style="width: 512px; height: 304px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,5,6,7]
<strong>输出：</strong>[[4],[2],[1,5,6],[3],[7]]
<strong>解释：</strong>
列 -2 ：只有结点 4 在此列中。
列 -1 ：只有结点 2 在此列中。
列  0 ：结点 1 、5 和 6 都在此列中。
          1 在上面，所以它出现在前面。
          5 和 6 位置都是 (2, 0) ，所以按值从小到大排序，5 在 6 的前面。
列  1 ：只有结点 3 在此列中。
列  2 ：只有结点 7 在此列中。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/29/vtree3.jpg" style="width: 512px; height: 304px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,4,6,5,7]
<strong>输出：</strong>[[4],[2],[1,5,6],[3],[7]]
<strong>解释：</strong>
这个示例实际上与示例 2 完全相同，只是结点 5 和 6 在树中的位置发生了交换。
因为 5 和 6 的位置仍然相同，所以答案保持不变，仍然按值从小到大排序。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中结点数目总数在范围 <code>[1, 1000]</code> 内</li>
	<li><code>0 <= Node.val <= 1000</code></li>
</ul>


    
## 方法一：遍历时存节点信息，遍历完自定义排序（以广度优先搜索为例）

[广度优先搜索(BFS)](https://leetcode.letmefly.xyz/tags/BFS/)相信大家都不陌生，因此我们可以二话不说将二叉树广搜一遍，在搜索过程中将所需要的信息计算并存下来，剩下的就是按照题目规则自定义排序了。

都需要哪些信息呢？需要“节点在哪一列”、“节点深度”、“节点值”。

遍历过程中将上述三元组存下来，遍历完成后依据这三个信息排序，作为答案并返回即可。

+ 时间复杂度$O(N\log N)$，其中$N$是二叉树中节点的个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<NodeInfo> q;  // [<node, <col, height>>, ...
        q.push({root, {0, 1}});
        vector<NodeInfo> v;
        while (q.size()) {
            NodeInfo thisNode = q.front();
            q.pop();
            v.push_back(thisNode);
            if (thisNode.first->left) {
                q.push({thisNode.first->left, {thisNode.second.first - 1, thisNode.second.second + 1}});
            }
            if (thisNode.first->right) {
                q.push({thisNode.first->right, {thisNode.second.first + 1, thisNode.second.second + 1}});
            }
        }
        sort(v.begin(), v.end(), [&](const NodeInfo& a, const NodeInfo& b) {
            return a.second == b.second ? a.first->val < b.first->val : a.second < b.second;
        });
        vector<vector<int>> ans;
        int lastCol = 1000000;
        for (NodeInfo& a : v) {
            if (a.second.first != lastCol) {
                lastCol = a.second.first;
                ans.push_back({});
            }
            ans.back().push_back(a.first->val);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        q = [(0, 0, root)]  # [(col, depth, node), ...
        v = []  # [(col, depth, val), ...]
        while q:
            thisCol, thisDepth, thisNode = q.pop()  # actually is't queue but a stack
            v.append((thisCol, thisDepth, thisNode.val))
            if thisNode.left:
                q.append((thisCol - 1, thisDepth + 1, thisNode.left))
            if thisNode.right:
                q.append((thisCol + 1, thisDepth + 1, thisNode.right))
        v.sort()
        ans = []
        lastCol = 100000
        for col, _, val in v:
            if col != lastCol:
                lastCol = col
                ans.append([])
            ans[-1].append(val)
        return ans

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/02/13/LeetCode%200987.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%9E%82%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136106019](https://letmefly.blog.csdn.net/article/details/136106019)
