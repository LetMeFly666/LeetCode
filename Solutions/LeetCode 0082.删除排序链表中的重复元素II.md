---
title: 82.删除排序链表中的重复元素 II
date: 2024-01-15 21:42:35
tags: [题解, LeetCode, 中等, 链表, 双指针]
categories: [题解, LeetCode]
---

# 【LetMeFly】82.删除排序链表中的重复元素 II：模拟

力扣题目链接：[https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/)

<p>给定一个已排序的链表的头&nbsp;<code>head</code> ，&nbsp;<em>删除原始链表中所有重复数字的节点，只留下不同的数字</em>&nbsp;。返回 <em>已排序的链表</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg" style="height: 142px; width: 500px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,3,4,4,5]
<strong>输出：</strong>[1,2,5]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg" style="height: 164px; width: 400px;" />
<pre>
<strong>输入：</strong>head = [1,1,1,2,3]
<strong>输出：</strong>[2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目在范围 <code>[0, 300]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>题目数据保证链表已经按升序 <strong>排列</strong></li>
</ul>


    
## 方法一：模拟

相同的节点可能被全部删除（头节点可能也会被删），因此我们可以新建一个“空的头节点ans”，ans的next指向head。

使用两个节点lastNode和thisNode，lastNode指向上一个节点（防止当前遍历到的节点被删除），thisNode指向当前处理到的节点。当thisNode和thisNode.next都非空时：

+ 如果```thisNode.val == thisNode.next.val```，新建一个nextNode节点指向thisNode.next.next（最终指向第一个和thisNode的值不同的节点）。当nextNode非空且```nextNode.val == thisNode.val```时，nextNode不断后移。最后将lastNode.next赋值为nextNode，并将thisNode赋值为nextNode（删掉了中间具有相同元素的节点）。
+ 否则，将lastNode和thisNode分别赋值为thisNode和thisNode.next（相当于指针后移）

最终返回“假头节点”ans的next即可。

+ 时间复杂度$O(len(listnode))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode(1000, head);
        ListNode* lastNode = ans, *thisNode = head;
        while (thisNode && thisNode->next) {
            if (thisNode->val == thisNode->next->val) {
                ListNode* nextNode = thisNode->next->next;
                while (nextNode && thisNode->val == nextNode->val) {
                    nextNode = nextNode->next;
                }
                lastNode->next = nextNode;
                thisNode = nextNode;
            }
            else {
                lastNode = thisNode, thisNode = thisNode->next;
            }
        }
        return ans->next;
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
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans = ListNode(1000, head)
        lastNode, thisNode = ans, head
        while thisNode and thisNode.next:
            if thisNode.val == thisNode.next.val:
                nextNode = thisNode.next.next
                while nextNode and thisNode.val == nextNode.val:
                    nextNode = nextNode.next
                lastNode.next = nextNode
                thisNode = nextNode
            else:
                lastNode, thisNode = thisNode, thisNode.next
        return ans.next
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/15/LeetCode%200082.%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135612345](https://letmefly.blog.csdn.net/article/details/135612345)
