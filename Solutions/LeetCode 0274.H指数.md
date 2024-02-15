---
title: 274.H 指数
date: 2023-10-29 07:15:20
tags: [题解, LeetCode, 中等, 数组, 计数排序, 排序]
---

# 【LetMeFly】274.H 指数：排序

力扣题目链接：[https://leetcode.cn/problems/h-index/](https://leetcode.cn/problems/h-index/)

<p>给你一个整数数组 <code>citations</code> ，其中 <code>citations[i]</code> 表示研究者的第 <code>i</code> 篇论文被引用的次数。计算并返回该研究者的 <strong><code>h</code><em>&nbsp;</em>指数</strong>。</p>

<p>根据维基百科上&nbsp;<a href="https://baike.baidu.com/item/h-index/3991452?fr=aladdin" target="_blank">h 指数的定义</a>：<code>h</code> 代表“高引用次数” ，一名科研人员的 <code>h</code><strong> 指数 </strong>是指他（她）至少发表了 <code>h</code> 篇论文，并且每篇论文<strong> 至少</strong> 被引用 <code>h</code> 次。如果 <code>h</code><em> </em>有多种可能的值，<strong><code>h</code> 指数 </strong>是其中最大的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong><code>citations = [3,0,6,1,5]</code>
<strong>输出：</strong>3 
<strong>解释：</strong>给定数组表示研究者总共有 <code>5</code> 篇论文，每篇论文相应的被引用了 <code>3, 0, 6, 1, 5</code> 次。
&nbsp;    由于研究者有 <code>3 </code>篇论文每篇 <strong>至少 </strong>被引用了 <code>3</code> 次，其余两篇论文每篇被引用 <strong>不多于</strong> <code>3</code> 次，所以她的 <em>h </em>指数是 <code>3</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>citations = [1,3,1]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == citations.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>0 &lt;= citations[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：排序

我们将所有的论文引用次数$citations$按从大到小排序，接着遍历$citations$数组，遍历过程中如果遇到了“第$i$篇论文的引用量小于$i$”说明什么？

说明引用量$\geq i$的论文数量不超过$i$篇，也就是说此时的$i$已经不满足“H指数”了（假设$i$从下标$1$开始）。而上一个$i$是符合“H指数”的，因此返回$此时篇数 - 1$即可。

+ 时间复杂度$O(n\log n)$，其中$n = len(citations)$
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (i + 1 > citations[i]) {
                return i;
            }
        }
        return citations.size();
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(key=lambda x: -x)
        for i in range(len(citations)):
            if i + 1 > citations[i]:
                return i
        return len(citations)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/29/LeetCode%200274.H%E6%8C%87%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134099234](https://letmefly.blog.csdn.net/article/details/134099234)
