---
title: 1339.分裂二叉树的最大乘积：深度优先搜索(一次DFS+存数组并遍历)
date: 2026-01-07 21:57:39
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 二叉树]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/02/02/sample_1_1699.png
---

# 【LetMeFly】1339.分裂二叉树的最大乘积：深度优先搜索(一次DFS+存数组并遍历)

力扣题目链接：[https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/](https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/)

<p>给你一棵二叉树，它的根为&nbsp;<code>root</code> 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。</p>

<p>由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/02/02/sample_1_1699.png" style="height: 200px; width: 495px;"></strong></p>

<pre><strong>输入：</strong>root = [1,2,3,4,5,6]
<strong>输出：</strong>110
<strong>解释：</strong>删除红色的边，得到 2 棵子树，和分别为 11 和 10 。它们的乘积是 110 （11*10）
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/02/02/sample_2_1699.png" style="height: 200px; width: 495px;"></p>

<pre><strong>输入：</strong>root = [1,null,2,3,4,null,null,5,6]
<strong>输出：</strong>90
<strong>解释：</strong>移除红色的边，得到 2 棵子树，和分别是 15 和 6 。它们的乘积为 90 （15*6）
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [2,3,9,10,7,8,6,5,4,11,1]
<strong>输出：</strong>1025
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>root = [1,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每棵树最多有&nbsp;<code>50000</code>&nbsp;个节点，且至少有&nbsp;<code>2</code>&nbsp;个节点。</li>
	<li>每个节点的值在&nbsp;<code>[1, 10000]</code>&nbsp;之间。</li>
</ul>


    
## 解题方法：DFS

一次DFS遍历结束立刻得到答案似乎是不可行的（往左子遍历时需要右子和信息），但是我们可以在遍历时把所有子树的和存下来。

任意位置切一刀，就相当于`以被切的子节点为根的子树的和`（记为$t$）乘以$sum-t$（其中$sum$是所有节点元素之和）。

+ 时间复杂度$O(size(tree))$
+ 空间复杂度$O(size(tree))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-07 21:52:59
 */
typedef long long ll;
class Solution {
private:
    vector<int> subTreeSum;
    int dfs(TreeNode* root) {
        int leftSum = 0, rightSum = 0;
        if (root->left) {
            leftSum = dfs(root->left);
            subTreeSum.push_back(leftSum);
        }
        if (root->right) {
            rightSum = dfs(root->right);
            subTreeSum.push_back(rightSum);
        }
        return root->val + leftSum + rightSum;
    }
public:
    int maxProduct(TreeNode* root) {
        int totalSum = dfs(root);
        ll ans = 0;
        for (int t : subTreeSum) {
            ans = max(ans, (ll)t * (totalSum - t));
        }
        return ans % 1000000007;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-01-07 21:55:18
'''
from typing import Optional  # 昨天改的newSolutions.py(好像是)今天就用上了

class Solution:
    def dfs(self, root: TreeNode) -> int:
        left, right = 0, 0
        if root.left:
            left = self.dfs(root.left)
            self.sum.append(left)
        if root.right:
            right = self.dfs(root.right)
            self.sum.append(right)
        return root.val + left + right
    
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.sum = []
        sum = self.dfs(root)
        return max(t * (sum - t) for t in self.sum) % 1000000007
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156697071)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/07/LeetCode%201339.%E5%88%86%E8%A3%82%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E4%B9%98%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
