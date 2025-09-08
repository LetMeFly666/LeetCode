---
title: 1317.将整数转换为两个无零整数的和：暴力模拟
date: 2025-09-08 23:25:21
tags: [题解, LeetCode, 简单, 数学, 暴力, 模拟, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】1317.将整数转换为两个无零整数的和：暴力模拟

力扣题目链接：[https://leetcode.cn/problems/convert-integer-to-the-sum-of-two-no-zero-integers/](https://leetcode.cn/problems/convert-integer-to-the-sum-of-two-no-zero-integers/)

<p>「无零整数」是十进制表示中 <strong>不含任何 0</strong>&nbsp;的正整数。</p>

<p>给你一个整数&nbsp;<code>n</code>，请你返回一个 <strong>由两个整数组成的列表</strong> <code>[a, b]</code>，满足：</p>

<ul>
	<li><code>a</code> 和 <code>b</code>&nbsp;都是无零整数</li>
	<li><code>a + b = n</code></li>
</ul>

<p>题目数据保证至少有一个有效的解决方案。</p>

<p>如果存在多个有效解决方案，你可以返回其中任意一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[1,1]
<strong>解释：</strong>a = 1, b = 1。a + b = n 并且 a 和 b 的十进制表示形式都不包含任何 0。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 11
<strong>输出：</strong>[2,9]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 10000
<strong>输出：</strong>[1,9999]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 69
<strong>输出：</strong>[1,68]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>n = 1010
<strong>输出：</strong>[11,999]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：模拟

从`1`到`n-1`枚举`i`，如果`i`和`n-i`十进制下都不包含`0`，则返回`[i, n - i]`。

如何判断一个数字十进制下是否含有0？两种方法：

1. 当这个数大于0时不断模10看余数，然后将这个数除以10向下取整直到为0为止。期间若任何一个余数为0则说明十进制下包含0。
2. 判断这个数十进制下字符串中是否包含字符`0`。

想简单题复杂做(玩玩)的话也可以参考：[灵神@三种方法：枚举/随机/构造](https://leetcode.cn/problems/convert-integer-to-the-sum-of-two-no-zero-integers/solutions/3761217/san-chong-fang-fa-mei-ju-sui-ji-gou-zao-fown3/)。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度：不使用字符串$O(1)$，使用字符串$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:11:26
 */
class Solution {
private:
    inline bool ok(int n) {
        while (n) {
            if (n % 10 == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (ok(i) && ok(n - i)) {
                return {i, n - i};
            }
        }
        return {};  // FAKE RETURN
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-08 23:05:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-08 23:13:48
'''
from typing import List

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(n):
            if '0' not in str(i) and '0' not in str(n - i):
                return [i, n - i]
        return []  # FAKE RETURN
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:19:08
 */
class Solution {
    private boolean non0(int n) {
        while (n > 0) {
            if (n % 10 == 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    public int[] getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            if (non0(i) && non0(n - i)) {
                return new int[]{i, n - i};
            }
        }
        return new int[]{};
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:16:59
 */
package main

func nonZero1317(n int) bool {
    for n > 0 {
        if n % 10 == 0 {
            return false
        }
        n /= 10
    }
    return true
}

func getNoZeroIntegers(n int) (ans []int) {
    for i := 1; i < n; i++ {
        if nonZero1317(i) && nonZero1317(n - i) {
            return []int{i, n - i}
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-09-08 23:05:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-08 23:22:39
 */
impl Solution {
    fn ok(mut n: i32) -> bool {
        while n > 0 {
            if n % 10 == 0 {
                return false;
            }
            n /= 10
        }
        true
    }
    
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        for i in 1..n {
            if Solution::ok(i) && Solution::ok(n - i) {
                return vec![i, n - i];
            }
        }
        vec![]
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151335088)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/08/LeetCode%201317.%E5%B0%86%E6%95%B4%E6%95%B0%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%B8%A4%E4%B8%AA%E6%97%A0%E9%9B%B6%E6%95%B4%E6%95%B0%E7%9A%84%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
