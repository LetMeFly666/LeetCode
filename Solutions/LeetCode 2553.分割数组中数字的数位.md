---
title: 2553.分割数组中数字的数位：模拟（maybe+翻转）——java也O(1)
date: 2026-05-11 21:35:42
tags: [题解, LeetCode, 简单, 数组, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2553.分割数组中数字的数位：模拟（maybe+翻转）——java也O(1)

力扣题目链接：[https://leetcode.cn/problems/separate-the-digits-in-an-array/](https://leetcode.cn/problems/separate-the-digits-in-an-array/)

<p>给你一个正整数数组&nbsp;<code>nums</code>&nbsp;，请你返回一个数组<em>&nbsp;</em><code>answer</code> ，你需要将&nbsp;<code>nums</code>&nbsp;中每个整数进行数位分割后，按照&nbsp;<code>nums</code>&nbsp;中出现的&nbsp;<strong>相同顺序</strong>&nbsp;放入答案数组中。</p>

<p>对一个整数进行数位分割，指的是将整数各个数位按原本出现的顺序排列成数组。</p>

<ul>
	<li>比方说，整数&nbsp;<code>10921</code>&nbsp;，分割它的各个数位得到&nbsp;<code>[1,0,9,2,1]</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [13,25,83,77]
<b>输出：</b>[1,3,2,5,8,3,7,7]
<b>解释：</b>
- 分割 13 得到 [1,3] 。
- 分割 25 得到 [2,5] 。
- 分割 83 得到 [8,3] 。
- 分割 77 得到 [7,7] 。
answer = [1,3,2,5,8,3,7,7] 。answer 中的数字分割结果按照原数字在数组中的相同顺序排列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [7,1,3,9]
<b>输出：</b>[7,1,3,9]
<b>解释：</b>nums 中每个整数的分割是它自己。
answer = [7,1,3,9] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：模拟

怎样求出一个大于零的整数在十进制下的每一位？

> 当这个数（$t$）不为零的时候，不断取出这个数的个位（$t\%10$），然后令这个数除以$10$并向下取整就好了。

但是这样求出的结果是低位在前高位在后的，如$12$我们按上述算法将会得到$[2, 1]$。

因此我们不如来个将错就错，先求$nums$最后一个元素，之后是倒数第二个，...，最后求$nums$第一个元素。

这样我们就得到了一个完全逆向的答案数组，将这个数组原地reverse一下就好了。

### 时空复杂度分析

+ 时间复杂度$O(len(nums)\times \log nums[i])$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

至于Java这种不可变长度数组的编程语言，若不想使用可变数组`List`把空间复杂度搞到$O(n)$，也可以dry run一次（只计算需要的长度不真的放入数组），然后再申请对应长度的`int[]`。

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-11 21:16:38
 */
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (nums[i]) {
                ans.push_back(nums[i] % 10);
                nums[i] /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-05-11 21:20:12
'''
from typing import List

class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for x in reversed(nums):
            while x:
                ans.append(x % 10)
                x //= 10
        ans.reverse()
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-05-11 21:32:57
 */
class Solution {
    public int[] separateDigits(int[] nums) {
        int cnt = 0;
        for (int t : nums) {
            while (t > 0) {
                cnt++;
                t /= 10;
            }
        }

        int[] ans = new int[cnt];
        for (int i = nums.length - 1, idx = cnt - 1; i >= 0; i--) {
            while (nums[i] > 0) {
                ans[idx--] = nums[i] % 10;
                nums[i] /= 10;
            }
        }

        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-05-11 21:22:04
 */
package main

import "slices"

func separateDigits(nums []int) (ans []int) {
    for _, x := range slices.Backward(nums) {
        for x > 0 {
            ans = append(ans, x % 10)
            x /= 10
        }
    }
    slices.Reverse(ans)
    return
}
```

#### Rust

+ 执行用时分布0ms击败100.00%
+ 消耗内存分布2.21MB击败100.00%

```rust
/*
 * @LastEditTime: 2026-05-11 21:35:16
 */
impl Solution {
    pub fn separate_digits(mut nums: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        for i in (0..nums.len()).rev() {
            while nums[i] != 0 {
                ans.push(nums[i] % 10);
                nums[i] /= 10;
            }
        }
        ans.reverse();
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160993737)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/11/LeetCode%202553.%E5%88%86%E5%89%B2%E6%95%B0%E7%BB%84%E4%B8%AD%E6%95%B0%E5%AD%97%E7%9A%84%E6%95%B0%E4%BD%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
