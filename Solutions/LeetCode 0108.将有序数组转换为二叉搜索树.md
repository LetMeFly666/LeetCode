---
title: 108.将有序数组转换为二叉搜索树
date: 2022-07-04 23:34:38
tags: [题解, LeetCode, 简单, 树, 二叉搜索树, 数组, 分治, 二叉树, BST]
---

# 【LetMeFly】108.将有序数组转换为二叉搜索树 - 数组中值为根，中值左右分别为左右子树

力扣题目链接：[https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)

<p>给你一个整数数组 <code>nums</code> ，其中元素已经按 <strong>升序</strong> 排列，请你将其转换为一棵 <strong>高度平衡</strong> 二叉搜索树。</p>

<p><strong>高度平衡 </strong>二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg" style="width: 302px; height: 222px;" />
<pre>
<strong>输入：</strong>nums = [-10,-3,0,5,9]
<strong>输出：</strong>[0,-3,9,-10,null,5]
<strong>解释：</strong>[0,-10,5,null,-3,null,9] 也将被视为正确答案：
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg" style="width: 302px; height: 222px;" />
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree.jpg" style="width: 342px; height: 142px;" />
<pre>
<strong>输入：</strong>nums = [1,3]
<strong>输出：</strong>[3,1]
<strong>解释：</strong>[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 按 <strong>严格递增</strong> 顺序排列</li>
</ul>

<small>其实我觉得这题难度设置为中等也不错</small>
    
## 方法一：数组中值为根，中值左右分别为左右子树

顾名思义，要想让这棵树为高度平衡的二叉搜索树，我们只需要把数组的中值作为根即可。

因为把数组的中值作为根，即可达到左边右边的元素数量相等(或相差一个)的效果。

同时，题目给定的是一颗已经排序过的数组，因此数组中值左边的元素全部小于中值元素，右边全部大于。

因此把中值左边全部作为左子树，右边全部作为右子树即可。

这就变成了子问题：左右子树的构建。因此递归即可。

终止条件：要构建的数组为空。

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数。
+ 空间复杂度$O(\log n)$，取决于递归栈的深度。

### AC代码

#### C++

```cpp
class Solution {
private:
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l >= r)
            return nullptr;

        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, l, mid);
        root->right = build(nums, mid + 1, r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/04/LeetCode%200108.%E5%B0%86%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125610878](https://letmefly.blog.csdn.net/article/details/125610878)
