---
title: 3110.字符串的分数：模拟(注意一个小细节)
date: 2025-03-15 10:44:37
tags: [题解, LeetCode, 简单, 字符串]
categories: [题解, LeetCode]
---

# 【LetMeFly】3110.字符串的分数：模拟(注意一个小细节)

力扣题目链接：[https://leetcode.cn/problems/score-of-a-string/](https://leetcode.cn/problems/score-of-a-string/)

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。一个字符串的&nbsp;<strong>分数</strong>&nbsp;定义为相邻字符 <strong>ASCII</strong>&nbsp;码差值绝对值的和。</p>

<p>请你返回 <code>s</code>&nbsp;的 <strong>分数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "hello"</span></p>

<p><span class="example-io"><b>输出：</b>13</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code>&nbsp;中字符的 <strong>ASCII </strong>码分别为：<code>'h' = 104</code>&nbsp;，<code>'e' = 101</code>&nbsp;，<code>'l' = 108</code>&nbsp;，<code>'o' = 111</code>&nbsp;。所以&nbsp;<code>s</code>&nbsp;的分数为&nbsp;<code>|104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "zaz"</span></p>

<p><span class="example-io"><b>输出：</b>50</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code>&nbsp;中字符的 <strong>ASCII&nbsp;</strong>码分别为：<code>'z' = 122</code>&nbsp;，<code>'a' = 97</code>&nbsp;。所以&nbsp;<code>s</code>&nbsp;的分数为&nbsp;<code>|122 - 97| + |97 - 122| = 25 + 25 = 50</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>


    
## 解题方法：模拟

直接从第二个字符开始遍历字符串，将这个字符减去前一个字符的绝对值累加到答案中，最终返回即可。

注意：请谨慎使用8比特数减8比特数（如char - char或byte - byte），因为有的编程语言中8比特数相减不会**类型提升**转为int相减。

如下代码的运行结果为255和255：

```go
package main

import "fmt"

func main() {
	a := byte(1)
	b := byte(2)
	c := a - b
	fmt.Println(c)  // 255
	d := int(c)
	fmt.Println(d)  // 255
}
```

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-15 10:26:54
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-15 10:27:59
 */
#ifdef _WIN32
#include "_[1,2]toVector.h"
#endif

class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            ans += abs(s[i] - s[i - 1]);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-15 10:28:26
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-15 10:28:50
'''
class Solution:
    def scoreOfString(self, s: str) -> int:
        return sum(abs(ord(s[i]) - ord(s[i - 1])) for i in range(1, len(s)))
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-15 10:36:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-15 10:36:23
 */
class Solution {
    public int scoreOfString(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            ans += Math.abs(s.charAt(i) - s.charAt(i - 1));
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-15 10:29:29
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-15 10:32:20
 */
package main

func abs3110(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func scoreOfString(s string) (ans int) {
    for i := 1; i < len(s); i++ {
        ans += abs3110(int(s[i]) - int(s[i - 1]))
    }
    return
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146275888)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/15/LeetCode%203110.%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%88%86%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
