---
title: 589.N 叉树的前序遍历
date: 2024-02-18 12:00:39
tags: [题解, LeetCode, 简单, 栈, 树, 深度优先搜索, DFS]
---

# 【LetMeFly】589.N 叉树的前序遍历：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/n-ary-tree-preorder-traversal/](https://leetcode.cn/problems/n-ary-tree-preorder-traversal/)

<p>给定一个 n&nbsp;叉树的根节点 <meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;，返回 <em>其节点值的<strong> 前序遍历</strong></em> 。</p>

<p>n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 <code>null</code> 分隔（请参见示例）。</p>

<p><br />
<strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="height: 193px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[1,3,5,6,2,4]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="height: 272px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点总数在范围<meta charset="UTF-8" />&nbsp;<code>[0, 10<sup>4</sup>]</code>内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>n 叉树的高度小于或等于 <code>1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归法很简单，你可以使用迭代法完成此题吗?</p>


    
## 方法一：深度优先搜索(DFS)

像正常的深度优先搜索一样，写一个函数来实现递归操作。这个函数接受一个节点作为参数：

> 首先将这个节点的值加入答案数组中，接着依次递归遍历每一个子节点。

从根节点开始调用这个函数后，最终返回答案数组即可。

+ 时间复杂度$O(N)$，其中$N$是节点个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<int> ans;

    void dfs(Node* root) {
        if (!root) {
            return;
        }
        ans.push_back(root->val);
        for (Node* nextNode : root->children) {
            dfs(nextNode);
        }
    }
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};
```

#### Python

```python
# from typing import Optional, List

# # Definition for a Node.
# class Node:
#     def __init__(self, val=None, children=None):
#         self.val = val
#         self.children = children

class Solution:
    def dfs(self, root: Optional['Node']) -> None:
        if not root:
            return
        self.ans.append(root.val)
        for nextChild in root.children:
            self.dfs(nextChild)
    
    def preorder(self, root: Optional['Node']) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/18/LeetCode%200589.N%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136149332](https://letmefly.blog.csdn.net/article/details/136149332)
