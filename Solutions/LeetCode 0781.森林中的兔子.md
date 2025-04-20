---
title: 781.森林中的兔子：思维题(哈希表+贪心) —— 通俗易懂讲解版
date: 2025-04-20 21:15:13
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, map, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】781.森林中的兔子：思维题(哈希表+贪心) —— 通俗易懂讲解版

力扣题目链接：[https://leetcode.cn/problems/rabbits-in-forest/](https://leetcode.cn/problems/rabbits-in-forest/)

<p>森林中有未知数量的兔子。提问其中若干只兔子<strong> "还有多少只兔子与你（指被提问的兔子）颜色相同?"</strong> ，将答案收集到一个整数数组 <code>answers</code> 中，其中 <code>answers[i]</code> 是第 <code>i</code> 只兔子的回答。</p>

<p>给你数组 <code>answers</code> ，返回森林中兔子的最少数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>answers = [1,1,2]
<strong>输出：</strong>5
<strong>解释：</strong>
两只回答了 "1" 的兔子可能有相同的颜色，设为红色。 
之后回答了 "2" 的兔子不会是红色，否则他们的回答会相互矛盾。
设回答了 "2" 的兔子为蓝色。 
此外，森林中还应有另外 2 只蓝色兔子的回答没有包含在数组中。 
因此森林中兔子的最少数量是 5 只：3 只回答的和 2 只没有回答的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>answers = [10,10,10]
<strong>输出：</strong>11
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= answers.length &lt;= 1000</code></li>
	<li><code>0 &lt;= answers[i] &lt; 1000</code></li>
</ul>

很有意思的一道题。

## 解题方法：哈希表+贪心

+ 假设有$3$只兔子的答案是“还有4只兔子和它颜色相同”，那么最少有几只兔子？最少有4只（这$3$只一组再加上没问到的一只一个色）。
+ 假设有$4$只兔子的答案是“还有4只兔子和它颜色相同”，那么最少有几只兔子？最少有4只（这$4$只一组一个色）。
+ 假设有$5$只兔子的答案是“还有4只兔子和它颜色相同”，那么最少有几只兔子？最少有8只（其中$4$只一组一个色，另外一只和其他没问到的$3$只一组另一个色）。
+ 假设有$6$只兔子的答案是“还有4只兔子和它颜色相同”，那么最少有几只兔子？最少有8只（其中$4$只一组一个色，另外两只和其他没问到的$2$只一组另一个色）。

不难发现，假设“和另外$group$只兔子颜色相同”的兔子一共有$total$只，那么这些兔子最少有多少只？最少有$\lceil\frac{total}{group + 1}\rceil\times (group+1)$只。

题外话：$\lceil\frac{total}{group + 1}\rceil\times (group+1)=\lfloor\frac{total+group}{group + 1}\rfloor\times (group+1)$。

+ 时间复杂度$O(len(answers))$
+ 空间复杂度$O(len(answers))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-20 19:35:57
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-20 19:40:16
 */
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> times;
        for (int t : answers) {
            times[t]++;
        }
        int ans = 0;
        for (auto [group, total] : times) {
            ans += (total + group) / (group + 1) * (group + 1);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-20 19:53:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-20 20:05:51
'''
from typing import List
from collections import Counter

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        return sum((group + total) // (group + 1) * (group + 1) for group, total in Counter(answers).items())
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-20 21:06:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-20 21:12:27
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> times = new HashMap<>();
        for (int t : answers) {
            times.merge(t, 1, Integer::sum);
        }
        int ans = 0;
        // times.forEach((group, total) -> ans += (group + total) / (group + 1) * (group + 1));  // 不可，CE
        for (Map.Entry<Integer, Integer> entry : times.entrySet()) {
            int group = entry.getKey();
            int total = entry.getValue();
            ans += (group + total) / (group + 1) * (group + 1);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-20 21:04:11
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-20 21:05:23
 */
package main

func numRabbits(answers []int) (ans int) {
    times := map[int]int{}
    for _, v := range answers {
        times[v]++
    }
    for group, total := range times {
        ans += (total + group) / (group + 1) * (group + 1)
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147375747)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/20/LeetCode%200781.%E6%A3%AE%E6%9E%97%E4%B8%AD%E7%9A%84%E5%85%94%E5%AD%90/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
