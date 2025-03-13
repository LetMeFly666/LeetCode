---
title: 235.二叉搜索树的最近公共祖先
date: 2024-02-25 10:48:35
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 二叉搜索树, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】235.二叉搜索树的最近公共祖先：用搜索树性质（不遍历全部节点）

力扣题目链接：[https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/)

<p>给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。</p>

<p><a href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin" target="_blank">百度百科</a>中最近公共祖先的定义为：&ldquo;对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。&rdquo;</p>

<p>例如，给定如下二叉搜索树:&nbsp; root =&nbsp;[6,2,8,0,4,7,9,null,null,3,5]</p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png" style="height: 190px; width: 200px;"></p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>输出:</strong> 6 
<strong>解释: </strong>节点 <code>2 </code>和节点 <code>8 </code>的最近公共祖先是 <code>6。</code>
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>输出:</strong> 2
<strong>解释: </strong>节点 <code>2</code> 和节点 <code>4</code> 的最近公共祖先是 <code>2</code>, 因为根据定义最近公共祖先节点可以为节点本身。</pre>

<p>&nbsp;</p>

<p><strong>说明:</strong></p>

<ul>
	<li>所有节点的值都是唯一的。</li>
	<li>p、q 为不同节点且均存在于给定的二叉搜索树中。</li>
</ul>


    
## 方法一：用搜索树性质（不遍历全部节点）

需要注意的是，这道题给定的二叉树是二叉搜索树。因此对于某个节点```root```：

+ 如果```root.val > p.val```并且```root.val > q.val```，就说明```p```和```q```都在```root```的左子树上。令```root = root.left```。
+ 否则如果```root.val < p.val```并且```root.val < q.val```，就说明```p```和```q```都在```root```的右子树上。令```root = root.right```。
+ 否则，说明```p```和```q```在```root```的左右子树上或者就是```root```，```root```即为```p```和```q```的最近公共祖先。

以上。

+ 时间复杂度$O(N)$，其中$N$是二叉树节点个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {  // AC,83.74%,90.18%
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            else {
                return root;
            }
        }
    }
};
```

#### Python

```python
# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while True:
            if root.val < p.val and root.val < q.val:
                root = root.right
            elif root.val > p.val and root.val > q.val:
                root = root.left
            else:
                return root
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/25/LeetCode%200235.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136279915](https://letmefly.blog.csdn.net/article/details/136279915)
