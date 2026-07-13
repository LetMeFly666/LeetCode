---
title: 1291.顺次数：打表/枚举
date: 2026-07-13 22:16:53
tags: [题解, LeetCode, 中等, 打表, 枚举]
categories: [题解, LeetCode]
description: 我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 1 的整数。请你返回由 [low, high] 范围内所有顺次数组成的 有序 列表（从小到大排序）。
---

# 【LetMeFly】1291.顺次数：打表/枚举

力扣题目链接：[https://leetcode.cn/problems/sequential-digits/](https://leetcode.cn/problems/sequential-digits/)

<p>我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 <code>1</code> 的整数。</p>

<p>请你返回由&nbsp;<code>[low, high]</code>&nbsp;范围内所有顺次数组成的 <strong>有序</strong> 列表（从小到大排序）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输出：</strong>low = 100, high = 300
<strong>输出：</strong>[123,234]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输出：</strong>low = 1000, high = 13000
<strong>输出：</strong>[1234,2345,3456,4567,5678,6789,12345]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 &lt;= low &lt;= high &lt;= 10^9</code></li>
</ul>


    
## 解题方法：枚举/打表

### 枚举

12345678这种*顺次数*最多有几十个，我们可以枚举所有的*顺次数*，如果在$low$和$high$之间就加入答案数组，最终排个序返回即可。

如何枚举所有*顺次数*？首先枚举第一位，然后依次往这个数后面拼接下一位，制止拼接完$9$位置。

### 打表

不用每个测试用例都重新枚举计算一遍所有的*顺次数*，直接初始化一个全局变量把所有*顺次数*存下来，每个测试用例只需要遍历就好了。

### 时空复杂度

+ 时间复杂度$O(1)$，只有几十个数，可以粗略地将复杂度视为$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++ —— 枚举

```cpp
/*
 * @LastEditTime: 2026-07-13 21:56:25
 */
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            int v = i;
            for (int j = i + 1; j <= 9; j++) {
                v = v * 10 + j;
                if (low <= v && v <= high) {
                    ans.push_back(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### C++ —— 打表

```cpp
/*
 * @LastEditTime: 2026-07-13 22:07:09
 */
vector<int> good;

int _ = [] {
    for (int i = 1; i <= 9; i++) {
        int v = i;
        for (int j = i + 1; j <= 9; j++) {
            v = v * 10 + j;
            good.push_back(v);
        }
    }
    sort(good.begin(), good.end());
    return 0;
}();

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int t : good) {
            if (low <=t && t <= high) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/162850792)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/07/13/LeetCode%201291.%E9%A1%BA%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
