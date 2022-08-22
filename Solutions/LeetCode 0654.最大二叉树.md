---
title: 654.最大二叉树
date: 2022-08-20 10:40:15
tags: [题解, LeetCode, 中等, 栈, 树, 数组, 分治, 二叉树, 单调栈, 递归, 暴力]
---

# 【LetMeFly】视频演示：654.最大二叉树（视频做了近2h😭）

力扣题目链接：[https://leetcode.cn/problems/maximum-binary-tree/](https://leetcode.cn/problems/maximum-binary-tree/)

<p>给定一个不重复的整数数组&nbsp;<code>nums</code> 。&nbsp;<strong>最大二叉树</strong>&nbsp;可以用下面的算法从&nbsp;<code>nums</code> 递归地构建:</p>

<ol>
	<li>创建一个根节点，其值为&nbsp;<code>nums</code> 中的最大值。</li>
	<li>递归地在最大值&nbsp;<strong>左边</strong>&nbsp;的&nbsp;<strong>子数组前缀上</strong>&nbsp;构建左子树。</li>
	<li>递归地在最大值 <strong>右边</strong> 的&nbsp;<strong>子数组后缀上</strong>&nbsp;构建右子树。</li>
</ol>

<p>返回&nbsp;<em><code>nums</code> 构建的 </em><strong><em>最大二叉树</em> </strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/tree1.jpg" />
<pre>
<strong>输入：</strong>nums = [3,2,1,6,0,5]
<strong>输出：</strong>[6,3,5,null,2,0,null,null,1]
<strong>解释：</strong>递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/tree2.jpg" />
<pre>
<strong>输入：</strong>nums = [3,2,1]
<strong>输出：</strong>[3,null,2,null,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>nums</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>


    
## 方法一：暴力递归

如题目所描述，递归求解。

每次遍历一遍数组找到当前递归范围内的最大的数的位置，以此为根节点，前后缀数组分别继续递归，直到数组为空。

+ 时间复杂度$O(n^2)$, 其中$n$是数组中元素的个数。最差的情况下，原数组有序排列，递归数组中最大的元素都在数组端点，二叉树退化成了一个“链表”
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
private:
    TreeNode* main(vector<int>::iterator l, vector<int>::iterator r) {
        if (l >= r)  // 数组为空
            return nullptr;
        vector<int>::iterator maxIt = l;  // 用来记录最大值的位置
        int maxVal = *l;
        for (vector<int>::iterator it = l; it != r; it++) {  // 找到最大值
            if (*it > maxVal) {
                maxVal = *it;
                maxIt = it;
            }
        }
        return new TreeNode(maxVal, main(l, maxIt), main(maxIt + 1, r));  // 以最大值为根，前后缀分别递归建树。
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return main(nums.begin(), nums.end());
    }
};
```

## 方法二：单调栈

用栈来存放节点，构造一个单调递减栈。

遍历数组，进行以下$3$步操作：

1. 当栈顶元素小于当前元素时，**不断**弹出栈顶元素，并把当前元素的左子赋值为栈顶元素
2. 如果栈顶还有元素（那么一定比当前元素大），就把栈顶元素的右子赋值为当前元素
3. 当前元素入栈

+ 时间复杂度$O(n)$, 其中$n$是数组中元素的个数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;
        for (int &t : nums) {
            TreeNode* thisNode = new TreeNode(t);
            while (st.size() && st.top()->val < t) {
                thisNode->left = st.top();
                st.pop();
            }
            if (st.size()) {
                st.top()->right = thisNode;
            }
            st.push(thisNode);
        }
        TreeNode* ans;
        while (st.size()) {
            ans = st.top();
            st.pop();
        }
        return ans;
    }
};
```

#### Java

🔥 感谢 [@于洛东](https://leetcode.cn/u/lodoo/)大佬 提供Java版本的代码~

```Java
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        
        Deque<TreeNode> stack = new ArrayDeque<>();
        for(int num : nums){

            TreeNode node = new TreeNode(num);

            while(!stack.isEmpty() && num > stack.getLast().val) node.left = stack.removeLast();

            if(!stack.isEmpty() && num < stack.getLast().val) stack.getLast().right = node;

            stack.addLast(node);
        }
        return stack.getFirst();
    }
}
```

视频制作不易，喜欢了就点个赞再走吧

<iframe src="//player.bilibili.com/player.html?aid=899738739&bvid=BV14N4y1F7tQ&cid=809337052&page=1" scrolling="no" border="0" frameborder="no" framespacing="0" allowfullscreen="true" height="500px" width="100%"> </iframe>

BiliBili视频地址： [https://b23.tv/ktZRYxI](https://b23.tv/ktZRYxI)  [_](https://www.bilibili.com/video/BV14N4y1F7tQ)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/08/20/LeetCode%200654.%E6%9C%80%E5%A4%A7%E4%BA%8C%E5%8F%89%E6%A0%91/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126443463](https://letmefly.blog.csdn.net/article/details/126443463)
