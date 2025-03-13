---
title: 206.反转链表
date: 2022-08-21 10:35:55
tags: [题解, LeetCode, 简单, 递归, 链表, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】206.反转链表

力扣题目链接：[https://leetcode.cn/problems/reverse-linked-list/](https://leetcode.cn/problems/reverse-linked-list/)

给你单链表的头节点 <code>head</code> ，请你反转链表，并返回反转后的链表。
<div class="original__bRMd">
<div>
<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5]
<strong>输出：</strong>[5,4,3,2,1]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 182px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2]
<strong>输出：</strong>[2,1]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = []
<strong>输出：</strong>[]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围是 <code>[0, 5000]</code></li>
	<li><code>-5000 <= Node.val <= 5000</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？</p>
</div>
</div>


    
## 方法一：遍历过程中，记录上一个节点

要把链表翻转，也就是把本应该指向下一个节点的指针指向上一个节点。

我们只需要遍历一遍链表，并记录下链表的上一个节点（初始值为```null```）

这样，在遍历过程中，我们先记录下下一个节点是什么，将这个节点的```next```指向上一个节点，并更新当前节点和上一个节点，直到遍历到节点尾部即可。

+ 时间复杂度$O(n)$，其中$n$是链表长度
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
// From 2022-08-21 10:33:03 To 2022-08-21 10:34:04
// 1min 码完
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* lastNode = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = lastNode;
            lastNode = head;
            head = nextNode;
        }
        return lastNode;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/21/LeetCode%200206.%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126448252](https://letmefly.blog.csdn.net/article/details/126448252)
