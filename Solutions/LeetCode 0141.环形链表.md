---
title: 141.环形链表
date: 2022-07-27 15:53:16
tags: [题解, LeetCode, 简单, 哈希表, 链表, 双指针, 快慢指针, 为了过题而过题]
categories: [题解, LeetCode]
---

# 【LetMeFly】三种方法解决：141.环形链表

力扣题目链接：[https://leetcode.cn/problems/linked-list-cycle/](https://leetcode.cn/problems/linked-list-cycle/)

<p>给你一个链表的头节点 <code>head</code> ，判断链表中是否有环。</p>

<p>如果链表中有某个节点，可以通过连续跟踪 <code>next</code> 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（索引从 0 开始）。<strong>注意：<code>pos</code> 不作为参数进行传递&nbsp;</strong>。仅仅是为了标识链表的实际情况。</p>

<p><em>如果链表中存在环</em>&nbsp;，则返回 <code>true</code> 。 否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" /></p>

<pre>
<strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>true
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" /></p>

<pre>
<strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>true
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" /></p>

<pre>
<strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>false
<strong>解释：</strong>链表中没有环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围是 <code>[0, 10<sup>4</sup>]</code></li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> 为 <code>-1</code> 或者链表中的一个 <strong>有效索引</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能用 <code>O(1)</code>（即，常量）内存解决此问题吗？</p>


    
## 方法一：哈希表

原理很简单，遍历链表，用哈希表记录遍历过的节点。

遍历过程中，如果发现某个节点已经存在于哈希表中了，就说明这个节点遍历过了，也就是说**有环**

一旦遍历到了“next为空”的某个节点，就说明这个节点是链表的最后一个节点，也就是说**无环**

+ 时间复杂度$O(n)$，其中$n$是链表中节点的个数。C++中若使用```unordered_set```，则插入和判断是否存在的复杂度都为$O(1)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> se;
        while (head) {
            if (se.count(head))
                return true;
            se.insert(head);
            head = head->next;
        }
        return false;
    }
};
```

## 方法二：快慢指针

道理也不难，用两个指针，初始位置都指向链表头节点。

每次快指针向后移动两个节点，慢指针向后移动一个节点。

如果快指针移动到了链表尾部，就说明链表无环

如果快慢指针相遇了，就说明链表有环

**注意：**若有环，则快慢指针一定会相遇。因为快指针一定比慢指针提前进入到环中，等慢指针也进入环中后，快指针一定会追上满指针（因为速度是慢指针的两倍），并且一定不会不相遇而直接跳过去（慢指针移动前的旧位置和移动后的新位置共$2$个节点，快指针一次前进$2$个节点，必定踩上一个）

+ 时间复杂度$O(n)$，其中$n$是链表中节点的个数。慢指针的速度是快指针的一半，快指针会在两圈内追上慢指针
+ 空间复杂度$O(1)$

### AC代码

#### C++

使用```do - while```：

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode *fast = head, *slow = head;
        do {
            if (!fast->next || !fast->next->next) {  // 走到尾了
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        return fast == slow;
    }
};
```

更简便的方式，直接使用while且不特判头节点是否为空：

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};
```

#### Python

```python
# from typing import Optional

# # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast, slow = head, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                return True
        return False
```

## 方法三：为了过题而过题

这个方法不实用，但是能够用简短的代码通过该题。

题目说了链表长度最多为$10^4$，因此我们可以遍历链表的同时计数，如果节点个数超过了$10^4$，就说明有节点遍历了不只一次，即说明链表中有环。

+ 时间复杂度$O(n \vee C)$，其中$n$是链表中节点的个数。$C$是链表中节点的最大数目（本题为$10^4$）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        int count = 0;
        while (head) {
            count++;
            if (count > 10000)
                return true;
            head = head->next;
        }
        return false;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/27/LeetCode%200141.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126017056](https://letmefly.blog.csdn.net/article/details/126017056)
