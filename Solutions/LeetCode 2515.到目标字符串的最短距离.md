---
title: 2515.到目标字符串的最短距离：从中间往两边遍历
date: 2026-04-15 23:16:19
tags: [题解, LeetCode, 简单, 数组, 字符串, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2515.到目标字符串的最短距离：从中间往两边遍历

力扣题目链接：[https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/](https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/)

<p>给你一个下标从 <strong>0</strong> 开始的 <strong>环形</strong> 字符串数组 <code>words</code> 和一个字符串 <code>target</code> 。<strong>环形数组</strong> 意味着数组首尾相连。</p>

<ul>
	<li>形式上， <code>words[i]</code> 的下一个元素是 <code>words[(i + 1) % n]</code> ，而 <code>words[i]</code> 的前一个元素是 <code>words[(i - 1 + n) % n]</code> ，其中 <code>n</code> 是 <code>words</code> 的长度。</li>
</ul>

<p>从 <code>startIndex</code> 开始，你一次可以用 <code>1</code> 步移动到下一个或者前一个单词。</p>

<p>返回到达目标字符串 <code>target</code> 所需的最短距离。如果 <code>words</code> 中不存在字符串 <code>target</code> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
<strong>输出：</strong>1
<strong>解释：</strong>从下标 1 开始，可以经由以下步骤到达 "hello" ：
- 向右移动 3 个单位，到达下标 4 。
- 向左移动 2 个单位，到达下标 4 。
- 向右移动 4 个单位，到达下标 0 。
- 向左移动 1 个单位，到达下标 0 。
到达 "hello" 的最短距离是 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
<strong>输出：</strong>1
<strong>解释：</strong>从下标 0 开始，可以经由以下步骤到达 "leetcode" ：
- 向右移动 2 个单位，到达下标 2 。
- 向左移动 1 个单位，到达下标 2 。
到达 "leetcode" 的最短距离是 1 。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["i","eat","leetcode"], target = "ate", startIndex = 0
<strong>输出：</strong>-1
<strong>解释：</strong>因为 words 中不存在字符串 "ate" ，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 和 <code>target</code> 仅由小写英文字母组成</li>
	<li><code>0 &lt;= startIndex &lt; words.length</code></li>
</ul>


    
## 解题方法：遍历

从startIndex开始往两边遍历，每个方向最多走$\lfloor\frac{len(words)}{2}+1\rfloor$步。

遇到target则立刻返回，最终都没有遇到则返回-1。

+ 时间复杂度$O(len(words)\times len(target))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-04-15 23:13:18
 */
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        for (int i = 0, n = words.size(), to = n / 2 + 1; i < to; i++) {
            if (words[(startIndex + i) % n] == target || words[(startIndex - i + n) % n] == target) {
                return i;
            }
        }
        return -1;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160193379)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/15/LeetCode%202515.%E5%88%B0%E7%9B%AE%E6%A0%87%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E7%9F%AD%E8%B7%9D%E7%A6%BB/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
