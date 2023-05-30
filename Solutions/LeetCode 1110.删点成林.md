---
title: 1110.删点成林
date: 2023-05-30 09:04:53
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 二叉树]
---

# 【LetMeFly】1110.删点成林

力扣题目链接：[https://leetcode.cn/problems/delete-nodes-and-return-forest/](https://leetcode.cn/problems/delete-nodes-and-return-forest/)

<p>给出二叉树的根节点&nbsp;<code>root</code>，树上每个节点都有一个不同的值。</p>

<p>如果节点值在&nbsp;<code>to_delete</code>&nbsp;中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。</p>

<p>返回森林中的每棵树。你可以按任意顺序组织答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/07/05/screen-shot-2019-07-01-at-53836-pm.png" style="height: 150px; width: 237px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4,5,6,7], to_delete = [3,5]
<strong>输出：</strong>[[1,2,null,4],[6],[7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2,4,null,3], to_delete = [3]
<strong>输出：</strong>[[1,2,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数最大为&nbsp;<code>1000</code>。</li>
	<li>每个节点都有一个介于&nbsp;<code>1</code> 到&nbsp;<code>1000</code>&nbsp;之间的值，且各不相同。</li>
	<li><code>to_delete.length &lt;= 1000</code></li>
	<li><code>to_delete</code> 包含一些从&nbsp;<code>1</code> 到&nbsp;<code>1000</code>、各不相同的值。</li>
</ul>


    
## 方法一：深度优先搜索DFS

写一个函数dfs(root)，返回root节点是否需要保留，并递归判断root的左右子是否需要保留。

+ 如果root不需要保留，但左右子中有需要保留的，则需要保留的字节的将称为新的根节点（加入到答案的根节点数组中）。
+ 否则（root需要保留），如果root的子节点不需要保留，则修改root的子节点为空。

就可以了。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<TreeNode*> ans;
    unordered_set<int> toDelete;

    bool dfs(TreeNode* root) {  // 是否需要保留root
        if (!root) {
            return false;
        }
        bool keepLeft = dfs(root->left);
        bool keepRight = dfs(root->right);
        if (toDelete.count(root->val)) {  // 删root
            if (keepLeft) {
                ans.push_back(root->left);
            }
            if (keepRight) {
                ans.push_back(root->right);
            }
            // delete root;
            return false;
        }
        else {
            root->left = keepLeft ? root->left : nullptr;
            root->right = keepRight ? root->right : nullptr;
            return true;
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int t : to_delete) {
            toDelete.insert(t);
        }
        if (dfs(root)) {
            ans.push_back(root);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import Optional, List

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return False
        keepLeft = self.dfs(root.left)
        keepRight = self.dfs(root.right)
        if root.val in self.toDelete:  # 删root
            if keepLeft:
                self.ans.append(root.left)
            if keepRight:
                self.ans.append(root.right)
            return False
        else:
            root.left = root.left if keepLeft else None
            root.right = root.right if keepRight else None
            return True
    
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        self.ans = []
        self.toDelete = set()
        for t in to_delete:
            self.toDelete.add(t)
        if self.dfs(root):
            self.ans.append(root)
        return self.ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/30/LeetCode%201110.%E5%88%A0%E7%82%B9%E6%88%90%E6%9E%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130941100](https://letmefly.blog.csdn.net/article/details/130941100)
