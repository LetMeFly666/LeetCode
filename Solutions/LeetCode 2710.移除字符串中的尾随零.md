---
title: 2710.移除字符串中的尾随零
date: 2024-06-29 17:19:37
tags: [题解, LeetCode, 简单, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2710.移除字符串中的尾随零：模拟

力扣题目链接：[https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/](https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/)

<p>给你一个用字符串表示的正整数 <code>num</code> ，请你以字符串形式返回不含尾随零的整数<em> </em><code>num</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = "51230100"
<strong>输出：</strong>"512301"
<strong>解释：</strong>整数 "51230100" 有 2 个尾随零，移除并返回整数 "512301" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = "123"
<strong>输出：</strong>"123"
<strong>解释：</strong>整数 "123" 不含尾随零，返回整数 "123" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 1000</code></li>
	<li><code>num</code> 仅由数字 <code>0</code> 到 <code>9</code> 组成</li>
	<li><code>num</code> 不含前导零</li>
</ul>


    
## 解题方法：字符串处理（模拟）

从最后一个元素开始向前遍历，遍历到第一个非零元素为止（一定包含非零元素）。

这样就找到了答案字符串的串尾位置，就能返回答案字符串了。

+ 时间复杂度$O(len(num))$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    string removeTrailingZeros(string num) {
        int loc = num.size() - 1;
        while (num[loc] == '0') {
            loc--;
        }
        return num.substr(0, loc + 1);
    }
};
```

#### Go

```go
// package main

func removeTrailingZeros(num string) string {
    loc := len(num) - 1
    for num[loc] == '0' {
        loc--
    }
    return num[0 : loc + 1]
}
```

#### Java

```java
class Solution {
    public String removeTrailingZeros(String num) {
        int loc = num.length() - 1;
        while (num.charAt(loc) == '0') {
            loc--;
        }
        return num.substring(0, loc + 1);
    }
}
```

#### Python

```python
class Solution:
    def removeTrailingZeros(self, num: str) -> str:
        for loc in range(len(num) - 1, -1, -1):
            if num[loc] != '0':
                break
        return num[:loc + 1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/06/29/LeetCode%202710.%E7%A7%BB%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%B0%BE%E9%9A%8F%E9%9B%B6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/140067468](https://letmefly.blog.csdn.net/article/details/140067468)
