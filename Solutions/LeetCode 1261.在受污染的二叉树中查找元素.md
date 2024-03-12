---
title: 1261.在受污染的二叉树中查找元素
date: 2024-03-12 09:30:01
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, dfs, 广度优先搜索, 设计, 哈希表, 哈希, set, 二叉树]
---

# 【LetMeFly】1261.在受污染的二叉树中查找元素：深搜+哈希表

力扣题目链接：[https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/](https://leetcode.cn/problems/find-elements-in-a-contaminated-binary-tree/)

<p>给出一个满足下述规则的二叉树：</p>

<ol>
	<li><code>root.val == 0</code></li>
	<li>如果 <code>treeNode.val == x</code> 且&nbsp;<code>treeNode.left != null</code>，那么&nbsp;<code>treeNode.left.val == 2 * x + 1</code></li>
	<li>如果 <code>treeNode.val == x</code> 且 <code>treeNode.right != null</code>，那么&nbsp;<code>treeNode.right.val == 2 * x + 2</code></li>
</ol>

<p>现在这个二叉树受到「污染」，所有的&nbsp;<code>treeNode.val</code>&nbsp;都变成了&nbsp;<code>-1</code>。</p>

<p>请你先还原二叉树，然后实现&nbsp;<code>FindElements</code>&nbsp;类：</p>

<ul>
	<li><code>FindElements(TreeNode* root)</code>&nbsp;用受污染的二叉树初始化对象，你需要先把它还原。</li>
	<li><code>bool find(int target)</code>&nbsp;判断目标值&nbsp;<code>target</code>&nbsp;是否存在于还原后的二叉树中并返回结果。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4-1.jpg" style="height: 119px; width: 320px;"></strong></p>

<pre><strong>输入：</strong>
[&quot;FindElements&quot;,&quot;find&quot;,&quot;find&quot;]
[[[-1,null,-1]],[1],[2]]
<strong>输出：</strong>
[null,false,true]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True </pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4.jpg" style="height: 198px; width: 400px;"></strong></p>

<pre><strong>输入：</strong>
[&quot;FindElements&quot;,&quot;find&quot;,&quot;find&quot;,&quot;find&quot;]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
<strong>输出：</strong>
[null,true,true,false]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/11/16/untitled-diagram-4-1-1.jpg" style="height: 274px; width: 306px;"></strong></p>

<pre><strong>输入：</strong>
[&quot;FindElements&quot;,&quot;find&quot;,&quot;find&quot;,&quot;find&quot;,&quot;find&quot;]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
<strong>输出：</strong>
[null,true,false,false,true]
<strong>解释：</strong>
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>TreeNode.val == -1</code></li>
	<li>二叉树的高度不超过&nbsp;<code>20</code></li>
	<li>节点的总数在&nbsp;<code>[1,&nbsp;10^4]</code>&nbsp;之间</li>
	<li>调用&nbsp;<code>find()</code>&nbsp;的总次数在&nbsp;<code>[1,&nbsp;10^4]</code>&nbsp;之间</li>
	<li><code>0 &lt;= target &lt;= 10^6</code></li>
</ul>


    
## 方法一：：DFS+哈希表

这道题不是“根据值是否在二叉树中去还原二叉树”，而是“已知二叉树然后问值是否在二叉树中”。

所以那不就好办了？遍历二叉树时使用哈希表记录哪些值出现过，对于每次查询直接返回这个值是否在哈希表中即可。

等下，你说二叉树未知？二叉树形状、根节点的值、父子节点间值的关系 都给你了，深度优先搜索的时候顺便把值确定了不就好了么。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
class FindElements {
private:
    unordered_set<int> se;

    void dfs(TreeNode* root, int val) {
        if (!root) {
            return;
        }
        root->val = val;
        se.insert(val);
        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return se.count(target);
    }
};
```

#### Python

```python
# from typing import Optional

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
    

class FindElements:
    def dfs(self, root: Optional[TreeNode], val: int) -> None:
        if not root:
            return
        root.val = val
        self.se.add(val)
        self.dfs(root.left, val * 2 + 1)
        self.dfs(root.right, val * 2 + 2)

    def __init__(self, root: TreeNode):
        self.se = set()
        self.dfs(root, 0)

    def find(self, target: int) -> bool:
        return target in self.se
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/03/12/LeetCode%201261.%E5%9C%A8%E5%8F%97%E6%B1%A1%E6%9F%93%E7%9A%84%E4%BA%8C%E5%8F%89%E6%A0%91%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/136642314](https://letmefly.blog.csdn.net/article/details/136642314)
