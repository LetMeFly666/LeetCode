---
title: 415.字符串相加：模拟实现高精度加法
date: 2023-07-17 08:31:39
tags: [题解, LeetCode, 简单, 数学, 字符串, 模拟, 高精度加法, 高精度]
---

# 【LetMeFly】415.字符串相加：模拟实现高精度加法

力扣题目链接：[https://leetcode.cn/problems/add-strings/](https://leetcode.cn/problems/add-strings/)

<p>给定两个字符串形式的非负整数&nbsp;<code>num1</code> 和<code>num2</code>&nbsp;，计算它们的和并同样以字符串形式返回。</p>

<p>你不能使用任何內建的用于处理大整数的库（比如 <code>BigInteger</code>），&nbsp;也不能直接将输入的字符串转换为整数形式。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = "11", num2 = "123"
<strong>输出：</strong>"134"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = "456", num2 = "77"
<strong>输出：</strong>"533"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num1 = "0", num2 = "0"
<strong>输出：</strong>"0"
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>num1</code> 和<code>num2</code> 都只包含数字&nbsp;<code>0-9</code></li>
	<li><code>num1</code> 和<code>num2</code> 都不包含任何前导零</li>
</ul>


    
## 方法一：模拟实现高精度加法

使用两个指针loc1和loc2分别从两个字符串的最低位不断往高位移动；使用一个变量add来记录每次相加后的进位（初始值为0）。

在```loc1没有指完```或```loc2没有指完```或```add不为0```时，$add += num1[loc1] + num2[loc2]$（如果指针指向位置有效），在答案的高位添加$add \% 10$，之后令$add /= 10$即可。

+ 时间复杂度$O(len(nums1) + len(nums2))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法的空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int loc1 = num1.size() - 1, loc2 = num2.size() - 1;
        int add = 0;
        string ans;
        while (loc1 >= 0 || loc2 >= 0 || add) {
            if (loc1 >= 0) {
                add += num1[loc1--] - '0';
            }
            if (loc2 >= 0) {
                add += num2[loc2--] - '0';
            }
            ans = (char)('0' + add % 10) + ans;
            add /= 10;
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        loc1, loc2 = len(num1) - 1, len(num2) - 1
        add = 0
        ans = ""
        while loc1 >= 0 or loc2 >= 0 or add:
            if loc1 >= 0:
                add += ord(num1[loc1]) - ord('0')
                loc1 -= 1
            if loc2 >= 0:
                add += ord(num2[loc2]) - ord('0')
                loc2 -= 1
            ans = chr(ord('0') + add % 10) + ans
            add //= 10
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/17/LeetCode%200415.%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9B%B8%E5%8A%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131758488](https://letmefly.blog.csdn.net/article/details/131758488)
