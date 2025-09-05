---
title: 2749.得到整数零需要执行的最少操作数：很独特的一道数学题（多公式硬讲——一步步还真能看懂）
date: 2025-09-05 21:34:33
tags: [题解, LeetCode, 中等, 位运算, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】2749.得到整数零需要执行的最少操作数：很独特的一道数学题（多公式硬讲——一步步还真能看懂）

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-make-the-integer-zero/](https://leetcode.cn/problems/minimum-operations-to-make-the-integer-zero/)

<p>给你两个整数：<code>num1</code> 和 <code>num2</code> 。</p>

<p>在一步操作中，你需要从范围&nbsp;<code>[0, 60]</code> 中选出一个整数 <code>i</code> ，并从 <code>num1</code> 减去 <code>2<sup>i</sup> + num2</code> 。</p>

<p>请你计算，要想使 <code>num1</code> 等于 <code>0</code> 需要执行的最少操作数，并以整数形式返回。</p>

<p>如果无法使 <code>num1</code> 等于 <code>0</code> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = 3, num2 = -2
<strong>输出：</strong>3
<strong>解释：</strong>可以执行下述步骤使 3 等于 0 ：
- 选择 i = 2 ，并从 3 减去 2<sup>2</sup> + (-2) ，num1 = 3 - (4 + (-2)) = 1 。
- 选择 i = 2 ，并从 1 减去 2<sup>2</sup> + (-2) ，num1 = 1 - (4 + (-2)) = -1 。
- 选择 i = 0 ，并从 -1 减去 2<sup>0</sup>&nbsp;+ (-2) ，num1 = (-1) - (1 + (-2)) = 0 。
可以证明 3 是需要执行的最少操作数。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = 5, num2 = 7
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明，执行操作无法使 5 等于 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1 &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= num2 &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：数学

这个题解我自己也看了很多遍，如果你想搞懂这道题，请静下心来仔细读读，相信你一定可以搞懂这道题的！哪里不懂欢迎[留言](https://github.com/LetMeFly666/LeetCode/issues/1115)。

**k范围浅分析**

假设$num1$减去$k$次$2^i+num2$后变成了$0$，那么有：

$$num_1 - k * num_2 = 2^{i_1} + 2^{i_2} + ... + 2^{i_k}$$

见到$2^{i_1} + 2^{i_2} + ... + 2^{i_k}$应该很敏感才对啊，这不是$2$的幂之和么，只不过加数可以重复。

令等式左边的$num_1 - k * num_2 = x$，那么想让右边的$2^{i_1} + 2^{i_2} + ... + 2^{i_k}=x$，$k$的合法范围是多少？

> 已知$2^{i+1}=2^i+2^i$，所以想让可以使等式成立的$k$比较大的话，可以把一个$2^{i+1}$可以拆成两个$2^i$，最小拆成$2=1+1$为止。也就是说，$x$最多可以由$1+1+1+\dots+1$（共$x$个）组成，也就是说$k$的最大值是$x$。
>
> 那么最小值呢？例如$5=101_{(2)}=2^2+2^0$，$k$最小值为$2$。也就是说对于$x$，$k$的最小值为$x$二进制下$1$的个数。

综上，只要$popcount(x)\leq k\leq x$，就能找到一种方法使得$2^{i_1} + 2^{i_2} + ... + 2^{i_k}=x$。（其中$popcount(x)$是$x$二进制下$1$的个数，$x\gt 0$。

请记住这两个条件：

1. $k\leq x$
2. $k\geq popcount(x)$

**枚举k**

但是别忘了，$x$中还含有变量$k$呢！其中$x=num_1 - k * num_2$。想要判断是返回$k$还是返回$-1$，还得看能不能找到一个$k$使得$popcount(x)\leq k\leq x$，其中$x=num_1 - k * num_2$。

最简单的办法就是**暴力枚举**。令$k$从$1$开始枚举，$1, 2, \cdots$，直到$k$超出“上界”，即$k\gt x$，也就是说$k\gt num_1 - k * num_2$停止。

这里你一定会思考，现在$k$超出上界了，那么我继续增大$k$的话，待会儿$k$会不会就不超出上界了呢？

> 为了探究这个问题，我们把$k$的合法范围处理一下：$k\leq num_1 - k * num_2\Leftrightarrow k*(1+num_2)\leq num_1$。
>
> + 当$1+num_2\leq 0$时，由于数据范围限制$num_1\geq 1$，所以$k*(1+num_2)\leq num_1$恒成立；
> + 当$1+num_2\gt 0$时，可得$k\leq \frac{num_1}{1+num_2}$时$k*(1+num_2)\leq num_1$成立，一旦$k$大于$\frac{num_1}{1+num_2}$该等式就再也不会成立；
>
> 综上，符合假设，不考虑实际算力限制下的超时问题的话，$k$从$1,2,\cdots$枚举到$k\gt x$为止，如果存在$k$满足第二个条件即$k\geq popcount(x)$，我们就能找到了符合条件的$k$；否则，这个枚举范围内没有满足第二个条件的$k$就返回$-1$。

那么$k$的范围究竟是多少呢？暴力枚举会不会超时呢？你别说，还真不会。

因为要想找到一个满足两个条件的$k$，除了一个限制枚举范围的$k\leq x$外，还有一个条件，就是$k\geq popcount(x)$。

我们一直担心的就是会不会$k\leq x$这个条件范围太大，导致$k$一直从$1$枚举到一个非常大的数字（甚至是无穷?），从而超时。

但是别忘了第二个条件$k\geq popcount(x)$是非常容易满足的，要知道$popcount(x)$可是$x$在二进制下$1$的个数，所以先告诉你结论再去证明：$k$最大枚举到几十就会满足第二个条件了。

> $k$的量级是几十（按$10^3$），$num$的量级是$10^9$，所以$x=num_1 - k * num_2$的量级最多为$10^{12}$，$2^40$已经大于$10^{12}$了（不信可以执行下`python -c "print(len(str(2**40)))"`试试），$x$二进制下位数不超过$40$位，就找到满足第二个条件的$k$了。

也就是说实际$k$从$1$开始枚举，最多枚举到$40$，就知道答案了，时间复杂度甚至可以认为是$O(1)$。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

然后结合实现代码说一下：

```cpp
int makeTheIntegerZero(int num1, int num2) {
    for (int k = 1; k <= num1 - (long long)num2 * k; k++) {
        if (k >= __builtin_popcountll(num1 - (long long)num2 * k)) {
            return k;
        }
    }
    return -1;
}
```

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-05 18:29:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-05 21:33:38
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
nums1 - k * nums2 = 2^{i_1} + 2^{i_2} + ... + 2^{i_k}
*/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= num1 - (long long)num2 * k; k++) {
            if (k >= __builtin_popcountll(num1 - (long long)num2 * k)) {
                return k;
            }
        }
        return -1;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/05/LeetCode%202749.%E5%BE%97%E5%88%B0%E6%95%B4%E6%95%B0%E9%9B%B6%E9%9C%80%E8%A6%81%E6%89%A7%E8%A1%8C%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
