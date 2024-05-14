---
title: 2244.完成所有任务需要的最少轮数
date: 2024-05-14 11:53:56
tags: [题解, LeetCode, 中等, 贪心, 数组, 哈希表, 计数]
---

# 【LetMeFly】2244.完成所有任务需要的最少轮数：贪心（计数）

力扣题目链接：[https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/](https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>tasks</code> ，其中 <code>tasks[i]</code> 表示任务的难度级别。在每一轮中，你可以完成 2 个或者 3 个 <strong>相同难度级别</strong> 的任务。</p>

<p>返回完成所有任务需要的 <strong>最少</strong> 轮数，如果无法完成所有任务，返回<em> </em><code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>tasks = [2,2,3,3,2,4,4,4,4,4]
<strong>输出：</strong>4
<strong>解释：</strong>要想完成所有任务，一个可能的计划是：
- 第一轮，完成难度级别为 2 的 3 个任务。 
- 第二轮，完成难度级别为 3 的 2 个任务。 
- 第三轮，完成难度级别为 4 的 3 个任务。 
- 第四轮，完成难度级别为 4 的 2 个任务。 
可以证明，无法在少于 4 轮的情况下完成所有任务，所以答案为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>tasks = [2,3,3]
<strong>输出：</strong>-1
<strong>解释：</strong>难度级别为 2 的任务只有 1 个，但每一轮执行中，只能选择完成 2 个或者 3 个相同难度级别的任务。因此，无法完成所有任务，答案为 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：计数（哈希表）

可以使用一个哈希表统计每个“难度”出现的次数。

对于某个任务：

> + 假设其一共出现了$1$次，则无法完成，直接返回$-1$。
> + 否则，假设出现了$n$次，则需要$\lceil\frac{n}{3}\rceil$轮次。

为什么$n\geq 2$时需要$\lceil\frac{n}{3}\rceil$轮？

> 因为贪心。每次能完成$2$个或$3$个，那当然是尽量完成$3$个。
>
> + 假设$n\mod 3=0$，则需要$\frac{n}{3}$轮
> + 假设$n\mod 3=1$，则需要$\lfloor\frac{n}{3}\rfloor-1$轮的$3$任务和$2$轮的$2$任务
> + 假设$n\mod 3=2$，则需要$\lfloor\frac{n}{3}\rfloor$轮的$3$任务和$1$轮的$2$任务

### 时空复杂度

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$，空间复杂度的主要来自哈希表

### AC代码

#### C++

```cpp
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> ma;
        for (int t : tasks) {
            ma[t]++;
        }
        int ans = 0;
        for (auto& [val, times] : ma) {
            if (times == 1) {
                return -1;
            }
            ans += (times + 2) / 3;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from collections import defaultdict

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        ma = defaultdict(int)
        for t in tasks:
            ma[t] += 1
        ans = 0
        for val, times in ma.items():
            if times == 1:
                return -1
            ans += (times + 2) // 3
        return ans
```

## 方法二：排序

和方法一思路相同，不同的是方法一中使用哈希表计数，方法二中使用排序。

将任务数组排个序，这样相同的任务就到一块了。

一次遍历即可得到“相同任务出现了几次”。

### 时空复杂度

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(\log n)$

相比于方法一，排序增加了时间复杂度，但降低了哈希表所需的空间复杂度。

## End

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/14/LeetCode%202244.%E5%AE%8C%E6%88%90%E6%89%80%E6%9C%89%E4%BB%BB%E5%8A%A1%E9%9C%80%E8%A6%81%E7%9A%84%E6%9C%80%E5%B0%91%E8%BD%AE%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138849002](https://letmefly.blog.csdn.net/article/details/138849002)
