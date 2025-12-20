---
title: 944.删列造序：字符串数组遍历（Python一行版）
date: 2025-12-20 23:04:57
tags: [题解, LeetCode, 简单, 数组, 字符串, 遍历]
categories: [题解, LeetCode]
---

# 【LetMeFly】944.删列造序：字符串数组遍历（Python一行版）

力扣题目链接：[https://leetcode.cn/problems/delete-columns-to-make-sorted/](https://leetcode.cn/problems/delete-columns-to-make-sorted/)

<p>给你由 <code>n</code> 个小写字母字符串组成的数组 <code>strs</code>，其中每个字符串长度相等。</p>

<p>这些字符串可以每个一行，排成一个网格。例如，<code>strs = ["abc", "bce", "cae"]</code> 可以排列为：</p>

<pre>
abc
bce
cae</pre>

<p>你需要找出并删除 <strong>不是按字典序非严格递增排列的</strong> 列。在上面的例子（下标从 0 开始）中，列 0（<code>'a'</code>, <code>'b'</code>, <code>'c'</code>）和列 2（<code>'c'</code>, <code>'e'</code>, <code>'e'</code>）都是按字典序非严格递增排列的，而列 1（<code>'b'</code>, <code>'c'</code>, <code>'a'</code>）不是，所以要删除列 1 。</p>

<p>返回你需要删除的列数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["cba","daf","ghi"]
<strong>输出：</strong>1
<strong>解释：</strong>网格示意如下：
  cba
  daf
  ghi
列 0 和列 2 按升序排列，但列 1 不是，所以只需要删除列 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["a","b"]
<strong>输出：</strong>0
<strong>解释：</strong>网格示意如下：
  a
  b
只有列 0 这一列，且已经按升序排列，所以不用删除任何列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>strs = ["zyx","wvu","tsr"]
<strong>输出：</strong>3
<strong>解释：</strong>网格示意如下：
  zyx
  wvu
  tsr
所有 3 列都是非升序排列的，所以都要删除。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == strs.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 1000</code></li>
	<li><code>strs[i]</code> 由小写英文字母组成</li>
</ul>


    
## 解题方法：遍历

两层循环，第一层循环遍历每一列，第二层循环从第二行开始往下遍历，遇到当前字符**小于**上一行对应字符则答案加一并退出第二层循环。

+ 时间复杂度$O(nm)$，其中$m=len(strs[i])$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-20 22:48:32
 */
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (strs[i][j] < strs[i - 1][j]) {  // 好吧，相同相邻字符是合法的
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Python

这种题，怎么少得了python一行版呢，你说是不？

```python
'''
LastEditTime: 2025-12-20 22:55:49
'''
from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        return sum(any(strs[i][j] < strs[i-1][j] for i in range(1, len(strs))) for j in range(len(strs[0])))
```

#### Java

```java
/*
 * @LastEditTime: 2025-12-20 22:59:10
 */
class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length, m = strs[0].length();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (strs[i].charAt(j) < strs[i-1].charAt(j)) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-20 22:58:23
 */
package main

func minDeletionSize(strs []string) (ans int) {
    n:= len(strs)
    for j := range strs[0] {
        for i := 1; i < n; i++ {
            if strs[i][j] < strs[i-1][j] {
                ans++
                break
            }
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-20 23:02:37
 */
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let n = strs.len();
        let m = strs[0].len();
        let mut ans: i32 = 0;
        for j in 0..m {
            for i in 1..n {
                if strs[i].chars().nth(j).unwrap() < strs[i-1].chars().nth(j).unwrap() {
                    ans += 1;
                    break;
                }
            } 
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156117851)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/20/LeetCode%200944.%E5%88%A0%E5%88%97%E9%80%A0%E5%BA%8F/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
