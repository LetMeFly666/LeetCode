---
title: 1290.二进制链表转整数：链表+进制转换
date: 2025-07-14 23:48:16
tags: [题解, LeetCode, 简单, 链表, 数学, 进制, 二进制, 进制转换]
categories: [题解, LeetCode]
index_img: http://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/12/15/graph-1.png
---

# 【LetMeFly】1290.二进制链表转整数：链表+进制转换

力扣题目链接：[https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/](https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/)

<p>给你一个单链表的引用结点&nbsp;<code>head</code>。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。</p>

<p>请你返回该链表所表示数字的 <strong>十进制值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/12/15/graph-1.png" style="height: 108px; width: 426px;"></p>

<pre><strong>输入：</strong>head = [1,0,1]
<strong>输出：</strong>5
<strong>解释：</strong>二进制数 (101) 转化为十进制数 (5)
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>head = [0]
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1]
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
<strong>输出：</strong>18880
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>head = [0,0]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表不为空。</li>
	<li>链表的结点总数不超过&nbsp;<code>30</code>。</li>
	<li>每个结点的值不是&nbsp;<code>0</code> 就是 <code>1</code>。</li>
</ul>


    
## 解题方法：进制转换

二进制如何转为十进制？

初始值$ans = 0$，遍历二进制数字，并令$ans\times 2+当前二进制位$

+ 时间复杂度$O(len(list))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-14 23:37:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-14 23:42:31
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-14 23:37:54
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-14 23:43:59
'''
from typing import Optional

# # Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        ans = 0
        while head:
            ans = ans * 2 + head.val
            head = head.next
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-14 23:37:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-14 23:45:19
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        int ans = 0;
        while (head != null) {
            ans = ans * 2 + head.val;
            head = head.next;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-14 23:37:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-14 23:47:42
 */
package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getDecimalValue(head *ListNode) (ans int) {
    for ; head != nil; head = head.Next {
        ans = ans * 2 + head.Val
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149342077)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/14/LeetCode%201290.%E4%BA%8C%E8%BF%9B%E5%88%B6%E9%93%BE%E8%A1%A8%E8%BD%AC%E6%95%B4%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
