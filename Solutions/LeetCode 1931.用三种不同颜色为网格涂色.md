---
title: 1931.用三种不同颜色为网格涂色
date: 2025-05-20 09:39:17
tags: [题解, LeetCode, 困难, 动态规划]
categories: [题解, LeetCode]
---

# 【LetMeFly】1931.用三种不同颜色为网格涂色

力扣题目链接：[https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/](https://leetcode.cn/problems/painting-a-grid-with-three-different-colors/)

<p>给你两个整数 <code>m</code> 和 <code>n</code> 。构造一个 <code>m x n</code> 的网格，其中每个单元格最开始是白色。请你用 <strong>红、绿、蓝</strong> 三种颜色为每个单元格涂色。所有单元格都需要被涂色。</p>

<p>涂色方案需要满足：<strong>不存在相邻两个单元格颜色相同的情况</strong> 。返回网格涂色的方法数。因为答案可能非常大， 返回 <strong>对 </strong><code>10<sup>9</sup> + 7</code><strong> 取余</strong> 的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/colorthegrid.png" style="width: 200px; height: 50px;" />
<pre>
<strong>输入：</strong>m = 1, n = 1
<strong>输出：</strong>3
<strong>解释：</strong>如上图所示，存在三种可能的涂色方案。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/22/copy-of-colorthegrid.png" style="width: 321px; height: 121px;" />
<pre>
<strong>输入：</strong>m = 1, n = 2
<strong>输出：</strong>6
<strong>解释：</strong>如上图所示，存在六种可能的涂色方案。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>m = 5, n = 5
<strong>输出：</strong>580986
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= m <= 5</code></li>
	<li><code>1 <= n <= 1000</code></li>
</ul>


    
## 解题方法：xx

```
firstCol:

[
f0
f1
f2
f3
]


mapping:

0: {1, 2}
1: {1, 3}
2: {}
3: {}


secondCol:

[
s0=0
s1=f0+f1
s2=f0
s3=f1
]


matrix

[                 [                  [ 
s0=0              [0 0 0 0]          f0
s1=f0+f1   --     [1 1 0 0]    \/    f1
s2=f0      --     [1 0 0 0]    /\    f2
s3=f1             [0 1 0 0]          f3
     ]                    ]           ]


S = M×F
```

+ 时间复杂度$O(N^2)$
+ 空间复杂度$O(N\log N)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-05-20 08:59:53
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-05-20 09:34:32
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

typedef long long ll;
typedef vector<vector<int>> matrix;

class Solution {
private:
    int singleNum;
    static constexpr int MOD = 1e9 + 7;
    static constexpr int pow[6] = {1, 3, 9, 27, 81, 243};

    inline int getTh(int a, int n) {
        return a / pow[n] % 3;
    }

    // 单看一列是否可行
    inline bool isOk(int a, int m) {
        for (int i = 1; i < m; i++) {
            if (getTh(a, i) == getTh(a, i - 1)) {
                return false;
            }
        }
        return true;
    }

    // 看可行的两列是否能相邻
    inline bool isOk(int a, int b, int m) {
        for (int i = 0; i < m; i++) {
            if (getTh(a, i) == getTh(b, i)) {
                return false;
            }
        }
        return true;
    }

    matrix mul(matrix a, matrix b) {
        matrix ans(singleNum, vector<int>(singleNum));
        for (int i = 0; i < singleNum; i++) {
            for (int k = 0; k < singleNum; k++) {
                for (int j = 0; j < singleNum; j++) {
                    ans[i][j] = (ans[i][j] + (ll)a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return ans;
    }

    matrix Pow(matrix a, int b) {
        matrix ans(singleNum, vector<int>(singleNum));
        for (int i = 0; i < singleNum; i++) {
            ans[i][i] = 1;
        }
        while (b) {
            if (b & 1) {
                ans = mul(ans, a);
            }
            a = mul(a, a);
            b >>= 1;
        }
        return ans;
    }
public:
    int colorTheGrid(int m, int n) {
        vector<int> singleOk;
        for (int i = 0; i < pow[m]; i++) {
            if (isOk(i, m)) {
                singleOk.push_back(i);
            }
        }
        singleNum = singleOk.size();  // 即使m=5也一共有48种
        // printf("%d\n", singleNum);
        matrix M(singleNum, vector<int>(singleNum));
        for (int i = 0; i < singleNum; i++) {
            for (int j = 0; j < singleNum; j++) {
                if (isOk(singleOk[i], singleOk[j], m)) {
                    M[j][i] = 1;
                }
            }
        }
        matrix Mn = Pow(M, n - 1);
        int ans = 0;
        for (int i = 0; i < singleNum; i++) {
            for (int j = 0; j < singleNum; j++) {
                ans = (ans + Mn[i][j]) % MOD;
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/--------------------------)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/05/20/LeetCode%201931.%E7%94%A8%E4%B8%89%E7%A7%8D%E4%B8%8D%E5%90%8C%E9%A2%9C%E8%89%B2%E4%B8%BA%E7%BD%91%E6%A0%BC%E6%B6%82%E8%89%B2/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
