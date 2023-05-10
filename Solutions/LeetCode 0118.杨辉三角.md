---
title: 118.杨辉三角
date: 2022-07-17 10:20:45
tags: [题解, LeetCode, 简单, 数组, 动态规划, 杨辉三角]
---

# 【LetMeFly】118.杨辉三角

力扣题目链接：[https://leetcode.cn/problems/pascals-triangle/](https://leetcode.cn/problems/pascals-triangle/)

<p>给定一个非负整数 <em><code>numRows</code>，</em>生成「杨辉三角」的前 <em><code>numRows</code> </em>行。</p>

<p><small>在「杨辉三角」中，每个数是它左上方和右上方的数的和。</small></p>

<p><img alt="" src="https://img-blog.csdnimg.cn/83bb725b0de24d27b6908f384d347f03.gif" /></p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> numRows = 5
<strong>输出:</strong> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> numRows = 1
<strong>输出:</strong> [[1]]
</pre>

<p> </p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 <= numRows <= 30</code></li>
</ul>


    
## 方法一：动态规划

我们用```vector<vector<int>> ans```来存放杨辉三角。

**初始化**杨辉三角的第一行（```ans.push_back({1})```）

之后从第$2$行开始（下标$i$从$1$开始），不断生成每一行。

**第i + 1行的生成方法为**：

首先向这一行中添加第一个元素$1$（```ans.push_back({1})```）

然后从第$2$个元素开始（下标$j$从$1$开始），到这一行最后一个元素的前一个为止，第```i + 1```行的第```j + 1```个元素等于上一行的对应两个元素之和（```ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]```）

最后，再向这一行的末尾添加一个$1$即可。

如果不理解，可以参考杨辉三角的第$3$行的第$2$个元素$3$的生成来研究：

> 当计算到第$3$行的第$2$个元素时，$i=2,j=1$。此时$ans[i][j]=ans[i-1][j-1]+ans[i-1][j]=1+1=2$，说明第$3$行的第$2$个元素的值为$2$。

![1+1](https://img-blog.csdnimg.cn/cf11d3123c1248afb7d55d1e719c920f.jpeg#pic_center)

+ 时间复杂度$O(size^2)$
+ 空间复杂度$O(1)$，答案不计入算法空间复杂度

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; i++) {
            ans.push_back({1});
            for (int j = 1; j < i; j++) {
                ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};
```

运行结果：耗时还挺少

![挺快的这次](https://img-blog.csdnimg.cn/062fef3809fd4c878ac408f98b2f2d24.jpeg#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/17/LeetCode%200118.%E6%9D%A8%E8%BE%89%E4%B8%89%E8%A7%92/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125829159](https://letmefly.blog.csdn.net/article/details/125829159)
