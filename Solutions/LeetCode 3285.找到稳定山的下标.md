---
title: 3285.找到稳定山的下标
date: 2024-12-19 22:43:34
tags: [题解, LeetCode, 简单, 数组]
---

# 【LetMeFly】3285.找到稳定山的下标：遍历

力扣题目链接：[https://leetcode.cn/problems/find-indices-of-stable-mountains/](https://leetcode.cn/problems/find-indices-of-stable-mountains/)

<p>有&nbsp;<code>n</code>&nbsp;座山排成一列，每座山都有一个高度。给你一个整数数组&nbsp;<code>height</code>&nbsp;，其中&nbsp;<code>height[i]</code>&nbsp;表示第 <code>i</code>&nbsp;座山的高度，再给你一个整数&nbsp;<code>threshold</code>&nbsp;。</p>

<p>对于下标不为 <code>0</code>&nbsp;的一座山，如果它左侧相邻的山的高度 <strong>严格</strong><strong>大于</strong>&nbsp;<code>threshold</code>&nbsp;，那么我们称它是 <strong>稳定</strong>&nbsp;的。我们定义下标为 <code>0</code>&nbsp;的山 <strong>不是</strong>&nbsp;稳定的。</p>

<p>请你返回一个数组，包含所有 <strong>稳定</strong>&nbsp;山的下标，你可以以 <strong>任意</strong>&nbsp;顺序返回下标数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>height = [1,2,3,4,5], threshold = 2</span></p>

<p><span class="example-io"><b>输出：</b>[3,4]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>下标为 3 的山是稳定的，因为&nbsp;<code>height[2] == 3</code>&nbsp;大于&nbsp;<code>threshold == 2</code>&nbsp;。</li>
	<li>下标为 4 的山是稳定的，因为&nbsp;<code>height[3] == 4</code> 大于 <code>threshold == 2</code>.</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>height = [10,1,10,1,10], threshold = 3</span></p>

<p><span class="example-io"><b>输出：</b>[1,3]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>height = [10,1,10,1,10], threshold = 10</span></p>

<p><span class="example-io"><b>输出：</b>[]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == height.length &lt;= 100</code></li>
	<li><code>1 &lt;= height[i] &lt;= 100</code></li>
	<li><code>1 &lt;= threshold &lt;= 100</code></li>
</ul>


    
## 解题方法：遍历

用$i$从$1$到$n-1$遍历山峰，如果$height[i - 1] \gt threshold$，则将$i$添加到答案数组中。

+ 时间复杂度$O(n)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2024-12-19 15:53:21
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-19 15:53:31
 */
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 1; i < height.size(); i++) {
            if (height[i - 1] > threshold) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2024-12-19 15:58:23
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-19 16:11:17
'''
from typing import List

class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        return [i for i in range(1, len(height)) if height[i - 1] > threshold]
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2024-12-19 16:12:01
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-19 16:27:42
 */
import java.util.List;
import java.util.ArrayList;

class Solution {
    public List<Integer> stableMountains(int[] height, int threshold) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < height.length; i++) {
            if (height[i - 1] > threshold) {
                ans.add(i);
            }
        }
        return ans;
    }
}
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2024-12-19 16:29:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-12-19 16:29:28
 */
package main

func stableMountains(height []int, threshold int) (ans []int) {
    for i := 1; i < len(height); i++ {
        if height[i - 1] > threshold {
            ans = append(ans, i)
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/12/19/LeetCode%203285.%E6%89%BE%E5%88%B0%E7%A8%B3%E5%AE%9A%E5%B1%B1%E7%9A%84%E4%B8%8B%E6%A0%87/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144596618](https://letmefly.blog.csdn.net/article/details/144596618)
