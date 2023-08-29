---
title: 623.在二叉树中增加一行
date: 2022-08-05 15:41:28
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, BFS, DFS, 层次遍历]
---

# 【LetMeFly】623.在二叉树中增加一行：DFS / BFS

力扣题目链接：[https://leetcode.cn/problems/add-one-row-to-tree/](https://leetcode.cn/problems/add-one-row-to-tree/)

<p>给定一个二叉树的根&nbsp;<code>root</code>&nbsp;和两个整数 <code>val</code> 和&nbsp;<code>depth</code>&nbsp;，在给定的深度&nbsp;<code>depth</code>&nbsp;处添加一个值为 <code>val</code> 的节点行。</p>

<p>注意，根节点&nbsp;<code>root</code>&nbsp;位于深度&nbsp;<code>1</code>&nbsp;。</p>

<p>加法规则如下:</p>

<ul>
	<li>给定整数&nbsp;<code>depth</code>，对于深度为&nbsp;<code>depth - 1</code> 的每个非空树节点 <code>cur</code> ，创建两个值为 <code>val</code> 的树节点作为 <code>cur</code> 的左子树根和右子树根。</li>
	<li><code>cur</code> 原来的左子树应该是新的左子树根的左子树。</li>
	<li><code>cur</code> 原来的右子树应该是新的右子树根的右子树。</li>
	<li>如果 <code>depth == 1 </code>意味着&nbsp;<code>depth - 1</code>&nbsp;根本没有深度，那么创建一个树节点，值 <code>val </code>作为整个原始树的新根，而原始树就是新根的左子树。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<!-- <p><img src="https://assets.leetcode.com/uploads/2021/03/15/addrow-tree.jpg" style="height: 231px; width: 500px;" /></p> -->
<p><img src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/a21274e0411a4c8ba0553a27ea5a4f5e.jpeg" style="height: 277px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> root = [4,2,6,3,1,5], val = 1, depth = 2
<strong>输出:</strong> [4,1,1,2,null,null,6,3,1,5]</pre>

<p><strong>示例 2:</strong></p>

<!-- <p><img src="https://assets.leetcode.com/uploads/2021/03/11/add2-tree.jpg" style="height: 277px; width: 500px;" /></p> -->
<p><img src="https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/99bcacfbf30345f1964a83c8859fe774.jpeg" style="height: 231px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> root = [4,2,null,3,1], val = 1, depth = 3
<strong>输出:</strong>  [4,2,null,1,1,3,null,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>节点数在&nbsp;<code>[1, 10<sup>4</sup>]</code>&nbsp;范围内</li>
	<li>树的深度在&nbsp;<code>[1, 10<sup>4</sup>]</code>范围内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= val &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= depth &lt;= the depth of tree + 1</code></li>
</ul>


    
## 方法一.1：广度优先搜索

按照经典的 [二叉树层次遍历的方法](https://blog.tisfy.eu.org/2022/07/04/LeetCode%200107.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86II/) 对二叉树进行层次遍历，当遍历到对应的层的上一层时，为这一层的左右子都新建立一个值为```val```的新的子节点，并将新左子指向旧左子，新右子指向旧右子。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        int nowLayer = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int thisLayerNodesNum = q.size();
            nowLayer++;
            for (int i = 0; i < thisLayerNodesNum; i++) {
                TreeNode* thisNode = q.front();
                q.pop();
                if (nowLayer == depth) {
                    TreeNode* leftNewNode = new TreeNode(val, thisNode->left, nullptr);
                    TreeNode* rightNewNode = new TreeNode(val, nullptr, thisNode->right);
                    thisNode->left = leftNewNode, thisNode->right = rightNewNode;
                    if (leftNewNode->left) {
                        q.push(leftNewNode->left);
                    }
                    if (rightNewNode->right) {
                        q.push(rightNewNode->right);
                    }
                }
                else {
                    if (thisNode->left) {
                        q.push(thisNode->left);
                    }
                    if (thisNode->right) {
                        q.push(thisNode->right);
                    }
                }
            }
        }
        return root;
    }
};
```

## 方法一.2：广度优先搜索 + 提前退出

在方法一.1的基础上，如果我们已经新建了节点，那么就已经没有必要再遍历下去了，因为层次遍历越往下层数越深，下面的节点不需要做出任何改变。

因此，方法一.2就是在方法一.1的基础上，插入新节点后，退出遍历。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        int nowLayer = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int thisLayerNodesNum = q.size();
            nowLayer++;
            for (int i = 0; i < thisLayerNodesNum; i++) {
                TreeNode* thisNode = q.front();
                q.pop();
                if (nowLayer == depth) {
                    TreeNode* leftNewNode = new TreeNode(val, thisNode->left, nullptr);
                    TreeNode* rightNewNode = new TreeNode(val, nullptr, thisNode->right);
                    thisNode->left = leftNewNode, thisNode->right = rightNewNode;

					// 相应地，这里也取消了入队操作  // -------------------
                }
                else {
                    if (thisNode->left) {
                        q.push(thisNode->left);
                    }
                    if (thisNode->right) {
                        q.push(thisNode->right);
                    }
                }
            }
            
            if (nowLayer == depth) {  // ------------------------
                break;  // 直接break掉即可
            }
        }
        return root;
    }
};
```

## 方法二：深度优先搜索

> 为什么先讲广度优先搜索再讲深度优先搜索？
>
> 因为深搜代码比广搜要简洁许多。

深搜时，如果```depth > 2```，就正常地递归即可

但是当```depth = 2```时，就说明这一层的下一层需要插入值为```val```的节点。那么就对这个节点新建两个值为```val```的新的子节点，(类似一.1)并将新左子指向旧左子，新右子指向旧右子。

建立新节点后，就不需要再继续递归了。

**特别的**，如果```depth = 1```（除非题目原始输入就是```depth```为```1```，否则不会遇到这种情况），就按题目要求新建值为```val```的节点，并将原始根节点赋值为新节点的左子节点，并返回新节点。

+ 时间复杂度$O(n)$，其中$n$是二叉树节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {  // 递归的魅力
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) {
            return nullptr;
        }
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val, root, nullptr);
            return newRoot;
        }
        if (depth == 2) {  // 不必再继续递归
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        }
        else {
            addOneRow(root->left, val, depth - 1);
            addOneRow(root->right, val, depth - 1);
        }
        return root;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/08/05/LeetCode%200623.%E5%9C%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E5%A2%9E%E5%8A%A0%E4%B8%80%E8%A1%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126179967](https://letmefly.blog.csdn.net/article/details/126179967)
