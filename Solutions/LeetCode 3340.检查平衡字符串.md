---
title: 3340.检查平衡字符串：模拟
date: 2025-03-14 09:39:25
tags: [题解, LeetCode, 简单, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】3340.检查平衡字符串：模拟

力扣题目链接：[https://leetcode.cn/problems/check-balanced-string/](https://leetcode.cn/problems/check-balanced-string/)

<p>给你一个仅由数字 0 - 9 组成的字符串 <code>num</code>。如果偶数下标处的数字之和等于奇数下标处的数字之和，则认为该数字字符串是一个 <b>平衡字符串</b>。</p>

<p>如果 <code>num</code> 是一个 <strong>平衡字符串</strong>，则返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>num<span class="example-io"> = "1234"</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>偶数下标处的数字之和为 <code>1 + 3 = 4</code>，奇数下标处的数字之和为 <code>2 + 4 = 6</code>。</li>
	<li>由于 4 不等于 6，<code>num</code> 不是平衡字符串。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong>num<span class="example-io"> = "24123"</span></p>

<p><strong>输出：</strong>true</p>

<p><strong>解释：</strong></p>

<ul>
	<li>偶数下标处的数字之和为 <code>2 + 1 + 3 = 6</code>，奇数下标处的数字之和为 <code>4 + 2 = 6</code>。</li>
	<li>由于两者相等，<code>num</code> 是平衡字符串。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= num.length &lt;= 100</code></li>
	<li><code>num</code> 仅由数字 0 - 9 组成。</li>
</ul>


    
## 解题方法：遍历求和

使用一个整型变量$cnt$来统计结果即可。遍历字符串，遇到奇数下标则加上当前字符对应的数字，否则减去之。最终判断$cnt$是否为$0$。

+ 时间复杂度$O(len(num))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-14 09:30:43
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-14 09:32:51
 */
class Solution {
public:
    bool isBalanced(string num) {
        int cnt = 0;
        for (int i = 0; i < num.size(); i++) {
            cnt += i % 2 ? (num[i] - '0') : -(num[i] - '0');
        }
        return cnt == 0;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-14 09:34:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-14 09:34:04
'''
class Solution:
    def isBalanced(self, num: str) -> bool:
        cnt = 0
        for i, c in enumerate(num):
            cnt += ord(c) - 48 if i % 2 else 48 - ord(c)
        return cnt == 0
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-14 09:35:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-14 09:35:26
 */
class Solution {
    public boolean isBalanced(String num) {
        int cnt = 0;
        for (int i = 0; i < num.length(); i++) {
            if (i % 2 == 0) {
                cnt += num.charAt(i) - 48;
            } else {
                cnt -= num.charAt(i) - 48;
            }
        }
        return cnt == 0;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-14 09:36:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-14 09:38:01
 */
package main

func isBalanced(num string) bool {
    cnt := 0
    for i, c := range num {
        if i % 2 == 0 {
            cnt += int(c) - 48
        } else {
            cnt -= int(c) - 48
        }
    }
    return cnt == 0
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146249653)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/14/LeetCode%203340.%E6%A3%80%E6%9F%A5%E5%B9%B3%E8%A1%A1%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
