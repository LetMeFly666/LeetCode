---
title: 2011.执行操作后的变量值：简单题简单做
date: 2022-12-23 19:19:38
tags: [题解, LeetCode, 简单, 数组, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2011.执行操作后的变量值：简单题简单做

力扣题目链接：[https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/](https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/)

<p>存在一种仅支持 4 种操作和 1 个变量 <code>X</code> 的编程语言：</p>

<ul>
	<li><code>++X</code> 和 <code>X++</code> 使变量 <code>X</code> 的值 <strong>加</strong> <code>1</code></li>
	<li><code>--X</code> 和 <code>X--</code> 使变量 <code>X</code> 的值 <strong>减</strong> <code>1</code></li>
</ul>

<p>最初，<code>X</code> 的值是 <code>0</code></p>

<p>给你一个字符串数组 <code>operations</code> ，这是由操作组成的一个列表，返回执行所有操作后，<em> </em><code>X</code> 的 <strong>最终值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>operations = ["--X","X++","X++"]
<strong>输出：</strong>1
<strong>解释：</strong>操作按下述步骤执行：
最初，X = 0
--X：X 减 1 ，X =  0 - 1 = -1
X++：X 加 1 ，X = -1 + 1 =  0
X++：X 加 1 ，X =  0 + 1 =  1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>operations = ["++X","++X","X++"]
<strong>输出：</strong>3
<strong>解释：</strong>操作按下述步骤执行： 
最初，X = 0
++X：X 加 1 ，X = 0 + 1 = 1
++X：X 加 1 ，X = 1 + 1 = 2
X++：X 加 1 ，X = 2 + 1 = 3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>operations = ["X++","++X","--X","X--"]
<strong>输出：</strong>0
<strong>解释：</strong>操作按下述步骤执行：
最初，X = 0
X++：X 加 1 ，X = 0 + 1 = 1
++X：X 加 1 ，X = 1 + 1 = 2
--X：X 减 1 ，X = 2 - 1 = 1
X--：X 减 1 ，X = 1 - 1 = 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= operations.length &lt;= 100</code></li>
	<li><code>operations[i]</code> 将会是 <code>"++X"</code>、<code>"X++"</code>、<code>"--X"</code> 或 <code>"X--"</code></li>
</ul>


    
## 方法一：模拟

变量$X$的初始值是$0$，之后遍历$operations$中的每个$operation$，如果这个$operation$是$X++$或$++X$，则令$X$的值加一；否则令$X$的值减一。

**小小小技巧：** 其实不用真的把$operation$和$X++$进行比较，因为不管是$X++$还是$++X$，其第二个字符都是$+$

因此，我们只需要判断$operation$的第二个字符是否为$+$并进行响应的操作即可。

+ 时间复杂度$O(len(operations))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 *  @LastEditTime: 2022-12-23 19:18:09
 */
// 下面代码中，ans即为题解中的X。使用变量ans是一些ACMer的习惯
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& s : operations) {
            if (s[1] == '+')
                ans++;
            else
                ans--;
        }
        return ans;
    }
};
```

#### C++

```cpp
/*
 * @LastEditTime: 2025-10-20 18:46:29
 */
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string& op : operations) {
            ans += op[1] == '+' ? 1 : -1;
        }
        return ans;
    }
};
```

#### Go

```go
/*
 * @LastEditTime: 2025-10-20 18:48:49
 */
package main

func finalValueAfterOperations(operations []string) (ans int) {
    for _, op := range operations {
        if op[1] == '+' {
            ans++;
        } else {
            ans--
        }
    }
    return
}
```

#### Java

```java
/*
 * @LastEditTime: 2025-10-20 18:48:23
 */
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (String op : operations) {
            if (op.charAt(1) == '+') {
                ans++;
            } else {
                ans--;
            }
        }
        return ans;
    }
}
```

#### Python

```python
'''
LastEditTime: 2025-10-20 18:47:35
'''
from typing import List

class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(1 if op[1] == '+' else -1 for op in operations)
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-10-20 18:56:38
 */
impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut ans: i32 = 0;
        for op in operations {
            if op.as_bytes()[1] == b'+' {
                ans += 1;  // cannot write as: ans++;
            } else {
                ans -= 1;
            }
        }
        ans
    }
}
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/12/23/LeetCode%202011.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%90%8E%E7%9A%84%E5%8F%98%E9%87%8F%E5%80%BC/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/128423159](https://letmefly.blog.csdn.net/article/details/128423159)
