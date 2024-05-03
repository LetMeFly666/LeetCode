---
title: 1491.去掉最低工资和最高工资后的工资平均值
date: 2024-05-03 14:36:24
tags: [题解, LeetCode, 简单, 数组, 排序]
---

# 【LetMeFly】1491.去掉最低工资和最高工资后的工资平均值：模拟（一次遍历）

力扣题目链接：[https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/](https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

<p>给你一个整数数组&nbsp;<code>salary</code>&nbsp;，数组里每个数都是 <strong>唯一</strong>&nbsp;的，其中&nbsp;<code>salary[i]</code> 是第&nbsp;<code>i</code>&nbsp;个员工的工资。</p>

<p>请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>salary = [4000,3000,1000,2000]
<strong>输出：</strong>2500.00000
<strong>解释：</strong>最低工资和最高工资分别是 1000 和 4000 。
去掉最低工资和最高工资以后的平均工资是 (2000+3000)/2= 2500
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>salary = [1000,2000,3000]
<strong>输出：</strong>2000.00000
<strong>解释：</strong>最低工资和最高工资分别是 1000 和 3000 。
去掉最低工资和最高工资以后的平均工资是 (2000)/1= 2000
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>salary = [6000,5000,4000,3000,2000,1000]
<strong>输出：</strong>3500.00000
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>salary = [8000,9000,2000,3000,6000,1000]
<strong>输出：</strong>4750.00000
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= salary.length &lt;= 100</code></li>
	<li><code>10^3&nbsp;&lt;= salary[i] &lt;= 10^6</code></li>
	<li><code>salary[i]</code>&nbsp;是唯一的。</li>
	<li>与真实值误差在&nbsp;<code>10^-5</code> 以内的结果都将视为正确答案。</li>
</ul>


    
## 解题方法：一次遍历——使用数个变量记录

遍历给定数组，在遍历的过程中，使用三个变量分别记录数组中元素的最小值、最大值、总和。

遍历结束后，$\frac{总和-最小值-最大值}{数组长度-2}$即为答案。

+ 时间复杂度$O(len(salary))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    double average(vector<int>& salary) {
        int m = salary[0], M = m, s = 0;
        for (int t : salary) {
            m = min(m, t);
            M = max(M, t);
            s += t;
        }
        return (double)(s - m - M) / (salary.size() - 2);
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def average(self, salary: List[int]) -> float:
        return (sum(salary) - min(salary) - max(salary)) / (len(salary) - 2)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/03/LeetCode%201491.%E5%8E%BB%E6%8E%89%E6%9C%80%E4%BD%8E%E5%B7%A5%E8%B5%84%E5%92%8C%E6%9C%80%E9%AB%98%E5%B7%A5%E8%B5%84%E5%90%8E%E7%9A%84%E5%B7%A5%E8%B5%84%E5%B9%B3%E5%9D%87%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138416153](https://letmefly.blog.csdn.net/article/details/138416153)
