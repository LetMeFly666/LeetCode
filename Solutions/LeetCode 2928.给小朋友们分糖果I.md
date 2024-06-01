---
title: 2928.给小朋友们分糖果 I
date: 2024-06-01 11:52:03
tags: [题解, LeetCode, 简单, 数学, 组合数学, 枚举, 模拟, 暴力]
---

# 【LetMeFly】2928.给小朋友们分糖果 I：Java提交的运行时间超过了61%的用户

力扣题目链接：[https://leetcode.cn/problems/distribute-candies-among-children-i/](https://leetcode.cn/problems/distribute-candies-among-children-i/)

<p>给你两个正整数&nbsp;<code>n</code> 和&nbsp;<code>limit</code>&nbsp;。</p>

<p>请你将 <code>n</code>&nbsp;颗糖果分给 <code>3</code>&nbsp;位小朋友，确保没有任何小朋友得到超过 <code>limit</code>&nbsp;颗糖果，请你返回满足此条件下的&nbsp;<strong>总方案数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 5, limit = 2
<b>输出：</b>3
<b>解释：</b>总共有 3 种方法分配 5 颗糖果，且每位小朋友的糖果数不超过 2 ：(1, 2, 2) ，(2, 1, 2) 和 (2, 2, 1) 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 3, limit = 3
<b>输出：</b>10
<b>解释：</b>总共有 10 种方法分配 3 颗糖果，且每位小朋友的糖果数不超过 3 ：(0, 0, 3) ，(0, 1, 2) ，(0, 2, 1) ，(0, 3, 0) ，(1, 0, 2) ，(1, 1, 1) ，(1, 2, 0) ，(2, 0, 1) ，(2, 1, 0) 和 (3, 0, 0) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= limit &lt;= 50</code></li>
</ul>


    
## 解题方法：模拟

用$x$从$0$到$\min(limit, n)$模拟第一个小朋友，用$y$从$0$到$\min(limit, n-x)$模拟第二个小朋友，则第三个小朋友能分到$n-x-y$个。如果$n-x-y\leq limit$，则视为一种可行方案。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int x = 0; x <= n && x <= limit; x++) {
            for (int y = 0; y <= n - x && y <= limit; y++) {
                if (n - x - y <= limit) {
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

func distributeCandies(n int, limit int) int {
    ans := 0
    for x := 0; x <= n && x <= limit; x++ {
        for y := 0; y <= n - x && y <= limit; y++ {
            if n - x - y <= limit {
                ans++
            }
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int x = 0; x <= n && x <= limit; x++) {
            for (int y = 0; y <= n - x && y <= limit; y++) {
                if (n - x - y <= limit) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

+ 执行用时分布```1 ms```，击败**61**.78%使用```Java```的用户；
+ 消耗内存分布```40.03 MB```，击败```5.10%```使用```Java```的用户。

#### Python

```python
class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        ans = 0
        for x in range(min(limit, n) + 1):
            for y in range(min(n - x, limit) + 1):
                if n - x - y <= limit:
                    ans += 1
        return ans
```

![61快乐](https://cdn.letmefly.xyz/img/img/happy61_2024.jpg)

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/01/LeetCode%202928.%E7%BB%99%E5%B0%8F%E6%9C%8B%E5%8F%8B%E4%BB%AC%E5%88%86%E7%B3%96%E6%9E%9CI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139380754](https://letmefly.blog.csdn.net/article/details/139380754)
