---
title: 2535.数组元素和与数字和的绝对差
date: 2024-09-26 18:14:41
tags: [题解, LeetCode, 简单, 数组, 数学, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2535.数组元素和与数字和的绝对差：模拟

力扣题目链接：[https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/](https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/)

<p>给你一个正整数数组 <code>nums</code> 。</p>

<ul>
	<li><strong>元素和</strong> 是 <code>nums</code> 中的所有元素相加求和。</li>
	<li><strong>数字和</strong> 是&nbsp;<code>nums</code> 中每一个元素的每一数位（重复数位需多次求和）相加求和。</li>
</ul>

<p>返回 <strong>元素和</strong> 与 <strong>数字和</strong> 的绝对差。</p>

<p><strong>注意：</strong>两个整数 <code>x</code> 和 <code>y</code> 的绝对差定义为 <code>|x - y|</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,15,6,3]
<strong>输出：</strong>9
<strong>解释：</strong>
nums 的元素和是 1 + 15 + 6 + 3 = 25 。
nums 的数字和是 1 + 1 + 5 + 6 + 3 = 16 。
元素和与数字和的绝对差是 |25 - 16| = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>0
<strong>解释：</strong>
nums 的元素和是 1 + 2 + 3 + 4 = 10 。
nums 的数字和是 1 + 2 + 3 + 4 = 10 。
元素和与数字和的绝对差是 |10 - 10| = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>


    
## 解题方法：模拟

写一个函数`getSum(x)`返回整数`x`在十进制下的每位之和：

```cpp
int getSum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
```

使用两个变量`x`和`y`分别记录元素之和和元素每一位之和，遍历一遍原始数组即可得到这个值。

最终，返回`abs(x - y)`即为答案。

+ 时间复杂度$O(len(nums)\times \log M)$，其中$M$是$nums[i]$可取值范围的最大值$2000$。
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int getSum(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int differenceOfSum(vector<int>& nums) {
        int x = 0, y = 0;
        for (int t : nums) {
            x += t, y += getSum(t);
        }
        return abs(x - y);
    }
};
```

#### Go

```go
package main

func abs(x int) int {
    if x >= 0 {
        return x
    }
    return -x
}

func getSum(x int) int {
    ans := 0
    for x > 0 {
        ans += x % 10
        x /= 10
    }
    return ans
}

func differenceOfSum(nums []int) int {
    x, y := 0, 0
    for _, t := range nums {
        x += t
        y += getSum(t)
    }
    return abs(x - y)
}
```

#### Java

```java
class Solution {
    private int getSum(int t) {
        int ans = 0;
        while (t > 0) {
            ans += t % 10;
            t /= 10;
        }
        return ans;
    }

    public int differenceOfSum(int[] nums) {
        int x = 0, y = 0;
        for (int t : nums) {
            x += t;
            y += getSum(t);
        }
        return Math.abs(x - y);
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def getSum(self, x: int) -> int:
        ans = 0
        while x:
            ans += x % 10
            x //= 10
        return ans

    def differenceOfSum(self, nums: List[int]) -> int:
        x = y = 0
        for t in nums:
            x += t
            y += self.getSum(t)
        return abs(x - y)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/26/LeetCode%202535.%E6%95%B0%E7%BB%84%E5%85%83%E7%B4%A0%E5%92%8C%E4%B8%8E%E6%95%B0%E5%AD%97%E5%92%8C%E7%9A%84%E7%BB%9D%E5%AF%B9%E5%B7%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142568318](https://letmefly.blog.csdn.net/article/details/142568318)
