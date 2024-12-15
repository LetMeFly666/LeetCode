---
title: 1338.数组大小减半
date: 2024-12-15 15:29:57
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, map, 排序, 堆（优先队列）]
---

# 【LetMeFly】1338.数组大小减半：贪心（有限删除出现次数多的）+哈希表

力扣题目链接：[https://leetcode.cn/problems/reduce-array-size-to-the-half/](https://leetcode.cn/problems/reduce-array-size-to-the-half/)

<p>给你一个整数数组&nbsp;<code>arr</code>。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。</p>

<p>返回&nbsp;<strong>至少</strong>&nbsp;能删除数组中的一半整数的整数集合的最小大小。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,3,3,3,5,5,5,2,2,7]
<strong>输出：</strong>2
<strong>解释：</strong>选择 {3,7} 使得结果数组为 [5,5,5,2,2]、长度为 5（原数组长度的一半）。
大小为 2 的可行集合有 {3,5},{3,2},{5,2}。
选择 {2,7} 是不可行的，它的结果数组为 [3,3,3,3,5,5,5]，新数组长度大于原数组的二分之一。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [7,7,7,7,7,7]
<strong>输出：</strong>1
<strong>解释：</strong>我们只能选择集合 {7}，结果数组为空。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>arr.length</code>&nbsp;为偶数</li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：贪心 + 哈希表

当然是优先删除出现次数多的元素。怎么统计每个元素出现了多少次？使用一个哈希表即可。

之后对“每个出现次数”组成的数组排序，从出现次数最大的开始累加，直到和不小于$\frac{arr}{2}$为止，所累加的数目即为答案。

+ 时间复杂度$O(n\log n)$，其中$n=len(arr)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> ma;
        for (int t : arr) {
            ma[t]++;
        }
        vector<int> times;
        for (auto&& [_, t] : ma) {
            times.push_back(t);
        }
        sort(times.begin(), times.end());
        int ans = 0;
        for (int cnt = 0, i = times.size() - 1; cnt < arr.size() / 2; ans++, i--) {
            cnt += times[i];
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List
from collections import Counter

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        ma = Counter(arr)
        times = [t for i, t in ma.items()]
        times.sort()
        ans, cnt, i = 0, 0, len(times) - 1
        while cnt < len(arr) // 2:
            ans += 1
            cnt += times[i]
            i -= 1
        return ans
```

#### Java

```java
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : arr) {
            ma.merge(t, 1, Integer::sum);
        }
        List<Integer> times = new ArrayList<>(ma.values());
        times.sort((a, b) -> b - a);
        int ans = 0;
        for (int cnt = 0, i = 0; cnt < arr.length / 2; ans++, i++) {
            cnt += times.get(i);
        }
        return ans;
    }
}
```

#### Go

```go
package main
import "sort"

func minSetSize(arr []int) (ans int) {
    ma := map[int]int{}
    for _, t := range arr {
        ma[t]++
    }
    var times []int
    for _, t := range ma {
        times = append(times, t)
    }
    sort.Slice(times, func(i, j int) bool {
        return times[i] > times[j]
    })
    for cnt := 0; cnt < len(arr) / 2; ans++ {
        cnt += times[ans]
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/15/LeetCode%201338.%E6%95%B0%E7%BB%84%E5%A4%A7%E5%B0%8F%E5%87%8F%E5%8D%8A/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144487651](https://letmefly.blog.csdn.net/article/details/144487651)
