---
title: 2130.链表最大孪生和：转数组 / 快慢指针+链表翻转（O(1)）
date: 2026-06-14 22:52:21
tags: [题解, LeetCode, 中等, 栈, 链表, 双指针]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/12/03/eg1drawio.png
---

# 【LetMeFly】2130.链表最大孪生和：转数组 / 快慢指针+链表翻转（O(1)）

力扣题目链接：[https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/](https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/)

<p>在一个大小为&nbsp;<code>n</code>&nbsp;且 <code>n</code>&nbsp;为&nbsp;<strong>偶数</strong> 的链表中，对于&nbsp;<code>0 &lt;= i &lt;= (n / 2) - 1</code>&nbsp;的 <code>i</code>&nbsp;，第&nbsp;<code>i</code>&nbsp;个节点（下标从 <strong>0</strong>&nbsp;开始）的孪生节点为第&nbsp;<code>(n-1-i)</code>&nbsp;个节点 。</p>

<ul>
	<li>比方说，<code>n = 4</code>&nbsp;那么节点&nbsp;<code>0</code>&nbsp;是节点 <code>3</code>&nbsp;的孪生节点，节点 <code>1</code>&nbsp;是节点 <code>2</code>&nbsp;的孪生节点。这是长度为 <code><span style="">n = 4</span></code>&nbsp;的链表中所有的孪生节点。</li>
</ul>

<p><strong>孪生和</strong>&nbsp;定义为一个节点和它孪生节点两者值之和。</p>

<p>给你一个长度为偶数的链表的头节点&nbsp;<code>head</code>&nbsp;，请你返回链表的 <strong>最大孪生和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/12/03/eg1drawio.png" style="width: 250px; height: 70px;"></p>

<pre><b>输入：</b>head = [5,4,2,1]
<b>输出：</b>6
<strong>解释：</strong>
节点 0 和节点 1 分别是节点 3 和 2 的孪生节点。孪生和都为 6 。
链表中没有其他孪生节点。
所以，链表的最大孪生和是 6 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/12/03/eg2drawio.png" style="width: 250px; height: 70px;"></p>

<pre><b>输入：</b>head = [4,2,2,3]
<b>输出：</b>7
<strong>解释：</strong>
链表中的孪生节点为：
- 节点 0 是节点 3 的孪生节点，孪生和为 4 + 3 = 7 。
- 节点 1 是节点 2 的孪生节点，孪生和为 2 + 2 = 4 。
所以，最大孪生和为 max(7, 4) = 7 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/12/03/eg3drawio.png" style="width: 200px; height: 88px;"></p>

<pre><b>输入：</b>head = [1,100000]
<b>输出：</b>100001
<strong>解释：</strong>
链表中只有一对孪生节点，孪生和为 1 + 100000 = 100001 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的节点数目是&nbsp;<code>[2, 10<sup>5</sup>]</code>&nbsp;中的&nbsp;<strong>偶数</strong>&nbsp;。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法一：转数组

遍历一遍链表，并且把链表中的每一个元素放入数组中。

使用两个指针分别指向数组中第一个和最后一个元素，当左指针在右指针之前时，不断更新答案最大值并靠近两指针。

+ 时间复杂度$O(n)$，其中$n$是链表中节点数量
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-14 21:48:39
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int ans = 0;
        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        for (int l = 0, r = vals.size() - 1; l < r; l++, r--) {
            ans = max(ans, vals[l] + vals[r]);
        }
        return ans;
    }
};
```

## 解题方法二：快慢指针+链表翻转

这道题可以变成两道题的组合再加一点。

第一道题 —— 快慢指针确定链表中间节点：

> 两个指针初始时都指向第一个节点，慢指针每次右移一个节点快指针每次右移两个，当快指针为空时即说明慢指针指向了中间节点（偏右一个）。

第二道题 —— 链表翻转：

> 将后半部分的链表翻转，使用三个指针分别指向*上一个节点*、*当前节点*、*下一个节点*，遍历一遍链表并：*将当前节点的next指向上一个节点*、*将当前节点赋值为下一个节点*、*将上一个节点赋值为当前节点*，直至当前节点为空时停止。


再加一点：

> 同时遍历前后两个链表，若前面链表指针指到了后半段链表则停止遍历。
>
> 遍历过程中更新答案最大值。

What's more：

> 由于本题是在后半段链表开始翻转的，所以实际上后半段链表的第一个元素的next没有被修改过的话，会形成环。这样力扣在尝试delete链表的时候就会RE。
>
> 我们可以在翻转完后半段链表后将翻转过的链表最后一个节点(即为原始链表中后半段的第一个节点)的next置空。

+ 时间复杂度$O(n)$，其中$n$是链表中节点数量
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-06-14 22:51:59
 */
/*
1 2
  | |

1 2 3 4
  | |
    |   |
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast) {
            fast = fast->next->next;  // 因为链表是偶数个节点，所以fast->next一定非null
            slow = slow->next;
        }

        ListNode* last = slow;
        for (ListNode* now = last->next; now; ) {
            ListNode* next = now->next;
            now->next = last;
            last = now;
            now = next;
        }
        slow->next = nullptr;

        int ans = 0;
        ListNode* p1 = head, *p2 = last;
        while (p1 != slow) {
            ans = max(ans, p1->val + p2->val);
            p1 = p1->next, p2 = p2->next;
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161985371)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/06/14/LeetCode%202130.%E9%93%BE%E8%A1%A8%E6%9C%80%E5%A4%A7%E5%AD%AA%E7%94%9F%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
