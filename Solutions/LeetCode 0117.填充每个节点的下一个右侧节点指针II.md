---
title: 117.填充每个节点的下一个右侧节点指针 II
date: 2022-07-17 10:03:42
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 链表, 二叉树, 层次遍历, 层序遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】117.填充每个节点的下一个右侧节点指针 II

力扣题目链接：[https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)

<p>给定一个二叉树</p>

<pre>
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}</pre>

<p>填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 <code>NULL</code>。</p>

<p>初始状态下，所有 next 指针都被设置为 <code>NULL</code>。</p>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你只能使用常量级额外空间。</li>
	<li>使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/02/15/117_sample.png" style="height: 218px; width: 640px;" /></p>

<pre>
<strong>输入</strong>：root = [1,2,3,4,5,null,7]
<strong>输出：</strong>[1,#,2,3,#,4,5,7,#]
<strong>解释：</strong>给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。序列化输出按层序遍历顺序（由 next 指针连接），'#' 表示每层的末尾。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数小于 <code>6000</code></li>
	<li><code>-100 <= node.val <= 100</code></li>
</ul>

<p> </p>

<ul>
</ul>


    
## 方法一：层次遍历

这道题和[LeetCode 116. 填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/) 几乎一模一样。

区别是[LeetCode0116](https://blog.letmefly.xyz/2022/07/16/LeetCode%200116.%E5%A1%AB%E5%85%85%E6%AF%8F%E4%B8%AA%E8%8A%82%E7%82%B9%E7%9A%84%E4%B8%8B%E4%B8%80%E4%B8%AA%E5%8F%B3%E4%BE%A7%E8%8A%82%E7%82%B9%E6%8C%87%E9%92%88/) 保证了二叉树为完全二叉树。

如果不考虑空间复杂度必须为$O(1)$的情况下，只使用层次遍历，那么这两道题的代码可以完全相同。

具体实现方法请参考[https://blog.letmefly.xyz/2022/07/16/LeetCode 0116.填充每个节点的下一个右侧节点指针](https://blog.letmefly.xyz/2022/07/16/LeetCode%200116.%E5%A1%AB%E5%85%85%E6%AF%8F%E4%B8%AA%E8%8A%82%E7%82%B9%E7%9A%84%E4%B8%8B%E4%B8%80%E4%B8%AA%E5%8F%B3%E4%BE%A7%E8%8A%82%E7%82%B9%E6%8C%87%E9%92%88/)

+ 时间复杂度$O(N)$，其中$N$是节点的个数
+ 空间复杂度$O(M)$，其中$M$是节点数最多的一层的节点的数量

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

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/17/LeetCode%200117.%E5%A1%AB%E5%85%85%E6%AF%8F%E4%B8%AA%E8%8A%82%E7%82%B9%E7%9A%84%E4%B8%8B%E4%B8%80%E4%B8%AA%E5%8F%B3%E4%BE%A7%E8%8A%82%E7%82%B9%E6%8C%87%E9%92%88II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125828883](https://letmefly.blog.csdn.net/article/details/125828883)
