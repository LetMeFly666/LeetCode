---
title: 113.路径总和 II
date: 2022-07-12 11:19:58
tags: [题解, LeetCode, 中等, 树, 深度优先搜索, 回溯, 二叉树, BFS]
---

# 【LetMeFly】113.路径总和 II：两种方法解决

力扣题目链接：[https://leetcode.cn/problems/path-sum-ii/](https://leetcode.cn/problems/path-sum-ii/)

<p>给你二叉树的根节点 <code>root</code> 和一个整数目标和 <code>targetSum</code> ，找出所有 <strong>从根节点到叶子节点</strong> 路径总和等于给定目标和的路径。</p>

<p><strong>叶子节点</strong> 是指没有子节点的节点。</p>

<div class="original__bRMd">
<div>
<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg" style="width: 500px; height: 356px;" />
<pre>
<strong>输入：</strong>root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
<strong>输出：</strong>[[5,4,11,2],[5,8,4,5]]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg" style="width: 212px; height: 181px;" />
<pre>
<strong>输入：</strong>root = [1,2,3], targetSum = 5
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [1,2], targetSum = 0
<strong>输出：</strong>[]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点总数在范围 <code>[0, 5000]</code> 内</li>
	<li><code>-1000 <= Node.val <= 1000</code></li>
	<li><code>-1000 <= targetSum <= 1000</code></li>
</ul>
</div>
</div>



## 前言

这道题类似于[LeetCode 112. 路径总和](https://leetcode.cn/problems/path-sum/)，可参考题解[https://letmefly.blog.csdn.net/article/details/125718939](https://letmefly.blog.csdn.net/article/details/125718939)


## 方法一：广搜过程中记录path和sum

和[LeetCode 112. 路径总和](https://letmefly.blog.csdn.net/article/details/125718939)类似，我们在广搜的时候，用```vector<int>```来记录路径上的节点的值即可。

+ 时间复杂度$O(n^2)$，其中$n$是树的所有节点的个数。第$1$维时间复杂度来自遍历(每个节点都遍历了$1$次)，第$2$维时间复杂度来自答案的存放(把一个路径添加到答案中时路径的长度也为$O(n)$)
+ 空间复杂度$O(n^2)$，每个节点都需要用$O(n)$的空间来记录$path$

### AC代码

#### C++

```cpp
typedef tuple<TreeNode*, vector<int>, int> pii;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        queue<pii> q;
        if (root)
            q.push({root, {root->val}, root->val});
        while (q.size()) {
            TreeNode* root;
            vector<int> path;
            int sum;
            tie (root, path, sum) = q.front();
            q.pop();
            if (!root->left && !root->right) {
                if (sum == targetSum) {
                    ans.push_back(path);
                }
            }
            if (root->left) {
                path.push_back(root->left->val);
                sum += root->left->val;
                q.push({root->left, path, sum});
                path.erase(--path.end());
                sum -= root->left->val;
            }
            if (root->right) {
                path.push_back(root->right->val);
                sum += root->right->val;
                q.push({root->right, path, sum});
            }
        }
        return ans;
    }
};
```

## 方法二：广搜过程中只记录sum

方法一的空间复杂度的来源主要是广搜过程中记录了路径path。我们可以优化这些空间：

用哈希表记录每个节点的父节点，再找到和为$targetSum$的叶节点后，从叶到根追溯到根节点即可获得路径。

这种方法相对于方法一会使用更少的空间，但是需要额外重新求一次路径path

+ 时间复杂度$O(n^2)$，其中$n$是树的所有节点的个数。第$1$维时间复杂度来自遍历(每个节点都遍历了$1$次)，第$2$维时间复杂度来自答案的存放(把一个路径添加到答案中时路径的长度也为$O(n)$)
+ 空间复杂度$O(n)$，每个节点都需要用$O(1)$的空间来记录$sum$，答案不计入空间复杂度中

### AC代码

#### C++

```cpp
typedef pair<TreeNode*, int> pii;
class Solution {
private:
    vector<vector<int>> ans;
    unordered_map<TreeNode*, TreeNode*> parent;

    void insertNewPath(TreeNode* leaf) {
        vector<int> path;
        while (true) {
            path.push_back(leaf->val);
            TreeNode* thisParent = parent[leaf];
            if (thisParent == leaf)
                break;
            leaf = thisParent;
        }        
        reverse(path.begin(), path.end());
        ans.push_back(path);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return {};
        parent[root] = root;
        queue<pii> q;
        q.push({root, root->val});
        while (q.size()) {
            auto[root, sum] = q.front();
            q.pop();
            if (!root->left && !root->right) {
                if (sum == targetSum)
                    insertNewPath(root);
            }
            if (root->left) {
                q.push({root->left, sum + root->left->val});
                parent[root->left] = root;
            }
            if (root->right) {
                q.push({root->right, sum + root->right->val});
                parent[root->right] = root;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/07/12/LeetCode%200113.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8CII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125739794](https://letmefly.blog.csdn.net/article/details/125739794)
