---
title: 1323.6 和 9 组成的最大数字：字符串辅助或直接计算
date: 2025-08-16 11:01:40
tags: [题解, LeetCode, 简单, 贪心, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1323.6 和 9 组成的最大数字：字符串辅助或直接计算

力扣题目链接：[https://leetcode.cn/problems/maximum-69-number/](https://leetcode.cn/problems/maximum-69-number/)

<p>给你一个仅由数字 6 和 9 组成的正整数&nbsp;<code>num</code>。</p>

<p>你最多只能翻转一位数字，将 6 变成&nbsp;9，或者把&nbsp;9 变成&nbsp;6 。</p>

<p>请返回你可以得到的最大数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 9669
<strong>输出：</strong>9969
<strong>解释：</strong>
改变第一位数字可以得到 6669 。
改变第二位数字可以得到 9969 。
改变第三位数字可以得到 9699 。
改变第四位数字可以得到 9666 。
其中最大的数字是 9969 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 9996
<strong>输出：</strong>9999
<strong>解释：</strong>将最后一位从 6 变到 9，其结果 9999 是最大的数。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 9999
<strong>输出：</strong>9999
<strong>解释：</strong>无需改变就已经是最大的数字了。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^4</code></li>
	<li><code>num</code>&nbsp;每一位上的数字都是 6 或者&nbsp;9 。</li>
</ul>


    
## 解题方法一：字符串辅助计算

这是最简单的一种方式，直接把num转为字符串，从前到后遍历字符串并将第一个`6`变成`9`，最后再转回正数。

+ 时间复杂度$O(\log_{10}num)$
+ 空间复杂度$O(\log_{10}num)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:19:20
 */
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break;  // 记得break
            }
        }
        return atoi(s.c_str());
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-16 10:17:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-16 10:24:13
'''
class Solution:
    def maximum69Number (self, num: int) -> int:
        s = list(str(num))
        for i, c in enumerate(s):
            if c == '6':
                s[i] = '9'
                break
        return int(''.join(s))  # 记得转回int
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:46:36
 */
class Solution {
    public int maximum69Number (int num) {
        return Integer.parseInt(String.valueOf(num).replaceFirst("6", "9"));  // java竟然一行解决了
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:43:00
 */
package main

import (
    "strconv"
    "strings"
)

func maximum69Number (num int) (ans int) {
    s := strconv.Itoa(num)
    s = strings.Replace(s, "6", "9", 1)
    ans, _ = strconv.Atoi(s)
    return
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:48:36
 */
impl Solution {
    pub fn maximum69_number (num: i32) -> i32 {
        num.to_string().replacen("6", "9", 1).parse().unwrap()
    }
}
```

## 解题方法二：直接计算

### 总体思路

想要知道num十进制下的第一个6，必须把num转为字符串吗？

不需要，将num不断模10，取出十进制下的每一位，并记下第一个6的下标即可。

知道了第一个6的下标first6loc，那么将这个6变成9，num会变大多少呢？会变大($3000...=3\times 10^{first6loc}$)。

### 具体的num变大方法

#### method1

就按照上面说的方法做就行。

#### 小优化

为了不再计算一次$10^{first6loc}$，我们也可以在循环过程中顺便算出$10^{first6loc}$。

只需要将之前的更新$first6loc$改为更新$10^{first6loc}$即可。

### 时空复杂度分析

+ 时间复杂度$O(\log_{10}num)$
+ 空间复杂度$O(1)$

### AC代码

#### C++ - method1

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:30:45
 */
class Solution {
public:
    int maximum69Number (int num) {
        int first6loc = -1;
        for (int n = num, loc = 0; n; n /= 10, loc++) {
            if (n % 10 == 6) {
                first6loc = loc;
            }
        }
        if (first6loc == -1) {
            return num;
        }
        return num + 3 * pow(10, first6loc);
    }
};
```

#### C++ - 小优化

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-16 10:17:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-16 10:34:19
 */
class Solution {
public:
    int maximum69Number (int num) {
        int base = 0;
        for (int n = num, loc = 0, nowPow = 1; n; n /= 10, loc++, nowPow *= 10) {
            if (n % 10 == 6) {
                base = nowPow;
            }
        }
        return num + base * 3;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150443019)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/16/LeetCode%201323.6%E5%92%8C9%E7%BB%84%E6%88%90%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E5%AD%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
