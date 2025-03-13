---
title: 2834.找出美丽数组的最小和
date: 2024-03-08 16:18:01
tags: [题解, LeetCode, 中等, 贪心, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】2834.找出美丽数组的最小和：数学（等差数列求和）——O(1)的做法

力扣题目链接：[https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/](https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/)

<p>给你两个正整数：<code>n</code> 和 <code>target</code> 。</p>

<p>如果数组 <code>nums</code> 满足下述条件，则称其为 <strong>美丽数组</strong> 。</p>

<ul>
	<li><code>nums.length == n</code>.</li>
	<li><code>nums</code> 由两两互不相同的正整数组成。</li>
	<li>在范围 <code>[0, n-1]</code> 内，<strong>不存在 </strong>两个 <strong>不同</strong> 下标 <code>i</code> 和 <code>j</code> ，使得 <code>nums[i] + nums[j] == target</code> 。</li>
</ul>

<p>返回符合条件的美丽数组所可能具备的 <strong>最小</strong> 和，并对结果进行取模 <code>10<sup>9</sup>&nbsp;+ 7</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2, target = 3
<strong>输出：</strong>4
<strong>解释：</strong>nums = [1,3] 是美丽数组。
- nums 的长度为 n = 2 。
- nums 由两两互不相同的正整数组成。
- 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
可以证明 4 是符合条件的美丽数组所可能具备的最小和。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, target = 3
<strong>输出：</strong>8
<strong>解释：</strong>
nums = [1,3,4] 是美丽数组。 
- nums 的长度为 n = 3 。 
- nums 由两两互不相同的正整数组成。 
- 不存在两个不同下标 i 和 j ，使得 nums[i] + nums[j] == 3 。
可以证明 8 是符合条件的美丽数组所可能具备的最小和。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1, target = 1
<strong>输出：</strong>1
<strong>解释：</strong>nums = [1] 是美丽数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：数学（等差数列求和）——O(1)的做法

$n$个不同的正整数，任意两数之和不为$target$，问这些数的最小和为多少。

怎么构造这个数组？当然是每个元素越小越好。那就从$0,1,2,\cdots$开始呗。

这样最多能到几？最多能到$\lfloor\frac{target}2\rfloor$。

<details><summary>原理（可跳过）</summary>

在$\le target$的数当中，存在$a$则不能存在$target-a$。

例如$target=5$时，$1$和$4$不能同时存在。选哪个？<span title="当然(是)">もちろん</span>选$4$。

</details>

如果这些数不够$n$个咋办？那就从$target$开始依次往上选就好了。$target, target + 1, target + 2, \cdots$，直到选够为止。

又有等差数列$a, a + 1, a + 2, \cdots, b$的和为$\frac{(a + b)\times(b - a + 1)}2$，因此可以在$O(1)$的时空复杂度内得出结果。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
const int MOD = 1e9 + 7;
class Solution {  // AC,14.77%,62.50%
private:
    inline long long cal(long long l, long long r) {
        return (l + r) * (r - l + 1) / 2;
    }
public:
    int minimumPossibleSum(int n, int target) {
        long long half = target / 2;
        if (n <= half) {
            return cal(1, n);
        }
        return (cal(1, half) + cal(target, target + n - half - 1)) % MOD;
    }
};
```

#### Python

```python
MOD = int(1e9) + 7
class Solution:
    def cal(self, l: int, r: int) -> int:
        return (l + r) * (r - l + 1) // 2

    def minimumPossibleSum(self, n: int, target: int) -> int:
        half = target >> 1
        if n <= half:
            return self.cal(1, n)
        return (self.cal(1, half) + self.cal(target, target + n - half - 1)) % MOD
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/08/LeetCode%202834.%E6%89%BE%E5%87%BA%E7%BE%8E%E4%B8%BD%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136565723](https://letmefly.blog.csdn.net/article/details/136565723)
