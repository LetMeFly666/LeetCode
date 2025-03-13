---
title: 1535.找出数组游戏的赢家
date: 2024-05-19 11:12:40
tags: [题解, LeetCode, 中等, 数组, 模拟, 思维, 脑筋急转弯]
categories: [题解, LeetCode]
---

# 【LetMeFly】1535.找出数组游戏的赢家：脑筋急转弯（部分模拟）

力扣题目链接：[https://leetcode.cn/problems/find-the-winner-of-an-array-game/](https://leetcode.cn/problems/find-the-winner-of-an-array-game/)

<p>给你一个由 <strong>不同</strong> 整数组成的整数数组 <code>arr</code> 和一个整数 <code>k</code> 。</p>

<p>每回合游戏都在数组的前两个元素（即 <code>arr[0]</code> 和 <code>arr[1]</code> ）之间进行。比较 <code>arr[0]</code> 与 <code>arr[1]</code> 的大小，较大的整数将会取得这一回合的胜利并保留在位置 <code>0</code> ，较小的整数移至数组的末尾。当一个整数赢得 <code>k</code> 个连续回合时，游戏结束，该整数就是比赛的 <strong>赢家</strong> 。</p>

<p>返回赢得比赛的整数。</p>

<p>题目数据 <strong>保证</strong> 游戏存在赢家。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,1,3,5,4,6,7], k = 2
<strong>输出：</strong>5
<strong>解释：</strong>一起看一下本场游戏每回合的情况：
<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/30/q-example.png" style="height: 90px; width: 400px;">
因此将进行 4 回合比赛，其中 5 是赢家，因为它连胜 2 回合。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [3,2,1], k = 10
<strong>输出：</strong>3
<strong>解释：</strong>3 将会在前 10 个回合中连续获胜。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [1,9,8,2,3,7,6,4,5], k = 7
<strong>输出：</strong>9
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000
<strong>输出：</strong>99
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^6</code></li>
	<li><code>arr</code> 所含的整数 <strong>各不相同</strong> 。</li>
	<li><code>1 &lt;= k &lt;= 10^9</code></li>
</ul>


    
## 解题方法：部分模拟

首先我们部分模拟这个“比赛”过程，其中“部分”是指：

> 1. 只遍历一遍数组，当所有元素都参赛过至少一次时，模拟就停止
> 2. 只模拟赢家不关心输家，用变量记录赢家及连胜次数，输家直接丢掉

如果在上面的模拟中出现了$k$连胜者，那么直接返回，算法结束。否则开始脑筋急转弯：

> 请你想，数组都遍历过一遍了，那么最大的元素一定变成了```arr[0]```。
> 
> 由于数组中每个元素各不相同，因此其他元素永无翻身之日，这个元素必定不会输。
> 
> 所以，**不论要连胜多少轮，连胜者都将会是这个元素**。

也就是说，遍历一遍数组模拟结束时若未有$k$连胜者，那么当前胜者（数组中最大的数）将会是第一个$k$连胜者。

+ 时间复杂度$O(len(arr))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0], winTime = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (winner > arr[i]) {
                winTime++;
            }
            else {
                winner = arr[i];
                winTime = 1;
            }
            if (winTime == k) {
                return winner;
            }
        }
        return winner;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        winner, winTime = arr[0], 0
        for i in range(1, len(arr)):
            if winner > arr[i]:
                winTime += 1
            else:
                winner = arr[i]
                winTime = 1
            if winTime == k:
                return winner
        return winner
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/19/LeetCode%201535.%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E6%B8%B8%E6%88%8F%E7%9A%84%E8%B5%A2%E5%AE%B6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139040126](https://letmefly.blog.csdn.net/article/details/139040126)
