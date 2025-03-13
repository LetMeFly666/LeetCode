---
title: 2806.取整购买后的账户余额
date: 2024-06-12 11:11:09
tags: [题解, LeetCode, 简单, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】2806.取整购买后的账户余额：四舍五入

力扣题目链接：[https://leetcode.cn/problems/account-balance-after-rounded-purchase/](https://leetcode.cn/problems/account-balance-after-rounded-purchase/)

<p>一开始，你的银行账户里有&nbsp;<code>100</code>&nbsp;块钱。</p>

<p>给你一个整数<code>purchaseAmount</code>&nbsp;，它表示你在一次购买中愿意支出的金额。</p>

<p>在一个商店里，你进行一次购买，实际支出的金额会向 <strong>最近</strong>&nbsp;的&nbsp;<code>10</code>&nbsp;的 <strong>倍数</strong>&nbsp;取整。换句话说，你实际会支付一个&nbsp;<strong>非负</strong>&nbsp;金额&nbsp;<code>roundedAmount</code>&nbsp;，满足&nbsp;<code>roundedAmount</code>&nbsp;是&nbsp;<code>10</code>&nbsp;的倍数且&nbsp;<code>abs(roundedAmount - purchaseAmount)</code>&nbsp;的值 <strong>最小</strong>&nbsp;。</p>

<p>如果存在多于一个最接近的 <code>10</code>&nbsp;的倍数，<strong>较大的倍数</strong>&nbsp;是你的实际支出金额。</p>

<p>请你返回一个整数，表示你在愿意支出金额为<em>&nbsp;</em><code>purchaseAmount</code><em>&nbsp;</em>块钱的前提下，购买之后剩下的余额。</p>

<p><strong>注意：</strong> <code>0</code>&nbsp;也是&nbsp;<code>10</code>&nbsp;的倍数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>purchaseAmount = 9
<b>输出：</b>90
<b>解释：</b>这个例子中，最接近 9 的 10 的倍数是 10 。所以你的账户余额为 100 - 10 = 90 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>purchaseAmount = 15
<b>输出：</b>80
<b>解释：</b>这个例子中，有 2 个最接近 15 的 10 的倍数：10 和 20，较大的数 20 是你的实际开销。
所以你的账户余额为 100 - 20 = 80 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= purchaseAmount &lt;= 100</code></li>
</ul>


    
## 解题方法：四舍五入

1. 记下预算的个位数
2. 预算减去个位数变成10的倍数
3. 如果原本的个位数$gt 5$，则预算$+10$
4. 返回$100-预算$

### 时空复杂度分析

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rest = purchaseAmount % 10;
        purchaseAmount -= rest;
        if (rest >= 5) {
            purchaseAmount += 10;
        }
        return 100 - purchaseAmount;
    }
};
```

#### Python

```python
class Solution:
    def accountBalanceAfterPurchase(self, purchaseAmount: int) -> int:
        rest = purchaseAmount % 10
        purchaseAmount -= rest
        if rest >= 5:
            purchaseAmount += 10
        return 100 - purchaseAmount
```

#### Java

```java
class Solution {
    public int accountBalanceAfterPurchase(int purchaseAmount) {
        int rest = purchaseAmount % 10;
        purchaseAmount -= rest;
        if (rest >= 5) {
            purchaseAmount += 10;
        }
        return 100 - purchaseAmount;
    }
}
```

#### Golang

```go
func accountBalanceAfterPurchase(purchaseAmount int) int {
    rest := purchaseAmount % 10
    purchaseAmount -= rest
    if rest >= 5 {
        purchaseAmount += 10
    }
    return 100 - purchaseAmount
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/12/LeetCode%202806.%E5%8F%96%E6%95%B4%E8%B4%AD%E4%B9%B0%E5%90%8E%E7%9A%84%E8%B4%A6%E6%88%B7%E4%BD%99%E9%A2%9D/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139621619](https://letmefly.blog.csdn.net/article/details/139621619)
