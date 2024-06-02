---
title: 575.分糖果
date: 2024-06-02 09:58:56
tags: [题解, LeetCode, 简单, 数组, 哈希表]
---

# 【LetMeFly】575.分糖果：min(type, size/2)

力扣题目链接：[https://leetcode.cn/problems/distribute-candies/](https://leetcode.cn/problems/distribute-candies/)

<p>Alice 有 <code>n</code> 枚糖，其中第 <code>i</code> 枚糖的类型为 <code>candyType[i]</code> 。Alice 注意到她的体重正在增长，所以前去拜访了一位医生。</p>

<p>医生建议 Alice 要少摄入糖分，只吃掉她所有糖的 <code>n / 2</code> 即可（<code>n</code> 是一个偶数）。Alice 非常喜欢这些糖，她想要在遵循医生建议的情况下，尽可能吃到最多不同种类的糖。</p>

<p>给你一个长度为 <code>n</code> 的整数数组 <code>candyType</code> ，返回： Alice <em>在仅吃掉 <code>n / 2</code> 枚糖的情况下，可以吃到糖的 <strong>最多</strong> 种类数</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>candyType = [1,1,2,2,3,3]
<strong>输出：</strong>3
<strong>解释：</strong>Alice 只能吃 6 / 2 = 3 枚糖，由于只有 3 种糖，她可以每种吃一枚。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>candyType = [1,1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>Alice 只能吃 4 / 2 = 2 枚糖，不管她选择吃的种类是 [1,2]、[1,3] 还是 [2,3]，她只能吃到两种不同类的糖。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>candyType = [6,6,6,6]
<strong>输出：</strong>1
<strong>解释：</strong>Alice 只能吃 4 / 2 = 2 枚糖，尽管她能吃 2 枚，但只能吃到 1 种糖。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == candyType.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>n</code> 是一个偶数</li>
	<li><code>-10<sup>5</sup> &lt;= candyType[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：比较

限制Alice能吃到糖的种类的因素有两个：

1. 糖本身的种类——无论Alice使用什么策略都无法突破糖原本种类数的限制；
2. 糖的总个数——医生让她最多吃一半数量的糖。

因此最终答案为$\min(type, \frac{size}2)$

+ 时间复杂度$O(size)$
+ 空间复杂度$O(size)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> se(candyType.begin(), candyType.end());
        return min(se.size(), candyType.size() / 2);
    }
};
```

#### Go

```go
package main

func min(a int, b int) int {
    if a <= b {
        return a
    }
    return b
}

func distributeCandies(candyType []int) int {
    se := make(map[int]int)
    for _, t := range candyType {
        se[t] = 0
    }
    return min(len(se), len(candyType) / 2)
}
```

#### Java

```java
// import java.util.HashSet;
// import java.util.Set;

class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> se = new HashSet<>();
        for (int t : candyType) {
            se.add(t);
        }
        return Math.min(se.size(), candyType.length / 2);
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(set(candyType)), len(candyType) // 2)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/02/LeetCode%200575.%E5%88%86%E7%B3%96%E6%9E%9C/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139387726](https://letmefly.blog.csdn.net/article/details/139387726)
