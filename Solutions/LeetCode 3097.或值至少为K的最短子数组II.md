---
title: 3097.或值至少为 K 的最短子数组 II：滑动窗口
date: 2025-01-17 12:49:46
tags: [题解, LeetCode, 中等, 位运算, 数组, 滑动窗口]
---

# 【LetMeFly】3097.或值至少为 K 的最短子数组 II：滑动窗口

力扣题目链接：[https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/](https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/)

<p>给你一个 <strong>非负</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个数组中所有元素的按位或运算 <code>OR</code>&nbsp;的值 <strong>至少</strong>&nbsp;为 <code>k</code>&nbsp;，那么我们称这个数组是 <strong>特别的</strong>&nbsp;。</p>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>最短特别非空</strong>&nbsp;<span data-keyword="subarray-nonempty">子数组</span>的长度，如果特别子数组不存在，那么返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[3]</code>&nbsp;的按位&nbsp;<code>OR</code> 值为&nbsp;<code>3</code>&nbsp;，所以我们返回 <code>1</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,8], k = 10</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[2,1,8]</code> 的按位&nbsp;<code>OR</code>&nbsp;值为 <code>11</code>&nbsp;，所以我们返回 <code>3</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2], k = 0</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>子数组&nbsp;<code>[1]</code>&nbsp;的按位&nbsp;<code>OR</code>&nbsp;值为&nbsp;<code>1</code>&nbsp;，所以我们返回&nbsp;<code>1</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup><font size="1">9</font></sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：滑动窗口

遍历数组作为窗口的起点，窗口的终点为第一个满足“窗口中元素OR值不小于k”的元素。所有合法窗口的最小长度即为答案。

但是有一个问题，窗口起点右移后，如何将元素移出窗口呢？

我们可以使用一个数组记录每一位分别出现了多少次，移出元素时只需要将这个元素的每一位对应的出现次数减一即可。

+ 时间复杂度$O(C\times len(nums))$，其中$C=\log \max nums[i]=30$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-17 12:08:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-17 12:22:14
 */
class Solution {
private:
    int calc(int* cnt) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (cnt[i]) {
                ans |= 1 << i;
            }
        }
        return ans;
    }

    void add(int* cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] += a >> i & 1;
        }
    }

    void del(int* cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] -= a >> i & 1;
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (!k) {
            return 1;
        }
        int ans = 1000000;
        int cnt[30] = {0};
        for (int l = 0, r = 0; l < nums.size(); l++) {
            if (l > 0) {
                del(cnt, nums[l - 1]);
            }
            while (r < nums.size() && calc(cnt) < k) {
                add(cnt, nums[r++]);
            }
            if (calc(cnt) >= k) {
                ans = min(ans, r - l);
            }
        }
        return ans == 1000000 ? -1 : ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-17 12:24:55
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-17 12:29:16
'''
from typing import List

class Solution:
    def calc(self) -> int:
        ans = 0
        for i in range(30):
            if self.cnt[i]:
                ans += 1 << i
        return ans
    
    def add(self, a: int) -> None:
        for i in range(30):
            self.cnt[i] += a >> i & 1
    
    def sub(self, a: int) -> None:
        for i in range(30):
            self.cnt[i] -= a >> i & 1

    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if not k:
            return 1
        ans = 1000000
        r = 0
        self.cnt = [0] * 30
        for l in range(len(nums)):
            if l:
                self.sub(nums[l - 1])
            while r < len(nums) and self.calc() < k:
                self.add(nums[r])
                r += 1
            if self.calc() >= k:
                ans = min(ans, r - l)
        return -1 if ans == 1000000 else ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-17 12:30:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-17 12:41:22
 */
class Solution {
    private int calc(int[] cnt) {
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (cnt[i] > 0) {
                ans |= 1 << i;
            }
        }
        return ans;
    }

    private void add(int[] cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] += a >> i & 1;
        }
    }

    private void del(int[] cnt, int a) {
        for (int i = 0; i < 30; i++) {
            cnt[i] -= a >> i & 1;
        }
    }

    public int minimumSubarrayLength(int[] nums, int k) {
        if (k == 0) {
            return 1;
        }
        int ans = 1000000;
        int[] cnt = new int[30];
        for (int l = 0, r = 0; l < nums.length; l++) {
            if (l > 0) {
                del(cnt, nums[l - 1]);
            }
            while (r < nums.length && calc(cnt) < k) {
                add(cnt, nums[r++]);
            }
            if (calc(cnt) >= k) {
                ans = Math.min(ans, r - l);
            }
        }
        return ans == 1000000 ? -1 : ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-17 12:42:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-17 13:47:03
 */
package main

func calc(cnt []int) (ans int) {
    for i, v := range cnt {
        if v > 0 {
            ans |= 1 << i
        }
    }
    return
}

func add(cnt []int, a int) {
    for i := range cnt {
        cnt[i] += a >> i & 1
    }
}

func del(cnt []int, a int) {
    for i := range cnt {
        cnt[i] -= a >> i & 1
    }
}

func minimumSubarrayLength(nums []int, k int) int {
    if k == 0 {
        return 1
    }
    ans := 1000000
    cnt := make([]int, 30)
    for l, r := 0, 0; l < len(nums); l++ {
        if l > 0 {
            del(cnt, nums[l - 1])
        }
        for r < len(nums) && calc(cnt) < k {
            add(cnt, nums[r])
            r++
        }
        if calc(cnt) >= k {
            ans = min(ans, r - l)
        }
    }
    if ans == 1000000 {
        return -1
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/17/LeetCode%203097.%E6%88%96%E5%80%BC%E8%87%B3%E5%B0%91%E4%B8%BAK%E7%9A%84%E6%9C%80%E7%9F%AD%E5%AD%90%E6%95%B0%E7%BB%84II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145206042](https://letmefly.blog.csdn.net/article/details/145206042)
