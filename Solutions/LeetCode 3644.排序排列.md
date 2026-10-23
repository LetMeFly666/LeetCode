---
title: 3644.排序排列：不对则与（脑筋急转弯）
date: 2026-10-23 20:40:06
tags: [题解, LeetCode, 中等, 位运算, 数组, 遍历, 脑筋急转弯]
categories: [题解, LeetCode]
---

# 【LetMeFly】3644.排序排列：不对则与（脑筋急转弯）

力扣题目链接：[https://leetcode.cn/problems/maximum-k-to-sort-a-permutation/](https://leetcode.cn/problems/maximum-k-to-sort-a-permutation/)

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code>，其中 <code>nums</code> 是范围 <code>[0..n - 1]</code> 内所有数字的一个&nbsp;<strong>排列&nbsp;</strong>。</p>

<p>你可以在满足条件 <code>nums[i] AND nums[j] == k</code> 的情况下交换下标&nbsp;<code>i</code> 和 <code>j</code> 的元素，其中 <code>AND</code> 表示按位与操作，<code>k</code> 是一个<strong>非负整数</strong>。</p>

<p>返回可以使数组按&nbsp;<strong>非递减&nbsp;</strong>顺序排序的最大值 <code>k</code>（允许进行任意次这样的交换）。如果 <code>nums</code> 已经是有序的，返回 0。</p>

<p><strong>排列&nbsp;</strong>是数组所有元素的一种重新排列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [0,3,2,1]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p>选择 <code>k = 1</code>。交换 <code>nums[1] = 3</code> 和 <code>nums[3] = 1</code>，因为 <code>nums[1] AND nums[3] == 1</code>，从而得到一个排序后的排列：<code>[0, 1, 2, 3]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [0,1,3,2]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>选择 <code>k = 2</code>。交换 <code>nums[2] = 3</code> 和 <code>nums[3] = 2</code>，因为 <code>nums[2] AND nums[3] == 2</code>，从而得到一个排序后的排列：<code>[0, 1, 2, 3]</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,2,1,0]</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>只有当 <code>k = 0</code> 时，才能进行排序，因为没有更大的 <code>k</code> 能够满足 <code>nums[i] AND nums[j] == k</code> 的交换条件。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= n - 1</code></li>
	<li><code>nums</code> 是从 <code>0</code> 到 <code>n - 1</code> 的一个排列。</li>
</ul>


    
## 解题方法：遍历

首先一定是有办法交换为递增数组的：

> 例如令$k=0$，则元素$0$与任意元素都可以交换位置，最终一定可以交换为递增数组。

所以我们看有没有一个更大的合法$k$。

已经在正确位置上的元素是不需要在移动的（例如$nums[i]=i$），所以我们只需要考虑不在正确位置上的元素。

假设不在自己正确位置上的元素有$a$、$b$、$c$、$\ldots$，则它们一定要与某个元素（假设为$A$等）交换位置，也就是说：

$$
\begin{aligned}
a\ \&\ A &= k,\\
b\ \&\ B &= k,\\
c\ \&\ C &= k,\\
&\vdots
\end{aligned}
$$

先不管$A$、$B$、$C$等是什么，$k=a \& A$得出$k$中为$1$的位在$a$中也一定为$1$，同理$k$中为$1$的位在$b$、$c$等中也一定为$1$，也就是说$k$中为$1$的位在$a$、$b$、$c$等中也一定为$1$（这里的位指的是$bit$），即$k\ \measuredangle\ a\& b \& c$。

> 这里的$\measuredangle$是我自定义的一个符号，表示按位来看的话，$k$一定“属于”$a$、$b$、$c$等按位与的结果。
> 
> 也就是说从上述几个等式可以得到$k$的最大值是$a\& b \& c$。

那么$k$可不可以等于$a\& b \& c$这个**上界**呢？还是说$k$需要更小呢？

> 答案是可以的，用等于$k$的那个数和$a$、$b$、$c$等不断交换位置即可。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-23 20:30:31
 */
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if (nums[0]) {
            return 0;
        }
        int ans = -1;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] != i) {
                ans &= i;
            }
        }
        return ans == -1 ? 0 : ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-10-23 20:32:12
'''
from typing import List

class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        if nums[0]:
            return 0
        ans = -1
        for i, t in enumerate(nums):
            if t != i:
                ans &= i
        return 0 if ans == -1 else ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-10-23 20:34:40
 */
class Solution {
    public int sortPermutation(int[] nums) {
        if (nums[0] != 0) {
            return 0;
        }
        int ans = -1;
        for (int i = 0, n = nums.length; i < n; i++) {
            if (i != nums[i]) {
                ans &= i;
            }
        }
        return ans == -1 ? 0 : ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-10-23 20:33:11
 */
package main

func sortPermutation(nums []int) int {
    if nums[0] != 0 {
        return 0
    }
    ans := -1
    for i, t := range nums {
        if t != i {
            ans &= i
        }
    }
    return max(ans, 0)
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-10-23 20:39:42
 */
impl Solution {
    pub fn sort_permutation(nums: Vec<i32>) -> i32 {
        if nums[0] != 0 {
            return 0;
        }
        let mut ans = -1;
        for (i, &t) in nums.iter().enumerate() {
            if t != i as i32 {
                ans &= i as i32;
            }
        }
        ans.max(0)
    }
}
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/168882996)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/23/LeetCode%203644.%E6%8E%92%E5%BA%8F%E6%8E%92%E5%88%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
