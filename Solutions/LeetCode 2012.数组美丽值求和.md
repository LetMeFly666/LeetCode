---
title: 2012.数组美丽值求和：前缀和
date: 2025-03-11 14:14:27
tags: [题解, LeetCode, 中等, 数组, 前缀和]
---

# 【LetMeFly】2012.数组美丽值求和：前缀和

力扣题目链接：[https://leetcode.cn/problems/sum-of-beauty-in-the-array/](https://leetcode.cn/problems/sum-of-beauty-in-the-array/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。对于每个下标 <code>i</code>（<code>1 &lt;= i &lt;= nums.length - 2</code>），<code>nums[i]</code> 的 <strong>美丽值</strong> 等于：</p>

<ul>
	<li><code>2</code>，对于所有 <code>0 &lt;= j &lt; i</code> 且 <code>i &lt; k &lt;= nums.length - 1</code> ，满足 <code>nums[j] &lt; nums[i] &lt; nums[k]</code></li>
	<li><code>1</code>，如果满足 <code>nums[i - 1] &lt; nums[i] &lt; nums[i + 1]</code> ，且不满足前面的条件</li>
	<li><code>0</code>，如果上述条件全部不满足</li>
</ul>

<p>返回符合 <code>1 &lt;= i &lt;= nums.length - 2</code> 的所有<em> </em><code>nums[i]</code><em> </em>的 <strong>美丽值的总和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>对于每个符合范围 1 &lt;= i &lt;= 1 的下标 i :
- nums[1] 的美丽值等于 2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,6,4]
<strong>输出：</strong>1
<strong>解释：</strong>对于每个符合范围 1 &lt;= i &lt;= 2 的下标 i :
- nums[1] 的美丽值等于 1
- nums[2] 的美丽值等于 0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,1]
<strong>输出：</strong>0
<strong>解释：</strong>对于每个符合范围 1 &lt;= i &lt;= 1 的下标 i :
- nums[1] 的美丽值等于 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：前缀和

如何快速判断$nums[0]$到$nums[i - 1]$是否都小于$nums[i]$？可以利用前缀思想，遍历一遍数组并将$nums[0]$到$nums[i - 1]$的最大值存入$mx[i - 1]$数组中。

同理，可使用$mn[i + 1]$代表$nums[i + 1]$到$nums[len(nums) - 1]$的最小值。

这样，只需要遍历一遍数组，就能统计出来每一个$i$的得分了。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

优化：前缀数组可以使用一个变量在遍历的过程中维护（见[Golang](#go)版本）。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-11 13:47:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-11 13:52:04
 */
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> M(nums.size()), m(nums.size());
        int now = 0;
        for (int i = 0; i < nums.size(); i++) {
            M[i] = now = max(now, nums[i]);
        }
        now = 1000000;
        for (int i = nums.size() - 1; i >= 0; i--) {
            m[i] = now = min(now, nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            // printf("M[%d] = %d, nums[%d] = %d, m[%d] = %d\n", i - 1, M[i - 1], i, nums[i], i + 1, m[i + 1]);  // ********
            if (M[i - 1] < nums[i] && nums[i] < m[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-11 14:04:02
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-11 14:07:14
'''
from typing import List

class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        mx = [0] * len(nums)
        mn = [0] * len(nums)
        now = 0
        for i in range(len(nums)):
            mx[i] = now = max(now, nums[i])
        now = 1000000
        for i in range(len(nums) - 1, -1, -1):
            mn[i] = now = min(now, nums[i])
        ans = 0
        for i in range(1, len(nums) - 1):
            if mx[i - 1] < nums[i] < mn[i + 1]:
                ans += 2
            elif nums[i - 1] < nums[i] < nums[i + 1]:
                ans += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-11 14:07:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-11 14:10:09
 */
class Solution {
    public int sumOfBeauties(int[] nums) {
        int[] mx = new int[nums.length];
        int[] mn = new int[nums.length];
        int now = 0;
        for (int i = 0; i < nums.length; i++) {
            mx[i] = now = Math.max(now, nums[i]);
        }
        for (int i = nums.length - 1; i >= 0; i--) {
            mn[i] = now = Math.min(now, nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            if (mx[i - 1] < nums[i] && nums[i] < mn[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-11 14:10:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-11 14:13:05
 */
package main

func sumOfBeauties(nums []int) (ans int) {
    mn := make([]int, len(nums))
    now := 100000
    for i := len(nums) - 1; i >= 0; i-- {
        now = min(now, nums[i])
        mn[i] = now
    }
    now = nums[0]
    for i := 1; i < len(nums) - 1; i++ {
        if now < nums[i] && nums[i] < mn[i + 1] {
            ans += 2
        } else if nums[i - 1] < nums[i] && nums[i] < nums[i + 1] {
            ans++
        }
        now = max(now, nums[i])
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146177984)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/11/LeetCode%202012.%E6%95%B0%E7%BB%84%E7%BE%8E%E4%B8%BD%E5%80%BC%E6%B1%82%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
