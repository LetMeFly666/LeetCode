---
title: 2769.找出最大的可达成数字
date: 2024-05-21 20:36:44
tags: [题解, LeetCode, 简单, 数学]
---

# 【LetMeFly】2769.找出最大的可达成数字：数学——一个猪脑可以不过载的题

力扣题目链接：[https://leetcode.cn/problems/find-the-maximum-achievable-number/](https://leetcode.cn/problems/find-the-maximum-achievable-number/)

<p>给你两个整数 <code>num</code> 和 <code>t</code> 。</p>

<p>如果整数 <code>x</code> 可以在执行下述操作不超过 <code>t</code> 次的情况下变为与 <code>num</code> 相等，则称其为 <strong>可达成数字</strong> ：</p>

<ul>
	<li>每次操作将 <code>x</code> 的值增加或减少 <code>1</code> ，同时可以选择将 <code>num</code> 的值增加或减少 <code>1</code> 。</li>
</ul>

<p>返回所有可达成数字中的最大值。可以证明至少存在一个可达成数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 4, t = 1
<strong>输出：</strong>6
<strong>解释：</strong>最大可达成数字是 x = 6 ，执行下述操作可以使其等于 num ：
- x 减少 1 ，同时 num 增加 1 。此时，x = 5 且 num = 5 。 
可以证明不存在大于 6 的可达成数字。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 3, t = 2
<strong>输出：</strong>7
<strong>解释：</strong>最大的可达成数字是 x = 7 ，执行下述操作可以使其等于 num ：
- x 减少 1 ，同时 num 增加 1 。此时，x = 6 且 num = 4 。 
- x 减少 1 ，同时 num 增加 1 。此时，x = 5 且 num = 5 。 
可以证明不存在大于 7 的可达成数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num, t&nbsp;&lt;= 50</code></li>
</ul>


    
## 解题方法：数学

记目标为$target$，$target$想要尽可能地大，但经过最多$t$次“操作”后还要和$num$相等。

那当然是每次操作$target-1$，$num+1$，经过$t$次操作后$num==target$，这样的话$target$的原始值最大。

最大为多大呢？最大为$target=num+t\times2$。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + t * 2;
    }
};
```

#### Python

```python
class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        return num + t * 2
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/21/LeetCode%202769.%E6%89%BE%E5%87%BA%E6%9C%80%E5%A4%A7%E7%9A%84%E5%8F%AF%E8%BE%BE%E6%88%90%E6%95%B0%E5%AD%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139101760](https://letmefly.blog.csdn.net/article/details/139101760)
