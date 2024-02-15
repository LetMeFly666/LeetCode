---
title: LCP 06.拿硬币
date: 2023-09-20 10:44:31
tags: [题解, LeetCode, 简单, 数组, 数学, 遍历]
---

# 【LetMeFly】LCP 06.拿硬币

力扣题目链接：[https://leetcode.cn/problems/na-ying-bi/](https://leetcode.cn/problems/na-ying-bi/)

<p>桌上有 <code>n</code> 堆力扣币，每堆的数量保存在数组 <code>coins</code> 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。</p>

<p><strong>示例 1：</strong></p>

<blockquote>
<p>输入：<code>[4,2,1]</code></p>

<p>输出：<code>4</code></p>

<p>解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。</p>
</blockquote>

<p><strong>示例 2：</strong></p>

<blockquote>
<p>输入：<code>[2,3,10]</code></p>

<p>输出：<code>8</code></p>
</blockquote>

<p><strong>限制：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 10</code></li>
</ul>

## 方法一：遍历

每次能拿1或2枚硬币，那肯定是尽可能地多拿。对于一堆$n$个硬币，需要的最少次数为$\lceil \frac{n}2 \rceil$。

小技巧：$\lfloor\frac{n+1}2\rfloor=\lceil \frac{n}2 \rceil$

+ 时间复杂度$O(len(coins))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for (int t : coins) {
            ans += (t + 1)/ 2;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def minCount(self, coins: List[int]) -> int:
        return sum((i + 1) // 2 for i in coins)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/20/LeetCode%20LCP%2006.%20%E6%8B%BF%E7%A1%AC%E5%B8%81/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133070027](https://letmefly.blog.csdn.net/article/details/133070027)
