---
title: 1299.将每个元素替换为右侧最大元素：倒序遍历，维护最大值，原地修改
date: 2025-02-16 10:28:29
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】1299.将每个元素替换为右侧最大元素：倒序遍历，维护最大值，原地修改

力扣题目链接：[https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/](https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side/)

<p>给你一个数组 <code>arr</code> ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 <code>-1</code> 替换。</p>

<p>完成所有替换操作后，请你返回这个数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [17,18,5,4,6,1]
<strong>输出：</strong>[18,6,6,6,1,-1]
<strong>解释：</strong>
- 下标 0 的元素 --> 右侧最大元素是下标 1 的元素 (18)
- 下标 1 的元素 --> 右侧最大元素是下标 4 的元素 (6)
- 下标 2 的元素 --> 右侧最大元素是下标 4 的元素 (6)
- 下标 3 的元素 --> 右侧最大元素是下标 4 的元素 (6)
- 下标 4 的元素 --> 右侧最大元素是下标 5 的元素 (1)
- 下标 5 的元素 --> 右侧没有其他元素，替换为 -1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [400]
<strong>输出：</strong>[-1]
<strong>解释：</strong>下标<strong> </strong>0 的元素右侧没有其他元素。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= arr[i] <= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：模拟

使用一个变量`M`记录右边元素最大值，初始值为`-1`。

从后向前遍历数组，使用`nextM`记录遍历完这个元素之后的最大值（`nextM = max(arr[i], M)`），更新这个元素为`M`，并更新`M`为`nextM`。

最终返回`arr`即为答案。

+ 时间复杂度$O(len(arr))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-02-16 10:21:04
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-16 10:22:18
 */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int M = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int nM = max(M, arr[i]);
            arr[i] = M;
            M = nM;
        }
        return arr;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-02-16 10:21:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-16 10:23:15
'''
from typing import List

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        M = -1
        for i in range(len(arr) - 1, -1, -1):
            arr[i], M = M, max(arr[i], M)
        return arr
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-02-16 10:21:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-16 10:24:13
 */
class Solution {
    public int[] replaceElements(int[] arr) {
        int M = -1;
        for (int i = arr.length - 1; i >= 0; i--) {
            int nM = Math.max(M, arr[i]);
            arr[i] = M;
            M = nM;
        }
        return arr;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-02-16 10:21:19
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-02-16 10:26:54
 */
package main

func max_REWGEORS(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func replaceElements(arr []int) []int {
    M := -1
    for i := len(arr) - 1; i >= 0; i-- {
        nM := max_REWGEORS(arr[i], M)
        arr[i] = M
        M = nM
    }
    return arr
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/145661909)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/02/16/LeetCode%201299.%E5%B0%86%E6%AF%8F%E4%B8%AA%E5%85%83%E7%B4%A0%E6%9B%BF%E6%8D%A2%E4%B8%BA%E5%8F%B3%E4%BE%A7%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
>
> Tisfy：[https://blog.letmefly.xyz/2025/02/16/LeetCode 1299.将每个元素替换为右侧最大元素/](https://blog.letmefly.xyz/2025/02/16/LeetCode%201299.%E5%B0%86%E6%AF%8F%E4%B8%AA%E5%85%83%E7%B4%A0%E6%9B%BF%E6%8D%A2%E4%B8%BA%E5%8F%B3%E4%BE%A7%E6%9C%80%E5%A4%A7%E5%85%83%E7%B4%A0/)
