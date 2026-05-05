---
title: 61.旋转链表：算总长——算新头
date: 2026-05-05 11:51:19
tags: [题解, LeetCode, 中等, 链表, 双指针, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】61.旋转链表：算总长——算新头

力扣题目链接：[https://leetcode.cn/problems/rotate-list/](https://leetcode.cn/problems/rotate-list/)

<p>给你一个链表的头节点 <code>head</code> ，旋转链表，将链表每个节点向右移动&nbsp;<code>k</code><em>&nbsp;</em>个位置。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg" style="width: 450px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 2
<strong>输出：</strong>[4,5,1,2,3]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg" style="width: 305px; height: 350px;" />
<pre>
<strong>输入：</strong>head = [0,1,2], k = 4
<strong>输出：</strong>[2,0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 500]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：两次遍历

第一次遍历一遍链表，计算出链表长度$n$，将链表尾节点指向头节点，形成循环链表。

之后将$k\mod n$，将链表右移$k$次相当于令倒数第$k$个节点变成新链表的头部，即将正着数第$n-k$个节点变成新头。

让新头节点的上一个节点next指向空，返回新头节点就好了。

> 注意链表可能为空，记得避免空指针情况发生。

+ 时间复杂度$O(len(listnode))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-05 11:49:41
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        
        int n = 1;
        ListNode* p = head;
        while (p->next) {
            n++;
            p = p->next;
        }
        p->next = head;
        k %= n;
        k = n - k;

        p = head;
        for (int i = 1; i < k; i++) {
            p = p->next;
        }
        ListNode* ans = p->next;
        p->next = nullptr;
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160789919)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/05/LeetCode%200061.%E6%97%8B%E8%BD%AC%E9%93%BE%E8%A1%A8/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
