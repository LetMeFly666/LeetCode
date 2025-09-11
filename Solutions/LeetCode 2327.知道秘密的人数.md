---
title: 2327.知道秘密的人数：动态规划/差分数组O(n)
date: 2025-09-11 13:00:17
tags: [题解, LeetCode, 中等, 队列, 动态规划, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2327.知道秘密的人数：动态规划/差分数组O(n)

力扣题目链接：[https://leetcode.cn/problems/number-of-people-aware-of-a-secret/](https://leetcode.cn/problems/number-of-people-aware-of-a-secret/)

<p>在第 <code>1</code>&nbsp;天，有一个人发现了一个秘密。</p>

<p>给你一个整数&nbsp;<code>delay</code>&nbsp;，表示每个人会在发现秘密后的 <code>delay</code>&nbsp;天之后，<strong>每天</strong>&nbsp;给一个新的人&nbsp;<strong>分享</strong>&nbsp;秘密。同时给你一个整数&nbsp;<code>forget</code>&nbsp;，表示每个人在发现秘密&nbsp;<code>forget</code>&nbsp;天之后会&nbsp;<strong>忘记</strong>&nbsp;这个秘密。一个人&nbsp;<strong>不能</strong>&nbsp;在忘记秘密那一天及之后的日子里分享秘密。</p>

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，请你返回在第 <code>n</code>&nbsp;天结束时，知道秘密的人数。由于答案可能会很大，请你将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 6, delay = 2, forget = 4
<b>输出：</b>5
<strong>解释：</strong>
第 1 天：假设第一个人叫 A 。（一个人知道秘密）
第 2 天：A 是唯一一个知道秘密的人。（一个人知道秘密）
第 3 天：A 把秘密分享给 B 。（两个人知道秘密）
第 4 天：A 把秘密分享给一个新的人 C 。（三个人知道秘密）
第 5 天：A 忘记了秘密，B 把秘密分享给一个新的人 D 。（三个人知道秘密）
第 6 天：B 把秘密分享给 E，C 把秘密分享给 F 。（五个人知道秘密）
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 4, delay = 1, forget = 3
<b>输出：</b>6
<strong>解释：</strong>
第 1 天：第一个知道秘密的人为 A 。（一个人知道秘密）
第 2 天：A 把秘密分享给 B 。（两个人知道秘密）
第 3 天：A 和 B 把秘密分享给 2 个新的人 C 和 D 。（四个人知道秘密）
第 4 天：A 忘记了秘密，B、C、D 分别分享给 3 个新的人。（六个人知道秘密）
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= delay &lt; forget &lt;= n</code></li>
</ul>


    
## 解题方法一：动态规划

> (为了方便描述)也可以把这道题看成细菌繁殖，细菌delay天成熟forget天死亡并且期间每天复制自身一份。

令`dp[i]`代表第`i-1`天新生细菌的数量，初始值`dp[0]=1`，其余`dp[i]=0`。

从第`1`天开始遍历到第`n`天，第`i`天出生的细菌可以在第`[i+delay, i+forget)`天分别产下一个新细菌，所以有`dp[i+j] += dp[i]`，其中`i+delay<=j<i+forget`。

+ 时间复杂度$O(n\times(forget-delay))$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-09 23:42:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-09 23:52:39
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

using ll = long long;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> dp(n);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + delay; j < i + forget && j < n; j++) {
                dp[j] = (dp[j] + dp[i]) % MOD;
            }
        }
        ll ans = 0;
        for (int i = 0; i < forget; i++) {
            ans = (ans + dp[n - i - 1]) % MOD;
        }
        return ans;
    }
};
```

## 解题方法二：查分数组

方法一中有一个耗时操作：对于第`i`天出生的细菌，令`i+delay`到`i+forget-1`天的细菌分别加上`dp[i]`。

这个耗时操作不正是差分数组可以优化的吗？

令`diff[i]=dp[i]-dp[i-1]`，想让`dp[i+delay]`到`dp[i+forget-1]`每个加`dp[i]`只需要令`diff[i+delay]+=dp[i]`和`diff[i+forget]-=dp[i]`。

相应的，`dp[i]`就等于`sum(diff[0..i+1])`。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-09 23:42:14
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-11 10:49:54
 */
using ll = long long;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll> diff(n + 1);
        diff[1] = 1;
        diff[2] = -1;
        ll now = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            now = (now + diff[i]) % MOD;
            if (i + forget > n) {
                ans = (ans + now) % MOD;
            }
            if (i + delay <= n) {
                diff[i + delay] = (diff[i + delay] + now) % MOD;
            }
            if (i + forget <= n) {
                diff[i + forget] = (diff[i + forget] + MOD - now) % MOD;
            }
        }
        return ans;
    }
};
```


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151586337)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/11/LeetCode%202327.%E7%9F%A5%E9%81%93%E7%A7%98%E5%AF%86%E7%9A%84%E4%BA%BA%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
