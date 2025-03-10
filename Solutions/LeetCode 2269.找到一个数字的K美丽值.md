---
title: 2269.找到一个数字的 K 美丽值：字符串数字转换(模拟)
date: 2025-03-10 12:51:23
tags: [题解, LeetCode, 简单, 字符串]
---

# 【LetMeFly】2269.找到一个数字的 K 美丽值：字符串数字转换(模拟)

力扣题目链接：[https://leetcode.cn/problems/find-the-k-beauty-of-a-number/](https://leetcode.cn/problems/find-the-k-beauty-of-a-number/)

<p>一个整数 <code>num</code>&nbsp;的&nbsp;<strong>k&nbsp;</strong>美丽值定义为&nbsp;<code>num</code>&nbsp;中符合以下条件的&nbsp;<strong>子字符串</strong>&nbsp;数目：</p>

<ul>
	<li>子字符串长度为&nbsp;<code>k</code>&nbsp;。</li>
	<li>子字符串能整除 <code>num</code> 。</li>
</ul>

<p>给你整数&nbsp;<code>num</code> 和&nbsp;<code>k</code>&nbsp;，请你返回<em>&nbsp;</em><code>num</code>&nbsp;的 k 美丽值。</p>

<p>注意：</p>

<ul>
	<li>允许有&nbsp;<strong>前缀</strong>&nbsp;<strong>0</strong>&nbsp;。</li>
	<li><code>0</code>&nbsp;不能整除任何值。</li>
</ul>

<p>一个 <strong>子字符串</strong>&nbsp;是一个字符串里的连续一段字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = 240, k = 2
<b>输出：</b>2
<b>解释：</b>以下是 num 里长度为 k 的子字符串：
- "<em><strong>24</strong></em>0" 中的 "24" ：24 能整除 240 。
- "2<em><strong>40</strong></em>" 中的 "40" ：40 能整除 240 。
所以，k 美丽值为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = 430043, k = 2
<b>输出：</b>2
<b>解释：</b>以下是 num 里长度为 k 的子字符串：
- "<em><strong>43</strong></em>0043" 中的 "43" ：43 能整除 430043 。
- "4<em><strong>30</strong></em>043" 中的 "30" ：30 不能整除 430043 。
- "43<em><strong>00</strong></em>43" 中的 "00" ：0 不能整除 430043 。
- "430<em><strong>04</strong></em>3" 中的 "04" ：4 不能整除 430043 。
- "4300<em><strong>43</strong></em>" 中的 "43" ：43 能整除 430043 。
所以，k 美丽值为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= num.length</code>&nbsp;（将&nbsp;<code>num</code>&nbsp;视为字符串）</li>
</ul>


    
## 解题方法：字符串数字转换

数据范围很小，直接按照题意将数字转为字符串和将字符串转为数字即可。

+ 时间复杂度$O(len(num)\times k)$
+ 空间复杂度$O(len(num))$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-10 12:36:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-10 12:41:03
 */
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        for (int i = 0; i + k <= s.size(); i++) {
            int thisNum = 0;
            for (int j = 0; j < k; j++) {
                thisNum = thisNum * 10 + s[i + j] - '0';
            }
            ans += thisNum && (num % thisNum == 0);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-10 12:43:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-10 12:44:22
'''
class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        ans = 0
        for i in range(len(s) - k + 1):
            thisNum = 0
            for j in range(k):
                thisNum = thisNum * 10 + ord(s[i + j]) - 48
            ans += thisNum and num % thisNum == 0
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-10 12:48:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-10 12:49:58
 */
class Solution {
    public int divisorSubstrings(int num, int k) {
        String s = String.valueOf(num);
        int ans = 0;
        for (int i = 0; i < s.length() - k + 1; i++) {
            int thisNum = Integer.parseInt(s.substring(i, i + k));
            if (thisNum > 0 && num % thisNum == 0) {
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-10 12:46:00
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-10 12:47:20
 */
package main

import "strconv"

func divisorSubstrings(num int, k int) (ans int) {
    s := strconv.Itoa(num)
    for i := 0; i < len(s) - k + 1; i++ {
        thisNum, _ := strconv.Atoi(s[i:i + k])
        if thisNum > 0 && num % thisNum == 0 {
            ans++
        }
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146151402)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/10/LeetCode%202269.%E6%89%BE%E5%88%B0%E4%B8%80%E4%B8%AA%E6%95%B0%E5%AD%97%E7%9A%84K%E7%BE%8E%E4%B8%BD%E5%80%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
