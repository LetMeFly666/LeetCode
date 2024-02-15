---
title: 655.输出二叉树
date: 2022-08-22 10:15:48
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 广度优先搜索, 二叉树, BFS, DFS, 矩阵填充]
---

# 【LetMeFly】655.输出二叉树

力扣题目链接：[https://leetcode.cn/problems/print-binary-tree/](https://leetcode.cn/problems/print-binary-tree/)

<p>在一个 m*n 的二维字符串数组中输出二叉树，并遵守以下规则：</p>

<ol>
	<li>行数&nbsp;<code>m</code>&nbsp;应当等于给定二叉树的高度。</li>
	<li>列数&nbsp;<code>n</code>&nbsp;应当总是奇数。</li>
	<li>根节点的值（以字符串格式给出）应当放在可放置的第一行正中间。根节点所在的行与列会将剩余空间划分为两部分（<strong>左下部分和右下部分</strong>）。你应该将左子树输出在左下部分，右子树输出在右下部分。左下和右下部分应当有相同的大小。即使一个子树为空而另一个非空，你不需要为空的子树输出任何东西，但仍需要为另一个子树留出足够的空间。然而，如果两个子树都为空则不需要为它们留出任何空间。</li>
	<li>每个未使用的空间应包含一个空的字符串<code>&quot;&quot;</code>。</li>
	<li>使用相同的规则输出子树。</li>
</ol>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong>
     1
    /
   2
<strong>输出:</strong>
[[&quot;&quot;, &quot;1&quot;, &quot;&quot;],
 [&quot;2&quot;, &quot;&quot;, &quot;&quot;]]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>
     1
    / \
   2   3
    \
     4
<strong>输出:</strong>
[[&quot;&quot;, &quot;&quot;, &quot;&quot;, &quot;1&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;],
 [&quot;&quot;, &quot;2&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;, &quot;3&quot;, &quot;&quot;],
 [&quot;&quot;, &quot;&quot;, &quot;4&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;]]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong>
      1
     / \
    2   5
   / 
  3 
 / 
4 
<strong>输出:</strong>
[[&quot;&quot;,  &quot;&quot;,  &quot;&quot;, &quot;&quot;,  &quot;&quot;, &quot;&quot;, &quot;&quot;, &quot;1&quot;, &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;, &quot;&quot;, &quot;&quot;]
 [&quot;&quot;,  &quot;&quot;,  &quot;&quot;, &quot;2&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;5&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;]
 [&quot;&quot;,  &quot;3&quot;, &quot;&quot;, &quot;&quot;,  &quot;&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;, &quot;&quot;, &quot;&quot;]
 [&quot;4&quot;, &quot;&quot;,  &quot;&quot;, &quot;&quot;,  &quot;&quot;, &quot;&quot;, &quot;&quot;, &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;,  &quot;&quot;, &quot;&quot;, &quot;&quot;]]
</pre>

<p><strong>注意:</strong> 二叉树的高度在范围 [1, 10] 中。</p>


    
## 方法一：DFS统计高度 + BFS填充矩阵

其实我觉得这道题的配图不是很好，样例二应该是这样的：

```
                  1
       +----------+-----------+
       2                      3
       +---+
           4
```

也就是说，越靠近根部，二叉树的“开口”就越大，```4```不在```1```的正下方。

但是这些都无所谓，只需要按照题意进行赋值就好了。

首先统计二叉树的高度。

```cpp
int getTreeHeight(TreeNode* root) {
    if (!root)
        return 0;
    return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
}
```

注意，题目中二叉树的根节点是```0```层，因此这个函数统计出来的$height$其实是题目中的$height + 1$

因此，矩阵的大小为$height\times 2^{height} - 1$

```cpp
vector<vector<string>> ans(height, vector<string>((1 << height) - 1));
```

之后我们可以建立一个结构体

```cpp
struct Node {
    TreeNode* treeNode;  // 当前节点
    int x, y;  // 当前节点在矩阵中的位置
    Node(TreeNode* treeNode, int x, int y) : treeNode(treeNode), x(x), y(y) {
        
    }
};
```

再建立一个队列，将根节点及其在矩阵中的位置入队。

在队列不空时，不断取出元素并在矩阵对应的位置赋值，如果左子或右子不为空，就入队。

左右子的位置计算公式题目中也已给出。

+ 时间复杂度$O(h\times 2^h)$，其中$h$是二叉的高度
+ 空间复杂度$O(C)$，其中$C$是二叉树单层的最大节点数量

### AC代码

#### C++

```cpp
struct Node {
    TreeNode* treeNode;
    int x, y;
    Node(TreeNode* treeNode, int x, int y) : treeNode(treeNode), x(x), y(y) {
        
    }
};

class Solution {
private:
    int getTreeHeight(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getTreeHeight(root);  // 这里的height就是题目中的height + 1
        vector<vector<string>> ans(height, vector<string>((1 << height) - 1));
        queue<Node> q;
        q.push({root, 0, ((1 << height) - 1) / 2});
        while (q.size()) {
            auto[node, x, y] = q.front();
            q.pop();
            ans[x][y] = to_string(node->val);
            if (node->left) {
                q.push({node->left, x + 1, y - (1 << (height - x - 2))});
            }
            if (node->right) {
                q.push({node->right, x + 1, y + (1 << (height - x - 2))});
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/22/LeetCode%200655.%E8%BE%93%E5%87%BA%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126461060](https://letmefly.blog.csdn.net/article/details/126461060)
