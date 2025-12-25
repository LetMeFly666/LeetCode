---
title: 3075.幸福值最大化的选择方案：排序
date: 2025-12-25 13:21:16
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】3075.幸福值最大化的选择方案：排序

力扣题目链接：[https://leetcode.cn/problems/maximize-happiness-of-selected-children/](https://leetcode.cn/problems/maximize-happiness-of-selected-children/)

<p>给你一个长度为 <code>n</code> 的数组 <code>happiness</code> ，以及一个<strong> 正整数 </strong><code>k</code> 。</p>

<p><code>n</code> 个孩子站成一队，其中第 <code>i</code> 个孩子的 <strong>幸福值</strong> 是<strong> </strong><code>happiness[i]</code> 。你计划组织 <code>k</code> 轮筛选从这 <code>n</code> 个孩子中选出 <code>k</code> 个孩子。</p>

<p>在每一轮选择一个孩子时，所有<strong> 尚未 </strong>被选中的孩子的 <strong>幸福值 </strong>将减少 <code>1</code> 。注意，幸福值<strong> 不能 </strong>变成负数，且只有在它是正数的情况下才会减少。</p>

<p>选择 <code>k</code> 个孩子，并使你选中的孩子幸福值之和最大，返回你能够得到的<strong> </strong><strong>最大值</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>happiness = [1,2,3], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>按以下方式选择 2 个孩子：
- 选择幸福值为 3 的孩子。剩余孩子的幸福值变为 [0,1] 。
- 选择幸福值为 1 的孩子。剩余孩子的幸福值变为 [0] 。注意幸福值不能小于 0 。
所选孩子的幸福值之和为 3 + 1 = 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>happiness = [1,1,1,1], k = 2
<strong>输出：</strong>1
<strong>解释：</strong>按以下方式选择 2 个孩子：
- 选择幸福值为 1 的任意一个孩子。剩余孩子的幸福值变为 [0,0,0] 。
- 选择幸福值为 0 的孩子。剩余孩子的幸福值变为 [0,0] 。
所选孩子的幸福值之和为 1 + 0 = 1 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>happiness = [2,3,4,5], k = 1
<strong>输出：</strong>5
<strong>解释：</strong>按以下方式选择 1 个孩子：
- 选择幸福值为 5 的孩子。剩余孩子的幸福值变为 [1,2,3] 。
所选孩子的幸福值之和为 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == happiness.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= happiness[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>


    
## 解题方法：排序

题目翻译：

> 每个孩子都有一个价值，一次只能压榨一个孩子的价值。每剥夺一个孩子的价值，其他娃子都会因为受到惊吓而价值减一，一旦某娃子没有了使用价值就会被立刻丢弃。
>
> 问最多压榨k个娃子最多夺取多少总价值。

怎么选？当然是按照价值大的优先选。没被压榨过的娃子们也会随着时间的流逝人老珠黄，但是没办法，一次只能压榨一个。

让娃子们俺价值从大到小排个序，每次压榨一个，第几次压榨被压榨孩子的价值就会减少几减1。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-25 12:59:03
 */
typedef long long ll;
class Solution {
public:
    ll maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            ans += max(0, happiness[i] - i);
        }
        return ans;
    }
};
```

#### C++

当然，前娃都没价值的时候后娃子肯定也没价值了，可直接提前完工。

```cpp
/*
 * @LastEditTime: 2025-12-25 13:00:12
 */
typedef long long ll;
class Solution {
public:
    ll maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<>());
        ll ans = 0;
        for (int i = 0; i < k; i++) {
            happiness[i] -= i;
            if (happiness[i] <= 0) {
                return ans;
            }
            ans += happiness[i];
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-12-25 13:02:05
'''
from typing import List

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        return sum(max(0, h - i) for i, h in enumerate(sorted(happiness, reverse=True)[:k]))
```

#### Java

```java
/*
 * @LastEditTime: 2025-12-25 13:18:34
 */
import java.util.Arrays;

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long ans = 0;
        int n = happiness.length;
        for (int i = 0; i < k; i++) {
            if (happiness[n - i - 1] <= i) {
                return ans;
            }
            ans += happiness[n - i - 1] - i;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-25 13:08:10
 */
package main

import "sort"

func maximumHappinessSum(happiness []int, k int) (ans int64) {
    sort.Slice(happiness, func(i, j int) bool { return happiness[i] > happiness[j] })
    for i := 0; i < k; i++ {
        happiness[i] -= i
        if happiness[i] <= 0 {
            return
        }
        ans += int64(happiness[i])
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-25 13:12:12
 */
impl Solution {
    pub fn maximum_happiness_sum(mut happiness: Vec<i32>, k: i32) -> i64 {
        let mut ans: i64 = 0;
        happiness.sort_by(|a: &i32, b: &i32| b.cmp(a));
        for i in 0..k {
            if happiness[i as usize] <= i {
                return ans;
            }
            ans += (happiness[i as usize] - i) as i64;
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156268485)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/25/LeetCode%203075.%E5%B9%B8%E7%A6%8F%E5%80%BC%E6%9C%80%E5%A4%A7%E5%8C%96%E7%9A%84%E9%80%89%E6%8B%A9%E6%96%B9%E6%A1%88/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
