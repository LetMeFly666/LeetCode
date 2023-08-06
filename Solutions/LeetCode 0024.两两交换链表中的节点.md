---
title: 24.两两交换链表中的节点：粗暴易懂的方法（几个临时变量）
date: 2023-08-06 10:08:48
tags: [题解, LeetCode, 中等, 递归, 链表]
---

# 【LetMeFly】24.两两交换链表中的节点：粗暴易懂的方法（几个临时变量）

力扣题目链接：[https://leetcode.cn/problems/swap-nodes-in-pairs/](https://leetcode.cn/problems/swap-nodes-in-pairs/)

<p>给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg" style="width: 422px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[2,1,4,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>


    
## 方法一：粗暴易懂的方法（几个临时变量）

遇到链表的题不用怕，可以**先用几个临时变量将需要记录的节点记录下来，之后随意更改要重新指向的next**。

```
0 -> 1 -> 2 -> 3
已|   正在   |未
```

对于本题，我们可以使用4个临时变量：

1. ```p```指向已经处理过的部分的最后一个节点（0）
2. ```first```指向待处理的第一个节点（1）
3. ```second```指向待处理的第二个节点（2）
4. ```third```指向还未处理到的第一个节点（4，可能为空）

由于需要进行如下更改：

```
0 -> 1 -> 2 -> 3
  |         |
  |    ↓    |
  |         |
0 -> 2 -> 1 -> 3
```

所以只需要：

1. ```p->next = second```
2. ```first->next = third```
3. ```second->next = first```

这样，原本的```1 -> 2```就处理完毕了，下一个待处理节点变成```3 -> ...```，第一个未处理的节点变成了```1```

所以只需```p = first```即可。

**细节处理：**

我们可以添加一个临时的头节点，代表“已处理部分的最后一个节点”，最终返回临时头节点的next即可。

+ 时间复杂度$O(len(list))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* p) {
        ListNode* head = new ListNode(0, p);
        p = head;
        while (p->next && p->next->next) {
            ListNode* first = p->next, *second = first->next, *third = second->next;
            p->next = second, first->next = third, second->next = first;
            p = first;
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
    def swapPairs(self, p: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(0, p)
        p = head
        while p.next and p.next.next:
            first, second, third = p.next, p.next.next, p.next.next.next
            p.next, first.next, second.next = second, third, first
            p = first
        return head.next
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/08/06/LeetCode%200024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132128294](https://letmefly.blog.csdn.net/article/details/132128294)
