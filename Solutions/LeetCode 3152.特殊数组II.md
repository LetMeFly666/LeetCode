---
title: 3152.特殊数组 II
date: 2024-08-14 23:46:15
tags: [题解, LeetCode, 中等, 数组, 二分查找, 前缀和]
---

# 【LetMeFly】3152.特殊数组 II：前缀和 - 原地修改（大概可视为O(1)空间）

力扣题目链接：[https://leetcode.cn/problems/special-array-ii/](https://leetcode.cn/problems/special-array-ii/)

<p>如果数组的每一对相邻元素都是两个奇偶性不同的数字，则该数组被认为是一个 <strong>特殊数组</strong> 。</p>

<p>周洋哥有一个整数数组 <code>nums</code> 和一个二维整数矩阵 <code>queries</code>，对于 <code>queries[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>，请你帮助周洋哥检查子数组 <code>nums[from<sub>i</sub>..to<sub>i</sub>]</code> 是不是一个 <strong>特殊数组 </strong>。</p>

<p>返回布尔数组 <code>answer</code>，如果 <code>nums[from<sub>i</sub>..to<sub>i</sub>]</code> 是特殊数组，则 <code>answer[i]</code> 为 <code>true</code> ，否则，<code>answer[i]</code> 为 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,4,1,2,6], queries = [[0,4]]</span></p>

<p><strong>输出：</strong><span class="example-io">[false]</span></p>

<p><strong>解释：</strong></p>

<p>子数组是 <code>[3,4,1,2,6]</code>。2 和 6 都是偶数。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [4,3,1,6], queries = [[0,2],[2,3]]</span></p>

<p><strong>输出：</strong><span class="example-io">[false,true]</span></p>

<p><strong>解释：</strong></p>

<ol>
	<li>子数组是 <code>[4,3,1]</code>。3 和 1 都是奇数。因此这个查询的答案是 <code>false</code>。</li>
	<li>子数组是 <code>[1,6]</code>。只有一对：<code>(1,6)</code>，且包含了奇偶性不同的数字。因此这个查询的答案是 <code>true</code>。</li>
</ol>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt;= nums.length - 1</code></li>
</ul>


    
## 解题方法：前缀和

因为要多次查询a到b区间是否有奇偶性不同的元素，所以很自然地想到前缀和。

前缀和的原数组$origin$长这个样：

> + 如果$nums[i]$和$nums[i + 1]$奇偶性相同，则$origin[i] = 1$；
> + 否则$origin[i] = 0$。

前缀和数组$prefix$长这个样：

> + $prefix[i]$为$nums$前$i$个元素的和。（前$0$个元素的和记为$0$）

那么，如果$prefix[b] - prefix[a]$为$0$，则说明$nums[a]$到$nums[b]$奇偶性全相同；否则说明有奇偶性不相同的相邻元素的存在。

+ 时间复杂度$O(len(nums) + len(queries))$
+ 空间复杂度$O(1)$：可以做到原地修改数组，力扣算法的返回值又不计入算法的空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            bool same = nums[i] % 2 == nums[i + 1] % 2;
            nums[i] = cnt;
            cnt += same;
        }
        nums.back() = cnt;
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = nums[queries[i][1]] == nums[queries[i][0]];
        }
        return ans;
    }
};
```

#### Go

```go
package main

func isArraySpecial(nums []int, queries [][]int) []bool {
    cnt := 0
    for i := 0; i < len(nums) - 1; i++ {
        same := nums[i] % 2 == nums[i + 1] % 2
        nums[i] = cnt
        if same {
            cnt++
        }
    }
    nums[len(nums) - 1] = cnt
    ans := make([]bool, len(queries))
    for i, q := range queries {
        ans[i] = nums[q[0]] == nums[q[1]]
    }
    return ans
}
```

#### Java

```java
class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int cnt = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            boolean same = nums[i] % 2 == nums[i + 1] % 2;
            nums[i] = cnt;
            cnt += same ? 1 : 0;
        }
        nums[nums.length - 1] = cnt;
        boolean[] ans = new boolean[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = nums[queries[i][0]] == nums[queries[i][1]];
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        cnt = 0
        for i in range(len(nums) - 1):
            same = nums[i] % 2 == nums[i + 1] % 2
            nums[i] = cnt
            cnt += same
        nums[-1] = cnt
        return [nums[a] == nums[b] for a, b in queries]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/08/14/LeetCode%203152.%E7%89%B9%E6%AE%8A%E6%95%B0%E7%BB%84II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141203073](https://letmefly.blog.csdn.net/article/details/141203073)
