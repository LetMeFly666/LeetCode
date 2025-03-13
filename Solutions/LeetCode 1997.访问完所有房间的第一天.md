---
title: 1997.访问完所有房间的第一天
date: 2024-03-28 17:31:32
tags: [题解, LeetCode, 中等, 数组, 动态规划, DP]
categories: [题解, LeetCode]
---

# 【LetMeFly】1997.访问完所有房间的第一天：动态规划(DP)——4行主要代码(不需要什么前缀和)

力扣题目链接：[https://leetcode.cn/problems/first-day-where-you-have-been-in-all-the-rooms/](https://leetcode.cn/problems/first-day-where-you-have-been-in-all-the-rooms/)

<p>你需要访问&nbsp;<code>n</code> 个房间，房间从 <code>0</code> 到 <code>n - 1</code> 编号。同时，每一天都有一个日期编号，从 <code>0</code> 开始，依天数递增。你每天都会访问一个房间。</p>

<p>最开始的第 <code>0</code> 天，你访问&nbsp;<code>0</code> 号房间。给你一个长度为 <code>n</code> 且 <strong>下标从 0 开始</strong> 的数组 <code>nextVisit</code> 。在接下来的几天中，你访问房间的 <strong>次序</strong> 将根据下面的 <strong>规则</strong> 决定：</p>

<ul>
	<li>假设某一天，你访问&nbsp;<code>i</code> 号房间。</li>
	<li>如果算上本次访问，访问&nbsp;<code>i</code> 号房间的次数为 <strong>奇数</strong> ，那么 <strong>第二天</strong> 需要访问&nbsp;<code>nextVisit[i]</code> 所指定的房间，其中 <code>0 &lt;= nextVisit[i] &lt;= i</code> 。</li>
	<li>如果算上本次访问，访问&nbsp;<code>i</code> 号房间的次数为 <strong>偶数</strong> ，那么 <strong>第二天</strong> 需要访问&nbsp;<code>(i + 1) mod n</code> 号房间。</li>
</ul>

<p>请返回你访问完所有房间的第一天的日期编号。题目数据保证总是存在这样的一天。由于答案可能很大，返回对 <code>10<sup>9</sup> + 7</code> 取余后的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nextVisit = [0,0]
<strong>输出：</strong>2
<strong>解释：</strong>
- 第 0 天，你访问房间 0 。访问 0 号房间的总次数为 1 ，次数为奇数。
&nbsp; 下一天你需要访问房间的编号是 nextVisit[0] = 0
- 第 1 天，你访问房间 0 。访问 0 号房间的总次数为 2 ，次数为偶数。
&nbsp; 下一天你需要访问房间的编号是 (0 + 1) mod 2 = 1
- 第 2 天，你访问房间 1 。这是你第一次完成访问所有房间的那天。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nextVisit = [0,0,2]
<strong>输出：</strong>6
<strong>解释：</strong>
你每天访问房间的次序是 [0,0,1,0,0,1,2,...] 。
第 6 天是你访问完所有房间的第一天。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nextVisit = [0,1,2,0]
<strong>输出：</strong>6
<strong>解释：</strong>
你每天访问房间的次序是 [0,0,1,1,2,2,3,...] 。
第 6 天是你访问完所有房间的第一天。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nextVisit.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nextVisit[i] &lt;= i</code></li>
</ul>


    
## 解题方法：动态规划(DP)

题目中明确说明了```0 <= nextVisit[i] <= i```，也就是说每个房间第一次访问都会“往前回退”到```nextVisit[i]```而不会访问新的房间，而第二次访问则会访问到“相邻的下一个房间”。

因此我们可以使用一个```firstVisit```数组，其中```firstVisit[i]```代表房间```i```第一次被访问时的天数。

<font title="さて">那么</font>，由房间<code>i</code>访问到房间<code>i + 1</code>需要多久呢？

+ 首先需要花费一天访问到```nextVisit[i]```这个房间（记为```j```）
+ 接着需要花费```firstVisit[i] - firstVisit[j]```天再一次地由```j```访问到```i```
+ 最后再花费一天由```i```访问到```i + 1```

因此首次访问到房间```i + 1```的天数为```firstVisit[i] + 1 + (firstVisit[i] - firstVisit[j]) + 1 = 2 * firstVisit[i] - firstVisit[j] + 2```。

从房间```1```开始往后遍历到最后一间房间，则```firstVisit.back()```记为答案。

### 时空复杂度

+ 时间复杂度$O(len(nextVisit))$
+ 空间复杂度$O(len(nextVisit))$。其实不难发现```nextVisit```数组中每个值只会用到一次，因此若将```firstVisit```保存在```nextVisit```数组中则可以以$O(1)$的空间复杂度实现。

### AC代码

#### C++

```cpp
typedef long long ll;
const ll MOD = 1e9 + 7;
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        vector<ll> firstVisit(nextVisit.size());
        for (int i = 1; i < nextVisit.size(); i++) {
            firstVisit[i] = (firstVisit[i - 1] * 2 - firstVisit[nextVisit[i - 1]] + 2 + MOD) % MOD;  // 记得先加个MOD再对MOD取模，否则可能是负结果。
        }
        return firstVisit.back();
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
        firstVisit = [0] * len(nextVisit)
        for i in range(1, len(nextVisit)):
            firstVisit[i] = (firstVisit[i - 1] * 2 - firstVisit[nextVisit[i - 1]] + 2 + 1_000_000_007) % 1_000_000_007
        return firstVisit[-1]
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/28/LeetCode%201997.%E8%AE%BF%E9%97%AE%E5%AE%8C%E6%89%80%E6%9C%89%E6%88%BF%E9%97%B4%E7%9A%84%E7%AC%AC%E4%B8%80%E5%A4%A9/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137119523](https://letmefly.blog.csdn.net/article/details/137119523)
