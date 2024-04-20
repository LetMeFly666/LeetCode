---
title: 39.组合总和
date: 2024-04-20 11:06:37
tags: [题解, LeetCode, 中等, 数组, 回溯]
---

# 【LetMeFly】39.组合总和：回溯 + 剪枝

力扣题目链接：[https://leetcode.cn/problems/combination-sum/](https://leetcode.cn/problems/combination-sum/)

<p>给你一个 <strong>无重复元素</strong> 的整数数组&nbsp;<code>candidates</code> 和一个目标整数&nbsp;<code>target</code>&nbsp;，找出&nbsp;<code>candidates</code>&nbsp;中可以使数字和为目标数&nbsp;<code>target</code> 的 所有<em>&nbsp;</em><strong>不同组合</strong> ，并以列表形式返回。你可以按 <strong>任意顺序</strong> 返回这些组合。</p>

<p><code>candidates</code> 中的 <strong>同一个</strong> 数字可以 <strong>无限制重复被选取</strong> 。如果至少一个数字的被选数量不同，则两种组合是不同的。&nbsp;</p>

<p>对于给定的输入，保证和为&nbsp;<code>target</code> 的不同组合数少于 <code>150</code> 个。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>candidates = <code>[2,3,6,7], </code>target = <code>7</code>
<strong>输出：</strong>[[2,2,3],[7]]
<strong>解释：</strong>
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入: </strong>candidates = [2,3,5]<code>, </code>target = 8
<strong>输出: </strong>[[2,2,2,2],[2,3,3],[3,5]]</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入: </strong>candidates = <code>[2], </code>target = 1
<strong>输出: </strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= candidates.length &lt;= 30</code></li>
	<li><code>2 &lt;= candidates[i] &lt;= 40</code></li>
	<li><code>candidates</code> 的所有元素 <strong>互不相同</strong></li>
	<li><code>1 &lt;= target &lt;= 40</code></li>
</ul>


    
## 解题方法：回溯 + 剪枝

写一个函数```dfs(target, index)```，用来处理距离目标还剩target，处理过候选数组的```[0, index)```的情况。

为了实现这个函数，我们还需要两个“全局”变量（或者通过参数传递）：```ans```用来存放所有可行的情况（答案）、```now```用来存放当前已选元素。

函数```dfs```终止条件：

+ target为0：```now```为一种可选方案，```now```加入```ans```数组并终止递归
+ index超出候选数组的下标范围：递归终止

函数```dfs```要做的事：

1. 在已选方案```now```的基础上，**不选**当前元素```candidates[index]```：递归```dfs(target, index + 1)```
2. 在已选方案```now```的基础上，**选择**当前元素```candidates[index]```：将```candidates[index]```加入```now```数组，递归```dfs(target - candidates[index], index)```，（回溯）将```candidates[index]```从```now```数组中剔除

剪枝方案：```target - candidates[index] >= 0```时再递归回溯。

+ 时间复杂度$O(Size(ans))$
+ 空间复杂度$O(target)$：空间复杂度为递归深度，最坏情况下全是```1```要递归```target```次

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    void dfs(vector<int>& candidates, int target, int index) {
        if (!target) {
            ans.push_back(now);
            return;
        }
        if (index == candidates.size()) {
            return;
        }
        // not choose
        dfs(candidates, target, index + 1);
        // choose
        if (target - candidates[index] >= 0) {
            now.push_back(candidates[index]);
            dfs(candidates, target - candidates[index], index);  // 这里不能是index + 1，因为可以重复选择
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def dfs(self, target: int, index: int) -> None:
        if not target:
            self.ans.append(self.now[:])
            return
        if index == len(self.candidates):
            return
        # not choose
        self.dfs(target, index + 1)
        # choose
        if target >= self.candidates[index]:
            self.now.append(self.candidates[index])
            self.dfs(target - self.candidates[index], index)
            self.now.pop()        

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans = []
        self.now = []
        self.candidates = candidates
        self.dfs(target, 0)
        return self.ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/20/LeetCode%200039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137994260](https://letmefly.blog.csdn.net/article/details/137994260)
