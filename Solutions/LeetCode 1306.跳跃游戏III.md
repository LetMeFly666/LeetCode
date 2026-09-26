---
title: 1306.跳跃游戏 III：深度优先搜索(DFS)
date: 2026-05-17 11:37:48
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 数组]
categories: [题解, LeetCode]
---

# 【LetMeFly】1306.跳跃游戏 III：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/jump-game-iii/](https://leetcode.cn/problems/jump-game-iii/)

<p>这里有一个非负整数数组&nbsp;<code>arr</code>，你最开始位于该数组的起始下标&nbsp;<code>start</code>&nbsp;处。当你位于下标&nbsp;<code>i</code>&nbsp;处时，你可以跳到&nbsp;<code>i + arr[i]</code> 或者 <code>i - arr[i]</code>。</p>

<p>请你判断自己是否能够跳到对应元素值为 0 的 <strong>任一</strong> 下标处。</p>

<p>注意，不管是什么情况下，你都无法跳到数组之外。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,3,0,3,1,2], start = 5
<strong>输出：</strong>true
<strong>解释：</strong>
到达值为 0 的下标 3 有以下可能方案： 
下标 5 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3 
下标 5 -&gt; 下标 6 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3 
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [4,2,3,0,3,1,2], start = 0
<strong>输出：</strong>true 
<strong>解释：
</strong>到达值为 0 的下标 3 有以下可能方案： 
下标 0 -&gt; 下标 4 -&gt; 下标 1 -&gt; 下标 3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [3,0,2,1,2], start = 2
<strong>输出：</strong>false
<strong>解释：</strong>无法到达值为 0 的下标 1 处。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10^4</code></li>
	<li><code>0 &lt;= arr[i] &lt;&nbsp;arr.length</code></li>
	<li><code>0 &lt;= start &lt; arr.length</code></li>
</ul>


    
## 解题方法：深度优先搜索

使用一个布尔类型的数组记录每个下标是否被搜索过，写一个`dfs(start)`函数返回从下标`start`能否到达一个值为$0$的下标。

dfs函数写法：

> 若`start`被访问过，说明从`start`无法到达值为$0$的下标，直接返回`false`；否则将`start`标记为被访问过并继续：
> 
> + 如果`start - arr[start] ≥ 0`并且`dfs(start - arr[start])`为`true`，则说明`start`可以通过下标`start - arr[start]`到达值为$0$的下标，返回`true`；
> + 如果`start + arr[start] < n`并且`dfs(start + arr[start])`为`true`，则说明`start`可以通过下标`start + arr[start]`到达值为$0$的下标，返回`true`。
> 
> 若两个路径都不可达，则返回`false`。

+ 时间复杂度$O(len(arr))$，每个下标只会被递归至多一次。
+ 空间复杂度$O(len(arr))$

### AC代码


#### Python

```python
'''
LastEditTime: 2026-05-17 10:46:40
'''
from typing import List

class Solution:
    def dfs(self, start: int) -> bool:
        if self.visited[start]:
            return False
        self.visited[start] = True
        if not self.arr[start]:
            return True
        if start - self.arr[start] >= 0 and self.dfs(start - self.arr[start]):
            return True
        if start + self.arr[start] < len(self.arr) and self.dfs(start + self.arr[start]):
            return True
        return False
    
    def canReach(self, arr: List[int], start: int) -> bool:
        self.arr = arr
        self.visited = [False] * len(arr)
        return self.dfs(start)
```

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-17 10:40:03
 */
class Solution {
private:
    vector<bool> visited;

    bool dfs(vector<int>& arr, int start) {
        if (visited[start]) {
            return false;
        }
        if (!arr[start]) {
            return true;
        }
        visited[start] = true;
        if (start - arr[start] >= 0 && dfs(arr, start - arr[start])) {
            return true;
        }
        if (start + arr[start] < arr.size() && dfs(arr, start + arr[start])) {
            return true;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size());
        return dfs(arr, start);
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161161656)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/17/LeetCode%201306.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8FIII/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
