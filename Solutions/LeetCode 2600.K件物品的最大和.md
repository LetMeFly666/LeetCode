---
title: 2600.K 件物品的最大和
date: 2023-07-05 07:44:40
tags: [题解, LeetCode, 简单, 贪心, 数学]
---

# 【LetMeFly】2600.K 件物品的最大和

力扣题目链接：[https://leetcode.cn/problems/k-items-with-the-maximum-sum/](https://leetcode.cn/problems/k-items-with-the-maximum-sum/)

<p>袋子中装有一些物品，每个物品上都标记着数字 <code>1</code> 、<code>0</code> 或 <code>-1</code> 。</p>

<p>给你四个非负整数 <code>numOnes</code> 、<code>numZeros</code> 、<code>numNegOnes</code> 和 <code>k</code> 。</p>

<p>袋子最初包含：</p>

<ul>
	<li><code>numOnes</code> 件标记为 <code>1</code> 的物品。</li>
	<li><code>numZeroes</code> 件标记为 <code>0</code> 的物品。</li>
	<li><code>numNegOnes</code> 件标记为 <code>-1</code> 的物品。</li>
</ul>

<p>现计划从这些物品中恰好选出 <code>k</code> 件物品。返回所有可行方案中，物品上所标记数字之和的最大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>numOnes = 3, numZeros = 2, numNegOnes = 0, k = 2
<strong>输出：</strong>2
<strong>解释：</strong>袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。取 2 件标记为 1 的物品，得到的数字之和为 2 。
可以证明 2 是所有可行方案中的最大值。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>numOnes = 3, numZeros = 2, numNegOnes = 0, k = 4
<strong>输出：</strong>3
<strong>解释：</strong>袋子中的物品分别标记为 {1, 1, 1, 0, 0} 。取 3 件标记为 1 的物品，1 件标记为 0 的物品，得到的数字之和为 3 。
可以证明 3 是所有可行方案中的最大值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= numOnes, numZeros, numNegOnes &lt;= 50</code></li>
	<li><code>0 &lt;= k &lt;= numOnes + numZeros + numNegOnes</code></li>
</ul>


    
## 方法一：贪心

选择一个“numOnes”能得1分，选择一个“numZeros”能得0分，选择一个“numNegOnes”得-1分；一共选k个，那当然是尽量选numOnes，之后尽量选numZeros，实在迫不得已再选numNegOnes。

因此我们可以建立一个二维数组：

```
a = [
	[numOnes, 1],
	[numZeros, 0],
	[numNegOnes, -1]
]
```

接着从0到2遍历数组$a$，在$k$未选择完时尽可能地选取$a[i][0]$，并将选择数量乘以$a[i][1]$累加到总分上。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        int a[3][2] = {{numOnes, 1}, {numZeros, 0}, {numNegOnes, -1}};
        for (int i = 0; i < 3; i++) {
            int thisNum = min(k, a[i][0]);
            ans += a[i][1] * thisNum;
            k -= thisNum;
        }
        return ans;
    }
};
```

#### Python

```python
class Solution:
    def kItemsWithMaximumSum(self, numOnes: int, numZeros: int, numNegOnes: int, k: int) -> int:
        ans = 0
        a = [[numOnes, 1], [numZeros, 0], [numNegOnes, -1]]
        for i in range(3):
            thisNum = min(k, a[i][0])
            ans += thisNum * a[i][1]
            k -= thisNum
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/07/05/LeetCode%202600.K%E4%BB%B6%E7%89%A9%E5%93%81%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/131547457](https://letmefly.blog.csdn.net/article/details/131547457)
