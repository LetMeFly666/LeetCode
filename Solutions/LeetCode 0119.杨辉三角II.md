---
title: 119.杨辉三角 II
date: 2022-07-18 15:59:25
tags: [题解, LeetCode, 简单, 数组, 动态规划, 杨辉三角, 原地滚动]
---

# 【LetMeFly】119.杨辉三角 II：基于原地滚动的空间优化

力扣题目链接：[https://leetcode.cn/problems/pascals-triangle-ii/](https://leetcode.cn/problems/pascals-triangle-ii/)

<p>给定一个非负索引 <code>rowIndex</code>，返回「杨辉三角」的第 <code>rowIndex</code><em> </em>行。</p>

<p><small>在「杨辉三角」中，每个数是它左上方和右上方的数的和。</small></p>

<p><img alt="" src="https://pic.leetcode-cn.com/1626927345-DZmfxB-PascalTriangleAnimated2.gif" /></p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> rowIndex = 3
<strong>输出:</strong> [1,3,3,1]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> rowIndex = 0
<strong>输出:</strong> [1]
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> rowIndex = 1
<strong>输出:</strong> [1,1]
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 <= rowIndex <= 33</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong></p>

<p>你可以优化你的算法到 <code><em>O</em>(<i>rowIndex</i>)</code> 空间复杂度吗？</p>


    
## 方法一：构造整个杨辉三角

这道题和[LeetCode 118.杨辉三角](https://leetcode.cn/problems/pascals-triangle/)类似。

不同之处在于：

+ 这道题只需要返回最后一行
+ 这道题的行数是从0开始的

那么方法一就是类似[LeetCode 118.杨辉三角](https://letmefly.blog.csdn.net/article/details/125829159)，返回时只返回最后一行即可。

具体思路可参考[https://leetcode.letmefly.xyz/2022/07/17/LeetCode 0118.杨辉三角/](https://leetcode.letmefly.xyz/2022/07/17/LeetCode%200118.%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92/)

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N^2)$，因为需要存储整个三角

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> getRow(int numRows) {
        numRows++;
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            ans.push_back({1});
            for (int j = 1; j < i; j++) {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        return ans.back();
    }
};
```
    
## 方法二：原地滚动 + 只构造最后一行

不难发现，第$i+1$行的计算只需要用到第$i$行的值。

因此，我们只开辟最后一行的空间，并且原地滚动即可。

原地滚动的时候，记得从后往前计算。

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(1)$，答案不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        for (int row = 1; row <= rowIndex; row++) {
            ans[row] = 1;
            for (int th = row - 1; th > 0; th--) {  // 必须是从后往前
                ans[th] += ans[th - 1];
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://leetcode.letmefly.xyz/2022/07/18/LeetCode%200119.%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92II/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125853536](https://letmefly.blog.csdn.net/article/details/125853536)
