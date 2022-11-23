---
title: 530.二叉搜索树的最小绝对差
date: 2022-11-23 11:37:47
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 广度优先搜索, 二叉搜索树, 二叉树, 中序遍历]
---

# 【LetMeFly】530.二叉搜索树的最小绝对差

力扣题目链接：[https://leetcode.cn/problems/minimum-absolute-difference-in-bst/](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

<p>给你一个二叉搜索树的根节点 <code>root</code> ，返回 <strong>树中任意两不同节点值之间的最小差值</strong> 。</p>

<p>差值是一个正数，其数值等于两值之差的绝对值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg" style="width: 292px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [4,2,6,1,3]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg" style="width: 282px; height: 301px;" />
<pre>
<strong>输入：</strong>root = [1,0,48,null,null,12,49]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目范围是 <code>[2, 10<sup>4</sup>]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与 783 <a href="https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/">https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/</a> 相同</p>


    
## 方法一：中序遍历

首先需要明白二叉搜索树的性质：

对于二叉搜索树的每个节点：

1. 左子树上的节点都小于（或等于）根节点
2. 右子树上的节点都大于（或等于）根节点

因此，我们只需要中序遍历一遍二叉搜索树，遍历过程中，访问的节点的值的顺序就是非递减的。

这样，“树中任意两不同节点值之间的最小差值”就转换为了“遍历过程中后一个节点与前一个节点的差值的最小值”

我们使用一个变量$lastNum$记录“上一个节点”的值，再使用一个变量$ans$记录“不同节点的最小差值”，遍历过程中不断更新上述两变量，遍历结束后$ans$即为答案。

+ 时间复杂度$O(n)$，其中$n$是二叉树中节点的个数
+ 空间复杂度$O(n)$，主要空间复杂度来源是递归

### AC代码

#### C++

```cpp
class Solution {
private:
    int lastNum = -1e7;
    int ans = 1e7;

    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        // printf("root->val = %d, lastNum = %d\n", root->val, lastNum);  //********
        ans = min(ans, root->val - lastNum);
        lastNum = root->val;
        dfs(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/11/23/LeetCode%200530.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127997530](https://letmefly.blog.csdn.net/article/details/127997530)
