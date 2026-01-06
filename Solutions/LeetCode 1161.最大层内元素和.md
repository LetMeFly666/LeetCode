---
title: 1161.最大层内元素和：层序遍历
date: 2022-07-31 10:29:07
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, BFS, 层次遍历, 层序遍历]
categories: [题解, LeetCode]
index_img: https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/capture.jpeg
---

# 【LetMeFly】1161.最大层内元素和：层序遍历

力扣题目链接：[https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/](https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/)

<p>给你一个二叉树的根节点&nbsp;<code>root</code>。设根节点位于二叉树的第 <code>1</code> 层，而根节点的子节点位于第 <code>2</code> 层，依此类推。</p>

<p>请返回层内元素之和 <strong>最大</strong> 的那几层（可能只有一层）的层号，并返回其中&nbsp;<strong>最小</strong> 的那个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/08/17/capture.jpeg" style="height: 175px; width: 200px;" /></strong></p>

<pre>
<strong>输入：</strong>root = [1,7,0,7,-8,null,null]
<strong>输出：</strong>2
<strong>解释：</strong>
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [989,null,10250,98693,-89388,null,null,null,-32127]
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中的节点数在<meta charset="UTF-8" />&nbsp;<code>[1, 10<sup>4</sup>]</code>范围内<meta charset="UTF-8" /></li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


    
## 方法一：层序遍历 + 广搜BFS

有关二叉树的层序遍历，之前已经讲过，详细方法可参考 [LeetCode 0107.二叉树的层序遍历II の 题解](https://blog.letmefly.xyz/2022/07/04/LeetCode%200107.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86II/)

本题，同样地，我们使用优先队列来对二叉树进行层序遍历。

+ 用变量```maxSum```记录当前的单层最大和
+ 用变量```ans```来记录取得```maxSum```的最小层号
+ 用变量```nowLayer```记录当前遍历到的层的层号

初始值```maxSum```为```int```范围内的最小值```INT_MIN```，```ans```取任意值即可，```nowLayer```的值取```1```。

在遍历到某一层时，用一个临时变量```thisSum```统计这一层的节点值之和

如果这一层遍历结束后，```thisSum```的值大于之前所记录的最大值```maxSum```

那么就更新```maxSum```为```thisSum```，并将```ans```赋值为当前层号```nowLayer```。

+ 时间复杂度$O(N)$，其中$N$是节点个数。
+ 空间复杂度$O(N2)$，其中$N2$是节点最多的一层的节点数。

### AC代码

#### C++

```cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = -1;
        int nowLayer = 1;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int thisLayerNum = q.size();  // 这一层有几个元素
            int thisSum = 0;
            for (int i = 0; i < thisLayerNum; i++) {
                TreeNode* thisNode = q.front();
                q.pop();
                thisSum += thisNode->val;
                if (thisNode->left)
                    q.push(thisNode->left);
                if (thisNode->right)
                    q.push(thisNode->right);
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
                ans = nowLayer;
            }
            nowLayer++;
        }

        return ans;
    }
};
```

新code和三年前nowLayer变量名一样诶。

#### Python

```python
'''
LastEditTime: 2026-01-06 10:44:20
'''
from typing import Optional
from collections import deque

# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        ans, maximum = 0, -1000000000
        nowLayer = 0
        q = deque([root])
        while q:
            nowLayer += 1
            layerSum = 0
            newQ = deque([])
            for node in q:
                layerSum += node.val
                if node.left:
                    newQ.append(node.left)
                if node.right:
                    newQ.append(node.right)
            q = newQ
            if layerSum > maximum:
                maximum = layerSum
                ans = nowLayer
        return ans
```

#### Java

```java
/*
 * @LastEditTime: 2026-01-06 10:54:39
 */
import java.util.Deque;
import java.util.ArrayDeque;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxLevelSum(TreeNode root) {
        int ans = 0, maximum = -1000000000;
        int layerNum = 0;
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            layerNum++;
            int layerSum = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode node = q.poll();
                layerSum += node.val;
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
            if (layerSum > maximum) {
                maximum = layerSum;
                ans = layerNum;
            }
        }
        return ans;
    }
}
```

#### Golang

```go
/*
 * @LastEditTime: 2026-01-06 10:37:44
 */
package main

import "container/list"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxLevelSum(root *TreeNode) int {
    ans, maximum := 0, -1000000000
    nowLayer := 0
    q := list.New();
    q.PushBack(root)
    for q.Len() > 0 {
        nowLayer++
        layerSum := 0
        for t := q.Len(); t > 0; t-- {
            nodeElement := q.Front()
            node := nodeElement.Value.(*TreeNode)
            q.Remove(nodeElement)
            layerSum += node.Val
            if node.Left != nil {
                q.PushBack(node.Left)
            }
            if node.Right != nil {
                q.PushBack(node.Right)
            }
        }
        if layerSum > maximum {
            maximum = layerSum
            ans = nowLayer
        }
    }
    return ans
}
```

#### Rust

```rust
/*
 * @LastEditTime: 2026-01-06 13:26:09
 */
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;

impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = 1;
        let mut maximum = -1000000000;
        let mut layer_num = 0;
        let mut q: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        if let Some(r) = root {
            q.push_back(r);
        }
        while !q.is_empty() {
            layer_num += 1;
            let mut layer_sum = 0;
            let size: usize = q.len();
            for _ in 0..size {
                let node_rc: Rc<RefCell<TreeNode>> = q.pop_front().unwrap();
                let node: std::cell::Ref<'_, TreeNode> = node_rc.borrow();
                layer_sum += node.val;
                if let Some(left) = node.left.clone() {
                    q.push_back(left);
                }
                if let Some(right) = node.right.clone() {
                    q.push_back(right);
                }
            }
            if layer_sum > maximum {
                maximum = layer_sum;
                ans = layer_num;
            }
        }
        ans
    }
}
```


> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/126082726)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2022/07/31/LeetCode%201161.%E6%9C%80%E5%A4%A7%E5%B1%82%E5%86%85%E5%85%83%E7%B4%A0%E5%92%8C/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)