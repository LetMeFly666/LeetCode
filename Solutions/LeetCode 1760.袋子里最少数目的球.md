---
title: 1760.袋子里最少数目的球：二分查找
date: 2022-12-20 22:56:47
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分]
categories: [题解, LeetCode]
---

# 【LetMeFly】1760.袋子里最少数目的球：二分查找

力扣题目链接：[https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/](https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/)

<p>给你一个整数数组 <code>nums</code> ，其中 <code>nums[i]</code> 表示第 <code>i</code> 个袋子里球的数目。同时给你一个整数 <code>maxOperations</code> 。</p>

<p>你可以进行如下操作至多 <code>maxOperations</code> 次：</p>

<ul>
	<li>选择任意一个袋子，并将袋子里的球分到 2 个新的袋子中，每个袋子里都有 <strong>正整数</strong> 个球。

	<ul>
		<li>比方说，一个袋子里有 <code>5</code> 个球，你可以把它们分到两个新袋子里，分别有 <code>1</code> 个和 <code>4</code> 个球，或者分别有 <code>2</code> 个和 <code>3</code> 个球。</li>
	</ul>
	</li>
</ul>

<p>你的开销是单个袋子里球数目的 <strong>最大值</strong> ，你想要 <strong>最小化</strong> 开销。</p>

<p>请你返回进行上述操作后的最小开销。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [9], maxOperations = 2
<b>输出：</b>3
<b>解释：</b>
- 将装有 9 个球的袋子分成装有 6 个和 3 个球的袋子。[<strong>9</strong>] -> [6,3] 。
- 将装有 6 个球的袋子分成装有 3 个和 3 个球的袋子。[<strong>6</strong>,3] -> [3,3,3] 。
装有最多球的袋子里装有 3 个球，所以开销为 3 并返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,4,8,2], maxOperations = 4
<b>输出：</b>2
<strong>解释：</strong>
- 将装有 8 个球的袋子分成装有 4 个和 4 个球的袋子。[2,4,<strong>8</strong>,2] -> [2,4,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,<strong>4</strong>,4,4,2] -> [2,2,2,4,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,<strong>4</strong>,4,2] -> [2,2,2,2,2,4,2] 。
- 将装有 4 个球的袋子分成装有 2 个和 2 个球的袋子。[2,2,2,2,2,<strong>4</strong>,2] -> [2,2,2,2,2,2,2,2] 。
装有最多球的袋子里装有 2 个球，所以开销为 2 并返回 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [7,17], maxOperations = 2
<b>输出：</b>7
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= maxOperations, nums[i] <= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：二分

若maxOperations次操作能使得最终“开销”为5，那么这么多次操作一定**能做到**使最小开销为6

因此，我们二分寻找“最小的开销”，如果开销为$mid$能实现，那么我们就试试一个更小的开销能否实现；反之若开销为$mid$不能实现，那么我们就试试一个更大的开销能否实现。

如何判断最终开销为$mid$时能否实现呢？

很简单，既然最终开销为$mid$，那么最终每个袋子中的小球个数的最大值都不能超过$mid$。

若原本袋子中有$[1, mid]$个球，那么这个袋子需要$0$次操作；若原本袋子中有$[mid + 1, 2\times mid]$个球，那么这个袋子需要$1$次操作；若这个袋子中有$n$个球，那么这个袋子需要$\lfloor\frac{n-1}{mid}\rfloor$次操作.

遍历每个袋子，计算出这个袋子最终小球数量不超过$mid$所需的操作次数，累加起来即为“最终开销为$mid$的最小操作次数”

+ 时间复杂度$O(len(nums)\times \max(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++(单函数版)

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2022-12-20 22:52:45
 * @LastEditors: LetMeFly
 * @LastEditTime: 2022-12-20 22:55:05
 */
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int& t : nums) {
                cnt += (t - 1) / mid;
            }
            if (cnt <= maxOperations)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};
```

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 13:37:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 13:42:15
 */
class Solution {
private:
    bool check(vector<int>& v, int m, int n) {
        for (int t : v) {
            m -= (t - 1) / n;
        }
        return m >= 0;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(nums, maxOperations, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-13 13:42:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-13 13:44:17
'''
from typing import List

class Solution:
    def check(self, op: int, m: int) -> bool:
        for t in self.nums:
            op -= (t - 1) // m
        return op >= 0
    
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        self.nums = nums
        l, r = 1, max(nums)
        while l < r:
            m = (l + r) >> 1
            if self.check(maxOperations, m):
                r = m
            else:
                l = m + 1
        return r
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 13:43:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 13:48:29
 */
class Solution {
    private int[] nums;

    private boolean check(int op, int m) {
        for (int t : nums) {
            op -= (t - 1) / m;
        }
        return op >= 0;
    }

    private int max() {
        int ans = nums[0];
        for (int t : nums) {
            ans = Math.max(ans, t);
        }
        return ans;
    }
    public int minimumSize(int[] nums, int maxOperations) {
        this.nums = nums;
        int l = 1, r = max();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(maxOperations, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-13 13:43:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-13 13:51:10
 */
package main

import "slices"

func check_MLBI1B(nums []int, op, m int) bool {
    for _, t := range nums {
        op -= (t - 1) / m
    }
    return op >= 0
}

func minimumSize(nums []int, maxOperations int) int {
    l, r := 1, slices.Max(nums)
    for l < r {
        m := (l + r) >> 1
        if check_MLBI1B(nums, maxOperations, m) {
            r = m
        } else {
            l = m + 1
        }
    }
    return r
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/20/LeetCode%201760.%E8%A2%8B%E5%AD%90%E9%87%8C%E6%9C%80%E5%B0%91%E6%95%B0%E7%9B%AE%E7%9A%84%E7%90%83/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128391344](https://letmefly.blog.csdn.net/article/details/128391344)
