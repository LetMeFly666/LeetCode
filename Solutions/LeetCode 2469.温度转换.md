---
title: 2469.温度转换
date: 2023-03-21 12:26:34
tags: [题解, LeetCode, 简单, 数学, 模拟]
---

# 【LetMeFly】2469.温度转换

力扣题目链接：[https://leetcode.cn/problems/convert-the-temperature/](https://leetcode.cn/problems/convert-the-temperature/)

<p>给你一个四舍五入到两位小数的非负浮点数 <code>celsius</code> 来表示温度，以 <strong>摄氏度</strong>（<strong>Celsius</strong>）为单位。</p>

<p>你需要将摄氏度转换为 <strong>开氏度</strong>（<strong>Kelvin</strong>）和 <strong>华氏度</strong>（<strong>Fahrenheit</strong>），并以数组 <code>ans = [kelvin, fahrenheit]</code> 的形式返回结果。</p>

<p>返回数组<em> <code>ans</code></em> 。与实际答案误差不超过 <code>10<sup>-5</sup></code> 的会视为正确答案<strong>。</strong></p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>开氏度 = 摄氏度 + 273.15</code></li>
	<li><code>华氏度 = 摄氏度 * 1.80 + 32.00</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre><strong>输入：</strong>celsius = 36.50
<strong>输出：</strong>[309.65000,97.70000]
<strong>解释：</strong>36.50 摄氏度：转换为开氏度是 309.65 ，转换为华氏度是 97.70 。</pre>

<p><strong>示例 2 ：</strong></p>

<pre><strong>输入：</strong>celsius = 122.11
<strong>输出：</strong>[395.26000,251.79800]
<strong>解释：</strong>122.11 摄氏度：转换为开氏度是 395.26 ，转换为华氏度是 251.798 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= celsius &lt;= 1000</code></li>
</ul>


    
## 方法一：模拟

这道题直接按照题意进行模拟即可。

题目中已经给定了摄氏度与另外两种温度的转化公式：

+ $开氏度 = 摄氏度 + 273.15$
+ $华氏度 = 摄氏度 * 1.80 + 32.00$

因此，不论是C++还是Python，我们都直接返回计算结果即可。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.8 + 32};
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.8 + 32]
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/03/21/LeetCode%202469.%E6%B8%A9%E5%BA%A6%E8%BD%AC%E6%8D%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129685884](https://letmefly.blog.csdn.net/article/details/129685884)
