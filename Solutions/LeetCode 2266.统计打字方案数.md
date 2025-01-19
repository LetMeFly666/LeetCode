---
title: 2266.统计打字方案数：排列组合
date: 2025-01-19 14:57:48
tags: [题解, LeetCode, 中等, 哈希表, 数学, 字符串, 动态规划, DP, 排列组合]
---

# 【LetMeFly】2266.统计打字方案数：排列组合

力扣题目链接：[https://leetcode.cn/problems/count-number-of-texts/](https://leetcode.cn/problems/count-number-of-texts/)

<p>Alice 在给 Bob 用手机打字。数字到字母的 <strong>对应</strong>&nbsp;如下图所示。</p>

<p><img alt="" src="https://pic.leetcode.cn/1722224025-gsUAIv-image.png" style="width: 200px; height: 162px;" /></p>

<p>为了 <strong>打出</strong>&nbsp;一个字母，Alice 需要 <strong>按</strong>&nbsp;对应字母 <code>i</code>&nbsp;次，<code>i</code>&nbsp;是该字母在这个按键上所处的位置。</p>

<ul>
	<li>比方说，为了按出字母&nbsp;<code>'s'</code>&nbsp;，Alice 需要按&nbsp;<code>'7'</code>&nbsp;四次。类似的， Alice 需要按&nbsp;<code>'5'</code>&nbsp;两次得到字母&nbsp;&nbsp;<code>'k'</code>&nbsp;。</li>
	<li>注意，数字&nbsp;<code>'0'</code> 和&nbsp;<code>'1'</code>&nbsp;不映射到任何字母，所以&nbsp;Alice <strong>不</strong>&nbsp;使用它们。</li>
</ul>

<p>但是，由于传输的错误，Bob 没有收到 Alice 打字的字母信息，反而收到了 <strong>按键的字符串信息</strong>&nbsp;。</p>

<ul>
	<li>比方说，Alice 发出的信息为&nbsp;<code>"bob"</code>&nbsp;，Bob 将收到字符串&nbsp;<code>"2266622"</code>&nbsp;。</li>
</ul>

<p>给你一个字符串&nbsp;<code>pressedKeys</code>&nbsp;，表示 Bob 收到的字符串，请你返回 Alice <strong>总共可能发出多少种文字信息</strong>&nbsp;。</p>

<p>由于答案可能很大，将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>pressedKeys = "22233"
<b>输出：</b>8
<strong>解释：</strong>
Alice 可能发出的文字信息包括：
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" 和 "ce" 。
由于总共有 8 种可能的信息，所以我们返回 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>pressedKeys = "222222222222222222222222222222222222"
<b>输出：</b>82876089
<strong>解释：</strong>
总共有 2082876103 种 Alice 可能发出的文字信息。
由于我们需要将答案对 10<sup>9</sup> + 7 取余，所以我们返回 2082876103 % (10<sup>9</sup> + 7) = 82876089 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pressedKeys.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pressedKeys</code> 只包含数字&nbsp;<code>'2'</code>&nbsp;到&nbsp;<code>'9'</code>&nbsp;。</li>
</ul>


    
## 解题方法：排列组合

按键`2`可以按`1/2/3`次，那么`n`次连续的按键`2`共有多少种拼写可能？

> 使用数组`dp3`，其中`dp3[n]`代表连续按`2`键`n`次有多少种拼写方案。我们考虑最后一个按出来的字母：
> 
> 1. 第`n`次按`2`可以在按了`n - 1`次的基础上再按`1`次（得到`a`）
> 1. 第`n`次按`2`可以在按了`n - 2`次的基础上连续按`2`次（得到`b`）
> 1. 第`n`次按`2`可以在按了`n - 3`次的基础上连续按`3`次（得到`c`）
>
> 因此`dp3[n] = (dp3[n - 1] + dp3[n - 2] + dp3[n - 3]) % mod`

和按键`2`一样，按键`3/4/5/6/8`同样适用于`dp3`数组；而按键`7`和按键`9`最多可以连按`4`次，因此可以计算`dp4`数组：

> `dp4[n] = (dp4[n - 1] + dp4[n - 2] + dp4[n - 3] + dp4[n - 4]) % mod`

给你一个按键字符串如`22233`，我们可以通过一次遍历很轻松地得到“连按了`3`次`2`，又连按了`2`次`3`”这一信息。

连按`3`次`2`可以有`dp3[3]`种方案，连按`2`次`3`可以有`dp3[2]`种方案，因此依据乘法原理，总计有`dp3[3] * dp3[2]`种方案。


+ 时间复杂度$O(len(pressedKeys))$
+ 空间复杂度$O(len(pressedKeys))$

### AC代码

#### C++

```cpp
const int mod = 1e9 + 7;
int dp3[100001], dp4[100001];
int init = []() {
    dp3[0] = dp4[0] = 1;
    dp3[1] = dp4[1] = 1;
    dp3[2] = dp4[2] = 2;
    dp3[3] = dp4[3] = 4;
    for (int i = 4; i <= 100000; i++) {
        dp3[i] = ((dp3[i- 1] + dp3[i - 2]) % mod + dp3[i - 3]) % mod;
        dp4[i] = (((dp4[i - 1] + dp4[i - 2]) % mod + dp4[i - 3]) % mod + dp4[i - 4]) % mod;
    }
    return 0;
}();

class Solution {
public:
    int countTexts(string& pressedKeys) {
        long long ans = 1;
        int cnt = 0;
        for (int i = 0; i < pressedKeys.size(); i++) {
            cnt++;
            if (i == pressedKeys.size() - 1 || pressedKeys[i] != pressedKeys[i + 1]) {
                ans = ans * (pressedKeys[i] == '7' || pressedKeys[i] == '9' ? dp4[cnt] : dp3[cnt]) % mod;
                cnt = 0;
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
Date: 2025-01-19 14:06:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-19 14:16:32
'''
MOD = 1000000007
dp3 = [1, 1, 2, 4] + [0] * 100000
dp4 = [1, 1, 2, 4] + [0] * 100000
for i in range(4, 100001):
    dp3[i] = (dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % MOD
    dp4[i] = (dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % MOD

class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        ans = 1
        cnt = 0
        for i in range(len(pressedKeys)):
            cnt += 1
            if i == len(pressedKeys) - 1 or pressedKeys[i] != pressedKeys[i + 1]:
                ans = ans * (dp4[cnt] if pressedKeys[i] == '7' or pressedKeys[i] == '9' else dp3[cnt]) % MOD
                cnt = 0
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-01-19 14:16:55
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-19 14:19:48
 */
class Solution {
    private static final int mod = 1000000007;
    private static final int[] dp3 = new int[100001];
    private static final int[] dp4 = new int[100001];

    static {
        dp3[0] = dp4[0] = 1;
        dp3[1] = dp4[1] = 1;
        dp3[2] = dp4[2] = 2;
        dp3[3] = dp4[3] = 4;
        for (int i = 4; i <= 100000; i++) {
            dp3[i] = ((dp3[i- 1] + dp3[i - 2]) % mod + dp3[i - 3]) % mod;
            dp4[i] = (((dp4[i - 1] + dp4[i - 2]) % mod + dp4[i - 3]) % mod + dp4[i - 4]) % mod;
        }
    }

    public int countTexts(String pressedKeys) {
        long ans = 1;
        int cnt = 0;
        for (int i = 0; i < pressedKeys.length(); i++) {
            cnt++;
            if (i == pressedKeys.length() - 1 || pressedKeys.charAt(i) != pressedKeys.charAt(i + 1)) {
                ans = ans * (pressedKeys.charAt(i) == '7' || pressedKeys.charAt(i) == '9' ? dp4[cnt] : dp3[cnt]) % mod;
                cnt = 0;
            }
        }
        return (int)ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-01-19 14:21:47
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-01-19 14:55:32
 */
package main

const mod int = 1000000007
var dp3 = [100001]int{1, 1, 2, 4}
var dp4 = dp3

func init() {
    for i := 4; i <= 100000; i++ {
        dp3[i] = ((dp3[i- 1] + dp3[i - 2]) % mod + dp3[i - 3]) % mod;
        dp4[i] = (((dp4[i - 1] + dp4[i - 2]) % mod + dp4[i - 3]) % mod + dp4[i - 4]) % mod;
    }
}

func countTexts(pressedKeys string) int {
    ans := int64(1)
    cnt := 0
    for i, c := range pressedKeys {
        cnt++
        if i == len(pressedKeys) - 1 || byte(c) != pressedKeys[i + 1] {
            if c == '7' || c == '9' {
                ans = ans * int64(dp4[cnt]) % int64(mod)
            } else {
                ans = ans * int64(dp3[cnt]) % int64(mod)
            }
            cnt = 0
        }
    }
    return int(ans)
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/01/19/LeetCode%202266.%E7%BB%9F%E8%AE%A1%E6%89%93%E5%AD%97%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/145243054](https://letmefly.blog.csdn.net/article/details/145243054)
