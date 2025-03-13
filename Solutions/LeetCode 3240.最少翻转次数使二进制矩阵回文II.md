---
title: 3240.最少翻转次数使二进制矩阵回文 II
date: 2024-11-16 13:47:46
tags: [题解, LeetCode, 中等, 数组, 双指针, 矩阵, 回文]
categories: [题解, LeetCode]
---

# 【LetMeFly】3240.最少翻转次数使二进制矩阵回文 II：分类讨论 

力扣题目链接：[https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/](https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/)

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>grid</code>&nbsp;。</p>

<p>如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 <strong>回文</strong>&nbsp;的。</p>

<p>你可以将 <code>grid</code>&nbsp;中任意格子的值 <strong>翻转</strong>&nbsp;，也就是将格子里的值从 <code>0</code>&nbsp;变成 <code>1</code>&nbsp;，或者从 <code>1</code>&nbsp;变成 <code>0</code>&nbsp;。</p>

<p>请你返回 <strong>最少</strong>&nbsp;翻转次数，使得矩阵中 <strong>所有</strong>&nbsp;行和列都是 <strong>回文的</strong>&nbsp;，且矩阵中 <code>1</code>&nbsp;的数目可以被 <code>4</code>&nbsp;<strong>整除</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,0,0],[0,1,0],[0,0,1]]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2024/08/01/image.png" style="width: 400px; height: 105px;" /></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,1],[0,1],[0,0]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/07/08/screenshot-from-2024-07-09-01-37-48.png" style="width: 300px; height: 104px;" /></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1],[1]]</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/08/01/screenshot-from-2024-08-01-23-05-26.png" style="width: 200px; height: 70px;" /></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 1</code></li>
</ul>


    
## 解题方法：分类讨论

step1: 先不考虑4的倍数个1，计算最小翻转次数

step2: 再考虑1的个数问题：

+ 偶数行偶数列：(1必定是4的倍数个)直接返回

+ 奇数行偶数列：看中间那一行有多少对11和多少对10/01

    + 偶数对11：(step1时可以把所有01/10变成00)直接返回
    + 奇数对11：看有无10/01：

        + 有10/01：(step1时把中间这一行的其中一对10/01变成11)直接返回
        + 无10/01：(step2必须把一对11变成00)step1结果+2后返回

+ 偶数行奇数列：和奇数行偶数列同理

+ 奇数行奇数列：要看“最中心元素”和“中间行中间列除最中间元素外的部分”两部分

    + 最中心元素：

        + 若为1：(必须变为0)step1+1
        + 若为0：step1不变
    
    + 中间行中间列除最中间元素外的部分：类似奇数行偶数列，统计这些元素中所有的11对和10/01对，之后同理

+ 时间复杂度$O(nm)$
+ 空间复杂度$O(1)$

不难发现，也可以直接判定是否存在“中间行”和“中间列”进行代码简化。

### AC代码

#### C++ 复杂版

```cpp
/*
step1: 先不考虑4的倍数个1，计算最小翻转次数

step2: 再考虑1的个数问题：

偶数行偶数列：(1必定是4的倍数个)直接返回
奇数行偶数列：看中间那一行有多少对11和多少对10/01
    + 偶数对11：(step1时可以把所有01/10变成00)直接返回
    + 奇数对11：看有无10/01：
        + 有10/01：(step1时把中间这一行的其中一对10/01变成11)直接返回
        + 无10/01：(step2必须把一对11变成00)step1结果+2后返回
偶数行奇数列：和奇数行偶数列同理
奇数行奇数列：要看“最中心元素”和“中间行中间列除最中间元素外的部分”两部分
    + 最中心元素：
        + 若为1：(必须变为0)step1+1
        + 若为0：step1不变
    + 中间行中间列除最中间元素外的部分：类似奇数行偶数列，统计这些元素中所有的11对和10/01对，之后同理
*/
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int cnt1 = grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1];
                ans += min(cnt1, 4 - cnt1);
            }
        }
        if (n % 2 == 0 && m % 2 == 0) {
            return ans;
        } else if (n % 2 == 1 && m % 2 == 0) {
            int cnt11 = 0, cnt0110 = 0;
            for (int j = 0; j < m / 2; j++) {
                if (grid[n / 2][j] == grid[n / 2][m - j - 1]) {
                    if (grid[n / 2][j] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            ans += cnt0110;
            if (cnt11 % 2 == 0 || cnt0110 > 0) {
                return ans;
            } else {
                return ans + 2;
            }
        } else if (n % 2 == 0 && m % 2 == 1) {
            int cnt11 = 0, cnt0110 = 0;
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] == grid[n - i - 1][m / 2]) {
                    if (grid[i][m / 2] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            ans += cnt0110;
            if (cnt11 % 2 == 0 || cnt0110 > 0) {
                return ans;
            } else {
                return ans + 2;
            }
        } else {
            if (grid[n / 2][m / 2]) {
                ans++;
            }
            int cnt11 = 0, cnt0110 = 0;
            for (int j = 0; j < m / 2; j++) {
                if (grid[n / 2][j] == grid[n / 2][m - j - 1]) {
                    if (grid[n / 2][j] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] == grid[n - i - 1][m / 2]) {
                    if (grid[i][m / 2] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            ans += cnt0110;
            if (cnt11 % 2 == 0 || cnt0110 > 0) {
                return ans;
            } else {
                return ans + 2;
            }
        }
    }
};
```

#### C++ 简化版

```cpp
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int cnt1 = grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1];
                ans += min(cnt1, 4 - cnt1);
            }
        }
        if (n % 2 && m % 2) {
            ans += grid[n / 2][m / 2];
        }
        int cnt11 = 0, cnt0110 = 0;
        if (n % 2 == 1) {
            for (int j = 0; j < m / 2; j++) {
                if (grid[n / 2][j] == grid[n / 2][m - j - 1]) {
                    if (grid[n / 2][j] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
        }
        if (m % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] == grid[n - i - 1][m / 2]) {
                    if (grid[i][m / 2] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
            
        }
        ans += cnt0110;
        if (cnt11 % 2 == 0 || cnt0110 > 0) {
            return ans;
        } else {
            return ans + 2;
        }
        return ans;
    }
};
```

#### Python

```python
from typing import List

class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        ans = 0
        n, m = len(grid), len(grid[0])
        for i in range(n // 2):
            for j in range(m // 2):
                cnt1 = grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1]
                ans += min(cnt1, 4 - cnt1)
        if n % 2 and m % 2:
            ans += grid[n // 2][m // 2]
        cnt11, cnt1001 = 0, 0
        if n % 2:
            for j in range(m // 2):
                if grid[n // 2][j] == grid[n // 2][m - j - 1]:
                    if grid[n // 2][j] == 1:
                        cnt11 += 1
                else:
                    cnt1001 += 1
        if m % 2:
            for i in range(n // 2):
                if grid[i][m // 2] == grid[n - i - 1][m // 2]:
                    if grid[i][m // 2] == 1:
                        cnt11 += 1
                else:
                    cnt1001 += 1
        ans += cnt1001
        if cnt11 % 2 and not cnt1001:
            ans += 2
        return ans
```

#### Java

```java
class Solution {
    public int minFlips(int[][] grid) {
        int ans = 0;
        int n = grid.length, m = grid[0].length;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int cnt1 = grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1];
                ans += Math.min(cnt1, 4 - cnt1);
            }
        }
        if (n % 2 == 1 && m % 2 == 1) {
            ans += grid[n / 2][m / 2];
        }
        int cnt11 = 0, cnt0110 = 0;
        if (n % 2 == 1) {
            for (int j = 0; j < m / 2; j++) {
                if (grid[n / 2][j] == grid[n / 2][m - j - 1]) {
                    if (grid[n / 2][j] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
        }
        if (m % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][m / 2] == grid[n - i - 1][m / 2]) {
                    if (grid[i][m / 2] == 1) {
                        cnt11++;
                    }
                } else {
                    cnt0110++;
                }
            }
        }
        ans += cnt0110;
        if (cnt11 % 2 == 1 && cnt0110 == 0) {
            ans += 2;
        }
        return ans;
    }
}
```

#### Go

```go
package main

func minFlips(grid [][]int) (ans int) {
    n, m := len(grid), len(grid[0])
    for i := 0; i < n / 2; i++ {
        for j := 0; j < m / 2; j++ {
            cnt1 := grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1]
            ans += min(cnt1, 4 - cnt1)
        }
    }
    if n % 2 == 1 && m % 2 == 1 {
        ans += grid[n / 2][m / 2]
    }
    cnt11, cnt1001 := 0, 0
    if n % 2 == 1 {
        for j := 0; j < m / 2; j++ {
            if grid[n / 2][j] == grid[n / 2][m - j - 1] {
                if grid[n / 2][j] == 1 {
                    cnt11++
                }
            } else {
                cnt1001++
            }
        }
    }
    if m % 2 == 1 {
        for i := 0; i < n / 2; i++ {
            if grid[i][m / 2] == grid[n - i - 1][m / 2] {
                if (grid[i][m / 2] == 1) {
                    cnt11++
                }
            } else {
                cnt1001++
            }
        }
    }
    ans += cnt1001
    if cnt11 % 2 == 1 && cnt1001 == 0 {
        ans +=2
    }
    return
}
```

> 同步发文于CSDN和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2024/11/16/LeetCode%203240.%E6%9C%80%E5%B0%91%E7%BF%BB%E8%BD%AC%E6%AC%A1%E6%95%B0%E4%BD%BF%E4%BA%8C%E8%BF%9B%E5%88%B6%E7%9F%A9%E9%98%B5%E5%9B%9E%E6%96%87II/)哦~
>
> Tisfy：[https://letmefly.blog.csdn.net/article/details/143816332](https://letmefly.blog.csdn.net/article/details/143816332)
