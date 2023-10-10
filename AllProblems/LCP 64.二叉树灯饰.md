---
title: LCP 64.二叉树灯饰
date: 2023-01-03 18-54-53
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 动态规划, 二叉树]
---

# 【LetMeFly】LCP 64.二叉树灯饰

力扣题目链接：[https://leetcode.cn/problems/U7WvvU/](https://leetcode.cn/problems/U7WvvU/)

<p>「力扣嘉年华」的中心广场放置了一个巨型的二叉树形状的装饰树。每个节点上均有一盏灯和三个开关。节点值为&nbsp;<code>0</code> 表示灯处于「关闭」状态，节点值为 <code>1</code>&nbsp;表示灯处于「开启」状态。每个节点上的三个开关各自功能如下：</p>

<ul>
	<li>开关 <code>1</code>：切换当前节点的灯的状态；</li>
	<li>开关 <code>2</code>：切换 <strong>以当前节点为根</strong>&nbsp;的子树中，所有节点上的灯的状态；</li>
	<li>开关 <code>3</code>：切换 <strong>当前节点及其左右子节点</strong>（若存在的话） 上的灯的状态；</li>
</ul>

<p>给定该装饰的初始状态 <code>root</code>，请返回最少需要操作多少次开关，可以关闭所有节点的灯。</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>root = [1,1,0,null,null,null,1]
<strong>输出：</strong>2
<strong>解释：</strong>以下是最佳的方案之一，如图所示
<img alt="" src="https://pic.leetcode-cn.com/1629357030-GSbzpY-b71b95bf405e3b223e00b2820a062ba4.gif" style="width: 300px; height: 225px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1,1,1,1,null,null,1]
<strong>输出：</strong>1
<strong>解释：</strong>以下是最佳的方案，如图所示
<img alt="" src="https://pic.leetcode-cn.com/1629356950-HZsKZC-a4091b6448a0089b4d9e8f0390ff9ac6.gif" style="width: 300px; height: 225px;" />
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0,null,0]
<strong>输出：</strong>0
<strong>解释：</strong>无需操作开关，当前所有节点上的灯均已关闭
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= 节点个数 &lt;= 10^5</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1</code></li>
</ul>


    