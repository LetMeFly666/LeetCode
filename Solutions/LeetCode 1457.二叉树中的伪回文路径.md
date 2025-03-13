---
title: 1457.二叉树中的伪回文路径
date: 2023-11-25 17:44:32
tags: [题解, LeetCode, 中等, 位运算, 树, 深度优先搜索, DFS, 广度优先搜索, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】1457.二叉树中的伪回文路径：深度优先搜索(DFS) + 位运算优化

力扣题目链接：[https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/](https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/)

<p>给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「<strong>伪回文</strong>」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。</p>

<p>请你返回从根到叶子节点的所有路径中&nbsp;<strong>伪回文&nbsp;</strong>路径的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/23/palindromic_paths_1.png" style="height: 201px; width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [2,3,1,3,1,null,1]
<strong>输出：</strong>2 
<strong>解释：</strong>上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
     在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/23/palindromic_paths_2.png" style="height: 314px; width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [2,1,1,1,3,null,null,null,null,null,1]
<strong>输出：</strong>1 
<strong>解释：</strong>上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
     这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [9]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定二叉树的节点数目在范围&nbsp;<code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 9</code></li>
</ul>


    
## 方法一：深度优先搜索(DFS) + 位运算优化

首先这道题组成“回文序列”时，每个数的顺序可变。因此不难发现，一个序列可以组成回文序列 **等价于** 这个序列要么```每个数都出现了偶数次```要么```只有一个数出现了奇数次其他数都出现了偶数次```。

因此，我们只深度优先搜索，使用一个大小为$10$的数组（节点中每个数的范围是1-9）存储每个数出现的次数。当搜索到叶节点时，看数组中元素出现的次数是否满足上方要求即可。

**如何使用位运算进行优化**呢？我们可以使用一个数的低$10$位来存储“某个数出现了奇数次还是偶数次”这一信息。若出现奇数次则这一位为1，出现偶数次则这一位为0。

这样，在遍历过程中，若当前节点值为$a$，就将$mask$异或上$(1<<a)$。

最终看$mask$是否最多有一个$1$的时候，可以借助[```lowbit```](https://web.letmefly.eu.org/Notes/ACM/Template/lowbit.html)的思想。若$mask = (mask & -mask)$则mask二进制下最多有1个1。

+ $6=(110)_2$，$lowbit(6)=(10)_2$
+ $12=(1100)_2$，$lowbit(12)=(100)_2$

以上。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点个数
+ 空间复杂度$O(n)$。若二叉树退化成一个直链，则递归消耗$O(n)$的空间

### AC代码

#### C++

```cpp
class Solution {
private:
    int ans;
    void dfs(TreeNode* root, int mask) {
        mask ^= (1 << root->val);
        if (!root->left && !root->right) {
            ans += __builtin_popcount(mask) < 2;
        }
        if (root->left) {
            dfs(root->left, mask);
        }
        if (root->right) {
            dfs(root->right, mask);
        }
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def dfs(self, root: TreeNode, mask: int) -> None:
        mask ^= (1 << root.val)
        if not root.left and not root.right:
            self.ans += mask == (mask & -mask)
        if root.left:
            self.dfs(root.left, mask)
        if root.right:
            self.dfs(root.right, mask)
    
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        self.ans = 0
        self.dfs(root, 0)
        return self.ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/11/25/LeetCode%201457.%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%AA%E5%9B%9E%E6%96%87%E8%B7%AF%E5%BE%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134617854](https://letmefly.blog.csdn.net/article/details/134617854)
