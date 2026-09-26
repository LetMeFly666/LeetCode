---
title: 3379.转换数组：下标取模
date: 2026-02-15 18:25:46
tags: [题解, LeetCode, 简单, 数组, 模拟, 模运算]
categories: [题解, LeetCode]
---

# 【LetMeFly】3379.转换数组：下标取模

力扣题目链接：[https://leetcode.cn/problems/transformed-array/](https://leetcode.cn/problems/transformed-array/)

<p>给你一个整数数组 <code>nums</code>，它表示一个循环数组。请你遵循以下规则创建一个大小&nbsp;<strong>相同&nbsp;</strong>的新数组 <code>result</code>&nbsp;：</p>
对于每个下标&nbsp;<code>i</code>（其中 <code>0 &lt;= i &lt; nums.length</code>），独立执行以下操作：

<ul>
	<li>如果 <code>nums[i] &gt; 0</code>：从下标&nbsp;<code>i</code> 开始，向&nbsp;<strong>右&nbsp;</strong>移动 <code>nums[i]</code> 步，在循环数组中落脚的下标对应的值赋给 <code>result[i]</code>。</li>
	<li>如果 <code>nums[i] &lt; 0</code>：从下标&nbsp;<code>i</code> 开始，向&nbsp;<strong>左&nbsp;</strong>移动 <code>abs(nums[i])</code> 步，在循环数组中落脚的下标对应的值赋给 <code>result[i]</code>。</li>
	<li>如果 <code>nums[i] == 0</code>：将 <code>nums[i]</code> 的值赋给 <code>result[i]</code>。</li>
</ul>

<p>返回新数组 <code>result</code>。</p>

<p><strong>注意：</strong>由于 <code>nums</code> 是循环数组，向右移动超过最后一个元素时将回到开头，向左移动超过第一个元素时将回到末尾。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [3,-2,1,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">[1,1,1,3]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>对于 <code>nums[0]</code> 等于 3，向右移动 3 步到 <code>nums[3]</code>，因此 <code>result[0]</code> 为 1。</li>
	<li>对于 <code>nums[1]</code> 等于 -2，向左移动 2 步到 <code>nums[3]</code>，因此 <code>result[1]</code> 为 1。</li>
	<li>对于 <code>nums[2]</code> 等于 1，向右移动 1 步到 <code>nums[3]</code>，因此 <code>result[2]</code> 为 1。</li>
	<li>对于 <code>nums[3]</code> 等于 1，向右移动 1 步到 <code>nums[0]</code>，因此 <code>result[3]</code> 为 3。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [-1,4,-1]</span></p>

<p><strong>输出：</strong> <span class="example-io">[-1,-1,4]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>对于 <code>nums[0]</code> 等于 -1，向左移动 1 步到 <code>nums[2]</code>，因此 <code>result[0]</code> 为 -1。</li>
	<li>对于 <code>nums[1]</code> 等于 4，向右移动 4 步到 <code>nums[2]</code>，因此 <code>result[1]</code> 为 -1。</li>
	<li>对于 <code>nums[2]</code> 等于 -1，向左移动 1 步到 <code>nums[1]</code>，因此 <code>result[2]</code> 为 4。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：下标取模

题目啥意思呢？题目意思是：令$result[i] = nums[i + nums[i]]$。

但是编程语言中数组$nums$可不是循环数组，所以需要将$i+nums[i]$映射到$0\sim n-1$（对于支持负数下标的编程语言python也可以映射为负数下标）。

$t$如何映射到$0\sim n-1$？$t\ \%\  n$可能为负数，再加上$n$再对$n$取模就好了。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(1)$，算法返回值不计入力扣空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-02-15 18:11:29
 */
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0, n = nums.size(); i < n; i++) {
            ans[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return ans;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-02-15 18:13:14
'''
from typing import List

class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        return [nums[(nums[i] + i) % len(nums)] for i in range(len(nums))]
```

#### Java

```java
/*
 * @LastEditTime: 2026-02-15 18:16:30
 */
class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int[] ans = new int[nums.length];
        for (int i = 0, n = nums.length; i < n; i++) {
            ans[i] = nums[((nums[i] + i) % n + n) % n];
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-02-15 18:15:07
 */
package main

func constructTransformedArray(nums []int) []int {
    ans := make([]int, len(nums))
    n := len(nums)
    for i, v := range nums {
        ans[i] = nums[((v + i) % n + n) % n]
    }
    return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-02-15 18:23:59
 */
impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;
        let mut ans = vec![0; n as usize];
        for i in 0..(n as usize) {
            let j = ((nums[i] + i as i32) % n + n) % n;  // 如果一路usize会无法得到负数
            ans[i] = nums[j as usize];
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/158101100)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/02/15/LeetCode%203379.%E8%BD%AC%E6%8D%A2%E6%95%B0%E7%BB%84/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
