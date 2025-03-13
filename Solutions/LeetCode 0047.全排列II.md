---
title: 47.全排列 II：内置函数 / 回溯（长篇小论）
date: 2025-02-06 14:28:35
tags: [题解, LeetCode, 中等, 数组, 回溯, 递归, 深度优先搜索, DFS, 全排列]
categories: [题解, LeetCode]
---

# 【LetMeFly】47.全排列 II：内置函数 / 回溯（长篇小论）

力扣题目链接：[https://leetcode.cn/problems/permutations-ii/](https://leetcode.cn/problems/permutations-ii/)

<p>给定一个可包含重复数字的序列 <code>nums</code> ，<em><strong>按任意顺序</strong></em> 返回所有不重复的全排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2]
<strong>输出：</strong>
[[1,1,2],
 [1,2,1],
 [2,1,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 8</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
</ul>


    
## 解题方法一：使用内置函数

### 解题思路

C++和Python都有全排列的内置函数，C++直接不生成重复的，Python去个重即可。

直接使用库函数不香么？

### 时空复杂度分析

+ 时间复杂度$O(n!)$，其中$n=len(nums)$
+ 空间复杂度：C++$O(\log n)$，Python$O(n!)$

其中C++单次调用`next_permutation`时间复杂度最坏$O(n)$，$n$个数的全排列最多$n!$种，$O(n\times n!) = O((n + 1)\times n!) = O((n + 1)!) = O(n!)$。

C++单次调用`next_permutation`的空间复杂度为$O(1)$，返回值不计入力扣空间复杂度。[1][cplusplus.com], [2][cpp-lang.net]

Python需要set等额外的中间变量来存放所有结果。

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:52:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 13:53:41
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-06 13:55:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-06 13:56:30
'''
from typing import List
from itertools import permutations

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return list(set(permutations(nums)))
```

## 解题方法二：回溯

### 解题思路

首先将`nums`数组排个序，使用一个数组记录哪个元素被选过，然后开始深搜回溯。

首先如果已选元素个数达到了$n$个，则说明生成了一种全排列方案，加入答案数组并返回。

否则开始遍历`nums`数组：

+ 如果当前元素被选过，或者当前元素和上一个元素相同且上一个元素没被选，则`continue`。（防止重复选择或重复方案）
+ 否则，选择当前元素并标记，递归，递归结束后移除当前元素并取消标记

### 时空复杂度分析

+ 时间复杂度$O(n!)$，其中$n=len(nums)$
+ 空间复杂度：C++$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:57:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 14:03:17
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    void dfs(int n, vector<vector<int>>& ans, vector<int>& now, vector<bool>& visited, vector<int>& nums) {
        if (n == nums.size()) {
            ans.push_back(now);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || i && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            now.push_back(nums[i]);
            visited[i] = true;
            dfs(n + 1, ans, now, visited, nums);
            visited[i] = false;
            now.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> now;
        vector<bool> visited(nums.size());
        sort(nums.begin(), nums.end());
        dfs(0, ans, now, visited, nums);
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-06 13:57:31
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-06 14:07:13
'''
from typing import List

class Solution:
    def dfs(self, n: int) -> None:
        if n == len(self.nums):
            self.ans.append([i for i in self.now])
            return
        for i in range(len(self.nums)):
            if self.visited[i] or i and self.nums[i] == self.nums[i - 1] and not self.visited[i - 1]:
                continue
            self.now.append(self.nums[i])
            self.visited[i] = True
            self.dfs(n + 1)
            self.visited[i] = False
            self.now.pop()
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.nums = sorted(nums)
        self.ans: List[List[int]] = []
        self.now: List[int] = []
        self.visited = [False] * len(nums)
        self.dfs(0)
        return self.ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:57:34
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 14:13:00
 */
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> now = new ArrayList<>();
    private int[] nums;
    private boolean[] visited;

    private void dfs(int n) {
        if (n == nums.length) {
            ans.add(new ArrayList<Integer>(now));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }
            now.add(nums[i]);
            visited[i] = true;
            dfs(n + 1);
            visited[i] = false;
            now.remove(now.size() - 1);
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        this.nums = nums;
        visited = new boolean[nums.length];
        dfs(0);
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-06 13:57:39
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-06 14:22:26
 */
package main

import "sort"

func dfs_P2(n int, ans *[][]int, now []int, visited []bool, nums []int) {
    if n == len(nums) {
        *ans = append(*ans, append(make([]int, 0), now...))
        return
    }
    for i := range nums {
        if visited[i] || i > 0 && nums[i] == nums[i - 1] && !visited[i - 1] {
            continue
        }
        now = append(now, nums[i])
        visited[i] = true
        dfs_P2(n + 1, ans, now, visited, nums)
        visited[i] = false
        now = now[:len(now) - 1]
    }
}

func permuteUnique(nums []int) (ans [][]int) {
    sort.Ints(nums)
    var now []int
    visited := make([]bool, len(nums))
    dfs_P2(0, &ans, now, visited, nums)
    return ans;
}
```

## End

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/06/LeetCode%200047.%E5%85%A8%E6%8E%92%E5%88%97II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145473834](https://letmefly.blog.csdn.net/article/details/145473834)

[cplusplus.com]: https://cplusplus.com/reference/algorithm/next_permutation/
[cpp-lang.net]: https://cpp-lang.net/docs/std/algo/ordinary/next_permutation/