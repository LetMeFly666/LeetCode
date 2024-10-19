---
title: 3192.使二进制数组全部等于 1 的最少操作次数 II
date: 2024-10-19 09:32:55
tags: [题解, LeetCode, 中等, 贪心, 数组, 动态规划, 位运算]
---

# 【LetMeFly】3192.使二进制数组全部等于 1 的最少操作次数 II：位运算模拟

力扣题目链接：[https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/](https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/)

<p>给你一个二进制数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以对数组执行以下操作&nbsp;<strong>任意</strong>&nbsp;次（也可以 0 次）：</p>

<ul>
	<li>选择数组中 <strong>任意</strong>&nbsp;一个下标 <code>i</code>&nbsp;，并将从下标 <code>i</code>&nbsp;开始一直到数组末尾 <strong>所有</strong>&nbsp;元素 <strong>反转</strong>&nbsp;。</li>
</ul>

<p><b>反转</b>&nbsp;一个元素指的是将它的值从 0 变 1 ，或者从 1 变 0 。</p>

<p>请你返回将 <code>nums</code>&nbsp;中所有元素变为 1 的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [0,1,1,0,1]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>选择下标&nbsp;<code>i = 1</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [0,<u><strong>0</strong></u>,<u><strong>0</strong></u>,<u><strong>1</strong></u>,<u><strong>0</strong></u>]</code>&nbsp;。</span></li>
	<li>选择下标&nbsp;<code>i = 0</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>0</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</span></li>
	<li>选择下标&nbsp;<code>i = 4</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [1,1,1,0,<u><strong>0</strong></u>]</code>&nbsp;。</span></li>
	<li>选择下标&nbsp;<code>i = 3</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [1,1,1,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</span></li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,0,0,0]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong><br />
我们可以执行以下操作：</p>

<ul>
	<li>选择下标&nbsp;<code>i = 1</code>&nbsp;执行操作，得到<span class="example-io">&nbsp;<code>nums = [1,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>&nbsp;。</span></li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>


    
## 解题方法：位运算模拟

类似于[LeetCode 3191.使二进制数组全部等于 1 的最少操作次数 I](https://blog.letmefly.xyz/2024/10/18/LeetCode%203191.%E4%BD%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E7%BB%84%E5%85%A8%E9%83%A8%E7%AD%89%E4%BA%8E1%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0I/)，本题也从前到后**模拟**，遇到0则翻转一次即可。

但是不用真的翻转，因为翻转偶数次相当于没有翻转，所以使用一个变量$original$记录是否未翻转即可。

**需要翻转 ⇔ (n XOR original)为true**

用$n$代表当前元素，$o$代表是否为原始值，则有：

|n|o|是否需要翻转|
|:--:|:--:|:--:|
|0|0|×|
|0|1|√|
|1|0|√|
|1|1|×|

**翻转只需要(original XOR= 1)**

一旦需要翻转，则original的值需要由0变1或1变0，也就是说original异或一个1即可。

**时空复杂度分析**

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
01101
10010
11101
11110
11111


n o
0 1 翻
0 0 不
1 1 不
1 0 翻
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, original = 1;
        for (int t : nums) {
            if (t ^ original) {
                ans++;
                original ^= 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main

func minOperations(nums []int) int {
    ans, original := 0, 1
    for _, t := range nums {
        if t ^ original == 1 {
            ans++
            original ^= 1
        }
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        int ans = 0, original = 1;
        for (int t : nums) {
            if ((t ^ original) == 1) {
                ans++;
                original ^= 1;
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans, original = 0, 1
        for t in nums:
            if t ^ original:
                ans += 1
                original ^= 1
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/19/LeetCode%203192.%E4%BD%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E7%BB%84%E5%85%A8%E9%83%A8%E7%AD%89%E4%BA%8E1%E7%9A%84%E6%9C%80%E5%B0%91%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143066863](https://letmefly.blog.csdn.net/article/details/143066863)
