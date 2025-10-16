---
title: 2598.执行操作后的最大 MEX：哈希表统计
date: 2025-10-16 20:18:41
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】2598.执行操作后的最大 MEX：哈希表统计

力扣题目链接：[https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/](https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>value</code> 。</p>

<p>在一步操作中，你可以对 <code>nums</code> 中的任一元素加上或减去 <code>value</code> 。</p>

<ul>
	<li>例如，如果 <code>nums = [1,2,3]</code> 且 <code>value = 2</code> ，你可以选择 <code>nums[0]</code> 减去 <code>value</code> ，得到 <code>nums = [-1,2,3]</code> 。</li>
</ul>

<p>数组的 MEX (minimum excluded) 是指其中数组中缺失的最小非负整数。</p>

<ul>
	<li>例如，<code>[-1,2,3]</code> 的 MEX 是 <code>0</code> ，而 <code>[1,0,3]</code> 的 MEX 是 <code>2</code> 。</li>
</ul>

<p>返回在执行上述操作 <strong>任意次</strong> 后，<code>nums</code><em> </em>的最大 MEX <em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,-10,7,13,6,8], value = 5
<strong>输出：</strong>4
<strong>解释：</strong>执行下述操作可以得到这一结果：
- nums[1] 加上 value 两次，nums = [1,<em><strong>0</strong></em>,7,13,6,8]
- nums[2] 减去 value 一次，nums = [1,0,<em><strong>2</strong></em>,13,6,8]
- nums[3] 减去 value 两次，nums = [1,0,2,<em><strong>3</strong></em>,6,8]
nums 的 MEX 是 4 。可以证明 4 是可以取到的最大 MEX 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,-10,7,13,6,8], value = 7
<strong>输出：</strong>2
<strong>解释：</strong>执行下述操作可以得到这一结果：
- nums[2] 减去 value 一次，nums = [1,-10,<em><strong>0</strong></em>,13,6,8]
nums 的 MEX 是 2 。可以证明 2 是可以取到的最大 MEX 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, value &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


## 解题方法：哈希表统计

由于可以任意词加减value，所以将数组中的每个数对value取模到`[0, value)`的范围，并使用哈希表统计取模后每个数的出现次数。

然后从0开始往上遍历，如果当前值对value取模后的值在哈希表中仍存在，则消耗一个哈希表中的这个值并将遍历数`+1`。

遇到无可消耗的值即为答案MEX。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(\min(len(nums), value))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-16 19:43:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> ma;
        for (int t : nums) {
            ma[t % value]++;
        }
        int ans = 0;
        while (true) {
            cout << ans << ',' << ma[ans] << endl;
            if (--ma[ans] == -1) {
                return ans;
            }
            ans++;
        }
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-10-16 19:55:23
'''
from typing import List
from collections import Counter

class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        cnt = Counter(x % value for x in nums)  # python负数模正数是正数
        ans = 0
        while cnt[ans % value]:
            cnt[ans % value] -= 1
            ans += 1
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2025-10-16 19:59:10
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int t : nums) {
            cnt.merge((t % value + value) % value, 1, Integer::sum);
        }
        int ans = 0;
        while (cnt.merge(ans % value, -1, Integer::sum) >= 0) {  // 记得是大于等于
            ans++;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-10-16 20:01:33
 */
package main

func findSmallestInteger(nums []int, value int) (ans int) {
    cnt := map[int]int{}
    for _, t := range nums {
        cnt[(t % value + value) % value]++
    }
    for cnt[ans % value] > 0 {
        cnt[ans % value]--
        ans++
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-10-16 20:18:30
 */
use std::collections::HashMap;

// 这语言设计的真精妙
impl Solution {
    pub fn find_smallest_integer(nums: Vec<i32>, value: i32) -> i32 {
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        for x in nums {
            *cnt.entry((x % value + value) % value).or_insert(0) += 1;
        }

        for ans in 0.. {
            // if matches!(cnt.get_mut(&(ans % value)), Some(v) if *v > 0) {
            //     *v -= 1;  // 无法使用v报错
            //     continue;
            // }
            if let Some(v) = cnt.get_mut(&(ans % value)) {
                if *v > 0 {  // 记得是大于
                    *v -= 1;
                    continue;
                }
            }
            return ans;
        }
        unreachable!()
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/153417357)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/10/16/LeetCode%202598.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%90%8E%E7%9A%84%E6%9C%80%E5%A4%A7MEX/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
