---
title: 328.奇偶链表
date: 2022-09-24 08:28:40
tags: [题解, LeetCode, 中等, 链表]
categories: [题解, LeetCode]
---

# 【LetMeFly】328.奇偶链表

力扣题目链接：[https://leetcode.cn/problems/odd-even-linked-list/](https://leetcode.cn/problems/odd-even-linked-list/)

<p>给定单链表的头节点&nbsp;<code>head</code>&nbsp;，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，然后返回重新排序的列表。</p>

<p><strong>第一个</strong>节点的索引被认为是 <strong>奇数</strong> ， <strong>第二个</strong>节点的索引为&nbsp;<strong>偶数</strong> ，以此类推。</p>

<p>请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。</p>

<p>你必须在&nbsp;<code>O(1)</code>&nbsp;的额外空间复杂度和&nbsp;<code>O(n)</code>&nbsp;的时间复杂度下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg" style="height: 123px; width: 300px;" /></p>

<pre>
<strong>输入: </strong>head = [1,2,3,4,5]
<strong>输出:</strong>&nbsp;[1,3,5,2,4]</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg" style="height: 142px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> head = [2,1,3,5,6,4,7]
<strong>输出:</strong> [2,3,6,7,1,5,4]</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n ==&nbsp;</code> 链表中的节点数</li>
	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：先将奇偶链表分开，再合并

建立两个空的头节点```odd```和```even```，这两个节点不存放数据，而只是为了后续合并的方便。

用一个变量记录当前遍历到了原始链表的第几个节点，以此来判断将此节点添加到哪个链表的尾部。

遍历原始链表，将节点添加到相应的“奇链表”的尾部或“偶链表”的尾部

最后，将奇链表的尾部元素的next指向偶链表的第一个元素（空的头节点的next），并将偶链表的最后一个节点的next置空。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$，虽然中间过程将奇偶链表分别存放了，但是并没有开辟太多的额外空间

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode;
        ListNode* even = new ListNode;
        ListNode* pOdd = odd, *pEven = even;
        int cnt = 0;
        while (head) {
            if (cnt % 2) {
                pEven->next = head;
                pEven = head;
            }
            else {
                pOdd->next = head;
                pOdd = head;
            }
            head = head->next;
            cnt++;            
        }
        pOdd->next = even->next;
        pEven->next = nullptr;
        return odd->next;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/24/LeetCode%200328.%E5%A5%87%E5%81%B6%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127020912](https://letmefly.blog.csdn.net/article/details/127020912)
