---
title: 88.合并两个有序数组：O(m + 1) + O(1)的做法
date: 2023-08-13 08:47:32
tags: [题解, LeetCode, 简单, 数组, 双指针, 排序]
---

# 【LetMeFly】88.合并两个有序数组：O(m + 1) + O(1)的做法

力扣题目链接：[https://leetcode.cn/problems/merge-sorted-array/](https://leetcode.cn/problems/merge-sorted-array/)

<p>给你两个按 <strong>非递减顺序</strong> 排列的整数数组&nbsp;<code>nums1</code><em> </em>和 <code>nums2</code>，另有两个整数 <code>m</code> 和 <code>n</code> ，分别表示 <code>nums1</code> 和 <code>nums2</code> 中的元素数目。</p>

<p>请你 <strong>合并</strong> <code>nums2</code><em> </em>到 <code>nums1</code> 中，使合并后的数组同样按 <strong>非递减顺序</strong> 排列。</p>

<p><strong>注意：</strong>最终，合并后数组不应由函数返回，而是存储在数组 <code>nums1</code> 中。为了应对这种情况，<code>nums1</code> 的初始长度为 <code>m + n</code>，其中前 <code>m</code> 个元素表示应合并的元素，后 <code>n</code> 个元素为 <code>0</code> ，应忽略。<code>nums2</code> 的长度为 <code>n</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
<strong>输出：</strong>[1,2,2,3,5,6]
<strong>解释：</strong>需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [<em><strong>1</strong></em>,<em><strong>2</strong></em>,2,<em><strong>3</strong></em>,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1], m = 1, nums2 = [], n = 0
<strong>输出：</strong>[1]
<strong>解释：</strong>需要合并 [1] 和 [] 。
合并结果是 [1] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [0], m = 0, nums2 = [1], n = 1
<strong>输出：</strong>[1]
<strong>解释：</strong>需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums1.length == m + n</code></li>
	<li><code>nums2.length == n</code></li>
	<li><code>0 &lt;= m, n &lt;= 200</code></li>
	<li><code>1 &lt;= m + n &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums1[i], nums2[j] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计实现一个时间复杂度为 <code>O(m + n)</code> 的算法解决此问题吗？</p>


    
## 方法一：三指针（双指针）

这道题不返回任何值，很显然，出题者想让你在```nums1```数组上原地修改。

怎么原地修改呢？```nums1```后面全是$0$，而这些地方本来应该是“大数”，所以我们使用两个指针，从$nums1$和$nums2$的大数区域往前指，每次将二者较大的那个放到```nums1```后面不就可以了吗。

```
      tail
      ↓
1 3 0 0
  ↑
2 6
  ↑
```

$3 < 6$，所以将$6$放到```tail```处，

```
    tail
    ↓
1 3 0 6
  ↑
2 -
↑
```

$3 > 2$，所以将$3$放到```tail```处，

```
  tail
  ↓
1 - 3 6
↑
2 -
↑
```

$1 < 2$，所以将$2$放到```tail```处，

```
tail
↓
1 2 3 6
↑
- -
```

$nums2$的指针指完了，任务完成，得到$[1, 2, 3, 6]$

+ 时间复杂度$O(m + n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int l1, vector<int>& nums2, int l2) {
        int n = l1 + l2 - 1;
        l1--, l2--;
        while (l2 >= 0) {
            while (l1 >= 0 && nums1[l1] > nums2[l2]) {
                nums1[n--] = nums1[l1--];
            }
            nums1[n--] = nums2[l2--];
        }
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def merge(self, nums1: List[int], l1: int, nums2: List[int], l2: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        l = l1 + l2 - 1
        l1, l2 = l1 - 1, l2 - 1
        while l2 >= 0:
            while l1 >= 0 and nums1[l1] > nums2[l2]:
                nums1[l] = nums1[l1]
                l, l1 = l - 1, l1 - 1
            nums1[l] = nums2[l2]
            l, l2 = l - 1, l2 - 1
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/08/13/LeetCode%200088.%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132256535](https://letmefly.blog.csdn.net/article/details/132256535)
