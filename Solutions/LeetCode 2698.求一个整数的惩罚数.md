---
title: 2698.求一个整数的惩罚数：模拟（二进制枚举）
date: 2023-10-25 19:42:34
tags: [题解, LeetCode, 中等, 数学, 回溯, 模拟, 二进制, 二进制枚举, 状态压缩]
---

# 【LetMeFly】2698.求一个整数的惩罚数：模拟（二进制枚举）

力扣题目链接：[https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/)

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，请你返回&nbsp;<code>n</code>&nbsp;的&nbsp;<strong>惩罚数</strong>&nbsp;。</p>

<p><code>n</code>&nbsp;的 <strong>惩罚数</strong>&nbsp;定义为所有满足以下条件 <code>i</code>&nbsp;的数的平方和：</p>

<ul>
	<li><code>1 &lt;= i &lt;= n</code></li>
	<li><code>i * i</code> 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 <code>i</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>n = 10
<b>输出：</b>182
<b>解释：</b>总共有 3 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
因此，10 的惩罚数为 1 + 81 + 100 = 182
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>n = 37
<b>输出：</b>1478
<b>解释：</b>总共有 4 个整数 i 满足要求：
- 1 ，因为 1 * 1 = 1
- 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
- 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
- 36 ，因为 36 * 36 = 1296 ，且 1296 可以分割成 1 + 29 + 6 。
因此，37 的惩罚数为 1 + 81 + 100 + 1296 = 1478
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


    
## 方法一：模拟（二进制枚举）

其实很简单，用$i$从$1$到$n$枚举，对于某个$i$：

将$i^2$转为字符串处理，接着用二进制从$0$到$2^{len(i^2)}-1$枚举“切割平方字符串的位置”，将每一部分的字符串相加看是否等于$i^2$即可。

+ 时间复杂度$O(n\times \log n)$（$\log n^2=2\times\log n$）
+ 空间复杂度$O(\log n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    int check(int n) {
        string to = to_string(n * n);
        int l = to.size();
        for (int mask = 0; mask < (1 << l); mask++) {
            int cnt = 0;
            int nowNum = 0;
            for (int i = 0; i < l; i++) {
                nowNum = nowNum * 10 + (to[i] - '0');
                if ((mask >> i) & 1) {  // 这一位后面隔开
                    cnt += nowNum;
                    nowNum = 0;
                }
            }
            if (cnt + nowNum == n) {  // 想着“会有结尾的i是不行的”
                return n * n;
            }
        }
        return 0;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += check(i);
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def check(self, n: int) -> int:
        to = str(n * n)
        l = len(to)
        for mask in range(1 << l):
            cnt = 0
            thisNum = 0
            for i in range(l):
                thisNum = thisNum * 10 + ord(to[i]) - ord('0')
                if (mask >> i) & 1:
                    cnt += thisNum
                    thisNum = 0
            if cnt + thisNum == n:
                return n * n
        return 0


    def punishmentNumber(self, n: int) -> int:
        return sum(self.check(i) for i in range(1, n + 1))
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/25/LeetCode%202698.%E6%B1%82%E4%B8%80%E4%B8%AA%E6%95%B4%E6%95%B0%E7%9A%84%E6%83%A9%E7%BD%9A%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/134043248](https://letmefly.blog.csdn.net/article/details/134043248)
