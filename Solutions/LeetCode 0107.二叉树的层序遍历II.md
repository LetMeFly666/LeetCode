---
title: 107.二叉树的层序遍历 II
date: 2022-07-04 23:18:27
tags: [题解, LeetCode, 中等, 树, 广度优先搜索, 二叉树, 层次遍历]
---

# 【LetMeFly】107.二叉树的层序遍历 II

力扣题目链接：[https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)

<p>给你二叉树的根节点 <code>root</code> ，返回其节点值 <strong>自底向上的层序遍历</strong> 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[15,7],[9,20],[3]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[[1]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>


    
## 方法一：优先队列

与[之前方法](https://letmefly.blog.csdn.net/article/details/125584554)不同，这次决定不使用```pair<TreeNode*, int>```，而是直接使用```TreeNode*```入队。

看不懂的可以先看之前这篇博客：[https://letmefly.blog.csdn.net/article/details/125584554](https://letmefly.blog.csdn.net/article/details/125584554)

那么，没有了```int```类型的层数，怎么判断哪些节点是属于同一层的呢？

其实也很简单，我们在队列不空的时候，记录下来队列中一共由多少个元素，这些元素的个数就是当前最后一层的节点的个数。

然后，我们用一个循环，把这些元素全都添加到答案的同一层中（同时把子节点入队）即可。

+ 时间复杂度$O(N)$，其中$N$是节点个数。
+ 空间复杂度$O(N2)$，其中$N2$是节点最多的一层的节点数。


### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        int layer = -1;
        while (q.size()) {
            ans.push_back({});
            layer++;
            int thisLayerNum = q.size();
            while (thisLayerNum--) {
                TreeNode* thisNode = q.front();
                q.pop();
                ans[layer].push_back(thisNode->val);
                if (thisNode->left)
                    q.push(thisNode->left);
                if (thisNode->right)
                    q.push(thisNode->right);
            }
        }
        reverse(ans.begin(), ans.end());  // 注意，这里是本题要求从最后一层开始遍历，所以reverse了以下。正常情况下的层次遍历是不需要reverse的
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/04/LeetCode%200107.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125610699](https://letmefly.blog.csdn.net/article/details/125610699)
