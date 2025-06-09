---
title: 386.字典序排数：细心总结条件
date: 2025-06-09 23:36:33
tags: [题解, LeetCode, 中等, 深度优先搜索, 字典树]
categories: [题解, LeetCode]
---

# 【LetMeFly】386.字典序排数：细心总结条件

力扣题目链接：[https://leetcode.cn/problems/lexicographical-numbers/](https://leetcode.cn/problems/lexicographical-numbers/)

<p>给你一个整数 <code>n</code> ，按字典序返回范围 <code>[1, n]</code> 内所有整数。</p>

<p>你必须设计一个时间复杂度为 <code>O(n)</code> 且使用 <code>O(1)</code> 额外空间的算法。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 13
<strong>输出：</strong>[1,10,11,12,13,2,3,4,5,6,7,8,9]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>[1,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
</ul>


    
## 解题方法：if-else

### 解题思路

使用O(1)的空间和O(n)的时间完成本题，不如先想想字典序下到底是个什么顺序。

1. 首先是1、10、100、...，直到即将大于n为止（假设n=200，那么100即将大于n(100*10=1000)）
2. 100后接着是101、102、...109
3. 109之后是11（而不是110），之后进入第一步(11、110、...)

基本上就这三种情况。

### 具体做法

使用一个变量now记录当前的值，如果$now\times 10\leq n$就让$now\times 10$，否则：

> 就让$now+1$。特别的，在$now+1$之前，若$now$的最后一位已经是$9$或者$now$已经等于了$n$，就不断移除$now$的最后一位(109变成110)。

### 时空复杂度分析

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-06-09 10:09:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-09 10:15:25
 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int now = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = now;
            if (now * 10 <= n) {
                now *= 10;
            } else {
                while (now % 10 == 9 || now == n) {
                    now /= 10;
                }
                now++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-06-09 10:09:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-09 10:21:53
'''
from typing import List

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = [0] * n
        now = 1
        for i in range(n):
            ans[i] = now
            if now * 10 <= n:
                now *= 10
            else:
                while now % 10 == 9 or now == n:
                    now //= 10
                now += 1
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-06-09 10:09:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-09 22:00:48
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>();
        for (int now = 1, i = 0; i < n; i++) {
            ans.add(now);
            if (now * 10 <= n) {
                now *= 10;
            } else {
                while (now % 10 == 9 || now == n) {
                    now /= 10;
                }
                now++;
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
 * @Date: 2025-06-09 10:09:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-06-09 22:03:40
 */
package main

func lexicalOrder(n int) []int {
    ans := make([]int, n)
    for now, i := 1, 0; i < n; i++ {
        ans[i] = now
        if now * 10 <= n {
            now *= 10
        } else {
            for now % 10 == 9 || now == n {
                now /= 10
            }
            now++
        }
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/148545551)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/06/09/LeetCode%200386.%E5%AD%97%E5%85%B8%E5%BA%8F%E6%8E%92%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
