---
title: 710.黑名单中的随机数
date: 2022-06-26 08:00:19
tags: [题解, LeetCode, 困难, Rand, 哈希表, 数学, 二分查找, 排序, 随机]
---

# 【LetMeFly】710.黑名单中的随机数 - 预处理实现O(1)取值

力扣题目链接：[https://leetcode.cn/problems/random-pick-with-blacklist/](https://leetcode.cn/problems/random-pick-with-blacklist/)

<p>给定一个整数 <code>n</code> 和一个 <strong>无重复</strong> 黑名单整数数组&nbsp;<code>blacklist</code>&nbsp;。设计一种算法，从 <code>[0, n - 1]</code> 范围内的任意整数中选取一个&nbsp;<strong>未加入&nbsp;</strong>黑名单&nbsp;<code>blacklist</code>&nbsp;的整数。任何在上述范围内且不在黑名单&nbsp;<code>blacklist</code>&nbsp;中的整数都应该有 <strong>同等的可能性</strong> 被返回。</p>

<p>优化你的算法，使它最小化调用语言 <strong>内置</strong> 随机函数的次数。</p>

<p>实现&nbsp;<code>Solution</code>&nbsp;类:</p>

<ul>
	<li><code>Solution(int n, int[] blacklist)</code>&nbsp;初始化整数 <code>n</code> 和被加入黑名单&nbsp;<code>blacklist</code>&nbsp;的整数</li>
	<li><code>int pick()</code>&nbsp;返回一个范围为 <code>[0, n - 1]</code> 且不在黑名单&nbsp;<code>blacklist</code> 中的随机整数</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
<strong>输出</strong>
[null, 0, 4, 1, 6, 1, 0, 4]

<b>解释
</b>Solution solution = new Solution(7, [2, 3, 5]);
solution.pick(); // 返回0，任何[0,1,4,6]的整数都可以。注意，对于每一个pick的调用，
                 // 0、1、4和6的返回概率必须相等(即概率为1/4)。
solution.pick(); // 返回 4
solution.pick(); // 返回 1
solution.pick(); // 返回 6
solution.pick(); // 返回 1
solution.pick(); // 返回 0
solution.pick(); // 返回 4
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= blacklist.length &lt;- min(10<sup>5</sup>, n - 1)</code></li>
	<li><code>0 &lt;= blacklist[i] &lt; n</code></li>
	<li><code>blacklist</code>&nbsp;中所有值都 <strong>不同</strong></li>
	<li>&nbsp;<code>pick</code>&nbsp;最多被调用&nbsp;<code>2 * 10<sup>4</sup></code>&nbsp;次</li>
</ul>

## 方法一：预处理实现O(1)取值

这一题我们可以预处理一下：把$[0, \min(n, 10^5))$中未出现的数字记录下来。

> 具体方法为：
> 把```blacklist```排序，使用一个指针初始值指向下标```0```。
> $i$从$[0, min(n, 10^5))$遍历每一个数，如果指针已经达到了```blacklist```的结尾，就记录下当前遍历到的$i$，否则看$指针所指元素$和$i$是否相同：若相同就说明$i$在```blacklist```中，指针后移并且不记录$i$；否则记录下$i$
> 上述算法得益于“```blacklist```中的值互补相同”。如果```blacklist```中存在相同的值，那么在“$指针所指元素=i$”时，指针不断后移，直到$当前指针所指元素\neq i$

知道了$[0, \min(n, 10^5))$中所有未出现过的数字，我们就能用$O(1)$的时间rand出一个值来。

> 具体方法为：
> 我们知道了$[0, \min(n, 10^5))$中未出现的数字，就能求得$[0,n)$中所有未出现过的数字的个数：$allNum=[0,\min(n, 10^5))中未出现的数字的个数+[10^5, n)的所有数字的个数$
> 这样只需要一次rand（$th = rand() \% allNum$就能在[0, allNum)范围内rand），拿$th$和$[0,n)$中所有未出现过的数字的个数做比较：小于则返回$[0,n)$中第$th + 1$个未出现的值；否则返回从$1e5$开始的第$th - smallNum + 1$个值


+ 时间复杂度$O(N\log N + M)$，其中$N=min(n, 10^5)$，$M$为调用次数。时间复杂度主要来自预处理，之后每次调用都只需要$O(1)$的时间复杂度。
+ 空间复杂度$O(S\log S)$，其中$S=blacklist.length$。空间复杂度主要来自预处理的排序（$O(S\log S)$），只需要$O(S)$的额外空间存储未出现过的值。

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<int> smallCan;  // 小范围数据可选取
    int n;
    int smallTo;
    int smallNum, allNum;
public:
    Solution(int n, vector<int>& blacklist): n(n) {
        sort(blacklist.begin(), blacklist.end());
        int loc = 0;
        int size = blacklist.size();
        smallTo = min(100000, n);
        for (int i = 0; i < smallTo; i++) {
            if (loc == size)
                smallCan.push_back(i);
            else {
                if (i == blacklist[loc]) {  // blacklist 中所有值都 不同
                    loc++;
                }
                else {
                    smallCan.push_back(i);
                }
            }
        }
        smallNum = smallCan.size();
        allNum = smallNum + (n - smallTo);
    }
    
    int pick() {
        int th = rand() % allNum;
        if (th < smallNum) {
            return smallCan[th];
        }
        else {
            return smallTo + (th - smallNum);
        }
    }
};
```


> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/06/26/LeetCode%200710.%20%E9%BB%91%E5%90%8D%E5%8D%95%E4%B8%AD%E7%9A%84%E9%9A%8F%E6%9C%BA%E6%95%B0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125466455](https://letmefly.blog.csdn.net/article/details/125466455)
    