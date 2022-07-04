---
title: 1200.最小绝对差
date: 2022-07-04 22:15:25
tags: [题解, LeetCode, 简单, 数组, 排序, 最小值]
---

# 【LetMeFly】1200.最小绝对差

力扣题目链接：[https://leetcode.cn/problems/minimum-absolute-difference/](https://leetcode.cn/problems/minimum-absolute-difference/)

<p>给你个整数数组&nbsp;<code>arr</code>，其中每个元素都 <strong>不相同</strong>。</p>

<p>请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,1,3]
<strong>输出：</strong>[[1,2],[2,3],[3,4]]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,3,6,10,15]
<strong>输出：</strong>[[1,3]]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [3,8,-10,23,19,-4,-14,27]
<strong>输出：</strong>[[-14,-10],[19,23],[23,27]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>-10^6 &lt;= arr[i] &lt;= 10^6</code></li>
</ul>


    
## 方法一：排序

这道题的数据范围是$10^5$，因此无法$O(n^2)$暴力

其实也不难，因为**排序后“最小绝对差的元素对”一定相邻**

所以我们直接排序即可，然后进行两次遍历

第一次求出绝对值只差的最小值，第二次把绝对值之差等于最小值的pair放入答案中即可。

+ 时间复杂度$O(n\log n)$，其中 $n$ 是数组 $\textit{arr}$ 的长度
+ 空间复杂度$O(\log n)$，皆为排序所至

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int m = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++) {
            m = min(m, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == m) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/04/LeetCode%201200.%E6%9C%80%E5%B0%8F%E7%BB%9D%E5%AF%B9%E5%B7%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125609898](https://letmefly.blog.csdn.net/article/details/125609898)
