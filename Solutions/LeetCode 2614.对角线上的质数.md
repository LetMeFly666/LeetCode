---
title: 2614.对角线上的质数：遍历(质数判断)
date: 2025-03-18 23:59:42
tags: [题解, LeetCode, 简单, 数组, 数学, 矩阵, 数论, 质数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2614.对角线上的质数：遍历(质数判断)

力扣题目链接：[https://leetcode.cn/problems/prime-in-diagonal/](https://leetcode.cn/problems/prime-in-diagonal/)

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>nums</code> 。</p>

<p>返回位于 <code>nums</code> 至少一条 <strong>对角线</strong> 上的最大 <strong>质数</strong> 。如果任一对角线上均不存在质数，返回<em> 0 。</em></p>

<p>注意：</p>

<ul>
	<li>如果某个整数大于 <code>1</code> ，且不存在除 <code>1</code> 和自身之外的正整数因子，则认为该整数是一个质数。</li>
	<li>如果存在整数 <code>i</code> ，使得&nbsp;<code>nums[i][i] = val</code> 或者&nbsp;<code>nums[i][nums.length - i - 1]= val</code> ，则认为整数 <code>val</code> 位于 <code>nums</code> 的一条对角线上。</li>
</ul>

<p><img alt="" src="https://assets.leetcode.com/uploads/2023/03/06/screenshot-2023-03-06-at-45648-pm.png" style="width: 181px; height: 121px;" /></p>

<p>在上图中，一条对角线是 <strong>[1,5,9]</strong> ，而另一条对角线是<strong> [3,5,7]</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,2,3],[5,6,7],[9,10,11]]
<strong>输出：</strong>11
<strong>解释：</strong>数字 1、3、6、9 和 11 是所有 "位于至少一条对角线上" 的数字。由于 11 是最大的质数，故返回 11 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,2,3],[5,17,7],[9,11,10]]
<strong>输出：</strong>17
<strong>解释：</strong>数字 1、3、9、10 和 17 是所有满足"位于至少一条对角线上"的数字。由于 17 是最大的质数，故返回 17 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 300</code></li>
	<li><code>nums.length == nums<sub>i</sub>.length</code></li>
	<li><code>1 &lt;= nums<span style="">[i][j]</span>&nbsp;&lt;= 4*10<sup>6</sup></code></li>
</ul>


    
## 解题方法：质数判断

如何判断一个数是否为质数？

> 首先如果这个数小于2那么一定不是质数
>
> 用$i$从2到$sqrt(n)$枚举，若$i$能整除$n$，则$n$不是质数
>
> 否则$n$是质数

如何遍历对角线？题目中说了 <code>nums.length == nums<sub>i</sub>.length</code> ，也就是说矩阵是正方形。

> 所以我们可以用$i$从$0$枚举到$n - 1$，那么$nums[i][i]$和$nums[i][len(nums) - i - 1]$即为对角线和副对角线上的元素。

+ 时间复杂度$O(len(nums)\sqrt{\max(nums[i][j]))}$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 23:40:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 23:43:36
 */
class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i][i])) {
                ans = max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][nums.size() - i - 1])) {
                ans = max(ans, nums[i][nums.size() - i - 1]);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-18 23:46:52
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-18 23:48:14
'''
from typing import List
from math import sqrt

class Solution:
    def isPrime(self, n: int) -> bool:
        if n < 2:
            return False
        for i in range(2, int(sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True
    
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        ans = 0
        for i in range(len(nums)):
            if self.isPrime(nums[i][i]):
                ans = max(ans, nums[i][i])
            if self.isPrime(nums[i][len(nums) - i - 1]):
                ans = max(ans, nums[i][len(nums) - i - 1])
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 23:50:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 23:55:24
 */
class Solution {
    private boolean isPrime(int n) {
        if (n < 2) {
            return false;
        }
        int k = (int)Math.sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int diagonalPrime(int[][] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (isPrime(nums[i][i])) {
                ans = Math.max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][nums.length - i - 1])) {
                ans = Math.max(ans, nums[i][nums.length - i - 1]);
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-18 23:55:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-18 23:58:46
 */
package main

func isPrime2614(n int) (ans bool) {
    if n < 2 {
        return
    }
    for i := 2; i * i <= n; i++ {
        if n % i == 0 {
            return
        }
    }
    return true
}

func diagonalPrime(nums [][]int) (ans int) {
    for i := range nums {
        if isPrime2614(nums[i][i]) {
            ans = max(ans, nums[i][i])
        }
        if isPrime2614(nums[i][len(nums) - i - 1]) {
            ans = max(ans, nums[i][len(nums) - i - 1])
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146356303)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/18/LeetCode%202614.%E5%AF%B9%E8%A7%92%E7%BA%BF%E4%B8%8A%E7%9A%84%E8%B4%A8%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
