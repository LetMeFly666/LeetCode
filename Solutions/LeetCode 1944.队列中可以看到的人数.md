---
title: 1944.队列中可以看到的人数
date: 2024-01-05 19:04:29
tags: [题解, LeetCode, 困难, 栈, 数组, 单调栈]
categories: [题解, LeetCode]
---

# 【LetMeFly】1944.队列中可以看到的人数：（一步步图解）单调栈

力扣题目链接：[https://leetcode.cn/problems/number-of-visible-people-in-a-queue/](https://leetcode.cn/problems/number-of-visible-people-in-a-queue/)

<p>有&nbsp;<code>n</code>&nbsp;个人排成一个队列，<strong>从左到右</strong>&nbsp;编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。给你以一个整数数组&nbsp;<code>heights</code>&nbsp;，每个整数 <strong>互不相同</strong>，<code>heights[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个人的高度。</p>

<p>一个人能 <strong>看到</strong> 他右边另一个人的条件是这两人之间的所有人都比他们两人 <strong>矮</strong>&nbsp;。更正式的，第&nbsp;<code>i</code>&nbsp;个人能看到第&nbsp;<code>j</code>&nbsp;个人的条件是&nbsp;<code>i &lt; j</code>&nbsp;且&nbsp;<code>min(heights[i], heights[j]) &gt; max(heights[i+1], heights[i+2], ..., heights[j-1])</code>&nbsp;。</p>

<p>请你返回一个长度为 <code>n</code>&nbsp;的数组<em>&nbsp;</em><code>answer</code><em>&nbsp;</em>，其中<em>&nbsp;</em><code>answer[i]</code><em>&nbsp;</em>是第&nbsp;<code>i</code>&nbsp;个人在他右侧队列中能&nbsp;<strong>看到</strong>&nbsp;的&nbsp;<strong>人数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/05/29/queue-plane.jpg" style="width: 600px; height: 247px;" /></p>

<pre>
<b>输入：</b>heights = [10,6,8,5,11,9]
<b>输出：</b>[3,1,2,1,1,0]
<strong>解释：</strong>
第 0 个人能看到编号为 1 ，2 和 4 的人。
第 1 个人能看到编号为 2 的人。
第 2 个人能看到编号为 3 和 4 的人。
第 3 个人能看到编号为 4 的人。
第 4 个人能看到编号为 5 的人。
第 5 个人谁也看不到因为他右边没人。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>heights = [5,1,2,3,10]
<b>输出：</b>[4,1,1,1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == heights.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>heights</code>&nbsp;中所有数 <strong>互不相同</strong>&nbsp;。</li>
</ul>


    
## 方法一：单调栈

### 思路

使用一个单调递减（非递增）栈，从栈底到栈顶是越来越矮的人。

从右往左遍历身高序列，当栈顶元素小于自己时（自己可以看到这个人，并且视线不被其阻挡，自己左边的人由于自己将无法看到这人），将这人出栈，自己看到的人的个数加一。

然后自己入栈。在自己入栈前，若栈中有人（那一定比自己高）则自己能看到的人数再加一。

### 举例

假设身高队列为```3, 4, 1, 2, 8```：

```
    3 4 1 2 8    ]
ans:0 0 0 0 0
```

栈中无比```8```低之人，```8```入栈：

```
    3 4 1 2     8]
ans:0 0 0 0     0
```

栈中无比```2```低之人，```2```入栈（入栈时栈非空，```2```能看到```8```）

```
    3 4 1     2 8]
ans:0 0 0     1 0
```

栈中无比```1```低之人，```1```入栈（入栈时栈非空，```1```能看到```2```）

```
    3 4     1 2 8]
ans:0 0     1 1 0
```

栈中```1```、```2```都比```4```低（```4```能看到```1```、```2```），```1```、```2```出栈```4```入栈（入栈时栈非空，```4```能看到```8```）

```
    3     4 8]
ans:0     3 0
```

栈中无比```3```低之人，```3```入栈（入栈时栈非空，```3```能看到```4```）

```
        3 4 8]
ans:    1 3 0
```

终止。```3, 4, 1, 2, 8```能看到的人数分别为```1, 3, 1, 1, 0```。

+ 时间复杂度$O(len(heights))$
+ 空间复杂度$O(len(heights))$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans(heights.size());
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (st.size() && heights[st.top()] < heights[i]) {
                st.pop();
                ans[i]++;
            }
            if (st.size()) {
                ans[i]++;
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

class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        ans = [0] * len(heights)
        st = []
        for i in range(len(heights) - 1, -1, -1):
            while st and heights[st[-1]] < heights[i]:
                st.pop()
                ans[i] += 1
            if st:
                ans[i] += 1
            st.append(i)
        return ans
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/01/05/LeetCode%201944.%E9%98%9F%E5%88%97%E4%B8%AD%E5%8F%AF%E4%BB%A5%E7%9C%8B%E5%88%B0%E7%9A%84%E4%BA%BA%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/135416441](https://letmefly.blog.csdn.net/article/details/135416441)
