---
title: 129.求根节点到叶节点数字之和
date: 2022-07-22 11:14:34
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 二叉树, BFS]
---

# 【LetMeFly】129.求根节点到叶节点数字之和

力扣题目链接：[https://leetcode.cn/problems/sum-root-to-leaf-numbers/](https://leetcode.cn/problems/sum-root-to-leaf-numbers/)

给你一个二叉树的根节点 <code>root</code> ，树中每个节点都存放有一个 <code>0</code> 到 <code>9</code> 之间的数字。
<div class="original__bRMd">
<div>
<p>每条从根节点到叶节点的路径都代表一个数字：</p>

<ul>
	<li>例如，从根节点到叶节点的路径 <code>1 -> 2 -> 3</code> 表示数字 <code>123</code> 。</li>
</ul>

<p>计算从根节点到叶节点生成的 <strong>所有数字之和</strong> 。</p>

<p><strong>叶节点</strong> 是指没有子节点的节点。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg" style="width: 212px; height: 182px;" />
<pre>
<strong>输入：</strong>root = [1,2,3]
<strong>输出：</strong>25
<strong>解释：</strong>
从根到叶子节点路径 <code>1->2</code> 代表数字 <code>12</code>
从根到叶子节点路径 <code>1->3</code> 代表数字 <code>13</code>
因此，数字总和 = 12 + 13 = <code>25</code></pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [4,9,0,5,1]
<strong>输出：</strong>1026
<strong>解释：</strong>
从根到叶子节点路径 <code>4->9->5</code> 代表数字 495
从根到叶子节点路径 <code>4->9->1</code> 代表数字 491
从根到叶子节点路径 <code>4->0</code> 代表数字 40
因此，数字总和 = 495 + 491 + 40 = <code>1026</code>
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 1000]</code> 内</li>
	<li><code>0 <= Node.val <= 9</code></li>
	<li>树的深度不超过 <code>10</code></li>
</ul>
</div>
</div>


    
## 方法一：BFS

这道题类似[LeetCode 112.路径总和](https://leetcode.cn/problems/path-sum/)，直接进行一次遍历并修改原节点的值即可。

可参考题解[https://blog.tisfy.eu.org/2022/07/11/LeetCode 0112.路径总和/](https://blog.tisfy.eu.org/2022/07/11/LeetCode%200112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C/)

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);  // root 非空
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            if (!p->left && !p->right) {
                ans += p->val;
                continue;
            }
            p->val *= 10;
            if (p->left) {
                p->left->val += p->val;
                q.push(p->left);
            }
            if (p->right) {
                p->right->val += p->val;
                q.push(p->right);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/22/LeetCode%200129.%E6%B1%82%E6%A0%B9%E8%8A%82%E7%82%B9%E5%88%B0%E5%8F%B6%E8%8A%82%E7%82%B9%E6%95%B0%E5%AD%97%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125928616](https://letmefly.blog.csdn.net/article/details/125928616)
