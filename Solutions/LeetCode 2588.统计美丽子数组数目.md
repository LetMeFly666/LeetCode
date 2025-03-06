---
title: 2588.统计美丽子数组数目：前缀和 + 位运算(异或) + 哈希表
date: 2025-03-06 16:49:58
tags: [题解, LeetCode, 中等, 位运算, 数组, 哈希表, 哈希, map, 前缀和]
---

# 【LetMeFly】2588.统计美丽子数组数目：前缀和 + 位运算(异或) + 哈希表

力扣题目链接：[https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/](https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组<code>nums</code>&nbsp;。每次操作中，你可以：</p>

<ul>
	<li>选择两个满足&nbsp;<code>0 &lt;= i, j &lt; nums.length</code>&nbsp;的不同下标&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;。</li>
	<li>选择一个非负整数&nbsp;<code>k</code>&nbsp;，满足 <code>nums[i]</code>&nbsp;和 <code>nums[j]</code>&nbsp;在二进制下的第 <code>k</code>&nbsp;位（下标编号从 <strong>0</strong>&nbsp;开始）是 <code>1</code>&nbsp;。</li>
	<li>将 <code>nums[i]</code>&nbsp;和 <code>nums[j]</code>&nbsp;都减去&nbsp;<code>2<sup>k</sup></code>&nbsp;。</li>
</ul>

<p>如果一个子数组内执行上述操作若干次后，该子数组可以变成一个全为 <code>0</code>&nbsp;的数组，那么我们称它是一个 <strong>美丽</strong>&nbsp;的子数组。</p>

<p>请你返回数组 <code>nums</code>&nbsp;中 <strong>美丽子数组</strong>&nbsp;的数目。</p>

<p>子数组是一个数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [4,3,1,2,4]
<b>输出：</b>2
<b>解释：</b>nums 中有 2 个美丽子数组：[4,<em><strong>3,1,2</strong></em>,4] 和 [<em><strong>4,3,1,2,4</strong></em>] 。
- 按照下述步骤，我们可以将子数组 [3,1,2] 中所有元素变成 0 ：
  - 选择 [<em><strong>3</strong></em>, 1, <em><strong>2</strong></em>] 和 k = 1 。将 2 个数字都减去 2<sup>1</sup> ，子数组变成 [1, 1, 0] 。
  - 选择 [<em><strong>1</strong></em>, <em><strong>1</strong></em>, 0] 和 k = 0 。将 2 个数字都减去 2<sup>0</sup> ，子数组变成 [0, 0, 0] 。
- 按照下述步骤，我们可以将子数组 [4,3,1,2,4] 中所有元素变成 0 ：
  - 选择 [<em><strong>4</strong></em>, 3, 1, 2, <em><strong>4</strong></em>] 和 k = 2 。将 2 个数字都减去 2<sup>2</sup> ，子数组变成 [0, 3, 1, 2, 0] 。
  - 选择 [0, <em><strong>3</strong></em>, <em><strong>1</strong></em>, 2, 0] 和 k = 0 。将 2 个数字都减去 2<sup>0</sup> ，子数组变成 [0, 2, 0, 2, 0] 。
  - 选择 [0, <em><strong>2</strong></em>, 0, <em><strong>2</strong></em>, 0] 和 k = 1 。将 2 个数字都减去 2<sup>1</sup> ，子数组变成 [0, 0, 0, 0, 0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,10,4]
<b>输出：</b>0
<b>解释：</b>nums 中没有任何美丽子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

很不错的一道题。

## 解题方法：前缀和 + 位运算(异或) + 哈希表

> 二进制下：数组中每一位都出现偶数次`等价于`数组是美丽数组

每一位都出现偶数次？那不是说明数组中所有元素异或起来的结果为$0$吗？

> 任意进制下：数组中值异或结果为0`等价于`数组是美丽数组

类似前缀和的思想，我们使用一个变量$val$记录数组的前缀异或和。从前到后遍历数组，遍历过程中使用当前值异或val。

> 如果`0-4`的异或结果为`3`，`0-7`的异或结果也为`3`，就说明`5-7`的异或结果为0，说明`5-7`的子数组是美丽子数组。

我们只需要使用一个哈希表`times`统计每个异或结果的出现次数，再次出现`val`时，历史上前缀异或和为`val`的次数`times[val]`即为以当前元素为终端的美丽子数组的个数。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-06 16:13:50
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 16:32:08
 */
typedef long long ll;

class Solution {
private:
    unordered_map<int, int> times;
public:
    ll beautifulSubarrays(vector<int>& nums) {
        times[0] = 1;
        int val = 0;
        ll ans = 0;
        for (int t : nums) {
            val ^= t;
            ans += times[val];
            // printf("val = %d, times[%d] = %d, ans = %d\n", val, val, times[val], ans);  //*******
            times[val]++;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-06 16:35:13
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-06 16:36:59
'''
from typing import List
from collections import defaultdict

class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        times = defaultdict(int)
        times[0] = 1
        ans = val = 0
        for t in nums:
            val ^= t
            ans += times[val]
            times[val] += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-06 16:38:18
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 16:41:02
 */
import java.util.Map;
import java.util.HashMap;

class Solution {
    public long beautifulSubarrays(int[] nums) {
        Map<Integer, Integer> times = new HashMap<>();
        times.put(0, 1);
        long ans = 0;
        int val = 0;
        for (int t : nums) {
            val ^= t;
            int thisTime = times.getOrDefault(val, 0);
            ans += thisTime;
            times.put(val, ++thisTime);
        }
        return ans;
    }
}
```

#### Golang

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-06 16:46:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-06 16:46:39
 */
package main

func beautifulSubarrays(nums []int) (ans int64) {
    times := map[int]int{0: 1}
    val := 0
    for _, t := range nums {
        val ^= t
        ans += int64(times[val])
        times[val]++
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146075194)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/06/LeetCode%202588.%E7%BB%9F%E8%AE%A1%E7%BE%8E%E4%B8%BD%E5%AD%90%E6%95%B0%E7%BB%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
