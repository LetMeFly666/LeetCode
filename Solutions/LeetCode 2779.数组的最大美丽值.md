---
title: 2779.数组的最大美丽值
date: 2024-06-15 19:17:40
tags: [题解, LeetCode, 中等, 数组, 二分查找, 排序, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】2779.数组的最大美丽值：排序 + 滑动窗口

力扣题目链接：[https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/](https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个 <strong>非负</strong> 整数 <code>k</code> 。</p>

<p>在一步操作中，你可以执行下述指令：</p>

<ul>
	<li>在范围&nbsp;<code>[0, nums.length - 1]</code> 中选择一个 <strong>此前没有选过</strong> 的下标 <code>i</code> 。</li>
	<li>将 <code>nums[i]</code> 替换为范围 <code>[nums[i] - k, nums[i] + k]</code> 内的任一整数。</li>
</ul>

<p>数组的 <strong>美丽值</strong> 定义为数组中由相等元素组成的最长子序列的长度。</p>

<p>对数组 <code>nums</code> 执行上述操作任意次后，返回数组可能取得的 <strong>最大</strong> 美丽值。</p>

<p><strong>注意：</strong>你 <strong>只</strong> 能对每个下标执行 <strong>一次</strong> 此操作。</p>

<p>数组的 <strong>子序列</strong> 定义是：经由原数组删除一些元素（也可能不删除）得到的一个新数组，且在此过程中剩余元素的顺序不发生改变。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,6,1,2], k = 2
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，我们执行下述操作：
- 选择下标 1 ，将其替换为 4（从范围 [4,8] 中选出），此时 nums = [4,4,1,2] 。
- 选择下标 3 ，将其替换为 4（从范围 [0,4] 中选出），此时 nums = [4,4,1,4] 。
执行上述操作后，数组的美丽值是 3（子序列由下标 0 、1 、3 对应的元素组成）。
可以证明 3 是我们可以得到的由相等元素组成的最长子序列长度。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1], k = 10
<strong>输出：</strong>4
<strong>解释：</strong>在这个示例中，我们无需执行任何操作。
数组 nums 的美丽值是 4（整个数组）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i], k &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：排序 + 滑动窗口

要求的是可以不连续的序列，因此每个元素的位置无关紧要，我们可以上来先对数组按从小到大的顺序排个序。

如果一个区间的数可以变地相同，那么这个区间的最大元素和最小元素之差不超过$2k$。

因此我们可以使用两个指针(滑动窗口)，$l$指向区间的左端点，$r$指向区间的右端点。每次$r$右移一位，若$nums[r]-nums[l]\gt2k$，则不断左移$l$指针。

区间“合法”后，更新区间的最大长度。最终区间的最大长度即为答案。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(), nums.end());
        k *= 2;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > k) {
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```

#### Go

```go
// package main

// import "sort"

func maximumBeauty(nums []int, k int) int {
    ans := 0
    sort.Ints(nums)
    k *= 2
    for l, r := 0, 0; r < len(nums); r++ {
        for ; nums[r] - nums[l] > k; {
            l++
        }
        if r - l + 1 > ans {
            ans = r - l + 1
        }
    }
    return ans
}
```

#### Java

```java
// import java.util.Arrays;
// import java.lang.Math;

class Solution {
    public int maximumBeauty(int[] nums, int k) {
        int ans = 0;
        Arrays.sort(nums);
        k *= 2;
        for (int l = 0, r = 0; r < nums.length; r++) {
            while (nums[r] - nums[l] > k) {
                l++;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        ans = 1
        nums.sort()
        k *= 2
        l = 0
        for r in range(len(nums)):
            while nums[r] - nums[l] > k:
                l += 1
            ans = max(ans, r - l + 1)
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/15/LeetCode%202779.%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E7%BE%8E%E4%B8%BD%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139707025](https://letmefly.blog.csdn.net/article/details/139707025)
