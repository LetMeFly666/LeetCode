---
title: 902.最大为 N 的数字组合
date: 2022-10-18 11:00:27
tags: [题解, LeetCode, 困难, 数组, 数学, 数字, 二分查找, 动态规划, DP, 排列组合]
categories: [题解, LeetCode]
---

# 【LetMeFly】902.最大为 N 的数字组合「抽象出了函数，看着较为明白的代码 + 手推」

力扣题目链接：[https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/)

<p>给定一个按&nbsp;<strong>非递减顺序</strong>&nbsp;排列的数字数组<meta charset="UTF-8" />&nbsp;<code>digits</code>&nbsp;。你可以用任意次数&nbsp;<code>digits[i]</code>&nbsp;来写的数字。例如，如果<meta charset="UTF-8" />&nbsp;<code>digits = ['1','3','5']</code>，我们可以写数字，如<meta charset="UTF-8" />&nbsp;<code>'13'</code>,&nbsp;<code>'551'</code>, 和&nbsp;<code>'1351315'</code>。</p>

<p>返回 <em>可以生成的小于或等于给定整数 <code>n</code> 的正整数的个数</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = ["1","3","5","7"], n = 100
<strong>输出：</strong>20
<strong>解释：</strong>
可写出的 20 个数字是：
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = ["1","4","9"], n = 1000000000
<strong>输出：</strong>29523
<strong>解释：</strong>
我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，
81 个四位数字，243 个五位数字，729 个六位数字，
2187 个七位数字，6561 个八位数字和 19683 个九位数字。
总共，可以使用D中的数字写出 29523 个整数。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>digits = ["7"], n = 8
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= digits.length &lt;= 9</code></li>
	<li><code>digits[i].length == 1</code></li>
	<li><code>digits[i]</code>&nbsp;是从&nbsp;<code>'1'</code>&nbsp;到&nbsp;<code>'9'</code> 的数</li>
	<li><code>digits</code>&nbsp;中的所有值都 <strong>不同</strong>&nbsp;</li>
	<li><code>digits</code>&nbsp;按&nbsp;<strong>非递减顺序</strong>&nbsp;排列</li>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 方法一：排列组合 + 动态规划

有两种数字小于$n$：

1. 数字位数直接小于$n$的
2. 数字位数和$n$相同，但仍然小于$n$

### 长度短的数字

对于第一种情况，假设$n=1024$，那么所有的三位数都小于$n$

假设候选数字$digits = {2, 5}$（有$2$个），那么：

+ 个位数有$2^1=2$个
+ 两位数有$2^2=4$个
+ 三位数有$2^3=8$个

所有的三位数有$2+4+8=14$个

### 长度和$n$相等的数字

假设$n=631$，$digits = {2, 6, 7}$

怎么计算长度为$3$的数字中，小于$n$的有多少个呢？

这里可以借助动态规划的思想，用两个变量$lessThan$和$equal$，分别代表遍历到$631$的某一位（记为$i$）时，“小于”和“等于”$631$前$i$位的$i$位数的个数。

说人话就是：假如当前遍历到了$631$的第$2$位（第一个数是$6$，第二个数是$3$）

那么$lessThan$就是**小于**$63$的两位数，$equal$就是**等于**$63$的两位数。

最终遍历完$631$的每一位后，$lessThan + equal$即为*小于等于*$631$的三位数

1. 首先看$631$的前$1$位$6$：
	+ 小于$6$的$1$位数有一个（$2$），因此$lessThan = 1$
	+ 等于$6$的$1$位数有一个（$6$），因此$equal = 1$
2. 接着看$631$的前$2$位$63$：
    + 小于$63$的$2$位数有$4$个（$lessThan = lessThan \times len(digits) + equal * lessThanThisWei = 1 \times 3 + 1\times 1 = 4$，小于$63$的包括```第一位就小于6，这一位任意```和```第一位等于6，这一位必须小于3```，而小于$3$的数有$1$个），因此$lessThan = 4$
	+ 等于$63$的$2$位数有$0$个（$equal = equal\times equalThisWei = 1\ times 0 = 0$，等于$63$的方案数为$第一位等于6的方案数\times这一位等于3的方案数$），因此$equal = 0$
3. 最后看$631$的前$3$位$631$：
    + 小于$631$的$3$位数有$12$个（$lessThan = lessThan \times len(digits) + equal * lessThanThisWei = 4 \times 3 + 0\times 0 = 12$，而小于$1$的数有$0$个），因此$lessThan = 12$
	+ 等于$631$的$3$位数有$0$个（$equal = equal\times equalThisWei = 0\ times 0 = 0$），因此$equal = 0$

因此小于等于$631$的三位数有$lessThan + equal = 12 + 0 = 12$个

（加上一位数$3$个和两位数$3\times3=9$个，由```[2, 6, 7]```组成的小于等于$631$的数一共有$12+(3+9)=24$个）

+ 时间复杂度$O((\log_{10}n)\times(\log_{10}n + len(digits)))$。前面求“短数字”的时间复杂度是$O((\log_{10}n)^2)$，后面求“等长数字”的时间复杂度是$O(\log_{10}n\times len(digits))$（这里题目中说$digits$是升序的，因此还可以实用二分查找，但是数据量不大，因此不是很有必要）
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
	/* 字符c是否在digits中 */
    bool isIn(char c, vector<string>& digits) {
        for (string& s : digits) {
            if (c == s[0])
                return true;
        }
        return false;
    }

	/* digits中小于字符c的元素的个数 */
    int cntLessThan(char c, vector<string>& digits) {
        int ans = 0;
        for (string& s : digits) {
            if (s[0] < c)
                ans++;
        }
        return ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int ans = 0;
		// 求“短数字”
        int len = to_string(n).size();
        for (int i = 1; i < len; i++) {
            ans += pow(digits.size(), i);
        }
		// 求“等长数字”
        string strify = to_string(n);
        int lessThan = cntLessThan(strify[0], digits), equal = isIn(strify[0], digits);  // 实用常数空间
        for (int i = 1; i < len; i++) {
            lessThan = lessThan * digits.size() + equal * cntLessThan(strify[i], digits);  // 公式原理在“631”的举例中详细说明了
            equal = equal * isIn(strify[i], digits);
        }
        ans += lessThan + equal;
        return ans;
    }
};
```

![result](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/0050bb334943415bbf7489d1441fe618.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/18/LeetCode%200902.%E6%9C%80%E5%A4%A7%E4%B8%BAN%E7%9A%84%E6%95%B0%E5%AD%97%E7%BB%84%E5%90%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127385999](https://letmefly.blog.csdn.net/article/details/127385999)
