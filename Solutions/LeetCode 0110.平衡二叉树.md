---
title: 110.平衡二叉树
date: 2022-07-09 11:47:50
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 二叉树]
---

# 【LetMeFly】110.平衡二叉树 - 自底向上

力扣题目链接：[https://leetcode.cn/problems/balanced-binary-tree/](https://leetcode.cn/problems/balanced-binary-tree/)

<p>给定一个二叉树，判断它是否是高度平衡的二叉树。</p>

<p>本题中，一棵高度平衡二叉树定义为：</p>

<blockquote>
<p>一个二叉树<em>每个节点 </em>的左右两个子树的高度差的绝对值不超过 1 。</p>
</blockquote>

<p> </p>

<p><strong>示例 1：</strong></p>
<!-- <img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg" style="width: 342px; height: 221px;" /> -->
<img alt="" src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/d1af0ddebbd343a69b85f0136f153bc4.jpeg" style="width: 342px; height: 221px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<!-- <img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg" style="width: 452px; height: 301px;" /> -->
<img alt="" src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/fd2c38a76b0a41a9a88300ef32854711.jpeg" style="width: 452px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [1,2,2,3,3,null,null,4,4]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在范围 <code>[0, 5000]</code> 内</li>
	<li><code>-10<sup>4</sup> <= Node.val <= 10<sup>4</sup></code></li>
</ul>


    
## 方法一：110.平衡二叉树 - 自底向上

判断一棵树是否为平衡二叉树，只需要判断```左子树的和右子树的高度之差的绝对值是否 ≤ 1```

我们只需要求出每个节点为根的树的高度（$\max(左子树, 右子树) + 1$），并且在求高度的过程中，判断左右子树的高度差是否大于1即可（若大于1，则记录下来）。

```cpp
bool ok = true;

int getHeight(TreeNode* root) {
	if (!root)  // 空节点高度为0
		return 0;
	int left = getHeight(root->left);  // 左子树的高度
	int right = getHeight(root->right);  // 右子树的高度
	if (abs(left - right) > 1) {  // 高度差大于1
		ok = false;  // 则不是平衡二叉树
	}
	return max(left, right) + 1;  // 以root为根的树的高度是max(left, right) + 1
}
```

因为递归过程中，其实是先求的叶节点的高度，因此美其名曰**自底向上**

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数（每个节点只需要遍历一次）
+ 空间复杂度$O(n)$，空间复杂度的消耗主要来自递归

### AC代码

#### C++

```cpp
class Solution {
private:
    bool ok = true;

    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1) {
            ok = false;
        }
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return ok;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/09/LeetCode%200110.%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125691684](https://letmefly.blog.csdn.net/article/details/125691684)
