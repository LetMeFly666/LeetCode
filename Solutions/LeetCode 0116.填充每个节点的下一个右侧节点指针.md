---
title: 116.填充每个节点的下一个右侧节点指针
date: 2022-07-16 15:55:15
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 链表, 二叉树, 层序遍历, 完全二叉树]
---

# 【LetMeFly】116.填充每个节点的下一个右侧节点指针

力扣题目链接：[https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/)

<p>给定一个&nbsp;<strong>完美二叉树&nbsp;</strong>，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：</p>

<pre>
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}</pre>

<p>填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 <code>NULL</code>。</p>

<p>初始状态下，所有&nbsp;next 指针都被设置为 <code>NULL</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
 
<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="height: 171px; width: 500px;" /></p>

<pre>
<b>输入：</b>root = [1,2,3,4,5,6,7]
<b>输出：</b>[1,#,2,3,#,4,5,6,7,#]
<b>解释：</b>给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
</pre>

<p><meta charset="UTF-8" /></p>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>root = []
<b>输出：</b>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量在<meta charset="UTF-8" />&nbsp;<code>[0, 2<sup>12</sup>&nbsp;- 1]</code>&nbsp;范围内</li>
	<li><code>-1000 &lt;= node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你只能使用常量级额外空间。</li>
	<li>使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。</li>
</ul>


    
## 方法一：层次遍历

其实这道题只需要将二叉树**层序遍历**，然后遍历的同时记录一下上一个遍历到的节点是什么。

如果这个节点和上一个节点位于同一层，则将上一个节点的**next**指向这一个节点。

有关二叉树的层序遍历可以参考[LeetCode 102. 二叉树的层序遍历](https://leetcode.letmefly.xyz/2022/07/03/LeetCode%200102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/)

+ 时间复杂度$O(N)$，其中$N$是节点的个数
+ 空间复杂度$O(M)$，其中$M$是最后一层的节点的数量

### AC代码

#### C++

```cpp
typedef pair<Node*, int> pii;
class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        queue<pii> q;
        q.push({root, 1});
        int lastLayer = 0;
        Node* lastNode;
        while (q.size()) {
            auto[thisNode, thisLayer] = q.front();
            q.pop();
            if (thisLayer == lastLayer) {
                lastNode->next = thisNode;
            }
            lastNode = thisNode;
            lastLayer = thisLayer;
            if (thisNode->left)
                q.push({thisNode->left, thisLayer + 1});
            if (thisNode->right)
                q.push({thisNode->right, thisLayer + 1});
        }
        return root;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/16/LeetCode%200116.%E5%A1%AB%E5%85%85%E6%AF%8F%E4%B8%AA%E8%8A%82%E7%82%B9%E7%9A%84%E4%B8%8B%E4%B8%80%E4%B8%AA%E5%8F%B3%E4%BE%A7%E8%8A%82%E7%82%B9%E6%8C%87%E9%92%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125821076](https://letmefly.blog.csdn.net/article/details/125821076)
