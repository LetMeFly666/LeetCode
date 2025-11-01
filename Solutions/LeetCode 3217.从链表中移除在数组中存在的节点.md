---
title: 3217.从链表中移除在数组中存在的节点：哈希表(一次遍历)
date: 2025-11-01 21:55:22
tags: [题解, LeetCode, 中等, 数组, 哈希表, set, 链表]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample0.png
---

# 【LetMeFly】3217.从链表中移除在数组中存在的节点：哈希表(一次遍历)

力扣题目链接：[https://leetcode.cn/problems/delete-nodes-from-linked-list-present-in-array/](https://leetcode.cn/problems/delete-nodes-from-linked-list-present-in-array/)

<p>给你一个整数数组 <code>nums</code> 和一个链表的头节点 <code>head</code>。从链表中<strong>移除</strong>所有存在于 <code>nums</code> 中的节点后，返回修改后的链表的头节点。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3], head = [1,2,3,4,5]</span></p>

<p><strong>输出：</strong> <span class="example-io">[4,5]</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample0.png" style="width: 400px; height: 66px;" /></strong></p>

<p>移除数值为 1, 2 和 3 的节点。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1], head = [1,2,1,2,1,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">[2,2,2]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample1.png" style="height: 62px; width: 450px;" /></p>

<p>移除数值为 1 的节点。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [5], head = [1,2,3,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">[1,2,3,4]</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2024/06/11/linkedlistexample2.png" style="width: 400px; height: 83px;" /></strong></p>

<p>链表中不存在值为 5 的节点。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums</code> 中的所有元素都是唯一的。</li>
	<li>链表中的节点数在 <code>[1, 10<sup>5</sup>]</code> 的范围内。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>输入保证链表中至少有一个值没有在&nbsp;<code>nums</code> 中出现过。</li>
</ul>


    
## 解题方法：哈希表

使用哈希表记录$nums$中都出现了哪些元素。

为了方便可以在链表第一个节点前设置一个一定不会被删除的没有实际值的“表头”，并使用两个变量$last$和$now$记录上一个遍历到的节点和当前节点。

在$now$不为空时，若$now$在$nums$中出现过，则扔掉$now$（更新$last$的$next$为$now$的$next$、$now$后移）；否则不删$now$（$last$和$now$都指向下一个节点）。

+ 时间复杂度$O(len(nums) + len(list))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-11-01 21:54:45
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* now) {
        unordered_set<int> se(nums.begin(), nums.end());
        ListNode* head = new ListNode(0, now);  // 不可以：ListNode* head(0, now);  // Most Vexing Parse
        ListNode* last = head;
        while (now) {
            if (se.count(now->val)) {
                now = now->next;
                last->next = now;
            } else {
                last = now;
                now = now->next;
            }
        }
        return head->next;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/154259704)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/11/01/LeetCode%203217.%E4%BB%8E%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%A7%BB%E9%99%A4%E5%9C%A8%E6%95%B0%E7%BB%84%E4%B8%AD%E5%AD%98%E5%9C%A8%E7%9A%84%E8%8A%82%E7%82%B9/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
