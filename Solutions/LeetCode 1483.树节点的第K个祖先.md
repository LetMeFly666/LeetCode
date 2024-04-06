---
title: 1483.树节点的第 K 个祖先
date: 2024-04-06 12:47:22
tags: [题解, LeetCode, 困难, 树, 深度优先搜索, 广度优先搜索, 设计, 二分查找, 动态规划]
---

# 【LetMeFly】1483.树节点的第 K 个祖先：树上倍增

力扣题目链接：[https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/)

<p>给你一棵树，树上有 <code>n</code> 个节点，按从 <code>0</code> 到 <code>n-1</code> 编号。树以父节点数组的形式给出，其中 <code>parent[i]</code> 是节点 <code>i</code> 的父节点。树的根节点是编号为 <code>0</code> 的节点。</p>

<p>树节点的第 <em><code>k</code> </em>个祖先节点是从该节点到根节点路径上的第 <code>k</code> 个节点。</p>

<p>实现 <code>TreeAncestor</code> 类：</p>

<ul>
	<li><code>TreeAncestor（int n， int[] parent）</code> 对树和父数组中的节点数初始化对象。</li>
	<li><code>getKthAncestor</code><code>(int node, int k)</code> 返回节点 <code>node</code> 的第 <code>k</code> 个祖先节点。如果不存在这样的祖先节点，返回 <code>-1</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/06/14/1528_ex1.png" /></strong></p>

<pre>
<strong>输入：</strong>
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]

<strong>输出：</strong>
[null,1,0,-1]

<strong>解释：</strong>
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);

treeAncestor.getKthAncestor(3, 1);  // 返回 1 ，它是 3 的父节点
treeAncestor.getKthAncestor(5, 2);  // 返回 0 ，它是 5 的祖父节点
treeAncestor.getKthAncestor(6, 3);  // 返回 -1 因为不存在满足要求的祖先节点
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>parent[0] == -1</code> 表示编号为 <code>0</code> 的节点是根节点。</li>
	<li>对于所有的 <code>0 &lt;&nbsp;i &lt; n</code> ，<code>0 &lt;= parent[i] &lt; n</code> 总成立</li>
	<li><code>0 &lt;= node &lt; n</code></li>
	<li>至多查询&nbsp;<code>5 * 10<sup>4</sup></code> 次</li>
</ul>


    
## 解题方法：树上倍增

预处理并创建一个```anc```数组，令```anc[i][j]```为节点```i```的第$2^j$个祖先。（其中```anc```是```ancestors```的缩写）

这样就剩下了两个问题：

**问题一、如何创建anc数组**

首先```anc[i][0] = parent[i]```（$2^0=1$，节点```i```的第```1```个祖先为其父节点）

其次```j > 1```时```anc[i][j] = anc[ anc[i][j-1] ][j-1]```（例如节点```i```的第```8```祖先节点 等于 节点```i```的第```4```祖先节点的第```4```祖先节点）

并且有```anc[-1][*] = -1```（已经无祖先节点了，再往上跳还是```-1```）

由于$2^{16}=65536\gt 50000$，因此最多$\log n=16$次就能完成一个节点的所有$2^j$祖先数组。

**问题二、如何依据anc数组快速求得节点node的第k祖先**

假设要求节点```node```的第$k=5=101_2=4+1$祖先节点，那么可以求```node```的第```1```父节点的第```4```父节点，也就是说```anc[ anc[node][0] ][2]```即为答案。

因此，我们可以从低到高（从高到低也一样）遍历```k```的二进制位，如果第```j```位为```1```，则令```node = anc[node][j]```，即求```node```的$2^j$祖先节点。

特别的，若```node```已经为```-1```则可直接返回。

### 时空复杂度

+ 时间复杂度：初始化$O(n\log n)$，单次查询$O(\log n)$
+ 空间复杂度：初始化$O(n\log n)$，单次查询$O(1)$

### AC代码

#### C++

```cpp
class TreeAncestor {
private:
    const static int Log = 16;  // 2 ^ 16 = 65536
    vector<vector<int>> ancestors;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestors = vector<vector<int>>(n, vector<int>(Log, -1));
        for (int i = 0; i < n; i++) {
            ancestors[i][0] = parent[i];
        }
        for (int j = 1; j < Log; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestors[i][j - 1] != -1) {  // don't forget
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < Log && node != -1; j++) {
            if ((k >> j) & 1) {
                node = ancestors[node][j];
            }
        }
        return node;
    }
};
```

#### Python

```python
# from typing import List


Log = 16

class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.ancestors = [[parent[i]] + [-1] * (Log - 1) for i in range(n)]
        for j in range(1, Log):
            for i in range(n):
                if self.ancestors[i][j - 1] != -1:
                    self.ancestors[i][j] = self.ancestors[self.ancestors[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for j in range(Log):
            if (k >> j) & 1:
                node = self.ancestors[node][j]
            if node == -1:
                break
        return node
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/06/LeetCode%201483.%E6%A0%91%E8%8A%82%E7%82%B9%E7%9A%84%E7%AC%ACK%E4%B8%AA%E7%A5%96%E5%85%88/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/137426434](https://letmefly.blog.csdn.net/article/details/137426434)
