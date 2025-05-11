---
title: 1550.存在连续三个奇数的数组：遍历
date: 2025-05-11 14:25:21
tags: [题解, LeetCode, 简单, 数组, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】1550.存在连续三个奇数的数组：遍历

力扣题目链接：[https://leetcode.cn/problems/three-consecutive-odds/](https://leetcode.cn/problems/three-consecutive-odds/)

<p>给你一个整数数组 <code>arr</code>，请你判断数组中是否存在连续三个元素都是奇数的情况：如果存在，请返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,6,4,1]
<strong>输出：</strong>false
<strong>解释：</strong>不存在连续三个元素都是奇数的情况。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,2,34,3,4,5,7,23,12]
<strong>输出：</strong>true
<strong>解释：</strong>存在连续三个元素都是奇数的情况，即 [5,7,23] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：遍历

从第3个元素（下标2）开始向后遍历，若遇到连续3个奇数则直接返回true，否则返回false。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-11 14:00:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-11 14:13:46
 */
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2) {
                return true;
            }
        }
        return false;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-11 14:00:52
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-11 14:16:01
Description: AC,100.00%,93.48%
'''
from typing import List

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        for i in range(2, len(arr)):
            if arr[i] % 2 and arr[i - 1] % 2 and arr[i - 2] % 2:
                return True
        return False
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-11 14:00:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-11 14:17:39
 * @Description: 1550: AC,100.00%,88.19%
 */
class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        for (int i = 2; i < arr.length; i++) {
            if (arr[i] % 2 == 1 && arr[i - 1] % 2 == 1 && arr[i - 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-11 14:00:52
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-11 14:19:31
 */
package main

func threeConsecutiveOdds(arr []int) bool {
    for i := 2; i < len(arr); i++ {
        if arr[i] % 2 == 1 && arr[i - 1] % 2 == 1 && arr[i - 2] % 2 == 1 {
            return true
        }
    }
    return false;
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147872651)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/11/LeetCode%201550.%E5%AD%98%E5%9C%A8%E8%BF%9E%E7%BB%AD%E4%B8%89%E4%B8%AA%E5%A5%87%E6%95%B0%E7%9A%84%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
