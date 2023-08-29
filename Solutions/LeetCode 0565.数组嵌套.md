---
title: 565.数组嵌套
date: 2022-07-17 09:37:58
tags: [题解, LeetCode, 中等, 深度优先搜索, 数组, 图, 图遍历, 最大环]
---

# 【LetMeFly】565.数组嵌套：转换为图 + 原地修改の优化

力扣题目链接：[https://leetcode.cn/problems/array-nesting/](https://leetcode.cn/problems/array-nesting/)

<p>索引从<code>0</code>开始长度为<code>N</code>的数组<code>A</code>，包含<code>0</code>到<code>N - 1</code>的所有整数。找到最大的集合<code>S</code>并返回其大小，其中 <code>S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }</code>且遵守以下的规则。</p>

<p>假设选择索引为<code>i</code>的元素<code>A[i]</code>为<code>S</code>的第一个元素，<code>S</code>的下一个元素应该是<code>A[A[i]]</code>，之后是<code>A[A[A[i]]]...</code> 以此类推，不断添加直到<code>S</code>出现重复的元素。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre><strong>输入:</strong> A = [5,4,0,3,1,6,2]
<strong>输出:</strong> 4
<strong>解释:</strong> 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li><code>N</code>是<code>[1, 20,000]</code>之间的整数。</li>
	<li><code>A</code>中不含有重复的元素。</li>
	<li><code>A</code>中的元素大小在<code>[0, N-1]</code>之间。</li>
</ol>


    
## 方法一：图遍历

我们可以把$a[i]=j$看成是节点$i$有一条指向节点$j$的边，这样，我们就构建出了一个图。

图中的节点是$0\sim n-1$，并且每个节点的入度和出度都为$1$（只有一个节点指向它，并且它只指向一个节点）

那么，我们遍历(深度优先)这个图，同时记录下这个图的最大的环即可。

下面是**这个图必定有环**的证明，可以跳过：

> 因为每个节点的出度都为$1$，因此不论到达了哪个节点，都有下一个指向的节点。也就是说我们可以在图上不停遍历，永远遍历不到尽头。那么，$n+1$次节点访问中，必定有重复的节点。同时每个节点只有一个出度，因此就构成了循环。

+ 时间复杂度$O(N)$，其中$N$是图中节点的个数（也就是数组$nums$的长度）
+ 空间复杂度$O(N)$，我们需要额外开辟一个空间来记录这个节点是否被遍历过。

### AC代码

#### C++

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (!visited[i]) {
                visited[i] = true;
                cnt++;
                i = nums[i];
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

## 方法二：图遍历基础上的原地标记优化

方法二是方法一在空间上的改进。

方法一中，我们开辟了一个数组$visited$来记录哪个节点被标记过。

方法二中，我们选择不再另外开辟一个全新的数组，而是修改遍历过的节点（修改为$N$），以此来判断哪个节点被遍历过。

+ 时间复杂度$O(N)$，其中$N$是图中节点的个数（也就是数组$nums$的长度）
+ 空间复杂度$O(1)$，与方法一不同的是，方法二原地标记节点的过程中会修改原始节点的值。如果有“原始数组不可修改”的要求，那么就无法使用方法二

### AC代码

#### C++

```cpp
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            while (nums[i] != n) {
                int next = nums[i];
                nums[i] = n;
                cnt++;
                i = next;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

可见空间使用量减少了一些。

![result](https://cors.tisfy.eu.org/https://img-blog.csdnimg.cn/aa14df7da5194e37982867e06991236d.png#pic_center)

> 同步发文于CSDN，原创不易，转载请附上[原文链接](https://blog.tisfy.eu.org/2022/07/17/LeetCode%200565.%E6%95%B0%E7%BB%84%E5%B5%8C%E5%A5%97/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/125828684](https://letmefly.blog.csdn.net/article/details/125828684)
