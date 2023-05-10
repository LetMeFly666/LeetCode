---
title: 55.跳跃游戏
date: 2022-05-28 18:28:43
tags: [题解, LeetCode, 中等, 数组, 贪心, 跳跃到终点, 模拟]
---

# 【LetMeFly】55.跳跃游戏

力扣题目链接：[https://leetcode.cn/problems/jump-game/](https://leetcode.cn/problems/jump-game/)

给定一个非负整数数组 ```nums``` ，你最初位于数组的 **第一个下标** 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

**示例 1:**

```
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```

**示例 2:**

```
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
```

**提示:**

+ $1\leq nums.length\leq 3 \times 10^4$
+ $0 \leq nums[i] \leq 10^5$

# 思路

这题想明白之后还实现起来并不难。每次都更新能到达的最远位置，看是否能到达终点即可。

## 方法一：贪心

我们可以用变量$farthest$记录下当前能跳跃到的最远位置。

以例一```[2,3,1,1,4]```为例，初始时我们处于下标$0$的位置，因此$farthest=0$。

之后从左向右遍历数组：

遍历到第$0$个数时，最远跳到下标$0+2=2$的位置，因此更新$farthest$为$2$。

遍历到第$1$个数时，最远跳到下标$1+3=4$的位置，因此更新$farthest$为$4$。

...

在遍历过程中，如果遇到```当前下标```大于```当前最远能到达位置```$farthest$，就返回```false```。

遍历结束后，如果$farthest \geq 最后一个位置$，就返回```true```，否则返回```false```

+ 时间复杂度$O(n!)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;  // 当前最远可达距离
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) {  // 到不了这一点
                return false;
            }
            farthest = max(farthest, i + nums[i]);
        }
        return farthest >= nums.size() - 1;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/05/28/LeetCode%200055.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125021531](https://letmefly.blog.csdn.net/article/details/125021531)
