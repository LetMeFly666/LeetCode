---
title: 881.救生艇
date: 2024-06-10 21:00:04
tags: [题解, LeetCode, 中等, 贪心, 数组, 双指针, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】881.救生艇：排序+双指针（大人掌船，能捎就捎）

力扣题目链接：[https://leetcode.cn/problems/boats-to-save-people/](https://leetcode.cn/problems/boats-to-save-people/)

<p>给定数组<meta charset="UTF-8" />&nbsp;<code>people</code>&nbsp;。<code>people[i]</code>表示第 <code>i</code><sup>&nbsp;</sup>个人的体重&nbsp;，<strong>船的数量不限</strong>，每艘船可以承载的最大重量为&nbsp;<code>limit</code>。</p>

<p>每艘船最多可同时载两人，但条件是这些人的重量之和最多为&nbsp;<code>limit</code>。</p>

<p>返回 <em>承载所有人所需的最小船数</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>people = [1,2], limit = 3
<strong>输出：</strong>1
<strong>解释：</strong>1 艘船载 (1, 2)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>people = [3,2,2,1], limit = 3
<strong>输出：</strong>3
<strong>解释：</strong>3 艘船分别载 (1, 2), (2) 和 (3)
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>people = [3,5,3,4], limit = 5
<strong>输出：</strong>4
<strong>解释：</strong>4 艘船分别载 (3), (3), (4), (5)</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= limit &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：排序+双指针

### 具体做法

首先对所有人按体重从低到高排序。

使用两个指针$l$和$r$分别指向数组的第一个和最后一个元素。

每次$r$指针向前移动一个元素（并且救生艇数量加一），另外的，若$r$指针移动前$people[l]+people[r]\leq lmit$，则$l$指针右移一个元素（相当于大人捎个小孩）。

### 为什么这么做

**为什么r指针每次都移动而l指针不一定移动？**

反正每个人都得坐船走，可以理解为先分配大人（每次r左移），若此大人还能捎带一个小孩儿，则就把这个小孩儿带走（此时l右移）。

**大人不应该带上“尽可能重的小孩”吗？**

第一反应是这样的。对于大人$people[r]$，是否应该带上满足$people[i]+people[r]\leq limit$的最大$i$而不是剩下所有小孩中最小的$l$呢？

其实带谁都一样。反正都是一个人头。此时$r$能带上“更重的小孩$i$”，那么待会儿“更轻的大人”也一定能带上小孩$i$。带$l$写起来简单，所以带$l$不带$i$。

### 时空复杂度分析

+ 时间复杂度$O(n\log n)$，其中$n=len(people)$
+ 空间复杂度$O(\log n)$

时空复杂度的来源主要是排序。

### AC代码

#### C++

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        for (int l = 0, r = people.size() - 1; l <= r; ans++, r--) {
            // 不用特判l是否等于r，因为不影响结果（若l=r则说明就剩一个人了，带不带那个“虚空影子”都无所谓）
            if (people[l] + people[r] <= limit) {
                l++;
            }
        }
        return ans;
    }
};
```

#### Go

```go
// package main

// import "sort"

func numRescueBoats(people []int, limit int) int {
    sort.Ints(people);
    ans := 0
    for l, r := 0, len(people) - 1; l <= r; ans, r = ans + 1, r - 1 {
        if people[l] + people[r] <= limit {
            l++;
        }
    }
    return ans
}
```

#### Java

```java
// import java.util.Arrays;

class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int ans = 0;
        for (int l = 0, r = people.length - 1; l <= r; ans++, r--) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
        }
        return ans;
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        ans = 0
        l, r = 0, len(people) - 1
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
            r -= 1
            ans += 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/10/LeetCode%200881.%E6%95%91%E7%94%9F%E8%89%87/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139582336](https://letmefly.blog.csdn.net/article/details/139582336)
