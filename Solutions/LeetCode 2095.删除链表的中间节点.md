---
title: 2095.删除链表的中间节点：两次遍历 / 一次遍历（快慢指针）
date: 2026-06-15 17:22:42
tags: [题解, LeetCode, 中等, 链表, 双指针]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png
---

# 【LetMeFly】2095.删除链表的中间节点：两次遍历 / 一次遍历（快慢指针）

力扣题目链接：[https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/](https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/)

<p>给你一个链表的头节点 <code>head</code> 。<strong>删除</strong> 链表的 <strong>中间节点</strong> ，并返回修改后的链表的头节点 <code>head</code> 。</p>

<p>长度为 <code>n</code> 链表的中间节点是从头数起第 <code>⌊n / 2⌋</code> 个节点（下标从 <strong>0</strong> 开始），其中 <code>⌊x⌋</code> 表示小于或等于 <code>x</code> 的最大整数。</p>

<ul>
	<li>对于 <code>n</code> = <code>1</code>、<code>2</code>、<code>3</code>、<code>4</code> 和 <code>5</code> 的情况，中间节点的下标分别是 <code>0</code>、<code>1</code>、<code>1</code>、<code>2</code> 和 <code>2</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png" style="width: 500px; height: 77px;" /></p>

<pre>
<strong>输入：</strong>head = [1,3,4,7,1,2,6]
<strong>输出：</strong>[1,3,4,1,2,6]
<strong>解释：</strong>
上图表示给出的链表。节点的下标分别标注在每个节点的下方。
由于 n = 7 ，值为 7 的节点 3 是中间节点，用红色标注。
返回结果为移除节点后的新链表。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg2drawio.png" style="width: 250px; height: 43px;" /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[1,2,4]
<strong>解释：</strong>
上图表示给出的链表。
对于 n = 4 ，值为 3 的节点 2 是中间节点，用红色标注。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/11/16/eg3drawio.png" style="width: 150px; height: 58px;" /></p>

<pre>
<strong>输入：</strong>head = [2,1]
<strong>输出：</strong>[2]
<strong>解释：</strong>
上图表示给出的链表。
对于 n = 2 ，值为 1 的节点 1 是中间节点，用红色标注。
值为 2 的节点 0 是移除节点 1 后剩下的唯一一个节点。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[1, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法一：两次遍历

第一次使用一个指针从头到尾遍历链表，求出链表中一共有多少个节点。

第二次使用一个指针走到待删除节点的前一个节点，将这个前向节点指向待删除节点的下一个节点并删掉待删除节点。

返回原始链表头节点。

**特别的**

当链表中只有一个节点时：

+ 待删除节点没有前向节点，所以需要我们特判
+ 我们不能真的删掉这个唯一的节点，否则力扣在尝试删除链表的时候会RE。

以上。

+ 时间复杂度$O(n)$，其中$n$是链表中节点数量
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-15 17:17:32
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int cnt = 0;
        for (ListNode* p = head; p; cnt++, p = p->next) {}
        if (cnt == 1) {
            // delete head;  // cannot，否则力扣尝试删除head会报错
            return nullptr;
        }
        
        ListNode* p = head;
        for (int i = 1, target = cnt / 2; i < target; i++) {  // 7->4, 4->3
            p = p->next;
        }
        ListNode* to_remove = p->next;  // 一定非null
        p->next = to_remove->next;
        delete to_remove;
        return head;
    }
};
```

## 解题方法二：快慢指针一次遍历

使用两个指针同时指向链表的头节点，(当快指针和快指针的下一个节点都非空时)快指针每次右移两个节点慢指针每次右移一个。

移动结束后，慢指针指向位置即为待删除节点。我们在移动慢指针的时候可以同时记录下慢指针的上一个节点，最终这个节点即为待删除节点的前一个节点。

**特别的**

当链表中只有一个节点时：

+ 待删除节点没有前向节点，所以需要我们特判
+ 我们不能真的删掉这个唯一的节点，否则力扣在尝试删除链表的时候会RE。

以上。

+ 时间复杂度$O(n)$，其中$n$是链表中节点数量
+ 空间复杂度$O(1)$

### AC代码


#### C++

```cpp
/*
 * @LastEditTime: 2026-06-15 17:21:46
 */
/*
1  2
||
   |  |
*/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head, *last = head;
        while (fast && fast->next) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow == head) {
            return nullptr;
        }
        last->next = slow->next;
        delete slow;
        return head;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162012068)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/15/LeetCode%202095.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E4%B8%AD%E9%97%B4%E8%8A%82%E7%82%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
