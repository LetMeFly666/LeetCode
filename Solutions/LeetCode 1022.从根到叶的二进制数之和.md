---
title: 1022.从根到叶的二进制数之和
date: 2022-05-30 10:52:40
tags: [题解, LeetCode, 简单, 二叉树, 树, 交互, 模拟]
---

# 【LetMeFly】1022.从根到叶的二进制数之和

力扣题目链接：[https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/](https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/)

给出一棵二叉树，其上每个结点的值都是 ```0``` 或 ```1``` 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。

+ 例如，如果路径为 ```0 -> 1 -> 1 -> 0 -> 1```，那么它表示二进制数 ```01101```，也就是 ```13``` 。
对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

返回这些数字之和。题目数据保证答案是一个 **32 位** 整数。

**示例 1:**

![示例1](https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png)

```
输入：root = [1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```

**示例 2:**

```
输入：root = [0]
输出：0
```

**提示:**

+ 树中的节点数在 ```[1, 1000]``` 范围内
+ ```Node.val``` 仅为 ```0``` 或 ```1```  

# 题目大意

假如从根到某个叶节点所经过的所有节点的值分别是“1”、“0”、“0”，那么最终答案就$加上(100)_2$ 

二进制的100等于十进制的4

# 思路

我们只需要层次遍历这棵树，遍历到某个节点时，如果存在子节点，子节点就加上这个节点的“值的<<1”的结果

## 方法一：层次遍历

+ 时间复杂度$O(n)$，其中$n$是树中节点的数量
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {  // 不会为空
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            TreeNode* p = q.front();
            q.pop();
            if (p->left || p->right) {
                if (p->left) {
                    p->left->val += (p->val) << 1;
                    q.push(p->left);
                }
                if (p->right) {
                    p->right->val += (p->val) << 1;
                    q.push(p->right);
                }
            }
            else {
                ans += p->val;
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/05/30/LeetCode%201022.%E4%BB%8E%E6%A0%B9%E5%88%B0%E5%8F%B6%E7%9A%84%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%95%B0%E4%B9%8B%E5%92%8C)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125043202](https://letmefly.blog.csdn.net/article/details/125043202)
