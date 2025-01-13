---
title: 2270.分割数组的方案数
date: 2025-01-13 22:40:27
tags: [题解, LeetCode, 中等, 数组, 前缀和]
---

# 【LetMeFly】2270.分割数组的方案数：前缀和

力扣题目链接：[https://leetcode.cn/problems/number-of-ways-to-split-array/](https://leetcode.cn/problems/number-of-ways-to-split-array/)

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。<br />
<span style="">如果以下描述为真，那么</span><span style=""> </span><code>nums</code>&nbsp;在下标 <code>i</code>&nbsp;处有一个 <strong>合法的分割</strong>&nbsp;：</p>

<ul>
	<li>前&nbsp;<code>i + 1</code>&nbsp;个元素的和 <strong>大于等于</strong>&nbsp;剩下的&nbsp;<code>n - i - 1</code>&nbsp;个元素的和。</li>
	<li>下标 <code>i</code>&nbsp;的右边 <strong>至少有一个</strong>&nbsp;元素，也就是说下标&nbsp;<code>i</code>&nbsp;满足&nbsp;<code>0 &lt;= i &lt; n - 1</code>&nbsp;。</li>
</ul>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中的&nbsp;<strong>合法分割</strong>&nbsp;方案数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [10,4,-8,7]
<b>输出：</b>2
<b>解释：</b>
总共有 3 种不同的方案可以将 nums 分割成两个非空的部分：
- 在下标 0 处分割 nums 。那么第一部分为 [10] ，和为 10 。第二部分为 [4,-8,7] ，和为 3 。因为 10 &gt;= 3 ，所以 i = 0 是一个合法的分割。
- 在下标 1 处分割 nums 。那么第一部分为 [10,4] ，和为 14 。第二部分为 [-8,7] ，和为 -1 。因为 14 &gt;= -1 ，所以 i = 1 是一个合法的分割。
- 在下标 2 处分割 nums 。那么第一部分为 [10,4,-8] ，和为 6 。第二部分为 [7] ，和为 7 。因为 6 &lt; 7 ，所以 i = 2 不是一个合法的分割。
所以 nums 中总共合法分割方案受为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,1,0]
<b>输出：</b>2
<b>解释：</b>
总共有 2 种 nums 的合法分割：
- 在下标 1 处分割 nums 。那么第一部分为 [2,3] ，和为 5 。第二部分为 [1,0] ，和为 1 。因为 5 &gt;= 1 ，所以 i = 1 是一个合法的分割。
- 在下标 2 处分割 nums 。那么第一部分为 [2,3,1] ，和为 6 。第二部分为 [0] ，和为 0 。因为 6 &gt;= 0 ，所以 i = 2 是一个合法的分割。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：前缀和

创建数组`prefix`其中`prefix[i]`的值为`nums[0] + nums[1] + ... + nums[i]`。这个数组我们遍历一遍即可得到。

再次用`i`从`0`到`len(nums) - 1`遍历数组，若`prefix[i] >= prefix[len(nums) - 1] - prefix[i]`，则说明`i`是一个合法分割点。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 22:28:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 22:31:22
 */
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans += prefix[i] >= prefix.back() - prefix[i];
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-13 22:32:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-13 22:33:53
'''
from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prefix = [0] * len(nums)
        prefix[0] = nums[0]
        for i in range(1, len(nums)):
            prefix[i] = prefix[i - 1] + nums[i]
        return sum(prefix[i] >= prefix[-1] - prefix[i] for i in range(len(nums) - 1))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-13 22:35:06
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 22:36:41
 */
class Solution {
    public int waysToSplitArray(int[] nums) {
        long[] prefix = new long[nums.length];
        prefix[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (prefix[i] >= prefix[nums.length - 1] - prefix[i]) {
                ans++;
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
 * @Date: 2025-01-13 22:37:03
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-13 22:39:18
 */
package main

func waysToSplitArray(nums []int) (ans int) {
    prefix := make([]int, len(nums))
    prefix[0] = nums[0]
    for i := 1; i < len(nums); i++ {
        prefix[i] = prefix[i - 1] + nums[i]
    }
    for i := 0; i < len(nums) - 1; i++ {
        if prefix[i] >= prefix[len(nums) - 1] - prefix[i] {
            ans++
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/13/LeetCode%202270.%E5%88%86%E5%89%B2%E6%95%B0%E7%BB%84%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145125736](https://letmefly.blog.csdn.net/article/details/145125736)
