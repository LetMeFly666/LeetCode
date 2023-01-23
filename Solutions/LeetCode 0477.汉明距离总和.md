---
title: 477.汉明距离总和
date: 2022-10-26 20:36:57
tags: [题解, LeetCode, 中等, 位运算, 数组, 数学]
---

# 【LetMeFly】477.汉明距离总和

力扣题目链接：[https://leetcode.cn/problems/total-hamming-distance/](https://leetcode.cn/problems/total-hamming-distance/)

<p>两个整数的&nbsp;<a href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB/475174?fr=aladdin">汉明距离</a> 指的是这两个数字的二进制数对应位不同的数量。</p>

<p>给你一个整数数组 <code>nums</code>，请你计算并返回 <code>nums</code> 中任意两个数之间 <strong>汉明距离的总和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,14,2]
<strong>输出：</strong>6
<strong>解释：</strong>在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,14,4]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>给定输入的对应答案符合 <strong>32-bit</strong> 整数范围</li>
</ul>


    
## 方法一：位运算

类似于[力扣461.汉明距离](https://leetcode.letmefly.xyz/2022/10/25/LeetCode%200461.%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB/)，这道题我们同样把每一位分开单独计算。

对于某一位，我们遍历一遍原始数组，并将这一位是1和这一位是0的数字个数统计下来。

什么时候两个数之间会产生“汉明距离”呢？

当然是“0”和“1”之间啊

任意一个“0”都会与任意一个“1”之间产生“汉明距离”，因此统计出某一位为“0”和为“1”的数字的个数之后，$0个数\times 1个数$即为**所有数**这一位汉明距离的总和

+ 时间复杂度$O(n\times C)$，其中$n$是数组中元素个数，$C=31$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int cnt0 = 0, cnt1 = 0;
            for (int num : nums) {
                if ((num >> i) & 1) {
                    cnt0++;
                }
                else {
                    cnt1++;
                }
            }
            ans += cnt0 * cnt1;
        }
        return ans;
    }
};
```

#### Java

🔥 感谢 [@Fomalhaut🥝](https://leetcode.cn/u/Fomalhaut1998/)大佬 提供 Java统计每一位贡献并且运行速度超越100% 的代码，以及详细的注释~

```java
class Solution {
    public int totalHammingDistance(int[] nums) {
        /*
        统计每一位的贡献
        以[4,14,2]为例进行说明
        0 1 0 0
        1 1 1 0
        0 0 1 0
        1.若该位为0，则其他的1对汉明距离有贡献
        2.若该位为1，则其他的0对汉明距离有贡献
        角度1:我们只要统计出每一位的1和0的数目即可快速统计出该数字每一位对于汉明距离的贡献
        第一个数字4为:1 + 1 + 2 + 0 = 4
        第一个数字14为:2 + 1 + 1 + 0 = 4
        第一个数字2为:1 + 2 + 1 + 0 = 4
        将结果/2就是答案
        角度2:统计每一位的总贡献进行累加
        位3:0 1 0 不妨将顺序调换成  1 0 0 那么有效的组合只有两个1 0
        相当于直接用每一位的1和0的个数进行相乘就可以得到该位的总贡献，最后将每一位的总贡献累加就是答案
        时间复杂度O:(C*N) 空间复杂度:O(1)
         */
        int n = nums.length;
        // 统计该位1的数目
        int res = 0;
        for (int i = 0; i < 30; i++) {
            int one = 0;
            for (int num : nums) {
                one += (num >> i) & 1;
            }
            res += one * (n - one);
        }
        return res;
    }
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/10/26/LeetCode%200477.%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB%E6%80%BB%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127540353](https://letmefly.blog.csdn.net/article/details/127540353)
