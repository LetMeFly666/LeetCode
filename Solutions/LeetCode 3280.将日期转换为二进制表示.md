---
title: 3280.将日期转换为二进制表示
date: 2025-01-01 18:59:51
tags: [题解, LeetCode, 简单, 数学, 字符串, 进制转换]
categories: [题解, LeetCode]
---

# 【LetMeFly】3280.将日期转换为二进制表示：库函数实现或手动转换

力扣题目链接：[https://leetcode.cn/problems/convert-date-to-binary/](https://leetcode.cn/problems/convert-date-to-binary/)

<p>给你一个字符串 <code>date</code>，它的格式为 <code>yyyy-mm-dd</code>，表示一个公历日期。</p>

<p><code>date</code> 可以重写为二进制表示，只需要将年、月、日分别转换为对应的二进制表示（不带前导零）并遵循 <code>year-month-day</code> 的格式。</p>

<p>返回 <code>date</code> 的 <strong>二进制</strong> 表示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">date = "2080-02-29"</span></p>

<p><strong>输出：</strong> <span class="example-io">"100000100000-10-11101"</span></p>

<p><strong>解释：</strong></p>

<p><span class="example-io">100000100000, 10 和 11101 分别是 2080, 02 和 29 的二进制表示。</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">date = "1900-01-01"</span></p>

<p><strong>输出：</strong> <span class="example-io">"11101101100-1-1"</span></p>

<p><strong>解释：</strong></p>

<p><span class="example-io">11101101100, 1 和 1 分别是 1900, 1 和 1 的二进制表示。</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == '-'</code>，其余的 <code>date[i]</code> 都是数字。</li>
	<li>输入保证 <code>date</code> 代表一个有效的公历日期，日期范围从 1900 年 1 月 1 日到 2100 年 12 月 31 日（包括这两天）。</li>
</ul>


    
## 解题方法：进制转换

如果手动将一个十进制字符串转换为一个二进制字符串，应如何做？

首先将字符串转为十进制数：

> 十进制数初始值为0，遍历字符串，每次十进制数乘以10并加上当前遍历到的字符对应的数字。

接着将十进制数转为二进制字符串：

> 在十进制数不为零时，不断将十进制数对2取模后的结果添加到二进制字符串的头部，然后将十进制数除以2。

当然，现在很多主流的编程语言都有库函数以更加方便地实现。

+ 时间复杂度$O(C)$，其中$C=len(s)=10$
+ 空间复杂度$O(C)$

### AC代码

#### C++ - 手动转换版本

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:36:02
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:41:24
 */
class Solution {
private:
    string ten2two(string original) {
        int ten = 0;
        for (char c : original) {
            ten = ten * 10 + c - '0';
        }
        string ans;
        while (ten) {
            ans = char(ten % 2 + '0') + ans;
            ten >>= 1;
        }
        return ans;
    }
public:
    string convertDateToBinary(string date) {
        return ten2two(date.substr(0, 4)) + '-' + ten2two(date.substr(5, 2)) + '-' + ten2two(date.substr(8, 2));
    }
};
```

#### C++ - 库函数版本

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:43:56
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:48:09
 */
class Solution {
private:
    string ten2two(string s) {
        int a = stoi(s);
        string temp = bitset<32>(a).to_string();
        return temp.substr(temp.find('1'));
    }
public:
    string convertDateToBinary(string date) {
        return ten2two(date.substr(0, 4)) + '-' + ten2two(date.substr(5, 2)) + '-' + ten2two(date.substr(8, 2));
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-01-01 18:49:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-01 18:50:23
'''
class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return '-'.join(bin(int(s))[2:] for s in date.split('-'))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:51:17
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:52:45
 */
class Solution {
    public String convertDateToBinary(String date) {
        String[] a = date.split("-");
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.toBinaryString(Integer.parseInt(a[i]));
        }
        return String.join("-", a);
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-01 18:54:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-01 18:57:15
 */
package main

import (
	"strconv"
	"strings"
)

func convertDateToBinary(date string) string {
    a := strings.Split(date, "-")
    for i := range a {
        x, _ := strconv.Atoi(a[i])
        a[i] = strconv.FormatUint(uint64(x), 2)
    }
    return strings.Join(a, "-")
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/01/LeetCode%203280.%E5%B0%86%E6%97%A5%E6%9C%9F%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E8%BF%9B%E5%88%B6%E8%A1%A8%E7%A4%BA/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144870892](https://letmefly.blog.csdn.net/article/details/144870892)
