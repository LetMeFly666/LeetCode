---
title: 662.二叉树最大宽度
date: 2022-08-27 13:49:30
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, 层次遍历, 层序遍历]
---

# 【LetMeFly】662.二叉树最大宽度：一组奇怪的数据

力扣题目链接：[https://leetcode.cn/problems/maximum-width-of-binary-tree/](https://leetcode.cn/problems/maximum-width-of-binary-tree/)

<p>给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与<strong>满二叉树（full binary tree）</strong>结构相同，但一些节点为空。</p>

<p>每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的<code>null</code>节点也计入长度）之间的长度。</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

<strong>输出:</strong> 4
<strong>解释:</strong> 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> 

          1
         /  
        3    
       / \       
      5   3     

<strong>输出:</strong> 2
<strong>解释:</strong> 最大值出现在树的第 3 层，宽度为 2 (5,3)。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入:</strong> 

          1
         / \
        3   2 
       /        
      5      

<strong>输出:</strong> 2
<strong>解释:</strong> 最大值出现在树的第 2 层，宽度为 2 (3,2)。
</pre>

<p><strong>示例 4:</strong></p>

<pre>
<strong>输入:</strong> 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
<strong>输出:</strong> 8
<strong>解释:</strong> 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
</pre>

<p><strong>注意:</strong> 答案在32位有符号整数的表示范围内。</p>


    
## 方法一：层次遍历

[层序遍历](https://leetcode.letmefly.xyz/tags/%E5%B1%82%E6%AC%A1%E9%81%8D%E5%8E%86/)二叉树，在遍历的同时，二叉树的“坐标”同时入队。

在处理每一层时，更新最左和最右的坐标。

处理完这一层后，$最右 - 最左 + 1$就是这层的宽度。

处理一个节点时，若此节点具有左子节点，那么左子节点的编号为这个节点编号的二倍

若具有右子节点，那么右子节点的编号是这个节点编号的二倍+1

具体原因为：

![why](https://img-blog.csdnimg.cn/8efa2bd7e4404d3a9a395a8377a47ccb.png#pic_center)

+ 时间复杂度$O(n)$，其中$n$为二叉树节点个数
+ 空间复杂度$O(n)$

提交我下面的代码并不能通过这道题，因为这道题数据有一组似乎得手写高精度。官方题解也溢出了（截止至20220827 15:03）。

已反馈至Github:[https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/8816](https://github.com/LeetCode-Feedback/LeetCode-Feedback/issues/8816)

![反馈](https://img-blog.csdnimg.cn/75bc5cf8a77d41d3b09bdad3c23bca52.jpeg#pic_center)

### 至发文为止不能AC的代码

#### C++

```cpp
typedef unsigned long long ull;
// typedef __int128 ull;
typedef pair<TreeNode*, ull> pii;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ull ans = 0;
        queue<pii> q;
        q.push({root, 1});
        ull lastL, lastR;
        // int cntDebug = 0;
        while (q.size()) {
            
            // cntDebug++;
            // if (cntDebug > 1750) {
            //     printf("q.size() = %lld, q:[");
            //     // queue<pii> q2, q3 = q;
            //     // while (q3.size()) {
            //     //     q2.push(q3.front());
            //     //     q3.pop();
            //     // }
            //     // while (q2.size()) {
            //     //     cout << q2.front().first->val << ", ";
            //     // }
            // }
            ull mostL = q.front().second, mostR = mostL;
            for (int i = q.size(); i > 0; i--) {
                auto[node, loc] = q.front();
                // printf("loc = %llu\n", loc);
                // if (node->val) {
                //     printf("node->val = %d, loc = %llu\n", node->val, loc);
                // }
                q.pop();
                mostL = min(mostL, loc);
                mostR = max(mostR, loc);
                if (node->left) {
                    q.push({node->left, loc * 2 - 1});
                }
                if (node->right) {
                    q.push({node->right, loc * 2});
                }
            }
            lastL = mostL, lastR = mostR;
            ans = max(ans, mostR - mostL + 1);
            // if (cntDebug > 1750) {
            //     // cout << "mostL = " << lastL << ", mostR = " << lastR << endl;
            //     printf("mostL = %llu, mostR = %llu\n", mostL, mostR, q.size());
            // }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/27/LeetCode%200662.%E4%BA%8C%E5%8F%89%E6%A0%91%E6%9C%80%E5%A4%A7%E5%AE%BD%E5%BA%A6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126558271](https://letmefly.blog.csdn.net/article/details/126558271)
