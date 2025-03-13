---
title: 788.旋转数字
date: 2022-09-25 20:03:35
tags: [题解, LeetCode, 中等, 数学, 动态规划, 暴力, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】788.旋转数字

力扣题目链接：[https://leetcode.cn/problems/rotated-digits/](https://leetcode.cn/problems/rotated-digits/)

<p>我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。</p>

<p>如果一个数的每位数字被旋转以后仍然还是一个数字，&nbsp;则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。</p>

<p>现在我们有一个正整数&nbsp;<code>N</code>, 计算从&nbsp;<code>1</code> 到&nbsp;<code>N</code> 中有多少个数&nbsp;X 是好数？</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入:</strong> 10
<strong>输出:</strong> 4
<strong>解释:</strong> 
在[1, 10]中有四个好数： 2, 5, 6, 9。
注意 1 和 10 不是好数, 因为他们在旋转之后不变。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>N&nbsp;的取值范围是&nbsp;<code>[1, 10000]</code>。</li>
</ul>


    
## 方法一：暴力模拟

因为$N$的最大取值范围是$10000$，因此从$1$到$N$遍历每一个数，分别判断这个数是否为“好数”即可。

判断一个数是否为“好数”的方法是：

初始时使用一个布尔类型的变量“haveDifferent”代表数字中是否存在“翻转后有效且和翻转前不同的数”，初始值是“false”

取出这个数的每一位，如果这一位是“2、5、6、9”中的一个，就把“haveDifferent”标记为“true”

如果这一位是“0、1、8”中的一个，就不进行任何操作

否则，直接返回“false”（这一位根本不能翻转）

如果看完了每一位，就查看是否存在“翻转后有效且和翻转前不同的数”。

只要存在（haveDifferent为true），整个数就和翻转前不同，就返回true。

否则返回false

+ 时间复杂度$O(N\log_{10}N)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
private:
    bool isGoodNum(int n) {
        bool haveDifferent = false;
        while (n) {
            int t = n % 10;
            n /= 10;
            if (t == 2 || t == 5 || t == 6 || t == 9) {
                haveDifferent = true;
            }
            else if (t == 0 || t == 1 || t == 8) {
                continue;
            }
            else {
                return false;
            }
        }
        return haveDifferent;
    }
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans += isGoodNum(i);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/09/25/LeetCode%200788.%E6%97%8B%E8%BD%AC%E6%95%B0%E5%AD%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127042249](https://letmefly.blog.csdn.net/article/details/127042249)
