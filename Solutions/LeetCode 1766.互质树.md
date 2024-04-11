---
title: 1766.互质树
date: 2024-04-11 15:24:55
tags: [题解, LeetCode, 困难, 树, 深度优先搜索, DFS, 广度优先搜索, 数学, 设计]
---

# 【LetMeFly】1766.互质树：设计（深度优先搜索）

力扣题目链接：[https://leetcode.cn/problems/tree-of-coprimes/](https://leetcode.cn/problems/tree-of-coprimes/)

<p>给你一个 <code>n</code> 个节点的树（也就是一个无环连通无向图），节点编号从 <code>0</code> 到 <code>n - 1</code> ，且恰好有 <code>n - 1</code> 条边，每个节点有一个值。树的 <strong>根节点</strong> 为 0 号点。</p>

<p>给你一个整数数组 <code>nums</code> 和一个二维数组 <code>edges</code> 来表示这棵树。<code>nums[i]</code> 表示第 <code>i</code> 个点的值，<code>edges[j] = [u<sub>j</sub>, v<sub>j</sub>]</code> 表示节点 <code>u<sub>j</sub></code> 和节点 <code>v<sub>j</sub></code> 在树中有一条边。</p>

<p>当 <code>gcd(x, y) == 1</code> ，我们称两个数 <code>x</code> 和 <code>y</code> 是 <strong>互质的</strong> ，其中 <code>gcd(x, y)</code> 是 <code>x</code> 和 <code>y</code> 的 <strong>最大公约数</strong> 。</p>

<p>从节点 <code>i</code> 到 <strong>根</strong> 最短路径上的点都是节点 <code>i</code> 的祖先节点。一个节点 <strong>不是</strong> 它自己的祖先节点。</p>

<p>请你返回一个大小为 <code>n</code> 的数组 <code>ans</code> ，其中<em> </em><code>ans[i]</code>是离节点 <code>i</code> 最近的祖先节点且满足<em> </em><code>nums[i]</code> 和<em> </em><code>nums[ans[i]]</code> 是 <strong>互质的</strong> ，如果不存在这样的祖先节点，<code>ans[i]</code> 为 <code>-1</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/02/20/untitled-diagram.png" style="width: 191px; height: 281px;" /></strong></p>

<pre>
<b>输入：</b>nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
<b>输出：</b>[-1,0,0,1]
<b>解释：</b>上图中，每个节点的值在括号中表示。
- 节点 0 没有互质祖先。
- 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
- 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0 的值是互质的(gcd(2,3) == 1)，所以节点 0 是最近的符合要求的祖先节点。
- 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1 是离它最近的符合要求的祖先节点。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/02/20/untitled-diagram1.png" style="width: 441px; height: 291px;" /></p>

<pre>
<strong>输入：</strong>nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
<b>输出：</b>[-1,0,-1,0,0,0,-1]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>1 <= nums[i] <= 50</code></li>
	<li><code>1 <= n <= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[j].length == 2</code></li>
	<li><code>0 <= u<sub>j</sub>, v<sub>j</sub> < n</code></li>
	<li><code>u<sub>j</sub> != v<sub>j</sub></code></li>
</ul>


    
## 解题方法：设计（深度优先搜索）

这道题的数据范围中可以得知，$nums[i]$最大只有$50$。因此可以建立一下数据结构：

+ [[int]] gcds;     // gcds[i]: 和i互质的所有数（题目范围内）
+ [[int]] path;     // path: dfs到当前节点时所有的祖先节点 | path[i]: 值为i的祖先节点们
+ [int] num2depth;  // num2depth[i]: 节点i的深度（默认值为0）
+ [[int]] graph;    // graph[i]: 节点i的所有相邻节点
+ [int] ans;        // ans: 最终要返回的答案

其中$gcds$可以在预处理时计算得出$1$到$50$的范围内每个数的所有质因数。

而$graph$课可以通过遍历一遍$edges$数组而得到。

至于$path$和$depth$，则可以在深度优先搜索的同时得到：

```cpp
void dfs(nums, num, depth) {
    num2depth[num] = depth;
    int thisVal = nums[num];
    ...  // 依据gcds[thisVal]遍历path中互质的数，深度最深的那个即为答案
    path[thisVal].push_back(num);
    ...  // 遍历graph开始递归
    path[thisVal].pop_back();
}
```

+ 时间复杂度$O(C^2+Cn)$，其中$C$为每个节点的数据范围，本题中$C=50$
+ 空间复杂度$O(C^2+n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<vector<int>> gcds;   // gcds[i]: 和i互质的所有数（题目范围内）
    vector<vector<int>> path;   // path: dfs到当前节点时所有的祖先节点 | path[i]: 值为i的祖先节点们
    vector<int> num2depth;      // num2depth[i]: 节点i的深度（默认值为0）
    vector<vector<int>> graph;  // graph[i]: 节点i的所有相邻节点
    vector<int> ans;            // ans: 最终要返回的答案

    void initGcds() {
        gcds.resize(51);
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (__gcd(i, j) == 1) {
                    gcds[i].push_back(j);
                    gcds[j].push_back(i);
                }
            }
        }
    }

    void initPath() {
        path.resize(51);
    }

    void initNum2depth(vector<int>& nums) {
        num2depth.resize(nums.size());
    }

    void initGraph(vector<int>& nums, vector<vector<int>>& edges) {
        graph.resize(nums.size());
        for (vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    void initAns(vector<int>& nums) {
        ans = vector<int>(nums.size(), -1);
    }

    void dfs(vector<int>& nums, int num, int depth) {
        num2depth[num] = depth;
        for (int coprime : gcds[nums[num]]) {
            if (path[coprime].size()) {
                int lastNum = path[coprime].back();
                if (ans[num] == -1 || num2depth[lastNum] > num2depth[ans[num]]) {
                    ans[num] = lastNum;
                }
            }
        }
        path[nums[num]].push_back(num);
        for (int nextNum : graph[num]) {
            if (!num2depth[nextNum]) {
                dfs(nums, nextNum, depth + 1);
            }
        }
        path[nums[num]].pop_back();
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        initGcds();
        initPath();
        initNum2depth(nums);
        initGraph(nums, edges);
        initAns(nums);
        dfs(nums, 0, 1);  // 根节点视为1层，和默认值不同
        return ans;
    }
};
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/11/LeetCode%201766.%E4%BA%92%E8%B4%A8%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137641344](https://letmefly.blog.csdn.net/article/details/137641344)
