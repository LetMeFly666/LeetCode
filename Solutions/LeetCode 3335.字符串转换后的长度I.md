---
title: 3335.字符串转换后的长度 I：I先递推
date: 2025-05-13 09:29:22
tags: [题解, LeetCode, 中等, 哈希表, 数学, 字符串, 动态规划, 计数]
categories: [题解, LeetCode]
---

# 【LetMeFly】3335.字符串转换后的长度 I：I先递推

力扣题目链接：[https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/](https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/)

<p>给你一个字符串 <code>s</code> 和一个整数 <code>t</code>，表示要执行的<strong> 转换 </strong>次数。每次 <strong>转换 </strong>需要根据以下规则替换字符串 <code>s</code> 中的每个字符：</p>

<ul>
	<li>如果字符是 <code>'z'</code>，则将其替换为字符串 <code>"ab"</code>。</li>
	<li>否则，将其替换为字母表中的<strong>下一个</strong>字符。例如，<code>'a'</code> 替换为 <code>'b'</code>，<code>'b'</code> 替换为 <code>'c'</code>，依此类推。</li>
</ul>

<p>返回<strong> 恰好 </strong>执行 <code>t</code> 次转换后得到的字符串的 <strong>长度</strong>。</p>

<p>由于答案可能非常大，返回其对 <code>10<sup>9</sup> + 7</code> 取余的结果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "abcyy", t = 2</span></p>

<p><strong>输出：</strong> <span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>第一次转换 (t = 1)</strong>

	<ul>
		<li><code>'a'</code> 变为 <code>'b'</code></li>
		<li><code>'b'</code> 变为 <code>'c'</code></li>
		<li><code>'c'</code> 变为 <code>'d'</code></li>
		<li><code>'y'</code> 变为 <code>'z'</code></li>
		<li><code>'y'</code> 变为 <code>'z'</code></li>
		<li>第一次转换后的字符串为：<code>"bcdzz"</code></li>
	</ul>
	</li>
	<li><strong>第二次转换 (t = 2)</strong>
	<ul>
		<li><code>'b'</code> 变为 <code>'c'</code></li>
		<li><code>'c'</code> 变为 <code>'d'</code></li>
		<li><code>'d'</code> 变为 <code>'e'</code></li>
		<li><code>'z'</code> 变为 <code>"ab"</code></li>
		<li><code>'z'</code> 变为 <code>"ab"</code></li>
		<li>第二次转换后的字符串为：<code>"cdeabab"</code></li>
	</ul>
	</li>
	<li><strong>最终字符串长度</strong>：字符串为 <code>"cdeabab"</code>，长度为 7 个字符。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "azbk", t = 1</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>第一次转换 (t = 1)</strong>

	<ul>
		<li><code>'a'</code> 变为 <code>'b'</code></li>
		<li><code>'z'</code> 变为 <code>"ab"</code></li>
		<li><code>'b'</code> 变为 <code>'c'</code></li>
		<li><code>'k'</code> 变为 <code>'l'</code></li>
		<li>第一次转换后的字符串为：<code>"babcl"</code></li>
	</ul>
	</li>
	<li><strong>最终字符串长度</strong>：字符串为 <code>"babcl"</code>，长度为 5 个字符。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成。</li>
	<li><code>1 &lt;= t &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：递推

使用一个长为26的数组记录每个字符当前分别有多少次。

然后进行$t$次模拟：

> 首先记下`z`的出现次数；
>
> 接着从`y`到`a`遍历，将cnt[i]赋值给cnt[i + 1]；
>
> 最后令`cnt[0] := z`，`cnt[1] += z`，`ans += z`（这是因为没轮操作`z`会变成`ab`，同时字符串长度会加一）

+ 时间复杂度$O(len(s)\cdot C)$，其中$C=26$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-13 09:02:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 09:15:09
 * @Description: 3335: AC,92.65%,98.53%
 */
const int MOD = 1e9 + 7;

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int cnt[26] = {0};
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int ans = s.size();
        while (t--) {
            int z = cnt[25];
            for (int i = 24; i >= 0; i--) {  // 这里必须从后往前
                cnt[i + 1] = cnt[i];
            }
            cnt[0] = z;
            cnt[1] = (cnt[1] + z) % MOD;
            ans = (ans + z) % MOD;
            // debug(cnt);
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-05-13 09:02:15
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-13 09:18:14
'''
MOD = 1000000007

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - 97] += 1
        ans = len(s)
        for _ in range(t):
            z = cnt[-1]
            for i in range(24, -1, -1):
                cnt[i + 1] = cnt[i]
            cnt[0] = z
            cnt[1] = (cnt[1] + z) % MOD
            ans = (ans + z) % MOD
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-05-13 09:02:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 09:19:43
 */

class Solution {
    private final int MOD = 1000000007;

    public int lengthAfterTransformations(String s, int t) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); i++) {
            cnt[s.charAt(i) - 'a']++;
        }
        int ans = s.length();
        while (t-- > 0) {
            int z = cnt[25];
            for (int i = 24; i >= 0; i--) {
                cnt[i + 1] = cnt[i];
            }
            cnt[0] = z;
            cnt[1] = (cnt[1] + z) % MOD;
            ans = (ans + z) % MOD;
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-05-13 09:02:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-13 09:28:34
 */
package main

var MOD3351 = 1000000007

func lengthAfterTransformations(s string, t int) int {
    cnt := make([]int, 26)
    for i := 0; i < len(s); i++ {
        cnt[s[i] - 'a']++
    }
    ans := len(s)
    for i := 0; i < t; i++ {
        z := cnt[25]
        for j := 24; j >= 0; j-- {
            cnt[j + 1] = cnt[j]
        }
        cnt[0] = z
        cnt[1] = (cnt[1] + z) % MOD3351
        ans = (ans + z) % MOD3351
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/147916305)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/13/LeetCode%203335.%E5%AD%97%E7%AC%A6%E4%B8%B2%E8%BD%AC%E6%8D%A2%E5%90%8E%E7%9A%84%E9%95%BF%E5%BA%A6I/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
