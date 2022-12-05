---
title: 543.二叉树的直径
date: 2022-12-05 22:50:08
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 二叉树, 二叉树的深度]
---

# 【LetMeFly】543.二叉树的直径

力扣题目链接：[https://leetcode.cn/problems/diameter-of-binary-tree/](https://leetcode.cn/problems/diameter-of-binary-tree/)

<p>给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。</p>

<p>&nbsp;</p>

<p><strong>示例 :</strong><br>
给定二叉树</p>

<pre>          1
         / \
        2   3
       / \     
      4   5    
</pre>

<p>返回&nbsp;<strong>3</strong>, 它的长度是路径 [4,2,1,3] 或者&nbsp;[5,2,1,3]。</p>

<p>&nbsp;</p>

<p><strong>注意：</strong>两结点之间的路径长度是以它们之间边的数目表示。</p>


    
## 方法一：深度优先搜索求二叉树的深度

我们只需要求出每个节点的左子树的最大深度，以及右子树的最大深度。

假设这个节点的左子树的最大深度为$left$，右子树的最大深度为$right$，那么**经过这个节点**的二叉树的最大“直径”为$left + right$

> 这是因为经过这个节点的最长“路径”所经过的节点个数为$left + right + 1$，而“直径”是节点之间的“边”数，“边数” = “点数” + 1

这样，我们在深度优先搜索求二叉树左子树和右子树的深度的同时，更新一下答案的最大值即可。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int ans;

    int getDeepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = getDeepth(root->left);
        int right = getDeepth(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        getDeepth(root);
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/05/LeetCode%200543.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%9B%B4%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128194953](https://letmefly.blog.csdn.net/article/details/128194953)
