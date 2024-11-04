---
title: 633.平方数之和
date: 2024-11-04 22:18:00
tags: [题解, LeetCode, 中等, 数学, 双指针, 二分查找]
---

# 【LetMeFly】633.平方数之和：模拟

力扣题目链接：[https://leetcode.cn/problems/sum-of-square-numbers/](https://leetcode.cn/problems/sum-of-square-numbers/)

<p>给定一个非负整数&nbsp;<code>c</code>&nbsp;，你要判断是否存在两个整数 <code>a</code> 和 <code>b</code>，使得&nbsp;<code>a<sup>2</sup> + b<sup>2</sup> = c</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>c = 5
<strong>输出：</strong>true
<strong>解释：</strong>1 * 1 + 2 * 2 = 5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>c = 3
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= c &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


    
## 解题方法：模拟

从$0$到$\sqrt{c}$模拟$a$，令$b=int(\sqrt{c-a^2})$。如果$a^2+b^2=c$则返回`true`。

+ 时间复杂度$O(\sqrt{c})$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int a = sqrt(c); a >= 0; a--) {
            int b = sqrt(c - a * a);
            if (b * b + a * a == c) {
                return true;
            }
        }
        return false;
    }
};
```

#### Python

```python
from math import sqrt

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for a in range(int(sqrt(c)) + 1):
            b = sqrt(c - a * a)
            if b == int(b):
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        for (int a = (int)Math.sqrt(c); a >= 0; a--) {
            int b = (int)Math.sqrt(c - a * a);
            if (a * a + b * b == c) {
                return true;
            }
        }
        return false;
    }
}
```

#### Go

```go
package main
import "math"

func judgeSquareSum(c int) bool {
    for a := int(math.Sqrt(float64(c))); a >= 0; a-- {
        b := int(math.Sqrt(float64(c - a * a)))
        if a * a + b * b == c {
            return true
        }
    }
    return false
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/04/LeetCode%200633.%E5%B9%B3%E6%96%B9%E6%95%B0%E4%B9%8B%E5%92%8C/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143495591](https://letmefly.blog.csdn.net/article/details/143495591)
