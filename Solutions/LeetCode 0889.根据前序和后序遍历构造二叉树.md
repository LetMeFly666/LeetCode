---
title: 889.根据前序和后序遍历构造二叉树
date: 2024-02-22 10:05:31
tags: [题解, LeetCode, 中等, 树, 数组, 哈希表, 哈希, map, 递归, 分治, 二叉树]
---

# 【LetMeFly】889.根据前序和后序遍历构造二叉树：分治（递归）——双O(n)的做法，五彩斑斓的题解（若不是彩色的可以点击原文链接查看）

力扣题目链接：[https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

<p>给定两个整数数组，<code>preorder</code>&nbsp;和 <code>postorder</code> ，其中 <code>preorder</code> 是一个具有 <strong>无重复</strong> 值的二叉树的前序遍历，<code>postorder</code> 是同一棵树的后序遍历，重构并返回二叉树。</p>

<p>如果存在多个答案，您可以返回其中 <strong>任何</strong> 一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/07/24/lc-prepost.jpg" style="height: 265px; width: 304px;" /></p>

<pre>
<strong>输入：</strong>preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
<strong>输出：</strong>[1,2,3,4,5,6,7]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> preorder = [1], postorder = [1]
<strong>输出:</strong> [1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 30</code></li>
	<li><code>1 &lt;= preorder[i] &lt;= preorder.length</code></li>
	<li><code>preorder</code>&nbsp;中所有值都 <strong>不同</strong></li>
	<li><code>postorder.length == preorder.length</code></li>
	<li><code>1 &lt;= postorder[i] &lt;= postorder.length</code></li>
	<li><code>postorder</code>&nbsp;中所有值都 <strong>不同</strong></li>
	<li>保证 <code>preorder</code>&nbsp;和 <code>postorder</code>&nbsp;是同一棵二叉树的前序遍历和后序遍历</li>
</ul>


    
## 方法一：分治（递归）——双O(n)的做法

做这道题前强烈建议先去做一下[从前序与中序建树](https://blog.letmefly.xyz/2024/02/20/LeetCode%200105.%E4%BB%8E%E5%89%8D%E5%BA%8F%E4%B8%8E%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86%E5%BA%8F%E5%88%97%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91/)。我们知道：

+ 前序遍历：<font color='gray'>根</font> <font color='red'>左子树</font> <font color='blue'>右子树</font>
+ 后序遍历：<font color='red'>左子树</font> <font color='blue'>右子树</font> <font color='gray'>根</font>

我们需要明白：**左子树和右子树只有一个的情况下，仅仅通过前序遍历和后续遍历的结果是无法得到原树是左子还是右子的**。这是因为，对于某个只有一个子树的节点：

> + 假设此节点只有<font color='red'>左子树</font>，那么遍历结果为：前序【<font color='gray'>根</font> <font color='red'>左子树</font>】后序【<font color='red'>左子树</font><font color='gray'>根</font>】
> + 假设此节点只有<font color='blue'>右子树</font>，那么遍历结果为：前序【<font color='gray'>根</font> <font color='blue'>右子树</font>】后序【<font color='blue'>右子树</font><font color='gray'>根</font>】
>
> 仅凭遍历结果无法得知到底是<font color='red'>左子树</font>还是<font color='blue'>右子树</font>

因此我们可以按照“只有一个子树的情况下将其还原为左子树”的方式进行建树。

因此我们可以写一个函数```dfs```接收```前序遍历数组```和```后序遍历数组```作为参数：

> 1. 以```前序遍历数组```的第一个节点（或者说```后序遍历数组```的最后一个节点）为<font color='gray'>根</font>
>
> 2. 如果```前序遍历数组```的长度为```1```，那么说明只有<font color='gray'>根</font>节点，直接返回。
>
> 3. 否则必定存在<font color='red'>左子树</font>（前面我们得出了结论，即使只有一个子树也可以视为<font color='red'>左子树</font>）。因此我们只需要得到<font color='red'>左子树</font>和<font color='blue'>右子树</font>（可能为空但无所谓）的长度，就能在```前序遍历数组```和```后序遍历数组```中将二者划分出来，并继续递归。确定<font color='red'>左子树</font>长度的方法为：
>
>    > 在```前序遍历数组```中，<font color='red'>左子树</font>的第一个节点为<font color='red'>左子树</font>的根节点。
>    >
>    > 在```后序遍历数组```中，<font color='red'>左子树</font>的最后一个节点为<font color='red'>左子树</font>的根节点。
>    >
>    > 因此从```前序遍历数组```中可以得到<font color='red'>左子树</font>的根节点，由这个节点在```后序遍历数组```中的位置，能得到<font color='red'>左子树</font>的长度。
>    >
>    > 从而<font color='blue'>右子树</font>的长度也能从任意一个遍历数组中，减去<font color='red'>左子树</font>的长度（减<font color='gray'>根</font>节点的长度）得出。
>    >
>    >

递归的终止条件为“前序遍历数组为空”，此时返回空节点。

**Tips:** 可以在预处理时建立一个哈希表，以便能快速地找到左子树的根节点在后序遍历数组中的位置。

+ 时间复杂度$O(N)$，其中$N$是节点个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<int, vector<int>::iterator> ma;
    
    TreeNode* dfs(vector<int>::iterator preLeft, vector<int>::iterator preRight, vector<int>::iterator postLeft, vector<int>::iterator postRight) {
        if (preLeft >= preRight) {
            return nullptr;
        }
        if (preLeft + 1 == preRight) {  // 只有一个节点
            return new TreeNode(*preLeft);
        }
        int leftLength = leftLength = ma[*(preLeft + 1)] - postLeft + 1;  // 注意是*(preLeft + 1)
        return new TreeNode(
            *preLeft,
            dfs(preLeft + 1, preLeft + 1 + leftLength, postLeft, postLeft + leftLength),
            dfs(preLeft + 1 + leftLength, preRight, postLeft + leftLength, postRight - 1)
        );
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preOrder, vector<int>& postOrder) {
        for (vector<int>::iterator it = postOrder.begin(); it != postOrder.end(); it++) {
            ma[*it] = it;
        }
        return dfs(preOrder.begin(), preOrder.end(), postOrder.begin(), postOrder.end());
    }
};
```

#### Python

```python
# from typing import List, Optional

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, preOrder: List[int], preLeft: int, preRight: int, postOrder: List[int], postLeft: int, postRight: int) -> Optional[TreeNode]:
        if preLeft >= preRight:
            return None
        if preLeft + 1 == preRight:
            return TreeNode(preOrder[preLeft])
        leftLength = self.ma[preOrder[preLeft + 1]] - postLeft + 1
        return TreeNode(
            preOrder[preLeft],
            self.dfs(preOrder, preLeft + 1, preLeft + 1 + leftLength, postOrder, postLeft, postLeft + leftLength),
            self.dfs(preOrder, preLeft + 1 + leftLength, preRight, postOrder, postLeft + leftLength, postRight - 1)
        )
    
    def constructFromPrePost(self, preOrder: List[int], postOrder: List[int]) -> TreeNode:
        self.ma = dict()
        for i in range(len(postOrder)):
            self.ma[postOrder[i]] = i
        return self.dfs(preOrder, 0, len(preOrder), postOrder, 0, len(postOrder))
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/22/LeetCode%200889.%E6%A0%B9%E6%8D%AE%E5%89%8D%E5%BA%8F%E5%92%8C%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86%E6%9E%84%E9%80%A0%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136227823](https://letmefly.blog.csdn.net/article/details/136227823)
