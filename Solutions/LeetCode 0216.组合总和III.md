---
title: 216.组合总和 III
date: 2024-04-21 14:06:02
tags: [题解, LeetCode, 中等, 数组, 回溯, 剪枝, 深度优先搜索, DFS]
---

# 【LetMeFly】216.组合总和 III：回溯(剪枝) OR 二进制枚举

力扣题目链接：[https://leetcode.cn/problems/combination-sum-iii/](https://leetcode.cn/problems/combination-sum-iii/)

<p>找出所有相加之和为&nbsp;<code>n</code><em> </em>的&nbsp;<code>k</code><strong>&nbsp;</strong>个数的组合，且满足下列条件：</p>

<ul>
	<li>只使用数字1到9</li>
	<li>每个数字&nbsp;<strong>最多使用一次</strong>&nbsp;</li>
</ul>

<p>返回 <em>所有可能的有效组合的列表</em> 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 7
<strong>输出:</strong> [[1,2,4]]
<strong>解释:</strong>
1 + 2 + 4 = 7
没有其他符合的组合了。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> <em><strong>k</strong></em> = 3, <em><strong>n</strong></em> = 9
<strong>输出:</strong> [[1,2,6], [1,3,5], [2,3,4]]
<strong>解释:
</strong>1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
没有其他符合的组合了。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> k = 4, n = 1
<strong>输出:</strong> []
<strong>解释:</strong> 不存在有效的组合。
在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 &gt; 1，没有有效的组合。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 60</code></li>
</ul>


    
## 方法一：二进制枚举（选与不选）

一共$9$个数，每个数选与不选一共有$2^9=512$种情况。

我们只需要使用一个二进制数一一枚举这$512$种情况即可。

二进制数的每一位代表每个数的选与不选，对于某种情况，只需要判断是否恰好为$k$个数，以及是否恰好和为$n$即可。

+ 时间复杂度$O(C\times2^C)$，其中$C=9$
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        int to = 1 << 9;
        for (int i = 0; i < to; i++) {
            if (__builtin_popcount(i) != k) {
                continue;
            }
            vector<int> thisSolution;
            int thisCnt = 0;
            for (int j = 0; j < 9; j++) {
                if (i & (1 << j)) {
                    thisCnt += j + 1;
                    thisSolution.push_back(j + 1);
                }
            }
            if (thisCnt == n) {
                ans.push_back(thisSolution);
            }
        }
        return ans;
    }
};
```

#### Python

```python
# from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        for i in range(1 << 9):
            if i.bit_count() != k:  # Python 3.9.4中似乎无此函数
                continue
            thisSolution = []
            thisCnt = 0
            for j in range(9):
                if i & (1 << j):
                    thisCnt += j + 1
                    thisSolution.append(j + 1)
            if thisCnt == n:
                ans.append(thisSolution)
        return ans
```

## 方法二：回溯+剪枝(DFS)

写一个函数```dfs(k, n, index)```来求所有“从[index,9]范围内选k个数使得和为n”的情况。

+ 如果```k = 0 && n == 0```，则说明当前方案为一个可行方案，计入答案中且返回
+ 如果```index > n || index == 10 || k <= 0```，则终止（剪枝/递归终止条件）

这样，就只有选与不选```index```这两种情况：

1. 不选```index```：直接递归调用```dfs(k, n, index + 1)```
2. 选```index```：将```index```加入当前选择方案的数组中、递归调用```dfs(k - 1, n - index, index + 1)```、将```index```从当前方案中移除（回溯）

以上

+ 时间复杂度$O(\begin{pmatrix}C\\ k\end{pmatrix}\times k)$，其中$C=9$，$\begin{pmatrix}C\\ k\end{pmatrix}$为组合数从$C$个数里面选$k$个
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;

    // 从[index,9]范围内选k个数使得和为n
    void dfs(int k, int n, int index) {
        if (!k && !n) {
            ans.push_back(now);
            return;
        }
        if (index > n || index == 10 || k <= 0) {
            return;
        }
        // not choose
        dfs(k, n, index + 1);
        // choose
        now.push_back(index);
        dfs(k - 1, n - index, index + 1);
        now.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }
};
```

小数据情况下，[方法一](https://leetcode.cn/submissions/detail/525643916/)的实际执行效果也许会优于[方法二](https://leetcode.cn/submissions/detail/525648605/)。

#### Python

```python
# from typing import List

class Solution:
    def dfs(self, k: int, n: int, index: int) -> None:
        if not k and not n:
            self.ans.append(self.now[:])
            return
        if index > n or index == 10 or k <= 0:
            return
        self.dfs(k, n, index + 1)
        self.now.append(index)
        self.dfs(k - 1, n - index, index + 1)
        self.now.pop()
    
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.ans = []
        self.now = []
        self.dfs(k, n, 1)
        return self.ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/04/21/LeetCode%200216.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CIII/)哦~
> Tisfy：[https://letmefly.blog.csdn.net/article/details/138033273](https://letmefly.blog.csdn.net/article/details/138033273)
