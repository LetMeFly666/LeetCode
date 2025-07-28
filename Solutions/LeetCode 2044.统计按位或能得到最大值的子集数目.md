---
title: 2044.统计按位或能得到最大值的子集数目：二进制枚举/DFS回溯(剪枝)
date: 2025-07-28 20:46:34
tags: [题解, LeetCode, 中等, 位运算, 数组, 回溯, 枚举, 二进制枚举, DFS, 深度优先搜索]
categories: [题解, LeetCode]
---

# 【LetMeFly】2044.统计按位或能得到最大值的子集数目：二进制枚举/DFS回溯(剪枝)

力扣题目链接：[https://leetcode.cn/problems/count-number-of-maximum-bitwise-or-subsets/](https://leetcode.cn/problems/count-number-of-maximum-bitwise-or-subsets/)

<p>给你一个整数数组 <code>nums</code> ，请你找出 <code>nums</code> 子集 <strong>按位或</strong> 可能得到的<strong> </strong><strong>最大值</strong> ，并返回按位或能得到最大值的 <strong>不同非空子集的数目</strong> 。</p>

<p>如果数组 <code>a</code> 可以由数组 <code>b</code> 删除一些元素（或不删除）得到，则认为数组 <code>a</code> 是数组 <code>b</code> 的一个 <strong>子集</strong> 。如果选中的元素下标位置不一样，则认为两个子集 <strong>不同</strong> 。</p>

<p>对数组 <code>a</code> 执行 <strong>按位或</strong>&nbsp;，结果等于 <code>a[0] <strong>OR</strong> a[1] <strong>OR</strong> ... <strong>OR</strong> a[a.length - 1]</code>（下标从 <strong>0</strong> 开始）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1]
<strong>输出：</strong>2
<strong>解释：</strong>子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
- [3]
- [3,1]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,2]
<strong>输出：</strong>7
<strong>解释：</strong>[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 2<sup>3</sup> - 1 = 7 个子集。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1,5]
<strong>输出：</strong>6
<strong>解释：</strong>子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 16</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法一：二进制枚举

使用一个整数二进制的每一位代表nums数组中每个元素的选择与不选。从$0$到$2^{nums}-1$即可枚举枚举完每个元素选与不选的情况。

+ 时间复杂度$O(n\times n^2)$，其中$n=len(nums)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 13:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 18:51:34
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxium = 0;
        for (int t : nums) {
            maxium |= t;
        }
        int ans = 0;
        int n = nums.size(), mask = 1 << n;
        for (int i = 0; i < mask; i++) {
            int thisVal = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    thisVal |= nums[j];
                }
            }
            ans += thisVal == maxium;
        }
        return ans;
    }
};
```

## 解题方法二：回溯DFS

写一个函数dfs(th, now)代表已经选(或不选)过前$th$个元素且总或值为$now$的情况。

如果已经选了$len(nums)$个，则判断$now$是否为$nums$所有元素或的结果并返回。如果是则ans++。

否则，可以不选当前元素并递归（`dfs(th, now)`），也可以选当前元素并递归（`dfs(th+1, now | nums[i]`）。

+ 时间复杂度$O(n^2)$，其中$n=len(nums)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 19:30:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 19:50:18
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans = 0;
    int maxium = 0;
    vector<int> nums;

    void dfs(int th, int now) {
        if (th == nums.size()) {
            ans += now == maxium;
            return;
        }
        dfs(th + 1, now);
        dfs(th + 1, now | nums[th]);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for (int t : nums) {
            maxium |= t;
        }
        this->nums = move(nums);
        dfs(0, 0);
        return ans;
    }
};
```

## 解题方法三：回溯DFS+小剪枝

有没有办法提前退出dfs函数呢？有。当当前的或结果已经为最大或结果的时候，后面的元素不论或与不或都不改变最终结果了。此时假设还剩$k$个元素，那么就说明后面还有$1<<k$种选法。

+ 时间复杂度$O(n^2)$，其中$n=len(nums)$
+ 空间复杂度$O(n)$

时空复杂度不变，但很多时候可以提前退出。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 19:30:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 19:51:20
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    int ans = 0;
    int maxium = 0;
    vector<int> nums;

    void dfs(int th, int now) {
        if (now == maxium) {
            ans += 1 << (nums.size() - th);
            return;
        }
        if (th == nums.size()) {
            return;
        }
        dfs(th + 1, now);
        dfs(th + 1, now | nums[th]);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for (int t : nums) {
            maxium |= t;
        }
        this->nums = move(nums);
        dfs(0, 0);
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-28 13:38:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-28 20:40:58
'''
from typing import List

class Solution:
    def dfs(self, th: int, now: int) -> None:
        if now == self.M:
            self.ans += 1 << (len(self.nums) - th)
            return
        if th == len(self.nums):
            return
        self.dfs(th + 1, now)
        self.dfs(th + 1, now | self.nums[th])
    
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        self.ans = 0
        self.nums = nums
        self.M = 0
        for t in nums:
            self.M |= t
        self.dfs(0, 0)
        return self.ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 13:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 20:43:13
 */
class Solution {
    private int ans = 0;
    private int M = 0;
    private int[] nums;

    private void dfs(int th, int now) {
        if (now == M) {
            ans += 1 << (nums.length - th);
            return;
        }
        if (th == nums.length) {
            return;
        }
        dfs(th + 1, now);
        dfs(th + 1, now | nums[th]);
    }

    public int countMaxOrSubsets(int[] nums) {
        this.nums = nums;
        for (int t : nums) {
            M |= t;
        }
        dfs(0, 0);
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-28 13:38:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-28 20:31:11
 */
package main

// import "fmt"

var ans2044, maxium2044 int = 0, 0
var nums2044 []int

func dfs2044(th, now int) {
    if now == maxium2044 {
        ans2044 += 1 << (len(nums2044) - th)
        return
    }
    if th == len(nums2044) {
        return
    }
    dfs2044(th + 1, now)
    dfs2044(th + 1, now | nums2044[th])
}

func countMaxOrSubsets(nums []int) int {
    nums2044 = nums
    ans2044 = 0
    maxium2044 = 0
    for _, t := range nums {
        maxium2044 |= t
    }
    dfs2044(0, 0)
    return ans2044
}

// func main() {
//     fmt.Println(countMaxOrSubsets([]int{2, 2, 2}))
// }
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149725900)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/28/LeetCode%202044.%E7%BB%9F%E8%AE%A1%E6%8C%89%E4%BD%8D%E6%88%96%E8%83%BD%E5%BE%97%E5%88%B0%E6%9C%80%E5%A4%A7%E5%80%BC%E7%9A%84%E5%AD%90%E9%9B%86%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
