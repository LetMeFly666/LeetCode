---
title: 1534.统计好三元组：系列题之-easy等级先模拟
date: 2025-04-15 13:27:51
tags: [题解, LeetCode, 简单, 数组, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】1534.统计好三元组：系列题之-easy等级先模拟

力扣题目链接：[https://leetcode.cn/problems/count-good-triplets/](https://leetcode.cn/problems/count-good-triplets/)

<p>给你一个整数数组 <code>arr</code> ，以及 <code>a</code>、<code>b</code> 、<code>c</code> 三个整数。请你统计其中好三元组的数量。</p>

<p>如果三元组 <code>(arr[i], arr[j], arr[k])</code> 满足下列全部条件，则认为它是一个 <strong>好三元组</strong> 。</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; k &lt;&nbsp;arr.length</code></li>
	<li><code>|arr[i] - arr[j]| &lt;= a</code></li>
	<li><code>|arr[j] - arr[k]| &lt;= b</code></li>
	<li><code>|arr[i] - arr[k]| &lt;= c</code></li>
</ul>

<p>其中 <code>|x|</code> 表示 <code>x</code> 的绝对值。</p>

<p>返回 <strong>好三元组的数量</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
<strong>输出：</strong>4
<strong>解释：</strong>一共有 4 个好三元组：[(3,0,1), (3,0,1), (3,1,1), (0,1,1)] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,1,2,2,3], a = 0, b = 0, c = 1
<strong>输出：</strong>0
<strong>解释：</strong>不存在满足所有条件的三元组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 100</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= a, b, c &lt;= 1000</code></li>
</ul>


    
## 解题方法：三层循环

第一层用$i$从$0$到$n-1$，第二层用$j$从$i+1$到$n-1$，第三层用$k$从$j+1$到$n-1$，判断这个三元组是否为“好三元组”。

+ 时间复杂度$O(len(arr)^3)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-15 10:24:13
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-15 10:28:19
 */
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) > a) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    ans += abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c;
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-15 10:28:55
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-15 10:34:14
'''
from typing import List

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        # return sum(abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(arr[j] - arr[k]) <= c for k in range(j + 1, len(arr)) for j in range(i + 1, len(arr)) for i in range(len(arr)))
        return sum(abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c for i in range(len(arr)) for j in range(i + 1, len(arr)) for k in range(j + 1, len(arr)))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-15 10:35:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-15 10:37:19
 */
class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int ans = 0, n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-15 10:39:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-15 10:43:14
 */
package main

func abs1534(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func countGoodTriplets(arr []int, a int, b int, c int) (ans int) {
    for i := range arr {
        for j := i + 1; j < len(arr); j++ {
            for k := j + 1; k < len(arr); k++ {
                if abs1534(arr[i] - arr[j]) <= a && abs1534(arr[j] - arr[k]) <= b && abs1534(arr[i] - arr[k]) <= c {
                    ans++
                }
            }
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147249275)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/15/LeetCode%201534.%E7%BB%9F%E8%AE%A1%E5%A5%BD%E4%B8%89%E5%85%83%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
