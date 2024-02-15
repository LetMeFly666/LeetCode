---
title: 814.二叉树剪枝
date: 2022-07-21 18:54:39
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 二叉树, DFS]
---

# 【LetMeFly】814.二叉树剪枝

力扣题目链接：[https://leetcode.cn/problems/binary-tree-pruning/](https://leetcode.cn/problems/binary-tree-pruning/)

<p>给你二叉树的根结点&nbsp;<code>root</code>&nbsp;，此外树的每个结点的值要么是 <code>0</code> ，要么是 <code>1</code> 。</p>

<p>返回移除了所有不包含 <code>1</code> 的子树的原二叉树。</p>

<p>节点 <code>node</code> 的子树为 <code>node</code> 本身加上所有 <code>node</code> 的后代。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png" style="width: 500px; height: 140px;" />
<pre>
<strong>输入：</strong>root = [1,null,0,0,1]
<strong>输出：</strong>[1,null,0,null,1]
<strong>解释：</strong>
只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png" style="width: 500px; height: 115px;" />
<pre>
<strong>输入：</strong>root = [1,0,1,0,0,0,1]
<strong>输出：</strong>[1,null,1,null,1]
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png" style="width: 500px; height: 134px;" />
<pre>
<strong>输入：</strong>root = [1,1,0,1,1,0,1,0]
<strong>输出：</strong>[1,1,0,1,1,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 200]</code> 内</li>
	<li><code>Node.val</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>


    
## 方法一：DFS

递归，返回结果的同时进行修剪。

因为涉及到一个节点的所有子树，因此很适合深搜DFS。

构建一个函数```isZero```，用来判断一个节点是否是某个```全0子树```的根。同时，如果这个节点的左子树是全0子树，就剪掉这个节点的左子树；右子树同理。

```cpp
/* 判断此节点的 左/右 子树是否为全0二叉树。若是，则移除对应子树 */
bool isZero(TreeNode* root) {
	bool is0 = true;  // 这个节点是否为全0子树的根
	if (root->val)  // 如果这个节点的值为1
		is0 = false;  // 直接排除全0子树
	// 判断左子树是否为全0子树。如果是，就修剪之
	if (root->left) {  // 前提是左子树不空
		if (isZero(root->left)) {  // 左子树是全0子树
			root->left = nullptr;  // 左子树设置为空（这样就修剪掉了）
		}
		else {  // 左子树不是全0子树
			is0 = false;  // 那么“父树”更不是全0树
		}
	}
	// 右子树同理
	if (root->right) {
		if (isZero(root->right)) {
			root->right = nullptr;
		}
		else {
			is0 = false;
		}
	}
	return is0;
}
```

+ 时间复杂度$O(N)$，其中$N$是节点的个数
+ 空间复杂度$O(N)$，空间复杂度主要来自递归

### AC代码

#### C++

```cpp
class Solution {
private:
    /* 判断此节点的 左/右 子树是否为全0二叉树。若是，则移除对应子树 */
    bool isZero(TreeNode* root) {
        bool is0 = true;
        if (root->val)
            is0 = false;
        if (root->left) {
            if (isZero(root->left)) {
                root->left = nullptr;
            }
            else {
                is0 = false;
            }
        }
        if (root->right) {
            if (isZero(root->right)) {
                root->right = nullptr;
            }
            else {
                is0 = false;
            }
        }
        return is0;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (isZero(root))
            root = nullptr;
        return root;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/21/LeetCode%200814.%E4%BA%8C%E5%8F%89%E6%A0%91%E5%89%AA%E6%9E%9D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125918905](https://letmefly.blog.csdn.net/article/details/125918905)
