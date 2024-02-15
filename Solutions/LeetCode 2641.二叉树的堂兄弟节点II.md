---
title: 2641.二叉树的堂兄弟节点 II
date: 2024-02-07 10:02:16
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 哈希表, 二叉树, 层次遍历, 层序遍历]
---

# 【LetMeFly】2641.二叉树的堂兄弟节点 II：层序遍历并记下兄弟节点

力扣题目链接：[https://leetcode.cn/problems/cousins-in-binary-tree-ii/](https://leetcode.cn/problems/cousins-in-binary-tree-ii/)

<p>给你一棵二叉树的根&nbsp;<code>root</code>&nbsp;，请你将每个节点的值替换成该节点的所有 <strong>堂兄弟节点值的和&nbsp;</strong>。</p>

<p>如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 <strong>堂兄弟</strong>&nbsp;。</p>

<p>请你返回修改值之后，树的根<em>&nbsp;</em><code>root</code><em>&nbsp;</em>。</p>

<p><strong>注意</strong>，一个节点的深度指的是从树根节点到这个节点经过的边数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/01/11/example11.png" style="width: 571px; height: 151px;" /></p>

<pre>
<b>输入：</b>root = [5,4,9,1,10,null,7]
<b>输出：</b>[0,0,0,7,7,null,11]
<b>解释：</b>上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 5 的节点没有堂兄弟，所以值修改为 0 。
- 值为 4 的节点没有堂兄弟，所以值修改为 0 。
- 值为 9 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 10 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 7 的节点有两个堂兄弟，值分别为 1 和 10 ，所以值修改为 11 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/01/11/diagram33.png" style="width: 481px; height: 91px;" /></p>

<pre>
<b>输入：</b>root = [3,1,2]
<b>输出：</b>[0,0,0]
<b>解释：</b>上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 3 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点没有堂兄弟，所以值修改为 0 。
- 值为 2 的节点没有堂兄弟，所以值修改为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目的范围是&nbsp;<code>[1, 10<sup>5</sup>]</code> 。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：层序遍历并记下兄弟节点

层序遍历很简单：

> 使用一个队列或数组（初始将根节点放入数组），在数组非空时：
>
> > 创建临时新数组并遍历数组中的所有节点，
> > 
> > 处理当前节点，将节点的子节（如有）放入新数组中。
> >
> > 遍历结束时，交换临时数组和上一个数组。

我们要做的修改是：

1. 将节点及其兄弟节点同时入队
1. 遍历某一层时，遍历两次。第一次统计这一层的元素之和、记录每个节点的值（后续可能会变化）、子节点放入新数组（如有）；第二次修改每个节点的值（$这层值的总和 - 当前节点值 - 兄弟节点值$）

最终返回根节点即可。

+ 时间复杂度$O(size(tree))$
+ 空间复杂度$O(\max size(layer))$

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<pair<TreeNode*, TreeNode*>> v = {{root, nullptr}, };  // [<thisNode, broNode>, ...]
        while (v.size()) {
            int valSum = 0;
            vector<pair<TreeNode*, TreeNode*>> nextV;
            unordered_map<TreeNode*, int> originalVal;
            for (auto&& [thisNode, broNode] : v) {
                originalVal[thisNode] = thisNode->val;
                valSum += thisNode->val;
                if (thisNode->left) {
                    nextV.push_back({thisNode->left, thisNode->right});
                }
                if (thisNode->right) {
                    nextV.push_back({thisNode->right, thisNode->left});
                }
            }
            for (auto&& [thisNode, broNode] : v) {
                thisNode->val = valSum - thisNode->val - originalVal[broNode];
            }
            swap(v, nextV);  // 这里不可：memmove(&v, &nextV, nextV.size());
        }
        return root;
    }
};
```

#### Python

```python
# from collections import defaultdict

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def replaceValueInTree(self, root: TreeNode) -> TreeNode:
        v = [(root, None)]
        while v:
            valSum = 0
            originalVal = defaultdict(int)
            nextV = []
            for thisNode, broNode in v:
                valSum += thisNode.val
                originalVal[thisNode] = thisNode.val
                if thisNode.left:
                    nextV.append((thisNode.left, thisNode.right))
                if thisNode.right:
                    nextV.append((thisNode.right, thisNode.left))
            for thisNode, broNode in v:
                thisNode.val = valSum - thisNode.val - originalVal[broNode]
            v = nextV
        return root
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/07/LeetCode%202641.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%A0%82%E5%85%84%E5%BC%9F%E8%8A%82%E7%82%B9II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136066230](https://letmefly.blog.csdn.net/article/details/136066230)
