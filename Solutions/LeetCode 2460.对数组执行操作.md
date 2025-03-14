---
title: 2460.对数组执行操作
date: 2023-06-05 12:58:37
tags: [题解, LeetCode, 简单, 数组, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2460.对数组执行操作

力扣题目链接：[https://leetcode.cn/problems/apply-operations-to-an-array/](https://leetcode.cn/problems/apply-operations-to-an-array/)

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组大小为 <code>n</code> ，且由 <strong>非负</strong> 整数组成。</p>

<p>你需要对数组执行 <code>n - 1</code> 步操作，其中第 <code>i</code> 步操作（从 <strong>0</strong> 开始计数）要求对 <code>nums</code> 中第 <code>i</code> 个元素执行下述指令：</p>

<ul>
	<li>如果 <code>nums[i] == nums[i + 1]</code> ，则 <code>nums[i]</code> 的值变成原来的 <code>2</code> 倍，<code>nums[i + 1]</code> 的值变成 <code>0</code> 。否则，跳过这步操作。</li>
</ul>

<p>在执行完 <strong>全部</strong> 操作后，将所有 <code>0</code> <strong>移动</strong> 到数组的 <strong>末尾</strong> 。</p>

<ul>
	<li>例如，数组 <code>[1,0,2,0,0,1]</code> 将所有 <code>0</code> 移动到末尾后变为 <code>[1,2,1,0,0,0]</code> 。</li>
</ul>

<p>返回结果数组。</p>

<p><strong>注意</strong> 操作应当 <strong>依次有序</strong> 执行，而不是一次性全部执行。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,1,1,0]
<strong>输出：</strong>[1,4,2,0,0,0]
<strong>解释：</strong>执行以下操作：
- i = 0: nums[0] 和 nums[1] 不相等，跳过这步操作。
- i = 1: nums[1] 和 nums[2] 相等，nums[1] 的值变成原来的 2 倍，nums[2] 的值变成 0 。数组变成 [1,<em><strong>4</strong></em>,<em><strong>0</strong></em>,1,1,0] 。
- i = 2: nums[2] 和 nums[3] 不相等，所以跳过这步操作。
- i = 3: nums[3] 和 nums[4] 相等，nums[3] 的值变成原来的 2 倍，nums[4] 的值变成 0 。数组变成 [1,4,0,<em><strong>2</strong></em>,<em><strong>0</strong></em>,0] 。
- i = 4: nums[4] 和 nums[5] 相等，nums[4] 的值变成原来的 2 倍，nums[5] 的值变成 0 。数组变成 [1,4,0,2,<em><strong>0</strong></em>,<em><strong>0</strong></em>] 。
执行完所有操作后，将 0 全部移动到数组末尾，得到结果数组 [1,4,2,0,0,0] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>无法执行任何操作，只需要将 0 移动到末尾。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：模拟

首先我们可以直接模拟，如果连续两个元素相等，就将第一个元素置0，第二个元素二倍。

接着关于将非零元素移动到数组前：
+ 对于可变数组（如C++），我们可以使用一个指针指向非零元素填充到的位置，将剩余位置全部置0
+ 对于不可变数组（如Python），我们可以直接新开辟一个数组并将非零元素放入数组前方，其余元素用0补齐

End.

+ 时间复杂度$O(len(nums))$
+ 空间复杂度：对于可变数组的编程语言$O(1)$，对于不可变数组的编程语言$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        int loc = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                nums[loc++] = nums[i];
            }
        }
        while (loc < nums.size()) {
            nums[loc++] = 0;
        }
        return nums;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(0, len(nums) - 1):
            if nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
        ans = []
        for i in nums:
            if i:
                ans.append(i)
        ans += [0] * (len(nums) - len(ans))
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/05/LeetCode%202460.%E5%AF%B9%E6%95%B0%E7%BB%84%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131046033](https://letmefly.blog.csdn.net/article/details/131046033)
