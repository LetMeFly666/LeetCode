---
title: 3038.相同分数的最大操作数目 I
date: 2024-06-07 20:49:43
tags: [题解, LeetCode, 简单, 数组, 模拟]
---

# 【LetMeFly】3038.相同分数的最大操作数目 I

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i/](https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i/)

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，如果&nbsp;<code>nums</code>&nbsp;<strong>至少</strong>&nbsp;包含&nbsp;<code>2</code>&nbsp;个元素，你可以执行以下操作：</p>

<ul>
	<li>选择 <code>nums</code>&nbsp;中的前两个元素并将它们删除。</li>
</ul>

<p>一次操作的 <strong>分数</strong>&nbsp;是被删除元素的和。</p>

<p>在确保<strong>&nbsp;所有操作分数相同</strong>&nbsp;的前提下，请你求出 <strong>最多</strong>&nbsp;能进行多少次操作。</p>

<p>请你返回按照上述要求 <strong>最多</strong>&nbsp;可以进行的操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,1,4,5]
<b>输出：</b>2
<b>解释：</b>我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [1,4,5] 。
- 删除前两个元素，分数为 1 + 4 = 5 ，nums = [5] 。
由于只剩下 1 个元素，我们无法继续进行任何操作。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,6,1,4]
<b>输出：</b>1
<b>解释：</b>我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [6,1,4] 。
由于下一次操作的分数与前一次不相等，我们无法继续进行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 解题方法：遍历模拟

首先记录$nums[0] + nums[1]的值$（记为$val$），接着从下标$2$开始遍历数组（遍历时$i$每次＋2），如果相邻两个元素之和为$val$，则答案加一且遍历继续；否则遍历结束。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int ans = 1;
        int val = nums[0] + nums[1];
        for (int i = 2; i + 1< nums.size(); i += 2) {
            if (nums[i] + nums[i + 1] != val) {
                break;
            }
            ans++;
        }
        return ans;
    }
};
```

#### Go

```go
// package main

func maxOperations(nums []int) int {
    ans := 1
    val := nums[0] + nums[1]
    for i := 2; i < len(nums)-1; i += 2 {
        if nums[i]+nums[i+1] != val {
            break
        }
        ans++
    }
    return ans
}
```

#### Java

```java
class Solution {
    public int maxOperations(int[] nums) {
        int ans = 1;
        int val = nums[0] + nums[1];
        for (int i = 2; i < nums.length - 1; i += 2) {
            if (nums[i] + nums[i + 1] != val) {
                break;
            }
            ans++;
        }
        return ans;
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        ans = 1
        val = nums[0] + nums[1]
        for i in range(2, len(nums) - 1, 2):
            if nums[i] + nums[i + 1] != val:
                break
            ans += 1
        return ans
```

## End

这是在486/1920(px)宽度屏幕下写的题解。这是为什么呢？

```base64
5LuK5aSp5byA5aeL56uv5Y2I5pS+5YGH77yM5LqO5piv5bCx5pyJ5LqG5piO5pel6KaB5a6M5oiQ55qE56CU56m2546w54q25ZKM5LiL5LiL5ZGo5LqM6KaB5a6M5oiQ55qE5oqA5pyv6Lev57q/44CC44GE44GE44KT44GY44KD44Gq44GE44GLRG9nZSjotoXlpKfniYgpCg==
```

还是白色背景的VsCode和Word比较像。

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/07/LeetCode%203038.%E7%9B%B8%E5%90%8C%E5%88%86%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E6%93%8D%E4%BD%9C%E6%95%B0%E7%9B%AEI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139535702](https://letmefly.blog.csdn.net/article/details/139535702)
