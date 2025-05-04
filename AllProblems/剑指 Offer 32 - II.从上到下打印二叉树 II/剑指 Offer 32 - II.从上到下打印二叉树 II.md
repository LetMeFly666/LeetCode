---
title: 剑指 Offer 32 - II.从上到下打印二叉树 II
date: 2022-06-02 20-16-07
tags: [题解, LeetCode, 简单, 树, 广度优先搜索, 二叉树]
---

# 【LetMeFly】剑指 Offer 32 - II.从上到下打印二叉树 II

力扣题目链接：[https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/](https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/)

<p>从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。</p>

<p>&nbsp;</p>

<p>例如:<br>
给定二叉树:&nbsp;<code>[3,9,20,null,null,15,7]</code>,</p>

<pre>    3
   / \
  9  20
    /  \
   15   7
</pre>

<p>返回其层次遍历结果：</p>

<pre>[
  [3],
  [9,20],
  [15,7]
]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>节点总数 &lt;= 1000</code></li>
</ol>

<p>注意：本题与主站 102 题相同：<a href="https://leetcode-cn.com/problems/binary-tree-level-order-traversal/">https://leetcode-cn.com/problems/binary-tree-level-order-traversal/</a></p>


    