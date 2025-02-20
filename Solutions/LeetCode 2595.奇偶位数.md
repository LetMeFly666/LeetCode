---
title: 2595.奇偶位数：位运算
date: 2025-02-20 12:11:36
tags: [题解, LeetCode, 简单, 位运算]
---

# 【LetMeFly】2595.奇偶位数：位运算

力扣题目链接：[https://leetcode.cn/problems/number-of-even-and-odd-bits/](https://leetcode.cn/problems/number-of-even-and-odd-bits/)

<p>给你一个 <strong>正</strong> 整数 <code>n</code> 。</p>

<p>用 <code>even</code> 表示在 <code>n</code> 的二进制形式（下标从 <strong>0</strong> 开始）中值为 <code>1</code> 的偶数下标的个数。</p>

<p>用 <code>odd</code> 表示在 <code>n</code> 的二进制形式（下标从 <strong>0</strong> 开始）中值为 <code>1</code> 的奇数下标的个数。</p>

<p>返回整数数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer = [even, odd]</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 17
<strong>输出：</strong>[2,0]
<strong>解释：</strong>17 的二进制形式是 10001 。 
下标 0 和 下标 4 对应的值为 1 。 
共有 2 个偶数下标，0 个奇数下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>[0,1]
<strong>解释：</strong>2 的二进制形式是 10 。 
下标 1 对应的值为 1 。 
共有 0 个偶数下标，1 个奇数下标。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


挺好一道题。

## 解题方法：位运算

解决这道题需要解决三个问题：

1. 如何取出$n$的最低位？

    `n & 1`即可

2. 如何移除$n$的最低为？

    直接右移`n >>= 1`即可

3. 如何变换奇偶下标？

    布尔类型`index = !index`或整型`index ^= 1`都可

+ 时间复杂度$O(\log(n))$。$\log 1024=10$，运算次数很低。
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-20 11:04:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-20 11:06:12
 */
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        bool index = false;
        while (n) {
            ans[index] += n & 1;
            index = !index;
            n >>= 1;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-20 11:06:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-20 11:08:51
'''
from typing import List

class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        ans = [0, 0]
        index = False
        while n:
            ans[index] += n & 1
            index = not index
            n >>= 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-20 11:06:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-20 11:10:57
 */
class Solution {
    public int[] evenOddBit(int n) {
        int[] ans = new int[2];
        int index = 0;
        while (n > 0) {
            ans[index] += n & 1;
            index ^= 1;
            n >>= 1;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-20 11:06:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-20 11:18:27
 */
package main

func evenOddBit(n int) []int {
    ans := make([]int, 2)
    for index := 0; n > 0; n >>= 1 {
        ans[index] += n & 1
        index ^= 1
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145750497)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/20/LeetCode%202595.%E5%A5%87%E5%81%B6%E4%BD%8D%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/20/LeetCode 2595.奇偶位数/](https://blog.letmefly.xyz/2025/02/20/LeetCode%202595.%E5%A5%87%E5%81%B6%E4%BD%8D%E6%95%B0/)
