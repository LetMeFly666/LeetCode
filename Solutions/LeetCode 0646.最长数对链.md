---
title: 646.最长数对链
date: 2022-09-03 21:03:16
tags: [题解, LeetCode, 中等, 贪心, 数组, 动态规划, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】646.最长数对链

力扣题目链接：[https://leetcode.cn/problems/maximum-length-of-pair-chain/](https://leetcode.cn/problems/maximum-length-of-pair-chain/)

<p>给出 <code>n</code> 个数对。 在每一个数对中，第一个数字总是比第二个数字小。</p>

<p>现在，我们定义一种跟随关系，当且仅当 <code>b < c</code> 时，数对<code>(c, d)</code> 才可以跟在 <code>(a, b)</code> 后面。我们用这种形式来构造一个数对链。</p>

<p>给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。</p>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>[[1,2], [2,3], [3,4]]
<strong>输出：</strong>2
<strong>解释：</strong>最长的数对链是 [1,2] -> [3,4]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>给出数对的个数在 <code>[1, 1000]</code> 范围内。</li>
</ul>


    
## 方法一：排序

对于一个数对，第一个数一定小于第二个数。

因此，最终的“最长数对链”中的所有元素一定是递增的。

要想让数对链最长，就要在 数对的第一个数大于前一个数对的第二个数 的前提下，数对的第二个数尽可能小。

因此，以第二个数为依据排序，越小的数越靠前。

之后遍历数对数组，如果当前数对的第一个数大于“上次的数对的第二个数”，那么就答案加一，并更新“上次的数对的第二个数”。

“上次的数对的第二个数”的初始值可为“极小值”。

+ 时间复杂度$O(n\log n)$，其中$n$是数对的个数
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 0;
        int lastEnd = INT_MIN;
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i][0] > lastEnd) {
                lastEnd = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/03/LeetCode%200646.%E6%9C%80%E9%95%BF%E6%95%B0%E5%AF%B9%E9%93%BE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126682589](https://letmefly.blog.csdn.net/article/details/126682589)
