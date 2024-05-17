---
title: 1953.你可以工作的最大周数
date: 2024-05-16 20:21:29
tags: [题解, LeetCode, 中等, 贪心, 数组]
---

# 【LetMeFly】1953.你可以工作的最大周数：贪心（两个变量一次遍历秒了）

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/](https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/)

<p>给你&nbsp;<code>n</code> 个项目，编号从 <code>0</code> 到 <code>n - 1</code> 。同时给你一个整数数组 <code>milestones</code> ，其中每个 <code>milestones[i]</code> 表示第 <code>i</code> 个项目中的阶段任务数量。</p>

<p>你可以按下面两个规则参与项目中的工作：</p>

<ul>
	<li>每周，你将会完成 <strong>某一个</strong> 项目中的 <strong>恰好一个</strong>&nbsp;阶段任务。你每周都 <strong>必须</strong> 工作。</li>
	<li>在 <strong>连续的</strong> 两周中，你 <strong>不能</strong> 参与并完成同一个项目中的两个阶段任务。</li>
</ul>

<p>一旦所有项目中的全部阶段任务都完成，或者仅剩余一个阶段任务都会导致你违反上面的规则，那么你将&nbsp;<strong>停止工作</strong> 。注意，由于这些条件的限制，你可能无法完成所有阶段任务。</p>

<p>返回在不违反上面规则的情况下你&nbsp;<strong>最多</strong>&nbsp;能工作多少周。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>milestones = [1,2,3]
<strong>输出：</strong>6
<strong>解释：</strong>一种可能的情形是：
​​​​- 第 1 周，你参与并完成项目 0 中的一个阶段任务。
- 第 2 周，你参与并完成项目 2 中的一个阶段任务。
- 第 3 周，你参与并完成项目 1 中的一个阶段任务。
- 第 4 周，你参与并完成项目 2 中的一个阶段任务。
- 第 5 周，你参与并完成项目 1 中的一个阶段任务。
- 第 6 周，你参与并完成项目 2 中的一个阶段任务。
总周数是 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>milestones = [5,2,1]
<strong>输出：</strong>7
<strong>解释：</strong>一种可能的情形是：
- 第 1 周，你参与并完成项目 0 中的一个阶段任务。
- 第 2 周，你参与并完成项目 1 中的一个阶段任务。
- 第 3 周，你参与并完成项目 0 中的一个阶段任务。
- 第 4 周，你参与并完成项目 1 中的一个阶段任务。
- 第 5 周，你参与并完成项目 0 中的一个阶段任务。
- 第 6 周，你参与并完成项目 2 中的一个阶段任务。
- 第 7 周，你参与并完成项目 0 中的一个阶段任务。
总周数是 7 。
注意，你不能在第 8 周参与完成项目 0 中的最后一个阶段任务，因为这会违反规则。
因此，项目 0 中会有一个阶段任务维持未完成状态。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == milestones.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= milestones[i] &lt;= 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：贪心——两个变量+一次遍历

相邻两周工作内容不能相同，怎么安排才能工作最久？当然是**小杂活穿插在最多的工作之间**。小杂活是指“工作次数较少的任务”，最多的工作是指在所有工作当中次数最多的那个工作。

那么不就两种情况么？

1. “最多的工作”特别特别多（假设为A），那么只能“A、x、A、y、A、...、A”，最多工作$2\times A+1$周
2. “最多的工作”也不是很多（$A\times 2\leq 总工作量$），那么能在相邻工作不同的前提下安排完所有的工作
   > 怎么安排？假设任务为$A\times3+B\times4+C\times3+D$，则里面任务最多的是$B$。
   >
   > 将B一个间隔一个地放置，直至序列末尾（B肯定不够用，没关系，那就使用另外任意一个或多个任务“接力”，直到放到末尾为止）
   >
   > 初始为：$\_\ \_\ \_\ \_\ \_\ \_\ \_\ \_\ \_\ \_\ \_\ $
   >
   > 间隔放，用完所有的B用A：$B\ \_\ B\ \_\ B\ \_\ B\ \_\ A\ \_\ A\ $
   >
   > 若A还有剩余，则在剩下的空位中从前往后依次放置：$B\ A\ B\ \_\ B\ \_\ B\ \_\ A\ \_\ A\ $（这里因为A的数量很少，所以前面和后面的A一定不会相遇）
   >
   > 剩下所有没被安排的任务，随意放喽，一定不会相邻了：$B\ A\ B\ C\ B\ C\ B\ C\ A\ D\ A\ $

   
因此只需要统计一下总共多少工时、最大工时是多少即可。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
typedef long long ll;

class Solution {
public:
    ll numberOfWeeks(vector<int>& milestones) {
        ll cnt = 0, M = 0;
        for (int t : milestones) {
            cnt += t;
            M = max(M, (ll)t);
        }
        return M * 2 <= cnt ? cnt : (cnt - M) * 2 + 1;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        cnt, M  =0, 0
        for t in milestones:
            cnt += t
            M = max(M, t)
        return cnt if M * 2 <= cnt else (cnt - M) * 2 + 1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/16/LeetCode%201953.%E4%BD%A0%E5%8F%AF%E4%BB%A5%E5%B7%A5%E4%BD%9C%E7%9A%84%E6%9C%80%E5%A4%A7%E5%91%A8%E6%95%B0/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138974368](https://letmefly.blog.csdn.net/article/details/138974368)
