---
title: 1287.有序数组中出现次数超过25%的元素：遍历
date: 2025-02-17 14:48:07
tags: [题解, LeetCode, 简单, 数组, 遍历]
---

# 【LetMeFly】1287.有序数组中出现次数超过25%的元素：遍历

力扣题目链接：[https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/](https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/)

<p>给你一个非递减的&nbsp;<strong>有序&nbsp;</strong>整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。</p>

<p>请你找到并返回这个整数</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,2,6,6,6,6,7,10]
<strong>输出：</strong>6
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^4</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^5</code></li>
</ul>


    
## 解题方法：遍历

对于长度为$n$的**有序**数组，对于一个首次出现下标为$i$的数：

> 整个数出现次数超过了$25\%$ **等价于** 下标$\lfloor\frac{n}{4}\rfloor+i$仍为这个数。

+ 时间复杂度$O(len(arr))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-17 14:38:51
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-17 14:42:26
 */
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int locDiff = arr.size() / 4;
        for (int i = 0; 1; i++) {
            if (arr[i] == arr[i + locDiff]) {
                return arr[i];
            }
        }
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-17 14:38:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-17 14:43:22
'''
from typing import List

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        locDiff = len(arr) // 4
        for i in range(len(arr)):
            if arr[i] == arr[i + locDiff]:
                return arr[i]
        return -1  # Fake Return
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-17 14:39:05
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-17 14:44:38
 */
class Solution {
    public int findSpecialInteger(int[] arr) {
        int locDiff = arr.length / 4;
        for (int i = 0; true; i++) {
            if (arr[i] == arr[i + locDiff]) {
                return arr[i];
            }
        }
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-17 14:39:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-17 14:47:00
 */
package main

func findSpecialInteger(arr []int) int {
    locDiff := len(arr) / 4
    for i := 0; true; i++ {
        if arr[i] == arr[i + locDiff] {
            return arr[i]
        }
    }
    return -1  // Fake Return - 及时上面是for true也需要return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145683090)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/17/LeetCode%201287.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E5%87%BA%E7%8E%B0%E6%AC%A1%E6%95%B0%E8%B6%85%E8%BF%8725%E7%9A%84%E5%85%83%E7%B4%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/17/LeetCode 1287.有序数组中出现次数超过25的元素](https://blog.letmefly.xyz/2025/02/17/LeetCode%201287.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E5%87%BA%E7%8E%B0%E6%AC%A1%E6%95%B0%E8%B6%85%E8%BF%8725%E7%9A%84%E5%85%83%E7%B4%A0/)
