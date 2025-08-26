---
title: 3000.对角线最长的矩形的面积：一次遍历
date: 2025-08-26 21:41:54
tags: [题解, LeetCode, 简单, 数组, 遍历, 模拟, 数学]
categories: [题解, LeetCode]
---

# 【LetMeFly】3000.对角线最长的矩形的面积：一次遍历

力扣题目链接：[https://leetcode.cn/problems/maximum-area-of-longest-diagonal-rectangle/](https://leetcode.cn/problems/maximum-area-of-longest-diagonal-rectangle/)

<p>给你一个下标从<strong> 0</strong> 开始的二维整数数组 <code>dimensions</code>。</p>

<p>对于所有下标 <code>i</code>（<code>0 &lt;= i &lt; dimensions.length</code>），<code>dimensions[i][0]</code> 表示矩形 <span style="font-size: 13.3333px;"> <code>i</code></span> 的长度，而 <code>dimensions[i][1]</code> 表示矩形 <span style="font-size: 13.3333px;"> <code>i</code></span> 的宽度。</p>

<p>返回对角线最 <strong>长 </strong>的矩形的<strong> 面积 </strong>。如果存在多个对角线长度相同的矩形，返回面积最<strong> 大 </strong>的矩形的面积。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>dimensions = [[9,3],[8,6]]
<strong>输出：</strong>48
<strong>解释：</strong>
下标 = 0，长度 = 9，宽度 = 3。对角线长度 = sqrt(9 * 9 + 3 * 3) = sqrt(90) ≈<!-- notionvc: 882cf44c-3b17-428e-9c65-9940810216f1 --> 9.487。
下标 = 1，长度 = 8，宽度 = 6。对角线长度 = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10。
因此，下标为 1 的矩形对角线更长，所以返回面积 = 8 * 6 = 48。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>dimensions = [[3,4],[4,3]]
<strong>输出：</strong>12
<strong>解释：</strong>两个矩形的对角线长度相同，为 5，所以最大面积 = 12。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= dimensions.length &lt;= 100</code></li>
	<li><code>dimensions[i].length == 2</code></li>
	<li><code>1 &lt;= dimensions[i][0], dimensions[i][1] &lt;= 100</code></li>
</ul>


    
## 解题方法：遍历维护最大值

使用一个变量l2维护最大的对角线长度的平方（避免无意义的开根号），遍历所有矩形：

+ 如果当前矩形对角线长度的平方大于l2，则更新l2并直接更新答案为当前矩形的面积；
+ 否则如果当前对角线长度的平方等于l2，则更新答案为当前矩形面积和答案的最大值。

### 时空复杂度分析

+ 时间复杂度$O(len(dimensions))$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-08-26 21:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 21:32:11
 */
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int M = 0;
        for (vector<int>& d : dimensions) {
            int l2 = d[0] * d[0] + d[1] * d[1];
            if (l2 > M) {
                M = l2;
                ans = d[0] * d[1];
            } else if (l2 == M) {
                ans = max(ans, d[0] * d[1]);
            }
        }
        return ans;
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[[6,5],[8,6],[2,10],[8,1],[9,2],[3,5],[3,5]]
*/
int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> v = stringToVectorVector(s);
        Solution sol;
        cout << sol.areaOfMaxDiagonal(v) << endl;
    }
    return 0;
}
#endif
```

#### Python

```python
'''
Author: LetMeFly
Date: 2025-08-26 21:25:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-26 21:34:38
'''
from typing import List
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        ans = M = 0
        for a, b in dimensions:
            l2 = a * a + b * b
            if l2 > M:
                M = l2
                ans = a * b
            elif l2 == M:
                ans = max(ans, a * b)
        return ans
```

#### Java

```java
/*
 * @Author: LetMeFly
 * @Date: 2025-08-26 21:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 21:36:58
 */
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0;
        int M = 0;
        for (int[] d : dimensions) {
            int l2 = d[0] * d[0] + d[1] * d[1];
            if (l2 > M) {
                M = l2;
                ans = d[0] * d[1];
            } else if (l2 == M) {
                ans = Math.max(ans, d[0] * d[1]);
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
 * @Date: 2025-08-26 21:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 21:36:14
 */
package main

func areaOfMaxDiagonal(dimensions [][]int) (ans int) {
    M := 0
    for _, d := range dimensions {
        l2 := d[0] * d[0] + d[1] * d[1]
        if l2 > M {
            M = l2
            ans = d[0] * d[1]
        } else if l2 == M {
            ans = max(ans, d[0] * d[1])
        }
    }
    return
}
```

#### Rust

```rust
/*
 * @Author: LetMeFly
 * @Date: 2025-08-26 21:25:10
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-08-26 21:40:59
 */
impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut ans: i32 = 0;
        let mut m: i32 = 0;
        for d in dimensions.iter() {
            let l2: i32 = d[0] * d[0] + d[1] * d[1];
            if l2 > m {
                m = l2;
                ans = d[0] * d[1];
            } else if l2 == m {
                ans = ans.max(d[0] * d[1]);
            }
        }
        ans
    }
}
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/150871371)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/08/26/LeetCode%203000.%E5%AF%B9%E8%A7%92%E7%BA%BF%E6%9C%80%E9%95%BF%E7%9A%84%E7%9F%A9%E5%BD%A2%E7%9A%84%E9%9D%A2%E7%A7%AF/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
