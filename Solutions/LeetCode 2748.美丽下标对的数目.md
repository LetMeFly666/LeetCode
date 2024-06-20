---
title: 2748.美丽下标对的数目
date: 2024-06-20 16:05:33
tags: [题解, LeetCode, 简单, 数组, 数学, 数论]
---

# 【LetMeFly】2748.美丽下标对的数目：模拟

力扣题目链接：[https://leetcode.cn/problems/number-of-beautiful-pairs/](https://leetcode.cn/problems/number-of-beautiful-pairs/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。如果下标对 <code>i</code>、<code>j</code> 满足 <code>0 ≤ i &lt; j &lt; nums.length</code> ，如果&nbsp;<code>nums[i]</code> 的 <strong>第一个数字</strong> 和 <code>nums[j]</code> 的 <strong>最后一个数字</strong> <strong>互质</strong> ，则认为 <code>nums[i]</code> 和 <code>nums[j]</code> 是一组 <strong>美丽下标对</strong> 。</p>

<p>返回 <code>nums</code> 中 <strong>美丽下标对</strong> 的总数目。</p>

<p>对于两个整数 <code>x</code> 和 <code>y</code> ，如果不存在大于 1 的整数可以整除它们，则认为 <code>x</code> 和 <code>y</code> <strong>互质</strong> 。换而言之，如果 <code>gcd(x, y) == 1</code> ，则认为 <code>x</code> 和 <code>y</code> 互质，其中 <code>gcd(x, y)</code> 是 <code>x</code> 和 <code>k</code> <strong>最大公因数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,5,1,4]
<strong>输出：</strong>5
<strong>解释：</strong>nums 中共有 5 组美丽下标对：
i = 0 和 j = 1 ：nums[0] 的第一个数字是 2 ，nums[1] 的最后一个数字是 5 。2 和 5 互质，因此 gcd(2,5) == 1 。
i = 0 和 j = 2 ：nums[0] 的第一个数字是 2 ，nums[2] 的最后一个数字是 1 。2 和 5 互质，因此 gcd(2,1) == 1 。
i = 1 和 j = 2 ：nums[1] 的第一个数字是 5 ，nums[2] 的最后一个数字是 1 。2 和 5 互质，因此 gcd(5,1) == 1 。
i = 1 和 j = 3 ：nums[1] 的第一个数字是 5 ，nums[3] 的最后一个数字是 4 。2 和 5 互质，因此 gcd(5,4) == 1 。
i = 2 和 j = 3 ：nums[2] 的第一个数字是 1 ，nums[3] 的最后一个数字是 4 。2 和 5 互质，因此 gcd(1,4) == 1 。
因此，返回 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [11,21,12]
<strong>输出：</strong>2
<strong>解释：</strong>共有 2 组美丽下标对：
i = 0 和 j = 1 ：nums[0] 的第一个数字是 1 ，nums[1] 的最后一个数字是 1 。gcd(1,1) == 1 。
i = 0 和 j = 2 ：nums[0] 的第一个数字是 1 ，nums[2] 的最后一个数字是 2 。gcd(1,2) == 1 。
因此，返回 2 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 9999</code></li>
	<li><code>nums[i] % 10 != 0</code></li>
</ul>


    
## 解题方法：模拟

两层循环模拟$i$和$j$即可。

**获得某个数十进制下第一位的方法：**

> 对于整数$n$，当$n\geq 10$时不断令$n=\lfloor\frac{n}{10}\rfloor$，最终的$n$即为所求。

**获得某个数十进制下最后一位的方法：**

> 对于整数$n$，$n\mod 10$即为所求。

**获得两个数的最大公因数的方法：**

> 可用辗转相除法。对于两个数$a$和$b$，令$c=a\mod b$：
>
> + 若$c=0$则$b$即为所求；
> + 否则令$a, b = b, c$。

+ 时间复杂度$O(n^2+n\log C)$，其中$C$为一个数的最大值
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    inline int getFirst(int n) {
        while (n >= 10) {
            n /= 10;
        }
        return n;
    }
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (__gcd(getFirst(nums[i]), nums[j] % 10) == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
// package main

func getFirst(n int) int {
    for ; n >= 10; {
        n /= 10;
    }
    return n
}

func gcd(a int, b int) int {
    if b == 0 {
        return a
    }
    return gcd(b, a % b)
}

func countBeautifulPairs(nums []int) int {
    ans := 0
    for i := 0; i < len(nums); i++ {
        for j := i + 1; j < len(nums); j++ {
            if gcd(getFirst((nums[i])), nums[j] % 10) == 1 {
                ans++
            }
        }
    }
    return ans
}
```

#### Java

```java
// import java.math.BigInteger;

class Solution {
    private BigInteger getFirst(int n) {
        while (n >= 10) {
            n /= 10;
        }
        return BigInteger.valueOf(n);
    }

    public int countBeautifulPairs(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (getFirst(nums[i]).gcd(BigInteger.valueOf(nums[j] % 10)).equals(BigInteger.valueOf(1))) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List
from math import gcd

"""
[2,5,1,4]
"""
class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if gcd(ord(str(nums[i])[0]) - ord('0'), nums[j] % 10) == 1:
                    ans += 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/20/LeetCode%202748.%E7%BE%8E%E4%B8%BD%E4%B8%8B%E6%A0%87%E5%AF%B9%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139842524](https://letmefly.blog.csdn.net/article/details/139842524)
