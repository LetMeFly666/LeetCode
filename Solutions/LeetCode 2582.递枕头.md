---
title: 2582.递枕头
date: 2023-09-26 08:49:31
tags: [题解, LeetCode, 简单, 数学, 模拟]
---

# 【LetMeFly】2582.递枕头：清晰的话讲述 O(1)的时间算法

力扣题目链接：[https://leetcode.cn/problems/pass-the-pillow/](https://leetcode.cn/problems/pass-the-pillow/)

<p><code>n</code> 个人站成一排，按从 <code>1</code> 到 <code>n</code> 编号。</p>

<p>最初，排在队首的第一个人拿着一个枕头。每秒钟，拿着枕头的人会将枕头传递给队伍中的下一个人。一旦枕头到达队首或队尾，传递方向就会改变，队伍会继续沿相反方向传递枕头。</p>

<ul>
	<li>例如，当枕头到达第 <code>n</code> 个人时，TA 会将枕头传递给第 <code>n - 1</code> 个人，然后传递给第 <code>n - 2</code> 个人，依此类推。</li>
</ul>

<p>给你两个正整数 <code>n</code> 和 <code>time</code> ，返回 <code>time</code> 秒后拿着枕头的人的编号。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 4, time = 5
<strong>输出：</strong>2
<strong>解释：</strong>队伍中枕头的传递情况为：1 -&gt; 2 -&gt; 3 -&gt; 4 -&gt; 3 -&gt; 2 。
5 秒后，枕头传递到第 2 个人手中。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, time = 2
<strong>输出：</strong>3
<strong>解释：</strong>队伍中枕头的传递情况为：1 -&gt; 2 -&gt; 3 。
2 秒后，枕头传递到第 3 个人手中。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= time &lt;= 1000</code></li>
</ul>


    
## 方法一：计算

n个人传递枕头，从左到右需要传递$n-1$次。同理，从右到左也需要传$n-1$次。也就是说，$2\times(n-1)$次一循环。

因此，$time$直接模上个$2\times(n-1)$即等效于单轮传递的结果。

+ 如果$time\leq n-1$，则说明是在往右传。传$0$次处于$1$，传$1$次处于$2$，...，传$time$次处于$time + 1$。
+ 否则，说明是在往左传。往左传了$time - (n - 1)$次。往左传$0$次处于$n$，往左传$1$次处于$n-1$，...，往左传$time - (n - 1)$次处于$n - (time - (n - 1)) = 2 * n - time - 1$。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int passThePillow(int n, int time) {
        time %= (n - 1) * 2;
        return time <= n - 1 ? time + 1 : 2 * n - time - 1;
    }
};
```

#### Python

```python
class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        time %= (n - 1) * 2
        return time + 1 if time <= n - 1 else 2 * n - time - 1
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/26/LeetCode%202582.%E9%80%92%E6%9E%95%E5%A4%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133294825](https://letmefly.blog.csdn.net/article/details/133294825)
