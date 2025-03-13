---
title: 2766.重新放置石块
date: 2024-07-25 12:55:30
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, set, 排序, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2766.重新放置石块：哈希表

力扣题目链接：[https://leetcode.cn/problems/relocate-marbles/](https://leetcode.cn/problems/relocate-marbles/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，表示一些石块的初始位置。再给你两个长度<strong>&nbsp;相等</strong>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>moveFrom</code> 和&nbsp;<code>moveTo</code>&nbsp;。</p>

<p>在&nbsp;<code>moveFrom.length</code>&nbsp;次操作内，你可以改变石块的位置。在第&nbsp;<code>i</code>&nbsp;次操作中，你将位置在&nbsp;<code>moveFrom[i]</code>&nbsp;的所有石块移到位置&nbsp;<code>moveTo[i]</code>&nbsp;。</p>

<p>完成这些操作后，请你按升序返回所有 <strong>有</strong>&nbsp;石块的位置。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果一个位置至少有一个石块，我们称这个位置 <strong>有</strong>&nbsp;石块。</li>
	<li>一个位置可能会有多个石块。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,6,7,8], moveFrom = [1,7,2], moveTo = [2,9,5]
<b>输出：</b>[5,6,8,9]
<b>解释：</b>一开始，石块在位置 1,6,7,8 。
第 i = 0 步操作中，我们将位置 1 处的石块移到位置 2 处，位置 2,6,7,8 有石块。
第 i = 1 步操作中，我们将位置 7 处的石块移到位置 9 处，位置 2,6,8,9 有石块。
第 i = 2 步操作中，我们将位置 2 处的石块移到位置 5 处，位置 5,6,8,9 有石块。
最后，至少有一个石块的位置为 [5,6,8,9] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,3,3], moveFrom = [1,3], moveTo = [2,2]
<b>输出：</b>[2]
<b>解释：</b>一开始，石块在位置 [1,1,3,3] 。
第 i = 0 步操作中，我们将位置 1 处的石块移到位置 2 处，有石块的位置为 [2,2,3,3] 。
第 i = 1 步操作中，我们将位置 3 处的石块移到位置 2 处，有石块的位置为 [2,2,2,2] 。
由于 2 是唯一有石块的位置，我们返回 [2] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= moveFrom.length &lt;= 10<sup>5</sup></code></li>
	<li><code>moveFrom.length == moveTo.length</code></li>
	<li><code>1 &lt;= nums[i], moveFrom[i], moveTo[i] &lt;= 10<sup>9</sup></code></li>
	<li>测试数据保证在进行第&nbsp;<code>i</code>&nbsp;步操作时，<code>moveFrom[i]</code>&nbsp;处至少有一个石块。</li>
</ul>


    
## 解题方法：哈希表（集合）

使用一个哈希表（集合），记录每个石头的位置。

接着遍历每次操作，将moveFrom对应的石头在哈希表中移除，将moveTo对应的石头在哈希表中插入。

最终将哈希表中的元素放入一个列表中并排序返回。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> stones(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); i++) {
            stones.erase(moveFrom[i]);
            stones.insert(moveTo[i]);
        }
        vector<int> ans(stones.begin(), stones.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
package main

import "sort"


func relocateMarbles(nums []int, moveFrom []int, moveTo []int) []int {
    se := map[int]struct{}{}
    for _, x := range nums {
        se[x] = struct{}{}
    }
    for i := 0; i < len(moveFrom); i++ {
        delete(se, moveFrom[i])
        se[moveTo[i]] = struct{}{}
    }
    ans := make([]int, 0, len(se))
    for x := range se {
        ans = append(ans, x)
    }
    sort.Ints(ans)
    return ans
}
```

#### Java

```java
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        Set<Integer> se = new HashSet<>(nums.length);  // 预先分配空间，效率更高
        for (int t : nums) {
            se.add(t);
        }
        for (int i = 0; i < moveFrom.length; i++) {
            se.remove(moveFrom[i]);
            se.add(moveTo[i]);
        }
        List<Integer> ans = new ArrayList<>(se);
        Collections.sort(ans);
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        se = set(nums)
        for from_, to in zip(moveFrom, moveTo):
            se.remove(from_)
            se.add(to)
        return sorted(se)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/25/LeetCode%202766.%E9%87%8D%E6%96%B0%E6%94%BE%E7%BD%AE%E7%9F%B3%E5%9D%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140686910](https://letmefly.blog.csdn.net/article/details/140686910)
