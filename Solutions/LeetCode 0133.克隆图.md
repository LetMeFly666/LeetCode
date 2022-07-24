---
title: 133.克隆图
date: 2022-07-24 16:25:56
tags: [题解, LeetCode, 中等, 深度优先搜索, 广度优先搜索, 图, 哈希表, BFS]
---

# 【LetMeFly】133.克隆图：BFS

力扣题目链接：[https://leetcode.cn/problems/clone-graph/](https://leetcode.cn/problems/clone-graph/)

<p>给你无向&nbsp;<strong><a href="https://baike.baidu.com/item/连通图/6460995?fr=aladdin" target="_blank">连通</a>&nbsp;</strong>图中一个节点的引用，请你返回该图的&nbsp;<a href="https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin" target="_blank"><strong>深拷贝</strong></a>（克隆）。</p>

<p>图中的每个节点都包含它的值 <code>val</code>（<code>int</code>） 和其邻居的列表（<code>list[Node]</code>）。</p>

<pre>class Node {
    public int val;
    public List&lt;Node&gt; neighbors;
}</pre>

<p>&nbsp;</p>

<p><strong>测试用例格式：</strong></p>

<p>简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（<code>val = 1</code>），第二个节点值为 2（<code>val = 2</code>），以此类推。该图在测试用例中使用邻接列表表示。</p>

<p><strong>邻接列表</strong> 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。</p>

<p>给定节点将始终是图中的第一个节点（值为 1）。你必须将&nbsp;<strong>给定节点的拷贝&nbsp;</strong>作为对克隆图的引用返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<!-- <p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/01/133_clone_graph_question.png" style="height: 500px; width: 500px;"></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/08c9bf3b85054cd39c6107e13f8b0f0e.png" style="height: 500px; width: 500px;"></p>

<pre><strong>输入：</strong>adjList = [[2,4],[1,3],[2,4],[1,3]]
<strong>输出：</strong>[[2,4],[1,3],[2,4],[1,3]]
<strong>解释：
</strong>图中有 4 个节点。
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
</pre>

<p><strong>示例 2：</strong></p>

<!-- <p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/01/graph.png" style="height: 148px; width: 163px;"></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/4379bcf1050345528a2f69ecadd03e4d.png" style="height: 148px; width: 163px;"></p>

<pre><strong>输入：</strong>adjList = [[]]
<strong>输出：</strong>[[]]
<strong>解释：</strong>输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>adjList = []
<strong>输出：</strong>[]
<strong>解释：</strong>这个图是空的，它不含任何节点。
</pre>

<p><strong>示例 4：</strong></p>

<!-- <p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/01/graph-1.png" style="height: 133px; width: 272px;"></p> -->
<p><img alt="" src="https://img-blog.csdnimg.cn/f9438857aacb42ca81f1b723cd85fe56.png" style="height: 133px; width: 272px;"></p>

<pre><strong>输入：</strong>adjList = [[2],[1]]
<strong>输出：</strong>[[2],[1]]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>节点数不超过 100 。</li>
	<li>每个节点值&nbsp;<code>Node.val</code> 都是唯一的，<code>1 &lt;= Node.val &lt;= 100</code>。</li>
	<li>无向图是一个<a href="https://baike.baidu.com/item/简单图/1680528?fr=aladdin" target="_blank">简单图</a>，这意味着图中没有重复的边，也没有自环。</li>
	<li>由于图是无向的，如果节点 <em>p</em> 是节点 <em>q</em> 的邻居，那么节点 <em>q</em> 也必须是节点 <em>p</em>&nbsp;的邻居。</li>
	<li>图是连通图，你可以从给定节点访问到所有节点。</li>
</ol>


    
## 方法一：BFS

我们可以通过广度优先搜素遍历一遍原图

遍历过程中，如果某个节点是第一次遇到，就**新建**一个和它的值相同的节点，并且用哈希表存下来原始节点对应的新节点是谁

不断把第一次遍历到的节点入队，每次从队中取出一个节点，把它的所有的边，添加给Copy出来的新节点。

+ 时间复杂度$O(n)$，其中$n$是节点的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> ma;
        queue<Node*> q;
        q.push(node);
        ma[node] = new Node(node->val);
        while (q.size()) {
            Node* thisNode = q.front();
            q.pop();
            for (Node* to : thisNode->neighbors) {
                if (!ma.count(to)) {
                    ma[to] = new Node(to->val);
                    q.push(to);  // 这里是to
                }
                ma[thisNode]->neighbors.push_back(ma[to]);  // 这里是ma[thisNode]
            }
        }
        return ma[node];
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/24/LeetCode%200133.%E5%85%8B%E9%9A%86%E5%9B%BE/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125960776](https://letmefly.blog.csdn.net/article/details/125960776)
