---
title: 40.组合总和 II：回溯 + 剪枝
date: 2025-01-26 09:03:37
tags: [题解, LeetCode, 中等, 数组, 回溯, 深度优先搜索, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】40.组合总和 II：回溯 + 剪枝

力扣题目链接：[https://leetcode.cn/problems/combination-sum-ii/](https://leetcode.cn/problems/combination-sum-ii/)

<p>给定一个候选人编号的集合&nbsp;<code>candidates</code>&nbsp;和一个目标数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中所有可以使数字和为&nbsp;<code>target</code>&nbsp;的组合。</p>

<p><code>candidates</code>&nbsp;中的每个数字在每个组合中只能使用&nbsp;<strong>一次</strong>&nbsp;。</p>

<p><strong>注意：</strong>解集不能包含重复的组合。&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> candidates =&nbsp;<code>[10,1,2,7,6,1,5]</code>, target =&nbsp;<code>8</code>,
<strong>输出:</strong>
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> candidates =&nbsp;[2,5,2,1,2], target =&nbsp;5,
<strong>输出:</strong>
[
[1,2,2],
[5]
]</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;candidates.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;candidates[i] &lt;= 50</code></li>
	<li><code>1 &lt;= target &lt;= 30</code></li>
</ul>


    
## 解题方法：回溯（剪枝）

类似[39.组合总和：回溯 + 剪枝](https://blog.letmefly.xyz/2024/04/20/LeetCode%200039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C/)，但这道题比较困难的地方在于，`candidates`中有重复的元素，而答案中不能有重复的数组。

怎么办呢，排序呗。刚开始还和之前一样走正常流程：

1. 如果target已经达到则将当前方案加入答案数组。
2. 如果已超target则直接返回
3. 选当前元素并回溯
4. 不选当前元素

不同之处在于，不选当前元素时，要保证选择的下一个元素和当前元素不同。

> 例如`[4, 4, 5]`，不选第一个`4`的话，就不能选第二个`4`。
>
> 否则的话，可能会出现`第一个4和5`、`第二个4和5`这两种相同的方案。

+ 时间复杂度$O(len(candidates)^2)$
+ 空间复杂度$O(len(candidates))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-26 07:27:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-26 07:57:37
 */
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    void dfs(vector<int>& c, int target, int index) {
        // 组合成功
        if (!target) {
            ans.push_back(now);
            return;
        }
        // 不再可能
        if (index == c.size() || target < 0) {
            return;
        }
        // 选当前
        now.push_back(c[index]);
        dfs(c, target - c[index], index + 1);
        now.pop_back();
        // 不选当前递归下一个
        int next = index;
        while (++next < c.size() && c[next] == c[index]);
        dfs(c, target, next);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-26 07:58:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-26 08:01:59
'''
from typing import List

class Solution:
    def dfs(self, target: int, index: int) -> None:
        if not target:
            self.ans.append([i for i in self.now])
            return
        if index == len(self.c) or target < 0:
            return
        self.now.append(self.c[index])
        self.dfs(target - self.c[index], index + 1)
        self.now.pop()
        next = index + 1
        while next < len(self.c) and self.c[next] == self.c[index]:
            next += 1
        self.dfs(target, next)
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.c = candidates
        self.ans = []
        self.now = []
        self.dfs(target, 0)
        return self.ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-26 08:02:41
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-26 08:10:08
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private List<List<Integer>> ans;
    private List<Integer> now;
    private int[] c;

    private void dfs(int target, int index) {
        if (target == 0) {
            ans.add(new ArrayList<>(now));
            return;
        }
        if (index == c.length || target < 0) {
            return;
        }
        now.add(c[index]);
        dfs(target - c[index], index + 1);
        now.remove(now.size() - 1);
        int next = index;
        while (++next < c.length && c[next] == c[index]);
        dfs(target, next);
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        c = candidates;
        ans = new ArrayList<>();
        now = new ArrayList<>();
        dfs(target, 0);
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-26 08:47:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-26 09:01:49
 * @Descreption: AC,100.00%,34.12%
 */
package main

import "sort"

func dfs(c []int, target int, now []int, index int, ans *[][]int) {
    if target == 0 {
        *ans = append(*ans, append([]int{}, now...))
        return
    }
    if index == len(c) || target < 0 {
        return
    }
    now = append(now, c[index])
    dfs(c, target - c[index], now, index + 1, ans)
    now = now[:len(now) - 1]
    next := index + 1
    for next < len(c) && c[next] == c[index] {
        next++
    }
    dfs(c, target, now, next, ans)
}

func combinationSum2(candidates []int, target int) (ans [][]int) {
    var now []int
    sort.Ints(candidates)
    dfs(candidates, target, now, 0, &ans)
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/26/LeetCode%200040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145363298](https://letmefly.blog.csdn.net/article/details/145363298)
