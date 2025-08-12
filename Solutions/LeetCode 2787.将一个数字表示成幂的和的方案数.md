---
title: 2787.将一个数字表示成幂的和的方案数：经典01背包
date: 2025-08-12 22:24:47
tags: [题解, LeetCode, 中等, 动态规划, DP, 背包问题, 01背包, 快速幂]
categories: [题解, LeetCode]
---

# 【LetMeFly】2787.将一个数字表示成幂的和的方案数：经典01背包

力扣题目链接：[https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/](https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers/)

<p>给你两个 <strong>正</strong>&nbsp;整数&nbsp;<code>n</code> 和&nbsp;<code>x</code>&nbsp;。</p>

<p>请你返回将<em>&nbsp;</em><code>n</code>&nbsp;表示成一些&nbsp;<strong>互不相同</strong>&nbsp;正整数的<em>&nbsp;</em><code>x</code>&nbsp;次幂之和的方案数。换句话说，你需要返回互不相同整数&nbsp;<code>[n<sub>1</sub>, n<sub>2</sub>, ..., n<sub>k</sub>]</code>&nbsp;的集合数目，满足&nbsp;<code>n = n<sub>1</sub><sup>x</sup> + n<sub>2</sub><sup>x</sup> + ... + n<sub>k</sub><sup>x</sup></code>&nbsp;。</p>

<p>由于答案可能非常大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余后返回。</p>

<p>比方说，<code>n = 160</code> 且&nbsp;<code>x = 3</code>&nbsp;，一个表示&nbsp;<code>n</code>&nbsp;的方法是&nbsp;<code>n = 2<sup>3</sup> + 3<sup>3</sup> + 5<sup>3</sup></code><sup>&nbsp;</sup>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 10, x = 2
<b>输出：</b>1
<b>解释：</b>我们可以将 n 表示为：n = 3<sup>2</sup> + 1<sup>2</sup> = 10 。
这是唯一将 10 表达成不同整数 2 次方之和的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 4, x = 1
<b>输出：</b>2
<b>解释：</b>我们可以将 n 按以下方案表示：
- n = 4<sup>1</sup> = 4 。
- n = 3<sup>1</sup> + 1<sup>1</sup> = 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>1 &lt;= x &lt;= 5</code></li>
</ul>


    
## 解题方法：动态规划(01背包)

这道题可以翻译为：$t^x$组成的数组中选择一些和为$n$的数有多少种方案。

可以使用$dp[i]$代表和为$i$的方案数，初始值$dp[0]=1$，$dp[1..n]=0$。

第一层循环从数组中取数，第二层循环倒序遍历dp数组且有状态转移方程$dp[i] += dp[i - p]$，其中$p$是数组中的一个$t^x$。倒序是为了得到$dp[i]$时保证$dp[i-p]$在第二层循环中还未被更改过。

+ 时间复杂度$O(n\times \sqrt[x]{n})$
+ 空间复杂度$O(n)$

### AC代码

#### C++

C++代码使用了快速幂，因数据范围很小所以浮点数pow也不会出现精度误差，若不想写快速幂也可以直接删掉`int pow()`函数。

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 21:33:24
 */
// dp[i]: 和为i的方案数
class Solution {
private:
    static const long long MOD = 1e9 + 7;

    int pow(int a, int b) {
        long long ans = 1;
        while (b) {
            if (b & 1) {
                ans = ans * a;
            }
            a = a * a;
            b >>= 1;
        }
        return ans;
    }
public:
    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int th = 1; ; th++) {
            int p = pow(th, x);
            if (p > n) {
                break;
            }
            for (int i = n; i >= p; i--) {
                dp[i] = (dp[i] + dp[i - p]) % MOD;
            }
        }
        return dp.back();
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-12 09:48:56
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-12 21:37:06
'''
class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        dp = [1] + [0] * n
        th = 1
        while True:
            p = th ** x
            if p > n:
                break
            th += 1
            for i in range(n, p - 1, -1):
                dp[i] += dp[i - p]
        return dp[-1] % 1000000007
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 21:50:02
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int numberOfWays(int n, int x) {
        long[] dp = new long[n + 1];
        dp[0] = 1;
        for (int th = 1; ; th++) {
            int p = (int)Math.pow(th, x);
            if (p > n) {
                break;
            }
            for (int i = n; i >= p; i--) {
                dp[i] += dp[i - p];
            }
        }
        return (int)(dp[n] % 1000000007);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 21:42:16
 */
package main

import "math"

func pow2787(a, b int) int {
    return int(math.Pow(float64(a), float64(b)))
}

func numberOfWays(n int, x int) int {
    dp := make([]int, n + 1)
    dp[0] = 1
    for th := 1; ; th++ {
        p := pow2787(th, x)
        if p > n {
            break
        }
        for i := n; i >= p; i-- {
            dp[i] += dp[i - p]
        }
    }
    return dp[n] % 1000000007
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-12 09:48:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-12 22:00:07
 */
impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        let n: usize = n as usize;
        let mut dp: Vec<i32> = vec![0; n + 1];
        dp[0] = 1;
        for th in 1usize.. {
            let p: usize = th.pow(x as u32);
            if p > n {
                break;
            }
            for i in (p..=n).rev() {
                dp[i] = ((dp[i] as i64 + dp[i - p] as i64) % (1000000007 as i64)) as i32
            }
        }
        dp[n]
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150296585)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/12/LeetCode%202787.%E5%B0%86%E4%B8%80%E4%B8%AA%E6%95%B0%E5%AD%97%E8%A1%A8%E7%A4%BA%E6%88%90%E5%B9%82%E7%9A%84%E5%92%8C%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
