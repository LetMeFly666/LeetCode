---
title: 2951.找出峰值
date: 2024-05-28 22:21:51
tags: [题解, LeetCode, 简单, 数组, 枚举]
---

# 【LetMeFly】2951.找出峰值：模拟（遍历）

力扣题目链接：[https://leetcode.cn/problems/find-the-peaks/](https://leetcode.cn/problems/find-the-peaks/)

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>mountain</code> 。你的任务是找出数组&nbsp;<code>mountain</code> 中的所有 <strong>峰值</strong>。</p>

<p>以数组形式返回给定数组中 <strong>峰值</strong> 的下标，<strong>顺序不限</strong> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>峰值</strong> 是指一个严格大于其相邻元素的元素。</li>
	<li>数组的第一个和最后一个元素 <strong>不</strong> 是峰值。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>mountain = [2,4,4]
<strong>输出：</strong>[]
<strong>解释：</strong>mountain[0] 和 mountain[2] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
mountain[1] 也不可能是峰值，因为它不严格大于 mountain[2] 。
因此，答案为 [] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>mountain = [1,4,3,8,5]
<strong>输出：</strong>[1,3]
<strong>解释：</strong>mountain[0] 和 mountain[4] 不可能是峰值，因为它们是数组的第一个和最后一个元素。
mountain[2] 也不可能是峰值，因为它不严格大于 mountain[3] 和 mountain[1] 。
但是 mountain[1] 和 mountain[3] 严格大于它们的相邻元素。
因此，答案是 [1,3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= mountain.length &lt;= 100</code></li>
	<li><code>1 &lt;= mountain[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：模拟（遍历）

用$i$从$1$到$mountain.length - 1$进行枚举，如果$mountain[i] \gt mountain[i - 1]$且$mountain[i]\gt mountain[i + 1]$，就将$i$添加到答案数组中。

> 小Tips: 将$i$添加到答案数组中的同时，可以将$i++$（因为下一个一定不是“峰值”元素）。

+ 时间复杂度$O(mountain.length)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> ans;
        for (int i = 1; i < mountain.size() - 1; i++) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                ans.push_back(i);
                i++;
            }
        }
        return ans;
    }
};
```

#### Go

```go
// package main

func findPeaks(mountain []int) []int {
    ans := make([]int, 0)
    for i := 1; i < len(mountain) - 1; i++ {
        if mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1] {
            ans = append(ans, i)
            i++
        }
    }
    return ans
}
```

#### Java

```java
// import java.util.ArrayList;
// import java.util.List;

class Solution {
    public List<Integer> findPeaks(int[] mountain) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < mountain.length - 1; i++) {
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                ans.add(i);
                i++;
            }
        }
        return ans;
    }
}
```

#### Python

```python
# from typing import List

class Solution:
    def findPeaks(self, mountain: List[int]) -> List[int]:
        ans = []
        for i in range(1, len(mountain) - 1):
            if mountain[i] > mountain[i - 1] and mountain[i] > mountain[i + 1]:
                ans.append(i)
        return ans
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/05/28/LeetCode%202951.%E6%89%BE%E5%87%BA%E5%B3%B0%E5%80%BC/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/139279605](https://letmefly.blog.csdn.net/article/details/139279605)
