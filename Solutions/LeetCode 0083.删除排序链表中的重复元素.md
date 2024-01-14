---
title: 83.删除排序链表中的重复元素
date: 2024-01-14 11:10:17
tags: [题解, LeetCode, 简单, 链表]
---

# 【LetMeFly】83.删除排序链表中的重复元素：模拟

力扣题目链接：[https://leetcode.cn/problems/remove-duplicates-from-sorted-list/](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/)

<p>给定一个已排序的链表的头<meta charset="UTF-8" />&nbsp;<code>head</code>&nbsp;，&nbsp;<em>删除所有重复的元素，使每个元素只出现一次</em>&nbsp;。返回 <em>已排序的链表</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/list1.jpg" style="height: 160px; width: 200px;" />
<pre>
<strong>输入：</strong>head = [1,1,2]
<strong>输出：</strong>[1,2]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/list2.jpg" style="height: 123px; width: 300px;" />
<pre>
<strong>输入：</strong>head = [1,1,2,3,3]
<strong>输出：</strong>[1,2,3]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数目在范围 <code>[0, 300]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li>题目数据保证链表已经按升序 <strong>排列</strong></li>
</ul>


    
## 方法一：模拟

当```当前节点```和```下一个节点```都非空时：

+ 如果```当前节点```和```下一个节点```值相同，就删掉```下一个节点```（```now->next = now->next->next```）
+ 否则，```当前节点```后移（```now = now->next```）

最终返回传入的头节点即可。

+ 时间复杂度$O(len(nodelist))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;
        while (head && head->next) {
            if (head->val == head->next->val) {
                head->next = head->next->next;  // haven't delete node
            }
            else {
                head = head->next;
            }
        }
        return ans;
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
        ans = head
        while head and head.next:
            if head.val == head.next.val:
                head.next = head.next.next
            else:
                head = head.next
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/01/14/LeetCode%200083.%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135581000](https://letmefly.blog.csdn.net/article/details/135581000)
