---
title: 2487.从链表中移除节点
date: 2024-01-03 10:23:16
tags: [题解, LeetCode, 中等, 栈, 递归, 链表, 单调栈]
categories: [题解, LeetCode]
---

# 【LetMeFly】2487.从链表中移除节点：单调栈

力扣题目链接：[https://leetcode.cn/problems/remove-nodes-from-linked-list/](https://leetcode.cn/problems/remove-nodes-from-linked-list/)

<p>给你一个链表的头节点 <code>head</code> 。</p>

<p>移除每个右侧有一个更大数值的节点。</p>

<p>返回修改后链表的头节点<em> </em><code>head</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/10/02/drawio.png" style="width: 631px; height: 51px;" /></p>

<pre>
<strong>输入：</strong>head = [5,2,13,3,8]
<strong>输出：</strong>[13,8]
<strong>解释：</strong>需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [1,1,1,1]
<strong>输出：</strong>[1,1,1,1]
<strong>解释：</strong>每个节点的值都是 1 ，所以没有需要移除的节点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给定列表中的节点数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：单调栈

维护一个单调递减栈（严格地说是单调非递增栈）：

> 遍历链表，在```当前节点大于栈顶节点```时不断弹出栈顶节点，然后将当前节点入栈。

最终，从栈底到栈顶的元素就是非递增的了。因此也就得到了想要的链表。

+ 时间复杂度$O(len(listnode))$
+ 空间复杂度$O(len(listnode))$

然后被丢弃节点的delete操作就靠力扣了hh。

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while (head) {
            while (st.size() && st.top()->val < head->val) {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }
        ListNode* lastNode = nullptr;
        while (st.size()) {
            ListNode* thisNode = st.top();
            st.pop();
            thisNode->next = lastNode;
            lastNode = thisNode;
        }
        return lastNode;
    }
};
```

#### Python

```python
class Solution:
    def removeNodes(self, head: ListNode) -> ListNode:
        st = []
        while head:
            while len(st) and st[-1].val < head.val:
                st.pop()
            st.append(head)
            head = head.next
        for i in range(len(st) - 1):
            st[i].next = st[i + 1]
        return st[0]
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/03/LeetCode%202487.%E4%BB%8E%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%A7%BB%E9%99%A4%E8%8A%82%E7%82%B9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135357617](https://letmefly.blog.csdn.net/article/details/135357617)
