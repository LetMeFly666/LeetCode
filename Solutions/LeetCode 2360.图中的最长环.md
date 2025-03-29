---
title: 2360.图中的最长环：一步一打卡(不撞南墙不回头) - 通过故事讲道理
date: 2025-03-29 14:24:01
tags: [题解, LeetCode, 困难, 深度优先搜索, DFS, 图, 拓扑排序]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png
---

# 【LetMeFly】2360.图中的最长环：一步一打卡(不撞南墙不回头) - 通过故事讲道理

力扣题目链接：[https://leetcode.cn/problems/longest-cycle-in-a-graph/](https://leetcode.cn/problems/longest-cycle-in-a-graph/)

<p>给你一个 <code>n</code>&nbsp;个节点的 <b>有向图</b>&nbsp;，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;，其中每个节点&nbsp;<strong>至多</strong>&nbsp;有一条出边。</p>

<p>图用一个大小为 <code>n</code>&nbsp;下标从<strong>&nbsp;0</strong>&nbsp;开始的数组&nbsp;<code>edges</code>&nbsp;表示，节点 <code>i</code>&nbsp;到节点&nbsp;<code>edges[i]</code>&nbsp;之间有一条有向边。如果节点&nbsp;<code>i</code>&nbsp;没有出边，那么&nbsp;<code>edges[i] == -1</code>&nbsp;。</p>

<p>请你返回图中的 <strong>最长</strong>&nbsp;环，如果没有任何环，请返回 <code>-1</code>&nbsp;。</p>

<p>一个环指的是起点和终点是 <strong>同一个</strong>&nbsp;节点的路径。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/06/08/graph4drawio-5.png" style="width: 335px; height: 191px;" /></p>

<pre>
<b>输入：</b>edges = [3,3,4,2,3]
<b>输出去：</b>3
<b>解释：</b>图中的最长环是：2 -&gt; 4 -&gt; 3 -&gt; 2 。
这个环的长度为 3 ，所以返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-1.png" style="width: 171px; height: 161px;" /></p>

<pre>
<b>输入：</b>edges = [2,-1,3,1]
<b>输出：</b>-1
<b>解释：</b>图中没有任何环。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-1 &lt;= edges[i] &lt; n</code></li>
	<li><code>edges[i] != i</code></li>
</ul>


    
## 解题方法：一步一打卡(不撞南墙不回头)

### 故事

<font title="Tisfy">小T</font>爱跑图，她有如下爱好：

1. 只跑没跑到过的景点
1. 不撞南墙不回头(一直跑下去，直到跑到一个跑到过的景点)
1. 爱打卡(第一次跑到一个景点，就打卡记录下“这是我解锁的第xx个城市”)

<font title="Tisfy">小T</font>跑完所有景点，这道题就解决了。

### 原理解析

这得益于每个景点最多只有一个“下一个景点”(每个节点至多有一条出边)。

+ 如果<font title="Tisfy">小T</font>的起点在环的任意一个位置：

    <font title="Tisfy">小T</font>一定会再次回到自己的起点(然后发现这里来过了，撞到了南墙，不再继续此路线)。
    
    由于记录了自己的打卡记录，所以只需要判断一下上次到这里是“解锁的第几个城市”，再看看本次到这里时一共解锁了几个城市，相减就能得到这个环的长度。

+ 如果<font title="Tisfy">小T</font>的起点不在环上：

    + 如果是一条单链：则要么会跑到终点后无路可走，要么会跑到一个去过的景点，<font title="Tisfy">小T</font>不再继续此路线
    
    + 如果是一条指向一个环的链：那么终将走到环上

        + 如果环还没有被走过，那么绕环跑一圈后就会得出环长
        + 如果环已经被走过了，那么<font title="Tisfy">小T</font>不再继续此路线

### 具体实现

使用一个$visited$数组记录一下每个景点的打卡记录，使用$cnt$记录即将要解锁的城市是第几个。

从任意一点开始尝试，按照<font title="Tisfy">小T</font>的跑法开始模拟，遇到新城市就打卡记录并尝试继续，直到到达终点或遇到了去过的城市为止。

<font title="Tisfy">小T</font>停止这条路线后：

+ 如果停止位置指向下一个城市($edges[i]\neq -1$)，则说明是到达了去过的城市(而不是达到了单链的终点)
+ 并且如果该城市的打卡记录不早于本次路线的开始时间，则说明是本次跑步过程中遇到的城市，说明有环

什么意思呢？<font title="Tisfy">小T</font>开始一条新的路线时，还需要记录一下新路线开始时一共打卡了多少城市。

遇到了一个去过城市，如果打卡记录编号很小(不是本次路线上遇到的，而是之前经过的)，就不能说明有环。

反之，如果这个去过的城市是本次线路上二次遇到的，就说明有环。

### 时空复杂度分析

+ 时间复杂度$O(n)$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 10:47:24
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 11:47:35
 * @Description: AC,93.64%,86.13%
 */
/*
[3,3,4,2,3]
 0 1 2 3 4

        1
        ↓
0-----> 3 <----- 4 
        |        ↑
        ↓        |
        2 -------+
*/

/*
 0  1 2 3
[2,-1,3,1]

0-->2-->3-->1

*/

/*
 0 1 2 3  4  5
[5,2,3,1,-1,-1]


0-->5      4

   1---->2
    ↖ ↙
      3
*/
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int cnt = 1;
        vector<int> visited(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            int begin = cnt, x = i;
            while (edges[x] != -1 && !visited[x]) {
                visited[x] = cnt++;
                x = edges[x];
            }
            if (edges[x] != -1 && visited[x] >= begin) {
                ans = max(ans, cnt - visited[x]);
            }
        }
        return ans;
    }
};


#ifdef _WIN32
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.longestCycle(v) << endl;
    }
    return 0;
}
#endif
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-03-29 14:06:24
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-29 14:09:27
'''
from typing import List

class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        ans = -1
        cnt = 1
        visited = [0] * len(edges)
        for i in range(len(edges)):
            begin = cnt
            while edges[i] != -1 and not visited[i]:
                visited[i] = cnt
                cnt += 1
                i = edges[i]
            if edges[i] != -1 and visited[i] >= begin:
                ans = max(ans, cnt - visited[i])
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 14:10:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 14:15:56
 */
class Solution {
    public int longestCycle(int[] edges) {
        int ans = -1;
        int cnt = 1;
        int[] visited = new int[edges.length];
        for (int i = 0; i < edges.length; i++) {
            int begin = cnt;
            int x = i;
            while (edges[x] != -1 && visited[x] == 0) {
                visited[x] = cnt++;
                x = edges[x];
            }
            if (edges[x] != -1 && visited[x] >= begin) {
                ans = Math.max(ans, cnt - visited[x]);
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-03-29 14:16:26
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-03-29 14:18:33
 */
package main

func longestCycle(edges []int) int {
    ans := -1
    cnt := 1
    visited := make([]int, len(edges))
    for i := range edges {
        begin := cnt
        for edges[i] != -1 && visited[i] == 0 {
            visited[i] = cnt
            cnt++
            i = edges[i]
        }
        if edges[i] != -1 && visited[i] >= begin {
            ans = max(ans, cnt - visited[i])
        }
    }
    return ans
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/146687134)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/03/29/LeetCode%202360.%E5%9B%BE%E4%B8%AD%E7%9A%84%E6%9C%80%E9%95%BF%E7%8E%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
