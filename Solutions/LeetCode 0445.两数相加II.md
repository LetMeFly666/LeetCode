---
title: 445.两数相加 II
date: 2022-10-14 10:48:43
tags: [题解, LeetCode, 中等, 栈, 链表, 数学]
---

# 【LetMeFly】445.两数相加 II

力扣题目链接：[https://leetcode.cn/problems/add-two-numbers-ii/](https://leetcode.cn/problems/add-two-numbers-ii/)

<p>给你两个 <strong>非空 </strong>链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。</p>

<p>你可以假设除了数字 0 之外，这两个数字都不会以零开头。</p>

<p>&nbsp;</p>

<p><strong>示例1：</strong></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626420025-fZfzMX-image.png" style="width: 302px; " /></p>

<pre>
<strong>输入：</strong>l1 = [7,2,4,3], l2 = [5,6,4]
<strong>输出：</strong>[7,8,0,7]
</pre>

<p><strong>示例2：</strong></p>

<pre>
<strong>输入：</strong>l1 = [2,4,3], l2 = [5,6,4]
<strong>输出：</strong>[8,0,7]
</pre>

<p><strong>示例3：</strong></p>

<pre>
<strong>输入：</strong>l1 = [0], l2 = [0]
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的长度范围为<code> [1, 100]</code></li>
	<li><code>0 &lt;= node.val &lt;= 9</code></li>
	<li>输入数据保证链表代表的数字无前导 0</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果输入链表不能翻转该如何解决？</p>


    
## 方法一：栈

链表是从前往后的，加法是从后往前的。

因此，栈就很合适。

首先使用两个栈，把两个链表中的元素分别入栈。

这样，在出栈的时候，就是从两个“链表数字”的低位开始运算了。

存放答案的时候同理，我们同样开辟一个“答案栈”，因为是从低位开始运算的，而低位要放到链表最后边。

之后用一个数```carry```来存放“进位”，当有栈不空时，将栈顶元素取出并累加，将```carry```的个位入栈。

之后```carry```对10取模，十位变成新的“进位”

最终，将元素不断从答案栈中取出（是从高位开始取的），逐个添加到链表末尾即可。

+ 时间复杂度$O(n+m)$，其中$n$是第一个链表中的节点个数，$m$是第二个链表的节点个数
+ 空间复杂度$O(n+m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        stack<int> added;
        int carry = 0;
        while (st1.size() || st2.size()) {
            if (st1.size()) {
                carry += st1.top();
                st1.pop();
            }
            if (st2.size()) {
                carry += st2.top();
                st2.pop();
            }
            added.push(carry % 10);
            carry /= 10;
        }
        if (carry)
            added.push(carry);
        ListNode* ans = new ListNode;
        ListNode* p = ans;
        while (added.size()) {
            p->next = new ListNode(added.top());
            added.pop();
            p = p->next;
        }
        return ans->next;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/14/LeetCode%200445.%E4%B8%A4%E6%95%B0%E7%9B%B8%E5%8A%A0II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127316269](https://letmefly.blog.csdn.net/article/details/127316269)
