---
title: 1161.最大层内元素和
date: 2022-07-31 10:29:07
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, BFS, 层次遍历, 层序遍历]
---

# 【LetMeFly】1161.最大层内元素和

力扣题目链接：[https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/](https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/)

<p>给你一个二叉树的根节点&nbsp;<code>root</code>。设根节点位于二叉树的第 <code>1</code> 层，而根节点的子节点位于第 <code>2</code> 层，依此类推。</p>

<p>请返回层内元素之和 <strong>最大</strong> 的那几层（可能只有一层）的层号，并返回其中&nbsp;<strong>最小</strong> 的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/capture.jpeg" style="height: 175px; width: 200px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,7,0,7,-8,null,null]
<strong>输出：</strong>2
<strong>解释：</strong>
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [989,null,10250,98693,-89388,null,null,null,-32127]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在<meta charset="UTF-8" />&nbsp;<code>[1, 10<sup>4</sup>]</code>范围内<meta charset="UTF-8" /></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：层序遍历 + 广搜BFS

有关二叉树的层序遍历，之前已经讲过，详细方法可参考 [LeetCode 0107.二叉树的层序遍历II の 题解](https://leetcode.letmefly.xyz/2022/07/04/LeetCode%200107.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86II/)

本题，同样地，我们使用优先队列来对二叉树进行层序遍历。

+ 用变量```maxSum```记录当前的单层最大和
+ 用变量```ans```来记录取得```maxSum```的最小层号
+ 用变量```nowLayer```记录当前遍历到的层的层号

初始值```maxSum```为```int```范围内的最小值```INT_MIN```，```ans```取任意值即可，```nowLayer```的值取```1```。

在遍历到某一层时，用一个临时变量```thisSum```统计这一层的节点值之和

如果这一层遍历结束后，```thisSum```的值大于之前所记录的最大值```maxSum```

那么就更新```maxSum```为```thisSum```，并将```ans```赋值为当前层号```nowLayer```。

+ 时间复杂度$O(N)$，其中$N$是节点个数。
+ 空间复杂度$O(N2)$，其中$N2$是节点最多的一层的节点数。

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = -1;
        int nowLayer = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int thisLayerNum = q.size();  // 这一层有几个元素
            int thisSum = 0;
            for (int i = 0; i < thisLayerNum; i++) {
                TreeNode* thisNode = q.front();
                q.pop();
                thisSum += thisNode->val;
                if (thisNode->left)
                    q.push(thisNode->left);
                if (thisNode->right)
                    q.push(thisNode->right);
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
                ans = nowLayer;
            }
            nowLayer++;
        }

        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/31/LeetCode%201161.%E6%9C%80%E5%A4%A7%E5%B1%82%E5%86%85%E5%85%83%E7%B4%A0%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126082726](https://letmefly.blog.csdn.net/article/details/126082726)
