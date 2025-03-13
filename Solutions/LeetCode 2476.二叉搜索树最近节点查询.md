---
title: 2476.二叉搜索树最近节点查询
date: 2024-02-24 11:10:28
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, DFS, 中序遍历, 二叉搜索树, 数组, 二分查找, 二叉树]
categories: [题解, LeetCode]
---

# 【LetMeFly】2476.二叉搜索树最近节点查询：中序遍历 + 二分查找

力扣题目链接：[https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/](https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/)

<p>给你一个 <strong>二叉搜索树</strong> 的根节点 <code>root</code> ，和一个由正整数组成、长度为 <code>n</code> 的数组 <code>queries</code> 。</p>

<p>请你找出一个长度为 <code>n</code> 的 <strong>二维</strong> 答案数组 <code>answer</code> ，其中 <code>answer[i] = [min<sub>i</sub>, max<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>min<sub>i</sub></code> 是树中小于等于&nbsp;<code>queries[i]</code> 的 <strong>最大值</strong> 。如果不存在这样的值，则使用 <code>-1</code> 代替。</li>
	<li><code>max<sub>i</sub></code> 是树中大于等于&nbsp;<code>queries[i]</code> 的 <strong>最小值</strong> 。如果不存在这样的值，则使用 <code>-1</code> 代替。</li>
</ul>

<p>返回数组 <code>answer</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/09/28/bstreeedrawioo.png" style="width: 261px; height: 281px;" /></p>

<pre>
<strong>输入：</strong>root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
<strong>输出：</strong>[[2,2],[4,6],[15,-1]]
<strong>解释：</strong>按下面的描述找出并返回查询的答案：
- 树中小于等于 2 的最大值是 2 ，且大于等于 2 的最小值也是 2 。所以第一个查询的答案是 [2,2] 。
- 树中小于等于 5 的最大值是 4 ，且大于等于 5 的最小值是 6 。所以第二个查询的答案是 [4,6] 。
- 树中小于等于 16 的最大值是 15 ，且大于等于 16 的最小值不存在。所以第三个查询的答案是 [15,-1] 。
</pre>

<p><strong>示例 2 ：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/09/28/bstttreee.png" style="width: 101px; height: 121px;" /></p>

<pre>
<strong>输入：</strong>root = [4,null,9], queries = [3]
<strong>输出：</strong>[[-1,4]]
<strong>解释：</strong>树中不存在小于等于 3 的最大值，且大于等于 3 的最小值是 4 。所以查询的答案是 [-1,4] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数目在范围 <code>[2, 10<sup>5</sup>]</code> 内</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>6</sup></code></li>
	<li><code>n == queries.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= 10<sup>6</sup></code></li>
</ul>


    
## 方法一：中序遍历 + 二分查找

首先要明确的是：

> 题目给的二叉搜索树不一定是平衡树。因此最坏的情况下，题目给的二叉搜索树可能会退化成一条链，单词搜索的时间复杂度可能会达到$O(n)$。

因为可能有很多次查询（$10^5$），所以我们可以预处理二叉搜索树：

> 我们知道二叉搜索树的[中序遍历](https://blog.letmefly.xyz/tags/%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86/)结果是递增的，因此我们中序遍历一遍二叉搜索树，就得到了二叉树所有节点值的递增数组。

这样，我们只需要遍历每一个查询，二分查找想要的答案即可：

> 对于查询$q$，使用内置函数```lower_bound```/```bisect_left```等找到第一个$\geq q$的位置$loc$。
>
> 判断$loc$是否超出数组范围：
>
> + 若超出：说明无比$q$大的数，$M$应为（默认值）```-1```
> + 否则：$M=v[loc]$。此时若$M$恰好等于$q$则可直接得到$m=M$
>
> $m$仍未默认值```-1```的话，还要判断$loc$是否非零：
>
> + 若非零：则$m=v[loc-1]$
> + 否则：$m$为默认值```-1```

+ 时间复杂度$O(N+Q\log N)$，其中$N$是二叉树节点个数，$Q$是查询个数
+ 空间复杂度$O(N)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<int> v;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<vector<int>> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int m = -1, M = -1;
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), queries[i]);
            if (it != v.end()) {
                M = *it;
                if (M == queries[i]) {
                    m = M;
                    goto loop;
                }
            }
            if (it != v.begin()) {
                m = *(it - 1);
            }
            loop:
            ans[i] = {m, M};
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List, Optional
# from bisect import bisect_left

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        self.dfs(root.left)
        self.v.append(root.val)
        self.dfs(root.right)
    
    def closestNodes(self, root: TreeNode, queries: List[int]) -> List[List[int]]:
        self.v = []
        self.dfs(root)
        ans = []
        for q in queries:
            m, M = -1, -1
            loc = bisect_left(self.v, q)
            if loc != len(self.v):
                M = self.v[loc]  # v1中这里笔误写成M=loc了
                if M == q:
                    ans.append([q, q])
                    continue
            if loc:
                m = self.v[loc - 1]
            ans.append([m, M])
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/02/24/LeetCode%202476.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E6%9C%80%E8%BF%91%E8%8A%82%E7%82%B9%E6%9F%A5%E8%AF%A2/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136269516](https://letmefly.blog.csdn.net/article/details/136269516)
