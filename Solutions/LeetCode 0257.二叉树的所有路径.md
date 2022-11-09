---
title: 257.二叉树的所有路径
date: 2022-09-12 09:56:37
tags: [题解, LeetCode, 简单, 树, 深度优先搜索, 字符串, 回溯, 二叉树, dfs]
---

# 【LetMeFly】257.二叉树的所有路径

力扣题目链接：[https://leetcode.cn/problems/binary-tree-paths/](https://leetcode.cn/problems/binary-tree-paths/)

<p>给你一个二叉树的根节点 <code>root</code> ，按 <strong>任意顺序</strong> ，返回所有从根节点到叶子节点的路径。</p>

<p><strong>叶子节点</strong> 是指没有子节点的节点。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg" style="width: 207px; height: 293px;" />
<pre>
<strong>输入：</strong>root = [1,2,3,null,5]
<strong>输出：</strong>["1-&gt;2-&gt;5","1-&gt;3"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>["1"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 100]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


    
## 方法一：DFS

深搜遍历二叉树，在遍历的过程中将所经过路径记录下来。如果遇到了叶子节点，就把当前路径加入答案中。

+ 时间复杂度$O(n^2)$，其中$n$是二叉树节点个数
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<string> ans;

    // void doNothing() {
    //     return;
    // }

    void dfs(TreeNode* root, string now) {
        if (!root->left && !root->right) {
            ans.push_back(now);
        }
        if (root->left) {
            dfs(root->left, now + "->" + to_string(root->left->val));
        }
        if (root->right) {
            dfs(root->right, now + "->" + to_string(root->right->val));
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, to_string(root->val));
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/09/12/LeetCode%200257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126813644](https://letmefly.blog.csdn.net/article/details/126813644)
