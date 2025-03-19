---
title: 2610.转换二维数组：哈希表(一次遍历)
date: 2025-03-19 20:06:36
tags: [题解, LeetCode, 中等, 数组, 哈希表]
categories: [题解, LeetCode]
---

# 【LetMeFly】2610.转换二维数组：哈希表(一次遍历)

力扣题目链接：[https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/](https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/)

<p>给你一个整数数组 <code>nums</code> 。请你创建一个满足以下条件的二维数组：</p>

<ul>
	<li>二维数组应该 <strong>只</strong> 包含数组 <code>nums</code> 中的元素。</li>
	<li>二维数组中的每一行都包含 <strong>不同</strong> 的整数。</li>
	<li>二维数组的行数应尽可能 <strong>少</strong> 。</li>
</ul>

<p>返回结果数组。如果存在多种答案，则返回其中任何一种。</p>

<p>请注意，二维数组的每一行上可以存在不同数量的元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,4,1,2,3,1]
<strong>输出：</strong>[[1,3,4,2],[1,3],[1]]
<strong>解释：</strong>根据题目要求可以创建包含以下几行元素的二维数组：
- 1,3,4,2
- 1,3
- 1
nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
可以证明无法创建少于三行且符合题目要求的二维数组。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>[[4,3,2,1]]
<strong>解释：</strong>nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
</ul>


    
## 解题方法：哈希表

使用一个哈希表统计每个数出现的次数。

遍历nums数组，统计当前元素的出现次数。若当前元素的出现次数大于答案数组的长度，就向答案数组中添加一个空数组。最后，将当前元素t加入$ans[出现次数-1]$中。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 19:54:08
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 19:55:17
 */
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> cnt;
        for (int t : nums) {
            cnt[t]++;
            if (cnt[t] > ans.size()) {
                ans.push_back({});
            }
            ans[cnt[t] - 1].push_back(t);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-19 19:56:03
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-19 19:57:12
'''
from typing import List
from collections import defaultdict


class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        ans: List[List[int]] = []
        ma = defaultdict(int)
        for t in nums:
            ma[t] += 1
            if ma[t] > len(ans):
                ans.append([])
            ans[ma[t] - 1].append(t)
        return ans

```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 19:58:16
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 20:03:10
 */
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;


class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Map<Integer, Integer> ma = new HashMap<>();
        for (int t : nums) {
            ma.merge(t, 1, Integer::sum);
            if (ma.get(t) > ans.size()) {
                ans.add(new ArrayList<>());
            }
            ans.get(ma.get(t) - 1).add(t);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-19 20:03:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-19 20:05:02
 */
package main

func findMatrix(nums []int) (ans [][]int) {
    ma := map[int]int{}
    for _, t := range nums {
        ma[t]++
        if ma[t] > len(ans) {
            ans = append(ans, make([]int, 0))
        }
        ans[ma[t] - 1] = append(ans[ma[t]-1], t)
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146379435/)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/19/LeetCode%202610.%E8%BD%AC%E6%8D%A2%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
