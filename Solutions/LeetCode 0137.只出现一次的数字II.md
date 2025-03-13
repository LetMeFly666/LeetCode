---
title: 137.只出现一次的数字 II
date: 2022-07-26 11:29:25
tags: [题解, LeetCode, 中等, 位运算, 数组, 数电, 哈希]
categories: [题解, LeetCode]
---

# 【LetMeFly】137.只出现一次的数字 II

力扣题目链接：[https://leetcode.cn/problems/single-number-ii/](https://leetcode.cn/problems/single-number-ii/)

<p>给你一个整数数组 <code>nums</code> ，除某个元素仅出现 <strong>一次</strong> 外，其余每个元素都恰出现 <strong>三次 。</strong>请你找出并返回那个只出现了一次的元素。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,3,2]
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,0,1,0,1,99]
<strong>输出：</strong>99
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1</code></li>
	<li><code>nums</code> 中，除某个元素仅出现 <strong>一次</strong> 外，其余每个元素都恰出现 <strong>三次</strong></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？</p>


    
## 方法一：哈希表

这道题使用哈希表最简单，只是复杂度不符合进阶要求。

对于```C++```，直接使用```unordered_map```统计一下每个数字出现的次数，然后遍历一遍哈希表，返回只出现了一次的数字即可。

+ 时间复杂度$O(n)$，其中$n$是数组中数字的个数
+ 空间复杂度$O(n)$，不符合本题进阶的$O(1)$要求

### AC代码

#### C++

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ma;
        for (int& t : nums) {
            ma[t]++;
        }
        for (auto& [num, times] : ma) {
            if (times == 1)
                return num;
        }
        return -1;  // FAKE_RETURN
    }
};
```

## 方法二：位运算

稍微多想一想，这道题可以使用位运算来解决。

一个$int$类型的数字有$32$位，对于其中的某一位：

> 遍历所有的数字，并统计这一位出现的次数。
> 出现了$3$次的数字，对这一位的出现次数的贡献要么是$3$，要么是$0$。总之都是$3$的倍数。
> 如果只出现了一次的数字的这一位是$1$，那么这一位出现的总次数就是$3的倍数+1$；
> 如果只出现了一次的数字的这一位是$0$，那么这一位出现的总次数就是$3的倍数$。

因此，对于某一位，如果出现次数不是$3$的倍数，就让答案的这一位为$1$，最终即能得到只出现了一次的数字

+ 时间复杂度$O(n\log C)$，其中$n$是数组中数字的个数，$C$是一个数字的范围($2^{32}$)。因此$\log C$就是$32$
+ 空间复杂度$O(1)$，符合本题进阶的$O(1)$要求

### AC代码

#### C++

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int times = 0;
            for (int& t : nums) {
                times += (t >> i) & 1;
            }
            if (times % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};
```

其实还有方法三：数字电路设计。太妙了，感兴趣了可参考[官方题解](https://leetcode.cn/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/)

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num: nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }
        return b;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/26/LeetCode%200137.%E5%8F%AA%E5%87%BA%E7%8E%B0%E4%B8%80%E6%AC%A1%E7%9A%84%E6%95%B0%E5%AD%97II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125991647](https://letmefly.blog.csdn.net/article/details/125991647)
