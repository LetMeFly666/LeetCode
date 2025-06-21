---
title: 1432.改变一个整数能得到的最大差值：暴力模拟/贪心
date: 2025-06-21 14:41:16
tags: [题解, LeetCode, 中等, 贪心, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1432.改变一个整数能得到的最大差值：暴力模拟/贪心

力扣题目链接：[https://leetcode.cn/problems/max-difference-you-can-get-from-changing-an-integer/](https://leetcode.cn/problems/max-difference-you-can-get-from-changing-an-integer/)

<p>给你一个整数&nbsp;<code>num</code>&nbsp;。你可以对它进行如下步骤恰好 <strong>两次</strong>&nbsp;：</p>

<ul>
	<li>选择一个数字&nbsp;<code>x (0&nbsp;&lt;= x &lt;= 9)</code>.</li>
	<li>选择另一个数字&nbsp;<code>y (0&nbsp;&lt;= y &lt;= 9)</code>&nbsp;。数字&nbsp;<code>y</code>&nbsp;可以等于&nbsp;<code>x</code>&nbsp;。</li>
	<li>将 <code>num</code>&nbsp;中所有出现 <code>x</code>&nbsp;的数位都用 <code>y</code>&nbsp;替换。</li>
	<li>得到的新的整数 <strong>不能</strong>&nbsp;有前导 0 ，得到的新整数也 <strong>不能</strong>&nbsp;是 0&nbsp;。</li>
</ul>

<p>令两次对 <code>num</code>&nbsp;的操作得到的结果分别为&nbsp;<code>a</code>&nbsp;和&nbsp;<code>b</code>&nbsp;。</p>

<p>请你返回&nbsp;<code>a</code> 和&nbsp;<code>b</code>&nbsp;的 <strong>最大差值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>num = 555
<strong>输出：</strong>888
<strong>解释：</strong>第一次选择 x = 5 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 5 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 999 和 b = 111 ，最大差值为 888
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>num = 9
<strong>输出：</strong>8
<strong>解释：</strong>第一次选择 x = 9 且 y = 9 ，并把得到的新数字保存在 a 中。
第二次选择 x = 9 且 y = 1 ，并把得到的新数字保存在 b 中。
现在，我们有 a = 9 和 b = 1 ，最大差值为 8
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>num = 123456
<strong>输出：</strong>820000
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>num = 10000
<strong>输出：</strong>80000
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>num = 9288
<strong>输出：</strong>8700
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10^8</code></li>
</ul>


    
## 解题方法一：暴力模拟

从0到9模x，从0到9模拟y，(如果x出现过则)将所有x替换为y，就能得到一个新数字。

在所有的新数字中，返回其中最大数和最小数之差。

+ 时间复杂度$O(C^2\log num)$，其中C=10
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-15 22:35:58
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-17 23:50:02
 */
class Solution {
private:
    inline bool isIn(string s, char c) {
        for (char t : s) {
            if (t == c) {
                return true;
            }
        }
        return false;
    }

    inline string replace(string s, char a, char b) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == a) {
                s[i] = b;
            }
        }
        return s;
    }
public:
    int maxDiff(int num) {
        int m = 100000000, M = 0;
        string s = to_string(num);
        for (int a = 0; a < 10; a++) {
            if (!isIn(s, '0' + a)) {
                continue;
            }
            for (int b = 0; b < 10; b++) {
                string x = replace(s, '0' + a, '0' + b);
                if (x[0] == '0') {
                    continue;
                }
                int val = atoi(x.c_str());
                m = min(m, val);
                M = max(M, val);
            }
        }
        return M - m;
    }
};
```

## 解题方法二：贪心

如何将num变得尽可能大？

> 前面的数哪怕变大一点(8->9)也比后面的数变大很多(0->9)更优(80->90比80->89更优)。
>
> 所以只需要将num中第一个非9数字全部变为9即可。

如何将num变得尽可能小？

> 题目要求不能包含前导零。
>
> + 如果num的最高位不是1，那么将所有值为num最高位的数变成1即可；
>
> + 否则，将第一个大于1的数字全部变为0即可(首位是1，所以不能将1变成0，只能将大于1的数变成0)。

+ 时间复杂度$O(\log num)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-19 10:28:35
 */
// max->第一个非9的值全改为9
// min->第一位如果是1，将第一个大于1的值全改为0；否则，将第一位的值全改为1
class Solution {
private:
    int firstNot9(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '9') {
                return i;
            }
        }
        return -1;
    }

    int firstNot01(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > '1') {
                return i;
            }
        }
        return -1;
    }

    int change(string s, char a, char b) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == a) {
                s[i] = b;
            }
        }
        return atoi(s.c_str());
    }
public:
    int maxDiff(int num) {
        int M, m;
        string s = to_string(num);
        int index = firstNot9(s);
        M = index < 0 ? num : change(s, s[index], '9');
        if (s[0] != '1') {
            m = change(s, s[0], '1');
        } else {
            index = firstNot01(s);
            m = index < 0 ? num : change(s, s[index], '0');
        }
        return M - m;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-06-19 10:16:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-19 10:35:59
'''
# M: !9 -> 9
# m: first == 1 ? (!01 -> 0) : (first->1)
class Solution:
    def firstN9(self, s: str) -> int:
        for i, c in enumerate(s):
            if c != '9':
                return i
        return -1
    
    def firstN01(self, s: str) -> int:
        for i, c in enumerate(s):
            if c != '0' and c != '1':
                return i
        return -1
    
    def change(self, s: str, a: str, b: str) -> int:
        li = list(s)
        for i, c in enumerate(li):
            if c == a:
                li[i] = b
        return int(''.join(li))
    
    def maxDiff(self, num: int) -> int:
        M = m = 0
        s = str(num)
        index = self.firstN9(s)
        M = num if index < 0 else self.change(s, s[index], '9')
        if s[0] == '1':
            index = self.firstN01(s)
            m = num if index < 0 else self.change(s, s[index], '0')
        else:
            m = self.change(s, s[0], '1')
        return M - m
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-21 14:38:38
 */
// M: !9->9
// m: first==1 ? !01->0 : first->1
class Solution {
    private int not9(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '9') {
                return i;
            }
        }
        return -1;
    }

    private int not01(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) > '1') {
                return i;
            }
        }
        return -1;
    }

    private int replace(String s, char a, char b) {
        return Integer.parseInt(s.replace(a, b));
    }
    public int maxDiff(int num) {
        int M, m;
        String s = String.valueOf(num);
        int index = not9(s);
        M = index == -1 ? num : replace(s, s.charAt(index), '9');
        if (s.charAt(0) == '1') {
            index = not01(s);
            m = index == -1 ? num : replace(s, s.charAt(index), '0');
        } else {
            m = replace(s, s.charAt(0), '1');
        }
        return M - m;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-06-19 10:16:46
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-21 11:33:06
 */
package main

import (
	"strconv"
	"strings"
)

// M: !9->9
// m: first==1 ? !01->0 : first->1
func maxDiff(num int) int {
    s := strconv.Itoa(num)  // 不可！： s := string(num)
    M, m := num, num
    change := func(s string, a, b byte) int {
        ans, _ := strconv.Atoi(strings.ReplaceAll(s, string(a), string(b)))
        return ans
    }
    for i := range s {
        if s[i] != '9' {
            M = change(s, s[i], '9')
            break
        }
    }
    if s[0] == '1' {
        for i := range s {
            if s[i] > '1' {
                m = change(s, s[i], '0')
                break
            }
        }
    } else {
        m = change(s, s[0], '1')
    }
    return M - m
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148811010)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/19/LeetCode%201432.%E6%94%B9%E5%8F%98%E4%B8%80%E4%B8%AA%E6%95%B4%E6%95%B0%E8%83%BD%E5%BE%97%E5%88%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E5%B7%AE%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
