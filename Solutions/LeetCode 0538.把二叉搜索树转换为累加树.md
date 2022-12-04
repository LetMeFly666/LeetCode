---
title: 538.把二叉搜索树转换为累加树
date: 2022-12-04 16:41:06
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 二叉搜索树, 二叉树, DFS, 中序遍历]
---

# 【LetMeFly】538.把二叉搜索树转换为累加树

力扣题目链接：[https://leetcode.cn/problems/convert-bst-to-greater-tree/](https://leetcode.cn/problems/convert-bst-to-greater-tree/)

<p>给出二叉<strong> 搜索 </strong>树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 <code>node</code>&nbsp;的新值等于原树中大于或等于&nbsp;<code>node.val</code>&nbsp;的值之和。</p>

<p>提醒一下，二叉搜索树满足下列约束条件：</p>

<ul>
	<li>节点的左子树仅包含键<strong> 小于 </strong>节点键的节点。</li>
	<li>节点的右子树仅包含键<strong> 大于</strong> 节点键的节点。</li>
	<li>左右子树也必须是二叉搜索树。</li>
</ul>

<p><strong>注意：</strong>本题和 1038:&nbsp;<a href="https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/">https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/</a> 相同</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/05/03/tree.png" style="height: 364px; width: 534px;"></strong></p>

<pre><strong>输入：</strong>[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
<strong>输出：</strong>[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>root = [0,null,1]
<strong>输出：</strong>[1,null,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [1,0,2]
<strong>输出：</strong>[3,3,2]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>root = [3,2,4,1]
<strong>输出：</strong>[7,9,4,10]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数介于 <code>0</code>&nbsp;和 <code>10<sup>4</sup></code><sup>&nbsp;</sup>之间。</li>
	<li>每个节点的值介于 <code>-10<sup>4</sup></code>&nbsp;和&nbsp;<code>10<sup>4</sup></code>&nbsp;之间。</li>
	<li>树中的所有值 <strong>互不相同</strong> 。</li>
	<li>给定的树为二叉搜索树。</li>
</ul>


    
## 方法一：DFS反向中序遍历

二叉搜索树有一个非常不错的性质，就是“中序遍历所经过的节点的值是非递减的”。

同理，如果我们“反向中序遍历（右子->根->左子）”一颗二叉搜索树，那么我们的遍历顺序就是“非递增”的。

我们只需要记录一下“历史遍历节点的总和”，然后按照反向中序遍历的方式去遍历这棵二叉树，遍历到某个节点时，将这个节点的值修改为“这个节点的初始值 和 历史节点总和 的 和”，同时更新“历史遍历节点的总和”即可。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int total;

    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->right);
        total = root->val = total + root->val;
        dfs(root->left);
    }
public:
    Solution() {total = 0;}

    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
```

至于更高级的$O(1)$空间复杂度实现中序遍历的方法，请参考[官方题解](https://leetcode.cn/problems/convert-bst-to-greater-tree/solutions/421616/ba-er-cha-sou-suo-shu-zhuan-huan-wei-lei-jia-sh-14/)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/12/04/LeetCode%200538.%E6%8A%8A%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E8%BD%AC%E6%8D%A2%E4%B8%BA%E7%B4%AF%E5%8A%A0%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128174296](https://letmefly.blog.csdn.net/article/details/128174296)
