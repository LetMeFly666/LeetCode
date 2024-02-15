---
title: 1402.做菜顺序
date: 2023-10-22 15:48:30
tags: [题解, LeetCode, 困难, 贪心, 数组, 动态规划, 排序]
---

# 【LetMeFly】1402.做菜顺序：排序 + 前缀（贪心） - 按思路讲解

力扣题目链接：[https://leetcode.cn/problems/reducing-dishes/](https://leetcode.cn/problems/reducing-dishes/)

<p>一个厨师收集了他&nbsp;<code>n</code>&nbsp;道菜的满意程度&nbsp;<code>satisfaction</code>&nbsp;，这个厨师做出每道菜的时间都是 1 单位时间。</p>

<p>一道菜的 「喜爱时间」系数定义为烹饪这道菜以及之前每道菜所花费的时间乘以这道菜的满意程度，也就是&nbsp;<code>time[i]</code>*<code>satisfaction[i]</code>&nbsp;。</p>

<p>请你返回做完所有菜 「喜爱时间」总和的最大值为多少。</p>

<p>你可以按&nbsp;<strong>任意</strong>&nbsp;顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>satisfaction = [-1,-8,0,5,-9]
<strong>输出：</strong>14
<strong>解释：</strong>去掉第二道和最后一道菜，最大的喜爱时间系数和为 (-1*1 + 0*2 + 5*3 = 14) 。每道菜都需要花费 1 单位时间完成。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>satisfaction = [4,3,2]
<strong>输出：</strong>20
<strong>解释：</strong>按照原来顺序相反的时间做菜 (2*1 + 3*2 + 4*3 = 20)
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>satisfaction = [-1,-4,-5]
<strong>输出：</strong>0
<strong>解释：</strong>大家都不喜欢这些菜，所以不做任何菜可以获得最大的喜爱时间系数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == satisfaction.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>-1000 &lt;= satisfaction[i] &lt;= 1000</code></li>
</ul>


    
## 方法一：排序 + 前缀（贪心）

假设选了一个做菜序列$[a,b,c,d,\cdots]$，那么很容易想到这道题的关键：菜开始的越晚权重越大。因此本题的核心思路（贪心）是：**satisfaction越高的菜越往后放**。

二话不说，先**排个序**吧。反正satisfaction为正的菜是一定要做的（只有好处没有坏处），所以就**二分查找**一下排序后第一个satisfaction为正的菜的位置positiveLocation，从positiveLocation到数组末尾的“正菜”先依次加入到做菜序列中。

好了，“正菜”处理完了，那么“负菜”就一无是处了吗？当然不是。每往做菜序列前面增加一道菜品，后面每道菜的权重都会加一。也就是说，**在现在的做菜序列基础上，每新加一道负菜，总分的变化是“正菜satisfaction之和 加上 负菜satisfaction之和”**（含新增的负菜。

那么到底怎么处理负菜呢？只需要统计一下“正菜satisfaction之和sumPositive”，以及加上这道负菜的话“负菜satisfaction之和sumNegative”，如果$abs(sumPositive) >= abs(sumNegative)$，那么就将这道菜加入到做菜序列之首，否则就不加。

对于同为负数的两道菜，当然是优先选择较大的那个负数菜喽（能选$-1$不选$-2$）。

+ 时间复杂度$O(n\times \log n)$。排序的时间复杂度是$n\log n$，二分（只二分了一次）的时间复杂度为$\log n$，选菜的总时间复杂度不超过$O(n)$。其中$n=len(satisfaction)$。
+ 空间复杂度$O(\log n)$。排序的空间复杂度为$O(\log n)$，其余部分空间复杂度都为$O(1)$。

> 其实本题中也可以不使用二分查找来获取“第一个正菜”的位置，可以使用遍历（复杂的不变）或从数组末尾开始往前遍历（不一定从最小的正菜开始）。
>
> 这里感谢[github@5hepp](https://github.com/kahakaha)以及[github@HuangSizhe](https://github.com/SWHsz)的建议~

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int positiveLocation = upper_bound(satisfaction.begin(), satisfaction.end(), 0) - satisfaction.begin();
        int ans = 0, sumPositive = 0;
        for (int i = positiveLocation; i < satisfaction.size(); i++) {
            ans += (i - positiveLocation + 1) * satisfaction[i];
            sumPositive += satisfaction[i];
        }
        int sumNegative = 0;
        for (int i = positiveLocation - 1; i >= 0; i--) {
            sumNegative += satisfaction[i];
            if (-sumNegative > sumPositive) {
                break;
            }
            ans += sumPositive + sumNegative;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List
# from bisect import bisect_right


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        positiveLocation = bisect_right(satisfaction, 0)
        ans, sumPositive = 0, 0
        for i in range(positiveLocation, len(satisfaction)):
            ans += (i - positiveLocation + 1) * satisfaction[i]
            sumPositive += satisfaction[i]
        sumNegative = 0
        for i in range(positiveLocation - 1, -1, -1):
            sumNegative += satisfaction[i]
            if -sumNegative > sumPositive:
                break
            ans += sumPositive + sumNegative
        return ans

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/10/22/LeetCode%201402.%E5%81%9A%E8%8F%9C%E9%A1%BA%E5%BA%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/133974648](https://letmefly.blog.csdn.net/article/details/133974648)
