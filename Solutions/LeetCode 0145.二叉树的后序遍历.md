---
title: 145.二叉树的后序遍历
date: 2022-07-29 15:50:29
tags: [题解, LeetCode, 简单, 栈, 树, 深度优先搜索, 二叉树, DFS, 后序遍历]
---

# 【LetMeFly】145.二叉树的后序遍历：二叉树必会算法-递归/迭代(栈模拟递归)

力扣题目链接：[https://leetcode.cn/problems/binary-tree-postorder-traversal/](https://leetcode.cn/problems/binary-tree-postorder-traversal/)

<p>给你一棵二叉树的根节点 <code>root</code> ，返回其节点值的 <strong>后序遍历 </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg" style="width: 127px; height: 200px;" />
<pre>
<strong>输入：</strong>root = [1,null,2,3]
<strong>输出：</strong>[3,2,1]
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
	<li>树中节点的数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归算法很简单，你可以通过迭代算法完成吗？</p>


    
## 方法一：深度优先搜索DFS(递归)

在学习后序遍历之前，有必要先了解以下[前序遍历](https://blog.letmefly.xyz/2022/07/29/LeetCode%200144.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86/)

可以参考题解：[https://letmefly.blog.csdn.net/article/details/126057536](https://letmefly.blog.csdn.net/article/details/126057536)

后序遍历于前序遍历的不同之处在于，后序是先遍历左子树和右子树，再遍历根节点的值。

因此，我们只需要把前序遍历代码中遍历根节点的顺序，调整到遍历左右子树节点 之后即可。

前序遍历核心代码：

```cpp
// 先根再左右子
ans.push_back(root->val);
dfs(root->left);
dfs(root->right);
```

后续遍历核心代码：

```cpp
// 先左右子再根
dfs(root->left);
dfs(root->right);
ans.push_back(root->val);
```

同理，中序遍历核心代码：

```cpp
// 左子 根 右子
dfs(root->left);
ans.push_back(root->val);
dfs(root->right);
```

+ 时间复杂度$O(N)$，其中$N$是二叉树节点的个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<int> ans;

    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
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
        self.dfs(root.left)
        self.dfs(root.right)
        self.ans.append(root.val)
    
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
```

## 方法二：使用栈模拟递归（栈模拟递归）

使用栈模拟递归，具体做法可参考[94. 中序遍历](https://leetcode.letmefly.xyz/2024/02/10/LeetCode%200094.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86/#方法二：使用栈模拟递归（栈模拟递归）)

与之不同的是，出栈顺序应该是左子右子根，因此入栈顺序为根右子左子。

+ 时间复杂度$O(N)$，其中$N$是二叉树节点的个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});
        while (st.size()) {
            auto [thisNode, ifPushed] = st.top();
            st.pop();
            if (!thisNode) {
                continue;
            }
            if (ifPushed) {
                ans.push_back(thisNode->val);
            }
            else {
                st.push({thisNode, true});
                st.push({thisNode->right, false});
                st.push({thisNode->left, false});
            }
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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        st =  [(root, False)]
        while st:
            thisNode, ifPushed = st.pop()
            if not thisNode:
                continue
            if ifPushed:
                ans.append(thisNode.val)
            else:
                st.append((thisNode, True))
                st.append((thisNode.right, False))
                st.append((thisNode.left, False))
        return ans

```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/29/LeetCode%200145.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126057794](https://letmefly.blog.csdn.net/article/details/126057794)
