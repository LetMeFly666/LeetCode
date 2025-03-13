---
title: 3211.生成不含相邻零的二进制字符串
date: 2024-10-29 23:43:10
tags: [题解, LeetCode, 中等, 位运算, 递归, 字符串, 二进制, 二进制枚举, 枚举]
categories: [题解, LeetCode]
---

# 【LetMeFly】3211.生成不含相邻零的二进制字符串：二进制枚举+位运算优化

力扣题目链接：[https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/](https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros/)

<p>给你一个正整数 <code>n</code>。</p>

<p>如果一个二进制字符串 <code>x</code> 的所有长度为 2 的<span data-keyword="substring-nonempty">子字符串</span>中包含 <strong>至少</strong> 一个 <code>"1"</code>，则称 <code>x</code> 是一个<strong> 有效</strong> 字符串。</p>

<p>返回所有长度为 <code>n</code> 的<strong> 有效</strong> 字符串，可以以任意顺序排列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">["010","011","101","110","111"]</span></p>

<p><strong>解释：</strong></p>

<p>长度为 3 的有效字符串有：<code>"010"</code>、<code>"011"</code>、<code>"101"</code>、<code>"110"</code> 和 <code>"111"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">n = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">["0","1"]</span></p>

<p><strong>解释：</strong></p>

<p>长度为 1 的有效字符串有：<code>"0"</code> 和 <code>"1"</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 18</code></li>
</ul>


    
## 解题方法：二进制枚举

不位运算优化的话其实很简单，从$0$枚举到$2^n-1$，看看哪个数字对应的字符串的二进制没有连续的$0$即可。这样时间复杂度为$n2^n$，$18\times 2^{18}=4,718,592$，完全在合理范围内。

有没有一种办法在$O(1)$的时间复杂度内判定一个数$i$的二进制下有没有连续两个$0$呢？还真有：

> 将$i$二进制下低$n$位取反（$0$变$1$、$1$变$0$），$i$二进制下没有连续两个$0$**等价于**$X$二进制下没有连续两个$1$。
>
> $x$二进制下没有相邻的$1$**等价于**$x \& (x >> 1)=0$。
>
> 因此问题变成了“如何快速将$i$低$n$位取反”。也很简单，$i$异或一个$1111..1$即可。其中$111.1$一共有$n$位，其值等于$(1 << n) - 1$。

+ 时间复杂度$O(2^n)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        int mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            int x = i ^ mask;  // 取反
            if (!(x & (x >> 1))) {
                ans.push_back(bitset<18>(i).to_string().substr(18 - n));
            }
        }
        return ans;
    }
};
```

#### Go

```go
package main

import "fmt"

func validStrings(n int) []string {
    ans := make([]string, 0)
    mask := (1 << n) - 1
    for i := 0; i < (1 << n); i++ {
        x := i ^ mask
        if (x & (x >> 1) == 0) {
            ans = append(ans, fmt.Sprintf("%0*b", n, i))
        }
    }
    return ans
}
```

#### Java

```java
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<String> validStrings(int n) {
        List<String> ans = new ArrayList<>();
        int mask = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            int x = i ^ mask;
            if ((x & (x >> 1)) == 0) {
                ans.add(Integer.toBinaryString((1 << n) | i).substring(1));  // 往n位“带有前导0的二进制”的前面加个1，再去掉
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def validStrings(self, n: int) -> List[str]:
        ans = []
        mask = (1 << n) - 1
        for i in range(1 << n):
            x = i ^ mask
            if not x & (x >> 1):
                ans.append(f'{i:0{n}b}')
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/29/LeetCode%203211.%E7%94%9F%E6%88%90%E4%B8%8D%E5%90%AB%E7%9B%B8%E9%82%BB%E9%9B%B6%E7%9A%84%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143352841](https://letmefly.blog.csdn.net/article/details/143352841)
