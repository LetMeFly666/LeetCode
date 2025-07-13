---
title: 2410.运动员和训练师的最大匹配数：贪心（拿当前min教练匹配剩下最min学员）
date: 2025-07-13 17:09:36
tags: [题解, LeetCode, 中等, 贪心, 数组, 双指针, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2410.运动员和训练师的最大匹配数：贪心（拿当前min教练匹配剩下最min学员）

力扣题目链接：[https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/](https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>players</code>&nbsp;，其中&nbsp;<code>players[i]</code>&nbsp;表示第 <code>i</code>&nbsp;名运动员的 <strong>能力</strong>&nbsp;值，同时给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>trainers</code>&nbsp;，其中&nbsp;<code>trainers[j]</code>&nbsp;表示第 <code>j</code>&nbsp;名训练师的 <strong>训练能力值</strong>&nbsp;。</p>

<p>如果第 <code>i</code>&nbsp;名运动员的能力值 <strong>小于等于</strong>&nbsp;第 <code>j</code>&nbsp;名训练师的能力值，那么第&nbsp;<code>i</code>&nbsp;名运动员可以 <strong>匹配</strong>&nbsp;第&nbsp;<code>j</code>&nbsp;名训练师。除此以外，每名运动员至多可以匹配一位训练师，每位训练师最多可以匹配一位运动员。</p>

<p>请你返回满足上述要求&nbsp;<code>players</code>&nbsp;和 <code>trainers</code>&nbsp;的 <strong>最大</strong> 匹配数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>players = [4,7,9], trainers = [8,2,5,8]
<b>输出：</b>2
<b>解释：</b>
得到两个匹配的一种方案是：
- players[0] 与 trainers[0] 匹配，因为 4 &lt;= 8 。
- players[1] 与 trainers[3] 匹配，因为 7 &lt;= 8 。
可以证明 2 是可以形成的最大匹配数。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>players = [1,1,1], trainers = [10]
<b>输出：</b>1
<b>解释：</b>
训练师可以匹配所有 3 个运动员
每个运动员至多只能匹配一个训练师，所以最大答案是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= players.length, trainers.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= players[i], trainers[j] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：贪心（排序）

首先二话不说分别对学员和教练按从小到大的顺序排个序，接着开始遍历教练：

如果最low的(剩余)学员都教不了，这个教练可以回家了；否则就让这个教练教这个最low学员。

why？

> 当前最low教练能教小菜，也能教小强，教练教小菜是不是浪费了？不浪费，这个教练都能教小菜了，下一个教练更能教小菜。我们只关注被教的学员数量而不关注所教的学员水平。
>
> 为何不让小菜选一个超强教练？很显然，因为浪费。超强教练都拿来教小菜了，后面的学员小强就不一定能有教练教了。

+ 时间复杂度$O(n\log n + m\log m)$，其中$n = len(players), m = len(trainers)$
+ 空间复杂度$O(\log n + \log m)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 16:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 16:57:27
 */
/*
拿当前min教练匹配剩下最min学员
*/
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int ans = 0;
        for (int t = 0, p = 0; t < trainers.size() && p < players.size(); t++) {
            if (trainers[t] >= players[p]) {
                ans++, p++;
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
Date: 2025-07-13 16:44:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-13 17:00:27
'''
from typing import List

class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        ans = p = t = 0
        while t < len(trainers) and p < len(players):
            if trainers[t] >= players[p]:
                ans += 1
                p += 1
            t += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-07-13 16:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 17:06:30
 */
import java.util.Arrays;

class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);
        int ans = 0;
        for (int p = 0, t = 0; p < players.length && t < trainers.length; t++) {
            if (trainers[t] >= players[p]) {
                ans++;
                p++;
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
 * @Date: 2025-07-13 16:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-07-13 17:08:39
 */
package main

import "sort"

func matchPlayersAndTrainers(players []int, trainers []int) (ans int) {
    sort.Ints(players)
    sort.Ints(trainers)
    for p, t := 0, 0; p < len(players) && t < len(trainers); t++ {
        if trainers[t] >= players[p] {
            ans++
            p++
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149312473)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/07/13/LeetCode%202410.%E8%BF%90%E5%8A%A8%E5%91%98%E5%92%8C%E8%AE%AD%E7%BB%83%E5%B8%88%E7%9A%84%E6%9C%80%E5%A4%A7%E5%8C%B9%E9%85%8D%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
