---
title: 2293.极大极小游戏
date: 2023-01-15 08:42:11
tags: [题解, LeetCode, 简单, 数组, 模拟, 递归]
---

# 【LetMeFly】2293.极大极小游戏

力扣题目链接：[https://leetcode.cn/problems/min-max-game/](https://leetcode.cn/problems/min-max-game/)

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，其长度是 <code>2</code> 的幂。</p>

<p>对 <code>nums</code> 执行下述算法：</p>

<ol>
	<li>设 <code>n</code> 等于 <code>nums</code> 的长度，如果 <code>n == 1</code> ，<strong>终止</strong> 算法过程。否则，<strong>创建</strong> 一个新的整数数组&nbsp;<code>newNums</code> ，新数组长度为 <code>n / 2</code> ，下标从 <strong>0</strong> 开始。</li>
	<li>对于满足&nbsp;<code>0 &lt;= i &lt; n / 2</code> 的每个 <strong>偶数</strong> 下标 <code>i</code> ，将 <code>newNums[i]</code> <strong>赋值</strong> 为 <code>min(nums[2 * i], nums[2 * i + 1])</code> 。</li>
	<li>对于满足&nbsp;<code>0 &lt;= i &lt; n / 2</code> 的每个 <strong>奇数</strong> 下标 <code>i</code> ，将 <code>newNums[i]</code> <strong>赋值</strong> 为 <code>max(nums[2 * i], nums[2 * i + 1])</code> 。</li>
	<li>用 <code>newNums</code> 替换 <code>nums</code> 。</li>
	<li>从步骤 1 开始 <strong>重复</strong> 整个过程。</li>
</ol>

<p>执行算法后，返回 <code>nums</code> 中剩下的那个数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/04/13/example1drawio-1.png" style="width: 500px; height: 240px;" /></p>

<pre>
<strong>输入：</strong>nums = [1,3,5,2,4,8,2,2]
<strong>输出：</strong>1
<strong>解释：</strong>重复执行算法会得到下述数组。
第一轮：nums = [1,5,4,2]
第二轮：nums = [1,4]
第三轮：nums = [1]
1 是最后剩下的那个数字，返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3]
<strong>输出：</strong>3
<strong>解释：</strong>3 就是最后剩下的数字，返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1024</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums.length</code> 是 <code>2</code> 的幂</li>
</ul>


    
## 方法一：递归

如果数组nums中只有一个元素，那么直接返回这个元素就是答案。

否则，我们需要创建一个新的数组，将原始数组两两取最大最小后，添加到新的数组中。

这样操作后，我们就得到了新的数组。接下来，递归调用这个函数，计算新数组的再新数组，直到长度为1，直接返回数组中的唯一元素为止。

+ 时间复杂度$O(n)$，其中$n=len(nums)$。$O(n)+O(\frac{n}{2})+O(\frac{n}{4})+\cdots+O(1)=O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> newNum;
        int loc = 0;
        bool isMin = true;
        while (loc < nums.size()) {
            if (isMin) {
                newNum.push_back(min(nums[loc++], nums[loc++]));
                isMin = false;
            }
            else {
                newNum.push_back(max(nums[loc++], nums[loc++]));
                isMin = true;
            }
        }
        return minMaxGame(newNum);
    }
};
```

#### Python

```python
class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        newNum = []
        loc = 0
        isMin = True
        while loc < len(nums):
            if isMin:
                newNum.append(min(nums[loc], nums[loc + 1]))
                isMin = False
            else:
                newNum.append(max(nums[loc], nums[loc + 1]))
                isMin = True
            loc += 2
        return self.minMaxGame(newNum)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/15/LeetCode%202293.%E6%9E%81%E5%A4%A7%E6%9E%81%E5%B0%8F%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128691681](https://letmefly.blog.csdn.net/article/details/128691681)
