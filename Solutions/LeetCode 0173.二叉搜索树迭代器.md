---
title: 173.二叉搜索树迭代器
date: 2022-08-05 16:31:03
tags: [题解, LeetCode, 中等, 栈, 树, 设计, 二叉搜索树, 二叉树, 迭代器, 中序遍历, 中序遍历的非递归实现]
---

# 【LetMeFly】173.二叉搜索树迭代器：中序遍历的非递归实现

力扣题目链接：[https://leetcode.cn/problems/binary-search-tree-iterator/](https://leetcode.cn/problems/binary-search-tree-iterator/)

实现一个二叉搜索树迭代器类<code>BSTIterator</code> ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
<div class="original__bRMd">
<div>
<ul>
	<li><code>BSTIterator(TreeNode root)</code> 初始化 <code>BSTIterator</code> 类的一个对象。BST 的根节点 <code>root</code> 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。</li>
	<li><code>boolean hasNext()</code> 如果向指针右侧遍历存在数字，则返回 <code>true</code> ；否则返回 <code>false</code> 。</li>
	<li><code>int next()</code>将指针向右移动，然后返回指针处的数字。</li>
</ul>

<p>注意，指针初始化为一个不存在于 BST 中的数字，所以对 <code>next()</code> 的首次调用将返回 BST 中的最小元素。</p>
</div>
</div>

<p>你可以假设 <code>next()</code> 调用总是有效的，也就是说，当调用 <code>next()</code> 时，BST 的中序遍历中至少存在一个下一个数字。</p>

<p> </p>

<p><strong>示例：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png" style="width: 189px; height: 178px;" />
<pre>
<strong>输入</strong>
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
<strong>输出</strong>
[null, 3, 7, true, 9, true, 15, true, 20, false]

<strong>解释</strong>
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // 返回 3
bSTIterator.next();    // 返回 7
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 9
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 15
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 20
bSTIterator.hasNext(); // 返回 False
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>0 <= Node.val <= 10<sup>6</sup></code></li>
	<li>最多调用 <code>10<sup>5</sup></code> 次 <code>hasNext</code> 和 <code>next</code> 操作</li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<ul>
	<li>你可以设计一个满足下述条件的解决方案吗？<code>next()</code> 和 <code>hasNext()</code> 操作均摊时间复杂度为 <code>O(1)</code> ，并使用 <code>O(h)</code> 内存。其中 <code>h</code> 是树的高度。</li>
</ul>


    
## 方法一：中序遍历的非递归实现

二叉树的中序遍历使用递归很容易实现，但是如果不适用递归就需要用栈来模拟。

用一个栈来存放“经过”但待“遍历”的节点，用一个指针指向待遍历节点。

初始时将根节点入栈，并将指针指向根节点。

每次都将指针不断向左子移动，直到没有左子为止（中序遍历应先遍历左子），移动过程中将每个节点入栈。

从栈顶取出一个元素，这个元素就是最左子，现在就“遍历”到它了，返回这个元素，并将指针指向这个元素的右子

+ 时间复杂度$O(1)$，总复杂度为$O(n)$，平均一次复杂度为$O(1)$
+ 空间复杂度$O(n)$，其中$n$是二叉树节点个数

### AC代码

#### C++

```cpp
class BSTIterator {
private:
    stack<TreeNode*> st;
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        int ans = cur->val;
        cur = cur->right;
        return ans;
    }
    
    bool hasNext() {
        return cur != nullptr || st.size();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/05/LeetCode%200173.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E8%BF%AD%E4%BB%A3%E5%99%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126181336](https://letmefly.blog.csdn.net/article/details/126181336)
