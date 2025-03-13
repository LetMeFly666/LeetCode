---
title: 2739.总行驶距离
date: 2024-04-25 09:42:51
tags: [题解, LeetCode, 简单, 数学, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2739.总行驶距离：不模拟直接算（很好算的）——相当于“满5返1”的活动

力扣题目链接：[https://leetcode.cn/problems/total-distance-traveled/](https://leetcode.cn/problems/total-distance-traveled/)

<p>卡车有两个油箱。给你两个整数，<code>mainTank</code> 表示主油箱中的燃料（以升为单位），<code>additionalTank</code> 表示副油箱中的燃料（以升为单位）。</p>

<p>该卡车每耗费 <code>1</code> 升燃料都可以行驶 <code>10</code> km。每当主油箱使用了 <code>5</code> 升燃料时，如果副油箱至少有 <code>1</code> 升燃料，则会将 <code>1</code> 升燃料从副油箱转移到主油箱。</p>

<p>返回卡车可以行驶的最大距离。</p>

<p>注意：从副油箱向主油箱注入燃料不是连续行为。这一事件会在每消耗 <code>5</code> 升燃料时突然且立即发生。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>mainTank = 5, additionalTank = 10
<strong>输出：</strong>60
<strong>解释：</strong>
在用掉 5 升燃料后，主油箱中燃料还剩下 (5 - 5 + 1) = 1 升，行驶距离为 50km 。
在用掉剩下的 1 升燃料后，没有新的燃料注入到主油箱中，主油箱变为空。
总行驶距离为 60km 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>mainTank = 1, additionalTank = 2
<strong>输出：</strong>10
<strong>解释：</strong>
在用掉 1 升燃料后，主油箱变为空。
总行驶距离为 10km 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= mainTank, additionalTank &lt;= 100</code></li>
</ul>



## 解题方法：直接算

先不慌，找规律：

> 假设副油箱无限，则有：
>
> | 主油箱 | 加油次数 | 总耗油 | 说明                            |
> | :----: | :------: | :----: | :---------------------------- |
> |   4    |    0     |   4    | 4 < 5                          |
> |   5    |    1     |   6    | 5 - 5 + 1 = 1 < 5               |
> |   9    |    2     |   11   | 9 - 5 + 1 - 5 + 1 = 1 < 5       |
> |   13   |    3     |   16   | 13 - 5 + 1 - 5 + 1- 5 + 1 = 1 < 5 |

也就是说，相当于主油箱每耗油4L，都会从副油箱补充1L，一共耗油5L。

但是副油箱会先“欠”主油箱1L，相当于“满5返1”的活动，先花5元再返1元。因此手里除了数个4，还得有额外的1用作“预支付”的“启动资金”。

一共有$\lfloor\frac{主油箱 - 1}{4}\rfloor$个4，最多“参加活动”$\min(\lfloor\frac{主油箱 - 1}{4}\rfloor, 副油箱)$次，手里还剩$主油箱-参加活动次数\times 4$。

因此$参加活动次数\times 5 + 最终手中剩余$即为总计耗油量。乘以10即为总行驶距离。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

公式：

+ $times = \min(\lfloor\frac{主油箱-1}4\rfloor,副油箱)$
+ $总耗油 = times\times5+(主油箱-times\times4)$
+ $总里程 = 总耗油 \times 10$

#### C++

```cpp
class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int added = min(additionalTank, (mainTank - 1) / 4);
        return added * 50 + (mainTank - added * 4) * 10;
    }
};
```

#### Python

```python
class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        added = min(additionalTank, (mainTank - 1) // 4)
        return added * 50 + (mainTank - added * 4) * 10
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/25/LeetCode%202739.%E6%80%BB%E8%A1%8C%E9%A9%B6%E8%B7%9D%E7%A6%BB/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138181110](https://letmefly.blog.csdn.net/article/details/138181110)
