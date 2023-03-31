---
title: 2367.算术三元组的数目
date: 2023-03-31 09:26:17
tags: [题解, LeetCode, 简单, 数组, 哈希表, 哈希, Set, 双指针, 三指针, 暴力, 枚举]
---

# 【LetMeFly】2367.算术三元组的数目

力扣题目链接：[https://leetcode.cn/problems/number-of-arithmetic-triplets/](https://leetcode.cn/problems/number-of-arithmetic-triplets/)

<p>给你一个下标从 <strong>0</strong> 开始、<strong>严格递增</strong> 的整数数组 <code>nums</code> 和一个正整数 <code>diff</code> 。如果满足下述全部条件，则三元组 <code>(i, j, k)</code> 就是一个 <strong>算术三元组</strong> ：</p>

<ul>
	<li><code>i &lt; j &lt; k</code> ，</li>
	<li><code>nums[j] - nums[i] == diff</code> 且</li>
	<li><code>nums[k] - nums[j] == diff</code></li>
</ul>

<p>返回不同 <strong>算术三元组</strong> 的数目<em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,4,6,7,10], diff = 3
<strong>输出：</strong>2
<strong>解释：</strong>
(1, 2, 4) 是算术三元组：7 - 4 == 3 且 4 - 1 == 3 。
(2, 4, 5) 是算术三元组：10 - 7 == 3 且 7 - 4 == 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [4,5,6,7,8,9], diff = 2
<strong>输出：</strong>2
<strong>解释：</strong>
(0, 2, 4) 是算术三元组：8 - 6 == 2 且 6 - 4 == 2 。
(1, 3, 5) 是算术三元组：9 - 7 == 2 且 7 - 5 == 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 200</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 200</code></li>
	<li><code>1 &lt;= diff &lt;= 50</code></li>
	<li><code>nums</code> <strong>严格</strong> 递增</li>
</ul>


    
## 方法一：暴力枚举

三层循环i、j、k，一旦$nums[i] + diff * 2 == nums[j] + diff == nums[k]$，就$ans++$

+ 时间复杂度$O(len(nums)^3)$
+ 空间复杂度$O(len(nums))$

## 方法二：哈希表

首先遍历一遍数组，将数组中的所有元素放入哈希表中

接着再遍历一次数组，如果$当前元素+diff$和$当前元素+2\times diff$都出现在了哈希表中，则$ans++$

（这样做得益于数组是递增的，因此只要满足$nums[i] + diff * 2 == nums[j] + diff == nums[k]$，就一定满足$i < j < k$）

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> se;
        for (int t : nums) {
            se.insert(t);
        }
        int ans = 0;
        for (int t : nums) {
            ans += se.count(t + diff) && se.count(t + 2 * diff);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        se = set()
        for t in nums:
            se.add(t)
        ans = 0
        for t in nums:
            ans += t + diff in se and t + 2 * diff in se
        return ans
```

## 方法三：三指针

三个指针i、j、k的初始值都是0

用指针k遍历数组，当$nums[j] + diff < nums[k]$时，指针j不断后移。如果移动到某个位置恰好$nums[j] + diff == nums[k]$，就以同样的方法移动指针i；否则（$nums[j] + diff > k$的话，就说明找不到合适的j，跳过这次循环，继续枚举下一个k）

移动指针i的方法同理：当$nums[i] + diff < nums[j]$时，指针i不断后移。如果正好$nums[i] + diff == nums[j]$，则$ans++$（能移动指针i就说明找到了合适的指针j的位置满足$nums[j] + diff == nums[k]$）

**问**：为什么遍历指针k，再寻找指针i和j，而不是遍历指针i，寻找指针j和k的位置呢？

答：因为数组递增且指针都是从小元素开始移动的，所以先移动最后一个指针k（最大），就不再需要判断指针i和指针j是否越界（最多移动到指针k的位置）。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        for (int i = 0, j = 0, k = 0; k < nums.size(); k++) {
            while (nums[j] + diff < nums[k]) {
                j++;
            }
            if (nums[j] + diff > nums[k]) {
                continue;
            }
            while (nums[i] + diff < nums[j]) {
                i++;
            }
            if (nums[i] + diff == nums[j]) {
                ans++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List


class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        ans, i, j = 0, 0, 0
        for k in range(len(nums)):
            while nums[j] + diff < nums[k]:
                j += 1
            if nums[j] + diff > nums[k]:
                continue
            while nums[i] + diff < nums[j]:
                i += 1
            if nums[i] + diff == nums[j]:
                ans += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2023/03/31/LeetCode%202367.%E7%AE%97%E6%9C%AF%E4%B8%89%E5%85%83%E7%BB%84%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129872479](https://letmefly.blog.csdn.net/article/details/129872479)
