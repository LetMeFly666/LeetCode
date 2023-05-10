---
title: 817.链表组件
date: 2022-10-12 10:41:44
tags: [题解, LeetCode, 中等, 哈希表, 哈希, 链表]
---

# 【LetMeFly】817.链表组件

力扣题目链接：[https://leetcode.cn/problems/linked-list-components/](https://leetcode.cn/problems/linked-list-components/)

<p>给定链表头结点&nbsp;<code>head</code>，该链表上的每个结点都有一个 <strong>唯一的整型值</strong> 。同时给定列表&nbsp;<code>nums</code>，该列表是上述链表中整型值的一个子集。</p>

<p>返回列表&nbsp;<code>nums</code>&nbsp;中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表&nbsp;<code>nums</code>&nbsp;中）构成的集合。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<!-- <p><img src="https://assets.leetcode.com/uploads/2021/07/22/lc-linkedlistcom1.jpg" /></p> -->

<p><img src="https://img-blog.csdnimg.cn/06fae68410c945fc9c392ddca9a2c185.jpeg" /></p>

<pre>
<strong>输入:</strong> head = [0,1,2,3], nums = [0,1,3]
<strong>输出:</strong> 2
<strong>解释:</strong> 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回 2。</pre>

<p><strong>示例 2：</strong></p>

<!-- <p><strong>&nbsp;</strong><img src="https://assets.leetcode.com/uploads/2021/07/22/lc-linkedlistcom2.jpg" /></p> -->

<p><strong>&nbsp;</strong><img src="https://img-blog.csdnimg.cn/81397d1ff87c4fd5ad764a13232139a3.jpeg" /></p>

<pre>
<strong>输入:</strong> head = [0,1,2,3,4], nums = [0,3,1,4]
<strong>输出:</strong> 2
<strong>解释:</strong> 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点数为<code>n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= Node.val &lt; n</code></li>
	<li><code>Node.val</code>&nbsp;中所有值 <strong>不同</strong></li>
	<li><code>1 &lt;= nums.length &lt;= n</code></li>
	<li><code>0 &lt;= nums[i] &lt; n</code></li>
	<li><code>nums</code> 中所有值 <strong>不同</strong></li>
</ul>


    
## 方法一：哈希

首先遍历一遍$nums$数组，将其中的所有元素都存入哈希表中（例如C++中的```unordered_set```）。这样判断链表中的某个元素是否存在于$nums$中的时间复杂度就变成了$O(1)$

之后遍历链表，用一个布尔类型的变量```lastIsIn```来记录链表的上一个节点是否存在于$nums$中

若“上一个节点不在$nums$中且这一个节点在$nums$中”，则“控件”个数+1

+ 时间复杂度$O(n)$，其中$n$是$nums$中元素的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> se;
        for (int& t : nums) {
            se.insert(t);
        }
        int ans = 0;
        bool lastIsIn = false;
        while (head) {
            if (se.count(head->val) && !lastIsIn) {
                ans++;
            }
            lastIsIn = se.count(head->val);
            head = head->next;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/10/12/LeetCode%200817.%E9%93%BE%E8%A1%A8%E7%BB%84%E4%BB%B6/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127278261](https://letmefly.blog.csdn.net/article/details/127278261)
