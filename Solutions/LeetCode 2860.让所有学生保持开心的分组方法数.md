---
title: 2860.让所有学生保持开心的分组方法数
date: 2024-09-04 21:48:27
tags: [题解, LeetCode, 中等, 数组, 枚举, 排序, 贪心, 遍历]
---

# 【LetMeFly】2860.让所有学生保持开心的分组方法数：排序+遍历

力扣题目链接：[https://leetcode.cn/problems/happy-students/](https://leetcode.cn/problems/happy-students/)

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> ，其中 <code>n</code> 是班级中学生的总数。班主任希望能够在让所有学生保持开心的情况下选出一组学生：</p>

<p>如果能够满足下述两个条件之一，则认为第 <code>i</code> 位学生将会保持开心：</p>

<ul>
	<li>这位学生被选中，并且被选中的学生人数 <strong>严格大于</strong> <code>nums[i]</code> 。</li>
	<li>这位学生没有被选中，并且被选中的学生人数 <strong>严格小于</strong> <code>nums[i]</code> 。</li>
</ul>

<p>返回能够满足让所有学生保持开心的分组方法的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>2
<strong>解释：</strong>
有两种可行的方法：
班主任没有选中学生。
班主任选中所有学生形成一组。 
如果班主任仅选中一个学生来完成分组，那么两个学生都无法保持开心。因此，仅存在两种可行的方法。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,0,3,3,6,7,2,7]
<strong>输出：</strong>3
<strong>解释：</strong>
存在三种可行的方法：
班主任选中下标为 1 的学生形成一组。
班主任选中下标为 1、2、3、6 的学生形成一组。
班主任选中所有学生形成一组。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
</ul>


    
## 解题方法：排序遍历

要选一个学生，那肯定是尽可能选值比较小的学生：

> 因为选中的学生要求“选中数”大于自己的值，选中的学生值越小越容易满足；
>
> 还因为未选中的学生要求“选中数”小于自己的值，未选中的学生值越大越容易满足。

所以按学生的值从小到大排个序，然后就能开始愉快地遍历学生了：

> 使用$i$从$1$到$n-1$遍历，代表选中前$i$个学生。
>
> 如果$i\gt nums[i - 1]$，则说明选中数大于选中学生的值；如果$i\lt nums[i]$，则说明选中数小于未选中学生的值。
>
> 如果二者同时满足，则可行方案数加一。

注意，上述遍历过程中未考虑全选或全不选的情况：

> 如果所有学生的值都大于$0$，则可以全不选；
>
> 因为没有学生的值大于等于学生个数，因此一定可以全选。

+ 时间复杂度$O(n\log n)$，其中$n=len(nums)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1 + (*min_element(nums.begin(), nums.end()) > 0);
        for (int i = 1; i < nums.size(); i++) {
            ans += i > nums[i - 1] && i < nums[i];
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def countWays(self, nums: List[int]) -> int:
        nums.sort()
        ans = 1 + (nums[0] != 0)
        for i in range(1, len(nums)):
            ans += i > nums[i - 1] and i < nums[i]
        return ans
```

#### Go

```go
package main
import "sort"

func countWays(nums []int) int {
    sort.Ints(nums)
    ans := 1
    if nums[0] > 0 {
        ans++
    }
    for i := 1; i < len(nums); i++ {
        if i > nums[i - 1] && i < nums[i] {
            ans++
        }
    }
    return ans
}
```

#### Java

```java
import java.util.List;
import java.util.Collections;

class Solution {
    public int countWays(List<Integer> nums) {
        Collections.sort(nums);
        int ans = 1 + (nums.get(0) > 0 ? 1 : 0);
        for (int i = 1; i < nums.size(); i++) {
            ans += i > nums.get(i - 1) && i < nums.get(i) ? 1 : 0;
        }
        return ans;
    }
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/04/LeetCode%202860.%E8%AE%A9%E6%89%80%E6%9C%89%E5%AD%A6%E7%94%9F%E4%BF%9D%E6%8C%81%E5%BC%80%E5%BF%83%E7%9A%84%E5%88%86%E7%BB%84%E6%96%B9%E6%B3%95%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/141905408](https://letmefly.blog.csdn.net/article/details/141905408)
