---
title: 2798.满足目标工作时长的员工数目
date: 2024-04-30 17:21:58
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟, 计数]
---

# 【LetMeFly】2798.满足目标工作时长的员工数目：Do_What_It_Let

力扣题目链接：[https://leetcode.cn/problems/number-of-employees-who-met-the-target/](https://leetcode.cn/problems/number-of-employees-who-met-the-target/)

<p>公司里共有 <code>n</code> 名员工，按从 <code>0</code> 到 <code>n - 1</code> 编号。每个员工 <code>i</code> 已经在公司工作了 <code>hours[i]</code> 小时。</p>

<p>公司要求每位员工工作&nbsp;<strong>至少</strong> <code>target</code> 小时。</p>

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的非负整数数组 <code>hours</code> 和一个非负整数 <code>target</code> 。</p>

<p>请你用整数表示并返回工作至少 <code>target</code> 小时的员工数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>hours = [0,1,2,3,4], target = 2
<strong>输出：</strong>3
<strong>解释：</strong>公司要求每位员工工作至少 2 小时。
- 员工 0 工作 0 小时，不满足要求。
- 员工 1 工作 1 小时，不满足要求。
- 员工 2 工作 2 小时，满足要求。
- 员工 3 工作 3 小时，满足要求。
- 员工 4 工作 4 小时，满足要求。
共有 3 位满足要求的员工。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>hours = [5,1,4,2,2], target = 6
<strong>输出：</strong>0
<strong>解释：</strong>公司要求每位员工工作至少 6 小时。
共有 0 位满足要求的员工。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == hours.length &lt;= 50</code></li>
	<li><code>0 &lt;=&nbsp;hours[i], target &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 解题方法：遍历

遍历数组中的所有元素，统计$\geq target$的元素的个数。

+ 时间复杂度$O(len(hours))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (int t : hours) {
            ans += t >= target;
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours: List[int], target: int) -> int:
        return sum(t >= target for t in hours)
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/30/LeetCode%202798.%E6%BB%A1%E8%B6%B3%E7%9B%AE%E6%A0%87%E5%B7%A5%E4%BD%9C%E6%97%B6%E9%95%BF%E7%9A%84%E5%91%98%E5%B7%A5%E6%95%B0%E7%9B%AE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138352241](https://letmefly.blog.csdn.net/article/details/138352241)
