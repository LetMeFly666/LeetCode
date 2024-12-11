---
title: 2717.半有序排列
date: 2024-12-11 23:24:28
tags: [题解, LeetCode, 简单, 数组, 模拟]
---

# 【LetMeFly】2717.半有序排列：一次遍历后计算

力扣题目链接：[https://leetcode.cn/problems/semi-ordered-permutation/](https://leetcode.cn/problems/semi-ordered-permutation/)

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数排列 <code>nums</code> 。</p>

<p>如果排列的第一个数字等于 <code>1</code> 且最后一个数字等于 <code>n</code> ，则称其为 <strong>半有序排列</strong> 。你可以执行多次下述操作，直到将 <code>nums</code> 变成一个 <strong>半有序排列</strong> ：</p>

<ul>
	<li>选择 <code>nums</code> 中相邻的两个元素，然后交换它们。</li>
</ul>

<p>返回使 <code>nums</code> 变成 <strong>半有序排列</strong> 所需的最小操作次数。</p>

<p><strong>排列</strong> 是一个长度为 <code>n</code> 的整数序列，其中包含从 <code>1</code> 到 <code>n</code> 的每个数字恰好一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,4,3]
<strong>输出：</strong>2
<strong>解释：</strong>可以依次执行下述操作得到半有序排列：
1 - 交换下标 0 和下标 1 对应元素。排列变为 [1,2,4,3] 。
2 - 交换下标 2 和下标 3 对应元素。排列变为 [1,2,3,4] 。
可以证明，要让 nums 成为半有序排列，不存在执行操作少于 2 次的方案。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,1,3]
<strong>输出：</strong>3
<strong>解释：
</strong>可以依次执行下述操作得到半有序排列：
1 - 交换下标 1 和下标 2 对应元素。排列变为 [2,1,4,3] 。
2 - 交换下标 0 和下标 1 对应元素。排列变为 [1,2,4,3] 。
3 - 交换下标 2 和下标 3 对应元素。排列变为 [1,2,3,4] 。
可以证明，要让 nums 成为半有序排列，不存在执行操作少于 3 次的方案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,4,2,5]
<strong>输出：</strong>0
<strong>解释：</strong>这个排列已经是一个半有序排列，无需执行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i]&nbsp;&lt;= 50</code></li>
	<li><code>nums</code> 是一个 <strong>排列</strong></li>
</ul>


    
## 解题方法：一次遍历

+ 假设$1$的下标是$a$，那么把$1$交换到首位需要$a$次
+ 假设$n$的下标是$b$，那么把$n$交换到末位需要$n-1-b$次

所以一共需要交换$a + (n - 1 - b)$次。

注意，如果$1$在$n$右边，那么必定有次$1$和$n$的交换被统计了两次，因此总次数减一。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int a, b;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                a = i;
            } else if (nums[i] == nums.size()) {
                b = i;
            }
        }
        return a + (nums.size() - b - 1) - (a > b);
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        a = b = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                a = i
            elif nums[i] == len(nums):
                b = i
        return a + (len(nums) - 1 - b) - (a > b)
```

#### Java

```java
class Solution {
    public int semiOrderedPermutation(int[] nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                a = i;
            } else if (nums[i] == nums.length) {
                b = i;
            }
        }
        int ans = a + (nums.length - 1 - b);
        if (a > b) {
            ans--;
        }
        return ans;
    }
}
```

#### Go

```go
package main

func semiOrderedPermutation(nums []int) (ans int) {
    a, b := 0, 0
    for th, val := range nums {
        if val == 1 {
            a = th
        } else if val == len(nums) {
            b = th
        }
    }
    ans = a + (len(nums) - b - 1)
    if a > b {
        ans--
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/11/LeetCode%202717.%E5%8D%8A%E6%9C%89%E5%BA%8F%E6%8E%92%E5%88%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144412760](https://letmefly.blog.csdn.net/article/details/144412760)
