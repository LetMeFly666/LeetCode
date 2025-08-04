---
title: 2561.重排水果：贪心 - 缜密的思维题
date: 2025-08-04 23:07:22
tags: [题解, LeetCode, 困难, 贪心, 数组, 哈希表, map, 思维]
categories: [题解, LeetCode]
---

# 【LetMeFly】2561.重排水果：贪心 - 缜密的思维题

力扣题目链接：[https://leetcode.cn/problems/rearranging-fruits/](https://leetcode.cn/problems/rearranging-fruits/)

<p>你有两个果篮，每个果篮中有 <code>n</code> 个水果。给你两个下标从 <strong>0</strong> 开始的整数数组 <code>basket1</code> 和 <code>basket2</code> ，用以表示两个果篮中每个水果的交换成本。你想要让两个果篮相等。为此，可以根据需要多次执行下述操作：</p>

<ul>
	<li>选中两个下标 <code>i</code> 和 <code>j</code> ，并交换 <code>basket1</code> 中的第 <code>i</code> 个水果和 <code>basket2</code> 中的第 <code>j</code> 个水果。</li>
	<li>交换的成本是 <code>min(basket1<sub>i</sub>,basket2<sub>j</sub>)</code> 。</li>
</ul>

<p>根据果篮中水果的成本进行排序，如果排序后结果完全相同，则认为两个果篮相等。</p>

<p>返回使两个果篮相等的最小交换成本，如果无法使两个果篮相等，则返回<em> </em><code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>basket1 = [4,2,2,2], basket2 = [1,4,1,2]
<strong>输出：</strong>1
<strong>解释：</strong>交换 basket1 中下标为 1 的水果和 basket2 中下标为 0 的水果，交换的成本为 1 。此时，basket1 = [4,1,2,2] 且 basket2 = [2,4,1,2] 。重排两个数组，发现二者相等。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>basket1 = [2,3,4,1], basket2 = [3,2,5,1]
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明无法使两个果篮相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>basket1.length == baskte2.length</code></li>
	<li><code>1 &lt;= basket1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= basket1<sub>i</sub>,basket2<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
</ul>

不错的一题。

## 解题方法：贪心

什么时候无法相等？

> 交换方式有两种，一种是同一个篮子中的水果交换（代价为0），另一种是两个篮子中的水果交换（代价为要交换水果中价值较小的那个），即任意两个水果之间都可以直接交换。
>
> 那么，怎么判断能否通过交换使得两个篮子中水果相同呢？很简单，若每种价值的水果出现偶数次即可。

关注哪些必要交换？

> 相同篮子中水果随便交换我们不管，我们关注的就是不同篮子之中至少要发生哪些交换。
>
> 因此可以使用一个哈希表记录下两个篮子中的水果差值（累积篮子1中的水果，累减篮子2中的水果）。
>
> 若某价值的水果出现次数之差不为零，则说明需要出现两个篮子之间的交换，交换次数为$abs(diff)/2$。
>
> > 这里其实可以顺带解决下能否相等的问题，若出现奇数次的diff说明无法交换地两个篮子相等。

最小交换代价是多少？

> 假设要交换的苹果**价值**数组是$[2, 3, 30, 40]$，那么最小交换代价是$2+3$（$2$和$30$交换，$3$和$40$交换），即交换数组最小的一半元素之和。
>
> 有人反驳说，一定可以做到全部使用交换数组中最小的一半元素和最大的一半元素交换吗？万一$2$和$30$在同一篮子中怎么办？
>
> 结论是一定可以，$2$和$30$在同一篮子中则说明$2$和$40$不在同一篮子中。

那最小交换代价是交换数组最小的一半元素之和吗？

> 也不一定，可能还会有更低的交换成本。
>
> 假设存在一个价值为$1$的苹果，而要交换的苹果的价值为$[100, 200, 300, ...]$，那么交换$100$和$300$时，假设$1$在$100$的篮子中，那么其实我可以先用$1$和$300$交换，再用$1$和$100$交换，$1$还在原来的篮子中但$100$和$300$交换了，总代价为$1\times 2$

综上：

> 假设要交换的苹果价值数组为change，则总代价为$\sum \min(2\times m, change[i])$，其中$m$为两筐苹果中价值最小的那个，$change[i]$为$change$数组中最小的那一半元素。

+ 时间复杂度$O(n\log n)$，其中$n=len(basket1)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-03 23:46:56
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

/*
假设要交换的有 3 4 30 40

b1: [3, 30]
b2: [4, 40]

则min: 3+4

*/
typedef long long ll;
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> diffTimes;
        int m = INT_MAX;
        for (int t : basket1) {
            diffTimes[t]++;
            m = min(m, t);
        }
        for (int t : basket2) {
            diffTimes[t]--;
            m = min(m, t);
        }
        vector<int> change;
        for (auto [val, times] : diffTimes) {
            if (!times) {
                continue;
            }
            if (times % 2) {
                return -1;
            }
            for (int i = 0; i < abs(times) / 2; i++) {
                change.push_back(val);
            }
        }
        sort(change.begin(), change.end());
        ll ans = 0;
        for (int i = 0; i < change.size() / 2; i++) {
            ans += min(change[i], 2 * m);
        }
        return ans;
    }
};

/*
[4,2,2,2]
[1,4,1,2]

1
*/
#if defined(_WIN32) || defined(__APPLE__)
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<int> v1 = stringToVector(s1), v2 = stringToVector(s2);
        Solution sol;
        cout << sol.minCost(v1, v2) << endl;
    }
    return 0;
}
#endif
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-03 22:53:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-04 00:07:41
'''
from typing import List
from collections import defaultdict

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        m = min(min(basket1), min(basket2))
        diffTimes = defaultdict(int)
        for t in basket1:
            diffTimes[t] += 1
        for t in basket2:
            diffTimes[t] -= 1
        change = []
        for val, times in diffTimes.items():
            if not times:
                continue
            if times % 2:
                return -1
            for _ in range(abs(times) // 2):
                change.append(val)
        change.sort()
        return sum(min(m * 2, t) for t in change[:len(change) // 2])
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-04 13:46:46
 */
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        int m = basket1[0];
        Map<Integer, Integer> timeDiffs = new HashMap<>();
        for (int t : basket1) {
            timeDiffs.merge(t, 1, Integer::sum);
            m = Math.min(m, t);
        }
        for (int t : basket2) {
            timeDiffs.merge(t, -1, Integer::sum);
            m = Math.min(m, t);
        }

        List<Integer> change = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : timeDiffs.entrySet()) {
            if (entry.getValue() == 0) {
                continue;
            }
            if (entry.getValue() % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < Math.abs(entry.getValue()) / 2; i++) {
                change.add(entry.getKey());
            }
        }

        long ans = 0;
        change.sort(Integer::compareTo);
        for (int i = 0; i < change.size() / 2; i++) {
            ans += Math.min(2 * m, change.get(i));
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-04 13:38:44
 */
package main

import "sort"

func abs2561(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func minCost(basket1 []int, basket2 []int) (ans int64) {
    timeDiffs := map[int]int{}
    m := 1000000000
    for _, t := range basket1 {
        timeDiffs[t]++
        m = min(m, t)
    }
    for _, t := range basket2 {
        timeDiffs[t]--
        m = min(m, t)
    }
    
    change := []int{}
    for val, times := range timeDiffs {
        if times == 0 {
            continue
        }
        if times % 2 != 0 {
            return -1
        }
        for range abs2561(times) / 2 {  // 刚发现go还有这种语法呢
            change = append(change, val)
        }
    }

    sort.Ints(change)
    for i := 0; i < len(change) / 2; i++ {
        ans += int64(min(2 * m, change[i]))
    }
    return
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-03 22:53:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-04 23:06:33
 */
use std::collections::HashMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let mut m: i32 = i32::MAX;
        let mut timeDiffs = HashMap::new();
        for &t in &basket1 {
            *timeDiffs.entry(t).or_insert(0) += 1;
            m = m.min(t);
        }
        for &t in &basket2 {
            *timeDiffs.entry(t).or_insert(0) -= 1;
            m = m.min(t);
        }
        
        let mut change: Vec<i32> = vec![];
        for (&val, &times) in timeDiffs.iter() {
            if times % 2 != 0 {
                return -1;
            }
            for _ in 0..((times as i32).abs() / 2) {
                change.push(val);
            }
        }

        change.sort_unstable();
        let mut ans: i64 = 0;
        for i in 0..(change.len() / 2) {
            ans += i64::from(change[i].min(2 * m));
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/149917019)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/03/LeetCode%202561.%E9%87%8D%E6%8E%92%E6%B0%B4%E6%9E%9C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
