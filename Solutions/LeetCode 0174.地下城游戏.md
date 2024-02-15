---
title: 174.地下城游戏
date: 2022-08-06 09:38:31
tags: [题解, LeetCode, 困难, 数组, 动态规划, 矩阵, dp]
---

# 【LetMeFly】174.地下城游戏：原数组上修改

力扣题目链接：[https://leetcode.cn/problems/dungeon-game/](https://leetcode.cn/problems/dungeon-game/)

<style>

table.dungeon, .dungeon th, .dungeon td {

  border:3px solid black;

}



 .dungeon th, .dungeon td {

    text-align: center;

    height: 70px;

    width: 70px;

}

</style>



<p>一些恶魔抓住了公主（<strong>P</strong>）并将她关在了地下城的右下角。地下城是由&nbsp;M x N 个房间组成的二维网格。我们英勇的骑士（<strong>K</strong>）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。</p>



<p>骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。</p>



<p>有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为<em>负整数</em>，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 <em>0</em>），要么包含增加骑士健康点数的魔法球（若房间里的值为<em>正整数</em>，则表示骑士将增加健康点数）。</p>



<p>为了尽快到达公主，骑士决定每次只向右或向下移动一步。</p>



<p>&nbsp;</p>



<p><strong>编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。</strong></p>



<p>例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 <code>右 -&gt; 右 -&gt; 下 -&gt; 下</code>，则骑士的初始健康点数至少为 <strong>7</strong>。</p>



<table class="dungeon">
<tr> 
<td>-2 (K)</td> 
<td>-3</td> 
<td>3</td> 
</tr> 
<tr> 
<td>-5</td> 
<td>-10</td> 
<td>1</td> 
</tr> 
<tr> 
<td>10</td> 
<td>30</td> 
<td>-5 (P)</td> 
</tr> 
</table>

<!---2K   -3  3

-5   -10   1

10 30   5P-->



<p>&nbsp;</p>



<p><strong>说明:</strong></p>



<ul>

	<li>

	<p>骑士的健康点数没有上限。</p>

	</li>

	<li>任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。</li>

</ul>

    
## 方法一：原数组上dp

这道题需要从右下向左上进行dp。因为从左上方向右下方dp的话，“路径和最大”不一定“所需初始值最小”（可能路上有$-10000$和$20000$，虽然路径和最大，但是经过$-10000$的时候至少需要$10001$的血）

从右下方向左上方dp，$dp[i][j]$表示从$(i, j)$到终点所需最小初始血量。

那么，$dp[0][0]$即为从起点到终点所需最小初始血量，即为答案。

从$dp[i][j]$可以到达$dp[i + 1][j]$或$dp[i][j + 1]$，具体要到哪个呢？当然是要到两个中最小的那个（$\min \{dp[i + 1][j], dp[i][j + 1]\}$）。

同时，$dp[i][j]$这一点经过“掉血”或“回血”后至少还有$1$滴血，因此$dp[i][j] = \max\{1, \min \{dp[i + 1][j], dp[i][j + 1]\} - dungeon[i][j]\}$

初始值$dp[n - 1][m - 1]=\max\{1, 1 - dungeon[n - 1][m - 1]\}$

如果原始地图数组允许修改，那么我们可以直接在原始数组上dp，这样空间复杂度就降为了1。

+ 时间复杂度$O(n\times m)$，其中地图大小为$n\times m$
+ 空间复杂度$O(1)$。如果原始地图数组不允许修改，那么我们就需要额外开辟一个dp空间，空间复杂度就变成了$O(\times m)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        dungeon[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i + 1 < n && j + 1 < m) {
                    dungeon[i][j] = max(1, min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j]);
                }
                else if (i + 1 < n) {
                    dungeon[i][j] = max(1, dungeon[i + 1][j] - dungeon[i][j]);
                }
                else if (j + 1 < m) {
                    dungeon[i][j] = max(1, dungeon[i][j + 1] - dungeon[i][j]);
                }
            }
        }
        return dungeon[0][0];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/06/LeetCode%200174.%E5%9C%B0%E4%B8%8B%E5%9F%8E%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126190011](https://letmefly.blog.csdn.net/article/details/126190011)
