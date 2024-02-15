---
title: 1171.从链表中删去总和值为零的连续节点
date: 2023-06-11 14:55:02
tags: [题解, LeetCode, 中等, 哈希表, 哈希, map, 链表, 前缀和]
---

# 【LetMeFly】1171.从链表中删去总和值为零的连续节点

力扣题目链接：[https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/](https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

<p>给你一个链表的头节点&nbsp;<code>head</code>，请你编写代码，反复删去链表中由 <strong>总和</strong>&nbsp;值为 <code>0</code> 的连续节点组成的序列，直到不存在这样的序列为止。</p>

<p>删除完毕后，请你返回最终结果链表的头节点。</p>

<p>&nbsp;</p>

<p>你可以返回任何满足题目要求的答案。</p>

<p>（注意，下面示例中的所有序列，都是对&nbsp;<code>ListNode</code>&nbsp;对象序列化的表示。）</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>head = [1,2,-3,3,1]
<strong>输出：</strong>[3,1]
<strong>提示：</strong>答案 [1,2,1] 也是正确的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>head = [1,2,3,-3,4]
<strong>输出：</strong>[1,2,4]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1,2,3,-3,-2]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给你的链表中可能有 <code>1</code> 到&nbsp;<code>1000</code>&nbsp;个节点。</li>
	<li>对于链表中的每个节点，节点的值：<code>-1000 &lt;= node.val &lt;= 1000</code>.</li>
</ul>


    
## 方法一：哈希表 + 前缀和

假如从第一个节点到第$a$个节点之和是$cnt$，并且第一个节点到第$b$个节点之和也是$cnt$，那么就说明第$a$个节点到第$b$个节点之和是$0$，将$a$节点的$next$赋值为$b$节点的$next$即可。

因此我们只需要使用哈希表，遍历一遍列表，计算得到前$i$个节点的和，并存入哈希表$lastAppear。这样$lastAppear[cnt]$就为最后一个前缀和为$cnt$的节点。

再次遍历一遍列表，将当前节点的$next$替换为最后一个前缀和也为$cnt$的节点的$next$即可。

+ 时间复杂度$O(n)$，其中$n$是链表中元素的个数。
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* emptyHead = new ListNode(0, head);
        unordered_map<int, ListNode*> lastAppear;
        int cnt = 0;
        for (ListNode* node = emptyHead; node; node = node->next) {
            cnt += node->val;
            lastAppear[cnt] = node;
        }
        cnt = 0;
        for (ListNode* node = emptyHead; node; node = node->next) {
            cnt += node->val;
            node->next = lastAppear[cnt]->next;
        }
        return emptyHead->next;
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
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        emptyHead = ListNode(0, head)
        lastAppear = dict()
        cnt = 0
        node = emptyHead
        while node:
            cnt += node.val
            lastAppear[cnt] = node
            node = node.next
        cnt = 0
        node = emptyHead
        while node:
            cnt += node.val
            node.next = lastAppear[cnt].next
            node = node.next
        return emptyHead.next
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/11/LeetCode%201171.%E4%BB%8E%E9%93%BE%E8%A1%A8%E4%B8%AD%E5%88%A0%E5%8E%BB%E6%80%BB%E5%92%8C%E5%80%BC%E4%B8%BA%E9%9B%B6%E7%9A%84%E8%BF%9E%E7%BB%AD%E8%8A%82%E7%82%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131153552](https://letmefly.blog.csdn.net/article/details/131153552)
