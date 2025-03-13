---
title: 2274.不含特殊楼层的最大连续楼层数
date: 2025-01-06 20:45:47
tags: [题解, LeetCode, 中等, 数组, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2274.不含特殊楼层的最大连续楼层数：排序

力扣题目链接：[https://leetcode.cn/problems/maximum-consecutive-floors-without-special-floors/](https://leetcode.cn/problems/maximum-consecutive-floors-without-special-floors/)

<p>Alice 管理着一家公司，并租用大楼的部分楼层作为办公空间。Alice 决定将一些楼层作为 <strong>特殊楼层</strong> ，仅用于放松。</p>

<p>给你两个整数 <code>bottom</code> 和 <code>top</code> ，表示 Alice 租用了从 <code>bottom</code> 到 <code>top</code>（含 <code>bottom</code> 和 <code>top</code> 在内）的所有楼层。另给你一个整数数组 <code>special</code> ，其中 <code>special[i]</code> 表示&nbsp; Alice 指定用于放松的特殊楼层。</p>

<p>返回不含特殊楼层的 <strong>最大</strong> 连续楼层数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>bottom = 2, top = 9, special = [4,6]
<strong>输出：</strong>3
<strong>解释：</strong>下面列出的是不含特殊楼层的连续楼层范围：
- (2, 3) ，楼层数为 2 。
- (5, 5) ，楼层数为 1 。
- (7, 9) ，楼层数为 3 。
因此，返回最大连续楼层数 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>bottom = 6, top = 8, special = [7,6,8]
<strong>输出：</strong>0
<strong>解释：</strong>每层楼都被规划为特殊楼层，所以返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示</strong></p>

<ul>
	<li><code>1 &lt;= special.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= bottom &lt;= special[i] &lt;= top &lt;= 10<sup>9</sup></code></li>
	<li><code>special</code> 中的所有值 <strong>互不相同</strong></li>
</ul>


    
## 解题方法：排序

对“特殊楼层”从小到大排序，统计如下三者的最大值即为答案：

1. $special[0] - bottom$
2. $special[i] - special[i - 1] - 1$，其中$1\leq i\lt len(special)$
3. $top - special[len(special) - 1]$

+ 时间复杂度$O(n\log n)$，其中$n=len(special)$
+ 空间复杂度$O(\log n)$

### AC代码

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-06 20:36:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-06 20:38:18
'''
from typing import List

class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.sort()
        ans = max(special[0] - bottom, top - special[-1])
        for i in range(1, len(special)):
            ans = max(ans, special[i] - special[i - 1] - 1)
        return ans
```

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-06 20:32:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-06 20:35:34
 */
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int ans = top - special.back();
        bottom--;
        for (int t : special) {
            ans = max(ans, t - bottom - 1);
            bottom = t;
        }
        return ans;
    }
};
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-06 20:39:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-06 20:40:24
 */
import java.util.Arrays;

class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        Arrays.sort(special);
        int ans = Math.max(special[0] - bottom, top - special[special.length - 1]);
        for (int i = 1; i < special.length; i++) {
            ans = Math.max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-06 20:41:20
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-06 20:43:19
 */
package main
import "sort"

func max_MCFWSF(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxConsecutive(bottom int, top int, special []int) (ans int) {
    sort.Ints(special)
    ans = max_MCFWSF(special[0] - bottom, top - special[len(special) - 1])
    for i := 1; i < len(special); i++ {
        ans = max_MCFWSF(ans, special[i] - special[i - 1] - 1)
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/06/LeetCode%202274.%E4%B8%8D%E5%90%AB%E7%89%B9%E6%AE%8A%E6%A5%BC%E5%B1%82%E7%9A%84%E6%9C%80%E5%A4%A7%E8%BF%9E%E7%BB%AD%E6%A5%BC%E5%B1%82%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144972086](https://letmefly.blog.csdn.net/article/details/144972086)
