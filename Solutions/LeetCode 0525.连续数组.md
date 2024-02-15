---
title: 525.连续数组
date: 2022-11-22 14:40:16
tags: [题解, LeetCode, 中等, 数组, 哈希表, 哈希, 前缀和]
---

# 【LetMeFly】525.连续数组：哈希表 + 前缀和

力扣题目链接：[https://leetcode.cn/problems/contiguous-array/](https://leetcode.cn/problems/contiguous-array/)

<p>给定一个二进制数组 <code>nums</code> , 找到含有相同数量的 <code>0</code> 和 <code>1</code> 的最长连续子数组，并返回该子数组的长度。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [0,1]
<strong>输出:</strong> 2
<strong>说明:</strong> [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [0,1,0]
<strong>输出:</strong> 2
<strong>说明:</strong> [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 不是 <code>0</code> 就是 <code>1</code></li>
</ul>


    
## 方法一：哈希表 + 前缀和

为了方便，我们将$0$全部替换为$-1$

这样，“含有相同数量的$-1$、$1$的子数组”的元素之和就是$0$

我们计算这个数组的“前缀和”（类似于今天的上一题[523.连续的子数组和](https://blog.letmefly.xyz/2022/11/22/LeetCode%200523.%E8%BF%9E%E7%BB%AD%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84%E5%92%8C/)），在计算的过程中，我们将“首次得到这个前缀和结果的下标记录下来”。

例如：

```
原始数组：[1  0  0 1  0 1 1]
用-1替换：[1 -1 -1 1 -1 1 1]
求前缀和：[1  0 -1 0 -1 0 1]
          ↑              ↑
    第一次出现1      再一次出现1
```

来看前缀和为1的位置：

第一次前缀和为1的位置的下标为0，第二次前缀和为1的位置下标为6

这说明什么？这说明$nums[1] + nums[2] + nums[3] + nums[4] + nums[5] + nums[6] = 0$

$1$到$6$这$6$个元素的和为$0$，也就是说，$1$到$6$这$6$个元素中，$1$和$-1$的个数相等。

因此，我们找到了长度为“6”的“01相等的连续子数组”

我们用哈希表记录下“每个前缀和第一次得到的位置”，这样，在再次得到这个前缀和时，我们就“找到了01相等的子数组”

注意，哈希表中的初始值为$[0, -1]$，这是因为前缀和为$0$时，这个元素及其之前的所有元素的和为$0$，这些元素的个数为$i + 1 = i - (-1)$

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> ma;
        int cnt = 0;
        ma[0] = -1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                cnt++;
            else
                cnt--;
            if (ma.count(cnt)) {
                ans = max(ans, i - ma[cnt]);
            }
            else {
                ma[cnt] = i;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/11/22/LeetCode%200525.%E8%BF%9E%E7%BB%AD%E6%95%B0%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127982922](https://letmefly.blog.csdn.net/article/details/127982922)
