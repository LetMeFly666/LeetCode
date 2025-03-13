---
title: 144.二叉树的前序遍历
date: 2022-07-29 15:41:51
tags: [题解, LeetCode, 简单, 栈, 树, 深度优先搜索, 二叉树, 前序遍历, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】144.二叉树的前序遍历：二叉树必会题-递归/迭代(栈模拟递归)

力扣题目链接：[https://leetcode.cn/problems/binary-tree-preorder-traversal/](https://leetcode.cn/problems/binary-tree-preorder-traversal/)

<p>给你二叉树的根节点 <code>root</code> ，返回它节点值的 <strong>前序</strong><em> </em>遍历。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="width: 202px; height: 324px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3]
<strong>输出：</strong>[1,2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 4：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg" style="width: 202px; height: 202px;" />
<pre>
<strong>输入：</strong>root = [1,2]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 5：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg" style="width: 202px; height: 202px;" />
<pre>
<strong>输入：</strong>root = [1,null,2]
<strong>输出：</strong>[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 <= Node.val <= 100</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>递归算法很简单，你可以通过迭代算法完成吗？</p>


    
## 方法一：深度优先搜索DFS(递归)

前序遍历的遍历顺序是：

```
根 → 左子树 → 右子树
```

这很明显地是个递归。

因此，我们可以构造一个```DFS```函数

```cpp
void DFS(TreeNode* root);
```

来处理以```root```为根时的遍历。

递归终止条件：```root```为空。

函数内容：

先遍历得到这个节点的值，然后递归左子树，再递归右子树。

+ 时间复杂度$O(N)$，其中$N$是二叉树节点的个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root)  // 递归终止条件
            return;
        ans.push_back(root->val);  // 先遍历得到这个节点的值
        dfs(root->left);  // 遍历左子树
        dfs(root->right);  // 遍历右子树
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);  // 前序遍历
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
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.ans.append(root.val)
        self.dfs(root.left)
        self.dfs(root.right)
    
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
```

## 方法二：使用栈模拟递归（栈模拟递归）

使用栈模拟递归，具体做法可参考[94. 中序遍历](https://leetcode.letmefly.xyz/2024/02/10/LeetCode%200094.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86/#方法二：使用栈模拟递归（栈模拟递归）)

与之不同的是，前序遍历需要存储的信息更少，因为遍历到当前节点后先处理当前节点才递归的。

因此，我们只需要将当前节点的右子、左子依次入栈即可。（出栈时为左子，右子）

+ 时间复杂度$O(N)$，其中$N$是二叉树节点的个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while (st.size()) {
            TreeNode* thisNode = st.top();
            st.pop();
            if (!thisNode) {
                continue;
            }
            ans.push_back(thisNode->val);
            st.push(thisNode->right);
            st.push(thisNode->left);
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
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        st = [root]
        while st:
            thisNode = st.pop()
            if not thisNode:
                continue
            ans.append(thisNode.val)
            st.append(thisNode.right)
            st.append(thisNode.left)
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/29/LeetCode%200144.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126057536](https://letmefly.blog.csdn.net/article/details/126057536)
