---
title: 3159.查询数组中元素的出现位置
date: 2024-12-27 12:26:15
tags: [题解, LeetCode, 中等, 数组, 哈希表, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3159.查询数组中元素的出现位置：存x下标

力扣题目链接：[https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array/](https://leetcode.cn/problems/find-occurrences-of-an-element-in-an-array/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，一个整数数组&nbsp;<code>queries</code>&nbsp;和一个整数&nbsp;<code>x</code>&nbsp;。</p>

<p>对于每个查询&nbsp;<code>queries[i]</code>&nbsp;，你需要找到&nbsp;<code>nums</code>&nbsp;中第&nbsp;<code>queries[i]</code>&nbsp;个&nbsp;<code>x</code>&nbsp;的位置，并返回它的下标。如果数组中&nbsp;<code>x</code>&nbsp;的出现次数少于&nbsp;<code>queries[i]</code>&nbsp;，该查询的答案为 -1 。</p>

<p>请你返回一个整数数组&nbsp;<code>answer</code>&nbsp;，包含所有查询的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,3,1,7], queries = [1,3,2,4], x = 1</span></p>

<p><span class="example-io"><b>输出：</b>[0,-1,2,-1]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第 1 个查询，第一个 1 出现在下标 0 处。</li>
	<li>第 2 个查询，<code>nums</code>&nbsp;中只有两个 1 ，所以答案为 -1 。</li>
	<li>第 3 个查询，第二个 1 出现在下标 2 处。</li>
	<li>第 4 个查询，<code>nums</code>&nbsp;中只有两个 1 ，所以答案为 -1 。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3], queries = [10], x = 5</span></p>

<p><span class="example-io"><b>输出：</b>[-1]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第 1 个查询，<code>nums</code>&nbsp;中没有 5 ，所以答案为 -1 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], x &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：模拟

首先遍历一遍`nums`数组，将`x`的下标存到`locs`数组中。

接着遍历`queries`数组，对于其中的一个`query`，如果`query > len(locs)`则查询结果为`-1`，否则查询结果为`locs[query - 1]`。

+ 时间复杂度$O(len(nums) + len(queries))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-27 12:13:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-27 12:14:52
 */
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> locs;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                locs.push_back(i);
            }
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = queries[i] > locs.size() ? -1 : locs[queries[i] - 1];
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-27 12:16:30
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-27 12:18:08
'''
from typing import List

class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        locs = [i for i in range(len(nums)) if nums[i] == x]
        return [-1 if q > len(locs) else locs[q - 1] for q in queries]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-27 12:18:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-27 12:20:43
 */
import java.util.ArrayList;

class Solution {
    public int[] occurrencesOfElement(int[] nums, int[] queries, int x) {
        ArrayList<Integer> locs = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == x) {
                locs.add(i);
            }
        }
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            if (queries[i] > locs.size()) {
                ans[i] = -1;
            } else {
                ans[i] = locs.get(queries[i] - 1);
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
 * @Date: 2024-12-27 12:22:32
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-27 12:23:51
 */
package main

func occurrencesOfElement(nums []int, queries []int, x int) []int {
    locs := make([]int, 0)
    for i, v := range nums {
        if v == x {
            locs = append(locs, i)
        }
    }
    ans := make([]int, 0)
    for _, q := range queries {
        if q > len(locs) {
            ans = append(ans, -1)
        } else {
            ans = append(ans, locs[q - 1])
        }
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/27/LeetCode%203159.%E6%9F%A5%E8%AF%A2%E6%95%B0%E7%BB%84%E4%B8%AD%E5%85%83%E7%B4%A0%E7%9A%84%E5%87%BA%E7%8E%B0%E4%BD%8D%E7%BD%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144765228](https://letmefly.blog.csdn.net/article/details/144765228)
