---
title: 1295.统计位数为偶数的数字：模拟
date: 2025-04-30 17:33:51
tags: [题解, LeetCode, 简单, 数组, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1295.统计位数为偶数的数字：模拟

力扣题目链接：[https://leetcode.cn/problems/find-numbers-with-even-number-of-digits/](https://leetcode.cn/problems/find-numbers-with-even-number-of-digits/)

<p>给你一个整数数组&nbsp;<code>nums</code>，请你返回其中位数为&nbsp;<strong>偶数</strong>&nbsp;的数字的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [12,345,2,6,7896]
<strong>输出：</strong>2
<strong>解释：
</strong>12 是 2 位数字（位数为偶数）&nbsp;
345 是 3 位数字（位数为奇数）&nbsp;&nbsp;
2 是 1 位数字（位数为奇数）&nbsp;
6 是 1 位数字 位数为奇数）&nbsp;
7896 是 4 位数字（位数为偶数）&nbsp;&nbsp;
因此只有 12 和 7896 是位数为偶数的数字
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [555,901,482,1771]
<strong>输出：</strong>1 
<strong>解释： </strong>
只有 1771 是位数为偶数的数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法一：正常模拟

如何判断一个(非负)数在十进制下有多少位？

> 当这个数不为0时拿这个数不断除以10，并将“数字位数”加一。

依次计算每个元素的位数，判断是否是偶数。

### 时空复杂度分析

+ 时间复杂度$O(len(nums)\times \log nums[i])$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 17:23:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:25:14
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    inline int getLength(int t) {
        int ans = 0;
        while (t) {
            ans++;
            t /= 10;
        }
        return ans;
    }
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            ans += getLength(t) % 2 == 0;
        }
        return ans;
    }
};
```


#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-30 17:24:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-30 17:26:24
'''
from typing import List

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(len(str(t)) % 2 == 0 for t in nums)
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 17:24:37
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:27:07
 */
class Solution {
    private int getLength(int t) {
        int ans = 0;
        while (t > 0) {
            ans++;
            t /= 10;
        }
        return ans;
    }
    public int findNumbers(int[] nums) {
        int ans = 0;
        for (int t : nums) {
            if (getLength(t) % 2 == 0) {
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
 * @Date: 2025-04-30 17:24:40
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:28:26
 */
func findNumbers(nums []int) (ans int) {
    for _, t := range nums {
		cnt := 0
		for t > 0 {
			cnt++
			t /= 10
		}
		if cnt % 2 == 0 {
			ans++
		}
	}
	return
}
```

## 解题方法二：一次移除两位

方法一中我们将元素一次除以10（移除元素的一位），但是问题求的是“元素位数是否为偶数”，那么我们为什么不可以在元素位数大于等于2的时候，一次移除两位呢？最后看元素剩下一位还是零位不就知道元素十进制下的位数是奇数还是偶数了吗。

### 时空复杂度分析

+ 时间复杂度$O(len(nums)\times \log nums[i])$
+ 空间复杂度$O(1)$

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-30 17:30:12
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-30 17:30:19
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int t : nums) {
            while (t >= 10) {
                t /= 100;
            }
            ans += t == 0;
        }
        return ans;
    }
};
```


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147637587)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/30/LeetCode%201295.%E7%BB%9F%E8%AE%A1%E4%BD%8D%E6%95%B0%E4%B8%BA%E5%81%B6%E6%95%B0%E7%9A%84%E6%95%B0%E5%AD%97/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
