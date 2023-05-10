---
title: 670.最大交换
date: 2022-09-13 08:24:45
tags: [题解, LeetCode, 中等, 贪心, 数学]
---

# 【LetMeFly】670.最大交换

力扣题目链接：[https://leetcode.cn/problems/maximum-swap/](https://leetcode.cn/problems/maximum-swap/)

<p>给定一个非负整数，你<strong>至多</strong>可以交换一次数字中的任意两位。返回你能得到的最大值。</p>

<p><strong>示例 1 :</strong></p>

<pre>
<strong>输入:</strong> 2736
<strong>输出:</strong> 7236
<strong>解释:</strong> 交换数字2和数字7。
</pre>

<p><strong>示例 2 :</strong></p>

<pre>
<strong>输入:</strong> 9973
<strong>输出:</strong> 9973
<strong>解释:</strong> 不需要交换。
</pre>

<p><strong>注意:</strong></p>

<ol>
	<li>给定数字的范围是&nbsp;[0, 10<sup>8</sup>]</li>
</ol>


    
## 方法一：两次遍历

要想使得一次交换的结果尽量大，那么越大的数就要尽可能地越靠前。

因此，直接第一层循环枚举“尽可能前”的位置，第二层循环寻找之后的最大且尽可能靠后的元素。

如果找到了比前面大的元素，就交换二者，并返回结果。

+ 时间复杂度$O(\log^2 num)$
+ 空间复杂度$O(\log num)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++) {
            int locM = -1;
            char M = 0;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] > s[i] && s[j] >= M) {
                    locM = j, M = s[j];
                }
            }
            if (locM != -1) {
                swap(s[i], s[locM]);
                return atoi(s.c_str());
            }
        }
        return atoi(s.c_str());
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/13/LeetCode%200670.%E6%9C%80%E5%A4%A7%E4%BA%A4%E6%8D%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126826280](https://letmefly.blog.csdn.net/article/details/126826280)
