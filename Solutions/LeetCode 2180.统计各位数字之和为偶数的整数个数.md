---
title: 2180.统计各位数字之和为偶数的整数个数
date: 2023-01-06 19:04:54
tags: [题解, LeetCode, 简单, 数学, 模拟, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】2180.统计各位数字之和为偶数的整数个数

力扣题目链接：[https://leetcode.cn/problems/count-integers-with-even-digit-sum/](https://leetcode.cn/problems/count-integers-with-even-digit-sum/)

<p>给你一个正整数 <code>num</code> ，请你统计并返回 <strong>小于或等于</strong> <code>num</code> 且各位数字之和为 <strong>偶数</strong> 的正整数的数目。</p>

<p>正整数的 <strong>各位数字之和</strong> 是其所有位上的对应数字相加的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 4
<strong>输出：</strong>2
<strong>解释：</strong>
只有 2 和 4 满足小于等于 4 且各位数字之和为偶数。    
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 30
<strong>输出：</strong>14
<strong>解释：</strong>
只有 14 个整数满足小于等于 30 且各位数字之和为偶数，分别是： 
2、4、6、8、11、13、15、17、19、20、22、24、26 和 28 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 1000</code></li>
</ul>


    
## 方法一：遍历模拟

我们只需要从1到num遍历一遍（使用变量i来遍历），对于每个正在遍历的数，统计这个数在十进制下的各位数之和（如果是偶数则答案数量加一）

怎么计算一个数在十进制下每一位之和呢？

很简单，在这个数不为0时，不断取出这个数的个位（这个数对10取模），然后将这个数除以10（并向下取整）即可（这样相当于是丢掉了各个位）。

```cpp
// 统计thisNum在十进制下的各位数之和
int cnt = 0;
while (thisNum) {
    cnt += thisNum % 10;
    thisNum /= 10;
}
ans += cnt % 2 == 0;
```

+ 时间复杂度$O(num\times \log(num))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; i++) {
            int cnt = 0, thisNum = i;
            while (thisNum) {
                cnt += thisNum % 10;
                thisNum /= 10;
            }
            ans += cnt % 2 == 0;
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/01/06/LeetCode%202180.%E7%BB%9F%E8%AE%A1%E5%90%84%E4%BD%8D%E6%95%B0%E5%AD%97%E4%B9%8B%E5%92%8C%E4%B8%BA%E5%81%B6%E6%95%B0%E7%9A%84%E6%95%B4%E6%95%B0%E4%B8%AA%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128583772](https://letmefly.blog.csdn.net/article/details/128583772)
