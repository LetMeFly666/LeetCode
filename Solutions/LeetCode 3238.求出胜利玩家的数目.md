---
title: 3238.求出胜利玩家的数目
date: 2024-11-23 17:07:13
tags: [题解, LeetCode, 简单, 数组, 哈希表, 计数]
---

# 【LetMeFly】3238.求出胜利玩家的数目：哈希表计数

力扣题目链接：[https://leetcode.cn/problems/find-the-number-of-winning-players/](https://leetcode.cn/problems/find-the-number-of-winning-players/)

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，表示在一个游戏中的玩家数目。同时给你一个二维整数数组&nbsp;<code>pick</code>&nbsp;，其中&nbsp;<code>pick[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示玩家&nbsp;<code>x<sub>i</sub></code>&nbsp;获得了一个颜色为&nbsp;<code>y<sub>i</sub></code>&nbsp;的球。</p>

<p>如果玩家 <code>i</code>&nbsp;获得的球中任何一种颜色球的数目 <strong>严格大于</strong>&nbsp;<code>i</code>&nbsp;个，那么我们说玩家 <code>i</code>&nbsp;是胜利玩家。换句话说：</p>

<ul>
	<li>如果玩家 0 获得了任何的球，那么玩家 0 是胜利玩家。</li>
	<li>如果玩家 1 获得了至少 2 个相同颜色的球，那么玩家 1 是胜利玩家。</li>
	<li>...</li>
	<li>如果玩家 <code>i</code>&nbsp;获得了至少&nbsp;<code>i + 1</code>&nbsp;个相同颜色的球，那么玩家 <code>i</code>&nbsp;是胜利玩家。</li>
</ul>

<p>请你返回游戏中 <strong>胜利玩家</strong>&nbsp;的数目。</p>

<p><strong>注意</strong>，可能有多个玩家是胜利玩家。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 4, pick = [[0,0],[1,0],[1,0],[2,1],[2,1],[2,0]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>玩家 0 和玩家 1 是胜利玩家，玩家 2 和玩家 3 不是胜利玩家。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, pick = [[1,1],[1,2],[1,3],[1,4]]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>没有胜利玩家。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, pick = [[1,1],[2,4],[2,4],[2,4]]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>玩家 2 是胜利玩家，因为玩家 2 获得了 3 个颜色为 4 的球。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= pick.length &lt;= 100</code></li>
	<li><code>pick[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub> &lt;= n - 1 </code></li>
	<li><code>0 &lt;= y<sub>i</sub> &lt;= 10</code></li>
</ul>


    
## 解题方法：(哈希表)计数

使用一个哈希表（数组也可以）记录每个玩家每种颜色的球的获得个数，遍历一遍`pick`数组即可完成统计。

然后对于每个玩家，从`0`到`10`遍历每种颜色的球的数量，一旦大于玩家编号，就答案加一且快进到下一个玩家。

+ 时间复杂度$O(nC+len(pick))$，其中$C=11$代表11种颜色
+ 空间复杂度$O(nC)$，若不想创建动态数组也可以创建$NC$大小的固定数组（其中$N=\max(n)=10$）

### AC代码

#### C++

```cpp
class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int cnt[10][11] = {0};
        for (vector<int>& p : pick) {
            cnt[p[0]][p[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                if (cnt[i][j] > i) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        cnt = [[0] * 11 for _ in range(n)]
        for a, b in pick:
            cnt[a][b] += 1
        return sum(any(cnt[i][j] > i for j in range(11)) for i in range(n))
```

#### Java

```java
class Solution {
    public int winningPlayerCount(int n, int[][] pick) {
        int cnt[][] = new int[n][11];
        for (int[] p : pick) {
            cnt[p[0]][p[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 11; j++) {
                if (cnt[i][j] > i) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
}
```

#### Go

```go
package main

func winningPlayerCount(n int, pick [][]int) (ans int) {
    cnt := make([][]int, n)
    for th := range cnt {
        cnt[th] = make([]int, 11)
    }
    for _, p := range pick {
        cnt[p[0]][p[1]]++
    }
    for i, row := range cnt {
        for _, val := range row {
            if val > i {
                ans++
                break
            }
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/23/LeetCode%203238.%E6%B1%82%E5%87%BA%E8%83%9C%E5%88%A9%E7%8E%A9%E5%AE%B6%E7%9A%84%E6%95%B0%E7%9B%AE/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143995245](https://letmefly.blog.csdn.net/article/details/143995245)
