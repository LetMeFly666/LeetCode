---
title: 1010.总持续时间可被 60 整除的歌曲
date: 2023-05-07 16:50:05
tags: [题解, LeetCode, 中等, 数组, 哈希表, 计数, 数学, 取模, 同余]
---

# 【LetMeFly】1010.总持续时间可被 60 整除的歌曲

力扣题目链接：[https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/](https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/)

<p>在歌曲列表中，第 <code>i</code> 首歌曲的持续时间为 <code>time[i]</code> 秒。</p>

<p>返回其总持续时间（以秒为单位）可被 <code>60</code> 整除的歌曲对的数量。形式上，我们希望下标数字 <code>i</code> 和 <code>j</code> 满足&nbsp; <code>i &lt; j</code> 且有&nbsp;<code>(time[i] + time[j]) % 60 == 0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>time = [30,20,150,100,40]
<strong>输出：</strong>3
<strong>解释：</strong>这三对的总持续时间可被 60 整除：
(time[0] = 30, time[2] = 150): 总持续时间 180
(time[1] = 20, time[3] = 100): 总持续时间 120
(time[1] = 20, time[4] = 40): 总持续时间 60
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>time = [60,60,60]
<strong>输出：</strong>3
<strong>解释：</strong>所有三对的总持续时间都是 120，可以被 60 整除。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= time.length &lt;= 6 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= time[i] &lt;= 500</code></li>
</ul>


    
## 方法一：取模 + 计数

题目意思是两个数之和是60的整数倍。那么其实我们只需要关系两个数对60取模的余数即可，至于这个数是60的多少倍并不重要。

因此我们可以开辟一个大小为60的整型数组$bin$，数组中每个元素的初始值都是0。$bin[i]$用来记录遍历到当前为止，余数为$i$的歌曲的个数

这样，在遍历过程中，假如当前歌曲时长对60的余数是$j$，那么其需要和$(60-j)\%60$组成60的倍数。（这里60-j之和再对60取模主要是为了处理特殊情况：60倍数+60倍数还是60倍数，$0+0=0$）

因此，每次遍历到一首（时长对60取模是j的）歌曲，只需要加上$bin[(60-j)\%60]$即可

+ 时间复杂度$O(len(time))$
+ 空间复杂度$O(C)$，其中$C=60$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int bin[60] = {0};
        int ans = 0;
        for (int t : time) {
            ans += bin[(60 - t % 60) % 60];
            bin[t % 60]++;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        bin = [0] * 60
        ans = 0
        for t in time:
            ans += bin[(60 - t % 60) % 60]
            bin[t % 60] += 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/07/LeetCode%201010.%E6%80%BB%E6%8C%81%E7%BB%AD%E6%97%B6%E9%97%B4%E5%8F%AF%E8%A2%AB60%E6%95%B4%E9%99%A4%E7%9A%84%E6%AD%8C%E6%9B%B2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130544996](https://letmefly.blog.csdn.net/article/details/130544996)
