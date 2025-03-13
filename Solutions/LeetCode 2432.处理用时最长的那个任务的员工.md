---
title: 2432.处理用时最长的那个任务的员工
date: 2023-05-05 20:08:29
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟]
categories: [题解, LeetCode]
---

# 【LetMeFly】2432.处理用时最长的那个任务的员工

力扣题目链接：[https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task/](https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task/)

<p>共有 <code>n</code> 位员工，每位员工都有一个从 <code>0</code> 到 <code>n - 1</code> 的唯一 id 。</p>

<p>给你一个二维整数数组 <code>logs</code> ，其中 <code>logs[i] = [id<sub>i</sub>, leaveTime<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>id<sub>i</sub></code> 是处理第 <code>i</code> 个任务的员工的 id ，且</li>
	<li><code>leaveTime<sub>i</sub></code> 是员工完成第 <code>i</code> 个任务的时刻。所有 <code>leaveTime<sub>i</sub></code> 的值都是 <strong>唯一</strong> 的。</li>
</ul>

<p>注意，第 <code>i</code> 个任务在第 <code>(i - 1)</code> 个任务结束后立即开始，且第 <code>0</code> 个任务从时刻 <code>0</code> 开始。</p>

<p>返回处理用时最长的那个任务的员工的 id 。如果存在两个或多个员工同时满足，则返回几人中 <strong>最小</strong> 的 id 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, logs = [[0,3],[2,5],[0,9],[1,15]]
<strong>输出：</strong>1
<strong>解释：</strong>
任务 0 于时刻 0 开始，且在时刻 3 结束，共计 3 个单位时间。
任务 1 于时刻 3 开始，且在时刻 5 结束，共计 2 个单位时间。
任务 2 于时刻 5 开始，且在时刻 9 结束，共计 4 个单位时间。
任务 3 于时刻 9 开始，且在时刻 15 结束，共计 6 个单位时间。
时间最长的任务是任务 3 ，而 id 为 1 的员工是处理此任务的员工，所以返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 26, logs = [[1,1],[3,7],[2,12],[7,17]]
<strong>输出：</strong>3
<strong>解释：</strong>
任务 0 于时刻 0 开始，且在时刻 1 结束，共计 1 个单位时间。
任务 1 于时刻 1 开始，且在时刻 7 结束，共计 6 个单位时间。
任务 2 于时刻 7 开始，且在时刻 12 结束，共计 5 个单位时间。
任务 3 于时刻 12 开始，且在时刻 17 结束，共计 5 个单位时间。
时间最长的任务是任务 1 ，而 id 为 3 的员工是处理此任务的员工，所以返回 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 2, logs = [[0,10],[1,20]]
<strong>输出：</strong>0
<strong>解释：</strong>
任务 0 于时刻 0 开始，且在时刻 10 结束，共计 10 个单位时间。
任务 1 于时刻 10 开始，且在时刻 20 结束，共计 10 个单位时间。
时间最长的任务是任务 0 和 1 ，处理这两个任务的员工的 id 分别是 0 和 1 ，所以返回最小的 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= logs.length &lt;= 500</code></li>
	<li><code>logs[i].length == 2</code></li>
	<li><code>0 &lt;= id<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>1 &lt;= leaveTime<sub>i</sub> &lt;= 500</code></li>
	<li><code>id<sub>i</sub> != id<sub>i + 1</sub></code></li>
	<li><code>leaveTime<sub>i</sub></code> 按严格递增顺序排列</li>
</ul>


    
## 方法一：遍历

我们需要三个变量：

+ ans记录答案
+ M记录当前所有员工的最大处理用时
+ lastTime记录上次任务从合适结束

接下来我们只需要遍历logs数组，对于某一条log，$log[1] - lastTime$即为这个员工的工作时间

+ 如果它大于$M$，则更新M的值，以及答案ans的值
+ 如果它等于$M$，则更新答案ans的值为$\min(ans, log[0])$

然后将$lastTime$赋值为$log[1]$并继续遍历

遍历结束后返回ans即为答案

+ 时间复杂度$O(len(logs))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = 0, M = -1, lastTime = 0;
        for (auto& log : logs) {
            if (log[1] - lastTime > M) {
                M = log[1] - lastTime;
                ans = log[0];
            }
            else if (log[1] - lastTime == M) {
                ans = min(ans, log[0]);
            }
            lastTime = log[1];
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        ans, M, lastTime = 0, -1, 0
        for log in logs:
            if log[1] - lastTime > M:
                M = log[1] - lastTime
                ans = log[0]
            elif log[1] - lastTime == M:
                ans = min(ans, log[0])
            lastTime = log[1]
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2023/05/05/LeetCode%202432.%E5%A4%84%E7%90%86%E7%94%A8%E6%97%B6%E6%9C%80%E9%95%BF%E7%9A%84%E9%82%A3%E4%B8%AA%E4%BB%BB%E5%8A%A1%E7%9A%84%E5%91%98%E5%B7%A5/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130514393](https://letmefly.blog.csdn.net/article/details/130514393)
