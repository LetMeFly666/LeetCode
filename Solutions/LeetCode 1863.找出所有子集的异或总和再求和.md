---
title: 1863.找出所有子集的异或总和再求和：位运算（二进制枚举）
date: 2025-04-06 16:57:15
tags: [题解, LeetCode, 简单, 位运算, 数组, 枚举, 二进制枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】1863.找出所有子集的异或总和再求和：位运算（二进制枚举）

力扣题目链接：[https://leetcode.cn/problems/sum-of-all-subset-xor-totals/](https://leetcode.cn/problems/sum-of-all-subset-xor-totals/)

<p>一个数组的<strong> 异或总和</strong> 定义为数组中所有元素按位 <code>XOR</code> 的结果；如果数组为 <strong>空</strong> ，则异或总和为 <code>0</code> 。</p>

<ul>
	<li>例如，数组 <code>[2,5,6]</code> 的 <strong>异或总和</strong> 为 <code>2 XOR 5 XOR 6 = 1</code> 。</li>
</ul>

<p>给你一个数组 <code>nums</code> ，请你求出 <code>nums</code> 中每个 <strong>子集</strong> 的 <strong>异或总和</strong> ，计算并返回这些值相加之 <strong>和</strong> 。</p>

<p><strong>注意：</strong>在本题中，元素 <strong>相同</strong> 的不同子集应 <strong>多次</strong> 计数。</p>

<p>数组 <code>a</code> 是数组 <code>b</code> 的一个 <strong>子集</strong> 的前提条件是：从 <code>b</code> 删除几个（也可能不删除）元素能够得到 <code>a</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3]
<strong>输出：</strong>6
<strong>解释：</strong>[1,3] 共有 4 个子集：
- 空子集的异或总和是 0 。
- [1] 的异或总和为 1 。
- [3] 的异或总和为 3 。
- [1,3] 的异或总和为 1 XOR 3 = 2 。
0 + 1 + 3 + 2 = 6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,1,6]
<strong>输出：</strong>28
<strong>解释：</strong>[5,1,6] 共有 8 个子集：
- 空子集的异或总和是 0 。
- [5] 的异或总和为 5 。
- [1] 的异或总和为 1 。
- [6] 的异或总和为 6 。
- [5,1] 的异或总和为 5 XOR 1 = 4 。
- [5,6] 的异或总和为 5 XOR 6 = 3 。
- [1,6] 的异或总和为 1 XOR 6 = 7 。
- [5,1,6] 的异或总和为 5 XOR 1 XOR 6 = 2 。
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,4,5,6,7,8]
<strong>输出：</strong>480
<strong>解释：</strong>每个子集的全部异或总和值之和为 480 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 12</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 20</code></li>
</ul>


    
## 解题方法：二进制枚举

使用一个变量$i$从$0$到$2^{n}-1$枚举，其中$i$二进制下的每一位代表数组中每个元素的选与不选。

再用一层循环枚举每个数是否被选，异或所有本次被选择的数。

累加所有选择方案的异或结果即为所求。

+ 时间复杂度$O(n\times2^n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-05 22:38:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-06 14:25:36
 */
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 1 << nums.size(); i >= 0; i--) {
            int thisVal = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i >> j & 1) {
                    thisVal ^= nums[j];
                }
            }
            ans += thisVal;
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-06 16:17:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-06 16:17:54
'''
from typing import List

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ans = 0
        for i in range(1 << len(nums)):
            thisCnt = 0
            for j in range(len(nums)):
                if i >> j & 1:
                    thisCnt ^= nums[j]
            ans += thisCnt
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-06 16:31:30
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-06 16:33:16
 */
class Solution {
    public int subsetXORSum(int[] nums) {
        int ans = 0;
        for (int i = 0; i < 1 << nums.length; i++) {
            int thisCnt = 0;
            for (int j = 0; j < nums.length; j++) {
                if ((i >> j & 1) == 1) {
                    thisCnt ^= nums[j];
                }
            }
            ans += thisCnt;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-06 16:34:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-06 16:37:55
 */
package main

func subsetXORSum(nums []int) (ans int) {
    for i := 0; i < 1 << len(nums); i++ {
        thisCnt := 0
        for j := 0; j < len(nums); j++ {
            if i >> j & 1 == 1 {
                thisCnt ^= nums[j]
            }
        }
        ans += thisCnt
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147027120)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/06/LeetCode%201863.%E6%89%BE%E5%87%BA%E6%89%80%E6%9C%89%E5%AD%90%E9%9B%86%E7%9A%84%E5%BC%82%E6%88%96%E6%80%BB%E5%92%8C%E5%86%8D%E6%B1%82%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
