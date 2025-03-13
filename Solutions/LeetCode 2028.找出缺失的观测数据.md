---
title: 2028.找出缺失的观测数据
date: 2024-05-27 21:57:59
tags: [题解, LeetCode, 中等, 数组, 数学, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2028.找出缺失的观测数据：a个骰子和为b？

力扣题目链接：[https://leetcode.cn/problems/find-missing-observations/](https://leetcode.cn/problems/find-missing-observations/)

<p>现有一份 <code>n + m</code>&nbsp;次投掷单个<strong> 六面</strong> 骰子的观测数据，骰子的每个面从 <code>1</code> 到 <code>6</code> 编号。观测数据中缺失了 <code>n</code> 份，你手上只拿到剩余&nbsp;<code>m</code> 次投掷的数据。幸好你有之前计算过的这 <code>n + m</code> 次投掷数据的 <strong>平均值</strong> 。</p>

<p>给你一个长度为 <code>m</code> 的整数数组 <code>rolls</code> ，其中&nbsp;<code>rolls[i]</code> 是第 <code>i</code> 次观测的值。同时给你两个整数 <code>mean</code> 和 <code>n</code> 。</p>

<p>返回一个长度为<em> </em><code>n</code><em> </em>的数组，包含所有缺失的观测数据，且满足这<em> </em><code>n + m</code><em> </em>次投掷的 <strong>平均值</strong> 是<em> </em><code>mean</code> 。如果存在多组符合要求的答案，只需要返回其中任意一组即可。如果不存在答案，返回一个空数组。</p>

<p><code>k</code>&nbsp;个数字的 <strong>平均值</strong> 为这些数字求和后再除以&nbsp;<code>k</code> 。</p>

<p>注意 <code>mean</code> 是一个整数，所以 <code>n + m</code> 次投掷的总和需要被&nbsp;<code>n + m</code>&nbsp;整除。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rolls = [3,2,4,3], mean = 4, n = 2
<strong>输出：</strong>[6,6]
<strong>解释：</strong>所有 n + m 次投掷的平均值是 (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rolls = [1,5,6], mean = 3, n = 4
<strong>输出：</strong>[2,3,2,2]
<strong>解释：</strong>所有 n + m 次投掷的平均值是 (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rolls = [1,2,3,4], mean = 6, n = 4
<strong>输出：</strong>[]
<strong>解释：</strong>无论丢失的 4 次数据是什么，平均值都不可能是 6 。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>rolls = [1], mean = 3, n = 1
<strong>输出：</strong>[5]
<strong>解释：</strong>所有 n + m 次投掷的平均值是 (1 + 5) / 2 = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == rolls.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= rolls[i], mean &lt;= 6</code></li>
</ul>


    
## 解题方法：a个骰子和为b？

令$b = mean \times 总数量 - \sum 已有点数$，令$a=n$，那么问题就转化为了“a个骰子和为b？”。

+ 如果$b\lt a$或$b \gt a \times 6$，则不能；
+ 否则，先令所有骰子都为$\lfloor\frac{b}{a}\rfloor$，再将其中$b\% a$个骰子加一。

以上。

+ 时间复杂度$O(n+m)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int target = mean * (rolls.size() + n);
        for (int t : rolls) {
            target -= t;
        }
        if (target < n || target > n * 6) {
            return {};
        }
        vector<int> ans(n, target / n);
        for (int i = target % n; i > 0; i--) {
            ans[i]++;
        }
        return ans;
    }
};
```

#### Go

```go
// package main

func missingRolls(rolls []int, mean int, n int) []int {
    target := mean * (len(rolls) + n)
    for i := 0; i < len(rolls); i++ {
        target -= rolls[i];
    }
    if target < n || target > n * 6 {
        return make([]int, 0)
    }
    ans := make([]int, n)
    mean2, remain := target / n, target % n
    for i := 0; i < n; i++ {
        ans[i] = mean2
        if i < remain {
            ans[i]++
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int target = mean * (n + rolls.length);
        for (int i = 0; i < rolls.length; i++) {
            target -= rolls[i];
        }
        if (target < n || target > n * 6) {
            return new int[0];
        }
        int[] ans = new int[n];
        int mean2 = target / n, more = target % n;
        for (int i = 0; i < n; i++) {
            ans[i] = mean2 + (i < more ? 1 : 0);
        }
        return ans;
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        target = mean * (len(rolls) + n) - sum(rolls)
        if target < n or target > n * 6:
            return []
        ans = [target // n] * n
        for i in range(target % n):
            ans[i] += 1
        return ans

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/27/LeetCode%202028.%E6%89%BE%E5%87%BA%E7%BC%BA%E5%A4%B1%E7%9A%84%E8%A7%82%E6%B5%8B%E6%95%B0%E6%8D%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139249243](https://letmefly.blog.csdn.net/article/details/139249243)
