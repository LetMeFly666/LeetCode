---
title: 3577.统计计算机解锁顺序排列数：脑筋急转弯(组合数学)
date: 2025-12-10 23:07:43
tags: [题解, LeetCode, 中等, 脑筋急转弯, 数组, 数学, 组合数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3577.统计计算机解锁顺序排列数：脑筋急转弯(组合数学)

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations/](https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations/)

<p>给你一个长度为 <code>n</code> 的数组 <code>complexity</code>。</p>

<p>在房间里有 <code>n</code> 台&nbsp;<strong>上锁的&nbsp;</strong>计算机，这些计算机的编号为 0 到 <code>n - 1</code>，每台计算机都有一个&nbsp;<strong>唯一&nbsp;</strong>的密码。编号为 <code>i</code> 的计算机的密码复杂度为 <code>complexity[i]</code>。</p>

<p>编号为 0 的计算机密码已经&nbsp;<strong>解锁&nbsp;</strong>，并作为根节点。其他所有计算机必须通过它或其他已经解锁的计算机来解锁，具体规则如下：</p>

<ul>
	<li>可以使用编号为 <code>j</code> 的计算机的密码解锁编号为 <code>i</code> 的计算机，其中 <code>j</code> 是任何小于 <code>i</code> 的整数，且满足 <code>complexity[j] &lt; complexity[i]</code>（即 <code>j &lt; i</code> 并且 <code>complexity[j] &lt; complexity[i]</code>）。</li>
	<li>要解锁编号为 <code>i</code> 的计算机，你需要事先解锁一个编号为 <code>j</code> 的计算机，满足 <code>j &lt; i</code> 并且 <code>complexity[j] &lt; complexity[i]</code>。</li>
</ul>

<p>求共有多少种 <code>[0, 1, 2, ..., (n - 1)]</code> 的排列方式，能够表示从编号为 0 的计算机（唯一初始解锁的计算机）开始解锁所有计算机的有效顺序。</p>

<p>由于答案可能很大，返回结果需要对 <strong>10<sup>9</sup> + 7</strong> 取余数。</p>

<p><strong>注意：</strong>编号为 0 的计算机的密码已解锁，而&nbsp;<strong>不是&nbsp;</strong>排列中第一个位置的计算机密码已解锁。</p>

<p><strong>排列&nbsp;</strong>是一个数组中所有元素的重新排列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">complexity = [1,2,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>有效的排列有：</p>

<ul>
	<li>[0, 1, 2]
	<ul>
		<li>首先使用根密码解锁计算机 0。</li>
		<li>使用计算机 0 的密码解锁计算机 1，因为 <code>complexity[0] &lt; complexity[1]</code>。</li>
		<li>使用计算机 1 的密码解锁计算机 2，因为 <code>complexity[1] &lt; complexity[2]</code>。</li>
	</ul>
	</li>
	<li>[0, 2, 1]
	<ul>
		<li>首先使用根密码解锁计算机 0。</li>
		<li>使用计算机 0 的密码解锁计算机 2，因为 <code>complexity[0] &lt; complexity[2]</code>。</li>
		<li>使用计算机 0 的密码解锁计算机 1，因为 <code>complexity[0] &lt; complexity[1]</code>。</li>
	</ul>
	</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">complexity = [3,3,3,4,4,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>没有任何排列能够解锁所有计算机。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= complexity.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= complexity[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：组合数学

题目意思是：编号从0到n-1的计算机，编号小且值小的可以解锁编号大且值大的，初始只有编号0（也就是给定序列中的第一个）是解锁状态，问解锁所有计算机有多少种解锁顺序（先解锁1号再解锁2号是一种，先解锁2号再解锁1号是另一种，至于它们是被谁解锁的不重要）。

转念一想发现，如果后面存在小于等于<font title="EVA00">零号机</font>的机器，则无论如何都不可能被解锁；反之若后面值都大于0号机，则后续任何一个机器想在任何次序(th)解锁都可以（都用0号去解锁就好了）。

### 具体方法

遍历一遍数组，如果有值小于等于数组中第一个元素，则返回0。

否则后面$len(complexity)-1$个机器的被解锁顺序可以按任意顺序排列，$(n-1)!$即为所求。

### 时空复杂度分析

+ 时间复杂度$O(n)$，其中$n=len(complexity)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-10 22:56:22
 */
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        ll ans = 1;
        for (ll i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            ans = ans * i % MOD;
        }
        return static_cast<int>(ans);
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-12-10 22:59:13
'''
from typing import List

class Solution:
    MOD = 1000000007

    def countPermutations(self, complexity: List[int]) -> int:
        ans = 1
        for i in range(1, len(complexity)):
            if complexity[i] <= complexity[0]:
                return 0
            ans = ans * i % self.MOD
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2025-12-10 23:03:09
 */
class Solution {
    private long MOD = 1000000007;

    public int countPermutations(int[] complexity) {
        long ans = 1;
        for (int i = 1; i < complexity.length; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            ans = ans * i % MOD;
        }
        return (int)ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-10 23:00:19
 */
package main

var MOD3577 int = 1000000007

func countPermutations(complexity []int) int {
    ans := 1
    for i := 1; i < len(complexity); i++ {
        if complexity[i] <= complexity[0] {
            return 0
        }
        ans = ans * i % MOD3577
    }
    return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-10 23:06:41
 */
impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        let mut ans: i64 = 1;
        let MOD: i64 = 1000000007;
        for i in 1..complexity.len() {
            if complexity[i] <= complexity[0] {
                return 0;
            }
            ans = ans * (i as i64) % MOD;
        }
        ans as i32
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/155791805)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/10/LeetCode%203577.%E7%BB%9F%E8%AE%A1%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%A7%A3%E9%94%81%E9%A1%BA%E5%BA%8F%E6%8E%92%E5%88%97%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
