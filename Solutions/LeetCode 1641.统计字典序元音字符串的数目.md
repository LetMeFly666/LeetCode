---
title: 1641.统计字典序元音字符串的数目
date: 2023-03-29 10:31:06
tags: [题解, LeetCode, 中等, 动态规划, DP, 数学, 排列组合, 组合, 思维]
---

# 【LetMeFly】1641.统计字典序元音字符串的数目

力扣题目链接：[https://leetcode.cn/problems/count-sorted-vowel-strings/](https://leetcode.cn/problems/count-sorted-vowel-strings/)

<p>给你一个整数 <code>n</code>，请返回长度为 <code>n</code> 、仅由元音 (<code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, <code>u</code>) 组成且按 <strong>字典序排列</strong> 的字符串数量。</p>

<p>字符串 <code>s</code> 按 <strong>字典序排列</strong> 需要满足：对于所有有效的 <code>i</code>，<code>s[i]</code> 在字母表中的位置总是与 <code>s[i+1]</code> 相同或在 <code>s[i+1]</code> 之前。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>5
<strong>解释：</strong>仅由元音组成的 5 个字典序字符串为 <code>["a","e","i","o","u"]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>15
<strong>解释：</strong>仅由元音组成的 15 个字典序字符串为
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 33
<strong>输出：</strong>66045
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
    <li><code>1 <= n <= 50</code> </li>
</ul>


    
## 方法一.1：动态规划

我们一位一位地生成字符串，先生成长度为1的字符串“a、e、i、o、u”，再生成长度为2的字符串“aa、ae、...”，再生成长度为3的字符串，...，最终生成长度为n的字符串。

我们使用dp[i]代表生成当前长度字符串时，以第$i+1$个元音字母结尾的字符串的个数。

为什么要以**结尾**作为dp的转移条件呢？因为长度为$k$的字符串是在长度为$k-1$的字符串的基础上生成的（$k=0$时除外），生成的标准是，新添加上去的这一个字符，不小于之前的**最后一个字符**。只有这样，才能保证字符串为字典序。

+ 假如长度为$k-1$的字符串的最后一个字符为$a$，那么生成长度为$k$的字符串时，我们可以在上一个字符串最后的$a$的基础上，添加“a或e或i或o或u”；
+ 假如长度$k-1$的字符串的最后一个字符为$e$，那么生成长度为$k$的字符串时，我们可以在上一个字符串最后的$ae$的基础上，添加“e或i或o或u”；
+ ......

也就是说，新增的字符（假设是第j+1个元音）可以增加在$k-1$长的字符串的 所有不大于j+1结尾的字符 的后面

```cpp
for (int i = 2; i <= n; i++) {  // 生成长度为2的字符串
    int newDP[5] = {0, 0, 0, 0, 0};
    for (int j = 0; j < 5; j++) {  // 求新的dp[j]（newDP[j]）
        for (int k = 0; k <= j; k++) {  // 之前结尾字符不超过j的都可以
            newDP[j] += dp[k];
        }
    }
    swap(dp, newDP);  // 用新的dp覆盖之前的dp
}
```

+ 时间复杂度$O(n \times C^2)$，其中$C$是元音音符的个数$C=5$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; i++) {
            int newDp[5] = {0, 0, 0, 0, 0};
            for (int j = 0; j < 5; j++) {
                for (int i = 0; i <= j; i++) {
                    newDp[j] += dp[i];
                }
            }
            swap(dp, newDp);
        }
        return dp[0] + dp[1] + dp[2] + dp[3] + dp[4];
    }
};
```

#### Python

```python
class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [1 for _ in range(5)]
        for i in range(2, n + 1):
            newDp = [0 for _ in range(5)]
            for j in range(5):
                for k in range(0, j + 1):
                    newDp[j] += dp[k]
            dp = newDp
        return sum(dp)
```

## 方法一.2：动态规划

有没有办法在之前的基础上进行优化呢？

不难发现，$newDP[j] = \sum_{k=0}^{j} dp[k]$

比如$newDP[2] = dp[0] + dp[1] + dp[2]$

而$newDP[3] = dp[0] + dp[1] + dp[2] + dp[3]$

所以有$newDP[j] = newDP[j - 1] + dp[j]$

也就是说，新的dp可以在前一个dp结果的基础上，由$O(1)$的时间复杂度算出。

这样就优化了一层循环（虽然常数$C$仅仅为5）

```cpp
for (int i = 2; i <= n; i++) {  // 生成长度为2的字符串
    int newDP[5] = {dp[0], 0, 0, 0, 0};
    for (int j = 1; j < 5; j++) {  // 这里要从1开始
        newDP[j] = newDP[j - 1] + dp[j];
    }
    swap(dp, newDP);  // 用新的dp覆盖之前的dp
}
```

不难发现，我们可以将空间也进行一丢丢的优化：

```cpp
for (int i = 2; i <= n; i++) {  // 生成长度为2的字符串
    for (int j = 1; j < 5; j++) {  // 这里要从1开始
        dp[j] = dp[j - 1] + dp[j];
    }
}
```

+ 时间复杂度$O(n \times C)$，其中$C$是元音音符的个数$C=5$，这里由原来的$C^2$减小为了$C$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5] = {1, 1, 1, 1, 1};
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < 5; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return accumulate(dp, dp + 5, 0);
    }
};
```

#### Python

```python
class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [1 for _ in range(5)]
        for i in range(2, n + 1):
            for j in range(1, 5):
                dp[j] += dp[j - 1]
        return sum(dp)
```

## 方法二：数学 之 排列组合

方法二完全不同于方法一，方法二采用数学思想，将问题巧妙地转化为排列组合问题。

现在我们换个角度：

**从左到右**有5个盒子，盒子的名称分别为a、e、i、o、u

现在有n个小球放入到这5个盒子中，盒子允许为空（允许一些盒子不放小球）

小球**全部**放入盒子中之后，**从左到右**拿出小球，取出哪个盒子中的小球，就往字符串中添加哪个盒子的名称。

诶？这不就生成长度为n的字典序字符串了吗？

**因此问题就转化为**： n个相同的小球放入5个盒子，允许某些盒子为空，有多少种放法。

**首先**我们考虑不允许盒子为空的情况：

将n个小球放入5个盒子，每个盒子中至少有一个小球，一共有多少种放法呢？

我们只需要拿4个**隔板**，在n个小球之间的$n-1$个间隔中，插入这4个隔板。这样，小球就被分成了5份。将每一份分别放入对应的盒子中即可达成目标。

$n-1$个间隔中放入4个隔板，有多少种放法？很简单，组合数$C_{n-1}^4$即为答案。

**接下来**我们考虑盒子允许为空的情况。

我们需要明白：n个小球放入5个盒子盒子能空 等价于 $n+5$个小球放入5个盒子盒子不空

这是为什么呢？$n+5$个小球放入5个盒子，每个盒子不能为空，那么我们可以先将其中的5个小球分别放入5个盒子中，剩下的n个小球随意放入5个盒子中（这样剩下的n个小球就可以随意放置，不用考虑是否哪个盒子中没有放小球了）

$n+5$个小球放入5个盒子且盒子不空，方法为$C_{n+5-1}^4=C_{n+4}^4=\frac{(n+4)\times(n+3)\times(n+2)\times(n+1)}{4\times3\times2\times1}$，**这，不就是我们要求的结果吗？**

+ 时间复杂度$O(C)$，其中$C$是元音音符的个数$C=5$，完全可以立即为$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
// n小球放入5个盒子中，允许为空
// C_{n - 1}^{4}为n小球放入5盒子且不空的情况，C_{n + 4}^{4}为n + 5小球放入5盒子且不空的情况（n + 5个小球放入5个盒子且不空，相当于先将多出的5个虚拟小球放入盒子中，其余n个小球随便放，可空）
class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
```

#### Python

```python
# from math import comb

class Solution:
    def countVowelStrings(self, n: int) -> int:
        return comb(n + 4, 4)
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/03/29/LeetCode%201641.%E7%BB%9F%E8%AE%A1%E5%AD%97%E5%85%B8%E5%BA%8F%E5%85%83%E9%9F%B3%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/129834519](https://letmefly.blog.csdn.net/article/details/129834519)
