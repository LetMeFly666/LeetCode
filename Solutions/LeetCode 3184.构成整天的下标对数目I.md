---
title: 3184.构成整天的下标对数目 I
date: 2024-10-22 19:04:28
tags: [题解, LeetCode, 简单, 数组, 哈希表, 计数, 模拟, 暴力]
categories: [题解, LeetCode]
---

# 【LetMeFly】3184.构成整天的下标对数目 I：暴力模拟（下一题再用哈希表）

力扣题目链接：[https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-i/](https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-i/)

<p>给你一个整数数组 <code>hours</code>，表示以 <strong>小时 </strong>为单位的时间，返回一个整数，表示满足 <code>i &lt; j</code> 且 <code>hours[i] + hours[j]</code> 构成 <strong>整天 </strong>的下标对&nbsp;<code>i</code>, <code>j</code> 的数目。</p>

<p><strong>整天 </strong>定义为时间持续时间是 24 小时的 <strong>整数倍 </strong>。</p>

<p>例如，1 天是 24 小时，2 天是 48 小时，3 天是 72 小时，以此类推。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [12,12,30,24,24]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code> 和 <code>(3, 4)</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">hours = [72,48,24,3]</span></p>

<p><strong>输出：</strong> <span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>构成整天的下标对分别是 <code>(0, 1)</code>、<code>(0, 2)</code> 和 <code>(1, 2)</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= hours.length &lt;= 100</code></li>
	<li><code>1 &lt;= hours[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：模拟

两层循环，第一层循环遍历数组的每个元素，第二层循环从第一层循环的元素的下一个元素开始遍历，如果两数之和是24的倍数，则答案数量加一。

+ 时间复杂度$O(len(hours)^2)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        for (int i = 0; i < hours.size(); i++) {
            for (int j = i + 1; j < hours.size(); j++) {
                ans += (hours[i] + hours[j]) % 24 == 0;
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main

func countCompleteDayPairs(hours []int) int {
    ans := 0
    for i, h1 := range hours {
        for j := i + 1; j < len(hours); j++ {
            if (h1 + hours[j]) % 24 == 0 {
                ans++
            }
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int countCompleteDayPairs(int[] hours) {
        int ans = 0;
        for (int i = 0; i < hours.length; i++) {
            for (int j = i + 1; j < hours.length; j++) {
                ans += (hours[i] + hours[j]) % 24 == 0 ? 1 : 0;
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        return sum((hours[i] + hours[j]) % 24 == 0 for i in range(len(hours)) for j in range(i + 1, len(hours)))

# if __name__ == '__main__':
#     l = ((i, j) for i in range(3) for j in range(3))
#     for i, j in l:
#         print(i, j)
#     """
#     0 0
#     0 1
#     0 2
#     1 0
#     1 1
#     1 2
#     2 0
#     2 1
#     2 2
#     """
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/22/LeetCode%203184.%E6%9E%84%E6%88%90%E6%95%B4%E5%A4%A9%E7%9A%84%E4%B8%8B%E6%A0%87%E5%AF%B9%E6%95%B0%E7%9B%AEI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143166228](https://letmefly.blog.csdn.net/article/details/143166228)
