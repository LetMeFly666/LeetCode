---
title: 1186.删除一次得到子数组最大和
date: 2024-07-22 09:17:18
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】1186.删除一次得到子数组最大和：动态规划

力扣题目链接：[https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/)

<p>给你一个整数数组，返回它的某个&nbsp;<strong>非空</strong> 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。</p>

<p>注意，删除一个元素后，子数组 <strong>不能为空</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,-2,0,3]
<strong>输出：</strong>4
<strong>解释：</strong>我们可以选出 [1, -2, 0, 3]，然后删掉 -2，这样得到 [1, 0, 3]，和最大。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,-2,-2,3]
<strong>输出：</strong>3
<strong>解释：</strong>我们直接选出 [3]，这就是最大和。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [-1,-1,-1,-1]
<strong>输出：</strong>-1
<strong>解释：</strong>最后得到的子数组不能为空，所以我们不能选择 [-1] 并从中删去 -1 来得到 0。
     我们应该直接选择 [-1]，或者选择 [-1, -1] 再从中删去一个 -1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：动态规划

遍历数组的同时使用两个变量记录一些信息：

1. `del0`表示以当前元素结尾的子数组的最大和
2. `del1`表示以当前元素结尾的(长度至少为2的)子数组删掉一个元素后的最大和

这样，在遍历过程中，我们就有转移方程：

1. `del1 = max(del1 + arr[i], del0)`：意思是之前已经删过一个了(del1)当前arr[i]不能再删了；或者之前没删过(del0)所以要删掉当前元素arr[i]（直接不加就好了）。
2. `del0 = max(del0 + arr[i], arr[i])`：意思是续上之前的子数组；或者从当前元素开始新开一个子数组。

整个遍历过程中，`del0`和`del1`的最大值，即为以任意一个元素为子数组结尾，删掉1个或0个元素后的最大和，也就是本题所求。

+ 时间复杂度$O(len(arr))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int del0 = arr[0], del1 = 0, ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            del1 = max(del0, del1 + arr[i]);
            del0 = max(del0 + arr[i], arr[i]);
            ans = max(ans, max(del0, del1));
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        del0, del1, ans = arr[0], 0, arr[0]
        for i in range(1, len(arr)):
            del1 = max(del1 + arr[i], del0)
            del0 = max(del0 + arr[i], arr[i])
            ans = max(ans, del0, del1)
        return ans
```

#### Java

```java
class Solution {
    public int maximumSum(int[] arr) {
        int del0 = arr[0], del1 = 0, ans = arr[0];
        for (int i = 1; i < arr.length; i++) {
            del1 = Math.max(del1 + arr[i], del0);
            del0 = Math.max(del0 + arr[i], arr[i]);
            ans = Math.max(ans, Math.max(del0, del1));
        }
        return ans;
    }
}
```

#### Go

```go
package main

func max2(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func max3(a int, b int, c int) int {
    return max2(a, max2(b, c))
}

func maximumSum(arr []int) int {
    del0, del1, ans := arr[0], 0, arr[0]
    for i := 1; i < len(arr); i++ {
        del1 = max2(del1 + arr[i], del0)
        del0 = max2(del0 + arr[i], arr[i])
        ans = max3(ans, del0, del1)
    }
    return ans
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/07/22/LeetCode%201186.%E5%88%A0%E9%99%A4%E4%B8%80%E6%AC%A1%E5%BE%97%E5%88%B0%E5%AD%90%E6%95%B0%E7%BB%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140601402](https://letmefly.blog.csdn.net/article/details/140601402)
