---
title: 2058.找出临界点之间的最小和最大距离：遍历+遇到极值则更新(这种题谁空间复杂度不是O(1)啊)
date: 2026-09-01 13:11:02
tags: [题解, LeetCode, 中等, 链表]
categories: [题解, LeetCode]
---

# 【LetMeFly】2058.找出临界点之间的最小和最大距离：遍历+遇到极值则更新(这种题谁空间复杂度不是O(1)啊)

力扣题目链接：[https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/](https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)

<p>链表中的 <strong>临界点</strong> 定义为一个 <strong>局部极大值点</strong> <strong>或</strong> <strong>局部极小值点 。</strong></p>

<p>如果当前节点的值 <strong>严格大于</strong> 前一个节点和后一个节点，那么这个节点就是一个<strong>&nbsp; 局部极大值点</strong> 。</p>

<p>如果当前节点的值 <strong>严格小于</strong> 前一个节点和后一个节点，那么这个节点就是一个<strong>&nbsp; 局部极小值点</strong> 。</p>

<p>注意：节点只有在同时存在前一个节点和后一个节点的情况下，才能成为一个 <strong>局部极大值点 / 极小值点</strong> 。</p>

<p>给你一个链表 <code>head</code> ，返回一个长度为 2 的数组<em> </em><code>[minDistance, maxDistance]</code> ，其中<em> </em><code>minDistance</code><em> </em>是任意两个不同临界点之间的最小距离，<code>maxDistance</code> 是任意两个不同临界点之间的最大距离。如果临界点少于两个，则返回 <code>[-1，-1]</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/13/a1.png" style="width: 148px; height: 55px;" /></p>

<pre>
<strong>输入：</strong>head = [3,1]
<strong>输出：</strong>[-1,-1]
<strong>解释：</strong>链表 [3,1] 中不存在临界点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/13/a2.png" style="width: 624px; height: 46px;" /></p>

<pre>
<strong>输入：</strong>head = [5,3,1,2,5,1,2]
<strong>输出：</strong>[1,3]
<strong>解释：</strong>存在三个临界点：
- [5,3,<em><strong>1</strong></em>,2,5,1,2]：第三个节点是一个局部极小值点，因为 1 比 3 和 2 小。
- [5,3,1,2,<em><strong>5</strong></em>,1,2]：第五个节点是一个局部极大值点，因为 5 比 2 和 1 大。
- [5,3,1,2,5,<em><strong>1</strong></em>,2]：第六个节点是一个局部极小值点，因为 1 比 5 和 2 小。
第五个节点和第六个节点之间距离最小。minDistance = 6 - 5 = 1 。
第三个节点和第六个节点之间距离最大。maxDistance = 6 - 3 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/14/a5.png" style="width: 624px; height: 39px;" /></p>

<pre>
<strong>输入：</strong>head = [1,3,2,2,3,2,2,2,7]
<strong>输出：</strong>[3,3]
<strong>解释：</strong>存在两个临界点：
- [1,<em><strong>3</strong></em>,2,2,3,2,2,2,7]：第二个节点是一个局部极大值点，因为 3 比 1 和 2 大。
- [1,3,2,2,<em><strong>3</strong></em>,2,2,2,7]：第五个节点是一个局部极大值点，因为 3 比 2 和 2 大。
最小和最大距离都存在于第二个节点和第五个节点之间。
因此，minDistance 和 maxDistance 是 5 - 2 = 3 。
注意，最后一个节点不算一个局部极大值点，因为它之后就没有节点了。
</pre>

<p><strong>示例 4：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/10/13/a4.png" style="width: 345px; height: 52px;" /></p>

<pre>
<strong>输入：</strong>head = [2,3,3,2]
<strong>输出：</strong>[-1,-1]
<strong>解释：</strong>链表 [2,3,3,2] 中不存在临界点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数量在范围 <code>[2, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：遍历

其实这道题遍历极值点并不难：

> 使用两个变量记录前两个节点的值，如果第二个节点相比第一个节点和当前节点都大/都小，则第二个节点即为极值点。

在此基础上维护极值点之间的最大最小间隔就可以了：

> 使用几个变量：上一个极值点下标、第一个极值点下标、最短距离、最大距离，初始值都是$-1$。
>
> 一旦遇到极值点，则看是否为第一个极值点（值为$-1$则是），若是第一个极值点则更新：上一个极值点下标、第一个极值点下标；否则则更新：最大距离（当前极值点下标 - 第一个极值点下标）、最小距离（min(上次最小距离, 当前极值点下标 - 上一个极值点下标)）、上一个极值点下标（更新为当前下标）

最后直接返回{最短距离、最大距离}就好。

+ 时间复杂度$O(len(list))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-01 13:10:00
 */
class Solution {
private:
    int lastIdx = -1, firstIdx = -1;
    int mDis = -1;
    int MDis = -1;

    void updateDis(int idx) {
        // cout << idx << endl;
        if (lastIdx == -1) {
            firstIdx = lastIdx = idx;
            return;
        }
        int dis = idx - lastIdx;
        if (mDis == -1) {
            mDis = MDis = dis;
        } else {
            mDis = min(mDis, dis);
            MDis = idx - firstIdx;
        }
        lastIdx = idx;  // 看来思路还是不能断啊
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstVal = head->val;
        int secondVal = head->next->val;
        int idx = 0;
        for (head = head->next->next; head; head = head->next, idx++) {
            int nowVal = head->val;
            if (secondVal < firstVal && secondVal < nowVal || secondVal > firstVal && secondVal > nowVal) {
                updateDis(idx);
            }
            firstVal = secondVal;
            secondVal = nowVal;
        }
        return {mDis, MDis};
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/164258148)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/01/LeetCode%202058.%E6%89%BE%E5%87%BA%E4%B8%B4%E7%95%8C%E7%82%B9%E4%B9%8B%E9%97%B4%E7%9A%84%E6%9C%80%E5%B0%8F%E5%92%8C%E6%9C%80%E5%A4%A7%E8%B7%9D%E7%A6%BB/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
