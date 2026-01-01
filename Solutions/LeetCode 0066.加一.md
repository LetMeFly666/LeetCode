---
title: 66.加一：模拟（附简单题必备——Python一行版）
date: 2026-01-01 16:11:02
tags: [题解, LeetCode, 简单, 数组, 数学, 高精度, 高精度加法]
categories: [题解, LeetCode]
---

# 【LetMeFly】66.加一：模拟（附简单题必备——Python一行版）

力扣题目链接：[https://leetcode.cn/problems/plus-one/](https://leetcode.cn/problems/plus-one/)

<p>给定一个表示 <strong>大整数</strong> 的整数数组 <code>digits</code>，其中 <code>digits[i]</code> 是整数的第 <code>i</code> 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 <code>0</code>。</p>

<p>将大整数加 1，并返回结果的数字数组。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>digits = [1,2,3]
<strong>输出：</strong>[1,2,4]
<strong>解释：</strong>输入数组表示数字 123。
加 1 后得到 123 + 1 = 124。
因此，结果应该是 [1,2,4]。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>digits = [4,3,2,1]
<strong>输出：</strong>[4,3,2,2]
<strong>解释：</strong>输入数组表示数字 4321。
加 1 后得到 4321 + 1 = 4322。
因此，结果应该是 [4,3,2,2]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = [9]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>输入数组表示数字 9。
加 1 得到了 9 + 1 = 10。
因此，结果应该是 [1,0]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
	<li><code>digits</code>&nbsp;不包含任何前导 <code>0</code>。</li>
</ul>


    
## 解题方法：模拟

使用一个初始值为$1$的整数`cnt`代表加法运算过程中的进位值，然后就可以愉快地开始模拟啦！

幼儿园学习加法的过程中我们了解到，多位数加上一个个位数，将个位数加到多位数的个位，若大于$9$则不断向高位进位<span title="我的博客里面很少用GPT生成内容，包括这段回忆也是本人写的">。</span>

+ 时间复杂度$O(len(digits))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-01 15:44:13
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += cnt;
            cnt = digits[i] / 10;
            digits[i] %= 10;
        }
        if (cnt) {
            digits.insert(digits.begin(), cnt);
        }
        return digits;
    }
};
```

#### Python

```python
'''
LastEditTime: 2026-01-01 15:54:44
'''
from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        cnt = 1
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += cnt
            cnt = digits[i] // 10
            digits[i] %= 10
        if cnt:
            digits = [1] + digits
        return digits
```

#### Python - 一行版

```python
'''
LastEditTime: 2026-01-01 16:03:01
'''
from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return list(map(int, str(int(''.join(map(str, digits))) + 1)))

# if __name__ == '__main__':
#     sol = Solution()
#     print(sol.plusOne([1,2,3]))
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-01 15:59:15
 */
class Solution {
    public int[] plusOne(int[] digits) {
        int cnt = 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            digits[i] += cnt;
            cnt = digits[i] / 10;
            digits[i] %= 10;
        }
        if (cnt > 0) {
            int[] ans = new int[digits.length + 1];
            ans[0] = cnt;
            for (int i = 0; i < digits.length; i++) {
                ans[i + 1] = digits[i];
            }
            return ans;
        }
        return digits;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2026-01-01 16:09:18
 */
package main

func plusOne(digits []int) []int {
    cnt := 1
    for i := len(digits) - 1; i >= 0; i-- {
        digits[i] += cnt
        cnt = digits[i] / 10
        digits[i] %= 10
    }
    if cnt > 0 {
        return append([]int{cnt}, digits...)
    }
    return digits
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-01 16:06:45
 */
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut cnt: i32 = 1;
        for i in (0..digits.len()).rev() {
            digits[i] += cnt;
            cnt = digits[i] / 10;
            digits[i] %= 10;
        }
        if cnt > 0 {
            digits.insert(0, cnt);
        }
        digits
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156488092)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/01/LeetCode%200066.%E5%8A%A0%E4%B8%80/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
