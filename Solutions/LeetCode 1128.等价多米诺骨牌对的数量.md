---
title: 1128.等价多米诺骨牌对的数量：计数
date: 2025-05-04 16:21:47
tags: [题解, LeetCode, 简单, 数组, 哈希表, map, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】1128.等价多米诺骨牌对的数量：计数

力扣题目链接：[https://leetcode.cn/problems/number-of-equivalent-domino-pairs/](https://leetcode.cn/problems/number-of-equivalent-domino-pairs/)

<p>给你一组多米诺骨牌 <code>dominoes</code> 。</p>

<p>形式上，<code>dominoes[i] = [a, b]</code> 与 <code>dominoes[j] = [c, d]</code> <strong>等价</strong> 当且仅当 (<code>a == c</code> 且 <code>b == d</code>) 或者 (<code>a == d</code> 且 <code>b == c</code>) 。即一张骨牌可以通过旋转 <code>0</code>&nbsp;度或 <code>180</code> 度得到另一张多米诺骨牌。</p>

<p>在&nbsp;<code>0 &lt;= i &lt; j &lt; dominoes.length</code>&nbsp;的前提下，找出满足&nbsp;<code>dominoes[i]</code> 和&nbsp;<code>dominoes[j]</code>&nbsp;等价的骨牌对 <code>(i, j)</code> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dominoes = [[1,2],[2,1],[3,4],[5,6]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= dominoes.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>dominoes[i].length == 2</code></li>
	<li><code>1 &lt;= dominoes[i][j] &lt;= 9</code></li>
</ul>


    
## 解题方法：哈希表计数

使用一个哈希表(或数组)统计每**种**多米诺骨牌的出现次数。

既然`[1, 2]`和`[2, 1]`等价，那么不妨将他们视为同一**种**骨牌来看待。

> 即：当`[a, b]`中`a > b`时，将`[a, b]`调整为`[b, a]`。

哈希表如何设计（如何将两个数映射为一个数）？

> `(a - 1) * 9 + (b - 1)`即可。
>
> 这样，哈希表的大小`9 * 9 = 81`即可。

如何计算“对数”？

> 两种方法：
>
> 1. 统计出每种骨牌出现次数后，遍历哈希表，若这种骨牌出现了$t$次，则可形成$\frac{t (t - 1)}{2}$对骨牌
>
> 2. 假设在骨牌$v$加入哈希表之前哈希表中$v$出现了$t$次，那么就先将答案加上$t$再将哈希表中$v$出现次数加一。

+ 时间复杂度：方法一$O(len(dominoes))$；方法二$O(len(dominoes)+C^2)$。其中$C=9$
+ 空间复杂度$O(C^2)$

### AC代码

#### C++ - 方法二

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 14:26:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 15:02:06
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int pair2int(vector<int>& v) {
        if (v[0] > v[1]) {
            return (v[1] - 1) * 9 + (v[0] - 1);
        }
        return (v[0] - 1) * 9 + (v[1] - 1);
    }
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int times[81] = {0};
        for (vector<int>& v : dominoes) {
            times[pair2int(v)]++;
        }
        int ans = 0;
        for (int i = 0; i < 81; i++) {
            ans += times[i] * (times[i] - 1) / 2;
        }
        return ans;
    }
};
```

#### C++ - 方法一

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 16:12:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 16:13:46
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int times[81] = {0} ;
        int ans = 0;
        for (vector<int>& d : dominoes) {
            ans += times[d[0] < d[1] ? (d[0] - 1) * 9 + d[1] - 1 : (d[1] - 1) * 9 + d[0] - 1]++;
        }
        return ans;
    }
};
```

#### Python - 方法一

```python
'''
Author: LetMeFly
Date: 2025-05-04 14:26:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-04 16:10:15
'''
from typing import List

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        times = [0] * 81
        ans = 0
        for a, b in dominoes:
            v = (a - 1) * 9 + (b - 1) if a < b else (b - 1) * 9 + (a - 1)
            ans += times[v]
            times[v] += 1
        return ans
```

#### Java - 方法一

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 14:26:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 16:15:28
 */
class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int[] times = new int[81];
        int ans = 0;
        for (int[] d : dominoes) {
            ans += times[d[0] < d[1] ? (d[0] - 1) * 9 + d[1] - 1 : (d[1] - 1) * 9 + d[0] - 1]++;
        }
        return ans;
    }
}
```

#### Go - 方法一

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-04 14:26:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-04 16:18:34
 */
package main

func numEquivDominoPairs(dominoes [][]int) (ans int) {
    times := make([]int, 81)
    for _, d := range dominoes {
        var v int
        if d[0] < d[1] {
            v = (d[0] - 1) * 9 + d[1] - 1
        } else {
            v = (d[1] - 1) * 9 + d[0] - 1
        }
        ans += times[v]
        times[v]++
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147700894)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/04/LeetCode%201128.%E7%AD%89%E4%BB%B7%E5%A4%9A%E7%B1%B3%E8%AF%BA%E9%AA%A8%E7%89%8C%E5%AF%B9%E7%9A%84%E6%95%B0%E9%87%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
