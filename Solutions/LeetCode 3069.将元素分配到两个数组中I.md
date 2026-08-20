---
title: 3069.将元素分配到两个数组中 I：模拟
date: 2026-08-20 10:30:47
tags: [题解, LeetCode, 简单, 数组, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3069.将元素分配到两个数组中 I：模拟

力扣题目链接：[https://leetcode.cn/problems/distribute-elements-into-two-arrays-i/](https://leetcode.cn/problems/distribute-elements-into-two-arrays-i/)

<p>给你一个下标从 <strong>1</strong> 开始、包含<strong> 不同 </strong>整数的数组 <code>nums</code> ，数组长度为 <code>n</code> 。</p>

<p>你需要通过 <code>n</code> 次操作，将 <code>nums</code> 中的所有元素分配到两个数组 <code>arr1</code> 和 <code>arr2</code> 中。在第一次操作中，将 <code>nums[1]</code> 追加到 <code>arr1</code> 。在第二次操作中，将 <code>nums[2]</code> 追加到 <code>arr2</code> 。之后，在第 <code>i</code> 次操作中：</p>

<ul>
	<li>如果 <code>arr1</code> 的最后一个元素 <strong>大于 </strong><code>arr2</code> 的最后一个元素，就将 <code>nums[i]</code> 追加到 <code>arr1</code> 。否则，将 <code>nums[i]</code> 追加到 <code>arr2</code> 。</li>
</ul>

<p>通过连接数组 <code>arr1</code> 和 <code>arr2</code> 形成数组 <code>result</code> 。例如，如果 <code>arr1 == [1,2,3]</code> 且 <code>arr2 == [4,5,6]</code> ，那么 <code>result = [1,2,3,4,5,6]</code> 。</p>

<p>返回数组 <code>result</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>[2,3,1]
<strong>解释：</strong>在前两次操作后，arr1 = [2] ，arr2 = [1] 。
在第 3 次操作中，由于 arr1 的最后一个元素大于 arr2 的最后一个元素（2 &gt; 1），将 nums[3] 追加到 arr1 。
3 次操作后，arr1 = [2,3] ，arr2 = [1] 。
因此，连接形成的数组 result 是 [2,3,1] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,3,8]
<strong>输出：</strong>[5,3,4,8]
<strong>解释：</strong>在前两次操作后，arr1 = [5] ，arr2 = [4] 。
在第 3 次操作中，由于 arr1 的最后一个元素大于 arr2 的最后一个元素（5 &gt; 4），将 nums[3] 追加到 arr1 ，因此 arr1 变为 [5,3] 。
在第 4 次操作中，由于 arr2 的最后一个元素大于 arr1 的最后一个元素（4 &gt; 3），将 nums[4] 追加到 arr2 ，因此 arr2 变为 [4,8] 。
4 次操作后，arr1 = [5,3] ，arr2 = [4,8] 。
因此，连接形成的数组 result 是 [5,3,4,8] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code>中的所有元素都互不相同。</li>
</ul>


    
## 解题方法：模拟

创建两个数组，初始值分别是$nums$中的前两个元素。

之后从$nums$第三个元素开始向后遍历，添加到两个数组中最后一个元素较大的那个（数据保证不会等大）。

最后拼接两个数组并返回。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-20 10:14:33
 */
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1(1, nums[0]), v2(1, nums[1]);
        for (int i = 2, n = nums.size(); i < n; i++) {
            (v1.back() > v2.back() ? v1 : v2).push_back(nums[i]);
        }
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-08-20 10:28:27
'''
from typing import List

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        v1, v2 = [nums[0]], [nums[1]]
        for i in range(2, len(nums)):
            (v1 if v1[-1] > v2[-1] else v2).append(nums[i])
        return v1 + v2
```

#### Java

```java
/*
 * @LastEditTime: 2026-08-20 10:22:02
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> v1 = new ArrayList<>();
        List<Integer> v2 = new ArrayList<>();
        v1.add(nums[0]);
        v2.add(nums[1]);

        for (int i = 2, n = nums.length; i < n; i++) {
            (v1.getLast() > v2.getLast() ? v1 : v2).add(nums[i]);
        }
        v1.addAll(v2);
        return v1.stream().mapToInt(i -> i).toArray();
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-08-20 10:27:19
 */
package main

func resultArray(nums []int) []int {
    v1 := []int{nums[0]}
    v2 := []int{nums[1]}
    for i, n := 2, len(nums); i < n; i++ {
        if v1[len(v1)-1] > v2[len(v2)-1] {
            v1 = append(v1, nums[i])
        } else {
            v2 = append(v2, nums[i])
        }
    }
    v1 = append(v1, v2...)
    return v1
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-08-20 10:29:49
 */
impl Solution {
    pub fn result_array(nums: Vec<i32>) -> Vec<i32> {
        let mut v1 = vec![nums[0]];
        let mut v2 = vec![nums[1]];
        for &num in &nums[2..] {
            if v1[v1.len() - 1] > v2[v2.len() - 1] {
                v1.push(num);
            } else {
                v2.push(num);
            }
        }
        v1.extend(v2);
        v1
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163910126)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/20/LeetCode%203069.%E5%B0%86%E5%85%83%E7%B4%A0%E5%88%86%E9%85%8D%E5%88%B0%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E4%B8%ADI/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
