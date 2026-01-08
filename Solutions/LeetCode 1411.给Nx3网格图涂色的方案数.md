---
title: 1411.给 N x 3 网格图涂色的方案数：递推+原地滚动(动态规划)
date: 2026-01-03 21:46:12
tags: [题解, LeetCode, 困难, 动态规划, DP]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/04/12/e1.png
---

# 【LetMeFly】1411.给 N x 3 网格图涂色的方案数：递推+原地滚动(动态规划)

力扣题目链接：[https://leetcode.cn/problems/number-of-ways-to-paint-n-3-grid/](https://leetcode.cn/problems/number-of-ways-to-paint-n-3-grid/)

<p>你有一个 <code>n x 3</code>&nbsp;的网格图 <code>grid</code>&nbsp;，你需要用 <strong>红，黄，绿</strong>&nbsp;三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。</p>

<p>给你网格图的行数 <code>n</code>&nbsp;。</p>

<p>请你返回给&nbsp;<code>grid</code>&nbsp;涂色的方案数。由于答案可能会非常大，请你返回答案对&nbsp;<code>10^9 + 7</code>&nbsp;取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>12
<strong>解释：</strong>总共有 12 种可行的方法：
<img alt="" src="https://assets.leetcode.cn/aliyun-lc-upload/uploads/2020/04/12/e1.png" style="height: 289px; width: 450px;">
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>54
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>246
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 7
<strong>输出：</strong>106494
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>n = 5000
<strong>输出：</strong>30228214
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>grid[i].length == 3</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
</ul>


    
## 解题方法：动态规划

**一层3个方块有多少种涂色方式？**

$3\times3\times3=27$种。

**对于一层，如何判断某种涂色方式是否有效？**

第一块颜色不等于第二块，且第二块颜色不等于第三块即可。

共有$3\times2\times2$共计$12$种有效涂色方式。

**对于各自有效的两层，如何判断是否可以相邻？**

两层的第一列颜色不同，两层的第二列颜色不同，两层的第三列颜色不同即可。

**n层共有多少种有效方式？**

使用长度为27的数组记录到当前层为止，每种方案的总计涂色方法数。

假设上一层涂色方案$a$和这一层的涂色方案$b$可以相邻，那么就将上一层方案$a$的总计涂色方法数累加到这一层的方案$b$中。

**优化方案？**

其实单层的有效方案有哪些、相邻两层哪种相邻方案有效，都可以只计算一次，然后存下来，后续测试用例继续使用曾经计算出的结果。

+ 时间复杂度：$O(nC^2)$其中$C=12$是单层合法方案数。
+ 空间复杂度$O(C)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-01-03 21:29:33
 */
class Solution {
private:
    const long long MOD = 1e9 + 7;
    static vector<int> okList;
    static unordered_map<int, bool> okCache;

    inline int getFirst(int n) {
        return n % 3;
    }

    inline int getSecond(int n) {
        return n / 3 % 3;
    }

    inline int getThird(int n) {
        return n / 9;
    }

    bool isOk(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        int key = a * 27 + b;
        if (okCache.count(key)) {
            return okCache[key];
        }
        
        int a1 = getFirst(a);
        int a2 = getSecond(a);
        int a3 = getThird(a);
        int b1 = getFirst(b);
        int b2 = getSecond(b);
        int b3 = getThird(b);
        
        return okCache[key] = a1 != b1 && a2 != b2 && a3 != b3;
    }

    void init() {
        static bool first = true;
        if (!first) {
            return;
        }
        first = false;
        for (int i = 0; i < 27; i++) {
            int first = getFirst(i);
            int second = getSecond(i);
            int third = getThird(i);
            if (first != second && second != third) {
                okList.push_back(i);
            }
        }
    }
public:
    int numOfWays(int n) {
        init();
        long long a[27] = {0};
        long long b[27] = {0};
        for (int t : okList) {
            a[t] = 1;
        }

        while (--n) {
            for (int first : okList) {
                for (int second : okList) {
                    if (isOk(first, second)) {
                        b[second] = (b[second] + a[first]) % MOD;
                    }
                }
            }
            swap(a, b);
            memset(b, 0, sizeof(b));
        }
        return accumulate(a, a + 27, 0ll) % MOD;
    }
};

vector<int> Solution::okList;
unordered_map<int, bool> Solution::okCache;
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/156545186)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/01/03/LeetCode%201411.%E7%BB%99Nx3%E7%BD%91%E6%A0%BC%E5%9B%BE%E6%B6%82%E8%89%B2%E7%9A%84%E6%96%B9%E6%A1%88%E6%95%B0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
