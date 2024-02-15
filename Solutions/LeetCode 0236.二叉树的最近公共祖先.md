---
title: 236.二叉树的最近公共祖先
date: 2022-09-09 14:42:04
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 二叉树, 位运算]
---

# 【LetMeFly】236.二叉树的最近公共祖先：深度优先搜索（巧用位运算）

力扣题目链接：[https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

<p>给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。</p>

<p><a href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin" target="_blank">百度百科</a>中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。”</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
<strong>输出：</strong>3
<strong>解释：</strong>节点 <code>5 </code>和节点 <code>1 </code>的最近公共祖先是节点 <code>3 。</code>
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;" />
<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
<strong>输出：</strong>5
<strong>解释：</strong>节点 <code>5 </code>和节点 <code>4 </code>的最近公共祖先是节点 <code>5 。</code>因为根据定义最近公共祖先节点可以为节点本身。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2], p = 1, q = 2
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[2, 10<sup>5</sup>]</code> 内。</li>
	<li><code>-10<sup>9</sup> <= Node.val <= 10<sup>9</sup></code></li>
	<li>所有 <code>Node.val</code> <code>互不相同</code> 。</li>
	<li><code>p != q</code></li>
	<li><code>p</code> 和 <code>q</code> 均存在于给定的二叉树中。</li>
</ul>


    
## 方法一：深搜确定路径，然后匹配

定义一个函数进行深搜，如果搜索到待寻找元素就返回当前节点到寻找节点的路径，否则就返回“空”

```cpp
vector<TreeNode*> dfs(TreeNode* root, TreeNode* finding) {
	如果当前节点为空，就返回空数组
	如果当前节点就是待搜索元素，就返回{当前元素}

	对左子树进行搜索，如果左子树中找到了代寻找节点（不空），就返回“左子到待寻找元素的路径 + 这个点”
	右子树同理

	左右子树都找不到，就返回空数组
}
```

这样，我们就可以确定根节点到第一个待寻找节点的路径，也可以确定根节点到第二个待寻找节点的路径。

将第一个路径用哈希表存起来，第二个路径从待寻找元素往根节点遍历，第一个存在于哈希表中的元素就是两个节点的最近公共祖先。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    /*
        如果找到finding，就返回当前到finding的路径
        否则就返回空数组
    */
    vector<TreeNode*> dfs(TreeNode* root, TreeNode* finding) {
        if (!root)
            return {};
        if (root == finding)
            return {finding};
        vector<TreeNode*> left = dfs(root->left, finding);
        if (left.size()) {
            left.push_back(root);
            return left;
        }
        vector<TreeNode*> right = dfs(root->right, finding);
        if (right.size()) {
            right.push_back(root);
            return right;
        }
        return {};
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP = dfs(root, p);
        vector<TreeNode*> pathQ = dfs(root, q);
        unordered_set<TreeNode*> se;
        for (auto& thisNode : pathP) {
            se.insert(thisNode);
        }
        for (auto& thisNode : pathQ) {
            if (se.count(thisNode)) {
                return thisNode;
            }
        }
        return nullptr;  // FakeReturn
    }
};
```

## 方法二：：深度优先搜索 + 巧用位运算

正常深搜（DFS），深搜过程中使用一个“状态”表示“当前节点及其子节点中PQ的存在情况”。

这样，第一个满足$状态=PQ都存在$的节点就是要找的答案（最近公共祖先）。

**怎么表示“状态”呢？**

可以使用二进制（位运算），用一个二进制位表示子树中是否有节点p和节点q，例如：

+ 0($00_2$)表示PQ都不存在
+ 1($01_2$)表示P存在Q不存在
+ 2($10_2$)表示P不存在Q存在
+ 3($11_2$)表示PQ都存在

这样，$当前节点状态 | 左子树状态 | 右子树状态$即为$当前子树状态$（其中$|$为或运算）

### AC代码

#### C++

```cpp
typedef int Status;  // 一个二进制位表示子树中是否有节点p和节点q
#define NONE 0
#define ONLYP 1
#define ONLYQ 2
#define BOTH 3

class Solution {
private:
    TreeNode* ans;

    Status dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NONE;
        }
        Status thisStatus = NONE;
        if (root == p) {
            thisStatus |= ONLYP;
        }
        if (root == q) {
            thisStatus |= ONLYQ;
        }
        thisStatus |= dfs(root->left, p, q) | dfs(root->right, p, q);
        if (thisStatus == BOTH && !ans) {
            ans = root;
        }
        return thisStatus;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        dfs(root, p, q);
        return ans;
    }
};
```

#### Python

```python
# # AC,93.83%,86.17%
# from typing import Optional

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Status:
    none = 0
    onlyP = 1
    onlyQ = 2
    both = 3

class Solution:
    def dfs(self, root: Optional[TreeNode], p: 'TreeNode', q: 'TreeNode') -> Status:
        if not root:
            return Status.none
        thisStatus = Status.none
        if root == p:
            thisStatus |= Status.onlyP
        if root == q:
            thisStatus |= Status.onlyQ
        thisStatus |= self.dfs(root.left, p, q) | self.dfs(root.right, p, q)
        if thisStatus == Status.both and not self.ans:
            self.ans = root
        return thisStatus
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ans = None
        self.dfs(root, p, q)
        return self.ans

```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/09/LeetCode%200236.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126782886](https://letmefly.blog.csdn.net/article/details/126782886)
