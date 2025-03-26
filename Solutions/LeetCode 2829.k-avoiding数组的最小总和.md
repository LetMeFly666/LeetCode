---
title: 2829.k-avoiding 数组的最小总和：贪心（数学公式O(1)算出）
date: 2025-03-26 13:52:44
tags: [题解, LeetCode, 中等, 贪心, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】2829.k-avoiding 数组的最小总和：贪心（数学公式O(1)算出）

力扣题目链接：[https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/](https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/)

<p>给你两个整数 <code>n</code> 和 <code>k</code> 。</p>

<p>对于一个由 <strong>不同</strong> 正整数组成的数组，如果其中不存在任何求和等于 k 的不同元素对，则称其为 <strong>k-avoiding</strong> 数组。</p>

<p>返回长度为 <code>n</code> 的 <strong>k-avoiding</strong> 数组的可能的最小总和。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5, k = 4
<strong>输出：</strong>18
<strong>解释：</strong>设若 k-avoiding 数组为 [1,2,4,5,6] ，其元素总和为 18 。
可以证明不存在总和小于 18 的 k-avoiding 数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 6
<strong>输出：</strong>3
<strong>解释：</strong>可以构造数组 [1,2] ，其元素总和为 3 。
可以证明不存在总和小于 3 的 k-avoiding 数组。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 50</code></li>
</ul>


    
## 解题方法：贪心

构造一个长度为$n$的数组，数组中任意两数之和不得为$k$，如何构造？

我们可以将数组分成两个部分：小于$k$的部分，大于等于$k$的部分。

+ 对于小于$k$的部分：

    有$a$则不能有*另外的*$k-a$，有$1$则不能有*另外的*$k-1$。

    那么我们怎么选？当然是选尽可能小的了([贪心](https://blog.letmefly.xyz/tags/%E8%B4%AA%E5%BF%83/))。

    我们从$1$开始，选择$1, 2, 3, \dots, \min(n, \lfloor\frac{k}2\rfloor)$即可。

+ 对于大于等于$k$的部分：

    若小于$k$的部分不足$n$个，则还需要选择大于等于$k$的数。

    从$k$开始依次选取就好了，一定不存在*另一个*正整数与这个数的和为$k$。

尽可能多选小于$k$的部分。附等差数列求和公式$s=\frac{(首项+尾项)\times项数}2$。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:08:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:43:41
 */
/*
5 4
1 2 4 5 6

2 6
1 2

∞ 1
1

∞ 2
1 2

∞ 3
1 3

∞ 4
1 2

∞ 5
1 2

∞ 6
1 2 3

∞ 7
1 2 3

∞ 8
1 2 3 4

∞ 9
1 2 3 4

小于k的数最多从1加到k/2(下取整)
之后就可以从k开始k, k+1, k+2, ...了
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int to = min(n, k / 2);
        int ans = to * (to + 1) / 2;
        n -= to;
        ans += n * (k + k + n - 1) / 2;
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-26 13:45:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-26 13:47:07
'''
class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        to = min(n, k // 2)
        n -= to
        return to * (to + 1) // 2 + n * (k + k + n - 1) // 2
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:48:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:48:58
 */
class Solution {
    public int minimumSum(int n, int k) {
        int to = Math.min(n, k / 2);
        n -= to;
        return to * (to + 1) / 2 + n * (k + k + n - 1) / 2;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-26 13:50:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-26 13:50:45
 */
package main

func minimumSum(n int, k int) int {
    to := min(n, k / 2)
    n -= to
    return to * (to + 1) / 2 + n * (k + k + n - 1) / 2
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146528057)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/26/LeetCode%202829.k-avoiding%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E6%80%BB%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
