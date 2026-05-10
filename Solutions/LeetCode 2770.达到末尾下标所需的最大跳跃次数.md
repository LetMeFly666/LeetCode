---
title: 2770.达到末尾下标所需的最大跳跃次数：深度优先搜索(DFS)
date: 2026-05-10 19:55:22
tags: [题解, LeetCode, 中等, 数组, 动态规划, 深度优先搜索, DFS, 记忆化搜索]
categories: [题解, LeetCode]
---

# 【LetMeFly】2770.达到末尾下标所需的最大跳跃次数：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index/](https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index/)

<p>给你一个下标从 <strong>0</strong> 开始、由 <code>n</code> 个整数组成的数组 <code>nums</code> 和一个整数 <code>target</code> 。</p>

<p>你的初始位置在下标 <code>0</code> 。在一步操作中，你可以从下标 <code>i</code> 跳跃到任意满足下述条件的下标 <code>j</code> ：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; n</code></li>
	<li><code>-target &lt;= nums[j] - nums[i] &lt;= target</code></li>
</ul>

<p>返回到达下标 <code>n - 1</code> 处所需的 <strong>最大跳跃次数</strong> 。</p>

<p>如果无法到达下标 <code>n - 1</code> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,6,4,1,2], target = 2
<strong>输出：</strong>3
<strong>解释：</strong>要想以最大跳跃次数从下标 0 到下标 n - 1 ，可以按下述跳跃序列执行操作：
- 从下标 0 跳跃到下标 1 。 
- 从下标 1 跳跃到下标 3 。 
- 从下标 3 跳跃到下标 5 。 
可以证明，从 0 到 n - 1 的所有方案中，不存在比 3 步更长的跳跃序列。因此，答案是 3 。 </pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,6,4,1,2], target = 3
<strong>输出：</strong>5
<strong>解释：</strong>要想以最大跳跃次数从下标 0 到下标 n - 1 ，可以按下述跳跃序列执行操作：
- 从下标 0 跳跃到下标 1 。 
- 从下标 1 跳跃到下标 2 。 
- 从下标 2 跳跃到下标 3 。 
- 从下标 3 跳跃到下标 4 。 
- 从下标 4 跳跃到下标 5 。 
可以证明，从 0 到 n - 1 的所有方案中，不存在比 5 步更长的跳跃序列。因此，答案是 5 。 </pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,6,4,1,2], target = 0
<strong>输出：</strong>-1
<strong>解释：</strong>可以证明不存在从 0 到 n - 1 的跳跃序列。因此，答案是 -1 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length == n &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= target &lt;= 2 * 10<sup>9</sup></code></li>
</ul>


    
## 解题方法：深度优先搜索

写一个函数`dfs(loc)`返回从下标$loc$到下标$0$的最大跳跃次数（负数代表不可达），则`dfs(n - 1)`即为所求。

这个函数怎么实现呢？

+ 如果`loc == 0`则说明达到了下标$0$，返回$0$；
+ 否则，返回$\max dfs(i)+1$，其中$0\leq i\lt loc$并且$|nums[i]-nums[loc]|\leq target$。

记得使用记忆化避免大量的重复计算。

+ 时间复杂度$O(n^2)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-10 19:53:35
 */
class Solution {
private:
    int n, target;
    vector<int> nums, mem;

    int dfs(int loc) {
        if (loc == 0) {
            return 0;
        }
        int& ans = mem[loc];  // 引用
        if (ans) {
            return ans;
        }

        ans = INT_MIN;
        for (int i = 0; i < loc; i++) {
            if (abs(nums[loc] - nums[i]) <= target) {
                ans = max(ans, dfs(i) + 1);
            }
        }
        return ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        this->nums = move(nums);
        this->target = target;
        mem.assign(n, 0);
        int ans = dfs(n - 1);
        return ans < 0 ? -1 : ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160959826)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/10/LeetCode%202770.%E8%BE%BE%E5%88%B0%E6%9C%AB%E5%B0%BE%E4%B8%8B%E6%A0%87%E6%89%80%E9%9C%80%E7%9A%84%E6%9C%80%E5%A4%A7%E8%B7%B3%E8%B7%83%E6%AC%A1%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
