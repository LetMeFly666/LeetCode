---
title: 3208.交替组 II
date: 2024-11-28 23:43:47
tags: [题解, LeetCode, 中等, 数组, 滑动窗口]
---

# 【LetMeFly】3208.交替组 II：滑动窗口

力扣题目链接：[https://leetcode.cn/problems/alternating-groups-ii/](https://leetcode.cn/problems/alternating-groups-ii/)

<p>给你一个整数数组 <code>colors</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，<code>colors</code>表示一个由红色和蓝色瓷砖组成的环，第 <code>i</code>&nbsp;块瓷砖的颜色为&nbsp;<code>colors[i]</code>&nbsp;：</p>

<ul>
	<li><code>colors[i] == 0</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;块瓷砖的颜色是 <strong>红色</strong>&nbsp;。</li>
	<li><code>colors[i] == 1</code>&nbsp;表示第 <code>i</code>&nbsp;块瓷砖的颜色是 <strong>蓝色</strong>&nbsp;。</li>
</ul>

<p>环中连续 <code>k</code>&nbsp;块瓷砖的颜色如果是 <strong>交替</strong>&nbsp;颜色（也就是说除了第一块和最后一块瓷砖以外，中间瓷砖的颜色与它<strong>&nbsp;左边</strong>&nbsp;和 <strong>右边</strong>&nbsp;的颜色都不同），那么它被称为一个 <strong>交替</strong>&nbsp;组。</p>

<p>请你返回 <strong>交替</strong>&nbsp;组的数目。</p>

<p><b>注意</b>&nbsp;，由于&nbsp;<code>colors</code>&nbsp;表示一个 <strong>环</strong>&nbsp;，<strong>第一块</strong>&nbsp;瓷砖和 <strong>最后一块</strong>&nbsp;瓷砖是相邻的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [0,1,0,1,0], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-183519.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>交替组包括：</p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-182448.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong><img alt="" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-182844.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2024/05/28/screenshot-2024-05-28-183057.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [0,1,0,0,1,0,1], k = 6</span></p>

<p><b>输出：</b>2</p>

<p><b>解释：</b></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-183907.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>交替组包括：</p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184128.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong><img alt="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184240.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p><strong>示例 3：</strong></p>

<p><strong>输入：</strong>colors = [1,1,0,1], k = 4</p>

<p><strong>输出：</strong>0</p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/06/19/screenshot-2024-05-28-184516.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= colors.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= colors[i] &lt;= 1</code></li>
	<li><code>3 &lt;= k &lt;= colors.length</code></li>
</ul>


    
## 解题方法：滑动窗口

使用一个大小为k的“窗口”，统计窗口中“相邻两个元素不相同”的个数。

从$0$到$len(colors) - 1$遍历“窗口”的起点，每次起点向后移动一位，终点也向后移动一位（记得对$len(colors)$取模）。

窗口每移动一次，就依据新加入窗口的“相邻元素对”和刚移出窗口的“相邻元素对”更新窗口中“相邻两个元素不相同”的个数。

每次窗口中“相邻两个元素不相同”的个数若为$k - 1$，则说明是一个符合要求的窗口，答案数量加一。

+ 时间复杂度$O(len(colors))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int cntDiff = 0;
        for (int i = 1; i < k; i++) {
            if (colors[i] != colors[i - 1]) {
                cntDiff++;
            }
        }
        for (int i = 0; i < colors.size(); i++) {
            ans += cntDiff == k - 1;
            cntDiff += colors[(i + k) % colors.size()] != colors[(i + k - 1) % colors.size()];
            cntDiff -= colors[(i + 1) % colors.size()] != colors[i];
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        ans = 0
        cntDiff = sum(colors[i] != colors[i - 1] for i in range(1, k))
        for i in range(len(colors)):
            ans += cntDiff == k - 1
            cntDiff += colors[(i + k) % len(colors)] != colors[(i + k - 1) % len(colors)]
            cntDiff -= colors[(i + 1) % len(colors)] != colors[i]
        return ans
```

#### Java

```java
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int ans = 0;
        int cntDiff = 0;
        for (int i = 1; i < k; i++) {
            if (colors[i] != colors[i - 1]) {
                cntDiff++;
            }
        }
        for (int i = 0; i < colors.length; i++) {
            if (cntDiff == k - 1) {
                ans++;
            }
            if (colors[(i + k) % colors.length] != colors[(i + k - 1) % colors.length]) {
                cntDiff++;
            }
            if (colors[(i + 1) % colors.length] != colors[i]) {
                cntDiff--;
            }
        }
        return ans;
    }
}
```

#### Go

```go
package main

func numberOfAlternatingGroups(colors []int, k int) (ans int) {
    cntDiff := 0
    for i := 1; i < k; i++ {
        if colors[i] != colors[i - 1] {
            cntDiff++
        }
    }
    for i := range colors {
        if cntDiff == k - 1 {
            ans++
        }
        if colors[(i + k) % len(colors)] != colors[(i + k - 1) % len(colors)] {
            cntDiff++
        }
        if colors[(i + 1) % len(colors)] != colors[i] {
            cntDiff--
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/28/LeetCode%203208.%E4%BA%A4%E6%9B%BF%E7%BB%84II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144123453](https://letmefly.blog.csdn.net/article/details/144123453)
