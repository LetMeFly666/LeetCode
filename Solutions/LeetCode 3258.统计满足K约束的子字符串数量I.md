---
title: 3258.统计满足 K 约束的子字符串数量 I
date: 2024-11-12 18:35:49
tags: [题解, LeetCode, 简单, 字符串, 滑动窗口]
---

# 【LetMeFly】3258.统计满足 K 约束的子字符串数量 I：滑动窗口（硬卷O(n)）

力扣题目链接：[https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/](https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/)

<p>给你一个 <strong>二进制</strong> 字符串 <code>s</code> 和一个整数 <code>k</code>。</p>

<p>如果一个 <strong>二进制字符串</strong> 满足以下任一条件，则认为该字符串满足 <strong>k 约束</strong>：</p>

<ul>
	<li>字符串中 <code>0</code> 的数量最多为 <code>k</code>。</li>
	<li>字符串中 <code>1</code> 的数量最多为 <code>k</code>。</li>
</ul>

<p>返回一个整数，表示 <code>s</code> 的所有满足 <strong>k 约束 </strong>的<span data-keyword="substring-nonempty">子字符串</span>的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "10101", k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">12</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code> 的所有子字符串中，除了 <code>"1010"</code>、<code>"10101"</code> 和 <code>"0101"</code> 外，其余子字符串都满足 k 约束。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "1010101", k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">25</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code> 的所有子字符串中，除了长度大于 5 的子字符串外，其余子字符串都满足 k 约束。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "11111", k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">15</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code> 的所有子字符串都满足 k 约束。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>s[i]</code> 是 <code>'0'</code> 或 <code>'1'</code>。</li>
</ul>


    
## 解题方法：滑动窗口

使用两个遍历`cnt[0]`和`cnt[1]`分别记录当前“窗口”中`0`和`1`的数量，使用两个指针`l`和`r`分别代表窗口的始末下标。

每次窗口右指针`r`向右移动一位，如果这个移动导致窗口中`cnt[0] > k`且`cnt[1] > k`，则不断右移左指针`l`直至窗口中子字符串符合“K约束”要求。

对于一个窗口，我们累加以`r`结尾的子字符串数量：$r - l + 1$。

+ 时间复杂度$O(len(s))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt[2] = {0};
        int ans = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            cnt[s[r] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {  // 啊这，De了半天原来是“任一”
                cnt[s[l++] - '0']--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        cnt = [0, 0]
        ans = 0
        l = 0
        for r in range(len(s)):
            cnt[ord(s[r]) - ord('0')] += 1
            while cnt[0] > k and cnt[1] > k:
                cnt[ord(s[l]) - ord('0')] -= 1
                l += 1
            ans += r - l + 1
        return ans
```

#### Java

```java
class Solution {
    public int countKConstraintSubstrings(String s, int k) {
        int[] cnt = new int[2];
        int ans = 0;
        for (int l = 0, r = 0; r < s.length(); r++) {
            cnt[s.charAt(r) - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s.charAt(l++) - '0']--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
}
```

#### Go

```go
package main

func countKConstraintSubstrings(s string, k int) (ans int) {
    cnt := make([]int, 2)
    for l, r := 0, 0; r < len(s); r++ {
        cnt[s[r] - '0']++
        for cnt[0] > k && cnt[1] > k {
            cnt[s[l] - '0']--
            l++
        }
        ans += r - l + 1
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/12/LeetCode%203258.%E7%BB%9F%E8%AE%A1%E6%BB%A1%E8%B6%B3K%E7%BA%A6%E6%9D%9F%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%95%B0%E9%87%8FI/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143726399](https://letmefly.blog.csdn.net/article/details/143726399)
