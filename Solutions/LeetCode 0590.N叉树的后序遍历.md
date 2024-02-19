---
title: 590.N 叉树的后序遍历
date: 2024-02-19 12:27:50
tags: [题解, LeetCode, 简单, 栈, 树, 深度优先搜索, DFS]
---

# 【LetMeFly】590.N 叉树的后序遍历：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/n-ary-tree-postorder-traversal/](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/)

<p>给定一个 n&nbsp;叉树的根节点<meta charset="UTF-8" />&nbsp;<code>root</code>&nbsp;，返回 <em>其节点值的<strong> 后序遍历</strong></em> 。</p>

<p>n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 <code>null</code> 分隔（请参见示例）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="height: 193px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[5,6,3,2,4,1]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="height: 269px; width: 296px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[2,6,14,11,7,3,12,8,4,13,9,10,5,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>节点总数在范围 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>n 叉树的高度小于或等于 <code>1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>递归法很简单，你可以使用迭代法完成此题吗?</p>


    
## 方法一：深度优先搜索(DFS)

类似于[N叉树的前序遍历](https://blog.letmefly.xyz/2024/02/18/LeetCode%200589.N%E5%8F%89%E6%A0%91%E7%9A%84%E5%89%8D%E5%BA%8F%E9%81%8D%E5%8E%86/)，像正常的深度优先搜索一样，写一个函数来实现递归操作。这个函数接受一个节点作为参数：

> 首先依次递归遍历每一个子节点，接着将这个节点的值加入答案数组中。

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
        for (Node* nextNode : root->children) {
            dfs(nextNode);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if (root) {
            dfs(root);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List, Optional

# # Definition for a Node.
# class Node:
#     def __init__(self, val=None, children=None):
#         self.val = val
#         self.children = children

class Solution:
    def dfs(self, root: 'Node') -> None:
        for nextNode in root.children:
            self.dfs(nextNode)
        self.ans.append(root.val)
    
    def postorder(self, root: Optional['Node']) -> List[int]:
        self.ans = []
        if root:
            self.dfs(root)
        return self.ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/19/LeetCode%200590.N%E5%8F%89%E6%A0%91%E7%9A%84%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136167758](https://letmefly.blog.csdn.net/article/details/136167758)
