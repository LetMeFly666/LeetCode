---
title: 3963.构造恰好一条路径的网格：左上到左下再到右下（构造）
date: 2026-10-27 20:01:57
tags: [题解, LeetCode, 简单, 构造, 字符串, 矩阵]
categories: [题解, LeetCode]
---

# 【LetMeFly】3963.构造恰好一条路径的网格：左上到左下再到右下（构造）

力扣题目链接：[https://leetcode.cn/problems/create-grid-with-exactly-one-path/](https://leetcode.cn/problems/create-grid-with-exactly-one-path/)

<p>给你两个整数 <code>m</code> 和 <code>n</code>，分别表示网格的行数和列数。</p>

<p>请你构造 <strong>任意</strong> 一个只包含字符 <code>'.'</code> 和 <code>'#'</code> 的 <code>m x n</code> 网格，其中：</p>

<ul>
	<li><code>'.'</code> 表示空单元格。</li>
	<li><code>'#'</code> 表示障碍物单元格。</li>
</ul>

<p><strong>有效路径</strong> 是满足以下条件的空单元格序列：</p>

<ul>
	<li>从左上角单元格 <code>(0, 0)</code> 开始。</li>
	<li>在右下角单元格 <code>(m - 1, n - 1)</code> 结束。</li>
	<li>只能向：
	<ul>
		<li>右移动，从 <code>(i, j)</code> 到 <code>(i, j + 1)</code>，或者</li>
		<li>下移动，从 <code>(i, j)</code> 到 <code>(i + 1, j)</code>。</li>
	</ul>
	</li>
</ul>

<p>返回任意一个从左上角到右下角 <strong>恰好只有一条有效路径</strong> 的网格。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">m = 2, n = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">["..#","#.."]</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/05/26/screenshot-2026-05-26-at-61005pm.png" style="width: 200px; height: 95px;" /></p>

<p>唯一的有效路径是：<code>(0,0) → (0,1) → (1,1) → (1,2)</code></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">m = 3, n = 3</span></p>

<p><strong>输出：</strong> <span class="example-io">["..#","#..","##."]</span></p>

<p><strong>解释：</strong></p>

<p><img src="https://assets.leetcode.com/uploads/2026/05/26/screenshot-2026-05-26-at-61129pm.png" style="width: 220px; height: 150px;" /></p>

<p>唯一的有效路径是：<code>(0,0) → (0,1) → (1,1) → (1,2) → (2,2)</code></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">m = 1, n = 4</span></p>

<p><strong>输出：</strong> <span class="example-io">["...."]</span></p>

<p><strong>解释：</strong></p>

<p>唯一的有效路径是：<code>(0,0) → (0,1) → (0,2) → (0,3)</code></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 25</code></li>
</ul>


    
## 解题方法：构造

初始化一个 m x n 的网格，全部填充为障碍物 `#`，然后将第一行和最后一列的单元格设置为空单元格 `.`，以上。

+ 时间复杂度$O(mn)$
+ 空间复杂度$O(1)$，力扣返回值不计入算法空间复杂度

### AC代码

#### C++

```cpp
/*
 * @LastEditTime: 2026-10-27 13:08:16
 */
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        for (int i = 0; i < m; i++) {
            ans[i][0] = '.';
        }
        for (int j = 0; j < n; j++) {
            ans[m - 1][j] = '.';
        }
        return ans;
    }
};
```

## End

> 同步发文于[CSDN](https://letmefly.blog.csdn.net/article/details/169267073)和我的[个人博客](https://blog.letmefly.xyz/)，原创不易，转载经作者同意后请附上[原文链接](https://blog.letmefly.xyz/2026/10/27/LeetCode%203963.%E6%9E%84%E9%80%A0%E6%81%B0%E5%A5%BD%E4%B8%80%E6%9D%A1%E8%B7%AF%E5%BE%84%E7%9A%84%E7%BD%91%E6%A0%BC/)哦~
>
> 千篇源码题解[已开源](https://github.com/LetMeFly666/LeetCode)
