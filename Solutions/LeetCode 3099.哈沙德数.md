---
title: 3099.哈沙德数
date: 2024-07-03 19:31:51
tags: [题解, LeetCode, 简单, 数学]
---

# 【LetMeFly】3099.哈沙德数：计算一个数十进制下各位之和

力扣题目链接：[https://leetcode.cn/problems/harshad-number/](https://leetcode.cn/problems/harshad-number/)

<p>如果一个整数能够被其各个数位上的数字之和整除，则称之为<strong> 哈沙德数</strong>（Harshad number）。给你一个整数 <code>x</code> 。如果 <code>x</code> 是 <strong>哈沙德数 </strong>，则返回<em> </em><code>x</code> 各个数位上的数字之和，否则，返回<em> </em><code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 18</span></p>

<p><strong>输出：</strong> <span class="example-io">9</span></p>

<p><strong>解释：</strong></p>

<p><code>x</code> 各个数位上的数字之和为 <code>9</code> 。<code>18</code> 能被 <code>9</code> 整除。因此 <code>18</code> 是哈沙德数，答案是 <code>9</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 23</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong></p>

<p><code>x</code> 各个数位上的数字之和为 <code>5</code> 。<code>23</code> 不能被 <code>5</code> 整除。因此 <code>23</code> 不是哈沙德数，答案是 <code>-1</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 100</code></li>
</ul>


    
## 解题方法：计算

如何“计算一个正整数十进制下各位之和”？

> 当这个数不为零时，不断取出这个数的最后一位（$n \% 10$）。
>
> 取出最后一位后讲这个数除以$10$。
>
> 将所有取出的“最后一位”累加后，即为所求。

给定一个正整数$x$，首先计算$x$十进制下每一位之和$sum$。

> + 若$x\% sum==0$，则返回$sum$；
> + 否则，返回$-1$。

+ 时间复杂度$O(\log x)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    inline int getSum(int n) {
        int ans = 0;
        while (n) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = getSum(x);
        return x % sum == 0 ? sum : -1;
    }
};
```

#### Go

```go
package main

func getSum(n int) int {
	ans := 0
	for n > 0 {
		ans += n % 10
		n /= 10
	}
	return ans
}

func sumOfTheDigitsOfHarshadNumber(x int) int {
	sum := getSum(x)
	if x%sum == 0 {
		return sum
	}
	return -1
}
```

#### Java

```java
class Solution {
    private int getSum(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = getSum(x);
        return x % sum == 0 ? sum : -1;
    }
}
```

#### Python

```python
class Solution:
    def getSum(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        sum = self.getSum(x)
        return sum if x % sum == 0 else -1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/03/LeetCode%203099.%E5%93%88%E6%B2%99%E5%BE%B7%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140160763](https://letmefly.blog.csdn.net/article/details/140160763)
