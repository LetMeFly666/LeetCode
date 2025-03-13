---
title: 303.区域和检索 - 数组不可变
date: 2024-03-18 10:10:10
tags: [题解, LeetCode, 简单, 设计, 数组, 前缀和]
categories: [题解, LeetCode]
---

# 【LetMeFly】303.区域和检索 - 数组不可变：前缀和（两行描述核心思路版本）

力扣题目链接：[https://leetcode.cn/problems/range-sum-query-immutable/](https://leetcode.cn/problems/range-sum-query-immutable/)

<p>给定一个整数数组 &nbsp;<code>nums</code>，处理以下类型的多个查询:</p>

<ol>
	<li>计算索引&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;（包含 <code>left</code> 和 <code>right</code>）之间的 <code>nums</code> 元素的 <strong>和</strong> ，其中&nbsp;<code>left &lt;= right</code></li>
</ol>

<p>实现 <code>NumArray</code> 类：</p>

<ul>
	<li><code>NumArray(int[] nums)</code> 使用数组 <code>nums</code> 初始化对象</li>
	<li><code>int sumRange(int i, int j)</code> 返回数组 <code>nums</code>&nbsp;中索引&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;之间的元素的 <strong>总和</strong> ，包含&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;两点（也就是&nbsp;<code>nums[left] + nums[left + 1] + ... + nums[right]</code>&nbsp;)</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
<strong>输出：
</strong>[null, 1, -1, -3]

<strong>解释：</strong>
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= nums[i] &lt;=&nbsp;10<sup>5</sup></code></li>
	<li><code>0 &lt;= i &lt;= j &lt; nums.length</code></li>
	<li>最多调用 <code>10<sup>4</sup></code> 次 <code>sumRange</code><strong> </strong>方法</li>
</ul>


    
## 方法一：前缀和

这道题唯一需要掌握的思路是：使用一个$prefix$数组，预处理使$prefix[i]=\sum_0^{i-1} nums[i]$。

这样，$\sum_{left}^{right}$就等于$prefix[right+1]-prefix[left]$了。

+ 时间复杂度：初始化$O(len(nums))$，查询$O(1)$每次 
+ 空间复杂度：$O(len(num))$，因为标题说“数组不可变”，否则直接修改原数组能把空间复杂度将为$O(1)$

### AC代码

#### C++

```cpp
class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
```

#### Python

```python
# from typing import List

class NumArray:

    def __init__(self, nums: List[int]):
        self.prefix = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            self.prefix[i + 1] = self.prefix[i] + nums[i]

    def sumRange(self, left: int, right: int) -> int:
        return self.prefix[right + 1] - self.prefix[left]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/18/LeetCode%200303.%E5%8C%BA%E5%9F%9F%E5%92%8C%E6%A3%80%E7%B4%A2-%E6%95%B0%E7%BB%84%E4%B8%8D%E5%8F%AF%E5%8F%98/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136801479](https://letmefly.blog.csdn.net/article/details/136801479)
