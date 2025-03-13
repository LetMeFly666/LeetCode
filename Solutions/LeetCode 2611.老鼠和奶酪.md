---
title: 2611.老鼠和奶酪：排序 + 贪心
date: 2023-06-07 13:16:40
tags: [题解, LeetCode, 中等, 贪心, 数组, 排序, 堆（优先队列）]
categories: [题解, LeetCode]
---

# 【LetMeFly】2611.老鼠和奶酪：排序 + 贪心

力扣题目链接：[https://leetcode.cn/problems/mice-and-cheese/](https://leetcode.cn/problems/mice-and-cheese/)

<p>有两只老鼠和&nbsp;<code>n</code>&nbsp;块不同类型的奶酪，每块奶酪都只能被其中一只老鼠吃掉。</p>

<p>下标为 <code>i</code>&nbsp;处的奶酪被吃掉的得分为：</p>

<ul>
	<li>如果第一只老鼠吃掉，则得分为&nbsp;<code>reward1[i]</code>&nbsp;。</li>
	<li>如果第二只老鼠吃掉，则得分为&nbsp;<code>reward2[i]</code>&nbsp;。</li>
</ul>

<p>给你一个正整数数组&nbsp;<code>reward1</code>&nbsp;，一个正整数数组&nbsp;<code>reward2</code>&nbsp;，和一个非负整数&nbsp;<code>k</code>&nbsp;。</p>

<p>请你返回第一只老鼠恰好吃掉 <code>k</code>&nbsp;块奶酪的情况下，<strong>最大</strong>&nbsp;得分为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
<b>输出：</b>15
<b>解释：</b>这个例子中，第一只老鼠吃掉第 2&nbsp;和 3 块奶酪（下标从 0 开始），第二只老鼠吃掉第 0 和 1 块奶酪。
总得分为 4 + 4 + 3 + 4 = 15 。
15 是最高得分。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>reward1 = [1,1], reward2 = [1,1], k = 2
<b>输出：</b>2
<b>解释：</b>这个例子中，第一只老鼠吃掉第 0 和 1 块奶酪（下标从 0 开始），第二只老鼠不吃任何奶酪。
总得分为 1 + 1 = 2 。
2 是最高得分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == reward1.length == reward2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= reward1[i],&nbsp;reward2[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= n</code></li>
</ul>


    
## 方法一：排序 + 贪心

假如全部奶酪被老鼠$2$吃掉，那么将会获得$\sum reward_2$分。

在此基础上，如果第$i$块奶酪换成被第$1$个老鼠吃掉，那么分数将会变化$reward_1[i]-reward_2[i]$。

又因为第$1$只老鼠必须吃掉$k$块奶酪，因此最好是吃掉$reward_1[i]-reward_2[i]$最大的$k$块奶酪。

提前计算出所有的$reward_1[i]-reward_2[i]$并排序，选取最大的$k$个与$\sum reward_2$求和即为答案。

+ 时间复杂度$O(n \log n)$，其中$n=len(reward_1)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> first(reward1.size());
        int ans = 0;
        for (int i = 0; i < reward1.size(); i++) {
            ans += reward2[i];
            first[i] = reward1[i] - reward2[i];
        }
        sort(first.begin(), first.end());
        while (k) {
            ans += first[first.size() - k--];
        }
        return ans;
    }
};
```

#### Python

Py代码太简洁辣！

```python
# from typing import List

class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        ans = sum(reward2)
        first = [reward1[i] - reward2[i] for i in range(len(reward1))]
        first.sort()
        while k:
            ans += first[-k]
            k -= 1
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/06/07/LeetCode%202611.%E8%80%81%E9%BC%A0%E5%92%8C%E5%A5%B6%E9%85%AA/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131085720](https://letmefly.blog.csdn.net/article/details/131085720)
