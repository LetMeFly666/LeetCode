---
title: 2385.感染二叉树需要的总时间
date: 2024-04-24 23:41:12
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, DFS, BFS]
---

# 【LetMeFly】2385.感染二叉树需要的总时间：两次搜索（深搜 + 广搜）

力扣题目链接：[https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/](https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/)

<p>给你一棵二叉树的根节点 <code>root</code> ，二叉树中节点的值 <strong>互不相同</strong> 。另给你一个整数 <code>start</code> 。在第 <code>0</code> 分钟，<strong>感染</strong> 将会从值为 <code>start</code> 的节点开始爆发。</p>

<p>每分钟，如果节点满足以下全部条件，就会被感染：</p>

<ul>
	<li>节点此前还没有感染。</li>
	<li>节点与一个已感染节点相邻。</li>
</ul>

<p>返回感染整棵树需要的分钟数<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png" style="width: 400px; height: 306px;">
<pre><strong>输入：</strong>root = [1,5,3,null,4,10,6,9,2], start = 3
<strong>输出：</strong>4
<strong>解释：</strong>节点按以下过程被感染：
- 第 0 分钟：节点 3
- 第 1 分钟：节点 1、10、6
- 第 2 分钟：节点5
- 第 3 分钟：节点 4
- 第 4 分钟：节点 9 和 2
感染整棵树需要 4 分钟，所以返回 4 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png" style="width: 75px; height: 66px;">
<pre><strong>输入：</strong>root = [1], start = 1
<strong>输出：</strong>0
<strong>解释：</strong>第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>每个节点的值 <strong>互不相同</strong></li>
	<li>树中必定存在值为 <code>start</code> 的节点</li>
</ul>


    
## 解题方法：两次搜索（深搜 + 广搜）

我们可以首先从根节点开始进行一次深度优先搜索，通过此次搜索便可以将每个节点的所有相邻节点记录下来。

接着从```start```结点开始广度优先搜索，每次感染一层，搜索完成时便得到了感染整棵树需要的时间。

Tips: 每个节点值互不相同，因此可以使用节点的值代替节点。

+ 时间复杂度$O(Size)$
+ 空间复杂度$O(Size)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<int, vector<int>> neighbors;

    void dfs(TreeNode* root) {
        if (root->left) {
            neighbors[root->val].push_back(root->left->val);
            neighbors[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if (root->right) {
            neighbors[root->val].push_back(root->right->val);
            neighbors[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        int ans = -1;
        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        while (q.size()) {
            ans++;
            for (int t = q.size(); t > 0; t--) {
                int thisNode = q.front();
                q.pop();
                for (int nextNode : neighbors[thisNode]) {
                    if (!visited.count(nextNode)) {
                        visited.insert(nextNode);
                        q.push(nextNode);
                    }
                }
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/24/LeetCode%202385.%E6%84%9F%E6%9F%93%E4%BA%8C%E5%8F%89%E6%A0%91%E9%9C%80%E8%A6%81%E7%9A%84%E6%80%BB%E6%97%B6%E9%97%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138172943](https://letmefly.blog.csdn.net/article/details/138172943)
