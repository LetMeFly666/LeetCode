---
title: 835.图像重叠：暴力模拟O(n^4)
date: 2026-09-13 11:32:34
tags: [题解, LeetCode, 中等, 数组, 矩阵, 模拟, 暴力]
categories: [题解, LeetCode]
index_img: https://files.letmefly.xyz/d/n/leetcode/0835-overlap_step2.jpg
---

# 【LetMeFly】835.图像重叠：暴力模拟O(n^4)

力扣题目链接：[https://leetcode.cn/problems/image-overlap/](https://leetcode.cn/problems/image-overlap/)

<p>给你两个图像 <code>img1</code> 和 <code>img2</code> ，两个图像的大小都是 <code>n x n</code> ，用大小相同的二进制正方形矩阵表示。二进制矩阵仅由若干 <code>0</code> 和若干 <code>1</code> 组成。</p>

<p><strong>转换</strong> 其中一个图像，将所有的 <code>1</code> 向左，右，上，或下滑动任何数量的单位；然后把它放在另一个图像的上面。该转换的 <strong>重叠</strong> 是指两个图像 <strong>都</strong> 具有 <code>1</code> 的位置的数目。</p>

<div class="original__bRMd">
<div>
<p>请注意，转换 <strong>不包括</strong> 向任何方向旋转。越过矩阵边界的 <code>1</code> 都将被清除。</p>

<p>最大可能的重叠数量是多少？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://files.letmefly.xyz/d/n/leetcode/0835-overlap1.jpg" style="width: 450px; height: 231px;" />
<pre>
<strong>输入：</strong>img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
<strong>输出：</strong>3
<strong>解释：</strong>将 img1 向右移动 1 个单位，再向下移动 1 个单位。
<img alt="" src="https://files.letmefly.xyz/d/n/leetcode/0835-overlap_step1.jpg" style="width: 450px; height: 105px;" />
两个图像都具有 <code>1</code> 的位置的数目是 3（用红色标识）。
<img alt="" src="https://files.letmefly.xyz/d/n/leetcode/0835-overlap_step2.jpg" style="width: 450px; height: 231px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>img1 = [[1]], img2 = [[1]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>img1 = [[0]], img2 = [[0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == img1.length == img1[i].length</code></li>
	<li><code>n == img2.length == img2[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>img1[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>img2[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>
</div>
</div>


    
## 解题方法：暴力模拟

`img1`最多往上移动$n-1$格，最多往下移动$n-1$格，于是我们第一层循环使用`dx`从$-(n-1)$到$n-1$表示`img1`往下移动的格数；左右移动同理，第二层循环使用`dy`从$-(n-1)$到$n-1$表示`img1`往右移动的格数。

两层循环枚举了`img1`的所有可能移动方式，由于`img1`向下移动了`dx`格向右移动了`dy`格，所以`img1[i][j]`就会移动到`img2[i+dx][j+dy]`的位置。由$0\leq i\lt n$和$0\leq i+dx\lt n$可以得出竖直方向的有效重叠范围是$0\leq i\lt n-dx$，同理水平方向有$0\leq j\lt n-dy$。

第三层第四层循环则可分别使用变量`i`从$\max(0,-dx)$到$\min(n,n-dx)$和变量`j`从$\max(0,-dy)$到$\min(n,n-dy)$，一个格子一个格子地计算在前两层循环的移动方式下，重叠的`1`有多少个。

+ 时间复杂度$O(n^4)$
+ 空间复杂度$O(1)$

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-09-13 11:32:09
 */
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0;
        int n = img1.size();
        for (int dx = 1 - n; dx < n; dx++) {  // [-(n-1), n-1]
            for (int dy = 1 - n; dy < n; dy++) {
                int this_ans = 0;
                // img1[i][j] -> img2[i+dx][j+dy]
                // 0≤i<n 且 0≤i+dx<n 得出 0≤i -dx≤i i<n i<n-dx
                for (int i = max(0, -dx); i < min(n, n-dx); i++) {
                    for (int j = max(0, -dy); j < min(n, n-dy); j++) {
                        this_ans += img1[i][j] * img2[i+dx][j+dy];
                    }
                }
                ans = max(ans, this_ans);
            }
        }
        return ans;
    }
};
```

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/165214693)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/09/13/LeetCode%200835.%E5%9B%BE%E5%83%8F%E9%87%8D%E5%8F%A0/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
