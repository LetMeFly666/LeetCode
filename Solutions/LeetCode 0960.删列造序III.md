---
title: 960.删列造序 III：动态规划(最长递增子序列)
date: 2025-12-22 23:05:56
tags: [题解, LeetCode, 困难, 数组, 字符串, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】960.删列造序 III：动态规划(最长递增子序列)

力扣题目链接：[https://leetcode.cn/problems/delete-columns-to-make-sorted-iii/](https://leetcode.cn/problems/delete-columns-to-make-sorted-iii/)

<p>给定由<meta charset="UTF-8" />&nbsp;<code>n</code>&nbsp;个小写字母字符串组成的数组<meta charset="UTF-8" />&nbsp;<code>strs</code>&nbsp;，其中每个字符串长度相等。</p>

<p>选取一个删除索引序列，对于<meta charset="UTF-8" />&nbsp;<code>strs</code>&nbsp;中的每个字符串，删除对应每个索引处的字符。</p>

<p>比如，有<meta charset="UTF-8" />&nbsp;<code>strs = ["abcdef","uvwxyz"]</code>&nbsp;，删除索引序列<meta charset="UTF-8" />&nbsp;<code>{0, 2, 3}</code>&nbsp;，删除后为<meta charset="UTF-8" />&nbsp;<code>["bef", "vyz"]</code>&nbsp;。</p>

<p>假设，我们选择了一组删除索引<meta charset="UTF-8" />&nbsp;<code>answer</code>&nbsp;，那么在执行删除操作之后，最终得到的数组的行中的 <strong>每个元素</strong> 都是按<strong>字典序</strong>排列的（即&nbsp;<code>(strs[0][0] &lt;= strs[0][1] &lt;= ... &lt;= strs[0][strs[0].length - 1])</code>&nbsp;和&nbsp;<code>(strs[1][0] &lt;= strs[1][1] &lt;= ... &lt;= strs[1][strs[1].length - 1])</code> ，依此类推）。</p>

<p>请返回<meta charset="UTF-8" /><em>&nbsp;<code>answer.length</code>&nbsp;的最小可能值</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["babca","bbazb"]
<strong>输出：</strong>3
<strong>解释：
</strong>删除 0、1 和 4 这三列后，最终得到的数组是 strs = ["bc", "az"]。
这两行是分别按字典序排列的（即，strs[0][0] &lt;= strs[0][1] 且 strs[1][0] &lt;= strs[1][1]）。
注意，strs[0] &gt; strs[1] —— 数组 strs 不一定是按字典序排列的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["edcba"]
<strong>输出：</strong>4
<strong>解释：</strong>如果删除的列少于 4 列，则剩下的行都不会按字典序排列。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>strs = ["ghi","def","abc"]
<strong>输出：</strong>0
<strong>解释：</strong>所有行都已按字典序排列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>n == strs.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code>&nbsp;由小写英文字母组成</li>
</ul>


    
## 解题方法：动态规划

这道题可以换个角度思考：`求最少删除列使剩余元素非递减` 相当于 `求最长非递减子序列`。子序列外的其他列就是要删除的列。

好了，这就和[300.最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/)大同小异了。

使用一个dp数组，其中`dp[i]`表示strs每一行都以第`i`个元素结尾时，最多保留的非递减列数。那么`总列数 - max(dp[i])`即为所求。

两层循环，第一层循环从`0`到`len(strs[0])`枚举并计算`dp[cur]`，怎么计算呢？

第二层循环从`0`到`cur-1`枚举`prev`，如果strs中每一行的`cur`列都大于等于`prev`列，并且以`prev`列结尾的非递减序列还比当前以`cur`结尾的非递减序列长，那么是不是就说明`prev`这一列可以拼接到`cur`这一列的后面了（更新`dp[cur] = dp[prev] + 1`）。

+ 时间复杂度$O(nm^2)$，其中$m=len(strs[0])$
+ 空间复杂度$O(m)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2025-12-22 22:43:18
 */
class Solution {
private:
    bool can(vector<string>& strs, int i, int j) {
        for (string& s : strs) {
            if (s[i] < s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        vector<int> dp(m);
        for (int i = 0; i < m; i++) {  // 一定要从0开始！！要不然dp[0]恒为0
            for (int j = 0; j < i; j++) {
                if (dp[j] > dp[i] && can(strs, i, j)) {
                    dp[i] = dp[j];
                }
            }
            dp[i]++;
        }
        return m - *max_element(dp.begin(), dp.end());
    }
};
```

#### Python

```python
'''
LastEditTime: 2025-12-22 22:49:18
'''
from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m = len(strs[0])
        dp = [0] * m
        for cur in range(m):
            for prev in range(cur):
                if dp[cur] < dp[prev] and all(s[prev] <= s[cur] for s in strs):
                    dp[cur] = dp[prev]
            dp[cur] += 1
        return m - max(dp)
```

#### Java

```java
/*
 * @LastEditTime: 2025-12-22 22:59:50
 */
class Solution {
    private boolean can(String[] strs, int prev, int cur) {
        for (String s : strs) {
            if (s.charAt(prev) > s.charAt(cur)) {
                return false;
            }
        }
        return true;
    }

    public int minDeletionSize(String[] strs) {
        int m = strs[0].length();
        int[] dp = new int[m];
        int longest = 0;
        for (int cur = 0; cur < m; cur++) {
            for (int prev = 0; prev < cur; prev++) {
                if (dp[cur] < dp[prev] && can(strs, prev, cur)) {
                    dp[cur] = dp[prev];
                }
            }
            longest = Math.max(longest, ++dp[cur]);
        }
        return m - longest;
    }
}
```

#### Go

```go
/*
 * @LastEditTime: 2025-12-22 22:53:21
 */
package main

import "slices"

func can960(strs []string, prev, cur int) bool {
    for _, s := range strs {
        if s[prev] > s[cur] {
            return false
        }
    }
    return true
}

func minDeletionSize(strs []string) int {
    m := len(strs[0])
    dp := make([]int, m)
    for cur := 0; cur < m; cur++ {
        for prev := 0; prev < cur; prev++ {
            if dp[cur] < dp[prev] && can960(strs, prev, cur) {
                dp[cur] = dp[prev]
            }
        }
        dp[cur]++
    }
    return m - slices.Max(dp)
}
```

+ 执行用时分布0ms击败100.00%
+ 消耗内存分布5.24MB击败100.00%

#### Rust

```rust
/*
 * @LastEditTime: 2025-12-22 23:05:28
 */
impl Solution {
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let m = strs[0].len();
        let mut dp = vec![0; m];
        for cur in 0..m {
            for prev in 0..cur {
                if dp[prev] > dp[cur] && strs.iter().all(|s| s.as_bytes()[prev] <= s.as_bytes()[cur]) {
                    dp[cur] = dp[prev];
                }
            }
            dp[cur] += 1;
        }
        m as i32 - *dp.iter().max().unwrap()
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156169371)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/12/22/LeetCode%200960.%E5%88%A0%E5%88%97%E9%80%A0%E5%BA%8FIII/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
