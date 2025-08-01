---
title: 2411.按位或最大的最小子数组长度：一次倒序遍历
date: 2025-08-01 10:41:56
tags: [题解, LeetCode, 中等, 位运算, 数组, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2411.按位或最大的最小子数组长度：一次倒序遍历

力扣题目链接：[https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/](https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/)

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的数组&nbsp;<code>nums</code>&nbsp;，数组中所有数字均为非负整数。对于&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;之间的每一个下标 <code>i</code>&nbsp;，你需要找出&nbsp;<code>nums</code>&nbsp;中一个 <strong>最小</strong> 非空子数组，它的起始位置为&nbsp;<code>i</code>&nbsp;（包含这个位置），同时有&nbsp;<strong>最大</strong>&nbsp;的 <strong>按位或</strong><b>运算值</b>&nbsp;。</p>

<ul>
	<li>换言之，令&nbsp;<code>B<sub>ij</sub></code>&nbsp;表示子数组&nbsp;<code>nums[i...j]</code>&nbsp;的按位或运算的结果，你需要找到一个起始位置为&nbsp;<code>i</code>&nbsp;的最小子数组，这个子数组的按位或运算的结果等于&nbsp;<code>max(B<sub>ik</sub>)</code>&nbsp;，其中&nbsp;<code>i &lt;= k &lt;= n - 1</code>&nbsp;。</li>
</ul>

<p>一个数组的按位或运算值是这个数组里所有数字按位或运算的结果。</p>

<p>请你返回一个大小为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>answer</code>，其中<em>&nbsp;</em><code>answer[i]</code>是开始位置为&nbsp;<code>i</code>&nbsp;，按位或运算结果最大，且&nbsp;<strong>最短</strong>&nbsp;子数组的长度。</p>

<p><strong>子数组</strong>&nbsp;是数组里一段连续非空元素组成的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,0,2,1,3]
<b>输出：</b>[3,3,2,2,1]
<strong>解释：</strong>
任何位置开始，最大按位或运算的结果都是 3 。
- 下标 0 处，能得到结果 3 的最短子数组是 [1,0,2] 。
- 下标 1 处，能得到结果 3 的最短子数组是 [0,2,1] 。
- 下标 2 处，能得到结果 3 的最短子数组是 [2,1] 。
- 下标 3 处，能得到结果 3 的最短子数组是 [1,3] 。
- 下标 4 处，能得到结果 3 的最短子数组是 [3] 。
所以我们返回 [3,3,2,2,1] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2]
<b>输出：</b>[2,1]
<strong>解释：
</strong>下标 0 处，能得到最大按位或运算值的最短子数组长度为 2 。
下标 1 处，能得到最大按位或运算值的最短子数组长度为 1 。
所以我们返回 [2,1] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：倒序遍历

### 解题思路

或运算的性质决定每一位是可以分开来单独看的。假设我们只关注最低的一位，那么问题就转化为了：

> 从nums[i]开始到哪个元素为止最低的一位出现过$1$。
>
> 一旦最低位出现了$1$，子数组的最短长度就确定了，就没必要继续往后遍历了。

现在nums的范围是$10^9$，二进制下一共有31位，每一位互不影响，单独来看，求最长的子数组就好了。

### 具体方法

对于某一位（以二进制下的最低位为例），如何判断从nums[i]开始，第一个这一位是1的元素呢？

只需要从后往前遍历，使用一个变量lastPos记录最后一次这一位为1的下标（即这位为1的最小下标），则遍历到nums[i]时，lastPos的值就是从nums[i]开始第一个这一位为1的元素下标。

特别的，我们可以将lastPos的初始值设置为0；由于nums[i]的范围是$10^9$，所以我们需要一个长度为$31$的lastPos数组，nums[i]开始的最短数组的长度为31位中结果最长的那个。

### 时空复杂度

+ 时间复杂度$O(len(nums)\times C)$，其中$C=\log \max (nums[i])=\log10^9=31$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-30 00:00:01
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> lastPos(31);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int last = i;
            for (int j = 0; j < 31; j++) {
                if (nums[i] >> j & 1) {
                    lastPos[j] = i;
                } else {
                    last = max(last, lastPos[j]);
                }
            }
            ans[i] = max(ans[i], last - i + 1);
        }
        return ans;
    }
};


#if defined(_WIN32) || defined(__APPLE__)
/*
 [1,0,2,1,3]
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        debug(sol.smallestSubarrays(v));
    }
    return 0;
}
#endif
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-29 23:42:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-30 10:14:12
'''
from typing import List

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        lastPos = [0] * 31
        for i in range(len(nums) - 1, -1, -1):
            last = i
            for j in range(31):
                if nums[i] >> j & 1:
                    lastPos[j] = i
                else:
                    last = max(last, lastPos[j])
            ans[i] = max(ans[i], last - i + 1)
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-31 10:45:02
 */
class Solution {
    public int[] smallestSubarrays(int[] nums) {
        int[] ans = new int[nums.length];
        int[] lastPos = new int[31];
        for (int i = nums.length - 1; i >= 0; i--) {
            int last = i;
            for (int j = 0; j < 31; j++) {
                if ((nums[i] >> j & 1) == 1) {
                    lastPos[j] = i;
                } else {
                    last = Math.max(last, lastPos[j]);
                }
            }
            ans[i] = Math.max(ans[i], last - i + 1);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-30 10:15:13
 */
package main

func smallestSubarrays(nums []int) []int {
    ans := make([]int, len(nums))
    lastPos := make([]int, 31)
    for i := len(nums) - 1; i >= 0; i-- {
        last := i
        for j := 0; j < 31; j++ {
            if nums[i] >> j & 1 == 1 {
                lastPos[j] = i
            } else {
                last = max(last, lastPos[j])
            }
        }
        ans[i] = max(ans[i], last - i + 1)
    }
    return ans
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-07-29 23:42:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-30 21:00:40
 */
use std::cmp::max;

impl Solution {
    pub fn smallest_subarrays(nums: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![0; nums.len()];
        let mut lastPos: Vec<i32> = vec![0; 31];
        for i in (0..ans.len()).rev() {
            let ii32: i32 = i.try_into().unwrap();
            let mut last: i32 = ii32;
            for j in (0..31) {
                if nums[i] >> j & 1 == 1 {
                    lastPos[j] = ii32;
                } else {
                    last = max(last, lastPos[j])
                }
            }
            ans[i] = max(ans[i], last - ii32 + 1)
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149831577)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/01/LeetCode%202411.%E6%8C%89%E4%BD%8D%E6%88%96%E6%9C%80%E5%A4%A7%E7%9A%84%E6%9C%80%E5%B0%8F%E5%AD%90%E6%95%B0%E7%BB%84%E9%95%BF%E5%BA%A6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
