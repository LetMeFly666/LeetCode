---
title: 699.掉落的方块
date: 2022-05-26 09:10:06
tags: [题解, LeetCode, 困难, 暴力, 有序集合]
categories: [题解, LeetCode]
---

# 【LetMeFly】两种方法解决 699.掉落的方块

力扣题目链接：[https://leetcode.cn/problems/falling-squares/](https://leetcode.cn/problems/falling-squares/)

在无限长的数轴（即```x```轴）上，我们根据给定的顺序放置对应的正方形方块。

第```i```个掉落的方块（```positions[i] = (left, side_length```)）是正方形，其中 ```left 表示该方块最左边的点位置(positions[i][0])，side_length 表示该方块的边长(positions[i][1])。```

每个方块的底部边缘平行于数轴（即 x 轴），并且从一个比目前所有的落地方块更高的高度掉落而下。在上一个方块结束掉落，并保持静止后，才开始掉落新方块。

方块的底边具有非常大的粘性，并将保持固定在它们所接触的任何长度表面上（无论是数轴还是其他方块）。邻接掉落的边不会过早地粘合在一起，```因为只有底边才具有粘性```。

返回一个堆叠高度列表```ans```。每一个堆叠高度```ans[i]```表示在通过```positions[0], positions[1], ..., positions[i]```表示的方块掉落结束后，目前所有已经落稳的方块堆叠的最高高度。


**示例 1:**

```
输入: [[1, 2], [2, 3], [6, 1]]
输出: [2, 5, 5]
解释:

第一个方块 positions[0] = [1, 2] 掉落：
_aa
_aa
-------
方块最大高度为 2 。

第二个方块 positions[1] = [2, 3] 掉落：
__aaa
__aaa
__aaa
_aa__
_aa__
--------------
方块最大高度为5。
大的方块保持在较小的方块的顶部，不论它的重心在哪里，因为方块的底部边缘有非常大的粘性。

第三个方块 positions[1] = [6, 1] 掉落：
__aaa
__aaa
__aaa
_aa
_aa___a
-------------- 
方块最大高度为5。

因此，我们返回结果[2, 5, 5]。
```

**示例 2:**

```
输入: [[100, 100], [200, 100]]
输出: [100, 100]
解释: 相邻的方块不会过早地卡住，只有它们的底部边缘才能粘在表面上。
```

**提示:**

+ $1\leq positions.length\leq 1000$
+ $1\leq positions[i][0]\leq10^8$
+ $1\leq positions[i][1]\leq10^6$

# 思路

主要思路就是判断每个方块下落地的最大已有高度并更新记录之。

## 方法一：暴力枚举

这题中方块数量的上限是$1000$，因此可以在$O(n^2)$的复杂度内通过该题。

我们可以自定义一种数据结构```Line```：

```cpp
struct Line {
    int l, r;  // max{l} = max{positions[i][0]} ≤ 1e8 < INT_MAX；max{l} = max{l} + max{length} = max{positions[i][0]} + max{positions[i][1]} ≤ 1.01e8 < INT_MAX 
    int height;  // max{height} ≤ sum{length} ≤ max{positions.length} * max{positions[i][1]} ≤ 1e9 < INT_MAX
};
```

代表 ```[l, r]```的最大高度都是```height```。

这样我们就可以依次模拟每个方块的下落，对于每个方块，遍历所有的Line，如果这个Line和这个方块有交集，就更新这个方块的最大高度。



+ 时间复杂度$O(n^2)$，其中$n$是方块的个数
+ 空间复杂度$O(1)$，返回值不计入空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<Line> lines;
        vector<int> ans;  // 答案
        int Max = 0;  // 最大高度
        for (auto& thisSquare : positions) {
            int l = thisSquare[0], r = thisSquare[0] + thisSquare[1] - 1;  // 这个方块的水平投影的范围是[l, r]
            int thisMaxHeight = thisSquare[1];  // 这个方块的最大高度
            for (Line& thisLine : lines) {  // 遍历每一条Line
                if (!(thisLine.r < l || thisLine.l > r)) {  // 如果这条Line和方块水平投影有交集
                    thisMaxHeight = max(thisMaxHeight, thisLine.height + thisSquare[1]);  // 更新这条线的最大高度
                }
            }
            lines.push_back(Line(l, r, thisMaxHeight));  // 更新插入这条Line（这里不用erase之前被覆盖掉的Line，因为方块只会越摞越高）
            Max = max(Max, thisMaxHeight);
            ans.push_back(Max);
        }
        return ans;
    }
};
```

## 方法二：有序集合

如果n的范围再增大一些呢？有没有一种时间复杂度为$O(n\log n)$的方法呢

我们来分析以下时间主要消耗在哪里。主要就是对Line的遍历。每下落一个方块都要对所有的Line进行一次遍历。

那么，如果我们维护一个有序的lines的话，是不是就可以了呢？

也就是说，查询已有的重叠的Line的时候，我们可以使用二分法在$O(\log n)$的时间复杂度内查找；在插入新Line的时候，我们可以用$O(\log n)$的时间复杂度插入到对应位置。同时记得还需要删除被覆盖的Line。

其实，我们可以采用方法一的思想，但是使用一个新的数据结构：```map<int, int>```。不同编程语言具体实现方式可能不同，这里就以C++为例：

> 定义一个```map<int, int>```类型的```heightMap```，```heightMap[x1]```代表从x1开始，知道遇到下一个x2之前，所有的位置高度都是heightMap[x1]。（ [X1, x2) ）

在下落一个新的方块时，假设方块范围是[l, r]，那么我们要先求得有序集合中[l, r]的最大高度，加上方块边长就是[l, r]的新的高度。

求得新的高度后，删除[l, r]中的原始高度，插入[l, r]的新的高度即可。

+ 时间复杂度$O(n\log n)$，其中$n$是方块的个数
+ 空间复杂度$O(1n)$，返回值不计入空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<Line> lines;
        vector<int> ans;  // 答案
        int Max = 0;
        for (auto& thisSquare : positions) {
            int l = thisSquare[0], r = thisSquare[0] + thisSquare[1] - 1;  // 这个方块的水平投影的范围是[l, r]
            int thisMaxHeight = thisSquare[1];  // 这个方块的最大高度
            for (Line& thisLine : lines) {  // 遍历每一条Line
                if (!(thisLine.r < l || thisLine.l > r)) {  // 如果这条Line和方块水平投影有交集
                    thisMaxHeight = max(thisMaxHeight, thisLine.height + thisSquare[1]);  // 更新这条线的最大高度
                }
            }
            lines.push_back(Line(l, r, thisMaxHeight));  // 更新插入这条Line（这里不用erase之前被覆盖掉的Line，因为方块只会越摞越高）
            Max = max(Max, thisMaxHeight);
            ans.push_back(Max);
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/05/26/LeetCode%200699.%E6%8E%89%E8%90%BD%E7%9A%84%E6%96%B9%E5%9D%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/124978728](https://letmefly.blog.csdn.net/article/details/124978728)
