---
title: 1039.多边形三角剖分的最低得分：记忆化搜索（深度优先搜索）
date: 2025-10-01 20:40:37
tags: [题解, LeetCode, 中等, 数组, DFS, 深度优先搜索, 记忆化搜索]
categories: [题解, LeetCode]
index_img: https://assets.leetcode.com/uploads/2021/02/25/shape3.jpg
---

# 【LetMeFly】1039.多边形三角剖分的最低得分：记忆化搜索（深度优先搜索）

力扣题目链接：[https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/)

<p>你有一个凸的<meta charset="UTF-8" />&nbsp;<code>n</code>&nbsp;边形，其每个顶点都有一个整数值。给定一个整数数组<meta charset="UTF-8" />&nbsp;<code>values</code>&nbsp;，其中<meta charset="UTF-8" />&nbsp;<code>values[i]</code>&nbsp;是第 <code>i</code> 个顶点的值（即 <strong>顺时针顺序</strong> ）。</p>

<p>假设将多边形 <strong>剖分</strong>&nbsp;为 <code>n - 2</code>&nbsp;个三角形。对于每个三角形，该三角形的值是顶点标记的<strong>乘积</strong>，三角剖分的分数是进行三角剖分后所有 <code>n - 2</code>&nbsp;个三角形的值之和。</p>

<p>返回 <em>多边形进行三角剖分后可以得到的最低分</em> 。<br />
&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/shape1.jpg" /></p>

<pre>
<strong>输入：</strong>values = [1,2,3]
<strong>输出：</strong>6
<strong>解释：</strong>多边形已经三角化，唯一三角形的分数为 6。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/shape2.jpg" style="height: 163px; width: 446px;" /></p>

<pre>
<strong>输入：</strong>values = [3,7,4,5]
<strong>输出：</strong>144
<strong>解释：</strong>有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7 = 144。最低分数为 144。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/02/25/shape3.jpg" /></p>

<pre>
<strong>输入：</strong>values = [1,3,1,4,1,5]
<strong>输出：</strong>13
<strong>解释：</strong>最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == values.length</code></li>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= values[i] &lt;= 100</code></li>
</ul>


    
## 解题方法：DFS

借一张[@灵茶山艾府](https://leetcode.cn/u/endlesscheng/)的[图](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/solutions/2203005/shi-pin-jiao-ni-yi-bu-bu-si-kao-dong-tai-aty6/)：

![5时示例图](https://cors.letmefly.xyz/https://i-blog.csdnimg.cn/direct/61d6f9b28c9345e0a18fafcd758422a0.png#pic_center)

<!-- ![000.png](https://pic.leetcode.cn/1759323132-bVvWcC-000.png) -->

以边`1-5`为例，这条边最终一定在一个三角形中。在哪个三角形中呢？一共有图中这四种可能。我们分别枚举这4种可能就好了。

具体来说，我们可以写一个函数`dfs(i, j)`，代表从`i`到`j`的凸多边形的最低得分，那么将点`k`作为边`15`所在三角形的另一个顶点的话，得到的总得分为`dfs(i, k)+dfs(k, j) + i*j*k`。

+ 时间复杂度$O(n^3)$
+ 空间复杂度$O(n^2)$

### AC代码

#### C++

```cpp
/*
 * @Author: LetMeFly
 * @Date: 2025-09-29 18:44:48
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2025-10-01 20:38:27
 */
#if defined(_WIN32) || defined(__APPLE__)
#include "_[1,2]toVector.h"
#endif

class Solution {
private:
    unordered_map<int, int> cache;
    vector<int> values;
    int n;

    int dfs(int i, int j) {
        if (j - i < 2) {
            return 0;
        }
        int key = i * n + j;
        if (cache.count(key)) {
            return cache[key];
        }
        if (j - i == 2) {
            return cache[key] = values[i] * values[i + 1] * values[i + 2];
        }
        int ans = 1000000000;
        /*
        0 1 2 3 -> 0 1 2 + 0 2 3

        0   1

        3   2


        0 1 2 3 4


            3
                 
        4        2

         0      1

        
        (i,j,k) + dfs(i,k)+dfs(k,j)
        */
        for (int k = i + 1; k < j; k++) {
            ans = min(ans, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
        }
        return cache[key] = ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        this->values = move(values);
        n = this->values.size();
        return dfs(0, n - 1);
    }
};

#if defined(_WIN32) || defined(__APPLE__)
/*
[3,7,4,5]

144
*/
int main() {
    string s;
    while (cin >> s) {
        vector<int> v = stringToVector(s);
        Solution sol;
        cout << sol.minScoreTriangulation(v) << endl;
    }
    return 0;
}
#endif
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/152376690)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2025/09/29/LeetCode%201039.%E5%A4%9A%E8%BE%B9%E5%BD%A2%E4%B8%89%E8%A7%92%E5%89%96%E5%88%86%E7%9A%84%E6%9C%80%E4%BD%8E%E5%BE%97%E5%88%86/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
