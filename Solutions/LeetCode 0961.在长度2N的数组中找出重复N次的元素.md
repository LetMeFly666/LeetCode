---
title: 961.在长度2N的数组中找出重复N次的元素
date: 2022-05-21 10:31:00
tags: [题解, LeetCode, 简单, 数组, 哈希, set, 随机, Rand, 排序, 数学]
---

# 【LetMeFly】四种方式解决 961.在长度2N的数组中找出重复N次的元素

力扣题目链接：[https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/](https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/)

给你一个整数数组 $nums$ ，该数组具有以下属性：

+ $nums.length == 2 * n$.
+ $nums$ 包含 $n + 1$ 个 不同的 元素
+ $nums$ 中恰有一个元素重复 $n$ 次

找出并返回重复了 $n$ 次的那个元素。



**示例 1:**

```
输入：nums = [1,2,3,3]
输出：3
```

**示例 2:**

```
输入：nums = [2,1,2,5,3,2]
输出：2
```

**示例 3:**

```
输入：nums = [5,1,5,2,5,3,5,4]
输出：5
```

**提示:**

+ $2\leq n\leq 5000$
+ $nums.length == 2 * n$
+ $0\leq nums[i]\leq10^4$
+ $nums$由$n+1$个**不同的**元素组成，且其中一个元素恰好重复```n```次


# 思路

有一个元素出现了$n$次，其余元素都只出现了$1$次

## 方法一：排序

这让我们很容易想到排序。排序后相同的数字会挨到一起，从前向后遍历数组，如果有相邻的两个数字相同，那么这个数字就是答案。

+ 时间复杂度$O(n\log n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;  // Fake return：LeetCode编译器必须要求有一个返回值
    }
};
```

## 方法二：哈希表

我们可以用哈希表记录下每个数出现的次数，如果遇到出现两次的数字就是答案。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> appended;  // 记录已经出现过的元素
        for (int& t : nums) {  // 遍历
            if (appended.count(t)) {  // 出现过
                return t;
            }
            appended.insert(t);
        }
        return -1;  // Fake return
    }
};
```

## 方法三：数学

首先我们可以思考：一个数组中有$n$个相同的数，这些相同的数中，距离最近的两个数的最大距离是多少呢？

答案肯定不会很大吧。实际上确实如此。证明如下：

> 记$n$个相同的数为$x$，假设每两个$x$之间都间隔了$\geq2$个数。那么$n$个$x$需要至少$2\times(n-1)$个数来间隔。但是非$x$的数只有$n$个。只有$n\geq 2\times(n-1)$时上述假设才成立。解得$n\leq2$。
> 也就是说，只有$n=2$时，才有可能满足两个$x$之间间隔$\geq2$（$[x,a,b,x]$）
> **$n>2$时，必存在两个间距$<2$的相同的$x$**。

因此我们只需要在“相邻两个数、间隔一个数”的条件下，就能找到答案（$n=2$时除外）

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if (nums.size() == 4) {  // n = 2时特判
            for (int i = 0; i < 4; i++) {
                for (int j = i + 1; j < 4; j++) {
                    if (nums[i] == nums[j]) {
                        return nums[i];
                    }
                }
            }
        }
        // n > 2
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                return nums[i];
            }
            if (i + 2 < nums.size() && nums[i + 2] == nums[i]) {
                return nums[i];
            }
        }
        return -1;  // Fake return
    }
};
```

## 方法四：随机选择

这种方法就是无脑随机选取两个**下标不同的**数，看两个数是否相等。如果不相等继续选择，直到相等为止。

这种方法看似很笨，其实效率很高。因为选择两个数相同的概率是$\frac{n}{2n}\times\frac{n-1}{2n}\approx \frac{1}{4}$，平均$4$次随机选择就能找到答案。因此期望时间复杂度为$O(1)$。

+ 期望时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++错误示范

```cpp
// 不可以这样写，因为这样可能会选取两个相同的下标
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        srand(time(NULL));
        int location;
        do {
            location = rand() % nums.size();
        } while (nums[location] != nums[rand() % nums.size()]);
        return nums[location];
    }
};
```

#### C++正确示范

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        srand(time(NULL));
        int loc1, loc2;
        do {
            loc1 = rand() % nums.size();
            loc2 = rand() % nums.size();
        } while (nums[loc1] != nums[loc2]);
        return nums[loc1];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/05/21/LeetCode%200961.%E5%9C%A8%E9%95%BF%E5%BA%A62N%E7%9A%84%E6%95%B0%E7%BB%84%E4%B8%AD%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8DN%E6%AC%A1%E7%9A%84%E5%85%83%E7%B4%A0)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/124897591](https://letmefly.blog.csdn.net/article/details/124897591)
