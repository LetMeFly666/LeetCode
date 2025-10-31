---
title: 3289.数字小镇中的捣蛋鬼：哈希表O(n)空间 / 位运算O(1)空间
date: 2025-10-31 22:50:22
tags: [题解, LeetCode, 简单, 数组, 哈希表, set, 数学, 位运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】3289.数字小镇中的捣蛋鬼：哈希表O(n)空间 / 位运算O(1)空间

力扣题目链接：[https://leetcode.cn/problems/the-two-sneaky-numbers-of-digitville/](https://leetcode.cn/problems/the-two-sneaky-numbers-of-digitville/)

<p>数字小镇 Digitville 中，存在一个数字列表 <code>nums</code>，其中包含从 <code>0</code> 到 <code>n - 1</code> 的整数。每个数字本应 <strong>只出现一次</strong>，然而，有 <strong>两个 </strong>顽皮的数字额外多出现了一次，使得列表变得比正常情况下更长。</p>

<p>为了恢复 Digitville 的和平，作为小镇中的名侦探，请你找出这两个顽皮的数字。</p>

<p>返回一个长度为 2 的数组，包含这两个数字（顺序任意）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,1,1,0]</span></p>

<p><strong>输出：</strong> <span class="example-io">[0,1]</span></p>

<p><strong>解释：</strong></p>

<p>数字 0 和 1 分别在数组中出现了两次。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,3,2,1,3,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">[2,3]</span></p>

<p><strong>解释: </strong></p>

<p>数字 2 和 3 分别在数组中出现了两次。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [7,1,5,4,3,4,6,0,9,5,8,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">[4,5]</span></p>

<p><strong>解释: </strong></p>

<p>数字 4 和 5 分别在数组中出现了两次。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>nums.length == n + 2</code></li>
	<li><code>0 &lt;= nums[i] &lt; n</code></li>
	<li>输入保证 <code>nums</code> 中<strong> 恰好 </strong>包含两个重复的元素。</li>
</ul>


    
## 解题方法一：哈希表

使用哈希表统计每个数是否出现过。

遍历数组，若一个数已经在哈希表中出现过，则将其加入到答案中；否则将这个数添加到哈希表中。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-31 22:19:51
 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> se;
        vector<int> ans;
        for (int t : nums) {
            if (se.count(t)) {
                ans.push_back(t);
            } else {
                se.insert(t);
            }
        }
        return ans;
    }
};
```


#### Python

```python
'''
LastEditTime: 2025-10-31 22:21:51
'''
from typing import List

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        se = set()
        ans = []
        for t in nums:
            if t in se:
                ans.append(t)
            else:
                se.add(t)
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2025-10-31 22:27:27
 */
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int[] ans = new int[2];
        int already = 0;
        Set<Integer> se = new HashSet<>();
        for (int t : nums) {
            if (se.contains(t)) {
                ans[already++] = t;
            } else {
                se.add(t);
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-10-31 22:24:27
 */
package main

func getSneakyNumbers(nums []int) (ans []int) {
    se := map[int]struct{}{}
    for _, t := range nums {
        if _, ok := se[t]; ok {
            ans = append(ans, t)
        } else {
            se[t] = struct{}{}
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-10-31 22:39:35
 */
use std::collections::HashSet;

impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut se = HashSet::new();
        let mut ans = Vec::with_capacity(2);
        for t in nums {
            if se.contains(&t) {
                ans.push(t);
            } else {
                se.insert(t);
            }
        }
        ans
    }
}
```

## 解题方法二：位运算

需要用到位运算两个性质：

1. 异或一个数偶数次，相当于什么都没干
2. lowbit：$x\&-x$得到的结果是$x$二进制下最后一个$1$及其后的$0$

知道了这两个性质，我们就可以先计算出$x\oplus y$（假设$x$和$y$出现了两次）

> 使用$0$来异或数组中的每一个数然后再从$0$异或到$n-1$，那么数组中每个出现了一次的数总计被异或两次，相当于没有被异或；
>
> 而$x$和$y$总计被异或了3次，也相当于分别被异或了一次。
>
> 所以得到的最终结果就是$x\oplus y$的值。

接下来拆分出$x$和$y$，核心思想是把$x$和$y$分成两组。怎么分成两组呢？还记得我们刚刚得到的$x\oplus y$吗：

> $x\neq y$所以$x\oplus y$一定非零。假设$x\oplus y=a$，那么对于$a$二进制下非零的位，$x$和$y$的对应位一定一个为零一个非零。
>
> 为了方便，我们可以以$lowbit$为依据，将所有的数分成两组。$0$到$n-1$中所有这一位为$1$的数分成一组，所有这一位为$0$的数分成一组。
>
> 那么对于两组分别进行类似的运算（异或两次），就能分别得到$x$和$y$了。（因为$x$所在的那一组里只有$x$出现了两次）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-31 22:49:15
 */
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int xored = 0;
        for (int t : nums) {
            xored ^= t;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            xored ^= i;
        }
        // now xored is x^y

        int lowbit = xored & -xored;
        int ans1 = 0, ans2 = 0;

        for (int t : nums) {
            if (t & lowbit) {
                ans1 ^= t;
            } else {
                ans2 ^= t;
            }
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i & lowbit) {
                ans1 ^= i;
            } else {
                ans2 ^= i;
            }
        }
        return {ans1, ans2};
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/154214125)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/10/31/LeetCode%203289.%E6%95%B0%E5%AD%97%E5%B0%8F%E9%95%87%E4%B8%AD%E7%9A%84%E6%8D%A3%E8%9B%8B%E9%AC%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
