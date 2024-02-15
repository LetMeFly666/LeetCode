---
title: LCP 50.宝石补给
date: 2023-09-14 10:11:35
tags: [题解, LeetCode, 简单, 数组, 模拟]
---

# 【LetMeFly】LCP 50.宝石补给

力扣题目链接：[https://leetcode.cn/problems/WHnhjV/](https://leetcode.cn/problems/WHnhjV/)

欢迎各位勇者来到力扣新手村，在开始试炼之前，请各位勇者先进行「宝石补给」。

每位勇者初始都拥有一些能量宝石， `gem[i]` 表示第 `i` 位勇者的宝石数量。现在这些勇者们进行了一系列的赠送，`operations[j] = [x, y]` 表示在第 `j` 次的赠送中 第 `x` 位勇者将自己一半的宝石（需向下取整）赠送给第 `y` 位勇者。

在完成所有的赠送后，请找到拥有**最多**宝石的勇者和拥有**最少**宝石的勇者，并返回他们二者的宝石数量**之差**。

**注意：**
- 赠送将按顺序逐步进行。

**示例 1：**
>输入：`gem = [3,1,2], operations = [[0,2],[2,1],[2,0]]`
>
>输出：`2`
>
>解释：
>第 1 次操作，勇者 `0` 将一半的宝石赠送给勇者 `2`， `gem = [2,1,3]`
>第 2 次操作，勇者 `2` 将一半的宝石赠送给勇者 `1`， `gem = [2,2,2]`
>第 3 次操作，勇者 `2` 将一半的宝石赠送给勇者 `0`， `gem = [3,2,1]`
>返回 3 - 1 = 2

**示例 2：**
>输入：`gem = [100,0,50,100], operations = [[0,2],[0,1],[3,0],[3,0]]`
>
>输出：`75`
>
>解释：
>第 1 次操作，勇者 `0` 将一半的宝石赠送给勇者 `2`， `gem = [50,0,100,100]`
>第 2 次操作，勇者 `0` 将一半的宝石赠送给勇者 `1`， `gem = [25,25,100,100]`
>第 3 次操作，勇者 `3` 将一半的宝石赠送给勇者 `0`， `gem = [75,25,100,50]`
>第 4 次操作，勇者 `3` 将一半的宝石赠送给勇者 `0`， `gem = [100,25,100,25]`
>返回 100 - 25 = 75

**示例 3：**
>输入：`gem = [0,0,0,0], operations = [[1,2],[3,1],[1,2]]`
>
>输出：`0`

**提示：**
- `2 <= gem.length <= 10^3`
- `0 <= gem[i] <= 10^3`
- `0 <= operations.length <= 10^4`
- `operations[i].length == 2`
- `0 <= operations[i][0], operations[i][1] < gem.length`
    
## 方法一：模拟

遍历opertaions数组，每次对于其中的一个操作$[a, b]$，将$gem[a]$的一半（向下取整）给$gem[b]$。

最终，返回gem数组的最大值和最小值之差。

+ 时间复杂度$O(len(gem) + len(operations))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& ab : operations) {
            int change = gem[ab[0]] / 2;
            gem[ab[0]] -= change;
            gem[ab[1]] += change;
        }
        int m = 1e7, M = 0;
        for (int g : gem) {
            m = min(m, g);
            M = max(M, g);
        }
        return M - m;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def giveGem(self, gem: List[int], operations: List[List[int]]) -> int:
        for a, b in operations:
            change = gem[a] // 2
            gem[a] -= change
            gem[b] += change
        return max(gem) - min(gem)
```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2023/09/15/LeetCode%20LCP%2050.%20%E5%AE%9D%E7%9F%B3%E8%A1%A5%E7%BB%99/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/132895132](https://letmefly.blog.csdn.net/article/details/132895132)
