---
title: 421.数组中两个数的最大异或值
date: 2022-10-19 17:58:27
tags: [题解, LeetCode, 中等, 位运算, 字典树, 数组, 哈希表, 哈希]
---

# 【LetMeFly】421.数组中两个数的最大异或值

力扣题目链接：[https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/](https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/)

<p>给你一个整数数组 <code>nums</code> ，返回<em> </em><code>nums[i] XOR nums[j]</code> 的最大运算结果，其中 <code>0 ≤ i ≤ j < n</code> 。</p>

<p><strong>进阶：</strong>你可以在 <code>O(n)</code> 的时间解决这个问题吗？</p>

<p> </p>

<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,10,5,25,2,8]
<strong>输出：</strong>28
<strong>解释：</strong>最大运算结果是 5 XOR 25 = 28.</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4]
<strong>输出：</strong>6
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>nums = [8,10,2]
<strong>输出：</strong>10
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>nums = [14,70,53,83,49,91,36,80,92,51,66,70]
<strong>输出：</strong>127
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 2 * 10<sup>4</sup></code></li>
	<li><code>0 <= nums[i] <= 2<sup>31</sup> - 1</code></li>
</ul>
</div>
</div>


    
## 方法一：哈希 + 假设修正

这种位运算的题，可以考虑每一位分别计算。

想要结果最大，那么优先高位最大。

那么我们从高位开始处理，令```ans```为答案中，处理到当前位位置，高位的数值。

接下来我们从高位到地位开始遍历（```30 -> 0```）

我们希望答案的这一位是$1$，那么我们就构造一个这一位是“1”的数（ans左移一位并加一）

用这个“预期结果”去异或每一个数，如果异或结果也在数组中，那么这一位就可以是1。

否则，这一位必须是0。

至于判断某个数是否存在于数组中，我们可以预处理一遍，将所有数都放入哈希表中，这样就能以$O(1)$的时间判断数字是否在数字中了。

具体方法或解释可参考代码注释

+ 时间复杂度$O(nC)$，其中$n$是数组中元素个数，$C$是要处理的位数，这里为$31$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;  // 处理到当前位时，高位的数值
        for (int i = 30; i >= 0; i--) {  // 处理每一位  // for循环里面，我们不考虑整个数，而只关注某个数的前几位
            // 开始预处理，将每个数的前几位放入哈希表
            unordered_set<int> se;
            for (int& t : nums) {
                se.insert(t >> i);
            }
            // 我们希望这一位也是1，假设前三位是101，那么我们希望前四位是1011，而1011 = (101 << 1) + 1
            int wantBe = (ans << 1) + 1;
            bool found = false;
            for (int& t : nums) {
                if (se.count(wantBe ^ (t >> i))) {  // 假设 wantBe ^ (t的前几位) = X，那么X ^ (t的前几位)就是wantBe
                    found = true;
                    break;
                }
            }
            ans = found ? wantBe : wantBe - 1;  // 如果没找到，那么这一位只好是0，也就是“1010 = 1011 - 1”
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/19/LeetCode%200421.%E6%95%B0%E7%BB%84%E4%B8%AD%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BC%82%E6%88%96%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127413219](https://letmefly.blog.csdn.net/article/details/127413219)
