---
title: 3516.找到最近的人：计算绝对值大小
date: 2025-09-04 13:42:19
tags: [题解, LeetCode, 简单, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3516.找到最近的人：计算绝对值大小

力扣题目链接：[https://leetcode.cn/problems/find-closest-person/](https://leetcode.cn/problems/find-closest-person/)

<p data-end="116" data-start="0">给你三个整数 <code data-end="33" data-start="30">x</code>、<code data-end="38" data-start="35">y</code> 和 <code data-end="47" data-start="44">z</code>，表示数轴上三个人的位置：</p>

<ul data-end="252" data-start="118">
	<li data-end="154" data-start="118"><code data-end="123" data-start="120">x</code> 是第 1 个人的位置。</li>
	<li data-end="191" data-start="155"><code data-end="160" data-start="157">y</code> 是第 2 个人的位置。</li>
	<li data-end="252" data-start="192"><code data-end="197" data-start="194">z</code> 是第 3 个人的位置，第 3 个人&nbsp;<strong>不会移动&nbsp;</strong>。</li>
</ul>

<p data-end="322" data-start="254">第 1 个人和第 2 个人以&nbsp;<strong>相同&nbsp;</strong>的速度向第 3 个人移动。</p>

<p data-end="372" data-start="324">判断谁会&nbsp;<strong>先&nbsp;</strong>到达第 3 个人的位置：</p>

<ul data-end="505" data-start="374">
	<li data-end="415" data-start="374">如果第 1 个人先到达，返回 1 。</li>
	<li data-end="457" data-start="416">如果第 2 个人先到达，返回 2 。</li>
	<li data-end="505" data-start="458">如果两个人同时到达，返回 <strong>0&nbsp;</strong>。</li>
</ul>

<p data-end="537" data-is-last-node="" data-is-only-node="" data-start="507">根据上述规则返回结果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 2, y = 7, z = 4</span></p>

<p><strong>输出：</strong> <span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<ul data-end="258" data-start="113">
	<li data-end="193" data-start="113">第 1 个人在位置 2，到达第 3 个人（位置 4）需要 2 步。</li>
	<li data-end="258" data-start="194">第 2 个人在位置 7，到达第 3 个人需要 3 步。</li>
</ul>

<p data-end="317" data-is-last-node="" data-is-only-node="" data-start="260">由于第 1 个人先到达，所以输出为 1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 2, y = 5, z = 6</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<ul data-end="245" data-start="92">
	<li data-end="174" data-start="92">第 1 个人在位置 2，到达第 3 个人（位置 6）需要 4 步。</li>
	<li data-end="245" data-start="175">第 2 个人在位置 5，到达第 3 个人需要 1 步。</li>
</ul>

<p data-end="304" data-is-last-node="" data-is-only-node="" data-start="247">由于第 2 个人先到达，所以输出为 2。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 1, y = 5, z = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<ul data-end="245" data-start="92">
	<li data-end="174" data-start="92">第 1 个人在位置 1，到达第 3 个人（位置 3）需要 2 步。</li>
	<li data-end="245" data-start="175">第 2 个人在位置 5，到达第 3 个人需要 2 步。</li>
</ul>

<p data-end="304" data-is-last-node="" data-is-only-node="" data-start="247">由于两个人同时到达，所以输出为 0。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x, y, z &lt;= 100</code></li>
</ul>


    
## 解题方法：数学

速度相同，路程越长到达越晚。

a和b的路程 = a和b坐标之差的绝对值。

+ 时间复杂度$O(1)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-04 13:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-04 13:36:19
 */
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diff = abs(x - z) - abs(y - z);
        return diff ? diff > 0 ? 2 : 1 : 0;
    }
};
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-09-04 13:33:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-04 13:37:22
'''
class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        diff = abs(x - z) - abs(y - z)
        return 2 if diff > 0 else 1 if diff else 0
```

#### Go

```go
/*
 * @Author: LetMeFly
 * @Date: 2025-09-04 13:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-04 13:39:11
 */
package main

func abs3516(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func findClosest(x int, y int, z int) int {
    diff := abs3516(x - z) - abs3516(y - z)
    if diff == 0 {
        return 0
    } else if diff > 0 {
        return 2
    }
    return 1
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-09-04 13:33:33
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-09-04 13:40:19
 */
impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let diff: i32 = (x - z).abs() - (y - z).abs();
        if diff == 0 {
            return 0;  // 这里必须带上return
        } else if diff > 0 {
            return 2;
        }
        1
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/151184074)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/04/LeetCode%203516.%E6%89%BE%E5%88%B0%E6%9C%80%E8%BF%91%E7%9A%84%E4%BA%BA/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
