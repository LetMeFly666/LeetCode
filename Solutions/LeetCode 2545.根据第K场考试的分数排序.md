---
title: 2545.根据第 K 场考试的分数排序
date: 2024-12-21 20:32:59
tags: [题解, LeetCode, 中等, 数组, 矩阵, 排序]
categories: [题解, LeetCode]
---

# 【LetMeFly】2545.根据第 K 场考试的分数排序：考察编程语言的排序

力扣题目链接：[https://leetcode.cn/problems/sort-the-students-by-their-kth-score/](https://leetcode.cn/problems/sort-the-students-by-their-kth-score/)

<p>班里有 <code>m</code> 位学生，共计划组织 <code>n</code> 场考试。给你一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的整数矩阵 <code>score</code> ，其中每一行对应一位学生，而 <code>score[i][j]</code> 表示第 <code>i</code> 位学生在第 <code>j</code> 场考试取得的分数。矩阵 <code>score</code> 包含的整数&nbsp;<strong>互不相同</strong>&nbsp;。</p>

<p>另给你一个整数 <code>k</code> 。请你按第 <code>k</code> 场考试分数从高到低完成对这些学生（矩阵中的行）的排序。</p>

<p>返回排序后的矩阵。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/11/30/example1.png" style="width: 600px; height: 136px;" /></p>

<pre>
<strong>输入：</strong>score = [[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2
<strong>输出：</strong>[[7,5,11,2],[10,6,9,1],[4,8,3,15]]
<strong>解释：</strong>在上图中，S 表示学生，E 表示考试。
- 下标为 1 的学生在第 2 场考试取得的分数为 11 ，这是考试的最高分，所以 TA 需要排在第一。
- 下标为 0 的学生在第 2 场考试取得的分数为 9 ，这是考试的第二高分，所以 TA 需要排在第二。
- 下标为 2 的学生在第 2 场考试取得的分数为 3 ，这是考试的最低分，所以 TA 需要排在第三。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2022/11/30/example2.png" style="width: 486px; height: 121px;" /></p>

<pre>
<strong>输入：</strong>score = [[3,4],[5,6]], k = 0
<strong>输出：</strong>[[5,6],[3,4]]
<strong>解释：</strong>在上图中，S 表示学生，E 表示考试。
- 下标为 1 的学生在第 0 场考试取得的分数为 5 ，这是考试的最高分，所以 TA 需要排在第一。
- 下标为 0 的学生在第 0 场考试取得的分数为 3 ，这是考试的最低分，所以 TA 需要排在第二。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == score.length</code></li>
	<li><code>n == score[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 250</code></li>
	<li><code>1 &lt;= score[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>score</code> 由 <strong>不同</strong> 的整数组成</li>
	<li><code>0 &lt;= k &lt; n</code></li>
</ul>


    
## 解题方法：自定义排序

在各种编程语言中，调用排序函数(如有)对数组按照每一行下标$k$从大到小的顺序排序。

+ 时间复杂度$O(m\log m)$
+ 空间复杂度$O(\log m)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-21 17:49:59
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 17:53:37
 * @Description: 没有全程在写
 */
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&k](const vector<int>& a, const vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-21 17:55:19
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-21 17:56:05
'''
from typing import List

class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        return sorted(score, key=lambda a: -a[k])
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-21 18:01:15
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 18:04:28
 */
import java.util.Arrays;

class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (a, b) -> b[k] - a[k]);
        return score;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-21 20:26:42
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-21 20:31:21
 */
package main

import "sort"

func sortTheStudents(score [][]int, k int) [][]int {
    sort.Slice(score, func(i, j int) bool {
        return score[i][k] > score[j][k]
    })
    return score
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/21/LeetCode%202545.%E6%A0%B9%E6%8D%AE%E7%AC%ACK%E5%9C%BA%E8%80%83%E8%AF%95%E7%9A%84%E5%88%86%E6%95%B0%E6%8E%92%E5%BA%8F/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144635776](https://letmefly.blog.csdn.net/article/details/144635776)
