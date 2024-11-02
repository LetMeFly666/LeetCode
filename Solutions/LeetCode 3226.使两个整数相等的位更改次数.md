---
title: 3226.使两个整数相等的位更改次数
date: 2024-11-02 11:09:29
tags: [题解, LeetCode, 简单, 位运算]
---

# 【LetMeFly】3226.使两个整数相等的位更改次数：位运算（接近O(1)的做法）

力扣题目链接：[https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal/](https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal/)

<p>给你两个正整数 <code>n</code> 和 <code>k</code>。</p>

<p>你可以选择 <code>n</code> 的 <strong>二进制表示</strong> 中任意一个值为 1 的位，并将其改为 0。</p>

<p>返回使得 <code>n</code> 等于 <code>k</code> 所需要的更改次数。如果无法实现，返回 -1。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 13, k = 4</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong><br />
最初，<code>n</code> 和 <code>k</code> 的二进制表示分别为 <code>n = (1101)<sub>2</sub></code> 和 <code>k = (0100)<sub>2</sub></code>，</p>

<p>我们可以改变 <code>n</code> 的第一位和第四位。结果整数为 <code>n = (<u><strong>0</strong></u>10<u><strong>0</strong></u>)<sub>2</sub> = k</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 21, k = 21</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong><br />
<code>n</code> 和 <code>k</code> 已经相等，因此不需要更改。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 14, k = 13</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong><br />
无法使 <code>n</code> 等于 <code>k</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 解题方法：位运算

如何通过位运算判断能否实现？

> 若`n | k == n`则说明`n`二进制下为`0`的位在`k`中也都为`0`，说明可行。

可行情况下如何快速统计需要修改多少次？

> `n 异或 k`后，二者二进制不同的位将会变成`1`，相同的位则会变成`0`。因此使用内置函数统计`n 异或 k`的结果中有多少个`1`即为答案。

+ 时间复杂度$O(1)$。统计二进制下有多少个`1`的时间复杂度可能和编程语言以及CPU有无对应指令有关，可以是$O(1)$或近似看成$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minChanges(int n, int k) {
        return (n | k) == n ? __builtin_popcount(n ^ k) : -1;
    }
};
```

#### C++（非位运算但纯模拟版本）

$O(\log \max n)$

```cpp
class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for (int i = 0; i < 20; i++) {
            int thisN = n & (1 << i), thisK = k & (1 << i);
            if (thisN && !thisK) {
                ans++;
            } else if (thisN != thisK) {
                return -1;
            }
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def minChanges(self, n: int, k: int) -> int:
        return (n ^ k).bit_count() if (n | k) == n else -1
```

#### Java

```java
class Solution {
    public int minChanges(int n, int k) {
        return (n | k) == n ? Integer.bitCount(n ^ k) : -1;
    }
}
```

#### Go

```go
package main
import "math/bits"

func minChanges(n int, k int) int {
    if n | k == n {
        return bits.OnesCount(uint(n ^ k))
    }
    return -1
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/02/LeetCode%203226.%E4%BD%BF%E4%B8%A4%E4%B8%AA%E6%95%B4%E6%95%B0%E7%9B%B8%E7%AD%89%E7%9A%84%E4%BD%8D%E6%9B%B4%E6%94%B9%E6%AC%A1%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143448117](https://letmefly.blog.csdn.net/article/details/143448117)
