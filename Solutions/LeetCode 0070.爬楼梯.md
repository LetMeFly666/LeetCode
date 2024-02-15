---
title: 70.爬楼梯
date: 2023-12-10 20:22:44
tags: [题解, LeetCode, 简单, 记忆化搜索, 数学, 动态规划, DP]
---

# 【LetMeFly】70.爬楼梯：动态规划（递推）

力扣题目链接：[https://leetcode.cn/problems/climbing-stairs/](https://leetcode.cn/problems/climbing-stairs/)

<p>假设你正在爬楼梯。需要 <code>n</code>&nbsp;阶你才能到达楼顶。</p>

<p>每次你可以爬 <code>1</code> 或 <code>2</code> 个台阶。你有多少种不同的方法可以爬到楼顶呢？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>3
<strong>解释：</strong>有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
</ul>


    
## 方法一：动态规划（递推）

第$i$阶楼梯可以由第$i-1$阶或$i-2$阶楼梯而来，因此只需要将相邻两阶的方案数加起来，就能得到下一阶的方案数。

初始值$0$阶楼梯的方案数为$1$，$1$阶楼梯的方案数为$1$。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int _0 = 1, _1 = 1;
        for (int i = 2; i <= n; i++) {
            int _2 = _0 + _1;
            _0 = _1, _1 = _2;
        }
        return _1;
    }
};
```

#### Python

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        _0, _1 = 1, 1
        for i in range(n - 1):
            _0, _1 = _1, _0 + _1
        return _1
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/12/10/LeetCode%200070.%E7%88%AC%E6%A5%BC%E6%A2%AF/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134913892](https://letmefly.blog.csdn.net/article/details/134913892)
