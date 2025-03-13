---
title: 2583.二叉树中的第 K 大层和
date: 2024-02-23 10:21:43
tags: [题解, LeetCode, 中等, 树, 广度优先搜索, BFS, 层序遍历, 层次遍历, 二叉树, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2583.二叉树中的第 K 大层和：层序遍历 + 排序

力扣题目链接：[https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/](https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/)

<p>给你一棵二叉树的根节点 <code>root</code> 和一个正整数 <code>k</code> 。</p>

<p>树中的 <strong>层和</strong> 是指 <strong>同一层</strong> 上节点值的总和。</p>

<p>返回树中第 <code>k</code> 大的层和（不一定不同）。如果树少于 <code>k</code> 层，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong>，如果两个节点与根节点的距离相同，则认为它们在同一层。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/binaryytreeedrawio-2.png" style="width: 301px; height: 284px;" /></p>

<pre>
<strong>输入：</strong>root = [5,8,9,2,1,3,7,4,6], k = 2
<strong>输出：</strong>13
<strong>解释：</strong>树中每一层的层和分别是：
- Level 1: 5
- Level 2: 8 + 9 = 17
- Level 3: 2 + 1 + 3 + 7 = 13
- Level 4: 4 + 6 = 10
第 2 大的层和等于 13 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/12/14/treedrawio-3.png" style="width: 181px; height: 181px;" /></p>

<pre>
<strong>输入：</strong>root = [1,2,null,3], k = 1
<strong>输出：</strong>3
<strong>解释：</strong>最大的层和是 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数为 <code>n</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


    
## 方法一：层序遍历 + 排序

如果已经掌握了[二叉树的层序遍历](https://blog.letmefly.xyz/2022/07/03/LeetCode%200102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/)，那么这道题将会如鱼得水。

我们依然进行层序遍历，在层序遍历的过程中，计算每一层的节点值之和，并加入到一个数组中。

遍历结束后，对数组进行排序，返回第```k```大值或```-1```即可。

+ 时间复杂度$O(N1 + N2\log N2)$，其中$N1$是二叉树节点个数，$N2$是二叉树深度
+ 空间复杂度$O(N3 + N2)$，其中$N3$是最多一层的节点个数

时空复杂度也可以将全部的$N$都视为二叉树节点个数。

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> values;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            ll cnt = 0;
            for (int _ = q.size(); _ > 0; _--) {
                TreeNode* thisNode = q.front();
                q.pop();
                cnt += thisNode->val;
                if (thisNode->left) {
                    q.push(thisNode->left);
                }
                if (thisNode->right) {
                    q.push(thisNode->right);
                }
            }
            values.push_back(cnt);
        }
        sort(values.begin(), values.end());
        return k > values.size() ? -1 : values[values.size() - k];
    }
};
```

#### Python

注意本题数据级别是$10^5$，不能[使用数组切片模拟队列](https://gist.github.com/LetMeFly666/9b1fdc0bf38c80d6cbec70a74730d1da)的方式。

```python
# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthLargestLevelSum(self, root: TreeNode, k: int) -> int:
        values = []
        q = [root]
        while q:
            cnt = 0
            thisLayer = q
            q = []
            for thisNode in thisLayer:
                cnt += thisNode.val
                if thisNode.left:
                    q.append(thisNode.left)
                if thisNode.right:
                    q.append(thisNode.right)
            values.append(cnt)
        values.sort()
        return values[len(values) - k] if len(values) >= k else -1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/23/LeetCode%202583.%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E7%9A%84%E7%AC%ACK%E5%A4%A7%E5%B1%82%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136252010](https://letmefly.blog.csdn.net/article/details/136252010)
