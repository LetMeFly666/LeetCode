---
title: 1625.执行操作后字典序最小的字符串
date: 2023-03-19 15:01:56
tags: [题解, LeetCode, 中等, 广度优先搜索, 字符串, 模拟]
---

# 【LetMeFly】1625.执行操作后字典序最小的字符串

力扣题目链接：[https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/](https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/)

<p>给你一个字符串 <code>s</code> 以及两个整数 <code>a</code> 和 <code>b</code> 。其中，字符串 <code>s</code> 的长度为偶数，且仅由数字 <code>0</code> 到 <code>9</code> 组成。</p>

<p>你可以在 <code>s</code> 上按任意顺序多次执行下面两个操作之一：</p>

<ul>
	<li>累加：将  <code>a</code> 加到 <code>s</code> 中所有下标为奇数的元素上（<strong>下标从 0 开始</strong>）。数字一旦超过 <code>9</code> 就会变成 <code>0</code>，如此循环往复。例如，<code>s = "3456"</code> 且 <code>a = 5</code>，则执行此操作后 <code>s</code> 变成 <code>"3951"</code>。</li>
	<li>轮转：将 <code>s</code> 向右轮转 <code>b</code> 位。例如，<code>s = "3456"</code> 且 <code>b = 1</code>，则执行此操作后 <code>s</code> 变成 <code>"6345"</code>。</li>
</ul>

<p>请你返回在 <code>s</code> 上执行上述操作任意次后可以得到的 <strong>字典序最小</strong> 的字符串。</p>

<p>如果两个字符串长度相同，那么字符串 <code>a</code> 字典序比字符串 <code>b</code> 小可以这样定义：在 <code>a</code> 和 <code>b</code> 出现不同的第一个位置上，字符串 <code>a</code> 中的字符出现在字母表中的时间早于 <code>b</code> 中的对应字符。例如，<code>"0158”</code> 字典序比 <code>"0190"</code> 小，因为不同的第一个位置是在第三个字符，显然 <code>'5'</code> 出现在 <code>'9'</code> 之前。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "5525", a = 9, b = 2
<strong>输出：</strong>"2050"
<strong>解释：</strong>执行操作如下：
初态："5525"
轮转："2555"
累加："2454"
累加："2353"
轮转："5323"
累加："5222"
累加："5121"
轮转："2151"
累加："2050"​​​​​​​​​​​​
无法获得字典序小于 "2050" 的字符串。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "74", a = 5, b = 1
<strong>输出：</strong>"24"
<strong>解释：</strong>执行操作如下：
初态："74"
轮转："47"
累加："42"
轮转："24"​​​​​​​​​​​​
无法获得字典序小于 "24" 的字符串。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "0011", a = 4, b = 2
<strong>输出：</strong>"0011"
<strong>解释：</strong>无法获得字典序小于 "0011" 的字符串。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "43987654", a = 7, b = 3
<strong>输出：</strong>"00553311"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= s.length <= 100</code></li>
	<li><code>s.length</code> 是偶数</li>
	<li><code>s</code> 仅由数字 <code>0</code> 到 <code>9</code> 组成</li>
	<li><code>1 <= a <= 9</code></li>
	<li><code>1 <= b <= s.length - 1</code></li>
</ul>


    
## 方法一：模拟

我们只需要明白：

1. 因为轮转不可能产生无限多种字符串，所以**轮转所产生的字符串是在不断循环地**
2. 因为我们只能同时改变偶数位置的字符，所以对于一个轮转后的字符串，**我们要让下标为1的字符尽可能地小**
3. 因为字符串长度为偶数，所以**如果轮转距离b是奇数，则奇数位置的字符下标也有机会到达偶数**；反之奇数下标永远只能处于奇数的位置。

这样，我们就能开开心心地模拟了。

首先模拟所有的“轮转结果”（最多有len(s)种）

对于每种轮转结果，我们让其下标1处的字符加上数个a后尽可能地小，然后让所有奇数下标的字符加上相同数量的a。如果b为奇数，则**再**让下标0处的字符加上数个a后尽可能小，并将所有偶数下标的字符加上相同数量的a。

对于每种轮转结果，得到加最优a后的字符串后，在所有字符串中最小的一个即为答案。

+ 时间复杂度$O(len(s)^2\times C)$，其中$C=10$。最多需要$len(s)$次轮转，对于每次轮转需要$len(s)\times C$的复杂度完成“加a”、比较等操作。最多加上10次a即可找到最优的加a次数。
+ 空间复杂度$O(len(s))$

### AC代码

#### C++

```cpp
class Solution {
private:
    int add2minStep(char original, int a) {  // 将original加数次a，使得original尽可能小，需要加几次
        int ans = 0;
        int step = 0;
        int m = original - '0';
        int n = original - '0';
        do {
            n = (n + a) % 10;
            step++;
            if (n < m) {
                m = n;
                ans = step;
            }
        } while (a * step % 10);
        return ans;
    }

    string change2loc2min(string& s, int a, int b, int l) {  // 将s的l、l + 1两个位置变得尽可能小并移动到最前
        string ans = s.substr(l, s.size() - l) + s.substr(0, l);
        if (b % 2) {
            int m1 = add2minStep(ans[0], a);
            for (int i = 0; i < s.size(); i += 2) {
                ans[i] = (char)((ans[i] - '0' + a * m1) % 10 + '0');
            }
        }
        int m2 = add2minStep(ans[1], a);
        for (int i = 1; i < s.size(); i += 2) {
            ans[i] = (char)((ans[i] - '0' + a * m2) % 10 + '0');
        }
        return ans;
    }
public:
    string findLexSmallestString(string& s, int a, int b) {
        string ans = s;
        int totalRotate = b;
        do {
            // string thisStr = change2loc2min(s, a, b, s.size() - totalRotate);  cout << thisStr << endl;  //**********
            ans = min(ans, change2loc2min(s, a, b, s.size() - totalRotate));
            totalRotate = (totalRotate + b) % s.size();
        } while (totalRotate != b);
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/19/LeetCode%201625.%E6%89%A7%E8%A1%8C%E6%93%8D%E4%BD%9C%E5%90%8E%E5%AD%97%E5%85%B8%E5%BA%8F%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129651164](https://letmefly.blog.csdn.net/article/details/129651164)
