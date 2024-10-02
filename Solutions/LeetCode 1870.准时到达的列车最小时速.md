---
title: 1870.准时到达的列车最小时速
date: 2024-10-02 13:18:03
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分]
---

# 【LetMeFly】1870.准时到达的列车最小时速：二分查找（避免浮点误差）

力扣题目链接：[https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/](https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/)

<p>给你一个浮点数 <code>hour</code> ，表示你到达办公室可用的总通勤时间。要到达办公室，你必须按给定次序乘坐 <code>n</code> 趟列车。另给你一个长度为 <code>n</code> 的整数数组 <code>dist</code> ，其中 <code>dist[i]</code> 表示第 <code>i</code> 趟列车的行驶距离（单位是千米）。</p>

<p>每趟列车均只能在整点发车，所以你可能需要在两趟列车之间等待一段时间。</p>

<ul>
	<li>例如，第 <code>1</code> 趟列车需要 <code>1.5</code> 小时，那你必须再等待 <code>0.5</code> 小时，搭乘在第 2 小时发车的第 <code>2</code> 趟列车。</li>
</ul>

<p>返回能满足你准时到达办公室所要求全部列车的<strong> 最小正整数 </strong>时速（单位：千米每小时），如果无法准时到达，则返回 <code>-1</code> 。</p>

<p>生成的测试用例保证答案不超过 <code>10<sup>7</sup></code> ，且 <code>hour</code> 的 <strong>小数点后最多存在两位数字</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,2], hour = 6
<strong>输出：</strong>1
<strong>解释：</strong>速度为 1 时：
- 第 1 趟列车运行需要 1/1 = 1 小时。
- 由于是在整数时间到达，可以立即换乘在第 1 小时发车的列车。第 2 趟列车运行需要 3/1 = 3 小时。
- 由于是在整数时间到达，可以立即换乘在第 4 小时发车的列车。第 3 趟列车运行需要 2/1 = 2 小时。
- 你将会恰好在第 6 小时到达。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,2], hour = 2.7
<strong>输出：</strong>3
<strong>解释：</strong>速度为 3 时：
- 第 1 趟列车运行需要 1/3 = 0.33333 小时。
- 由于不是在整数时间到达，故需要等待至第 1 小时才能搭乘列车。第 2 趟列车运行需要 3/3 = 1 小时。
- 由于是在整数时间到达，可以立即换乘在第 2 小时发车的列车。第 3 趟列车运行需要 2/3 = 0.66667 小时。
- 你将会在第 2.66667 小时到达。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>dist = [1,3,2], hour = 1.9
<strong>输出：</strong>-1
<strong>解释：</strong>不可能准时到达，因为第 3 趟列车最早是在第 2 小时发车。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == dist.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>1 <= dist[i] <= 10<sup>5</sup></code></li>
	<li><code>1 <= hour <= 10<sup>9</sup></code></li>
	<li><code>hours</code> 中，小数点后最多存在两位数字</li>
</ul>


    
## 解题方法：二分查找

速度越快耗时越短，因此直接二分查找确定最小速度即可。速度下限为`1`，速度上限为`10^7`（这是因为每一段路程最多`10^5`，速度再大，前面每段路程的耗时也至少得为`1`；由于时间精度是`0.01`，所以速度再快只会让最后一段路程耗时为一个更小的分数`0.001`无意义）

如何避免精度误差？当然是把一切结果都转为整数运算。首先对于给定时间，直接乘以`100`并转为整数（例如C++的`llround`和python的`round`）。前面每段路程计算时间时，本来就是整数；最后一段路程计算时间时，将除法转换为乘法：

$前面时间\times 100+\frac{最后一段路程\times 100}{速度}\leq round(hour\times 100)\iff (round(hour\times 100)-前面时间\times 100)\times 速度\geq 最后一段路程\times 100$

+ 时间复杂度$O(n\log C)$，其中$C=10^7$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;
class Solution {
private:
    bool ok(vector<int>& dist, ll hour, int speed) {
        ll t = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            t += (dist[i] + speed - 1) / speed;
        }
        return (hour - t * 100) * speed >= dist.back() * 100;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        ll hour100 = llround(hour * 100);
        int l = 1, r = 1e7 + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (ok(dist, hour100, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l == 1e7 + 1 ? -1 : l;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def ok(self, speed) -> bool:
        t = 0
        for i in range(len(self.dist) - 1):
            t += (self.dist[i] + speed - 1) // speed
        return (self.hour - t * 100) * speed >= self.dist[-1] * 100
    
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        self.dist = dist
        self.hour = round(hour * 100)
        l, r = 1, int(1e7) + 1
        while l < r:
            mid = (l + r) >> 1
            if self.ok(mid):
                r = mid
            else:
                l = mid + 1
        return -1 if l == int(1e7) + 1 else l

```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/02/LeetCode%201870.%E5%87%86%E6%97%B6%E5%88%B0%E8%BE%BE%E7%9A%84%E5%88%97%E8%BD%A6%E6%9C%80%E5%B0%8F%E6%97%B6%E9%80%9F/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142680612](https://letmefly.blog.csdn.net/article/details/142680612)
