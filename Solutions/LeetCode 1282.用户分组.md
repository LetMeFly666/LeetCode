---
title: 1282.用户分组
date: 2022-08-12 09:48:35
tags: [题解, LeetCode, 中等, 数组, 哈希表]
categories: [题解, LeetCode]
---

# 【LetMeFly】1282.用户分组

力扣题目链接：[https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/](https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/)

<p>有&nbsp;<code>n</code>&nbsp;个人被分成数量未知的组。每个人都被标记为一个从 <code>0</code> 到 <code>n - 1</code> 的<strong>唯一ID</strong>&nbsp;。</p>

<p>给定一个整数数组 <code>groupSizes</code> ，其中<meta charset="UTF-8" />&nbsp;<code>groupSizes[i]</code>&nbsp;是第 <code>i</code> 个人所在的组的大小。例如，如果&nbsp;<code>groupSizes[1] = 3</code>&nbsp;，则第 <code>1</code> 个人必须位于大小为 <code>3</code> 的组中。</p>

<p>返回一个组列表，使每个人 <code>i</code> 都在一个大小为<meta charset="UTF-8" /><em>&nbsp;<code>groupSizes[i]</code>&nbsp;</em>的组中。</p>

<p>每个人应该&nbsp;<strong>恰好只&nbsp;</strong>出现在&nbsp;<strong>一个组&nbsp;</strong>中，并且每个人必须在一个组中。如果有多个答案，返回其中&nbsp;<strong>任何&nbsp;</strong>一个。可以&nbsp;<strong>保证&nbsp;</strong>给定输入&nbsp;<strong>至少有一个&nbsp;</strong>有效的解。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>groupSizes = [3,3,3,3,3,1,3]
<strong>输出：</strong>[[5],[0,1,2],[3,4,6]]
<strong>解释：
</strong>第一组是 [5]，大小为 1，groupSizes[5] = 1。
第二组是 [0,1,2]，大小为 3，groupSizes[0] = groupSizes[1] = groupSizes[2] = 3。
第三组是 [3,4,6]，大小为 3，groupSizes[3] = groupSizes[4] = groupSizes[6] = 3。 
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>groupSizes = [2,1,3,3,3,2]
<strong>输出：</strong>[[1],[0,5],[2,3,4]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>groupSizes.length == n</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;groupSizes[i] &lt;= n</code></li>
</ul>


    
## 方法一：模拟

假如一共有$n$个人，那么就开辟一个第一维大小为$n+1$的二维vector（```vector<vector<int>>(n + 1) v```）

然后遍历原始数组，把$t$人一组的这个人添加到```v[t]```中

如果```v[t].size()```达到了```t```，就说明这```t```个想要```t```人一组的人组好了队，就添加到答案中并把组队数组```v[t]```清空

因题目保证一定有解，故遍历完数组时恰能把所有人分组完毕

+ 时间复杂度$O(n)$，其中$n$是待分组人数
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        vector<vector<int>> v(n + 1);
        for (int i = 0; i < n; i++) {
            int thisGroupSize = groupSizes[i];
            v[thisGroupSize].push_back(i);
            if (v[thisGroupSize].size() == thisGroupSize) {
                ans.push_back(v[thisGroupSize]);
                v[thisGroupSize].clear();
            }
        }
        return ans;
    }
};
```

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.letmefly.xyz/2022/08/12/LeetCode%201282.%E7%94%A8%E6%88%B7%E5%88%86%E7%BB%84/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/126298148](https://letmefly.blog.csdn.net/article/details/126298148)
