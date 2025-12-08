---
title: 1925.统计平方和三元组的数目：两层循环枚举
date: 2025-12-08 21:56:26
tags: [题解, LeetCode, 简单, 数学, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】1925.统计平方和三元组的数目：两层循环枚举

力扣题目链接：[https://leetcode.cn/problems/count-square-sum-triples/](https://leetcode.cn/problems/count-square-sum-triples/)

<p>一个 <strong>平方和三元组</strong> <code>(a,b,c)</code> 指的是满足 <code>a<sup>2</sup> + b<sup>2</sup> = c<sup>2</sup></code> 的 <strong>整数 </strong>三元组 <code>a</code>，<code>b</code> 和 <code>c</code> 。</p>

<p>给你一个整数 <code>n</code> ，请你返回满足<em> </em><code>1 &lt;= a, b, c &lt;= n</code> 的 <strong>平方和三元组</strong> 的数目。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 5
<b>输出：</b>2
<b>解释：</b>平方和三元组为 (3,4,5) 和 (4,3,5) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 10
<b>输出：</b>4
<b>解释：</b>平方和三元组为 (3,4,5)，(4,3,5)，(6,8,10) 和 (8,6,10) 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 250</code></li>
</ul>


    
## 解题方法：两层循环枚举

n的数据范围只有$250$，因此可以第一层循环用$a$从$1$到$n$枚举，第二层循环用$b$从$1$到$n$枚举。

由于第三层循环再从$1$枚举到$n$的话，最大时间复杂度可能会达到$250^3\approx1.6\times10^7$，有超时风险，

所以直接算出$a^2+b^2$的值（记为$k$），令$c=\lfloor\sqrt{k}\rfloor$，看$c$是否不超过$n$且$c^2=k$

+ 时间复杂度$O(n^2)$，开根号时间复杂度视为$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-08 18:47:09
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int k = a * a + b * b;
                int c = sqrt(k);
                ans += c * c == k && c <= n;
                // if (c * c == k) {
                //     printf("(%d, %d, %d)\n", a, b, c);
                // }
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
int main() {
    Solution sol;
    cout << sol.countTriples(5) << endl;
    cout << sol.countTriples(12) << endl;
    return 0;
}
#endif
```

#### Python

```python
'''
LastEditTime: 2025-12-08 18:53:01
'''
from math import sqrt

class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                k = a * a + b * b
                c = int(sqrt(k))
                ans += c <= n and c * c == k
                # if c <= n and c * c == k:
                #     print(f"({a}, {b}, {c})")
        return ans

# a = Solution()
# print(a.countTriples(5))
```

#### Java

```java
/*
 * @LastEditTime: 2025-12-08 18:59:47
 */
class Solution {
    public int countTriples(int n) {
        int ans = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int k = a * a + b * b;
                int c = (int)Math.sqrt(k);
                if (c <= n && c * c == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-08 18:57:02
 */
package main

import "math"

func countTriples(n int) (ans int) {
    for a := 1; a <= n; a++ {
        for b := 1; b <= n; b++ {
            k := a * a + b * b
            c := int(math.Sqrt(float64(k)))
            if c <= n && c * c == k {
                ans++
            }
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-08 21:55:06
 */
impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut ans: i32 = 0;
        for a in 1..n+1 {
            for b in 1..n+1 {
                let k = a * a + b * b;
                let c = (k as f64).sqrt() as i32;
                if c <= n && c * c == k {
                    ans += 1;
                }
            }
        }
        ans
    }
}
```

## End

<font size="6px" face="Ink Free" title="no “.”">I am back</font>

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/155717892)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/08/LeetCode%201925.%E7%BB%9F%E8%AE%A1%E5%B9%B3%E6%96%B9%E5%92%8C%E4%B8%89%E5%85%83%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
