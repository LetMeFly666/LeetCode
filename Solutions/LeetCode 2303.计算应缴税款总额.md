---
title: 2303.计算应缴税款总额
date: 2023-01-23 10:06:42
tags: [题解, LeetCode, 简单, 数组, 模拟, 遍历]
---

# 【LetMeFly】2303.计算应缴税款总额

力扣题目链接：[https://leetcode.cn/problems/calculate-amount-paid-in-taxes/](https://leetcode.cn/problems/calculate-amount-paid-in-taxes/)

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>brackets</code> ，其中 <code>brackets[i] = [upper<sub>i</sub>, percent<sub>i</sub>]</code> ，表示第 <code>i</code> 个税级的上限是 <code>upper<sub>i</sub></code> ，征收的税率为 <code>percent<sub>i</sub></code> 。税级按上限 <strong>从低到高排序</strong>（在满足 <code>0 &lt; i &lt; brackets.length</code> 的前提下，<code>upper<sub>i-1</sub> &lt; upper<sub>i</sub></code>）。</p>

<p>税款计算方式如下：</p>

<ul>
	<li>不超过 <code>upper<sub>0</sub></code> 的收入按税率 <code>percent<sub>0</sub></code> 缴纳</li>
	<li>接着 <code>upper<sub>1</sub> - upper<sub>0</sub></code> 的部分按税率 <code>percent<sub>1</sub></code> 缴纳</li>
	<li>然后 <code>upper<sub>2</sub> - upper<sub>1</sub></code> 的部分按税率 <code>percent<sub>2</sub></code> 缴纳</li>
	<li>以此类推</li>
</ul>

<p>给你一个整数 <code>income</code> 表示你的总收入。返回你需要缴纳的税款总额。与标准答案误差不超 <code>10<sup>-5</sup></code> 的结果将被视作正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>brackets = [[3,50],[7,10],[12,25]], income = 10
<strong>输出：</strong>2.65000
<strong>解释：</strong>
前 $3 的税率为 50% 。需要支付税款 $3 * 50% = $1.50 。
接下来 $7 - $3 = $4 的税率为 10% 。需要支付税款 $4 * 10% = $0.40 。
最后 $10 - $7 = $3 的税率为 25% 。需要支付税款 $3 * 25% = $0.75 。
需要支付的税款总计 $1.50 + $0.40 + $0.75 = $2.65 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>brackets = [[1,0],[4,25],[5,50]], income = 2
<strong>输出：</strong>0.25000
<strong>解释：</strong>
前 $1 的税率为 0% 。需要支付税款 $1 * 0% = $0 。
剩下 $1 的税率为 25% 。需要支付税款 $1 * 25% = $0.25 。
需要支付的税款总计 $0 + $0.25 = $0.25 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>brackets = [[2,50]], income = 0
<strong>输出：</strong>0.00000
<strong>解释：</strong>
没有收入，无需纳税，需要支付的税款总计 $0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= brackets.length &lt;= 100</code></li>
	<li><code>1 &lt;= upper<sub>i</sub> &lt;= 1000</code></li>
	<li><code>0 &lt;= percent<sub>i</sub> &lt;= 100</code></li>
	<li><code>0 &lt;= income &lt;= 1000</code></li>
	<li><code>upper<sub>i</sub></code> 按递增顺序排列</li>
	<li><code>upper<sub>i</sub></code> 中的所有值 <strong>互不相同</strong></li>
	<li>最后一个税级的上限大于等于 <code>income</code></li>
</ul>


    
## 方法一：遍历模拟

使用一个变量```lastUpper```来记录上次的交税上限

接着遍历税收数组，这次应计算入交税的收入有```min(income, 这次税收上限) - lastUpper```

把这次应交税的收入乘以税率并累加到答案中，接着更新lastUpper为这次的税收上限。

遍历的结束条件为：(遍历结束或)某次的税收上限大于收入income

+ 时间复杂度$O(len(brackets))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int ans = 0;
        int lastUpper = 0;
        for (auto& v : brackets) {
            ans +=  (min(income, v[0]) - lastUpper) * v[1];
            lastUpper = v[0];
            if (v[0] >= income)
                break;
        }
        return (double)ans / 100;
    }
};
```

#### Python

```python
class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        ans = 0
        lastUpper = 0
        for v in brackets:
            ans += (min(v[0], income) - lastUpper) * v[1] / 100
            lastUpper = v[0]
            if v[0] >= income:
                break
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/23/LeetCode%202303.%E8%AE%A1%E7%AE%97%E5%BA%94%E7%BC%B4%E7%A8%8E%E6%AC%BE%E6%80%BB%E9%A2%9D/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128751683](https://letmefly.blog.csdn.net/article/details/128751683)
