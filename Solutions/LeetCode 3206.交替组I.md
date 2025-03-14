---
title: 3206.交替组 I
date: 2024-11-26 23:43:43
tags: [题解, LeetCode, 简单, 数组, 滑动窗口]
categories: [题解, LeetCode]
---

# 【LetMeFly】3206.交替组 I：遍历

力扣题目链接：[https://leetcode.cn/problems/alternating-groups-i/](https://leetcode.cn/problems/alternating-groups-i/)

<p>给你一个整数数组 <code>colors</code>&nbsp;，它表示一个由红色和蓝色瓷砖组成的环，第 <code>i</code>&nbsp;块瓷砖的颜色为&nbsp;<code>colors[i]</code>&nbsp;：</p>

<ul>
	<li><code>colors[i] == 0</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;块瓷砖的颜色是 <strong>红色</strong>&nbsp;。</li>
	<li><code>colors[i] == 1</code>&nbsp;表示第 <code>i</code>&nbsp;块瓷砖的颜色是 <strong>蓝色</strong>&nbsp;。</li>
</ul>

<p>环中连续 3 块瓷砖的颜色如果是 <strong>交替</strong>&nbsp;颜色（也就是说中间瓷砖的颜色与它<strong>&nbsp;左边</strong>&nbsp;和 <strong>右边</strong>&nbsp;的颜色都不同），那么它被称为一个 <strong>交替</strong>&nbsp;组。</p>

<p>请你返回 <strong>交替</strong>&nbsp;组的数目。</p>

<p><b>注意</b>&nbsp;，由于&nbsp;<code>colors</code>&nbsp;表示一个 <strong>环</strong>&nbsp;，<strong>第一块</strong>&nbsp;瓷砖和 <strong>最后一块</strong>&nbsp;瓷砖是相邻的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-53-171.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>colors = [0,1,0,0,1]</span></p>

<p><b>输出：</b>3</p>

<p><b>解释：</b></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-47-491.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<p>交替组包括：</p>

<p><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-50-441.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong><img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-48-211.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /><strong class="example"><img alt="" src="https://assets.leetcode.com/uploads/2024/05/16/image_2024-05-16_23-49-351.png" style="width: 150px; height: 150px; padding: 10px; background: #fff; border-radius: .5rem;" /></strong></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= colors.length &lt;= 100</code></li>
	<li><code>0 &lt;= colors[i] &lt;= 1</code></li>
</ul>


    
## 解题方法：遍历

遍历“三连砖”的起点：

> 假设起点是$i$，那么下一个瓷砖就是$(i + 1) \% len(colors)$，下下个瓷砖就是$(i + 2) \% len(colors)$.

+ 时间复杂度$O(len(colors))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans = 0;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] != colors[(i + 1) % colors.size()] && colors[i] == colors[(i + 2) % colors.size()]) {
                ans++;
            }
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        return sum(colors[i] != colors[(i + 1) % len(colors)] != colors[(i + 2) % len(colors)] for i in range(len(colors)))
```

#### Java

```java
class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int ans = 0;
        for (int i = 0; i < colors.length; i++) {
            if (colors[i] != colors[(i + 1) % colors.length] && colors[i] == colors[(i + 2) % colors.length]) {
                ans++;
            }
        }
        return ans;
    }
}
```

#### Go

```go
package main

func numberOfAlternatingGroups(colors []int) (ans int) {
    for i := range colors {
        if colors[i] != colors[(i + 1) % len(colors)] && colors[i] == colors[(i + 2) % len(colors)] {
            ans++
        }
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/26/LeetCode%203206.%E4%BA%A4%E6%9B%BF%E7%BB%84I/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/144071026](https://letmefly.blog.csdn.net/article/details/144071026)
