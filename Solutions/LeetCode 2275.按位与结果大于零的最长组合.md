---
title: 2275.按位与结果大于零的最长组合
date: 2025-01-14 17:27:43
tags: [题解, LeetCode, 中等, 位运算, 数组, 哈希表, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】2275.按位与结果大于零的最长组合：按位与

力扣题目链接：[https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/](https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/)

<p>对数组&nbsp;<code>nums</code> 执行 <strong>按位与</strong> 相当于对数组&nbsp;<code>nums</code> 中的所有整数执行 <strong>按位与</strong> 。</p>

<ul>
	<li>例如，对 <code>nums = [1, 5, 3]</code> 来说，按位与等于 <code>1 &amp; 5 &amp; 3 = 1</code> 。</li>
	<li>同样，对 <code>nums = [7]</code> 而言，按位与等于 <code>7</code> 。</li>
</ul>

<p>给你一个正整数数组 <code>candidates</code> 。计算 <code>candidates</code> 中的数字每种组合下 <strong>按位与</strong> 的结果。</p>

<p>返回按位与结果大于 <code>0</code> 的 <strong>最长</strong> 组合的长度<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>candidates = [16,17,71,62,12,24,14]
<strong>输出：</strong>4
<strong>解释：</strong>组合 [16,17,62,24] 的按位与结果是 16 &amp; 17 &amp; 62 &amp; 24 = 16 &gt; 0 。
组合长度是 4 。
可以证明不存在按位与结果大于 0 且长度大于 4 的组合。
注意，符合长度最大的组合可能不止一种。
例如，组合 [62,12,24,14] 的按位与结果是 62 &amp; 12 &amp; 24 &amp; 14 = 8 &gt; 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>candidates = [8,8]
<strong>输出：</strong>2
<strong>解释：</strong>最长组合是 [8,8] ，按位与结果 8 &amp; 8 = 8 &gt; 0 。
组合长度是 2 ，所以返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= candidates[i] &lt;= 10<sup>7</sup></code></li>
</ul>


    
## 解题方法：位运算(按位与)

假设最终选择了$a$、$b$、$c$且它们的与运算结果非零，那么二进制下$abc$至少有一位都非零。

因此我们可以对每一位分别计算，对于某一位，遍历数组中所有元素，统计这一位非零元素的个数。这些元素按位与的话，结果一定非零。

在所有位中，非零数量最多的“数量”即为所求。

+ 时间复杂度$O(\log\max(candidates[i])\times len(canndidates))$，其中$2^{24}=16,777,216\gt10^7$，$\log\max(candidates[i])\approx24$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 17:04:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 17:05:30
 */
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 24; i++) {
            int cnt = 0;
            for (int t : candidates) {
                cnt += t >> i & 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-14 17:13:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-14 17:15:52
'''
from typing import List

class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        return max(sum(t >> i & 1 for t in candidates) for i in range(24))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 17:16:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 17:16:23
 */
class Solution {
    public int largestCombination(int[] candidates) {
        int ans = 0;
        for (int i = 0; i < 24; i++) {
            int cnt = 0;
            for (int t : candidates) {
                cnt += t >> i & 1;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-14 17:17:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-14 17:18:45
 */
package main

func largestCombination(candidates []int) (ans int) {
    for i := 0; i < 24; i++ {
        cnt := 0
        for _, t := range candidates {
            cnt += t >> i & 1
        }
        if cnt > ans {
            ans = cnt
        }
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/14/LeetCode%202275.%E6%8C%89%E4%BD%8D%E4%B8%8E%E7%BB%93%E6%9E%9C%E5%A4%A7%E4%BA%8E%E9%9B%B6%E7%9A%84%E6%9C%80%E9%95%BF%E7%BB%84%E5%90%88/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145144347](https://letmefly.blog.csdn.net/article/details/145144347)
