---
title: 3201.找出有效子序列的最大长度 I：分类统计+贪心（一次遍历）
date: 2025-07-16 23:10:03
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 贪心]
categories: [题解, LeetCode]
---

# 【LetMeFly】3201.找出有效子序列的最大长度 I：分类统计+贪心（一次遍历）

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i/](https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i/)

<p>给你一个整数数组 <code>nums</code>。</p>

<p><code>nums</code> 的子序列 <code>sub</code> 的长度为 <code>x</code> ，如果其满足以下条件，则称其为 <strong>有效子序列</strong>：</p>

<ul>
	<li><code>(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2</code></li>
</ul>

<p>返回 <code>nums</code> 的 <strong>最长的有效子序列</strong> 的长度。</p>

<p>一个&nbsp;<strong>子序列</strong>&nbsp;指的是从原数组中删除一些元素（也可以不删除任何元素），剩余元素保持原来顺序组成的新数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>最长的有效子序列是 <code>[1, 2, 3, 4]</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,1,1,2,1,2]</span></p>

<p><strong>输出：</strong> 6</p>

<p><strong>解释：</strong></p>

<p>最长的有效子序列是 <code>[1, 2, 1, 2, 1, 2]</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>最长的有效子序列是 <code>[1, 3]</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


    
## 解题方法：分类统计

子序列如果是有效子序列(相邻两个元素之和 的奇偶性相同)，只有以下三种可能：

1. 全奇
2. 全偶
3. 一奇一偶交替排列

怎么一次遍历**分别**统计出这三种情况最长有效子序列呢？

+ 使用一个变量$odd$，统计数组中奇数元素的个数（那么偶数元素的个数就是$len(nums) - odd$）； 
+ 使用一个变量$last$，代表上一个选中元素是奇是偶；并使用一个元素$cnt$统计选中了多少个奇偶交替排列的元素。

所谓贪心，体现在当方案为奇偶交替时，遇到和上一个元素奇偶不同的元素一定选（不选白不选），遍历结束则能得到奇偶交替方案的最长长度。

> 举个例子：$2, 0, 3, 5, 4$这个数组，遍历时遇到2，选还是不选？
>
> 选，不选干嘛<span title="愣着啊">，</span>以奇数开头吗？没必要，以奇数开头不就少选了个偶数吗。

而一次遍历过程中顺便统计下奇数个数就很简单了。

+ 时间复杂度$O(x)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-16 13:16:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-16 13:19:44
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans = 0;
        int odd = 0;
        bool last = nums[0] % 2 ? false : true;
        for (int t : nums) {
            if (t % 2) {
                odd++;
                if (!last) {
                    last = true;
                    ans++;
                }
            } else {
                if (last) {
                    last = false;
                    ans++;
                }
            }
        }
        return max(ans, max(odd, int(nums.size()) - odd));
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-07-16 13:16:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-16 13:36:53
'''
from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        ans = odd = 0
        last = False if nums[0] % 2 else True
        for t in nums:
            if t % 2:
                odd += 1
                if not last:
                    last = True
                    ans += 1
            else:
                if last:
                    last = False
                    ans += 1
        return max(ans, odd, len(nums) - odd)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-16 13:16:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-16 13:41:23
 */
class Solution {
    public int maximumLength(int[] nums) {
        int ans = 0;
        int odd = 0;
        boolean last = nums[0] % 2 == 0;
        for (int t : nums) {
            if (t % 2 == 0) {
                if (last) {
                    last = false;
                    ans++;
                }
            } else {
                odd++;
                if (!last) {
                    last = true;
                    ans++;
                }
            }
        }
        return Math.max(ans, Math.max(odd, nums.length - odd));
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-07-16 13:16:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-16 13:40:18
 */
package main

func maximumLength(nums []int) (ans int) {
    odd := 0
    last := nums[0] % 2 == 0
    for _, t := range nums {
        if t % 2 == 0 {
            if last {
                last = false
                ans++
            }
        } else {
            odd++
            if !last {
                last = true
                ans++
            }
        }
    }
    return max(ans, max(odd, len(nums) - odd))
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149409629)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/16/LeetCode%203201.%E6%89%BE%E5%87%BA%E6%9C%89%E6%95%88%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E6%9C%80%E5%A4%A7%E9%95%BF%E5%BA%A6I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
