---
title: 1673.找出最具竞争力的子序列
date: 2024-05-24 21:38:41
tags: [题解, LeetCode, 中等, 栈, 贪心, 数组, 单调栈]
---

# 【LetMeFly】1673.找出最具竞争力的子序列：单调栈（贪心）

力扣题目链接：[https://leetcode.cn/problems/find-the-most-competitive-subsequence/](https://leetcode.cn/problems/find-the-most-competitive-subsequence/)

<p>给你一个整数数组 <code>nums</code> 和一个正整数 <code>k</code> ，返回长度为 <code>k</code> 且最具 <strong>竞争力</strong> 的<em> </em><code>nums</code> 子序列。</p>

<p>数组的子序列是从数组中删除一些元素（可能不删除元素）得到的序列。</p>

<p>在子序列 <code>a</code> 和子序列 <code>b</code> 第一个不相同的位置上，如果 <code>a</code> 中的数字小于 <code>b</code> 中对应的数字，那么我们称子序列 <code>a</code> 比子序列 <code>b</code>（相同长度下）更具 <strong>竞争力</strong> 。 例如，<code>[1,3,4]</code> 比 <code>[1,3,5]</code> 更具竞争力，在第一个不相同的位置，也就是最后一个位置上， <code>4</code> 小于 <code>5</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,5,2,6], k = 2
<strong>输出：</strong>[2,6]
<strong>解释：</strong>在所有可能的子序列集合 {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} 中，[2,6] 最具竞争力。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,3,3,5,4,9,6], k = 4
<strong>输出：</strong>[2,3,3,4]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= nums[i] <= 10<sup>9</sup></code></li>
	<li><code>1 <= k <= nums.length</code></li>
</ul>


    
## 解题方法：单调栈

先看做法，再讲原理（可能看完做法不看原理就懂了）。

### 方法概述

使用一个单调递增栈。和普通单调栈不同的是，本题需要同时确保：

1. 单调栈中最多有$k$个元素
2. 如果要出栈，要先保证出栈后$栈中元素+剩余元素\geq k$

然后问题基本上就解决了。

### 具体怎么做

使用一个栈$st$用来存放最终答案，然后遍历数组：

> 当```栈顶元素＞当前元素```且```栈顶出栈后还能凑够k个```时，栈顶元素不断出栈。
>
> 若栈中元素个数小于k，则当前元素入栈。

遍历完成后，从栈底到栈顶的元素即为要找的答案。

### 为什么这么做

需要明白的是，“只要后面元素还够，遇到小的元素时小元素越往前越好”：

> 例如当前栈中是```[2 4 6```，```k = 3```，剩余元素是```3 1000 1000 1000 ...```。
> 
> 当前遍历到了元素```3```，后面元素足够多，那么```3```就应该尽量往前（把```4 6```都替换掉变成```[2 3```）。
> 
> 虽然```3```后面的元素都很大，但是```[2 3 ∞```是优于```[2 4 6```的。

为什么“若栈中元素个数小于k，则当前元素入栈”：

> 因为“若当前元素较小”或者“栈中元素不是很足”，那当前元素当然要入栈。
>
> 否则（栈中元素数量为$k$）的话，说明当前元素很大，没给栈中元素弹出来，当前元素不值得入栈。

### 时空复杂度

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(k)$，栈中最多同时存在$k$个元素

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (st.size() && st.top() > nums[i] && (st.size() - 1) + (nums.size() - i) >= k) {
                st.pop();
            }
            if (st.size() < k) {
                st.push(nums[i]);
            }
        }
        // stack -> vector
        vector<int> ans;
        while (st.size()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Java

```java
// import java.util.ArrayDeque;
// import java.util.Deque;

class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Deque<Integer> st = new ArrayDeque<Integer>();
        for (int i = 0; i < nums.length; i++) {
            while (!st.isEmpty() && st.peek() > nums[i] && (st.size() - 1) + (nums.length - i) >= k) {
                st.pop();
            }
            if (st.size() < k) {
                st.push(nums[i]);
            }
        }
        // stack -> array
        int[] ans = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = st.pop();
        }
        return ans;
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        st = []
        for i in range(len(nums)):
            while st and st[-1] > nums[i] and (len(st) - 1) + (len(nums) - i) >= k:
                st.pop()
            if len(st) < k:
                st.append(nums[i])
        return st
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/24/LeetCode%201673.%E6%89%BE%E5%87%BA%E6%9C%80%E5%85%B7%E7%AB%9E%E4%BA%89%E5%8A%9B%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139185554](https://letmefly.blog.csdn.net/article/details/139185554)
