---
title: 94.二叉树的中序遍历
date: 2024-02-10 11:37:39
tags: [题解, LeetCode, 简单, 栈, 树, 深度优先搜索, DFS, 二叉树, 递归]
categories: [题解, LeetCode]
---

# 【LetMeFly】94.二叉树的中序遍历：递归/迭代(栈模拟递归)

力扣题目链接：[https://leetcode.cn/problems/binary-tree-inorder-traversal/](https://leetcode.cn/problems/binary-tree-inorder-traversal/)

<p>给定一个二叉树的根节点 <code>root</code> ，返回 <em>它的 <strong>中序</strong>&nbsp;遍历</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="height: 200px; width: 125px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3]
<strong>输出：</strong>[1,3,2]
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

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶:</strong>&nbsp;递归算法很简单，你可以通过迭代算法完成吗？</p>


    
## 方法一：深度优先搜索DFS(递归)

写一个函数进行深搜：

函数接受一个节点作为参数，若节点为空则直接返回，否则递归左子节点，当前节点加入答案，递归右子节点。

从根节点开始使用上述函数递归，递归完成后返回答案。

+ 时间复杂度$O(size(tree))$
+ 空间复杂度$O(size(tree))$

更详细的描述可以参考[144. 前序遍历](https://leetcode.letmefly.xyz/2022/07/29/LeetCode%200144.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86/)

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root) {
            return ;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

#### Python

```python
# from typing import Optional, List

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
        self.dfs(root.left)
        self.ans.append(root.val)
        self.dfs(root.right)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
```

## 方法二：使用栈模拟递归（栈模拟递归）

递归过程中实际上是系统使用栈帮你存下了当前的信息，调用函数结束后恢复当前信息继续往下执行。因此我们使用栈模拟一下递归即可。

递归的时候都需要保存哪些信息呢？其实我们只需要保存```当前节点是什么```和```当前节点是否递归过(左)子节点```即可。

若是*第一次处理到这个节点*，则先将右子入栈，再将本节点再次入栈（并标记一下说左子节点入过栈了），最后将左子节点入栈。（这样出栈顺序将时左中右）

出栈时先看节点是否为空，为空直接返回。若左子节点入栈过了，则将当前节点值加入答案；否则（左子还未入栈），执行“第一次处理到这个节点”的操作。

+ 时间复杂度$O(size(tree))$
+ 空间复杂度$O(size(tree))$

使用栈模拟递归，时空复杂度都不变，但毕竟保存的信息变少了，将会更高效。

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> st;  // [<node, ifPushedChild>, ...
        st.push({root, false});
        while (st.size()) {
            auto [thisNode, ifPushedChild] = st.top();
            st.pop();
            if (!thisNode) {
                continue;
            }
            if (ifPushedChild) {
                ans.push_back(thisNode->val);
            }
            else {
                st.push({thisNode->right, false});
                st.push({thisNode, true});
                st.push({thisNode->left, false});
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import Optional, List

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        st = [(root, False)]
        while st:
            thisNode, ifPushedChild = st.pop()
            if not thisNode:
                continue
            if ifPushedChild:
                ans.append(thisNode.val)
            else:
                st.append((thisNode.right, False))
                st.append((thisNode, True))
                st.append((thisNode.left, False))
        return ans

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/10/LeetCode%200094.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136090242](https://letmefly.blog.csdn.net/article/details/136090242)
