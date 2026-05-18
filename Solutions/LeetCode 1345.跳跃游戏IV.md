---
title: 1345.跳跃游戏 IV：广度优先搜索(BFS)
date: 2026-05-18 21:53:19
tags: [题解, LeetCode, 困难, 广度优先搜索, BFS, 数组, 哈希表, map]
categories: [题解, LeetCode]
---

# 【LetMeFly】1345.跳跃游戏 IV：广度优先搜索(BFS)

力扣题目链接：[https://leetcode.cn/problems/jump-game-iv/](https://leetcode.cn/problems/jump-game-iv/)

<p>给你一个整数数组&nbsp;<code>arr</code>&nbsp;，你一开始在数组的第一个元素处（下标为 0）。</p>

<p>每一步，你可以从下标&nbsp;<code>i</code>&nbsp;跳到下标&nbsp;<code>i + 1</code> 、<code>i - 1</code> 或者 <code>j</code> ：</p>

<ul>
	<li><code>i + 1</code> 需满足：<code>i + 1 &lt; arr.length</code></li>
	<li><code>i - 1</code>&nbsp;需满足：<code>i - 1 &gt;= 0</code></li>
	<li><code>j</code>&nbsp;需满足：<code>arr[i] == arr[j]</code>&nbsp;且&nbsp;<code>i != j</code></li>
</ul>

<p>请你返回到达数组最后一个元素的下标处所需的&nbsp;<strong>最少操作次数</strong>&nbsp;。</p>

<p>注意：任何时候你都不能跳到数组外面。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [100,-23,-23,404,100,23,23,23,3,404]
<strong>输出：</strong>3
<strong>解释：</strong>那你需要跳跃 3 次，下标依次为 0 --&gt; 4 --&gt; 3 --&gt; 9 。下标 9 为数组的最后一个元素的下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [7]
<strong>输出：</strong>0
<strong>解释：</strong>一开始就在最后一个元素处，所以你不需要跳跃。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [7,6,9,6,9,6,9,7]
<strong>输出：</strong>1
<strong>解释：</strong>你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup>&nbsp;&lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
</ul>


    
## 解题方法：广度优先搜索(BFS)

这种求最小“步数”的，肯定得BFS：每次把第$step$步能走到的点全部走到(已经走到过的除外)，然后再以这些点为起点迈向它们能走到的下一点。

和正常的左右走的题不同的是，本题还能相同值之间跳跃。怎么办？好说，预处理遍历一遍数组，以数组元素值为key，以数组中这个值的下标构成的数组为value，创建一个哈希表即可。

特殊需注意：相同值的元素可能会比较多，所以某值走过一次“相同值跳跃”后，其他相同的值再这么尝试跳跃只会得到一大堆的“访问过”，所以在一个值进行过等值跳跃后，可以标注或删掉哈希表中的这个值避免大量重复访问。

+ 时间复杂度$O(len(arr))$，可以理解为每个下标最多只会被通过“左边”、“右边”、“相同值”尝试访问3次。
+ 空间复杂度$O(len(arr))$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-05-18 21:51:28
 */
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> visited(n);
        unordered_map<int, vector<int>> same;
        for (int i = 0; i < n; i++) {
            same[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int ans = 0;
        while (true) {
            int size = q.size();
            while (size--) {
                int now = q.front();
                // cout << "now: " << now << endl;
                q.pop();
                if (now == n - 1) {
                    return ans;
                }
                if (now - 1 >= 0 && !visited[now - 1]) {
                    q.push(now - 1);
                    visited[now - 1] = true;
                }
                if (now + 1 < n && !visited[now + 1]) {
                    q.push(now + 1);
                    visited[now + 1] = true;
                }
                if (same.count(arr[now])) {
                    for (int next : same[arr[now]]) {
                        if (!visited[next]) {
                            visited[next] = true;
                            q.push(next);
                        }
                    }
                    same.erase(arr[now]);
                }
            }
            ans++;
        }
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/161202446)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/05/18/LeetCode%201345.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8FIV/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
