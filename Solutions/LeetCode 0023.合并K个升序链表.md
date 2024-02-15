---
title: 23.合并 K 个升序链表
date: 2023-08-12 08:39:44
tags: [题解, LeetCode, 困难, 链表, 分治, 堆（优先队列）, 归并排序, 优先队列]
---

# 【LetMeFly】23.合并 K 个升序链表

力扣题目链接：[https://leetcode.cn/problems/merge-k-sorted-lists/](https://leetcode.cn/problems/merge-k-sorted-lists/)

<p>给你一个链表数组，每个链表都已经按升序排列。</p>

<p>请你将所有链表合并到一个升序链表中，返回合并后的链表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>lists = [[1,4,5],[1,3,4],[2,6]]
<strong>输出：</strong>[1,1,2,3,4,4,5,6]
<strong>解释：</strong>链表数组如下：
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
将它们合并到一个有序链表中得到。
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>lists = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>lists = [[]]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10^4</code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10^4 &lt;= lists[i][j] &lt;= 10^4</code></li>
	<li><code>lists[i]</code> 按 <strong>升序</strong> 排列</li>
	<li><code>lists[i].length</code> 的总和不超过 <code>10^4</code></li>
</ul>


    
## 方法一：优先队列

我们只需要将每个链表的 当前节点（初始值是表头） 放入小根堆中，每次从小根堆中取出一个节点并拼接起来，若这个节点不是表尾节点，则这个节点的下一个节点入队。

+ 时间复杂度$O(N\times \log k)$，其中$n$是所有节点的个数
+ 空间复杂度$O(k)$

### AC代码

#### C++

```cpp
class Solution {
private:
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (ListNode*& node : lists) {
            if (node) {
                pq.push(node);
            }
        }
        ListNode* head = new ListNode(), *p = head;
        while (pq.size()) {
            ListNode* thisNode = pq.top();
            pq.pop();
            p->next = thisNode;
            p = thisNode;
            if (thisNode->next) {
                pq.push(thisNode->next);
            }
        }
        return head->next;
    }
};
```

#### Python

```python
# from typing import List, Optional
# import heapq

# # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# ListNode.__lt__ = lambda a, b: a.val < b.val

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = []
        for node in lists:
            if node:
                heapq.heappush(pq, node)
        head = ListNode()
        p = head
        while pq:
            thisNode = heapq.heappop(pq)
            p.next = thisNode
            p = thisNode
            if thisNode.next:
                heapq.heappush(pq, thisNode.next)
        return head.next
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/08/12/LeetCode%200023.%E5%90%88%E5%B9%B6K%E4%B8%AA%E5%8D%87%E5%BA%8F%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132243952](https://letmefly.blog.csdn.net/article/details/132243952)
