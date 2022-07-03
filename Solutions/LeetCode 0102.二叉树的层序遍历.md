---
title: 102.二叉树的层序遍历
date: 2022-07-03 14:28:54
tags: [题解, LeetCode, 中等, 树, 广度优先搜索, 二叉树, 层次遍历]
---

# 【LetMeFly】102.二叉树的层序遍历 + 针对C++的使用空间优化 （可能不同于常规做法）

力扣题目链接：[https://leetcode.cn/problems/binary-tree-level-order-traversal/](https://leetcode.cn/problems/binary-tree-level-order-traversal/)

<p>给你二叉树的根节点 <code>root</code> ，返回其节点值的 <strong>层序遍历</strong> 。 （即逐层地，从左到右访问所有节点）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>输入：</strong>root = [3,9,20,null,null,15,7]
<strong>输出：</strong>[[3],[9,20],[15,7]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[[1]]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = []
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>


    
## 方法一：层次遍历

记根节点为第$0$层

我们用```pair<TreeNode*, int>```记录```<此节点, 此节点的层数>```

初始时将根节点入队，在队列不空的时候：

> 不断取出队首元素，如果此元素不空，就判断此元素和上一个元素是否在同一层
>
> 如果不在同一层，就把上一层的所有节点添加到答案中
>
> 把此节点的左右子入队（层数=此层+1）

详见代码注释。

+ 时间复杂度$O(N)$，其中$N$是节点个数
+ 空间复杂度$O(N2)$，其中$N2$是节点最多的一层的节点数

### AC代码

#### C++

```cpp
typedef pair<TreeNode*, int> pii;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)  // root本来就为空
            return {};
        queue<pii> q;  // 队列
        int lastLayer = 0;  // 上一个节点是第几层
        q.push({root, 0});
        vector<vector<int>> ans;  // 答案
        vector<int> thisAns;  // 用来存放某一层的节点
        while (q.size()) {  // 不空的时候
            auto[p, thisLayer] = q.front();  // 取出队首元素
            q.pop();
            if (!p)  // 若为空节点，不做任何处理
                continue;
            if (thisLayer != lastLayer) {  // 这是新的一层
                lastLayer = thisLayer;  // 更新lastLayer
                ans.push_back(thisAns);  // 答案中添加这一层
                thisAns.clear();  // 这一层清空
            }
            thisAns.push_back(p->val);  // 添加到这一层中
            q.push({p->left, thisLayer + 1});  // 左子入队
            q.push({p->right, thisLayer + 1});  // 右子入队
        }
        ans.push_back(thisAns);  // 最后的一层添加到答案中
        return ans;
    }
};
```

## 方法二：层次遍历 + 针对C++的使用空间优化

不难发现，方法一中，```vector<int> thisAns```用来记录这一层的节点。

当遇到新的一层的节点时，我们将````thisAns```push到了```ans```中，然后将```thisAns```清空。

通俗地讲，就是先```copy```后```删除```。也许上述现象在某些语言中并不会发生，但C++中，确实会先为```ans```申请一些新的空间，再释放掉```thisAns```的空间，而不是直接让```ans```的下一个元素指向```thisAns```。

那么，我们如何避免上述现象呢？也很简单，只需要在```ans```中提前开辟一层，并且使用```ans[ans.size() - 1]```代替```thisAns```即可。

+ 时间复杂度$O(N)$，其中$N$是节点个数。与方法一相比，不需要专门将“某一层”添加到答案中，也不需要清空“用于存储某一层的空间”
+ 空间复杂度$O(N2)$，其中$N2$是节点最多的一层的节点数。与方法一相比，优势在于没有专门为某一层申请临时存储空间

上述优化仅仅是个小优化，并不会改变复杂度。

### AC代码

#### C++

```cpp
typedef pair<TreeNode*, int> pii;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        int lastLayer = 0;
        queue<pii> q;
        q.push({root, 0});
        vector<vector<int>> ans;
        ans.push_back({});
        while (q.size()) {
            auto[p, thisLayer] = q.front();
            q.pop();
            if (!p)
                continue;
            if (thisLayer != lastLayer) {
                lastLayer = thisLayer;
                ans.push_back({});  // 这里不需要clear()了
            }
            ans[thisLayer].push_back(p->val);
            q.push({p->left, thisLayer + 1});
            q.push({p->right, thisLayer + 1});
        }
        // 这里也不需要push最后一层了
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/03/LeetCode%200102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125584554](https://letmefly.blog.csdn.net/article/details/125584554)
