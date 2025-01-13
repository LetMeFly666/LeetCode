---
title: 3270.求出数字答案
date: 2025-01-13 23:53:51
tags: [题解, LeetCode, 简单, 数学]
---

# 【LetMeFly】3270.求出数字答案：每位分别计算 或 for循环

力扣题目链接：[https://leetcode.cn/problems/find-the-key-of-the-numbers/](https://leetcode.cn/problems/find-the-key-of-the-numbers/)

<p>给你三个 <strong>正</strong>&nbsp;整数&nbsp;<code>num1</code>&nbsp;，<code>num2</code>&nbsp;和&nbsp;<code>num3</code>&nbsp;。</p>

<p>数字 <code>num1</code>&nbsp;，<code>num2</code>&nbsp;和 <code>num3</code>&nbsp;的数字答案 <code>key</code>&nbsp;是一个四位数，定义如下：</p>

<ul>
	<li>一开始，如果有数字 <strong>少于</strong>&nbsp;四位数，给它补 <strong>前导 0 </strong>。</li>
	<li>答案 <code>key</code>&nbsp;的第&nbsp;<code>i</code>&nbsp;个数位（<code>1 &lt;= i &lt;= 4</code>）为&nbsp;<code>num1</code>&nbsp;，<code>num2</code>&nbsp;和&nbsp;<code>num3</code>&nbsp;第&nbsp;<code>i</code>&nbsp;个数位中的&nbsp;<strong>最小</strong>&nbsp;值。</li>
</ul>

<p>请你返回三个数字 <strong>没有</strong>&nbsp;前导 0 的数字答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>num1 = 1, num2 = 10, num3 = 1000</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><b>解释：</b></p>

<p>补前导 0 后，<code>num1</code>&nbsp;变为&nbsp;<code>"0001"</code>&nbsp;，<code>num2</code> 变为&nbsp;<code>"0010"</code>&nbsp;，<code>num3</code>&nbsp;保持不变，为&nbsp;<code>"1000"</code>&nbsp;。</p>

<ul>
	<li>数字答案 <code>key</code>&nbsp;的第&nbsp;<code>1</code>&nbsp;个数位为&nbsp;<code>min(0, 0, 1)</code>&nbsp;。</li>
	<li>数字答案 <code>key</code>&nbsp;的第&nbsp;<code>2</code>&nbsp;个数位为&nbsp;<code>min(0, 0, 0)</code>&nbsp;。</li>
	<li>数字答案 <code>key</code>&nbsp;的第 <code>3</code> 个数位为&nbsp;<code>min(0, 1, 0)</code>&nbsp;。</li>
	<li>数字答案 <code>key</code>&nbsp;的第 <code>4</code> 个数位为&nbsp;<code>min(1, 0, 0)</code>&nbsp;。</li>
</ul>

<p>所以数字答案为&nbsp;<code>"0000"</code>&nbsp;，也就是 0 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">num1 = 987, num2 = 879, num3 = 798</span></p>

<p><span class="example-io"><b>输出：</b>777</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>num1 = 1, num2 = 2, num3 = 3</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1, num2, num3 &lt;= 9999</code></li>
</ul>


    
## 解题方法一：每一位分别计算

如何取出`a`的百分位？`a / 100 % 10`即可。

依次取出三个数十进制下的低4位即可。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int min3(int a, int b, int c) {
        return min(min(a, b), c);
    }
public:
    int generateKey(int num1, int num2, int num3) {
        return 1000 * min3(num1 / 1000, num2 / 1000, num3 / 1000) + 
               100 * min3(num1 / 100 % 10, num2 / 100 % 10, num3 / 100 % 10) + 
               10 * min3(num1 / 10 % 10, num2 / 10 % 10, num3 / 10 % 10) +
               min3(num1 % 10, num2 % 10, num3 % 10);
    }
};
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 23:45:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 23:48:54
 */
class Solution {
    private int get(int num1, int num2, int num3, int dev) {
        return Math.min(num1 / dev % 10, Math.min(num2 / dev % 10, num3 / dev % 10));
    }

    public int generateKey(int num1, int num2, int num3) {
        return get(num1, num2, num3, 1000) * 1000 +
               get(num1, num2, num3, 100) * 100 + 
               get(num1, num2, num3, 10) * 10 + 
               get(num1, num2, num3, 1); 
    }
}
```

## 解题方法二：for循环

在三个数字都不为零时，依次取出三个数的最后一位，将最小值乘以这一位对应的“weight”并累加。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-11 22:29:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-11 22:31:40
'''
class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        ans = 0
        p = 1
        while num1 and num2 and num3:
            ans += p * min(num1 % 10, num2 % 10, num3 % 10)
            num1 //= 10
            num2 //= 10
            num3 //= 10
            p *= 10
        return ans
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 23:49:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 23:52:27
 */
package main


func min_FKN(a, b, c int) int {
    if a > b {
        a = b
    }
    if a > c {
        a = c
    }
    return a
}

func generateKey(num1 int, num2 int, num3 int) (ans int) {
    p := 1
    for num1 + num2 + num3 > 0 {
        ans += min_FKN(num1 % 10, num2 % 10, num3 % 10) * p
        p *= 10
        num1, num2, num3 = num1 / 10, num2 / 10, num3 / 10
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/13/LeetCode%203270.%E6%B1%82%E5%87%BA%E6%95%B0%E5%AD%97%E7%AD%94%E6%A1%88/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145126790](https://letmefly.blog.csdn.net/article/details/145126790)
