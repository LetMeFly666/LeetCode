---
title: 667.优美的排列 II
date: 2022-09-08 10:22:16
tags: [题解, LeetCode, 中等, 数组, 数学, 思维, 构造]
categories: [题解, LeetCode]
---

# 【LetMeFly】667.优美的排列 II

力扣题目链接：[https://leetcode.cn/problems/beautiful-arrangement-ii/](https://leetcode.cn/problems/beautiful-arrangement-ii/)

<p>给你两个整数 <code>n</code> 和 <code>k</code> ，请你构造一个答案列表 <code>answer</code> ，该列表应当包含从 <code>1</code> 到 <code>n</code> 的 <code>n</code> 个不同正整数，并同时满足下述条件：</p>

<ul>
	<li>假设该列表是 <code>answer = [a<sub>1</sub>, a<sub>2</sub>, a<sub>3</sub>, ... , a<sub>n</sub>]</code> ，那么列表 <code>[|a<sub>1</sub> - a<sub>2</sub>|, |a<sub>2</sub> - a<sub>3</sub>|, |a<sub>3</sub> - a<sub>4</sub>|, ... , |a<sub>n-1</sub> - a<sub>n</sub>|]</code> 中应该有且仅有 <code>k</code> 个不同整数。</li>
</ul>

<p>返回列表 <code>answer</code> 。如果存在多种答案，只需返回其中 <strong>任意一种</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>[1, 2, 3]
<strong>解释：</strong>[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 2
<strong>输出：</strong>[1, 3, 2]
<strong>解释：</strong>[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2 个不同整数：1 和 2
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k < n <= 10<sup>4</sup></code></li>
</ul>

<p> </p>


    
## 方法一：思维 + 构造

如图

![图解](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/6557ccb126ff45c6abc348ffd88cb061.png#pic_center)

数组前面(橘色)采用“一前一后”的方式构造（1、8、2、7、3、6、……），后面(蓝色)从紧邻前面的最后一个数字开始连续递增或递减。

当$k$为奇数时，蓝色部分递增；为偶数时递减。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$，答案不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int l = 1, r = n;
        for (int i = 0; i < k; i++) {
            if (i % 2) {
                ans[i] = r--;
            }
            else {
                ans[i] = l++;
            }
        }
        int toLoc = k;
        if (k % 2) {
            while (l <= r) {
                ans[toLoc++] = l++;
            }
        }
        else {
            while (l <= r) {
                ans[toLoc++] = r--;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/08/LeetCode%200667.%E4%BC%98%E7%BE%8E%E7%9A%84%E6%8E%92%E5%88%97II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126759880](https://letmefly.blog.csdn.net/article/details/126759880)
