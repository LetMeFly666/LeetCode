---
title: 3396.使数组元素互不相同所需的最少操作次数：O(n)一次倒序遍历
date: 2025-04-08 23:29:15
tags: [题解, LeetCode, 简单, 数组, 哈希表, set, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】3396.使数组元素互不相同所需的最少操作次数：O(n)一次倒序遍历

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/](https://leetcode.cn/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/)

<p>给你一个整数数组 <code>nums</code>，你需要确保数组中的元素&nbsp;<strong>互不相同&nbsp;</strong>。为此，你可以执行以下操作任意次：</p>

<ul>
	<li>从数组的开头移除 3 个元素。如果数组中元素少于 3 个，则移除所有剩余元素。</li>
</ul>

<p><strong>注意：</strong>空数组也视作为数组元素互不相同。返回使数组元素互不相同所需的&nbsp;<strong>最少操作次数&nbsp;</strong>。<!-- notionvc: 210ee4f2-90af-4cdf-8dbc-96d1fa8f67c7 --></p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,2,3,4,2,3,3,5,7]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第一次操作：移除前 3 个元素，数组变为 <code>[4, 2, 3, 3, 5, 7]</code>。</li>
	<li>第二次操作：再次移除前 3 个元素，数组变为 <code>[3, 5, 7]</code>，此时数组中的元素互不相同。</li>
</ul>

<p>因此，答案是 2。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [4,5,6,4,4]</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>第一次操作：移除前 3 个元素，数组变为 <code>[4, 4]</code>。</li>
	<li>第二次操作：移除所有剩余元素，数组变为空。</li>
</ul>

<p>因此，答案是 2。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [6,7,8,9]</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>数组中的元素已经互不相同，因此不需要进行任何操作，答案是 0。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：遍历

只有一种删除重复元素的方式，就是把开头几个元素都删了。

删到多少为止呢？删到剩余元素全不同为止。

倒序遍历数组，使用一个哈希表记录遍历过程中出现的元素。若当前元素已经出现过，则至少从头删到当前元素。

当前下标为$i$到话，需要删多少次呢？需要删$\lceil\frac{i+1}3\rceil=\lfloor\frac{i}3\rfloor$次。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-08 21:52:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-08 21:54:03
 */
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> se;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (se.count(nums[i])) {
                return min((int)nums.size(), i / 3 + 1);
            }
            se.insert(nums[i]);
        }
        return 0;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-08 21:55:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-08 21:57:08
'''
from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        se = set()
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] in se:
                return i // 3 + 1
            se.add(nums[i])
        return 0
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-08 21:57:38
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-08 21:59:04
 */
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int minimumOperations(int[] nums) {
        Set<Integer> se = new HashSet<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            if (!se.add(nums[i])) {
                return i / 3 + 1;
            }
        }
        return 0;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-08 21:59:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-08 22:01:57
 */
package main

func minimumOperations(nums []int) int {
    se := map[int]struct{}{}
    for i := len(nums) - 1; i >= 0; i-- {
        if _, ok := se[nums[i]]; ok {
            return i / 3 + 1
        }
        se[nums[i]] = struct{}{}
    }
    return 0
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147080178)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/08/LeetCode%203396.%E4%BD%BF%E6%95%B0%E7%BB%84%E5%85%83%E7%B4%A0%E4%BA%92%E4%B8%8D%E7%9B%B8%E5%90%8C%E6%89%80%E9%9C%80%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
