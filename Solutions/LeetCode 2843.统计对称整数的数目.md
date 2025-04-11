---
title: 2843.统计对称整数的数目：字符串数字转换
date: 2025-04-11 21:28:52
tags: [题解, LeetCode, 简单, 数学, 枚举, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】2843.统计对称整数的数目：字符串数字转换

力扣题目链接：[https://leetcode.cn/problems/count-symmetric-integers/](https://leetcode.cn/problems/count-symmetric-integers/)

<p>给你两个正整数 <code>low</code> 和 <code>high</code> 。</p>

<p>对于一个由 <code>2 * n</code> 位数字组成的整数 <code>x</code> ，如果其前 <code>n</code> 位数字之和与后 <code>n</code> 位数字之和相等，则认为这个数字是一个对称整数。</p>

<p>返回在 <code>[low, high]</code> 范围内的 <strong>对称整数的数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>low = 1, high = 100
<strong>输出：</strong>9
<strong>解释：</strong>在 1 到 100 范围内共有 9 个对称整数：11、22、33、44、55、66、77、88 和 99 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>low = 1200, high = 1230
<strong>输出：</strong>4
<strong>解释：</strong>在 1200 到 1230 范围内共有 4 个对称整数：1203、1212、1221 和 1230 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= low &lt;= high &lt;= 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：模拟

如何判断一个数字是否为“对称整数“？

> 首先将数字转为字符串，如果字符串长度为奇数则一定不是。
>
> 否则遍历到字符串的一半位置，使用一个变量cnt，加上s[i]并减去s[len(s) - i - 1]，最终看cnt是否为0。

+ 时间复杂度$O(high\times \log high)$
+ 空间复杂度$O(\log high)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-04-11 21:02:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-11 21:06:39
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    bool isOk(int n) {
        string temp = to_string(n);
        if (temp.size() % 2) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < temp.size() / 2; i++) {
            cnt += temp[i] - temp[temp.size() - i - 1];  // 不用转为对应的数字就行
        }
        return cnt == 0;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans += isOk(i);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-04-11 21:07:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-11 21:09:06
'''
class Solution:
    def isOk(self, n: int) -> bool:
        s = str(n)
        if len(s) % 2:
            return False
        cnt = 0
        for i in range(len(s) // 2):
            cnt += ord(s[i]) - ord(s[-i - 1])
        return cnt == 0
    
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        return sum(self.isOk(i) for i in range(low, high + 1))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-04-11 21:13:44
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-11 21:17:40
 */
class Solution {
    private int isOk(int n) {
        String s = String.valueOf(n);
        if (s.length() % 2 == 1) {
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            cnt += s.charAt(i) - s.charAt(s.length() - i - 1);
        }
        return cnt != 0 ? 0 : 1;
    }

    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans += isOk(i);
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-04-11 21:19:27
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-04-11 21:26:25
 */
package main

import (
    // "fmt"
    "strconv"
)

func isOK2843(n int) int {
    s := strconv.Itoa(n)
    if len(s) % 2 == 1 {
        return 0
    }
    cnt := 0
    for i := 0; i < len(s) / 2; i++ {
        cnt += int(s[i]) - int(s[len(s) - i - 1])  // 不能int(s[i] - s[len(s) - i - 1])
    }
    if cnt == 0 {
        return 1
    }
    return 0
}

func countSymmetricIntegers(low int, high int) (ans int) {
    for i := low; i <= high; i++ {
        // fmt.Println(i, isOK2843(i))
        ans += isOK2843(i)
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147154718)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/04/11/LeetCode%202843.%E7%BB%9F%E8%AE%A1%E5%AF%B9%E7%A7%B0%E6%95%B4%E6%95%B0%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
