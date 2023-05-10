---
title: 234.回文链表
date: 2022-09-08 16:25:07
tags: [题解, LeetCode, 简单, 栈, 递归, 链表, 双指针, 回文]
---

# 【LetMeFly】234.回文链表

力扣题目链接：[https://leetcode.cn/problems/palindrome-linked-list/](https://leetcode.cn/problems/palindrome-linked-list/)

<p>给你一个单链表的头节点 <code>head</code> ，请你判断该链表是否为回文链表。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg" style="width: 422px; height: 62px;" />
<pre>
<strong>输入：</strong>head = [1,2,2,1]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg" style="width: 182px; height: 62px;" />
<pre>
<strong>输入：</strong>head = [1,2]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目在范围<code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能否用&nbsp;<code>O(n)</code> 时间复杂度和 <code>O(1)</code> 空间复杂度解决此题？</p>


    
## 方法一：复制到数组

首先遍历一遍链表，将链表存放为一个线性表（如数组）

之后遍历数组的前半部分，并判断是否和后半部分对应位置相同。

+ 时间复杂度$O(n)$，其中$n$是链表中节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < a.size() / 2; i++) {
            if (a[i] != a[a.size() - i - 1])
                return false;
        }
        return true;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/08/LeetCode%200234.%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126767188](https://letmefly.blog.csdn.net/article/details/126767188)
