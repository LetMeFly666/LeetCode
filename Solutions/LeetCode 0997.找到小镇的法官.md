---
title: 997.找到小镇的法官
date: 2024-09-22 23:36:30
tags: [题解, LeetCode, 简单, 图, 数组, 哈希表, 计数, 图]
categories: [题解, LeetCode]
---

# 【LetMeFly】997.找到小镇的法官：计数

力扣题目链接：[https://leetcode.cn/problems/find-the-town-judge/](https://leetcode.cn/problems/find-the-town-judge/)

<p>小镇里有 <code>n</code> 个人，按从 <code>1</code> 到 <code>n</code> 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。</p>

<p>如果小镇法官真的存在，那么：</p>

<ol>
	<li>小镇法官不会信任任何人。</li>
	<li>每个人（除了小镇法官）都信任这位小镇法官。</li>
	<li>只有一个人同时满足属性 <strong>1</strong> 和属性 <strong>2</strong> 。</li>
</ol>

<p>给你一个数组 <code>trust</code> ，其中 <code>trust[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示编号为 <code>a<sub>i</sub></code> 的人信任编号为 <code>b<sub>i</sub></code> 的人。</p>

<p>如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2, trust = [[1,2]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3, trust = [[1,3],[2,3]]
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 3, trust = [[1,3],[2,3],[3,1]]
<strong>输出：</strong>-1
</pre>
&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= trust.length &lt;= 10<sup>4</sup></code></li>
	<li><code>trust[i].length == 2</code></li>
	<li><code>trust</code> 中的所有<code>trust[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> <strong>互不相同</strong></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n</code></li>
</ul>


    
## 解题方法：计数

使用inDegree数组记录每个元素分别被信任几次，使用outDegree数组记录每个元素分别信任他人几次。

遍历一遍trust数组即可得到inDegree数组和outDegree数组。

遍历每个元素，若inDegree值等于$n-1$且outDegree数组为空，则返回该元素。

否则返回`-1`。

+ 时间复杂度$O(n+len(trust))$
+ 空间复杂度$O(n)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n + 1), outDegree(n + 1);
        for (vector<int>& v : trust) {
            inDegree[v[1]]++, outDegree[v[0]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
```

```cpp
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> cannotHim(n);
        vector<int> cntHim(n);
        for (vector<int>& v : trust) {
            cannotHim[v[0] - 1] = true;
            cntHim[v[1] - 1]++;
        }
        for (int i = 0; i < n; i++) {
            if (!cannotHim[i] && cntHim[i] == n - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};
```

#### Python

```python
from typing import List
from collections import Counter

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        inDegree = Counter(y for x, y in trust)
        outDegree = Counter(x for x, y in trust)
        for th in range(n):
            if inDegree[th + 1] == n - 1 and not outDegree[th + 1]:
                return th + 1
        return -1
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/09/22/LeetCode%200997.%E6%89%BE%E5%88%B0%E5%B0%8F%E9%95%87%E7%9A%84%E6%B3%95%E5%AE%98/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/142446520](https://letmefly.blog.csdn.net/article/details/142446520)
