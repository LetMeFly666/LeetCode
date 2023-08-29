---
title: 1302.层数最深叶子节点的和
date: 2022-08-17 08:35:39
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, BFS, 层次遍历, 层序遍历]
---

# 【LetMeFly】1302.层数最深叶子节点的和

力扣题目链接：[https://leetcode.cn/problems/deepest-leaves-sum/](https://leetcode.cn/problems/deepest-leaves-sum/)

<p>给你一棵二叉树的根节点 <code>root</code> ，请你返回 <strong>层数最深的叶子节点的和</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<!-- <p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/12/28/1483_ex1.png" style="height: 265px; width: 273px;" /></strong></p> -->

<p><strong><img alt="" src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/fad04952e29b43a998ffacb6d81ab73d.png" style="height: 265px; width: 273px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
<strong>输出：</strong>15
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
<strong>输出：</strong>19
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 10<sup>4</sup>]</code> 之间。</li>
	<li><code>1 <= Node.val <= 100</code></li>
</ul>


    
## 方法一：BFS

方法等同于[二叉树的层次遍历](https://blog.tisfy.eu.org/2022/07/04/LeetCode%200107.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86II/)，可以用变量```ans```来统计每一层节点的和，最终```ans```的值即为最后一层的节点的和。

+ 时间复杂度$O(n)$，其中$n$是二叉树的节点个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {  // root not null
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            ans = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode* thisNode = q.front();
                q.pop();
                ans += thisNode->val;
                if (thisNode->left)
                    q.push(thisNode->left);
                if (thisNode->right)
                    q.push(thisNode->right);
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/17/LeetCode%201302.%E5%B1%82%E6%95%B0%E6%9C%80%E6%B7%B1%E5%8F%B6%E5%AD%90%E8%8A%82%E7%82%B9%E7%9A%84%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126377912](https://letmefly.blog.csdn.net/article/details/126377912)
