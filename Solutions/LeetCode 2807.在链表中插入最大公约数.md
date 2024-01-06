---
title: 2807.在链表中插入最大公约数
date: 2024-01-06 11:35:29
tags: [题解, LeetCode, 中等, 数组, 链表, 数学, 模拟]
---

# 【LetMeFly】2807.在链表中插入最大公约数

力扣题目链接：[https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list/](https://leetcode.cn/problems/insert-greatest-common-divisors-in-linked-list/)

<p>给你一个链表的头&nbsp;<code>head</code>&nbsp;，每个结点包含一个整数值。</p>

<p>在相邻结点之间，请你插入一个新的结点，结点值为这两个相邻结点值的 <strong>最大公约数</strong>&nbsp;。</p>

<p>请你返回插入之后的链表。</p>

<p>两个数的 <strong>最大公约数</strong>&nbsp;是可以被两个数字整除的最大正整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/07/18/ex1_copy.png" style="width: 641px; height: 181px;"></p>

<pre><b>输入：</b>head = [18,6,10,3]
<b>输出：</b>[18,6,6,2,10,1,3]
<b>解释：</b>第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点）。
- 18 和 6 的最大公约数为 6 ，插入第一和第二个结点之间。
- 6 和 10 的最大公约数为 2 ，插入第二和第三个结点之间。
- 10 和 3 的最大公约数为 1 ，插入第三和第四个结点之间。
所有相邻结点之间都插入完毕，返回链表。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/07/18/ex2_copy1.png" style="width: 51px; height: 191px;"></p>

<pre><b>输入：</b>head = [7]
<strong>输出：</strong>[7]
<b>解释：</b>第一幅图是一开始的链表，第二幅图是插入新结点后的图（蓝色结点为新插入结点）。
没有相邻结点，所以返回初始链表。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中结点数目在&nbsp;<code>[1, 5000]</code> 之间。</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>


    
## 方法一：模拟

注意到“最大公约数”都是在两个节点之间插入的，因此“当前节点非空 且 下一个节点非空”的时候不断往后遍历节点，创建一个新节点（值为二者的最大公约数）插入到二者中间，用“下一个节点”覆盖“当前节点”继续循环。

+ 时间复杂度$O(len(listnode))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        while (head && head->next) {
            ListNode* middle = new ListNode(__gcd(head->val, head->next->val));
            middle->next = head->next;
            head->next = middle;
            head = middle->next;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import Optional
# from math import gcd

# # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ans = head
        while head and head.next:
            mid = ListNode(gcd(head.val, head.next.val))
            mid.next = head.next
            head.next = mid
            head = mid.next
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/01/06/LeetCode%202807.%E5%9C%A8%E9%93%BE%E8%A1%A8%E4%B8%AD%E6%8F%92%E5%85%A5%E6%9C%80%E5%A4%A7%E5%85%AC%E7%BA%A6%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135424056](https://letmefly.blog.csdn.net/article/details/135424056)
