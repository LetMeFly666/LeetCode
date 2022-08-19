---
title: 203.移除链表元素
date: 2022-08-19 08:41:38
tags: [题解, LeetCode, 简单, 递归, 链表]
---

# 【LetMeFly】203.移除链表元素：添加临时头节点以便操作

力扣题目链接：[https://leetcode.cn/problems/remove-linked-list-elements/](https://leetcode.cn/problems/remove-linked-list-elements/)

给你一个链表的头节点 <code>head</code> 和一个整数 <code>val</code> ，请你删除链表中所有满足 <code>Node.val == val</code> 的节点，并返回 <strong>新的头节点</strong> 。
<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg" style="width: 500px; height: 142px;" />
<pre>
<strong>输入：</strong>head = [1,2,6,3,4,5,6], val = 6
<strong>输出：</strong>[1,2,3,4,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [], val = 1
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [7,7,7,7], val = 7
<strong>输出：</strong>[]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>列表中的节点数目在范围 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>1 <= Node.val <= 50</code></li>
	<li><code>0 <= val <= 50</code></li>
</ul>


    
## 方法一：添加临时头节点以便操作

这个解法的思路是，添加一个临时头节点，并把临时头节点的```next```指向原始头节点。这样，就避免了删除头节点的麻烦操作。之后遍历并删除值为```val```的节点。最后，返回临时头节点的下一个节点即可。

具体遍历删除方法为：

使用两个指针，```last```指向上一个元素，```current```指向当前遍历到的元素。（初始值```current = head```，相应地，```last = 临时头节点```）

之后在当前指针```current```不为空时：

+ 如果```current```的值恰好等于```val```，那么就让```last```的```next```指向```current```的```next```，并将```current```指向```current```的```next```（相当于删除了```current```）
+ 否则，将```last```指向```current```，并将```current```指向```current```的```next```（相当于往后继续遍历）

:rose:

+ 时间复杂度$O(n)$，其中$n$是链表节点个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ansHead = new ListNode;
        ansHead->next = head;
        ListNode* last = ansHead, *current = ansHead->next;
        while (current) {
            if (current->val == val) {
                last->next = current->next;
                // delete current;  // Here should delete actually
                current = current->next;
            }
            else {
                last = current;
                current = current->next;
            }
        }
        // ListNode* head = ansHead;
        // delete head;
        return ansHead->next;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/19/LeetCode%200203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126417421](https://letmefly.blog.csdn.net/article/details/126417421)
