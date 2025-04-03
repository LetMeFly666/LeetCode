---
title: 2140.解决智力问题：记忆化搜索(DFS) / 动态规划(DP)
date: 2025-04-03 23:57:52
tags: [题解, LeetCode, 中等, 数组, 动态规划, 深度优先搜索, DFS, 记忆化搜索]
categories: [题解, LeetCode]
---

# 【LetMeFly】2140.解决智力问题：记忆化搜索(DFS) / 动态规划(DP)

力扣题目链接：[https://leetcode.cn/problems/solving-questions-with-brainpower/](https://leetcode.cn/problems/solving-questions-with-brainpower/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>questions</code>&nbsp;，其中&nbsp;<code>questions[i] = [points<sub>i</sub>, brainpower<sub>i</sub>]</code>&nbsp;。</p>

<p>这个数组表示一场考试里的一系列题目，你需要 <strong>按顺序</strong>&nbsp;（也就是从问题 <code>0</code><strong>&nbsp;</strong>开始依次解决），针对每个问题选择 <strong>解决</strong>&nbsp;或者 <strong>跳过</strong>&nbsp;操作。解决问题 <code>i</code>&nbsp;将让你 <b>获得</b>&nbsp;&nbsp;<code>points<sub>i</sub></code>&nbsp;的分数，但是你将 <strong>无法</strong>&nbsp;解决接下来的&nbsp;<code>brainpower<sub>i</sub></code>&nbsp;个问题（即只能跳过接下来的 <code>brainpower<sub>i</sub></code><sub>&nbsp;</sub>个问题）。如果你跳过问题&nbsp;<code>i</code>&nbsp;，你可以对下一个问题决定使用哪种操作。</p>

<ul>
	<li>比方说，给你&nbsp;<code>questions = [[3, 2], [4, 3], [4, 4], [2, 5]]</code>&nbsp;：

	<ul>
		<li>如果问题&nbsp;<code>0</code>&nbsp;被解决了， 那么你可以获得&nbsp;<code>3</code>&nbsp;分，但你不能解决问题&nbsp;<code>1</code> 和&nbsp;<code>2</code>&nbsp;。</li>
		<li>如果你跳过问题&nbsp;<code>0</code>&nbsp;，且解决问题&nbsp;<code>1</code>&nbsp;，你将获得 <code>4</code> 分但是不能解决问题&nbsp;<code>2</code> 和&nbsp;<code>3</code>&nbsp;。</li>
	</ul>
	</li>
</ul>

<p>请你返回这场考试里你能获得的 <strong>最高</strong>&nbsp;分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>questions = [[3,2],[4,3],[4,4],[2,5]]
<b>输出：</b>5
<b>解释：</b>解决问题 0 和 3 得到最高分。
- 解决问题 0 ：获得 3 分，但接下来 2 个问题都不能解决。
- 不能解决问题 1 和 2
- 解决问题 3 ：获得 2 分
总得分为：3 + 2 = 5 。没有别的办法获得 5 分或者多于 5 分。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
<b>输出：</b>7
<b>解释：</b>解决问题 1 和 4 得到最高分。
- 跳过问题 0
- 解决问题 1 ：获得 2 分，但接下来 2 个问题都不能解决。
- 不能解决问题 2 和 3
- 解决问题 4 ：获得 5 分
总得分为：2 + 5 = 7 。没有别的办法获得 7 分或者多于 7 分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= questions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>questions[i].length == 2</code></li>
	<li><code>1 &lt;= points<sub>i</sub>, brainpower<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法一：记忆化搜索

对于问题`i`：

+ 不选`i`则有：可以从`i + 1`开始选
+ 选择`i`则有：要从`i + questions[i][1] + 1`开始选

可以写一个DFS函数，`dfs(i)`表示问题`i`到问题`n - 1`的最大得分，则有：

+ 若i超过了`n`：`dfs(i) = 0`
+ 否则：`dfs(i) = max(dfs(i + 1), dfs(i + questions[i][1] + 1) + questions[i][0])`

### 时空复杂度分析

+ 时间复杂度$O(n)$，其中$n=len(questions)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:18:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:24:41
 */
typedef long long ll;

class Solution {
private:
    vector<vector<int>> q;
    unordered_map<int, ll> cache;

    ll dfs(int n) {
        if (n >= q.size()) {
            return 0;
        }
        if (cache.count(n)) {
            return cache[n];
        }
        return cache[n] = max(dfs(n + 1), dfs(n + q[n][1] + 1) + q[n][0]);
    }
public:
    ll mostPoints(vector<vector<int>>& questions) {
        q = move(questions);
        return dfs(0);
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-03 23:28:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-03 23:31:54
'''
from functools import cache
from typing import List


class Solution:
    @cache
    def dfs(self, i: int) -> int:
        if i >= len(self.q):
            return 0
        return max(self.dfs(i + 1), self.dfs(i + self.q[i][1] + 1) + self.q[i][0])

    def mostPoints(self, questions: List[List[int]]) -> int:
        self.q = questions
        return self.dfs(0)

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:32:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:38:01
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    private int[][] q;
    private Map<Integer, Long> cache = new HashMap<>();

    private long dfs(int i) {
        if (i >= q.length) {
            return 0;
        }
        if (cache.containsKey(i)) {
            return cache.get(i);
        }
        long ans = Math.max(dfs(i + 1), dfs(i + q[i][1] + 1) + q[i][0]);
        cache.put(i, ans);
        return ans;
    }

    public long mostPoints(int[][] questions) {
        q = questions;
        return dfs(0);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:39:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:46:51
 */
package main

var q [][]int
// var cache = make(map[int]int64)  // 不可！会被力扣多次调用
var cache map[int]int64  // 这里声明即可，每次在mostPoints时重新赋值

func dfs2140(i int) int64 {
    if i >= len(q) {
        return 0
    }
    if val, ok := cache[i]; ok {
        return val
    }
    ans := max(dfs2140(i + 1), dfs2140(i + q[i][1] + 1) + int64(q[i][0]))
    cache[i] = ans
    return ans
}

func mostPoints(questions [][]int) int64 {
    q = questions
    cache = make(map[int]int64)
    return dfs2140(0)
}
```
    
## 解题方法二：记忆化搜索

同样的：

对于问题`i`：

+ 不选`i`则有：可以从`i + 1`开始选，`dp[i] = dp[i + 1]`
+ 选择`i`则有：要从`i + questions[i][1] + 1`开始选，`dp[i] = dp[i + questions[i][1] + 1] + questions[i][0]`

倒序遍历即可。

### 时空复杂度分析

+ 时间复杂度$O(n)$，其中$n=len(questions)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 22:29:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:01:43
 */
typedef long long ll;

class Solution {
public:
    ll mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            int j = min(i + questions[i][1] + 1, n);
            dp[i] = max(dp[i + 1], dp[j] + questions[i][0]);
        }
        return dp[0];
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-03 23:48:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-03 23:49:25
'''
from typing import List

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            j = min(i + questions[i][1] + 1, n)
            dp[i] = max(dp[i + 1], dp[j] + questions[i][0])
        return dp[0]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:50:36
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:52:09
 */
class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length;
        long[] dp = new long[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            int j = Math.min(i + questions[i][1] + 1, n);
            dp[i] = Math.max(dp[i + 1], dp[j] + questions[i][0]);
        }
        return dp[0];
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-03 23:53:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-03 23:56:32
 */
package main

func mostPoints(questions [][]int) int64 {
    n := len(questions)
    dp := make([]int64, n + 1)
    for i := n - 1; i >= 0; i-- {
        j := min(i + questions[i][1] + 1, n)
        dp[i] = max(dp[i + 1], dp[j] + int64(questions[i][0]))
    }
    return dp[0]
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146991317)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/03/LeetCode%202140.%E8%A7%A3%E5%86%B3%E6%99%BA%E5%8A%9B%E9%97%AE%E9%A2%98/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
