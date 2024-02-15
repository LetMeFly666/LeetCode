---
title: 114.二叉树展开为链表
date: 2022-07-12 13:38:55
tags: [题解, LeetCode, 中等, 栈, 树, 深度优先搜索, 链表, 二叉树, 前序遍历, 巧]
---

# 【LetMeFly】114.二叉树展开为链表：两种方法（简单粗暴/十分巧妙）

力扣题目链接：[https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

<p>给你二叉树的根结点 <code>root</code> ，请你将它展开为一个单链表：</p>

<ul>
	<li>展开后的单链表应该同样使用 <code>TreeNode</code> ，其中 <code>right</code> 子指针指向链表中下一个结点，而左子指针始终为 <code>null</code> 。</li>
	<li>展开后的单链表应该与二叉树 <a href="https://baike.baidu.com/item/%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86/6442839?fr=aladdin" target="_blank"><strong>先序遍历</strong></a> 顺序相同。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg" style="width: 500px; height: 226px;" />
<pre>
<strong>输入：</strong>root = [1,2,5,3,4,null,6]
<strong>输出：</strong>[1,null,2,null,3,null,4,null,5,null,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0]
<strong>输出：</strong>[0]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中结点数在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-100 <= Node.val <= 100</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你可以使用原地算法（<code>O(1)</code> 额外空间）展开这棵树吗？</p>


    
## 方法一：简单粗暴

二叉树的前序遍历大家都会吧（可以参考[114. 二叉树展开为链表](https://leetcode.cn/problems/binary-tree-preorder-traversal/)）

那么一个简单粗暴的方法就是：

完全不基于原本的树，而是重新建立一棵树。

在前序遍历的过程中，把遍历到的节点作为新节点添加到新树里面即可。

+ 时间复杂度$O(n)$，其中$n$是节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    TreeNode* head;  // 新树的空的头节点
    TreeNode* p;  // 新树的当前的最后一个节点

    void addVal(int n) {  // 把“值n”添加到新树中
        p->right = new TreeNode(n);
        p = p->right;
    }

    void dfs(TreeNode* root) {  // 前序遍历
        if (!root)
            return;
        addVal(root->val);  // 加到新树中
        dfs(root->left);
        dfs(root->right);
    }
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        head = new TreeNode;  // 新树
        p = head;
        dfs(root);  // 前序遍历
        *root = *(head->right);  // 强制改值
    }
};
```

## 方法二：十分巧妙

方法一虽然简单粗暴，但是不够完美。

最完美的方法就是在原树的基础上进行修改，不产生额外的节点。

具体办法是：

从根节点$root$开始，在$root$不为空的时候：

如果$root$存在左节点$left$，就把$root的右节点$添加到$left的最右节点的右子处$，然后把$root->right$置为$left$，并把$root->left$置空，最后用$root->right$更新$root$即可。

LeetCode官方题解有一个不错的图，大家可以参考[LeetCode官方题解的方法三](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solution/er-cha-shu-zhan-kai-wei-lian-biao-by-leetcode-solu/#%E6%96%B9%E6%B3%95%E4%B8%89%EF%BC%9A%E5%AF%BB%E6%89%BE%E5%89%8D%E9%A9%B1%E8%8A%82%E7%82%B9)

+ 时间复杂度$O(n)$，其中$n$是节点的个数
+ 空间复杂度$O(1)$，是不是非常漂亮！

### AC代码

#### C++

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* left4mostright = root->left;
                while (left4mostright->right)
                    left4mostright = left4mostright->right;
                left4mostright->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/12/LeetCode%200114.%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%95%E5%BC%80%E4%B8%BA%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125741572](https://letmefly.blog.csdn.net/article/details/125741572)
