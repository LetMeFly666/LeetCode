---
title: 919.完全二叉树插入器
date: 2022-07-25 14:26:22
tags: [题解, LeetCode, 中等, 树, 广度优先搜索, 设计, 二叉树, 完全二叉树, 完全二叉树的数组表示, 层次遍历]
---

# 【LetMeFly】919.完全二叉树插入器：完全二叉树的数组表示

力扣题目链接：[https://leetcode.cn/problems/complete-binary-tree-inserter/](https://leetcode.cn/problems/complete-binary-tree-inserter/)

<p><strong>完全二叉树</strong> 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。</p>

<p>设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。</p>

<p>实现 <code>CBTInserter</code> 类:</p>

<ul>
	<li><code>CBTInserter(TreeNode root)</code>&nbsp;使用头节点为&nbsp;<code>root</code>&nbsp;的给定树初始化该数据结构；</li>
	<li><code>CBTInserter.insert(int v)</code>&nbsp; 向树中插入一个值为&nbsp;<code>Node.val == val</code>的新节点&nbsp;<code>TreeNode</code>。使树保持完全二叉树的状态，<strong>并返回插入节点</strong>&nbsp;<code>TreeNode</code>&nbsp;<strong>的父节点的值</strong>；</li>
	<li><code>CBTInserter.get_root()</code> 将返回树的头节点。</li>
</ul>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<!-- <p><img src="https://assets.leetcode.com/uploads/2021/08/03/lc-treeinsert.jpg" style="height: 143px; width: 500px;" /></p> -->
<p><img src="https://img-blog.csdnimg.cn/2c0bcf240d4046a5a26794d3c388e5fa.jpeg" style="height: 143px; width: 500px;" /></p>

<pre>
<strong>输入</strong>
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
<strong>输出</strong>
[null, 1, 2, [1, 2, 3, 4]]

<strong>解释</strong>
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // 返回 1
cBTInserter.insert(4);  // 返回 2
cBTInserter.get_root(); // 返回 [1, 2, 3, 4]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数量范围为&nbsp;<code>[1, 1000]</code>&nbsp;</li>
	<li><code>0 &lt;= Node.val &lt;= 5000</code></li>
	<li><code>root</code>&nbsp;是完全二叉树</li>
	<li><code>0 &lt;= val &lt;= 5000</code>&nbsp;</li>
	<li>每个测试用例最多调用&nbsp;<code>insert</code>&nbsp;和&nbsp;<code>get_root</code>&nbsp;操作&nbsp;<code>10<sup>4</sup></code>&nbsp;次</li>
</ul>


    
## 方法一：用数组存储完全二叉树

完全二叉树具有以下性质：

![完全二叉树的数组表示](https://img-blog.csdnimg.cn/9e721d0b2e5a47ca94b4c66e3afb06e4.png#pic_center)

如果根节点从1开始按层次遍历的方式进行编号，那么$父节点的编号=\lfloor \frac{子节点的编号}{2}\rfloor$

因此，我们可以用数组存放完全二叉树的节点，这样在添加新的节点时，直接将新节点追加到数组尾部，就可以很容易地得到新节点的父节点$O(1)$。

之后，把父节点的子节点指向新节点即可。

+ 时间复杂度$O(n)$，其中$n$是初始二叉树的节点个数
+ 空间复杂度$O(m)$，其中$m$是最终二叉树的节点个数

### AC代码

#### C++

```cpp
class CBTInserter {
private:
    vector<TreeNode*> a;
public:
    CBTInserter(TreeNode* root) {  // 初始二叉树，按照层次遍历的方式存入数组
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            a.push_back(p);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    
    int insert(int val) {
        TreeNode* thisNode = new TreeNode(val);  // 新节点
        a.push_back(thisNode);
        int th = a.size();  // 新节点的编号
        TreeNode* father = a[th / 2 - 1];  // 父节点的编号 = 新节点的编号 / 2  ；-1是因为数组中下标从0开始而二叉树节点从1开始编号
        if (th % 2) {  // 奇数说明是左节点
            father->right = thisNode;
        }
        else {
            father->left = thisNode;
        }
        return father->val;
    }
    
    TreeNode* get_root() {
        return a[0];  // 根就是数组中的第一个节点
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/25/LeetCode%200919.%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E6%8F%92%E5%85%A5%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125974862](https://letmefly.blog.csdn.net/article/details/125974862)
