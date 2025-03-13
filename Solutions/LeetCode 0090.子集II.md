---
title: 90.子集 II：二进制枚举 / 回溯
date: 2025-02-05 12:44:00
tags: [题解, LeetCode, 中等, 位运算, 二进制枚举, 数组, 回溯]
categories: [题解, LeetCode]
---

# 【LetMeFly】90.子集 II：二进制枚举 / 回溯

力扣题目链接：[https://leetcode.cn/problems/subsets-ii/](https://leetcode.cn/problems/subsets-ii/)

<p>给你一个整数数组 <code>nums</code> ，其中可能包含重复元素，请你返回该数组所有可能的 <span data-keyword="subset">子集</span>（幂集）。</p>

<p>解集 <strong>不能</strong> 包含重复的子集。返回的解集中，子集可以按 <strong>任意顺序</strong> 排列。</p>

<div class="original__bRMd">
<div>
<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2]
<strong>输出：</strong>[[],[1],[1,2],[1,2,2],[2],[2,2]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>[[],[0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
</ul>
</div>
</div>



## 解题方法一：位运算（二进制枚举）

使用变量$state$从$0$枚举到$2 ^ n - 1$，其中$state$二进制下的每一位代表选择$nums[i]$或不选。

枚举之前先将$nums$排序，若当前选择方案不存在则加入答案数组中。

+ 时间复杂度$O(n\log n + n^2\times2^n)$，其中$n=len(nums)$
+ 空间复杂度$O(n)$，返回值不计入

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:22:09
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:24:34
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> thisAns;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) {
                    thisAns.push_back(nums[j]);
                }
            }
            if (find(ans.begin(), ans.end(), thisAns) == ans.end()) {
                ans.push_back(thisAns);
            }
        }
        return ans;
    }
};
```

## 解题方法二：回溯

类似[LeetCode 40.组合总和 II：回溯 + 剪枝](https://blog.letmefly.xyz/2025/01/26/LeetCode%200040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII/)，写一个`dfs`函数枚举选与不选两种情况。

+ 如果当前下标已越界，则将当前方案添加到答案数组中
+ 选当前元素时，将当前元素加入当前方案，递归，再将当前元素移除当前方案（回溯）
+ 不选当前元素时，如果下一个元素（下下个元素，...）和当前元素一样，那么也不能选。

以上。

+ 时间复杂度$O(n^\times2^n)$，其中$n=len(nums)$
+ 空间复杂度$O(n)$，返回值不计入

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:25:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:28:24
 */
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    void dfs(vector<int>& a, int loc) {
        if (loc == a.size()) {
            ans.push_back(now);
            return;
        }
        // 选当前
        now.push_back(a[loc]);
        dfs(a, loc + 1);
        now.pop_back();
        // 不选当前
        int next = loc + 1;
        while (next < a.size() && a[loc] == a[next]) {
            next++;
        }
        dfs(a, next);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-05 12:29:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-05 12:32:04
'''
from typing import List

class Solution:
    def dfs(self, loc: int) -> None:
        if loc == len(self.a):
            self.ans.append([i for i in self.now])
            return
        # 选当前
        self.now.append(self.a[loc])
        self.dfs(loc + 1)
        self.now.pop()
        # 不选当前
        next = loc + 1
        while next < len(self.a) and self.a[next] == self.a[loc]:
            next += 1
        self.dfs(next)
    
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        self.ans: List[List[int]] = []
        self.a = sorted(nums)
        self.now = []
        self.dfs(0)
        return self.ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:29:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:38:09
 */
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> now = new ArrayList<>();
    private int[] a;

    private void dfs(int loc) {
        if (loc == a.length) {
            ans.add(new ArrayList<>(now));
            return;
        }
        // 选当前
        now.add(a[loc]);
        dfs(loc + 1);
        now.remove(now.size() - 1);
        // 不选
        int next = loc + 1;
        while (next < a.length && a[next] == a[loc]) {
            next++;
        }
        dfs(next);
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        a = nums;
        dfs(0);
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-05 12:29:25
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-05 12:42:51
 */
package main

import "sort"

var (
    ans [][]int
    now,
    a []int
)

func dfs_S2(loc int) {
    if loc == len(a) {
        ans = append(ans, append([]int{}, now...))
        return
    }
    // 选
    now = append(now, a[loc])
    dfs_S2(loc + 1)
    now = now[:len(now) - 1]
    // 不选
    next := loc + 1
    for next < len(a) && a[next] == a[loc] {
        next++
    }
    dfs_S2(next)
}

func subsetsWithDup(nums []int) [][]int {
    ans = make([][]int, 0)
    now = make([]int, 0)
    sort.Ints(nums)
    a = nums
    dfs_S2(0)
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/05/LeetCode%200090.%E5%AD%90%E9%9B%86II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145453136](https://letmefly.blog.csdn.net/article/details/145453136)
