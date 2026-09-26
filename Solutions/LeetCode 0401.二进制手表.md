---
title: 401.二进制手表
date: 2022-10-14 11:53:11
tags: [题解, LeetCode, 简单, 位运算, 回溯, 二进制枚举, 状态压缩]
categories: [题解, LeetCode]
---

# 【LetMeFly】两种方法详解：401.二进制手表

力扣题目链接：[https://leetcode.cn/problems/binary-watch/](https://leetcode.cn/problems/binary-watch/)

<p>二进制手表顶部有 4 个 LED 代表<strong> 小时（0-11）</strong>，底部的 6 个 LED 代表<strong> 分钟（0-59）</strong>。每个 LED 代表一个 0 或 1，最低位在右侧。</p>

<ul>
	<li>例如，下面的二进制手表读取 <code>"3:25"</code> 。</li>
</ul>

<!-- <p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/03/29/binary_clock_samui_moon.jpg" style="height: 300px; width" /></p> -->

<p><img src="https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/0e65d0f8c1664633a161c0e67f5e936f.jpeg" style="height: 300px; width" /></p>

<p><small><em>（图源：<a href="https://commons.m.wikimedia.org/wiki/File:Binary_clock_samui_moon.jpg">WikiMedia - Binary clock samui moon.jpg</a> ，许可协议：<a href="https://creativecommons.org/licenses/by-sa/3.0/deed.en">Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0)</a> ）</em></small></p>

<p>给你一个整数 <code>turnedOn</code> ，表示当前亮着的 LED 的数量，返回二进制手表可以表示的所有可能时间。你可以 <strong>按任意顺序</strong> 返回答案。</p>

<p>小时不会以零开头：</p>

<ul>
	<li>例如，<code>"01:00"</code> 是无效的时间，正确的写法应该是 <code>"1:00"</code> 。</li>
</ul>

<p>分钟必须由两位数组成，可能会以零开头：</p>

<ul>
	<li>例如，<code>"10:2"</code> 是无效的时间，正确的写法应该是 <code>"10:02"</code> 。</li>
</ul>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>turnedOn = 1
<strong>输出：</strong>["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>turnedOn = 9
<strong>输出：</strong>[]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= turnedOn <= 10</code></li>
</ul>


    
## 方法一.1：二进制枚举1024种状态，从中选择合法的时和分

一共有10盏灯，每盏灯有开与不开两种状态，也就是说一共有$2^{10}=1024$种状态

因此我们可以枚举这$1024$种状态，对于某种状态，首先判断其中二进制下有多少个$1$，如果$1$的个数恰好和$turnedOn$相同，就把“小时”和“分钟”取出来，看是否为合法时间。

关于如何确定二进制下有多少个$1$，可以参考我的博客：[https://blog.letmefly.xyz/2022/09/28/LeetCode 0338.比特位计数/](https://blog.letmefly.xyz/2022/09/28/LeetCode%200338.%E6%AF%94%E7%89%B9%E4%BD%8D%E8%AE%A1%E6%95%B0/)，这篇博客用三种方法进行了讲解。

怎么取出“小时”和“分钟”呢？我们上述枚举种，可以将4位的“时”作为高4位，6位的“分”作为低6位

那么，想要取出“分”，直接将“状态码”与上一个二进制下的“$111111_{(2)}$”即可。而$111111_{(2)}=(1 << 6) - 1$

想要取出“时”，可以先将高4位取出来（与上一个$1111000000_{(2)}$）。而$1111000000_{(2)}=1111111111_{(2)}-111111_{(2)}=(1 << 10) - 1 - 111111_{(2)}$

取出高4位后，再右移6位，得到的即为“分”

+ 时间复杂度$O(1)$，运算量几乎是固定的，可以理解为$O(1)$
+ 空间复杂度$O(1)$，力扣答案不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        int maskMin = (1 << 6) - 1;
        int maskHour = (1 << 10) - 1 - maskMin;
        for (int state = 0; state < 1024; state++) {
            int cnt1 = 0;
            for (int i = 0; i < 10; i++) {
                if (state & (1 << i)) {
                    cnt1++;
                }
            }
            if (cnt1 != turnedOn) {
                continue;
            }
            int hour = (state & maskHour) >> 6;
            int minute = state & maskMin;
            if (hour < 12 && minute < 60) {
                ans.push_back(to_string(hour) + ':' + (char)(minute / 10 + '0') + (char)(minute % 10 + '0'));
            }
        }
        return ans;
    }
};
```

## 方法一.2：对方法一.1的小简化

总体思路保持不变，但具体细节可以简化。

首先是判断二进制状态码有多少个1，这一点完全可以参考[我博客](https://blog.letmefly.xyz/2022/09/28/LeetCode%200338.%E6%AF%94%E7%89%B9%E4%BD%8D%E8%AE%A1%E6%95%B0/)中的其他方法，比如使用内置函数```__builtin_popcount()```，这就让代码简洁了不少

其次是取出高位的“时”。方法一.1中我们先取出了高4位，之后右移了6位得到了“时”。但是不难发现，既然要右移，那么低6位原本是什么就无关紧要了。因此可以直接状态数右移6位，直接得到“时”。

再次是“分”，因为$111111_{(2)}=63$，所以我们就没有必要再在程序中使用位运算来计算了，可以直接$state \& 63$就得到了“分”

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int mask = 0; mask < 1024; mask++) {
            if (__builtin_popcount(mask) != turnedOn)
                continue;
            int hour = mask >> 6;
            int minute = mask & 63;
            if (hour < 12 && minute < 60) {
                ans.push_back(to_string(hour) + ':' + (char)(minute / 10 + '0') + (char)(minute % 10 + '0'));
            }
        }
        return ans;
    }
};
```

相比于方法一.1，运算量小了一丢丢，代码也简洁了不少。

也可以使用C++20开始的`format`宏进行整数向时间的转换：

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(format("{}:{:02}", h, m));
                }
            }
        }
        return ans;
    }
};
```

## 方法二：枚举合法的时和分，判断二进制下是否恰好为turned个1

方法一中，我们枚举了所有可能的状态，因此还需要判断某种状态是否表示合法的时间。

在方法二中，不如我们换个思路，直接在合法的时间范围内枚举不就好了么。

两层循环，第一层枚举“时”，第二层枚举“分”

这样所有的时间都是合法的了。

再计算“时”和“分”二进制下是否恰好为```trunedOn```个1，如果是，就是答案的情况之一。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int hour = 0; hour < 12; hour++) {
            for (int minute = 0; minute < 60; minute++) {
                if (__builtin_popcount(hour) + __builtin_popcount(minute) == turnedOn) {
                    ans.push_back(to_string(hour) + ':' + (char)(minute / 10 + '0') + (char)(minute % 10 + '0'));
                }
            }
        }
        return ans;
    }
};
```

相比于方法一，运算量再次减少了一些。方法一中枚举了$1024$种可能状态，其中包含一些不合法的时间。

而方法二只枚举了$12\times60=720$种状态，每种枚举的状态都是合法的时间状态。

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/10/14/LeetCode%200401.%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%89%8B%E8%A1%A8/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/127318166](https://letmefly.blog.csdn.net/article/details/127318166)
