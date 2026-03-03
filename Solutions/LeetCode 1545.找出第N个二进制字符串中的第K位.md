---
title: 1545.找出第 N 个二进制字符串中的第 K 位：模拟 或 递归(数学)
date: 2026-03-03 09:29:45
tags: [题解, LeetCode, 中等, 递归, 字符串, 模拟, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】1545.找出第 N 个二进制字符串中的第 K 位：模拟 或 递归(数学)

力扣题目链接：[https://leetcode.cn/problems/find-kth-bit-in-nth-binary-string/](https://leetcode.cn/problems/find-kth-bit-in-nth-binary-string/)

<p>给你两个正整数 <code>n</code> 和 <code>k</code>，二进制字符串  <code>S<sub>n</sub></code> 的形成规则如下：</p>

<ul>
	<li><code>S<sub>1</sub> = "0"</code></li>
	<li>当 <code>i > 1</code> 时，<code>S<sub>i</sub> = S<sub>i-1</sub> + "1" + reverse(invert(S<sub>i-1</sub>))</code></li>
</ul>

<p>其中 <code>+</code> 表示串联操作，<code>reverse(x)</code> 返回反转 <code>x</code> 后得到的字符串，而 <code>invert(x)</code> 则会翻转 x 中的每一位（0 变为 1，而 1 变为 0）。</p>

<p>例如，符合上述描述的序列的前 4 个字符串依次是：</p>

<ul>
	<li><code>S<sub>1 </sub>= "0"</code></li>
	<li><code>S<sub>2 </sub>= "0<strong>1</strong>1"</code></li>
	<li><code>S<sub>3 </sub>= "011<strong>1</strong>001"</code></li>
	<li><code>S<sub>4</sub> = "0111001<strong>1</strong>0110001"</code></li>
</ul>

<p>请你返回  <code>S<sub>n</sub></code> 的 <strong>第 <code>k</code> 位字符</strong> ，题目数据保证 <code>k</code> 一定在 <code>S<sub>n</sub></code> 长度范围以内。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, k = 1
<strong>输出：</strong>"0"
<strong>解释：</strong>S<sub>3</sub> 为 "<strong>0</strong>111001"，其第 1 位为 "0" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 4, k = 11
<strong>输出：</strong>"1"
<strong>解释：</strong>S<sub>4</sub> 为 "0111001101<strong>1</strong>0001"，其第 11 位为 "1" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1, k = 1
<strong>输出：</strong>"0"
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 3
<strong>输出：</strong>"1"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= n <= 20</code></li>
	<li><code>1 <= k <= 2<sup>n</sup> - 1</code></li>
</ul>


# 解题方法

## 解题方法一：模拟

写一个函数，求当前字符串的下一个字符串，一直模拟$n-1$次`next`就好了。注意最终返回下标`k-1`。

+ 时间复杂度$O(2^n)$
+ 空间复杂度$O(2^n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-03 09:14:52
 */
class Solution {
private:
    void invert(string& s) {
        for (char& c : s) {
            c = c == '0' ? '1' : '0';
        }
    }

    string next(string& now) {
        string ans = now + '1';
        invert(now);
        reverse(now.begin(), now.end());
        ans += now;
        return ans;
    }
public:
    char findKthBit(int n, int k) {
        string now = "0";
        for (int i = 2; i <= n; i++) {
            now = next(now);
        }
        return now[k - 1];
    }
};
```

## 解题方法一：递归 + 数学

对于字符串长度：

```
n1 = 1
n2 = 2 * n1 + 1
n3 = 2 * n2 + 1

...

n_k = ?
```

答案是$n_k=2^k-1$，原因如下：

> $n_{k+1} = 2n_k + 1$
>
> 两边都加一：$n_{k+1} + 1 = 2n_k + 1 + 1 = 2(n_k + 1)$
>
> 令 $a_k = n_k + 1$，则：$a_{k+1} = 2 \cdot a_k$
>
> $a_k$是一个公比为2的等比数列，且初项$a_1=n_1+1=2$，所以$a_k=2^k$
>
> 由于$a_k = n_k + 1$，所以$n_k=a_k-1=2^k-1$。

那么`findKthBit

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-03-03 09:28:21
 */
class Solution {
public:
    char findKthBit(int n, int k, bool invert=false) {
        if (n == 1) {
            return invert ? '1' : '0';
        }
        int len = (1 << n) - 1;
        int half_len = len >> 1;
        if (k == half_len + 1) {
            return invert ? '0' : '1';
        } else if (k <= half_len) {
            return findKthBit(n - 1, k, invert);
        } else {
            return findKthBit(n - 1, len - k + 1, 1 ^ invert);  // n = 2, k = 3 -> len = 3, half_len = 1, next_k = 1
        }
    }
};
```


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/03/03/LeetCode%201545.%E6%89%BE%E5%87%BA%E7%AC%ACN%E4%B8%AA%E4%BA%8C%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E7%AC%ACK%E4%BD%8D/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
