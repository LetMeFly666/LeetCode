---
title: 67.二进制求和
date: 2022-07-14 21:36:50
tags: [题解, LeetCode, 简单, 位运算, 数学, 字符串, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】67.二进制求和

力扣题目链接：[https://leetcode.cn/problems/add-binary/](https://leetcode.cn/problems/add-binary/)

<p>给你两个二进制字符串，返回它们的和（用二进制表示）。</p>

<p>输入为 <strong>非空 </strong>字符串且只包含数字&nbsp;<code>1</code>&nbsp;和&nbsp;<code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> a = &quot;11&quot;, b = &quot;1&quot;
<strong>输出:</strong> &quot;100&quot;</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入:</strong> a = &quot;1010&quot;, b = &quot;1011&quot;
<strong>输出:</strong> &quot;10101&quot;</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>每个字符串仅由字符 <code>&#39;0&#39;</code> 或 <code>&#39;1&#39;</code> 组成。</li>
	<li><code>1 &lt;= a.length, b.length &lt;= 10^4</code></li>
	<li>字符串如果不是 <code>&quot;0&quot;</code> ，就都不含前导零。</li>
</ul>



## 方法一：reverse

这里我对字符串进行了一个处理，先把字符串前后颠倒了一下顺序（123变成321），计算后再颠倒回来。

这样做的目的是字符串往后添加比较容易（直接```s += '0'```即可），并且数位比较容易对齐（最低位的下标都变成了0）。当然你也可以选择不这么做，直接insert到前面也一样。

我们只需要用一个变量记录“进位”，初始值是```0```。

然后令```a```为长度长的数字，从```0```到```a.size()```枚举```a```的每一位，如果```b```也有对应的这一位，就加之。

![今日收到百度寄过来的礼品啦](https://https://cors.letmefly.xyz/https://img-blog.csdnimg.cn/8a7c122488d14b2b9ab60b982372b049.jpeg#pic_center)

+ 时间复杂度$O(n)$，其中$n$是两个数字的最大长度
+ 空间复杂度$O(1)$（没考虑reverse所消耗的空间）

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2022-06-08 11:33:09
 */
class Solution {
public:
    string addBinary(string& a, string& b) {
        bool JinWei = false;
        if (a.size() < b.size())
            swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < a.size(); i++) {
            int cnt = JinWei;
            cnt += a[i] - '0';
            if (i < b.size())
                cnt += b[i] - '0';
            a[i] = (cnt % 2) + '0';
            JinWei = cnt / 2;
        }
        if (JinWei)
            a += '1';
        reverse(a.begin(), a.end());
        return a;
    }
};
```

#### C++ - 写法2

```cpp
/*
 * @LastEditTime: 2026-02-15 12:38:31
 */
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int cnt = 0;
        for (int i = 0, to = max(a.size(), b.size()); i < to; i++) {
            cnt += i < a.size() ? a[i] - '0' : 0;
            cnt += i < b.size() ? b[i] - '0' : 0;
            ans.push_back('0' + (cnt % 2));
            cnt >>= 1;
        }
        if (cnt) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Python - 内部库 string->int->string

```python
'''
LastEditTime: 2026-02-15 12:45:41
'''
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return format((int(a, 2) + int(b, 2)), 'b')
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/125793685)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2022/07/14/LeetCode%200067.%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%B1%82%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
