---
title: 142.环形链表 II
date: 2022-07-28 11:06:13
tags: [题解, LeetCode, 中等, 哈希表, 链表, 双指针]
categories: [题解, LeetCode]
---

# 【LetMeFly】142.环形链表 II

力扣题目链接：[https://leetcode.cn/problems/linked-list-cycle-ii/](https://leetcode.cn/problems/linked-list-cycle-ii/)

<p>给定一个链表的头节点 &nbsp;<code>head</code>&nbsp;，返回链表开始入环的第一个节点。&nbsp;<em>如果链表无环，则返回&nbsp;<code>null</code>。</em></p>

<p>如果链表中有某个节点，可以通过连续跟踪 <code>next</code> 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（<strong>索引从 0 开始</strong>）。如果 <code>pos</code> 是 <code>-1</code>，则在该链表中没有环。<strong>注意：<code>pos</code> 不作为参数进行传递</strong>，仅仅是为了标识链表的实际情况。</p>

<p><strong>不允许修改 </strong>链表。</p>

<ul>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png" /></p>

<pre>
<strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>返回索引为 1 的链表节点
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" /></p>

<pre>
<strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>返回索引为 0 的链表节点
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" /></p>

<pre>
<strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>返回 null
<strong>解释：</strong>链表中没有环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目范围在范围 <code>[0, 10<sup>4</sup>]</code> 内</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>pos</code> 的值为 <code>-1</code> 或者链表中的一个有效索引</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你是否可以使用 <code>O(1)</code> 空间解决此题？</p>


    
## 方法一：哈希表

这道题类似 [LeetCode 141.环形链表](https://leetcode.cn/problems/linked-list-cycle/LeetCode ) ，可参考题解[https://blog.letmefly.xyz/2022/07/27/LeetCode 0141.环形链表/](https://blog.letmefly.xyz/2022/07/27/LeetCode%200141.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8/)的方法一

同样地，我们用哈希表记录每个节点是否出现过，之后遍历链表。如果遇到了出现过的节点，那么就说明这个节点是环的开始，直接返回这个节点即可。

如果遍历到了链表的末尾，就说明无环，返回```nullptr```

+ 时间复杂度$O(n)$，其中$n$是链表中的节点个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> se;
        while (head) {
            if (se.count(head))
                return head;
            se.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
```

## 方法二：快慢指针

这次“快慢指针”是数学方法，真的是挺玄学的。

具体我就不推公式了，感兴趣了可参考下[官方博客](https://leetcode.cn/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/)的方法二。

+ 时间复杂度$O(n)$，其中$n$是链表中的节点个数
+ 空间复杂度$O(1)$


### AC代码

#### C++

来自官方题解：

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/28/LeetCode%200142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126030761](https://letmefly.blog.csdn.net/article/details/126030761)
