---
title: 429.N 叉树的层序遍历
date: 2024-02-17 10:47:59
tags: [题解, LeetCode, 中等, 树, 广度优先搜索, BFS, 层序遍历, 层次遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】429.N 叉树的层序遍历：广度优先搜索(BFS)

力扣题目链接：[https://leetcode.cn/problems/n-ary-tree-level-order-traversal/](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)

<p>给定一个 N 叉树，返回其节点值的<em>层序遍历</em>。（即从左到右，逐层遍历）。</p>

<p>树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,3,2,4,null,5,6]
<strong>输出：</strong>[[1],[3,2,4],[5,6]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png" style="width: 296px; height: 241px;" /></p>

<pre>
<strong>输入：</strong>root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
<strong>输出：</strong>[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树的高度不会超过 <code>1000</code></li>
	<li>树的节点总数在 <code>[0, 10^4]</code> 之间</li>
</ul>


    
## 方法一：广度优先搜索(BFS)

和之前[二叉树的广度优先搜索](https://blog.letmefly.xyz/2022/07/03/LeetCode%200102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/)一样，我们可以使用一个队列来存放每一层的节点，再让这些节点依次出队，并将节点的孩子们（如有）入队。

+ 时间复杂度$O(N)$，其中$N$是节点个数
+ 空间复杂度$O(N2)$，其中$N2$是节点最多的一层的节点数

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;
        if (root) {
            q.push(root);
        }
        while (q.size()) {
            ans.push_back({});
            for (int _ = q.size(); _ > 0; _--) {
                Node* thisNode = q.front();
                q.pop();
                ans.back().push_back(thisNode->val);
                for (Node* nextNode : thisNode->children) {
                    q.push(nextNode);
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List, Optional

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def levelOrder(self, root: Optional[Node]) -> List[List[int]]:
        ans = []
        q = []
        if root:
            q.append(root)
        while q:
            ans.append([])
            for _ in range(len(q)):
                thisNode = q[0]
                q = q[1:]
                ans[-1].append(thisNode.val)
                for nextNode in thisNode.children:
                    q.append(nextNode)
        return ans

```

针对于Python的语法糖，若使用两个数组可以很大程度上减少代码量（甚至提高效率）：

```python
# from typing import Optional, List

# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution:
    def levelOrder(self, root: Optional[Node]) -> List[List[int]]:
        ans = []
        a = []
        if root:
            a.append(root)
        while a:
            ans.append([thisNode.val for thisNode in a])
            a = [nextChild for thisNode in a for nextChild in thisNode.children]
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/17/LeetCode%200429.N%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136136336](https://letmefly.blog.csdn.net/article/details/136136336)
