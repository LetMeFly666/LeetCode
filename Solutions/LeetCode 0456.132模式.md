---
title: 456.132 模式
date: 2022-10-22 13:02:08
tags: [题解, LeetCode, 中等, 栈, 数组, 二分查找, 有序集合, 单调栈]
---

# 【LetMeFly】456.132 模式

力扣题目链接：[https://leetcode.cn/problems/132-pattern/](https://leetcode.cn/problems/132-pattern/)

<p>给你一个整数数组 <code>nums</code> ，数组中共有 <code>n</code> 个整数。<strong>132 模式的子序列</strong> 由三个整数 <code>nums[i]</code>、<code>nums[j]</code> 和 <code>nums[k]</code> 组成，并同时满足：<code>i < j < k</code> 和 <code>nums[i] < nums[k] < nums[j]</code> 。</p>

<p>如果 <code>nums</code> 中存在 <strong>132 模式的子序列</strong> ，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>false
<strong>解释：</strong>序列中不存在 132 模式的子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,4,2]
<strong>输出：</strong>true
<strong>解释：</strong>序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,3,2,0]
<strong>输出：</strong>true
<strong>解释：</strong>序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= n <= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：单调栈

先以样例二为例，再讲解原理。

```[3,1,4,2]```

建立一个栈```stack<int> st```

使用一个变量$k$来记录“从栈中弹出的元素的最大值”。$k$的初始值为“极小值”

从后往前遍历数组中的元素，如果当前元素小于$k$，直接返回```true```；否则在当前元素大于栈顶元素时，不断出栈并更新$k$，然后将当前元素入栈

**元素2**

```
[
k = -99999999999999999
```

栈为空，$k<2$，$2$入栈

```
[ 2
k = -99999999999999999
```

**元素4**

$4$大于栈顶元素$2$，$2$出栈并更新$k$（$k = \max(k, 2) = 2$）

```
[
k = 2
```

栈中五元素，$4$入栈

```
[ 4
k = 2
```

**元素1**

$1 < k$，返回$true$

为什么这么“神奇”呢？

原因就在于这个$k$

假设我们要找的$132$分别为$ijk$

那么$k$之左一定有比$k$大的数，这样$k$才能出栈

而最终元素$1$就是$i$，$i < k$，且$i$和$k$中间有比$k$还大的数，因此$132$结构组成了。

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int k = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < k)
                return true;
            while (st.size() && nums[i] > st.top()) {
                k = max(k, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/22/LeetCode%200456.132%E6%A8%A1%E5%BC%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127460716](https://letmefly.blog.csdn.net/article/details/127460716)
