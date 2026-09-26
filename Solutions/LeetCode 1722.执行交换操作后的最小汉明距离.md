---
title: 1722.执行交换操作后的最小汉明距离：连通图
date: 2026-04-21 23:14:59
tags: [题解, LeetCode, 中等, 深度优先搜索, 并查集, 数组, 广度优先搜索, BFS, 连通图, 图]
categories: [题解, LeetCode]
---

# 【LetMeFly】1722.执行交换操作后的最小汉明距离：连通图

力扣题目链接：[https://leetcode.cn/problems/minimize-hamming-distance-after-swap-operations/](https://leetcode.cn/problems/minimize-hamming-distance-after-swap-operations/)

<p>给你两个整数数组 <code>source</code> 和 <code>target</code> ，长度都是 <code>n</code> 。还有一个数组 <code>allowedSwaps</code> ，其中每个 <code>allowedSwaps[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示你可以交换数组 <code>source</code> 中下标为 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code>（<strong>下标从 0 开始</strong>）的两个元素。注意，你可以按 <strong>任意</strong> 顺序 <strong>多次</strong> 交换一对特定下标指向的元素。</p>

<p>相同长度的两个数组 <code>source</code> 和 <code>target</code> 间的 <strong>汉明距离</strong> 是元素不同的下标数量。形式上，其值等于满足 <code>source[i] != target[i]</code> （<strong>下标从 0 开始</strong>）的下标 <code>i</code>（<code>0 &lt;= i &lt;= n-1</code>）的数量。</p>

<p>在对数组 <code>source</code> 执行 <strong>任意</strong> 数量的交换操作后，返回 <code>source</code> 和 <code>target</code> 间的 <strong>最小汉明距离</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
<strong>输出：</strong>1
<strong>解释：</strong>source 可以按下述方式转换：
- 交换下标 0 和 1 指向的元素：source = [<strong>2</strong>,<strong>1</strong>,3,4]
- 交换下标 2 和 3 指向的元素：source = [2,1,<strong>4</strong>,<strong>3</strong>]
source 和 target 间的汉明距离是 1 ，二者有 1 处元素不同，在下标 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
<strong>输出：</strong>2
<strong>解释：</strong>不能对 source 执行交换操作。
source 和 target 间的汉明距离是 2 ，二者有 2 处元素不同，在下标 1 和下标 2 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == source.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= source[i], target[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= allowedSwaps.length &lt;= 10<sup>5</sup></code></li>
	<li><code>allowedSwaps[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
</ul>


    
## 解题方法：连通图

allowedPairs可以随便交换，我们可以据此构建BFS一个连通子图，一个连通子图中的所有下标可以任意交换。

> 具体而言，如果$allowedSwaps[i] = [a_i, b_i]$，则看成$a_i$和$b_i$之间有一条边。遍历一遍$allowedSwaps$数组则可得到$graph$（其中$graph[i]$为所有与节点$i$直接连通的节点们）。

对于一批可以相互交换的元素（一个连通子图），如何得知他的*最小汉明距离*呢？两种方法

### 方法一：一个数组一个set

数组$a$中存放这个连通子图(其中任意节点可以随意交换)$source$中的所有元素，multiset$b$存放这个连通子图$target$中的所有元素。

遍历数组$a$中的元素，如果在$b$中则匹配并抹去，如果不在则汉明距离加一。

### 方法二：一个map

一个map存放这个连通子图中元素的diff。$source$中元素则累计记数加一，$target$中元素则累计计数减一。

最终遍历map所有键值对，值的绝对值之和即为总汉明距离的二倍。

### 时空复杂度分析

+ 时间复杂度$O(n+m)$，其中$m=len(allowedSwaps)$
+ 空间复杂度$O(n+m)$

### AC代码

#### C++ - 方法一

```cpp
/*
 * @LastEditTime: 2026-04-21 23:07:46
 */
class Solution {
private:
    inline void put(int node, vector<int>& source, vector<int>& target, vector<bool>& visited, vector<int>& a, unordered_multiset<int>& b, queue<int>& q) {
        q.push(node);
        visited[node] = true;
        a.push_back(source[node]);
        b.insert(target[node]);
    }

    int trace(int from, vector<int>& source, vector<int>& target, vector<vector<int>>& graph, vector<bool>& visited) {
        int ans = 0;
        queue<int> q;
        vector<int> a;
        unordered_multiset<int> b;
        
        put(from, source, target, visited, a, b, q);
        while (q.size()) {
            int from = q.front();
            q.pop();
            for (int to : graph[from]) {
                if (!visited[to]) {
                    put(to, source, target, visited, a, b, q);
                }
            }
        }

        for (int t : a) {
            unordered_multiset<int>::iterator it = b.find(t);
            if (it == b.end()) {
                ans++;
            } else {
                b.erase(it);
            }
        }
        return ans;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> graph(n);
        for (vector<int>& s : allowedSwaps) {
            graph[s[0]].push_back(s[1]);
            graph[s[1]].push_back(s[0]);
        }
        int ans = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans += trace(i, source, target, graph, visited);
            }
        }
        return ans;
    }
};

```

#### C++ - 方法二

```cpp
/*
 * @LastEditTime: 2026-04-21 23:14:07
 */
class Solution {
private:
    inline void put(int node, vector<int>& source, vector<int>& target, vector<bool>& visited, unordered_map<int, int>& diff, queue<int>& q) {
        q.push(node);
        visited[node] = true;
        diff[source[node]]++;
        diff[target[node]]--;
    }

    int trace(int from, vector<int>& source, vector<int>& target, vector<vector<int>>& graph, vector<bool>& visited) {
        int ans = 0;
        queue<int> q;
        unordered_map<int, int> diff;
        
        put(from, source, target, visited, diff, q);
        while (q.size()) {
            int from = q.front();
            q.pop();
            for (int to : graph[from]) {
                if (!visited[to]) {
                    put(to, source, target, visited, diff, q);
                }
            }
        }

        for (auto [_, d] : diff) {
            ans += abs(d);
        }
        return ans;
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> graph(n);
        for (vector<int>& s : allowedSwaps) {
            graph[s[0]].push_back(s[1]);
            graph[s[1]].push_back(s[0]);
        }
        int ans = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans += trace(i, source, target, graph, visited);
            }
        }
        return ans / 2;
    }
};

```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/160384168)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/04/21/LeetCode%201722.%E6%89%A7%E8%A1%8C%E4%BA%A4%E6%8D%A2%E6%93%8D%E4%BD%9C%E5%90%8E%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
