---
title: 907.子数组的最小值之和
date: 2023-11-27 18:40:38
tags: [题解, LeetCode, 中等, 栈, 数组, 动态规划, 单调栈]
---

# 【LetMeFly】907.子数组的最小值之和：单调栈

力扣题目链接：[https://leetcode.cn/problems/sum-of-subarray-minimums/](https://leetcode.cn/problems/sum-of-subarray-minimums/)

<p>给定一个整数数组 <code>arr</code>，找到 <code>min(b)</code> 的总和，其中 <code>b</code> 的范围为 <code>arr</code> 的每个（连续）子数组。</p>

<p>由于答案可能很大，因此<strong> 返回答案模 <code>10^9 + 7</code></strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,1,2,4]
<strong>输出：</strong>17
<strong>解释：
</strong>子数组为<strong> </strong>[3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [11,81,94,43,3]
<strong>输出：</strong>444
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>1 <= arr[i] <= 3 * 10<sup>4</sup></code></li>
</ul>

<p> </p>


    
## 方法一：单调栈

要求的是： 每个元素 ✖ 这个元素及左边数个元素的个数 ✖ 这个元素及右边数个元素的个数。

左边右边到哪里为止呢？到小于这个元素的元素位置的前一个位置。

好了，怎么确定左右两边小于这个元素的位置呢？使用一个单调递增的单调栈即可。

栈中存放数组的下标，保证每个下标在数组中对应的元素是单调递增的。

遍历数组，当当前元素小于栈顶元素时，不断将栈顶元素弹出。诶，被弹出的这个元素的“左右到达位置不就确定了吗？”

被弹出元素右边到达的位置即为当前元素的前一个元素，被弹出元素左边到达的位置即为这个元素在栈中的下一个元素（不包含）。

为了方便，可以在初始时将栈顶入栈一个```-1```并在数组末尾加一个元素```-1```作为哨兵。期间注意不要超过32位整数。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
const int MOD = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(-1);
        stack<int> st;
        st.push(-1);
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (st.size() > 1 && arr[i] < arr[st.top()]) {
                int last = st.top();
                st.pop();
                ans = (ans + (long long)arr[last] * (last - st.top()) * (i - last)) % MOD;
            }
            st.push(i);
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

MOD = 1000000007
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        st = [-1]
        arr.append(-1)
        ans = 0
        for i in range(len(arr)):
            while len(st) > 1 and arr[i] < arr[st[-1]]:
                last = st.pop()
                ans = (ans + arr[last] * (last - st[-1]) * (i - last)) % MOD
            st.append(i)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2023/11/27/LeetCode%200907.%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%B0%8F%E5%80%BC%E4%B9%8B%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134652093](https://letmefly.blog.csdn.net/article/details/134652093)
