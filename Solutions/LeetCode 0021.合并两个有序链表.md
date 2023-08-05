---
title: 21.合并两个有序链表
date: 2023-08-05 07:57:28
tags: [题解, LeetCode, 简单, 递归, 链表]
---

# 【LetMeFly】21.合并两个有序链表

力扣题目链接：[https://leetcode.cn/problems/merge-two-sorted-lists/](https://leetcode.cn/problems/merge-two-sorted-lists/)

<p>将两个升序链表合并为一个新的 <strong>升序</strong> 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 </p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg" style="width: 662px; height: 302px;" />
<pre>
<strong>输入：</strong>l1 = [1,2,4], l2 = [1,3,4]
<strong>输出：</strong>[1,1,2,3,4,4]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>l1 = [], l2 = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>l1 = [], l2 = [0]
<strong>输出：</strong>[0]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>两个链表的节点数目范围是 <code>[0, 50]</code></li>
	<li><code>-100 <= Node.val <= 100</code></li>
	<li><code>l1</code> 和 <code>l2</code> 均按 <strong>非递减顺序</strong> 排列</li>
</ul>


    
## 方法一：遍历

使用一个指针p指向新的链表，

在list1和list2都非空时：
   + 若$list1->val < list2->val$，则$p->next = list1, list1 = list1->next$
   + 否则，$p->next = list2, list2 = list2->next$

   + 无论如何都：$p = p->next$

+ 时间复杂度$O(len(list1) + len(list2))$（其实为$\min(len(list1), len(list2))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度。（如果list1和list2允许修改的话，空间使用量将会更低）

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* p = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                // list2->=next; （笑）
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1) {
            p->next = list1;
        }
        else {
            p->next = list2;
        }
        return head->next;
    }
};
```

#### Python

```python
# from typing import Optional

# # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        p = head
        while list1 and list2:
            if list1.val < list2.val:
                p.next = list1
                list1 = list1.next
            else:
                p.next = list2
                list2 = list2.next
            p = p.next
        if list1:
            p.next = list1
        else:
            p.next = list2
        return head.next
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/08/05/LeetCode%200021.%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132115272](https://letmefly.blog.csdn.net/article/details/132115272)
