---
title: 109.有序链表转换二叉搜索树
date: 2022-07-09 11:28:51
tags: [题解, LeetCode, 中等, 树, 二叉搜索树, 链表, 分治, 二叉树, BST, 哈希]
---

# 【LetMeFly】109.有序链表转换二叉搜索树 - 链表中值为根，中值左右分别为左右子树

力扣题目链接：[https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/](https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/)

<p>给定一个单链表的头节点 &nbsp;<code>head</code>&nbsp;，其中的元素 <strong>按升序排序</strong> ，将其转换为高度平衡的二叉搜索树。</p>

<p>本题中，一个高度平衡二叉树是指一个二叉树<em>每个节点&nbsp;</em>的左右两个子树的高度差不超过 1。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://img-blog.csdnimg.cn/b3c0269ea1ee43d69db7f7f5f61975f2.jpeg" style="height: 388px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> head = [-10,-3,0,5,9]
<strong>输出:</strong> [0,-3,9,-10,null,5]
<strong>解释:</strong> 一个可能的答案是[0，-3,9，-10,null,5]，它表示所示的高度平衡的二叉搜索树。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> head = []
<strong>输出:</strong> []
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>head</code>&nbsp;中的节点数在<code>[0, 2 * 10<sup>4</sup>]</code>&nbsp;范围内</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：链表中值为根，中值左右分别为左右子树

这题与[LeetCode 0108.将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)类似。

区别是```本题```将```0108```的```有序数组```变成了```有序链表```。

因此我们仍然采用[LeetCode 0108](https://letmefly.blog.csdn.net/article/details/125610878)的思路，并用哈希表记录一下```链表的第几个元素的值是多少```即可。

具体方法请参考[https://letmefly.blog.csdn.net/article/details/125610878](https://letmefly.blog.csdn.net/article/details/125610878)

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数。
+ 空间复杂度$O(\log n)$，取决于递归栈的深度。

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<int, int> ma;

    TreeNode* build(int l, int r) {  // [l, r)
        if (l >= r)
            return nullptr;
        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(ma[mid]);
        root->left = build(l, mid);
        root->right = build(mid + 1, r);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int th = 0;
        while (head) {
            ma[th++] = head->val;
            head = head->next;
        }
        return build(0, th);
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/09/LeetCode%200109.%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8%E8%BD%AC%E6%8D%A2%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125691471](https://letmefly.blog.csdn.net/article/details/125691471)
