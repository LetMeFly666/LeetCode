---
title: 486.预测赢家：深度优先搜索(DFS)
date: 2026-08-01 19:01:14
tags: [题解, LeetCode, 中等, 递归, 数组, 数学, 动态规划, 博弈, 深度优先搜索, DFS]
categories: [题解, LeetCode]
---

# 【LetMeFly】486.预测赢家：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/predict-the-winner/](https://leetcode.cn/problems/predict-the-winner/)

<p>给你一个整数数组 <code>nums</code> 。玩家 1 和玩家 2 基于这个数组设计了一个游戏。</p>

<p>玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手。开始时，两个玩家的初始分值都是 <code>0</code> 。每一回合，玩家从数组的任意一端取一个数字（即，<code>nums[0]</code> 或 <code>nums[nums.length - 1]</code>），取到的数字将会从数组中移除（数组长度减 <code>1</code> ）。玩家选中的数字将会加到他的得分上。当数组中没有剩余数字可取时，游戏结束。</p>

<p>如果玩家 1 能成为赢家，返回 <code>true</code> 。如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 <code>true</code> 。你可以假设每个玩家的玩法都会使他的分数最大化。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,2]
<strong>输出：</strong>false
<strong>解释：</strong>一开始，玩家 1 可以从 1 和 2 中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。 
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 false 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,233,7]
<strong>输出：</strong>true
<strong>解释：</strong>玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 true，表示玩家 1 可以成为赢家。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>


    
## 解题方法：深度优先搜索

写一个函数`play`，计算当前可选范围是`nums[l]`到`nums[r]`时的最大得分。

+ 计算规则：选`l`和选`r`得分中最大的一个
+ 终止条件：nums中仅剩下一个元素

返回初始状态下`play`结果是否$\geq 0$

+ 时间复杂度$O(len(nums)^2)$，可以看参数$l$和$r$最多有$n^2$种组合。
+ 空间复杂度$O(len(nums))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-01 19:00:00
 */
class Solution {
private:
    int play(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        return max(nums[l] - play(nums, l + 1, r), nums[r] - play(nums, l, r - 1));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return play(nums, 0, nums.size() - 1) >= 0;
    }
};
```

#### C++ —— 别看，双端队列版本

```cpp
/*
 * @LastEditTime: 2026-08-01 18:54:52
 */
class Solution {
private:
    int play(deque<int>& q) {
        if (q.empty()) {
            return 0;
        }

        int first = q.front();
        q.pop_front();
        int score1 = first - play(q);
        q.push_front(first);

        int last = q.back();
        q.pop_back();
        int score2 = last - play(q);
        q.push_back(last);

        return max(score1, score2);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        deque<int> q;
        for (int t : nums) {
            q.push_back(t);
        }
        return play(q) >= 0;
    }
};

#ifdef _DEBUG
/*
[1,567,1,1,99,100]

true
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.predictTheWinner(v) << endl;
    }
    return 0;
}
#endif
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163397063)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/01/LeetCode%200486.%E9%A2%84%E6%B5%8B%E8%B5%A2%E5%AE%B6/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
