---
title: 86.分隔链表
date: 2022-06-26 10:30:54
tags: [题解, LeetCode, 中等, 链表, 双指针]
---

# 【LetMeFly】86.分隔链表

力扣题目链接：[https://leetcode.cn/problems/partition-list/](https://leetcode.cn/problems/partition-list/)

<p>给你一个链表的头节点 <code>head</code> 和一个特定值<em> </em><code>x</code> ，请你对链表进行分隔，使得所有 <strong>小于</strong> <code>x</code> 的节点都出现在 <strong>大于或等于</strong> <code>x</code> 的节点之前。</p>

<p>你应当 <strong>保留</strong> 两个分区中每个节点的初始相对位置。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/partition.jpg" style="width: 662px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,4,3,2,5,2], x = 3
<strong>输出</strong>：[1,2,2,4,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [2,1], x = 2
<strong>输出</strong>：[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 200]</code> 内</li>
	<li><code>-100 <= Node.val <= 100</code></li>
	<li><code>-200 <= x <= 200</code></li>
</ul>


## 方法一：双指针

这一题我们只需要把原始链表依据“是否小于x”的规则分成两个链表，再把两个链表合并即可。

首先定义两个新的头节点，遍历原始链表，把每个节点分别添加到新的对应的链表中。

最后，把“小于x的链表”的最后一个节点的next指向“大于等于x的链表”的第一个节点，把“大于等于x的链表”的最后一个节点的next置空，返回“小于x的链表”的第一个节点即可。

具体实现可详见代码注释。


+ 时间复杂度$O(N)$，其中$N$是原始链表的节点个数
+ 空间复杂度$O(1)$，只需要常数个节点（把节点添加到链表尾部只需要修改next指针，并不需要额外的空间）

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* le = new ListNode, *ge = new ListNode;  // 小于x的链表、大于等于x的链表
        ListNode* p1 = le, *p2 = ge;  // 两个指针
        while (head) {  // 遍历原始链表
            if (head->val < x) {
                p1->next = head;  // 添加到“小于x的链表”后面
                p1 = p1->next;  // 指针后移
            }
            else {
                p2->next = head;  // // 添加到“大于等于x的链表”后面
                p2 = p2->next;
            }
            head = head->next;
        }
        p1->next = ge->next;  // “小于x的链表”的最后一个节点指向“大于等于x的链表”的第一个节点（头节点为空，并未存储值，因此指向ge->next）
        p2->next = nullptr;  // “大于等于x的链表”的最后一个节点的next置空
        return le->next;  // 返回“小于x的链表”的第一个节点
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/06/26/LeetCode%200086.%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125467594](https://letmefly.blog.csdn.net/article/details/125467594)
    