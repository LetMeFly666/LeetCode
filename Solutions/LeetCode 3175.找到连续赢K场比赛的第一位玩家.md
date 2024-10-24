---
title: 3175.找到连续赢 K 场比赛的第一位玩家
date: 2024-10-24 12:27:36
tags: [题解, LeetCode, 中等, 数组, 模拟]
---

# 【LetMeFly】3175.找到连续赢 K 场比赛的第一位玩家：一次遍历（记录胜者）——清晰题解

力扣题目链接：[https://leetcode.cn/problems/find-the-first-player-to-win-k-games-in-a-row/](https://leetcode.cn/problems/find-the-first-player-to-win-k-games-in-a-row/)

<p>有&nbsp;<code>n</code>&nbsp;位玩家在进行比赛，玩家编号依次为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。</p>

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>skills</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;，其中&nbsp;<code>skills[i]</code>&nbsp;是第 <code>i</code>&nbsp;位玩家的技能等级。<code>skills</code>&nbsp;中所有整数 <strong>互不相同</strong>&nbsp;。</p>

<p>所有玩家从编号 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;排成一列。</p>

<p>比赛进行方式如下：</p>

<ul>
	<li>队列中最前面两名玩家进行一场比赛，技能等级 <strong>更高</strong>&nbsp;的玩家胜出。</li>
	<li>比赛后，获胜者保持在队列的开头，而失败者排到队列的末尾。</li>
</ul>

<p>这个比赛的赢家是 <strong>第一位连续</strong>&nbsp;赢下&nbsp;<code>k</code>&nbsp;场比赛的玩家。</p>

<p>请你返回这个比赛的赢家编号。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>skills = [4,2,6,3,9], k = 2</span></p>

<p><b>输出：</b>2</p>

<p><strong>解释：</strong></p>

<p>一开始，队列里的玩家为&nbsp;<code>[0,1,2,3,4]</code>&nbsp;。比赛过程如下：</p>

<ul>
	<li>玩家 0 和 1 进行一场比赛，玩家 0 的技能等级高于玩家 1 ，玩家 0 胜出，队列变为&nbsp;<code>[0,2,3,4,1]</code>&nbsp;。</li>
	<li>玩家 0 和 2 进行一场比赛，玩家 2 的技能等级高于玩家 0 ，玩家 2 胜出，队列变为&nbsp;<code>[2,3,4,1,0]</code>&nbsp;。</li>
	<li>玩家 2 和 3 进行一场比赛，玩家 2 的技能等级高于玩家 3 ，玩家 2 胜出，队列变为&nbsp;<code>[2,4,1,0,3]</code>&nbsp;。</li>
</ul>

<p>玩家 2 连续赢了&nbsp;<code>k = 2</code>&nbsp;场比赛，所以赢家是玩家 2 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>skills = [2,5,4], k = 3</span></p>

<p><b>输出：</b>1</p>

<p><strong>解释：</strong></p>

<p>一开始，队列里的玩家为&nbsp;<code>[0,1,2]</code>&nbsp;。比赛过程如下：</p>

<ul>
	<li>玩家 0 和 1 进行一场比赛，玩家 1 的技能等级高于玩家 0 ，玩家 1 胜出，队列变为&nbsp;<code>[1,2,0]</code>&nbsp;。</li>
	<li>玩家 1&nbsp;和 2&nbsp;进行一场比赛，玩家 1 的技能等级高于玩家 2&nbsp;，玩家 1 胜出，队列变为&nbsp;<code>[1,0,2]</code>&nbsp;。</li>
	<li>玩家 1&nbsp;和 0&nbsp;进行一场比赛，玩家 1 的技能等级高于玩家 0&nbsp;，玩家 1 胜出，队列变为&nbsp;<code>[1,2,0]</code>&nbsp;。</li>
</ul>

<p>玩家 1 连续赢了&nbsp;<code>k = 3</code>&nbsp;场比赛，所以赢家是玩家 1 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == skills.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= skills[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>skills</code>&nbsp;中的整数互不相同。</li>
</ul>


    
## 解题方法：擂台调整-一次遍历

首先需要明白：

1. 一个人若是失败一场，则他将永无出头之日，永远作为一个失败者（因此失败后他的值不再重要，不用真的把他移动到队尾，他只是一个给强者刷等级的小喽啰）
2. 若是每人都比过一次还无k连胜胜者，则其中的最强之人将会霸榜，每人能将他拿下（因此不论k多大，最终k连胜者一定是他）

所以解题思路来了：

1. 使用$winner$记录遍历过程中最强者下标，使用$challenger$记录当前被遍历到的人的下标，使用$cnt$记录$winner$的连胜场数。
2. 遍历过程中，若$skills[winner]\gt skills[challenger]$则连胜累积（$cnt+=1$）；否则江山易主（令$winner$为$challenger$并将连胜局数重置为$1$）
3. 结束条件：出现k连胜者或者遍历结束。结束后返回$winner$。

时空复杂度：

+ 时间复杂度$O(len(skills))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int winner = 0;
        for (int challenger = 1, cnt = 0; challenger < skills.size() && cnt < k; challenger++) {
            if (skills[winner] > skills[challenger]) {
                cnt++;
            } else {
                winner = challenger;
                cnt = 1;
            }
        }
        return winner;
    }
};
```

#### Go

```go
package main

func findWinningPlayer(skills []int, k int) int {
    winner := 0
    for challenger, cnt := 1, 0; challenger < len(skills) && cnt < k; challenger++ {
        if skills[winner] > skills[challenger] {
            cnt++;
        } else {
            winner = challenger
            cnt = 1
        }
    }
    return winner
}
```

#### Java

```java
class Solution {
    public int findWinningPlayer(int[] skills, int k) {
        int winner = 0;
        for (int challenger = 1, cnt = 0; challenger < skills.length && cnt < k; challenger++) {
            if (skills[winner] > skills[challenger]) {
                cnt++;
            } else {
                winner = challenger;
                cnt = 1;
            }
        }
        return winner;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        winner, challenger, cnt = 0, 1, 0
        while challenger < len(skills) and cnt < k:
            if skills[winner] > skills[challenger]:
                cnt += 1
            else:
                winner = challenger
                cnt = 1
            challenger += 1
        return winner
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/10/24/LeetCode%203175.%E6%89%BE%E5%88%B0%E8%BF%9E%E7%BB%AD%E8%B5%A2K%E5%9C%BA%E6%AF%94%E8%B5%9B%E7%9A%84%E7%AC%AC%E4%B8%80%E4%BD%8D%E7%8E%A9%E5%AE%B6/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143206596](https://letmefly.blog.csdn.net/article/details/143206596)
