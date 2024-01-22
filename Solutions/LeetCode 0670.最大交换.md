---
title: 670.最大交换
date: 2022-09-13 08:24:45
tags: [题解, LeetCode, 中等, 贪心, 数学, 暴力]
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



## 方法一：两层遍历 + 暴力

二话不说直接枚举两个要交换的位置，交换之并取所有结果中最大的一个作为答案返回。

### AC代码

#### Python

```python
class Solution:
    def maximumSwap(self, num: int) -> int:
        ans = num
        s = str(num)
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                temp = list(s)
                temp[i], temp[j] = temp[j], temp[i]
                ans = max(ans, int(''.join(temp)))
        return ans
```

+ 时间复杂度$O(\log^2 num)$
+ 空间复杂度$O(\log num)$

如果再加上一点小贪心，就变成了方法二（方法二相比于方法一而言实现起来变复杂了，但是可能提前结束循环）
    
## 方法二：两层遍历 + 贪心

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

2024.1.22日看上述提交代码，执行耗时0ms击败```100.00%```使用C++的用户，消耗内存5.70MB击败```100.00%```使用C++的用户。

小数据下复杂度低不一定慢，但面试的话可能会问有无复杂的更低的算法。

## 方法三：一层遍历 + 贪心

类似方法一：

> 要想使得一次交换的结果尽量大，那么越大的数就要尽可能地越靠前。

将数字（字符串的形式）分为两部分：前面非递增的一部分 + 后续部分。例如```998755738786```可以分为```998755```和```738786```两部分。

两个元素的交换肯定不会**都**在第一部分的非递增区域，一定发生在第二部分和第一部分之间。

假设第二部分的最大的数（如有同大取其后）的位置是```loc2```，第一个小于```num[loc2]```的数的位置是```loc1```（一定在第一部分），则交换```num[loc1]```和```num[loc2]```既能得到最大的数。

+ 时间复杂度$O(\log num)$
+ 空间复杂度$O(\log num)$

### AC代码

#### C++

```cpp
class Solution {
private:
    string s;
    
    int getFirstIncreaseLoc() {
        for (int i = 1; i < s.size(); i++) {
            if (s[i] > s[i - 1]) {
                return i;
            }
        }
        return s.size();
    }
    
    int getMaxLocFromA(int a) {
        int ans = a;
        int M = s[a];
        for (; a < s.size(); a++) {
            if (s[a] >= M) {
                ans = a;
                M = s[a];
            }
        }
        return ans;
    }

    int getFirstLessthanLoc(char n) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < n) {
                return i;
            }
        }
        return s.size();  // Fake Return
    }
public:
    int maximumSwap(int num) {
        s = to_string(num);
        int firstIncreaseLoc = getFirstIncreaseLoc();  // 将字符串分为两部分
        if (firstIncreaseLoc == s.size()) {
            return num;
        }
        int maxLoc = getMaxLocFromA(firstIncreaseLoc);  // 第二部分的最大的位置
        int firstLessthanLoc = getFirstLessthanLoc(s[maxLoc]);  // 第一部分第一个小于num[maxLoc]的数
        swap(s[firstLessthanLoc], s[maxLoc]);  // 交换之
        return atoi(s.c_str());
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/09/13/LeetCode%200670.%E6%9C%80%E5%A4%A7%E4%BA%A4%E6%8D%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126826280](https://letmefly.blog.csdn.net/article/details/126826280)
