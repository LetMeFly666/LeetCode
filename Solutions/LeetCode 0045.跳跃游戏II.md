---
title: 45.跳跃游戏 II：贪心（柳暗花明又一村）
date: 2025-01-27 07:59:38
tags: [题解, LeetCode, 中等, 贪心, 数组]
---

# 【LetMeFly】45.跳跃游戏 II：贪心（柳暗花明又一村）

力扣题目链接：[https://leetcode.cn/problems/jump-game-ii/](https://leetcode.cn/problems/jump-game-ii/)

<p>给定一个长度为 <code>n</code> 的 <strong>0 索引</strong>整数数组 <code>nums</code>。初始位置为 <code>nums[0]</code>。</p>

<p>每个元素 <code>nums[i]</code> 表示从索引 <code>i</code> 向前跳转的最大长度。换句话说，如果你在 <code>nums[i]</code> 处，你可以跳转到任意 <code>nums[i + j]</code> 处:</p>

<ul>
	<li><code>0 &lt;= j &lt;= nums[i]</code>&nbsp;</li>
	<li><code>i + j &lt; n</code></li>
</ul>

<p>返回到达&nbsp;<code>nums[n - 1]</code> 的最小跳跃次数。生成的测试用例可以到达 <code>nums[n - 1]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,3,1,1,4]
<strong>输出:</strong> 2
<strong>解释:</strong> 跳到最后一个位置的最小跳跃数是 <code>2</code>。
&nbsp;    从下标为 0 跳到下标为 1 的位置，跳&nbsp;<code>1</code>&nbsp;步，然后跳&nbsp;<code>3</code>&nbsp;步到达数组的最后一个位置。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,3,0,1,4]
<strong>输出:</strong> 2
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li>题目保证可以到达&nbsp;<code>nums[n-1]</code></li>
</ul>


    
## 解题思路

假设第一步从`0`可以跳到`1, 2, 3`这`3`个位置，那么第二步从这三个位置中的哪一个开始起跳？

> 当然是从哪个能跳更远，就从哪个开始跳。

然后问题就解决了。

## 解题方法：贪心

使用一个变量记录**上一步**能跳到的最远位置$nowMax$，使用另一个变量记录**这一步**能跳到的最远位置$nextMax$。

遍历jump数组，并不断更新“这一步能跳到的最远位置”。

如果当前下标和“上一步能跳到的最远位置相同”（例如第一步可以跳到`1, 2, 3`，现在遍历到下标`3`了，待会儿是第二步才能到达的起点了），就：跳跃次数加一，更新$nowMax$为$nextMax$。

## 时空复杂度分析

+ 时间复杂度$O(len(jump))
+ 空间复杂度$O(1)$

## AC代码

### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-27 07:44:31
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-27 07:47:14
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, nowMax = 0, nextMax = 0;
        for (int i = 0; i < nums.size() - 1; i++) {  // 注意这里的遍历范围
            nextMax = max(nextMax, i + nums[i]);
            if (nowMax == i) {
                ans++;  // 下一步还没跳，预先加了一步。所以已经跳到“目的位置前一个位置”就计算够了。
                nowMax = nextMax;
            }
        }
        return ans;
    }
};
```

### Python

```python
'''
Author: LetMeFly
Date: 2025-01-27 07:48:32
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-27 07:55:15
'''
from typing import List

class Solution:
    def jump(self, nums: List[int]) -> int:
        ans = nowMax = nextMax = 0
        for i, l in enumerate(nums[:-1]):
            nextMax = max(nextMax, i + l)
            if i == nowMax:
                nowMax = nextMax
                ans += 1
        return ans

if __name__ == '__main__':
    sol = Solution()
    ans = sol.jump([2, 3, 1, 1, 4])
    print(ans)
    assert ans == 2
```

### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-27 07:55:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-27 07:56:59
 */
class Solution {
    public int jump(int[] nums) {
        int ans = 0, nowMax = 0, nextMax = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            nextMax = Math.max(nextMax, i + nums[i]);
            if (i == nowMax) {
                nowMax = nextMax;
                ans++;
            }
        }
        return ans;
    }
}
```

### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-27 07:57:23
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-27 07:58:38
 */
package main

func jump(nums []int) (ans int) {
    var nowMax, nextMax int
    for i, l := range nums[:len(nums) - 1] {
        nextMax = max(nextMax, i + l)
        if nowMax == i {
            nowMax = nextMax
            ans++
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/27/LeetCode%200045.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8FII/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145374394](https://letmefly.blog.csdn.net/article/details/145374394)
