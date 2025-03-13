---
title: 3259.超级饮料的最大强化能量
date: 2024-11-01 12:42:59
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP, 原地滚动]
categories: [题解, LeetCode]
---

# 【LetMeFly】3259.超级饮料的最大强化能量：动态规划（O(1)空间）

力扣题目链接：[https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/](https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/)

<p>来自未来的体育科学家给你两个整数数组 <code>energyDrinkA</code> 和 <code>energyDrinkB</code>，数组长度都等于 <code>n</code>。这两个数组分别代表 A、B 两种不同能量饮料每小时所能提供的强化能量。</p>

<p>你需要每小时饮用一种能量饮料来 <strong>最大化 </strong>你的总强化能量。然而，如果从一种能量饮料切换到另一种，你需要等待一小时来梳理身体的能量体系（在那个小时里你将不会获得任何强化能量）。</p>

<p>返回在接下来的 <code>n</code> 小时内你能获得的<strong> 最大 </strong>总强化能量。</p>

<p><strong>注意 </strong>你可以选择从饮用任意一种能量饮料开始。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>energyDrinkA<span class="example-io"> = [1,3,1], </span>energyDrinkB<span class="example-io"> = [3,1,1]</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>要想获得 5 点强化能量，需要选择只饮用能量饮料 A（或者只饮用 B）。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>energyDrinkA<span class="example-io"> = [4,1,1], </span>energyDrinkB<span class="example-io"> = [1,1,3]</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第一个小时饮用能量饮料 A。</li>
	<li>切换到能量饮料 B ，在第二个小时无法获得强化能量。</li>
	<li>第三个小时饮用能量饮料 B ，并获得强化能量。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == energyDrinkA.length == energyDrinkB.length</code></li>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= energyDrinkA[i], energyDrinkB[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：动态规划（原地滚动）

使用4个变量：

+ day0a代表**第0**天使用**A**能量饮料时的最大总能量
+ day0b代表**第0**天使用**B**能量饮料时的最大总能量
+ day1a代表**第1**天使用**A**能量饮料时的最大总能量
+ day1b代表**第1**天使用**B**能量饮料时的最大总能量

那么对于第“2”天：

+ 选择饮料A的话：可以第1天就是饮料A（day1a），也可以第1天不喝然后第0天是饮料B（day0b）。最终到这天为止的总能量为$\max(day1a, day0b) + energyB[i]$
+ 选择饮料B的话：同理，最大总能量为$\max(day0a, day1b) + energyB[i]$

变量过程中更新维护这4个变量，最终返回$\max(day1a, day1b)$即为答案。（因为$day1a$一定大于$day0a$，$day1b$一定大于$day0b$）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
public:
    ll maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        ll day0a = 0, day0b = 0, day1a = energyDrinkA[0], day1b = energyDrinkB[0];
        for (int i = 1; i < energyDrinkA.size(); i++) {
            ll day2a = max(day1a, day0b) + energyDrinkA[i];
            ll day2b = max(day0a, day1b) + energyDrinkB[i];
            day0a = day1a, day0b = day1b, day1a = day2a, day1b = day2b;
        }
        return max(day1a, day1b);
    }
};
```

时空复杂度超越百分比：AC,100.00%,94.62%。

#### Python

```python
from typing import List

class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        day0a, day0b, day1a, day1b = 0, 0, energyDrinkA[0], energyDrinkB[0]
        for i in range(1, len(energyDrinkA)):
            day0a, day0b, day1a, day1b = day1a, day1b, max(day1a, day0b) + energyDrinkA[i], max(day0a, day1b) + energyDrinkB[i]
        return max(day1a, day1b)
```

#### Java

```java
class Solution {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        long day0a = 0, day0b = 0, day1a = energyDrinkA[0], day1b = energyDrinkB[0];
        for (int i = 1; i < energyDrinkA.length; i++) {
            long day2a = Math.max(day1a, day0b) + energyDrinkA[i], day2b = Math.max(day0a, day1b) + energyDrinkB[i];
            day0a = day1a;
            day0b = day1b;
            day1a = day2a;
            day1b = day2b;
        }
        return Math.max(day1a, day1b);
    }
}
```

#### Go

```go
package main

func max(a int64, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func maxEnergyBoost(energyDrinkA []int, energyDrinkB []int) int64 {
    var day0a, day0b, day1a, day1b int64 = 0, 0, int64(energyDrinkA[0]), int64(energyDrinkB[0])
    for i := 1; i < len(energyDrinkA); i++ {
        day0a, day0b, day1a, day1b = day1a, day1b, max(day1a, day0b) + int64(energyDrinkA[i]), max(day0a, day1b) + int64(energyDrinkB[i])
    }
    return max(day1a, day1b)
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/01/LeetCode%203259.%E8%B6%85%E7%BA%A7%E9%A5%AE%E6%96%99%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BC%BA%E5%8C%96%E8%83%BD%E9%87%8F/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143429899](https://letmefly.blog.csdn.net/article/details/143429899)
