---
title: 556.下一个更大元素 III
date: 2022-07-03 11:03:09
tags: [题解, LeetCode, 中等, 数学, 双指针, 字符串, 模拟]
---

# 【LetMeFly】4步讲完：556.下一个更大元素 III

力扣题目链接：[https://leetcode.cn/problems/next-greater-element-iii/](https://leetcode.cn/problems/next-greater-element-iii/)

<p>给你一个正整数 <code>n</code> ，请你找出符合条件的最小整数，其由重新排列 <code>n</code><strong> </strong>中存在的每位数字组成，并且其值大于 <code>n</code> 。如果不存在这样的正整数，则返回 <code>-1</code> 。</p>

<p><strong>注意</strong> ，返回的整数应当是一个 <strong>32 位整数</strong> ，如果存在满足题意的答案，但不是 <strong>32 位整数</strong> ，同样返回 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 12
<strong>输出：</strong>21
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 21
<strong>输出：</strong>-1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 2<sup>31</sup> - 1</code></li>
</ul>


## 方法一：模拟

其实就是求数字对应字符串的下一个全排列，方法也很简单（4步）：

1. 从后往前看，找到第一个“后面有大于它的数”的数（记为s[i] = x）

2. 在s[i ~ 最后]中找到最小的大于x的数（记为s[j] = y）

3. 交换s[i]和s[j]

4. 在s[i+1 ~ 最后]范围内从小到大排序

然后返回字符串对应的数字即可

+ 时间复杂度$O(N^2)$，其中$N$是数字的位数（$N\leq 10$）
+ 空间复杂度$O(N\log N)$，空间复杂度主要是排序所致

### AC代码

#### C++

```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        bool changed = false;
        for (int i = s.size() - 2; i >= 0; i--) {
            char m = 58;  // '9' = 57
            int locm = i;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] > s[i] && s[j] < m) {
                    m = s[j];
                    locm = j;
                }
            }
            if (locm != i) {
                changed = true;
                swap(s[i], s[locm]);
                sort(s.begin() + i + 1, s.end());
                break;
            }
        }
        if (!changed)
            return -1;
        ll ans = atoll(s.c_str());
        if (ans > INT_MAX)
            return -1;
        return ans;
    }
};
```

小小记录一下嘿嘿

![100.00%,93.66%](https://img-blog.csdnimg.cn/ea16b8ef5f844202886d7d393739f8f5.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/03/LeetCode%200556.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0III)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125582351](https://letmefly.blog.csdn.net/article/details/125582351)

