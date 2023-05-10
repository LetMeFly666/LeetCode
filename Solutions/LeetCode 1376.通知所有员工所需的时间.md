---
title: 1376.通知所有员工所需的时间
date: 2023-05-01 21:09:26
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, DFS, 哈希表, map]
---

# 【LetMeFly】1376.通知所有员工所需的时间

力扣题目链接：[https://leetcode.cn/problems/time-needed-to-inform-all-employees/](https://leetcode.cn/problems/time-needed-to-inform-all-employees/)

<p>公司里有 <code>n</code> 名员工，每个员工的 ID 都是独一无二的，编号从 <code>0</code> 到 <code>n - 1</code>。公司的总负责人通过 <code>headID</code> 进行标识。</p>

<p>在 <code>manager</code> 数组中，每个员工都有一个直属负责人，其中 <code>manager[i]</code> 是第 <code>i</code> 名员工的直属负责人。对于总负责人，<code>manager[headID] = -1</code>。题目保证从属关系可以用树结构显示。</p>

<p>公司总负责人想要向公司所有员工通告一条紧急消息。他将会首先通知他的直属下属们，然后由这些下属通知他们的下属，直到所有的员工都得知这条紧急消息。</p>

<p>第 <code>i</code> 名员工需要 <code>informTime[i]</code> 分钟来通知它的所有直属下属（也就是说在 <code>informTime[i]</code> 分钟后，他的所有直属下属都可以开始传播这一消息）。</p>

<p>返回通知所有员工这一紧急消息所需要的 <strong>分钟数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, headID = 0, manager = [-1], informTime = [0]
<strong>输出：</strong>0
<strong>解释：</strong>公司总负责人是该公司的唯一一名员工。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/03/08/graph.png" style="height: 174px; width: 404px;" /></p>

<pre>
<strong>输入：</strong>n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
<strong>输出：</strong>1
<strong>解释：</strong>id = 2 的员工是公司的总负责人，也是其他所有员工的直属负责人，他需要 1 分钟来通知所有员工。
上图显示了公司员工的树结构。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>0 &lt;= headID &lt; n</code></li>
	<li><code>manager.length == n</code></li>
	<li><code>0 &lt;= manager[i] &lt; n</code></li>
	<li><code>manager[headID] == -1</code></li>
	<li><code>informTime.length&nbsp;== n</code></li>
	<li><code>0 &lt;= informTime[i] &lt;= 1000</code></li>
	<li>如果员工 <code>i</code> 没有下属，<code>informTime[i] == 0</code> 。</li>
	<li>题目 <strong>保证</strong> 所有员工都可以收到通知。</li>
</ul>


    
## 方法一：DFS + 哈希表

使用一个哈希表，来记录计算过的 通知到某个员工所需要的时间。

这样，每个员工被通知到所需要的时间最多被计算一次。

接着写一个递归函数```getTime(i)```，用来计算通知到员工i所需花费的时间。

如果i在哈希表中已经有记录，那么就直接返回哈希表中的值；

否则$通知到员工i的时间 = 通知到员工i的经理的时间 + 该员工的经理通知员工的耗时$

其中，“通知到员工i的经理的时间”能通过调用```getTime```函数来得到。

计算出结果后，我们先将结果存入哈希表再返回即可。

**使用哈希表的好处是，我们就不用建树了**

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    unordered_map<int, int> ma;

    int getTime(int node, vector<int>& manager, vector<int>& informTime) {
        if (ma.count(node)) {
            return ma[node];
        }
        return ma[node] = getTime(manager[node], manager, informTime) + informTime[manager[node]];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        ma[headID] = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, getTime(i, manager, informTime));
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def getTime(self, node: int, manager: List[int], informTime: List[int]) -> int:
        if node in self.ma:
            return self.ma[node]
        self.ma[node] = self.getTime(manager[node], manager, informTime) + informTime[manager[node]]
        return self.ma[node]
    
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        ans = 0
        self.ma = dict()
        self.ma[headID] = 0
        for i in range(n):
            ans = max(ans, self.getTime(i, manager, informTime))
        return ans
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2023/05/01/LeetCode%201376.%E9%80%9A%E7%9F%A5%E6%89%80%E6%9C%89%E5%91%98%E5%B7%A5%E6%89%80%E9%9C%80%E7%9A%84%E6%97%B6%E9%97%B4/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/130458959](https://letmefly.blog.csdn.net/article/details/130458959)
