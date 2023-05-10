---
title: 275.H 指数 II
date: 2022-09-14 13:50:58
tags: [题解, LeetCode, 中等, 数组, 二分查找, 二分, 遍历]
---

# 【LetMeFly】275.H 指数 II

力扣题目链接：[https://leetcode.cn/problems/h-index-ii/](https://leetcode.cn/problems/h-index-ii/)

<p>给你一个整数数组 <code>citations</code> ，其中 <code>citations[i]</code> 表示研究者的第 <code>i</code> 篇论文被引用的次数，<code>citations</code> 已经按照 <strong>升序排列 </strong>。计算并返回该研究者的 <strong><code>h</code><em> </em>指数</strong>。</p>

<p><a href="https://baike.baidu.com/item/h-index/3991452?fr=aladdin" target="_blank">h 指数的定义</a>：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （<code>n</code> 篇论文中）<strong>总共</strong>有 <code>h</code> 篇论文分别被引用了<strong>至少</strong> <code>h</code> 次。且其余的 <em><code>n - h</code> </em>篇论文每篇被引用次数 <strong>不超过 </strong><em><code>h</code> </em>次。</p>

<p><strong>提示：</strong>如果 <code>h</code><em> </em>有多种可能的值，<strong><code>h</code> 指数 </strong>是其中最大的那个。</p>

<p>请你设计并实现对数时间复杂度的算法解决此问题。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入<code>：</code></strong><code>citations = [0,1,3,5,6]</code>
<strong>输出：</strong>3 
<strong>解释：</strong>给定数组表示研究者总共有 <code>5</code> 篇论文，每篇论文相应的被引用了 0<code>, 1, 3, 5, 6</code> 次。
     由于研究者有 <code>3 </code>篇论文每篇<strong> 至少 </strong>被引用了 <code>3</code> 次，其余两篇论文每篇被引用<strong> 不多于</strong> <code>3</code> 次，所以她的<em> h </em>指数是 <code>3</code> 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>citations = [1,2,100]
<strong>输出：</strong>2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == citations.length</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>0 <= citations[i] <= 1000</code></li>
	<li><code>citations</code> 按 <strong>升序排列</strong></li>
</ul>


    
## 方法一：遍历

因为原始数组已经是排好序的了，因此越往后的论文引用次数就越高。

我们只需要从前往后遍历一遍数组，当遍历到第$i$个元素时，如果后面$n-i$篇论文的引用次数都大于等于$n-i$，就说明$n-i$是一个```h指数```。

因数组是升序的，所以后面$n-i$篇论文的引用次数都大于等于$n-i$ 等价于 第$i$篇论文的引用量大于等于$n-i$

第一个合法的```h指数```就是最大的```h```

+ 时间复杂度$O(n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                return n - i;
            }
        }
        return 0;
    }
};
```

## 方法二：二分

与方法一同理，如果$n-i\geq citations[i]$，那么$n-i$就是一个合法的```h```

并且如果$n-i$是```h```，那么$n - i - 1$、$n - i - 2$、$\cdots$都是合法的```h```

我们要找的就是最大的```合法h```

显然，二分很合适。

初始时$l$指向合法区间的第一个元素$0$，$r$指向合法区间的后一个元素$n$（$n$不合法）

当$l < r$时，如果二者中值$mid$合法，就令$r=mid$，否则令$l=mid+1$

最终$n-l$即为答案

+ 时间复杂度$O(\log n)$，其中$n$是数组中元素的个数
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (citations[mid] >= n - mid) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return n - l;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/14/LeetCode%200275.H%E6%8C%87%E6%95%B0II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126851266](https://letmefly.blog.csdn.net/article/details/126851266)
