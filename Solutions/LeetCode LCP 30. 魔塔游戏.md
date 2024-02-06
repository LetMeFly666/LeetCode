---
title: LCP 30.魔塔游戏
date: 2024-02-06 10:44:13
tags: [题解, LeetCode, 中等, 贪心, 数组, 堆（优先队列）]
---

# 【LetMeFly】LCP 30.魔塔游戏：贪心（优先队列）

力扣题目链接：[https://leetcode.cn/problems/p0NxJO/](https://leetcode.cn/problems/p0NxJO/)

小扣当前位于魔塔游戏第一层，共有 `N` 个房间，编号为 `0 ~ N-1`。每个房间的补血道具/怪物对于血量影响记于数组 `nums`，其中正数表示道具补血数值，即血量增加对应数值；负数表示怪物造成伤害值，即血量减少对应数值；`0` 表示房间对血量无影响。

**小扣初始血量为 1，且无上限**。假定小扣原计划按房间编号升序访问所有房间补血/打怪，**为保证血量始终为正值**，小扣需对房间访问顺序进行调整，**每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾**。请返回小扣最少需要调整几次，才能顺利访问所有房间。若调整顺序也无法访问完全部房间，请返回 -1。


**示例 1：**
>输入：`nums = [100,100,100,-250,-60,-140,-50,-50,100,150]`
>
>输出：`1`
>
>解释：初始血量为 1。至少需要将 nums[3] 调整至访问顺序末尾以满足要求。

**示例 2：**
>输入：`nums = [-200,-300,400,0]`
>
>输出：`-1`
>
>解释：调整访问顺序也无法完成全部房间的访问。

**提示：**
- `1 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`

## 方法一：贪心（优先队列）

使用一个优先队列```pq```记录所有的负数房间（绝对值越大的负数房间越优先出栈），从前到后遍历所有房间，并将房间的值累加到自己的血量上（若房间值为负记得加入优先队列）。

一旦遇到自己的血量不为正数的情况，就**开始反悔**：将队列中绝对值最大的负数房间调整到队尾（血量恢复这个房间的绝对值的量，并记录一共有多少房间移动到了队列尾）。

一旦出现血量非正且队列为空的情况，立刻返回```-1```。若遍历结束，看血量是否大于移动到队尾的所有房间绝对值之和。

+ 时间复杂度$O(len(nums))$
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
class Solution {
public:
    int magicTower(vector<int>& nums) {
        priority_queue<int> pq;
        long long now = 1;
        long long totalNegative = 0;
        int ans = 0;
        for (int t : nums) {
            if (t < 0) {
                pq.push(-t);
            }
            now += t;
            while (now <= 0 && pq.size()) {
                int thisNegative = pq.top();
                pq.pop();
                now += thisNegative;
                totalNegative += thisNegative;
                ans++;
            }
            if (now <= 0) {
                return -1;
            }
        }
        return now > totalNegative ? ans : -1;
    }
};
```

#### Python

```python
# from typing import List
# import heapq

class Solution:
    def magicTower(self, nums: List[int]) -> int:
        pq = []
        now = 1
        totalNegative = 0
        ans = 0
        for t in nums:
            if t < 0:
                heapq.heappush(pq, t)
            now += t
            while now <= 0 and pq:
                thisNegative = -heapq.heappop(pq)
                totalNegative += thisNegative
                now += thisNegative
                ans += 1
            if now <= 0:
                return -1
        return ans if now > totalNegative else -1

```

> 同步发文于CSDN，原创不易，转载经作者同意后请附上[原文链接](https://blog.tisfy.eu.org/2024/02/06/LeetCode%20LCP%2030.%20%E9%AD%94%E5%A1%94%E6%B8%B8%E6%88%8F/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136053198](https://letmefly.blog.csdn.net/article/details/136053198)
