---
title: 3310.移除可疑的方法：深度优先搜索(DFS)
date: 2026-08-05 21:45:12
tags: [题解, LeetCode, 中等, 深度优先搜索, DFS, 广度优先搜索, 图]
categories: [题解, LeetCode]
---

# 【LetMeFly】3310.移除可疑的方法：深度优先搜索(DFS)

力扣题目链接：[https://leetcode.cn/problems/remove-methods-from-project/](https://leetcode.cn/problems/remove-methods-from-project/)

<p>你正在维护一个项目，该项目有 <code>n</code> 个方法，编号从 <code>0</code> 到 <code>n - 1</code>。</p>

<p>给你两个整数 <code>n</code> 和 <code>k</code>，以及一个二维整数数组 <code>invocations</code>，其中 <code>invocations[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示方法 <code>a<sub>i</sub></code> 调用了方法 <code>b<sub>i</sub></code>。</p>

<p>已知如果方法 <code>k</code> 存在一个已知的 bug。那么方法 <code>k</code> 以及它直接或间接调用的任何方法都被视为<strong> </strong><strong>可疑方法</strong> ，我们需要从项目中移除这些方法。</p>

<p><span class="text-only" data-eleid="13" style="white-space: pre;">只有当一组方法没有被这组之外的任何方法调用时，这组方法才能被移除。</span></p>

<p>返回一个数组，包含移除所有<strong> </strong><strong>可疑方法</strong> 后剩下的所有方法。你可以以任意顺序返回答案。如果无法移除<strong> 所有 </strong>可疑方法，则<strong> 不 </strong>移除任何方法。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]</span></p>

<p><strong>输出:</strong> <span class="example-io">[0,1,2,3]</span></p>

<p><strong>解释:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/07/18/graph-2.png" style="width: 200px; height: 200px;" /></p>

<p>方法 2 和方法 1 是可疑方法，但它们分别直接被方法 3 和方法 0 调用。由于方法 3 和方法 0 不是可疑方法，我们无法移除任何方法，故返回所有方法。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]</span></p>

<p><strong>输出:</strong> <span class="example-io">[3,4]</span></p>

<p><strong>解释:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/07/18/graph-3.png" style="width: 200px; height: 200px;" /></p>

<p>方法 0、方法 1 和方法 2 是可疑方法，且没有被任何其他方法直接调用。我们可以移除它们。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入:</strong> <span class="example-io">n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]</span></p>

<p><strong>输出:</strong> <span class="example-io">[]</span></p>

<p><strong>解释:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/07/20/graph.png" style="width: 200px; height: 200px;" /></p>

<p>所有方法都是可疑方法。我们可以移除它们。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= n - 1</code></li>
	<li><code>0 &lt;= invocations.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>invocations[i] == [a<sub>i</sub>, b<sub>i</sub>]</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>invocations[i] != invocations[j]</code></li>
</ul>


    
## 解题方法：深度优先搜索

首先遍历一遍所有边并得到邻接表，接着从节点$k$开始深度优先搜索，谁被指到谁可疑。

再遍历一遍所有边，看看有没有好节点指向坏节点的边，如果有，直接返回$0$到$n-1$；否则，返回所有可疑节点。

+ 时间复杂度$O(n+m)$，其中$m=len(invocations)$
+ 空间复杂度$O(n+m)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-08-05 21:43:40
 */
class Solution {
private:
    int n;
    vector<bool> visited;
    vector<vector<int>> graph;

    void dfs(int from) {
        visited[from] = true;
        for (int to : graph[from]) {
            if (!visited[to]) {
                dfs(to);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        graph.resize(n);
        for (vector<int>& i : invocations) {
            graph[i[0]].push_back(i[1]);
        }

        visited.resize(n);
        this->n = n;
        dfs(k);

        for (vector<int>& i : invocations) {
            if (!visited[i[0]] && visited[i[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/163513352)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/08/05/LeetCode%203310.%E7%A7%BB%E9%99%A4%E5%8F%AF%E7%96%91%E7%9A%84%E6%96%B9%E6%B3%95/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
