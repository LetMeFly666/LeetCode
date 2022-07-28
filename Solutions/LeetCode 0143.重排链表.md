---
title: 143.重排链表
date: 2022-07-28 11:32:11
tags: [题解, LeetCode, 中等, 栈, 递归, 链表, 双指针, 哈希表, 数组]
---

# 【LetMeFly】143.重排链表

力扣题目链接：[https://leetcode.cn/problems/reorder-list/](https://leetcode.cn/problems/reorder-list/)

<p>给定一个单链表 <code>L</code><em> </em>的头节点 <code>head</code> ，单链表 <code>L</code> 表示为：</p>

<pre>
L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

<p>请将其重新排列后变为：</p>

<pre>
L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …</pre>

<p>不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<!-- <p><img alt="" src="https://pic.leetcode-cn.com/1626420311-PkUiGI-image.png" style="width: 240px; " /></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/8af42f232ca647fcbef61f28611c7f47.png" style="width: 240px; " /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[1,4,2,3]</pre>

<p><strong>示例 2：</strong></p>

<!-- <p><img alt="" src="https://pic.leetcode-cn.com/1626420320-YUiulT-image.png" style="width: 320px; " /></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/f38f64faab124f53ae3c293a76a10b2f.png" style="width: 320px; " /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4,5]
<strong>输出：</strong>[1,5,2,4,3]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的长度范围为 <code>[1, 5 * 10<sup>4</sup>]</code></li>
	<li><code>1 &lt;= node.val &lt;= 1000</code></li>
</ul>


    
## 方法一：哈希表

遍历链表，将链表节点存入哈希表中，映射关系为```<[第几个节点, 节点]>``` （其实这里使用数组也可以，虽然复杂度相同，但是数组的实际开销还是要小一些）

然后，用两个指针$l$和$r$，分别指向前面该处理的节点和后面该处理的节点

当前指针超过后指针时，退出循环。

**注意事项：**

1. 用head遍历完链表后，head已经不再指向头节点，记得将head归位
2. 记得将链表的最后一个节点的next置空

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
class Solution {
public:
    void reorderList(ListNode* head) {
        unordered_map<int, ListNode*> ma;
        int cnt = 0;
        while (head) {
            ma[cnt++] = head;
            head = head->next;
        }
        head = ma[0];  // head归位
        int l = 1, r = cnt - 1;  // 待指定
        bool front = false;
        while (l <= r) {
            if (front) {
                head->next = ma[l++];
                front = false;
            }
            else {
                head->next = ma[r--];
                front = true;
            }
            head = head->next;
        }
        head->next = nullptr;  // 最后一个节点的next置空
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/28/LeetCode%200143.%E9%87%8D%E6%8E%92%E9%93%BE%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126031446](https://letmefly.blog.csdn.net/article/details/126031446)
