---
title: 1552.两球之间的磁力：二分查找
date: 2025-02-14 11:07:39
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】1552.两球之间的磁力：二分查找

力扣题目链接：[https://leetcode.cn/problems/magnetic-force-between-two-balls/](https://leetcode.cn/problems/magnetic-force-between-two-balls/)

<p>在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有&nbsp;<code>n</code>&nbsp;个空的篮子，第&nbsp;<code>i</code>&nbsp;个篮子的位置在&nbsp;<code>position[i]</code>&nbsp;，Morty&nbsp;想把&nbsp;<code>m</code>&nbsp;个球放到这些篮子里，使得任意两球间&nbsp;<strong>最小磁力</strong>&nbsp;最大。</p>

<p>已知两个球如果分别位于&nbsp;<code>x</code>&nbsp;和&nbsp;<code>y</code>&nbsp;，那么它们之间的磁力为&nbsp;<code>|x - y|</code>&nbsp;。</p>

<p>给你一个整数数组&nbsp;<code>position</code>&nbsp;和一个整数&nbsp;<code>m</code>&nbsp;，请你返回最大化的最小磁力。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://cors.letmefly.xyz/https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/08/16/q3v1.jpg" style="height: 195px; width: 562px;"></p>

<pre><strong>输入：</strong>position = [1,2,3,4,7], m = 3
<strong>输出：</strong>3
<strong>解释：</strong>将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>position = [5,4,3,2,1,1000000000], m = 2
<strong>输出：</strong>999999999
<strong>解释：</strong>我们使用位于 1 和 1000000000 的篮子时最小磁力最大。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == position.length</code></li>
	<li><code>2 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= position[i] &lt;= 10^9</code></li>
	<li>所有&nbsp;<code>position</code>&nbsp;中的整数 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>2 &lt;= m &lt;= position.length</code></li>
</ul>


    
## 解题方法：二分查找

能做到“最小磁力”为$a$的话，更容易做到“最小磁力”为$a-1$。这就很适合二分。

闭区间二分，初始范围`[1, max(position) - min(position)]`。

每次令$mid = \lceil\frac{l+r}2\rceil$，若$mid$可行就令$l=mid$，否则就令$r=mid-1$。

最终返回$l$即为答案。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-14 10:45:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-14 10:55:39
 */
class Solution {
private:
    bool check(vector<int>& v, int m, int d) {
        int lastPosition = -1000000000;
        for (int t : v) {
            if (t - lastPosition >= d) {
                m--;
                if (!m) {
                    return true;
                }
                lastPosition = t;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back() - position[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(position, m, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-14 10:56:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-14 10:58:23
'''
from typing import List

class Solution:
    def check(self, m: int, d: int) -> bool:
        last = -1000000000
        for t in self.position:
            if t - last >= d:
                m -= 1
                if not m:
                    return True
                last = t
        return False
    
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        self.position = position
        l, r = 1, position[-1] - position[0]
        while l < r:
            mid = (l + r + 1) >> 1
            if self.check(m, mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-14 10:56:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-14 11:02:35
 */
import java.util.Arrays;


class Solution {
	private int[] v;

	private boolean check(int m, int d) {
        int last = -1000000000;
        for (int t : v) {
            if (t - last >= d) {
                if (--m == 0) {
                    return true;
                }
                last = t;
            }
        }
        return false;
    }

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        v = position;
        int l = 1, r = v[v.length - 1] - v[0];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(m, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-14 10:56:28
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-14 11:05:50
 */
package main

import "slices"

func check_MFB2B(v []int, m, d int) bool {
    last := -1000000000
    for _, t := range v {
        if t - last >= d {
            m--
            if m <= 0 {
                return true
            }
            last = t
        }
    }
    return false
}

func maxDistance(position []int, m int) int {
    slices.Sort(position)
    l, r := 1, position[len(position) - 1] - position[0]
    for l < r {
        mid := (l + r + 1) >> 1
        if check_MFB2B(position, m, mid) {
            l = mid
        } else {
            r = mid - 1
        }
    }
    return l
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145629037)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/14/LeetCode%201552.%E4%B8%A4%E7%90%83%E4%B9%8B%E9%97%B4%E7%9A%84%E7%A3%81%E5%8A%9B/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/14/LeetCode 1552.两球之间的磁力/](https://blog.letmefly.xyz/2025/02/14/LeetCode%201552.%E4%B8%A4%E7%90%83%E4%B9%8B%E9%97%B4%E7%9A%84%E7%A3%81%E5%8A%9B/)
