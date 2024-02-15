---
title: 481.神奇字符串
date: 2022-10-28 08:58:59
tags: [题解, LeetCode, 中等, 双指针, 字符串]
---

# 【LetMeFly】481.神奇字符串

力扣题目链接：[https://leetcode.cn/problems/magical-string/](https://leetcode.cn/problems/magical-string/)

<p>神奇字符串 <code>s</code> 仅由 <code>'1'</code> 和 <code>'2'</code> 组成，并需要遵守下面的规则：</p>

<ul>
	<li>神奇字符串 s 的神奇之处在于，串联字符串中 <code>'1'</code> 和 <code>'2'</code> 的连续出现次数可以生成该字符串。</li>
</ul>

<p><code>s</code> 的前几个元素是 <code>s = "1221121221221121122……"</code> 。如果将 <code>s</code> 中连续的若干 <code>1</code> 和 <code>2</code> 进行分组，可以得到 <code>"1 22 11 2 1 22 1 22 11 2 11 22 ......"</code> 。每组中 <code>1</code> 或者 <code>2</code> 的出现次数分别是 <code>"1 2 2 1 1 2 1 2 2 1 2 2 ......"</code> 。上面的出现次数正是 <code>s</code> 自身。</p>

<p>给你一个整数 <code>n</code> ，返回在神奇字符串 <code>s</code> 的前 <code>n</code> 个数字中 <code>1</code> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>3
<strong>解释：</strong>神奇字符串 s 的前 6 个元素是 “<code>122112</code>”，它包含三个 1，因此返回 3 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：双指针

我们把神奇字符串“1221121221221121122”称为原始串，把分组后的字符串“1 2 2 1 1”称为新串。（虽然二者相同，但我们仍然加以区分）

我们用一个“指针”```locFront```指向“新串”该生成的位置，用一个“指针”```locEnd```指向“原始串”处理到的位置

当原始串处理到$n-1$时，我们就处理（且知道）了原始串前$n$个字符，就知道了前$n$个字符中有多少个“1”

初始时我们知道原始串的前三个字符“122”，其对应新串为“1 2”（```1```个1，```2```个2）

原始串该处理第$4$个字符（下标为$3$），新串该处理第$3$个字符（下标为$2$）

因此，初始值$locFront = 2, locEnd = 3$

之后由“新串”该生成的位置，我们就能求得“原始串”应由一个还是两个连续的字符组成

例如新串的第三个字符应该是“2”，从而我们得知原始串应该再接“2”个1

如此进行下去，我们就得知了原始串的前$n$个字符。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
char str[100010] = "122";
class Solution {
public:
    int magicalString(int n) {
        int locFront = 2, locEnd = 3;
        char nowChar = '1';
		// 摸清原始串的前n个字符
        while (locEnd < n) {
            for (int i = str[locFront] - '0'; i > 0; i--) {
                str[locEnd++] = nowChar;
            }
            locFront++;
            nowChar = nowChar == '1' ? '2' : '1';
        }
        // 统计开始
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += str[i] == '1';
        }
        return ans;
    }
};
```

**What's more**

这道题每次测试 原始串都是相同的

因此我们也可以只进行一次求串操作（第一次调用这个类时，求出原始串的前$10^5$个字符），之后直接统计即可。

```cpp
// SecondTry  // 坏人做法：只求一次，后续只统计
// 坏坏方法，但是对执行结果的影响不大（数据不多，如果有几千组数据，那么这种坏方法的执行总时间将会大大减少）
char str[100010] = "122";
class Solution {
public:
    int magicalString(int n) {
        static bool first = true;
        if (first) {
            first = false;
            int locFront = 2, locEnd = 3;
            char nowChar = '1';
            while (locEnd < 100000) {
                for (int i = str[locFront] - '0'; i > 0; i--) {
                    str[locEnd++] = nowChar;
                }
                locFront++;
                nowChar = nowChar == '1' ? '2' : '1';
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += str[i] == '1';
        }
        return ans;
    }
};
```

对于这种初始化方法，[@Lin](https://leetcode.cn/u/lin-uu1/) 提供了一种方法：

```cpp
char str[100010] = "122";
int init = []() {
    int locFront = 2, locEnd = 3;
    char nowChar = '1';
    while (locEnd < 100000) {
        for (int i = str[locFront] - '0'; i > 0; i--) {
            str[locEnd++] = nowChar;
        }
        locFront++;
        nowChar = nowChar == '1' ? '2' : '1';
    }
    return 0;
}();


class Solution {
public:
    int magicalString(int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += str[i] == '1';
        }
        return ans;
    }
};
```

其中

```cpp
[]() {
    // ....
}
```

为C++ lambda函数

而其后紧接着跟随一个```()```表示对这个函数的调用。

因其处在全局变量中，故这个函数只执行一次。

![result](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/f466a3a26cf64844966b16fd3682efbf.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/28/LeetCode%200481.%E7%A5%9E%E5%A5%87%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127565144](https://letmefly.blog.csdn.net/article/details/127565144)
