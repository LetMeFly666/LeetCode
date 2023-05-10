---
title: 面试题 17.09.第 k 个数
date: 2022-09-28 12:28:28
tags: [题解, LeetCode, 中等, 哈希表, 数学, 动态规划, 堆（优先队列）]
---

# 【LetMeFly】面试题 17.09.第 k 个数

力扣题目链接：[https://leetcode.cn/problems/get-kth-magic-number-lcci/](https://leetcode.cn/problems/get-kth-magic-number-lcci/)

<p>有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>k = 5

<strong>输出: </strong>9
</pre>


## 方法一：取最小

这道题和[LeetCode 264. 丑数 II](https://blog.tisfy.eu.org/2022/09/13/LeetCode%200264.%E4%B8%91%E6%95%B0II/) 几乎相同

具体方法可参考我在[LeetCode 264. 丑数 II](https://letmefly.blog.csdn.net/article/details/126840084)写的题解：[https://blog.tisfy.eu.org/2022/09/13/LeetCode 0264.丑数II](https://blog.tisfy.eu.org/2022/09/13/LeetCode%200264.%E4%B8%91%E6%95%B0II/)

方法完全相同，用三个指针每次确定出一个最小值，哪个小就将哪个“入队”（加入候选）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int getKthMagicNumber(int k) {
        int loc3 = 0, loc5 = 0, loc7 = 0;
        vector<int> v = {1};
        while (--k) {
            int result3 = v[loc3] * 3;
            int result5 = v[loc5] * 5;
            int result7 = v[loc7] * 7;
            int m = min(result3, min(result5, result7));
            v.push_back(m);
            if (result3 == m) {
                loc3++;
            }
            if (result5 == m) {
                loc5++;
            }
            if (result7 == m) {
                loc7++;
            }
        }
        return v.back();
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/28/LeetCode%20%E9%9D%A2%E8%AF%95%E9%A2%98%2017.09.%20%E7%AC%AC%20k%20%E4%B8%AA%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127087237](https://letmefly.blog.csdn.net/article/details/127087237)
